To compose or to pipe
=====================

*Topics/tags: [CSC 151](index-151), functional programming*

Recently, I've been working on a reading on higher-order programming for
CSC 151.  We introduce function composition and sectioning early in the
semester and then return to them later in the semester.  In writing that
reading, one thing I've been thinking about is how to address function
composition.

You may remember function composition from your study of mathematics.
The composition operation, ∘, gets written between two function and
means "apply the second function and then the first".  For example,

> (_f_∘_g_)(_x_) = _f_(_g_(_x_))

For as long as I've been teaching function composition in 151, I've followed
that pattern, although with Scheme syntax.  For example, `(o square add1)`
represents a procedure that adds one to its parameter and then squares it.
I like that order, since it matches not only what we do in mathematics, but
also how you'd write things in Scheme.  That is,

> `((o square add1) 4)` = `(square (add1 4))`

But humans tend to think from left to right.  So it feels like "add
then square" should have the addition procedure appear before the square
procedure.  That's also the order in which we write things in the Unix
or Linux shell when we want to sequence operations.  So let's call that
operator "pipe" [1].

> `((pipe square add1) 4)` = `(add1 (square (4))`

I recall a student stopping by my office early this year telling
me how excited they were to learn about something like `pipe`.  From my
perspective, the order of parameters to the operation is a relatively
small matter.

Here's the question: Should I teach them the original composition, the
new pipe operation, or both?  If
---

It feels like I consider an issue like this for each section I write.
ONe of the reasons things are slower.

---

[1] won't have students write it as @code{|}.  Or at least I don't think
I will.

---

*Version 0.5 of 2018-11-12.*

