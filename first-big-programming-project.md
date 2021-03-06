My first big programming project
================================

In [a recent musing](coding-reminders-to-self-and-students), I mentioned
that my first programming project for my advisor involved rewriting a
program that had one comment.  At the time, I promised to explain more
about the project.  Here's the broader explanation.

My advisor, the legendary Michael J. O'Donnell, had invented a programming
language, which he called Equational Logic Programming (ELP) and which
his graduate students tended to refer to as O'Dbol [1,2].  ELP was an
interesting language.  Programs were series of equations.  In some sense,
it was like some lazy functional languages.  But Mike was a purist at heart;
for example, it offended him that the order of evaluation of `if` was
fixed in most languages [4].  ELP was certainly an interesting language.

In any case, his prior graduate student had written an ELP compiler in
Franz Lisp that generated VAX assembly code.  We no longer had a VAX
or a Franz Lisp interpreter. My job was therefore to rewrite the compiler
in T [5] and generate 68000 assembly code [7].  Of course, my knowledge
of LISP-like languages came primarily from my first course in CS.
I'd never taken an architecture course.  And, well, neither pair of
languages were really what you could call compatible.  VAX assembly is
a fairly high-level language, even compared to a CISC assembly languages
like 68000.  Franz Lisp, like many early Lisps, was dynamically scoped.
T, as a dialect of Scheme, was statically scoped.  I'd never really
studied the difference between the two scoping mechanisms, or if I had,
I hadn't understood it.

I called the project my "zero knowledge port".  I translated things bit,
by bit, by bit [8].  But the resulting
compiler worked.  We could run ELP programs on our new system, and they
ran at least as well as they ran on the old system.

But I don't think anyone would ever want to touch that code.  Fortunately,
soon thereafter, Mike's other graduate students decided to do a ground-up
rewrite of the compiler.  If I recall correctly, Steph Bailey wrote the
core parts of the new compiler and David Sherman did an amazing job
adding memoization.  David's memoization strategy formed the core of
his dissertation [9].  After a failed attempt at writing a structure
editor, I went on to explore strange models of program communication,
particularly with regards to how we could have imperative programs and
lazy functional programs interact.

What did I learn from what must have been a full semester of translation?
I didn't learn T's object system, which I'm told is awesome.  I didn't
learn enough VAX assembly or 68K to be anything close to competent as an
assembly language programmer.  I did learn that with enough elbow grease,
you can get code to work, even if you don't quite understand it.

More seriously, I gained experience in working on a large project, I
learned the value of writing clear and well-documented code, I came to
understand why we have intermediate representations when writing
compilers, I got really good at reading documentation, and I suppose I
developed a better understanding of functional and assembly programming.

Perhaps at some time, I'll tell you about my attempt to understand an
Algol 68 compiler written in Algol 60 [12].

---

Postscript: Although I have a series of musings called "[the joy of code](index-joc)", this musing does not belong in that series.

---

[1] A.k.a. "Oddball".

[2] There was a tendency at one time for languages to end with "bol".
SNOBOL [3] and COBOL are the ones that come to mind, but I'm sure
there were others.

[3] Really.  Even though I misspelled it as "Snowbol" in my first
iteration of this musing.

[4] It's been awhile; let's see if I can remember.  It was something to
do with the relationship between the equations

    (car (cons a b)) = a
    (cdr (cons a b)) = b

and

    (if #t a b) = a
    (if #f a b) = b

Both pairs of equations let us select one of two values depending on
a third.  In the first case, the selector value is whether we use `car`
or `cdr`.  In the second, the selector value is whether we use `#t` or
`#f`.  If I recall correctly, Mike was bothered that in the second case,
most language implementers make the initial determination that you
evaluate the second parameter to `if` before looking at the other
parameters.  He felt that the language system, rather than the implementer,
should make that determination.

I should also note that my use of Scheme syntax is for the reader's
benefit.  Mike believed that the language should be indepedent of the
external representation and so ELP had multiple "front end" syntaxes.

[5] T is a variant of Scheme, T bears no relation to S or R [6].  It
appears that Paul Graham has an interesting [History of T](http://www.paulgraham.com/thist.html).

[6] Yes, S and R are programming languages.  R is a more modern version of
S.  Both R and S are commonly used for statistics.  

[7] The 68000 series of chips were Motorola's competition to whatever
Intel was making at the time.  Motorola no longer makes chips.  Guess 
who won?  

[8] Not those 0/1 bits, but "small part" by "small part" by "small part".

[9] David, who was one of the most organized people I know, also had the
misfortune of being my office mate.  I was as much of a packrat then as
I am now [10].

[10] Among other things, our office was the proud possessor of an HP
counter [11] that the Physics department had discarded, dozens of
old bound issues of _Science_ from the beginning of the twentieth 
century that the library had discarded, and assorted journals that 
the faculty had discarded.  Oh, yeah, we also had a bunch of shelves
that I trash picked.  David can probably tell you what else.

[11] A three-foot by three-foot by three-foot metal cube that must have
weighed over 100 pounds.  As far as we could tell, its only purpose was 
to count the number of times an electrical signal was sent to it.  It made
sense that I got rid of it, but I do miss it.

[12] That musing will almost certainly wait until I find the printout
of the compiler that I hope still lives somewhere in my lab.

---

*Version 1.0.1 released 2018-01-19.*

*Version 1.0.2 of 2018-01-21.*

