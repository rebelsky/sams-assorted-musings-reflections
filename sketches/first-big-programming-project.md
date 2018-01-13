My first big programming project
================================

In [a recent musing](coding-reminders-to-self-and-students), I mentioned
that my first programming project for my advisor involved rewriting a
program that had one comment.  At the time, I promised to explain more
about the project.  Here's the broader explanation.

[3] My advisor had invented a programming language, which he called
Equational Logic Programming (ELP) and which his graduate students
tended to refer to as Oddball.  His prior graduate student had written
an ELP compiler in Franz Lisp that generated VAX assembly code.  We
no longer had a Vax or a Franz Lisp interpreter, so my job was to 
rewrite the compiler in T [4] and generate 68000 assembly code [6].
Of course, I'd never taken an architecture course.  And VAX assembly
is a fairly high-level language, even compared to a CISC language like
68000.  I also had the joy of dealing with the transition from a 
dynamically scoped language to a statically scoped language.


[4] A variant of Scheme, T bears no relation to S or R [5].

[5] Yes, S and R are programming languages.  R is a more modern version of
S.  Both R and S are commonly used for statistics.  

[6] The 68000 series of chips were Motorola's competition to whatever
Intel was making at the time.  Motorola no longer makes chips.  Guess 
who won?  

