Exploring code
==============

*Topics/tags: [The joy of code](index-joc) [1], Racket, Web, technical*

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
just preprocess the Web pages before I use the SXML procedure son them.  But
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
expression.  It uses `html->xexp` for that purpose.  That comes from the
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
    ... ; Lots and lots and lots of output
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
    ... ; Lots and lots of output

No errors.  I wonder why not.  Am I perhaps dealing with an element that
contains one of the anchors?  That shouldn't be the issue.

> (define espn-hack
    `(html (head (title "ESPN Links"))
           (body ,@espn-anchors)))
> (define espn2 ((sxml:modify `("//a" ,simple))
                 espn-hack))

No errors there, either.  I guess the error happens in an enclosing tag.  
That's going to be a pain to find.

---

Postscript: I've been musing about a lot of technical topics recently.  I
apologize to my non-technical readers.  I'll likely muse about a wider variety
of topics once the code camps are done.

---

[1] Well, not really joy.  But that's the closest tag I have.

[2] There are also some subsidiary steps.  They are less important.

[3] Relative URLs are great when you're writing Web sites.  They are not
as great for tools that try to re-present the Web site.

---

*Version 0.4 of 2018-07-26.*
