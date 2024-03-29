---
title: An introduction to "Don't embarrass me; Don't embarrass yourself: Thoughts on thinking in C and Unix"
number: 175
tags: [Don't embarrass me, don't embarrass yourself: Thoughts on thinking in C and Unix](index-cnix)
blurb: 
version: 1.2.1
released: 2017-01-01
current: 2022-01-23
---

Welcome to a work [1] that is tentatively entitled _Don't embarrass me;
Don't embarrass yourself_ and tentatively subtitled _Thoughts on thinking
in C and Unix_.  As the subtitle suggests, the focus of the work is to
help people develop skills as C programmers and as Unix programmers [2].
In case you weren't sure, C is a programming language designed in the
early 1970's, and Unix is both an operating system and a user environment
designed about the same time.  That both have survived and perhaps even
flourished is a testimony to certain aspects of their design, and that
makes them worth knowing and knowing about.

This work has evolved from a series of conversations I had with students
when I last taught our upper-level course in compilers [3].  I was
teaching a fairly traditional version of the course, using either the Red
Dragon Book or the Purple Dragon book [4] and the traditional tools of Lex
and Yacc [6] to translate something that looked a whole lot like Pascal.
However, almost every time I assumed that they knew how to do something
that I thought should be "obvious" to seasoned undergraduates, most of
them looked at me in puzzlement.  "It should be easy to track down that
segfault", I would say, "just use gdb or valgrind [8,10]."  They'd say "We've
only used gdb once, and what is this valgrind thingy?"  Or I might say
"the following macro will help", and they'd not know what a C macro is.
Don't even get me started on function pointers.

So I started giving a series of optional, mostly impromptu, lectures [11] 
on topics I thought they should know as students who program in C
in a Unix-like environment [12].  Most of the class came, as did a
few hangers-on.  Toward the end of the semester, they said "Those
lectures were great.  You should offer a course like this."  Now,
a course in how to use various Unix tools and how to program better
in C feels a bit too practical for a liberal arts college like
Grinnell.  But I agreed that the lectures seemed to be useful.  So
I came up with a compromise: During my next sabbatical, I offered
a one-credit "course" [14,15] in which I gave a somewhat more in-depth
treatment of these topics.

Somewhat in jest, I started referring to the course as "Don't embarrass me;
Don't embarrass yourself."  Why?  Because most of our students, having
completed our introductory sequence, write that they are "competent"
C programmers (or something equivalent) on their résumés.  But a C
programmer who doesn't know macros; or can't use a debugger well; or
hasn't figured out how to manage a moderate-sized, multi-file C project;
or can't use the "obvious" Unix tools to make her life easier isn't
really a competent C programmer.  If they go off and claim that they
are to someone else, it embarrasses me, and it should embarrass them.

I quickly realized that I was teaching more than tools and techniques;
both C and Unix promote particular ways of thinking about programming
and problem solving.  Hence, in many ways, I was teaching students how
to "think" in C and Unix.  These are clearly useful ways to think; I've
even heard from some of our students who go on to work at Microsoft and
Microsoft prefers candidates with a Unix background because of how Unix
encourages them to think.

The first offering of the course was pretty successful.  I had one
colleague from another department sit in on the course, and, at the
end, pronounced it one of the most useful courses at Grinnell [16].
It continues to seem successful in that students keep taking it and
students not enrolled still sit in on the course.

Why am I writing all of it down?  Since I am more used to teaching in
what our department calls "workshop-style" classes and which many people
might think of as a "flipped classroom" (students read stuff in advance
and do work during class), I thought it would be useful to turn
some of my "lectures" into readings, which should allow a somewhat
different in-class approach.  This "work", as I am referring to it,
represents my attempt to create the appropriate readings to prepare
students for in-class work.  I expect that I'll still expect them
to do out-of-class programming exercises; we'll probably end up
using in-class time to discuss their answers to those exercises.

I'm also writing this stuff down for another reason, one of the reasons
that I think the course is successful.  My colleague, Jerod Weinman,
tells me that all of the courses he ended up taking with one of us
undergraduate instructors were effectively "storytime with Frank".  In
many ways, this course is "storytime with SamR".  That is, I inject a
lot of side notes from my experiences teaching and programming, and those
side notes help provide additional context to why we approach things in
the way we do.  I hope my readers find those side stories and notes as
useful as my students do, and I hope my students continue to find them
useful in this different form.

Does the world really need another book on thinking in C
and Unix?  Probably not.  Eric S. Raymond's [_The Art of Unix
Programming_](http://www.catb.org/esr/writings/taoup/) is an excellent
text that is available free online [17].  Kernighan and Pike's _The Unix
Programming Environment_ is a classic [18].  Although Mike Gancarz's _The
Unix Philosophy_, is less widely read than those two works, it also has
very useful parts.  Beyond that, there's a whole Web of information on
these topics.

However, I still find it useful to present these materials in a way that
will make sense to our students, and that reflects my own perspectives on
programming and program development.  I also find that each of those books
is simultaneously too basic (e.g., my students don't really need to learn
about directory structures; they learned that in CSC-161 [19] and elsewhere)
and too advanced (e.g., I don't need to cover low-level system calls;
they should learn those in CSC-211 [20] or CSC-213 [21]).  I'm
targeting somewhere in between And, as noted above, the writings
will allow me to teach more of a workshop-style class [22].  Also,
lots of people continue to write books on topics that have already
been covered in classic works.

Will there be an audience beyond my students?  I don't know [23].  I'm not
sure that I really care.  If this work allows my students to learn better,
it's worth my time.

In the next two parts of the introduction, we will consider what it
means to think in C and to think in Unix.

---

[1] Right now, the "work" consists of a series of comparatively short
writings posted to the World-Wide Web.  Eventually, it may end up in
book or pamphlet form.  I will refer to it as a "work" so that I do
not bias toward  any particular form.

[2] "Unix programmers" has multiple possible meanings.  In this case,
I mean programmers working within the textual user interfaces typically
associated with the Unix and GNU Linux operating systems.

[3] A compiler is a computer program that translates from one programming
language (typically one that is more easily understood by humans)
to another programming language (typically one that is more easily
understood by computers).  The last step of this translation is typically 
taking various pieces of the translated code, as well as some standard
code, and compiling them together into one piece.  For some reason,
instead of calling the whole process "translation", computer scientists
and computer programmers started referring to it in terms of the last
step, which is "compilation".

[4] For a time, some classic computer science textbooks were referred
to by the drawings on their cover.  _Compilers: Principles, Techniques,
and Tools_ by Alfred V. Aho, Ravi Sethi, and Jeffrey D. Ullman, is a
classic book on compilers and has a knight fighting the red dragon of
compiler complexity using the various tools of a compiler writer [5].
Hence, "the Red Dragon book".  A recent revision has a purple dragon on
the cover.

[5] My snobbish programming language faculty tell me that while the 
kind of compilation that Aho, Sethi, Ullman, and now Lam focus on has
great historical and intellectual interest, it is not how modern
compilers work.  I still think it's a useful way to teach compilers.
the compiler

[6] Lex is a program that makes it easy to identify the individual
"parts of speech" in a program; in technical terms, it does "lexical
analysis".  Yacc does the more complex portions of the compilation [7].
Its name stands for "Yet another compiler compiler".

[7] No, that's not called "Yaking".

[8] Although the name "valgrind" makes it sound like you are grinding
values; the "i" in "grind" is pronounced more like "ih" as in "sin"
(doing something bad, not the trig function) [9].

[9] I was going to say "It rhymes with 'wind'", but then I realized that
"wind" can be pronounced one way to mean "blowing air" (which is what
I meant) and another way to mean "twist and turn".

[10] These days, address sanitizer or something similar seems to be a
more common approach.  I've used it a bit, but need to use it more.

[11] I don't really lecture.  I talk for a bit, and then ask students
to answer questions.  In my experience, you learn better by trying and
thinking on your own, than by listening.  I also find that you learn
many things better if you've tried yourself, and then someone suggests
a better approach.

[12] E.g., Linux, macOS.

[14] Typical Grinnell courses are four credits.

[15] My choice to offer a one-credit course during a sabbatical
says something about my personality.  My decision to write something
like a textbook for the course likely says something similar.

[16] I think that was a compliment.

[17] I have heard that many people are not comfortable reading ESR, so it
may be appropriate to write some new things.

[18] It does not have a cover illustration, so it has not alternate name.

[19] CSC-161 is Grinnell's _Imperative Problem Solving and Data
Structures_, the second course in Grinnell's CS curriculum.  It
covers the basics of C programming, including some pointer management,
as well as simple linked data structures and a bit of Linux.

[20] CSC-211 is _Computer Organization and Architecture_.

[21] CSC-213 is _Operating Systems_.  Well, it's really _Operating Systems
and Parallel Algorithms_.  But it's primarily an OS course.

[22] I suppose I could find parts of those other readings to do the
same.  However, I actually think it's easier to write the stuff myself.

[23] I did have a colleague at another institution tell me that they were 
using parts in their intro systems course.
