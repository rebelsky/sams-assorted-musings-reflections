Recently read
=============

*Topics/tags: ???*

As I noted in [the notes on this year's sabbatical](sabbatical-2019-08-30),
one of my goals for sabbatical is to read something professional every day, 
or at least every weekday.  A related goal is to read something for
pleasure each day.  This document represents my log of the first week of
reading.  I've added a short note for some items; I expect that when
I hit particularly important documents, I'll write a separate musing.

**Reading for growth**

"[Why Clojure](http://blog.cleancoder.com/uncle-bob/2019/08/22/WhyClojure.html)"
in Robert C. Martin's _The Clean Code Blog_.  

> This 'blog post was referenced on the Racket Users mailing list.  I
appreciate reading yet another experienced programmer who eventually
realizes that the Lisp family of languages are the best way to go for
most projects.  Martin focuses on Clojure, a Lisp-like language that
I don't know very well.

> From what I can see from his posting, Clojure has some interesting 
variations of the standard Lisp syntax, including a hash for something
like lambda and implicit arguments.  Here's how he writes a program
to print the squares of the first twenty-five integers.

> `(println (take 25 (map #(* % %) (range))))`

> The implicit parameter (`%`) is an interesting choice, as is the
implicit lazy evaluations [1].  In any case, the post suggests that
I should probably spend some time learning Clojure.  As I mentioned
in [the notes on my sabbatical](sabbatical-2019-08-30), I may even
consider what 151 would look like if taught in Clojure [2].

> I also appreciate two particular paragraphs from the post.

> > Smalltalk was small and elegant and beautiful. It spawned the Design Patterns revolution. It spawned the Refactoring revolution. It spawned the TDD revolution. It helped to spawn the Agile revolution. Smalltalk was a language of tremendous impact.

> > Finally, Lisp is functional. And the future is looking very functional to me.

> I've been predicting success for functional programming for more
than twenty years, so it's good to see someone relatively famous
say it, too.

**Reading for pleasure**

The last third of _Moonlight and Moss_ by Kim Beall.  

> I read _Seven Turns_ after seeing it mentioned in a book review
column by Charles de Lint.  I seem to recall that the review said
something like "A suprisingly nice tale marred by a really awful
cover."  It turned out to be free on Kindle Unlimited, so I gave
it a try.  The book was an engrossing rural fantasy [4].  Since
many questions are left unanswered at the end of the book, I was
happy to see that a sequel was available.  I purchased it and read
it over three nights.

_The Pizza Delivery Boy's Tale_ by Kim Beall.  

> A short story, published in book form, that explores that background
of one character in the two books that Beall has written.  To be
more precise, although it focuses on one character, it gives a bit
more background on multiple characters.  Plus it has maps related
to the books.  I think Beall suggested reading this before _Moonlight
and Moss_, but the ordering I chose seems better to me.

---

Postscript: Yes, I realize that there is reading that is for both growth
and pleasure.  For now, I'm separting the materials that I am reading 
primarily as part of my professional development and materials that I am 
reading primarily for fun.

---

[1] In simple terms, lazy evaluation is an approach in which you only 
evaluate as much of something as you need.  In this case, although we're
using an infinite list of integers, since we only need the first 
twenty-five, we only build the first twenty-five.

[2] I look forward to any comments my fifth-year colleagues [3] may have
on Clojure.

[3] Or anyone else, for that matter.

[4] My alternative to "urban fantasy" for books that take place in the
present [5], include a singificant fantasy element, and take place
in a rural area.  I also worry that for some, "urban fantasy" has 
shifted from describing the novels of, say, Charles de Lint and Emma Bull to 
come what seems to be more "paranormal romance".

[5] More or less.

---

*Version 0.1 of 2019-08-31.*
