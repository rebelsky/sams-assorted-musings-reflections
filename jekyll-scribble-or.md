Jekyll or Scribble or ...?
==========================

*Topics/tags: [Teaching](index-teaching), CSC 151, digital humanities, markup*

This semester, I'm writing the new curriculum for CSC 151.  That means
that I have to put together about thirty-two readings and corresponding
labs [1].  It's come time to decide what format and system I should use
for writing that curriculum.

There are a variety of options.  When we designed the image-based 151
curriculum, Janet and I decided to use DocBook because it was adaptable,
allowing each of us to incorporate the materials into our own course webs,
and because we thought it would be useful if we ever did a print version.
Toward the end of the lifetime of those materials, some colleagues
converted it to Markdown and Jekyll because, well, they are much easier
to use.  I'm tempted to continue in Jekyll, even though I don't love it.
But I'm working in Racket, and the Racket community uses Scribble.
Scribble sites aren't exciting, but they are consistent.  I could also
use some XML format [2,3], plain HTML, LaTeX, and more.

I don't like the standard Racket documentation format; I find it's a bit
concise for novices and I find real pedagogical value to the six P's.
[Insert example]  Is there a happy compromise for the documentation,
something more like the standard DrRacket documentation, but with
preconditions and postconditions?  Figuring that out requires tha I
learn Scribble.  Of course, It would also do me good to learn Scribble.

I'm pretty sure Scribble provides some significant advantages.  I'm pretty
sure that there's a way to put Racket code in the source and automatically
include the output of that code.  That's a much better strategy than cutting
and pasting [4].

A slight worry about the proliferation of languages in 151.  I won't teach
them Scribble.

The best strategy is probably to write the "book" in Scribble [5] and to 
write the remainder of the Web site in Jekyll.  That way, I match the
expectations of two separate communities.  Scribble makes sense for the
Racket community.  Jekyll makes sense of the CS department community.

---

[1] There are forty-two sessions of the class.  We have days for exam 
discussions, project presentations, and the like.  I *think* that means
that I'll need about thirty-two readings.

[2] That's what DocBook was.

[3] We are doing a lot of SXML processing in the course.  It makes some
sense to match the primary language.

[4] Back in the good old days of DocBook, I did write a tool to do some
automatic running of the Scheme code.  But we did not use it consistently
and it fell into disuse when we switched to Jekyll.

[5] _A functional approach to digital humanities_?  I should be able to
come up with a better name than that.  Is there a title that plays on
the ways in which "Racket" means noise?

---

*Version 0.2 of 2018-08-07.*
