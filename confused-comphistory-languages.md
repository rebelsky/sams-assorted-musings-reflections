I'm so confused!
================

*Topics/tags: [Miscellaneous](index-misc), programming languages, short*

Today Youngest Son and I visited the Computer History Museum.  The last
time we visited was about seven or eight years ago.  At that time, most
of the museum was closed for renovations.  This time, most of the museum
was open.  Lots of things were great, but I particularly enjoyed seeing
the analog computers and the IBM card sorters.  Youngest enjoyed seeing
the Curta calculators.  There was way too much to see.  We spent over
four hours there and didn't even finish the main exhibits [1].

About one-third of the way through the exhibit, they have a diagram
of about 150 major programming languages [2,3] and the influence
relationships between them.  I enjoyed tracing some of the LISP
descendants.

But then I noticed some strange things.  There's an arrow from `csh` to
Miranda.  It's hard for me to envision how a C-like [4] shell language 
could influence a lazy functional language.  There's also an arrow from
`csh` to KRC [5] and from KRC to Miranda.  Let's see ... 

> Kent Recursive Calculator was one of the earliest higher-order, lazy, purely functional programming systems. [6]

I was starting to wonder if someone was just having fun with the diagram or
whether I'd missed out on the monads in `csh` [7].  Then Youngest Son pointed
out that there's also an influence arrow from TeX to Lua.  Let's see ...
typesetting language and embedded application language.  Yeah, there's a
clear connection there.  More seriously though, I wonder if someone confused
Lua with [LuaTeX](http://www.luatex.org/).

So, what's going on here?

* Is the Computer History Museum checking to see if anyone notices?
* Did someone make a mistake in drawing the connections?
* Did someone put in some mistaken connections to see if people would
  draw incorrect connections?
* Are there actually connections between these languages?
* Something else?

I wish I knew.  Maybe I'll ask on the Computer History mailing list that
I'm on.  Maybe I'll ask on the SIGCSE list.  Or maybe I'll just leave things
well enough alone.

But for now, well, I'm just confused.

---

Postscript: If you should happen to visit the Computer History Museum,
spend a little time watching the looking toward the future videos.  There's
one in which the President of Electronic Arts says something like "Any
technology you learn now will be obsolete in five years.  So the best thing
to do is to get a broad Liberal Arts education."  I wish I'd been able to
record that.

---

Postscript: In "researching" this piece [8], I discovered that Turner's
early paper on KRC is called "[Recursion Equations as a Programming
Language](https://www.cs.kent.ac.uk/people/staff/dat/krc/recursion_equations.pdf)".
That reminded me of my advisor's book, [Equational Logic as a Programming
Language](https://www.amazon.com/Equational-Programming-Language-Foundations-Computing/dp/026215028X).  I wonder if "X as a Programming Language" was a
common topic for functional folks in the early 1980's.

---

[1] I think we would have gone back if we could.  Unfortunately, they aren't
open again until after we leave.

[2] And some not-so-major programming languages.

[3] And maybe some things that aren't strictly programming languages.

[4] I was surprised to see that although `sh` was listed as an
influence on `csh`, C wasn't.  I thought the whole point of `csh` was
to add a C perspective to shell scripting.

[5] The museum lists it as krc, all lowercase.  But I see it as KRC when
I look online.

[6] <http://krc-lang.org/krc.1.html>

[7] Miranda's popular descendent is Haskell.  Haskell handles pure I/O
with strange mathematical entities called monads.

[8] Air quotes are intentional.

---

*Version 1.0 of 2018-06-03.*
