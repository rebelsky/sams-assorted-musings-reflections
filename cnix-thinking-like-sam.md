---
title: Thinking like Sam (aka Some of SamR's thoughts on software development)
number: 216
tags: [Don't embarrass me, don't embarrass yourself: Thoughts on thinking in C and Unix](index-cnix)
blurb: 
version: 1.2
released: 2017-02-01 
current: 2021-01-23
---

As I've noted already, the primary focus of this work [1] is trying to
help you understand [some of the ways C programmers approach software
development](cnix-thinking-in-c) and [some of the ways Unix programmers
approach software development](cnix-thinking-in-unix).  As you might
expect, my reporting on these issues is colored by my perspectives
and experience.  And so, this work is also probably a reflection of
"Thinking like Sam".  My goal is not to force you to think like me.
However, I do want to warn you that what you see here will reflect
my biases and approaches.  Let's consider a few.

*Document diligently*.  I believe programmers have a responsibility
to document their code to help those who come after them (and to
help themselves when they return to the code).  I don't expect deep
preconditions and postconditions (although they are nice), but each
procedure should have a short comment that explains what it does,
and any tricky parts of the code probably need an explanation.  I
tend to develop by listing steps as comments and then going back
and coding.  I realize that represents more comments than most
programmers need, but I find it a useful strategy.  I also realize
that comments tend to go stale, so good programmers take the time
to update (or remove) comments when they change their code.

*Try to test*.  You have some responsibility to make sure that your code
is correct.  Careful analysis helps.  But it also helps to have tests
in place that you can easily run to check your code.  I find that writing
tests helps me think better about what I want the code to do, and
what is likely to go long, particularly as I *explore edges*. [2]

*Continue to concentrate on core concepts*.  Programming fads come and
go.  My long-time experience suggests that many key concepts that
programmers and computer scientists needed to learn three decades
ago remain important today.  Computer scientists, computer programmers,
and software developers ("computer scientists", in the following).
need to be able to design, read, and analyze algorithms and data
structures.  Computer scientists need to know the basic literature
of algorithms and data structures: searching and sorting algorithms;
stacks, queues, linked lists, hash tables, and graphs.  Computer
scientists need to understand memory layout.  And yes, there are
others concepts computer scientists need.  Those are just some that
immediately spring to mind.

*Diagram and draw*.  Most of us understand what is happening in a program
better if we draw it out, particularly when we are dealing with pointers
or linked structures.  I won't draw much, if at all, in these essays, but
I do expect to draw a bit in face-to-face conversations.  And, even if
I don't draw, you should.

*Generalize, generally*.  I prefer code that can be used in multiple
situations to code that can only be used in particular circumstances.
Consider, for example, the problem of sorting.  We often start by writing
a procedure that sorts a particular type using a particular comparator.
Then we realize that we might want to sort in different orders, so we
make the comparator a parameter.  Then we realize that we may want to
sort different types, so we find a way to make the type a parameter, or
otherwise to allow different types [4].  While I may ground the details
in particular examples, I will strive to help you write general code
and to look for approaches that allow you to write general code.

*Elucidate experience, both embedded and external* (aka *share stories*).
I learn from experience, both mine and others'.  When I've solved a
tricky problem [6], I remember the problem.  When I've helped others solve
a problem, I also remember the problem and the solution.  I'll include
a few of these "war stories" along the way.

*Recall readings*.  There are many classic pieces in CS that I
regularly refer back to.  I will use K&R for a variety of examples.
I'll probably pull out some things from _The Unix Programming
Environment_.  I'll refer to columns in _Joel on Software_ or Jon
Bentley's _Programming Pearls_.  In general, I think that students
are best served by sources that are designed for professionals,
rather than for education, because such sources often force you to
think more deeply given that their focus is not on pre-masticating
ideas.

*Choose clarity*.  C encourages you to write concise, sometimes obtuse,
code.  I generally recommend that you strive for concise but clear
code, emphasizing clarity over extreme efficiency [7].  Clarity also
includes practices like choosing good variable names, indenting your
code appropriately, ordering your procedures for ease of searching,
and so on and so forth.

*Learn like a language lawyer.*   Good programmers know many of the 
ins and outs of the language.  It takes time to learn them all, but
you can develop habits that help.  Ask yourself about edge cases.  See
what happens in those cases.  Then find the official documentation to
see if that's what's supposed to happen.  For example, consider the
following program.

    void
    silly (int a, int b)
    {
      printf("%d,%d\n", a,b);
    } // silly
    
    int
    main (int argc, char *argv[])
    {
      int i = 2;
      silly (i++, i++);
      printf ("%d\n", i);
      return 0;
    } // main

What are the possible outputs?  Which of those outputs do you expect?  How
would you figure out what output is "correct"?  Which output *is* correct? [8]

Here's another example: When you're dealing with procedures that parse,
see what happens when they get incorrect or awkward inputs (e.g.,
integers larger than the largest representable integer).

*Explore enthusiastically* and *Make use of the manual*.  We learn
by trying.  We also learn by reading.  Do both.  You'll see me ask a
question, then write code to answer it.  You'll see me then follow up
with a quotation from the man page.  I learn better by combining these
approaches, and I hope you will, too.

*Stick to standard styles*.  The way you structure code affects how
readable others will find the code.  There are a few standards for
formatting C code.  Follow one of them.  I tend
to try to follow [GNU
standards](https://www.gnu.org/prep/standards/html_node/Writing-C.html).
I expect students in my course to follow those same standards.

*Find, foster, and feel fun*.  Programming should be enjoyable, at least
most of the time.  Find joy in your work, even if it's through stupid
jokes or annoying alliteration.

I hope you find that these are all appropriate approaches.  But
even if not, you'll find that I use them throughout my work.  You've
been warned.

---

[1] Notes, 'blog, book, course, whatever it is.

[2] I admit that I should have some unit tests in place for my Web sites.
Too often, I make updates to the software or the source files that make
things kerflooey, but don't notice because I don't have good tests [3] in
place.

[3] Well, any tests.

[4] In C, we might end up sorting arrays of pointers, which, while not
ideal, at least helps achieve one form of generality.  We might also look
for ways to use macros to parameterize [5].

[5] Yes, we will explore ways to write somewhat type-generic code in C.
It'll be loads of fun.

[6] Or even a simple problem.  Today I knew that students were having
trouble saving files because they left out an initial slash in the
file name because I've seen that error dozens of times, and made it a
few myself.

[7] Yes, I realize that we're programming in C because we want to be
efficient.  However, I find that the kind of efficiency that leads
to unreadable code is often pointless.  It's okay to manually
optimize, but you probably want to profile first.  Optimizers also
tend to do better with clear code.

[8] These days, it seems that the output is relatively uniform across
compilers.  Just a few years ago, it was not.  Or maybe it's still not
uniform; I'll have to check again.
