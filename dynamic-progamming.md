Dynamic programming
===================

*Topics/tags: [The joy of code](index-joc), teaching, technical*

Some time in the past few months, I was talking to some students about
dynamic programming.  At the core, dynamic programming should be a
simple concept: You express the solution to a problem (often an
optimization problem) recursively [1], memoize using an array (depending
on the problem, it may be one-dimensional, two-dimensional, or have even
more dimensions), and then build the table iteratively.  The recursive
solution is attractive because it makes it clear that you're doing an
exhaustive search [2] of the solution space.  But when you are doing
something that involves multiple recursive calls, implementing it
recursively is inefficient.  Hence, there are two more steps.

[Explain steps]

[Example one: Fibonacci.  Note that it can be done using only two 
prior cells.]

[Example two: Minimum stamps.  I can probably steal this from somewhere.]

[Example three: Something 2D.]

Although dynamic programming should be a straightforward and simple
approach, many students don't find it such.  I'll admit that I 
found dynamic programming puzzling when I first learned about it [3].
In part, it was the name: I still don't understand what's all that
dynamic about dynamic programming.  It's not nearly as dynamic as,
say, dynamic scoping [4].  It may also have been that I focused more
on the particular problems I learned to solve with dynamic programming
rather than the broader technique.  If I remember the three-step
process (express recursively, memoize with an array, build the array
iteratively), dynamic programming seems much easier to appply.

Do I contribute to confusion when I teach it?  I show the recursive
memoizing approach first, before moving to the iterative version.  I
like the approach because ....  But perhaps it confuses the issue
for some students.  When I next teach it, I'll make sure to emphasize
the three-step process.

Insert people: Developed by Richard Bellman, at least according to
Wikipedia.

---

[1] Recursion should be natural to most computer scientists.

[2] It is probably more stylistically appropriate to write "you're
exhaustively searching" rather than "you're doing an exhaustive search",
but it's "exhaustive search" is a particular technique that I want
to highlight.

[3] More precisely, when I learned about it under the category of
"dynamic programming".  The memoizing for Fibonacci and the minimum
stamps problem seemed obvious, as did the conversion from a recursive
solution to an iterative solution.

---

