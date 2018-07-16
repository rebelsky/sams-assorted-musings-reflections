A web of Racket programs
========================

*Topics/tags: [Code camps](index-code-camps), Racket, [The Joy of Code](index-joc)*

Over the next week, we are putting together the final details for the
third of three summer 2018 code camps.  In this camp, we are focusing on
language and code.  I've already written about [the overall structure of
the camp](code-camp-language-and-code).  Now, I'm trying to put things
together to make sure that my research students have an appropriate
framework from which to build things.

The two primary "languages" we'll be using in code camp are HTML, a markup
language for the World-Wide Web, and Racket, a programming language that
follows the intellectual heritage of Lisp and Scheme.

Today, I'm exploring the interaction between the two.  In some sense,
the relationship is clear: an HTML document is a nested expression
[1] which makes it natural to represent it as an s-expression,
the basic data type of Racket [2].  Racket provides a lot of
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

What do we want our students to be able to do?  Let's see ...

* Write procedures that generate SXML/xexp expressions and have
  them appear as Web pages.
* Create and process forms for interactive pages.
* Fetch Web pages and see them as SXML/sexp expressions.
* Extract plain text from SXML/sexp expressions.  That way, we can
  have them do some of the plain text analysis on what they've fetched
  (e.g., determine the most frequent words or pairs).
* Extract portions of SXML/sexp expressions.  That may be the first 
  step in doing some other kinds of analysis.
* Transform SXML/sexp expressions.  More precisely, write programs that
  read Web pages and make new Web pages.

I think that's enough for now.  There's a separate list for text manipulation,
but I'll leave that for another musing.

*Serve Web pages*

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
latter rather than the former [3].

Let's see ...

* We'll call the first procedure `(serve-procedure! proc)`.
* We'll call the second procedure `(serve-string str type)`.
* We'll call the third procedure `(serve-file path)`.

---

[1] Well, it's supposed to be a nested expression.  Early HTML renderers
were pretty *laissez faire* about what they accepted.

[2] And Scheme, and Lisp.

[3] Okay, not all of them understand hash tables.  But hash tables are
easier than the pattern syntax for dispatch.

---

*Version 0.1 of 2018-07-15.*
