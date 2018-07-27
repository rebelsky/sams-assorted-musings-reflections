A tangled web of Racket Web programs
====================================

*Topics/tags: [Code camps](index-code-camps), Racket, [The Joy of Code](index-joc), technical, disjoint [1]*

Over the next week, we are putting together the final details for the
third of three summer 2018 code camps.  In this camp, we are focusing on
language and code.  I've already written about [the overall structure of
the camp](code-camp-language-and-code).  Now, I'm trying to put things
together to make sure that my research students have an appropriate
framework from which to build things.

The two primary "languages" we'll be using in code camp are HTML, a markup
language for the World-Wide Web, and Racket, a programming language that
follows the intellectual heritage of Lisp and Scheme.

I'm starting to explore the interaction between the two.  In some sense,
the relationship is clear: an HTML document is a nested expression
[3] which makes it natural to represent it as an s-expression,
the basic data type of Racket [4].  Racket provides a lot of
infrastructure for working on the Web.  There's a nice [Web
server](https://docs.racket-lang.org/web-server/index.html),
as well as [a library for parsing HTML into
s-expressions](http://www.neilvandyke.org/racket/html-parsing/),
[a library for converting s-expressions into
HTML](http://www.neilvandyke.org/racket/html-writing/), [a library for
working with URLs](https://docs.racket-lang.org/net/url.html), and much,
much more.

But, well, there are problems in imposing all of these libraries
on novices, particularly novice middle-school students.  Many of the
libraries assume that you understand a wide variety of Scheme concepts,
such as structures and back-quoted expressions.  There's also the
issue that since different people wrote different libraries, they have
somewhat different interpretations of what the s-expressions should
look like.  For example, the HTML parsing library represents the
parameters to a tag as a list that starts with `@` and contains the
remaining name/value lists.  In contrast, the Web server expects the
parameters to be represented as a list of lists.  The [SXPath library
for searching](https://docs.racket-lang.org/sxml/sxpath.html) and the
[SXSLT](https://docs.racket-lang.org/sxml/sxslt.html) library for
transforming pages seem to prefer the form used by the parser.  That
form is called "SXML/xexp".

So I'm writing a wrapper library.

What do we want our students to be able to do?  Let's see ...

* Write procedures that generate SXML/xexp expressions and have
  them appear as Web pages.
* Create and process forms for "interactive" pages.
* Fetch Web pages and see them as SXML/xexp expressions.
* Extract plain text from SXML/xexp expressions.  That way, we can
  have them do some of the plain text analysis on what they've fetched
  (e.g., determine the most frequent words or pairs).
* Extract portions of SXML/sexp expressions.  That may be the first 
  step in doing some other kinds of analysis.
* Transform SXML/sexp expressions.  More precisely, write programs that
  read Web pages and make new Web pages.

I think that's enough for now.  There's a separate list for text manipulation,
but I'll leave that for another musing.

*Serving Web pages*

While the Racket Web server provides tools for serving Web pages, it's one
of those things that I feel is too advanced for our students.  So, let me
think about what I'd like them to be able to do.

* Pair a path (such as `index.html`) and a procedure for generating a
  page.
* Pair a path (such as `style.css`) and a string that corresponds to the
  contents of the page.
* Pair a path (such as `static.html`) and a file that stores the page.
* Start the server.

In some ways, the Web server [URL-based
dispatch](https://docs.racket-lang.org/web-server/dispatch.html) is
designed to handle those first kinds of activities.  I could use that
behind the scenes.  Or I could just use a hash table.  So that it's
easier for my research students to understand, I'm going to try the
latter rather than the former [5].

Let's see ...

* We'll call the first procedure `(serve-procedure path proc)`.
* We'll call the second procedure `(serve-string path str type)`.
* We'll call the third procedure `(serve-file path filename)`.

That way, a student programmer can write something like the following.

    (require lac-camp/server)
    
    (define (sample-page stuff)
      `(*TOP*
         (html
           (head
            (title "Sample Page")
            (link (@ (rel "stylesheet")
                     (href "styles.css"))))
           (body
             (h1 "This is page one!")
             (p (@ (class "first"))
                "This is the first paragraph")
             (p "This is the second paragraph")))))
    
    (serve-procedure "sample" sample-page)
    (serve-file "styles.css" "Desktop/styles.css")
    (start-server)

It will clearly take them a bit to get used to the syntax for writing
pages.  But it's not any worse than plain HTML.

*Forms and form handling*

Generating forms is straightforward, if a bit painful.  We just follow
the normal strategy for HTML.  A form tag and some input tags.   It's
a bit painful, but for the basics they can just use cut and paste.

    (define (sum-form stuff)
      `(*TOP*
        (html
         (head (title "Simple math"))
         (body
          (h1 "Let's do some math.")
          (p "Enter two numbers and I'll find their sum")
          (form (@ (method "get")
                   (action "sum"))
                (p (input (@ (type "text")
                             (name "x")))
                   (input (@ (type "text")
                             (name "y"))))
                (p (input (@ (type "submit")
                             (value "Add them!")))))))))
    (serve-procedure "input" sum-form)

Or I could add a procedure, `(text-field name)`.  Maybe we could have
them write it.  No, we should provide them with the procedure.  But if
I do something similar in the new CSC151, I can ask those students to
write it [6].

    (define (text-field name)
      `(input (@ (type "text")
                 (name ,name))))
    
    (define (submit-button text)
      `(input (@ (type "submit")
                 (value ,text))))
    
    (define (sum-form stuff)
      `(*TOP*
        (html
         (head (title "Simple math"))
         (body
          (h1 "Let's do some math.")
          (p "Enter two numbers and I'll find their sum")
          (form (@ (method "get")
                   (action "sum"))
                (p ,(text-field "x")
                   ,(text-field "y"))
                (p ,(submit-button "Add them")))))))


What about handling the form?  I've written a `(get input field default)`
procedure.  I think that's enough.  I'm not sure that `get` is the
best name, but we'll stick with it for now.

*Fetch Web pages as SXML/xexp*

This one is fairly straightforward.  I'll probably add something to
simplify it.  However, for now, it seems to work.

    #lang racket
    (require html-parsing)
    (require net/url)
    
    (define (fetch-page url)
      (html->xexp (get-pure-port (string->url url))))

How well does that work  Let's see ...

    > (fetch-page "https://www.cs.grinnell.edu/~rebelsky/")
    '(*TOP*
      (*DECL* DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd")
      "\n"
      (html
       (@ (lang "en"))
       "\n"
       (head
        "\n"
        (meta (@ (http-equiv "Content-Type") (content "text/html; charset=US-ASCII")))
        "\n"
        (title "SamR's Site: Samuel A. Rebelsky")
        "\n"
        "\n"
        (link (@ (rel "stylesheet") (type "text/css") (href "/~rebelsky/samr.css")))
        "\n"
        ...

Wow!  There are a lot of `"\n"`'s in there.  I wonder if I should filter
them out.  That may be a task for one of the future sections.

*Extract plain text from SXML/xexp expressions*

Let's see ... we'll want to grab the body, filter out any comments,
and then just grab the strings.  Will SXPath do that?  Let's see.
I can extract the body with something like the following.

    (define extract-body (sxpath "//body"))

That part was easy.  What about getting the strings?  I tried a
number of things before falling back on a search for the XPath format.

    (define extract-strings (sxpath "string(/)"))

That seems to work for the body.  But it doesn't work if I extract the
tags.

    > (define home (fetch-page "https:/www.cs.grinnell.edu/~rebelsky"))
    > (define tags ((sxpath "//a") home))
    > (take tags 4)
    '((a (@ (href "#postlinks")) "Skip To Body")
      (a (@ (accesskey "f") (href "/~rebelsky/index.html")) "Front Door")
      (a (@ (accesskey "o") (href "/~rebelsky/origin.html")) "Origin")
      (a (@ (accesskey "s") (href "/~rebelsky/schedule.html")) "Schedule"))
    > (extract-strings (take tags 4))
    "Skip To Body"

I suppose I'll have to use `map`.

    > (map extract-strings (take tags 4))
    '("Skip To Body" "Front Door" "Origin" "Schedule")

Yup, that works.  But I'll need to think more about how I'll deal with
the list.  I don't think a straight `string-append` makes sense.  Let's
play with `foldl`.

    > (define (join-with-space str1 str2) (string-append str1 " " str2))
    > (foldr join-with-space "" (map extract-strings (take tags 4)))
    "Skip To Body Front Door Origin Schedule "

That's not bad.  But there's an extra space at the end.  Let's see ...

    > (define (join-with-spaces lst)
        (let ([rev (reverse lst)])
          (foldl join-with-space (car rev) (cdr rev))))
    > (join-with-spaces (map extract-strings (take tags 4)))

Yup, that works.  Now I'll just need to think about the right interface.
Perhaps `(extract-page-content page)`.  But I think we want more than
that.  Let's see ... can I extract the text from a bunch of paragraphs?

    > (define example '(stuff (p "Hello " (strong "Hi")) (p "Goodbye " (em "'Bye"))))
    > (define paragraphs ((sxpath "//p") example))
    > (map extract-strings paragraphs)
    '("Hello Hi" "Goodbye 'Bye")

That looks okay.  So students can do interesting things with "extract
all the paragraphs as strings".  That's a good starting point.  They
should know `map`.  We'll give them `extract-strings`.  I'll probably
need to write a simple `select-by-tag` procedure.  I might as well do
that now.

    (define (select-by-tag tag xexp)
      ((sxpath (string-append "//" tag)) xexp))

     > (select-by-tag "strong" example)
     '((strong "Hi"))
     > (select-by-tag "p" example)
     '((p "Hello " (strong "Hi")) (p "Goodbye " (em "'Bye")))
     > (select-by-tag "strong" (select-by-tag "p" example))
     '((strong "Hi"))

Cool!  It works better than I thought [8].

*Extract portions of SXML/sexp expressions*

See above.  I'll need to see what the research students come up with for
activities before figuring out what the right interface is.  I'll chat
with them about it tomorrow morning.

*Transform SXML/sexp expressions*

Given the complications I had with SXPath, I think I'm leaving SXSLT to
another day.

*Rethinking earlier decisions*

Now that I see how SXPath works, I've realized that we don't need the
`*TOP*` at the start of documents.  That will simplify things a bit.
I wonder how far my students have gotten with the old library.  And
what does that say about what I should return from `fetch-page`.  Should
I drop the stuff around the page?  It would make things a bit clearer.

As I said, I'll talk to my research students tomorrow and see what they
think.

---

[1] I thought about using the term "rambly".  But there's more coherency
to my rambly musings than there is to this one.  So "disjoint" seems like
a better term.  I suppose I should consider rewriting it.  But my point
was really to use the musing to help me think through problems.  I'll add
"more coherent [2] musing about our library for Racket and the Web" to my
list of potential musings.

[2] Hmmm ... if this is "disjoint", should that be "more joint" rather
than "more coherent"?  I think not.

[3] Well, it's supposed to be a nested expression.  Early HTML renderers
were pretty *laissez-faire* about what they accepted.

[4] And Scheme, and Lisp.

[5] Okay, not all of them understand hash tables.  But hash tables are
easier than the pattern syntax for dispatch.

[6] Of course, if they find this musing, it will be much easier for them [7].

[7] Well, they have to read this disjoint musing, so perhaps it won't be all
that much easier.

[8] I had assumed that it would not work with the list of paragraphs.
But it did.  Yay!

---

*Version 1.0 released 2018-07-16.*

*Version 1.0.1 of 2018-07-27.*
