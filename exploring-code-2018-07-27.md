Exploring code
==============

*Topics/tags: [The joy of code](index-joc) [1], Racket, Web, technical, long*

One of the libraries I wrote for the [Language and
Code](code-camp-language-and-code) code camp [permits the students to
fetch and transform Web pages](code-camp-transforming-web-pages).
To play with it, I implemented a simple [Pig Latin
server](igpay-atinlay-revisited).  I thought things were okay.  But once
the campers got their hands on the code, they discovered some problems.

In particular, once students tried to fetch pages from some sites, such as
espn.com, they got an error.  In particular, here's what they saw when they
tried to fetch the ESPN home page.

    > (define espn (fetch-page "http://www.espn.com"))
    sxml:modify: (duplicate attribute -  class)

Isn't that wonderful?  I thought it would be useful to record how I approached
the problem.

That problem itself is relatively clear.  The ESPN home page includes some
element that has two class attributes.  The library I use to process Web pages
considers that inappropriate.  I can fix the problem relatively easily; I can
just preprocess the Web pages before I use the SXML procedures on them.  But
that's potentially inefficient and it is not a particularly general solution.
Are there other issues at play?  I'd like to explore a bit.

Let's start by considering some context.  I haven't written most of my page
fetching and transformation code by hand.  While I could write that code,
I'd rather use standard libraries.  It's faster to use standard libraries.
And I'd expect that the folks designing the standard libraries have thought
through a variety of issues that I would not necessarily consider.

How have I implemented `fetch-page`?  Let's see ... There are three main
steps [2].

1. First, `fetch-page` gets a network port associated with the URL.  
`(get-pure-port (string->url url))`.  Those procedures come from the
[net/url](https://docs.racket-lang.org/net/url.html) package.

2. Next, `fetch-page` reads the HTML from page and converts it to an xexp
expression.  It uses `html->xexp` for that purpose.  That comes from 
the [html-parsing](https://docs.racket-lang.org/html-parsing/) package.

3. Finally, `fetch-page` rewrites the URLs on the page so that they 
refer to locations on the original server [3].  Let's see, I wrote
a somewhat complicated procedure for that process.

        ;;; Procedure:
        ;;;   update-urls
        ;;; Parameters:
        ;;;   xexp, an xexp expression
        ;;;   current-url, a string or URL
        ;;; Purpose:
        ;;;   Transform all the relative URLs to be absolute.
        ;;; Produces:
        ;;;   updated, an xexp expression
        (define (update-urls xexp current-url)
          (let* ([url (if (string? current-url)
                          (string->url current-url)
                          current-url)]
                 [fix (lambda (relative)
                        (url->string (combine-url/relative url relative)))]
                 [fixer (lambda (attribute)
                          (lambda (element context root)
                            (update-attribute element attribute fix)))])
            ((sxml:modify (list "//a" (fixer 'href))
                          (list "//img" (fixer 'src))
                          (list "//link" (fixer 'href))
                          (list "//script" (fixer 'src)))
             xexp)))

What packages do I rely on here?  `update-attribute` is a
procedure I wrote.  `combine-url/relative` is also from the
[net/url](https://docs.racket-lang.org/net/url.html)
package.  And `sxml:modify` is from the
[sxml](https://docs.racket-lang.org/sxml/index.html) package.

As I said, the problem is somewhere in the ESPN.com home page.  There's an
element with two style tags.  Is that legal?  Not officially.  But this is
the Wild West of the World Wide Web, where the guidelines are broken with
some regularity and Web browsers put up with it.  So it's "acceptable", or
at least it's something that our code needs to put up with.  

Let's see if I can replicate the problem in a more step-by-step manner.
I have a procedure, `fetch-page-pure`, that skips the URL rewriting.
Let's see how well that works.

    > (define espn (fetch-page-pure "http://www.espn.com"))

No errors!  So far, so good.  

Next, let's see if using `update-urls` recreates the problem.  It should,
but I'd like to check.

    > (define espn2 (update-urls espn "http://www.espn.com"))
    sxml:modify: (duplicate attribute -  class)
    > espn2
    #f

Yup, that's where the error is.  Let's try doing just part of the
`update-urls` conversion.  Let's see ....  I need a procedure to use 
with `sxml:modify`.  I'll write one that prints out the matching
element and then returns that element.

    > (define (simple element attribute fix)
        (write element) (newline)
        element)
    > (define espn2 ((sxml:modify `("//a" ,simple))
                     espn))
    ; ... Lots and lots of output from sipmle
    sxml:modify:  (duplicate attribute - class)

Does that get me closer?  A bit.  I've found that we get the error just
working with the anchors.  Can I figure out which anchor it is?  I got way
too many screens of output to look.  Let's just grab the anchors without
processing them and see what happens.

    > (define espn-anchors  ((sxpath "//a") espn))
    > (length espn-anchors)
    179

Wow!  That's a lot of anchors.  I wonder what happens if I create an element
with just those links?

    > (define espn-div (cons 'div espn-anchors))
    > (define espn2 ((sxml:modify `("//a" ,simple))
                     espn-div))
    ; ... Lots and lots of output from simple

No errors.  I wonder why not.  Am I perhaps dealing with an element that
contains one of the anchors?  That shouldn't be the issue.

    > (define espn-hack
        `(html (head (title "ESPN Links"))
               (body ,@espn-anchors)))
    > (define espn2 ((sxml:modify `("//a" ,simple))
                     espn-hack))

No errors there, either.  When I first encountered this issue, I threw
up my hands and said to myself, "I have no idea what's happening."  But
musing about it made me realize that there's a good possibility that the
error is happening in an enclosing element, rather than the link/anchor.
Still, finding the enclosing element is likely to be painful.

My first approach was to write a procedure that looks for tags with two
class attributes.  Fortunately, I had an `extract-attributes` procedure
already.  Part of me wants to write a generalized iterator for xexp
expressions.  But I've taught enough agile programming to know that that's
overkill right now.  So, here's what I came up with.

    (define (double-class xexp)
      (when (pair? xexp)
        (when (< 1 (tally (lambda (att) (eq? 'class (car att))) (cdr (extract-attributes xexp))))
          (write xexp)
          (newline)
          (newline))
        (for-each double-class (extract-contents xexp))))

Let's see if it works on some simple inputs.

    > (double-class `(p (@ (class "foo") (class "bar"))))
    (p (@ (class "foo") (class "bar")))

    > (double-class `(body
                      (p (@ (class "foo")))
                      (p (@ (class "foo") (style "color:blue;") (class "bar")))))
    (p (@ (class "foo") (style "color:blue;") (class "bar")))

That's fine.  Can I use it to identify the elements with two classes in
`espn`?  

    > (double-class espn)
    ; Lots of output!

What does one of those double-class elements look like?  Just for fun, I
reformatted one for a bit more clarity [4].

    `(div (@ (class "miniCardCarousel__slide")
             (data-now-id "1-24198436")
             (data-tier-type "Feed Rule 10 - Tier 1 Non-Personalized Content")
             (data-index "0")
             (data-type "miniCard")
             (class "miniCard")
             (style "border-color: #cbccce")
             (data-id "null")
             (name "&lpos=fp:feed:xx:coll:carousel:yy:story"))
          "\n" "\t\n" "\n" "\t"
          (section (@ (class "contentItem__content contentItem__content--story has-image has-video miniCard contentItem__content--enhanced contentItem__content--fullWidth"))
                   (a (@ (name "&lpos=fp:feed:xx:coll:carousel:yy:story")
                         (data-id "23984797")
                         (href "/fantasy/football/story/_/id/23984797/fantasy-football-sleepers-busts-breakouts-2018")
                         (data-mporder "{&quot;desktop&quot;:&quot;image-story&quot;,&quot;mobile&quot;:&quot;story-image&quot;}")
                         (class "contentItem__padding contentItem__padding--border"))
                      (div (@ (class "contentItem__contentWrapper"))
                           (div (@ (class "contentItem__teamBorder")
                                   (style "background-color: #cbccce;")))
                           (div (@ (class "contentItem__titleWrapper"))
                                (h1 (@ (class "contentItem__title contentItem__title--story contentItem__title--noSubhead")
                                       (data-mptype "story")) "Fantasy football sleepers, busts, breakouts for 2018")))
                      (figure (@ (class "media-wrapper"))
                              (picture (@ (class "media-wrapper_image"))
                                       (source (@ (data-srcset "http://a3.espncdn.com/combiner/i?img=%2Fphoto%2F2018%2F0703%2Fr396025_1296x729_16%2D9.jpg&w=160&h=90&scale=crop&cquality=80&location=center, http://a3.espncdn.com/combiner/i?img=%2Fphoto%2F2018%2F0703%2Fr396025_1296x729_16%2D9.jpg&w=320&h=180&scale=crop&cquality=40&location=center 2x")
                                                  (media "(max-width: 767px)"))
                                               (source (@ (data-srcset "http://a3.espncdn.com/combiner/i?img=%2Fphoto%2F2018%2F0703%2Fr396025_1296x729_16%2D9.jpg&w=160&h=90&scale=crop&cquality=80&location=center, http://a3.espncdn.com/combiner/i?img=%2Fphoto%2F2018%2F0703%2Fr396025_1296x729_16%2D9.jpg&w=320&h=180&scale=crop&cquality=40&location=center 2x")
                                                          (media "(min-width: 768px)"))
                                                       (img (@ (data-default-src "http://a.espncdn.com/photo/2018/0703/r396025_1296x729_16-9.jpg") (class " lazyload")))))))))
          "\t\t\n")

Yeah, you can definitely tell when you have HTML code that's been
generated by a program, rather than by a human.  And yes, there are two
`class` attributes.  The solution is to merge the two attributes.  Did I
really need to spend that much time figuring that out?  Probably not.
It's nice to know that there are only two class attributes, rather
than more.

What's next?  As I suggested at the beginning, I need to write a procedure to
modify the page to eliminate the duplicate class tags.  The HTML model is that
if an element has multiple classes, you separate them with spaces in the
class attribute.  That's easy enough to deal with.  Here's a procedure to merge
the class attributes

    (define merge-class-attributes
      (lambda (attributes)
        (let ([class-attributes
               (filter (lambda (att) (eq? (car att) 'class)) (cdr attributes))]
              [other-attributes
               (filter (lambda (att) (not (eq? (car att) 'class))) (cdr attributes))])
          (if (or (null? class-attributes)
                  (null? (cdr class-attributes)))
              attributes
              (cons '@
                    (cons (list 'class
                                (reduce (lambda (a b) (string-append a " " b))
                                        (map cadr class-attributes)))
                          other-attributes))))))

We should check it out, at least a little bit.

    > (merge-class-attributes '(@ (class "one") (style "color: blue;") (class "two")))
    '(@ (class "one two") (style "color: blue;"))
    > (merge-class-attributes '(@ (href "somewhere")
                                  (class "one")
                                  (style "color: blue;")
                                  (class "two")
                                  (note "something")))
    '(@ (class "one two") (href "somewhere") (style "color: blue;") (note "something"))

But how do I traverse the SXML tree?  Ideally, I'd use SXSLT.
Unfortunately, SXSLT is what's causing the problem [5].  I guess that
means that I'll need to write a procedure to traverse the tree and modify
as appropriate.  Once again, my first inclination is to write a general
procedure.  Nonetheless, I'm going to write a more specific one.  That
will allow me to think a bit more about the structure of the general one.

    (define merge-multiple-classes
      (lambda (xexp)
        (if (not (pair? xexp))
            xexp
            (if (has-attributes? xexp)
                (cons (car xexp)
                      (cons (merge-class-attributes (cadr xexp))
                            (map merge-multiple-classes (cddr xexp))))
                (cons (car xexp)
                      (map merge-multiple-classes (cdr xexp)))))))

Let's see how it works with the tools I've just built.

    > (define espn2 (merge-multiple-classes espn))
    > (double-class espn2)
    ; No output!

So far, so good.  Now let's try putting things together.

    > (define espn (update-urls
                    (merge-multiple-classes
                     (fetch-page-pure "http://www.espn.com"))
                    "http://www.espn.com"))

I got no errors.  Next, I should see whether I get a similar-looking page
when I load it in my Web browser.  It's not exactly the same, but it's close
enough.  Yay!

---

Postscript: I've been musing about a lot of technical topics recently.  I
apologize to my non-technical readers.  I'll likely muse about a wider variety
of topics once the code camps are done.

---

[1] Well, not really joy.  But that's the closest tag I have.

[2] There are also some subsidiary steps.  They are less important.

[3] Relative URLs are great when you're writing Web sites.  They are not
as great for tools that try to re-present the Web site.

[4] You'll have to accept that it's an SXML expression rather than an HTML
expression.

[5] More precisely, it's the interaction between the not-quite-valid HTML
code and SXSLT.

---

*Version 1.0.1 of 2018-07-28.*
