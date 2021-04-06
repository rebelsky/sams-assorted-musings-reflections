---
title: The joy of code: An instance of matrix initialization
number: 1132
tags: [The joy of code](index-joc)
blurb: Learning from the classics
version: 0.2
released: 
current: 2021-04-05
---
The other day, I was in my lab to pick up a book for one of my
children [1].  While I was there, I thought I'd pull out some books
for the classes I"m teaching this term: [CSC-282, _Thinking in C
and
Unix_](https://rebelsky.cs.grinnell.edu/Courses/CSC282/2021SpT2/syllabus/)
and [CSC/PSY/TEC-232, _Human-Computer
Interaction_](https://rebelsky.cs.grinnell.edu/Courses/HCI232/2021SpT2/syllabus/).  And, for fun, I went through a box of old books related to issues in
software engineering.  One of the books that called out to me was
Kernighan and Plauger's _The Elements of Programming Style_.  I'm not
sure whether it was the 1st edition or the 2nd edition [2,3].  "Hmm",
I said to myself, "I wonder whether this has anything that would be
useful for either class."

Amazingly, the first example of bad style in the book is something I
thought I might use in CSC-282.  It looks like this.

        DO 14 I=1,N
        DO 14 J=1,N
     14 V(I,J)=(I/J)*(J/I)

Even if you don't speak Fortran, you can probably figure out this is
a nested loop.  We go through each I,J pair, initializing a matrix
called `V` at each position.

So what's wrong with the code?  Let's hear from Kernighan and Plauger.

> A modest familiarity with Fortran tells us that this doubly nested DO loop assigns something to each element of an `N` by `N` matrix `V`. What are the values assigned? `I` and `J` are positive integer variables and, in Fortran, integer division truncates toward zero. Thus when `I` is less than `J`, `(I/J)` is zero; conversely, when `J` is less than `I`, `(J/I)` is zero. When `I` equals `J`, both factors are one. So `(I/J)•(J/I)` is one if and only if `I` equals `J`; otherwise it is zero. The program fragment puts ones on the diagonal of `V` and zeros everywhere else. (`V` becomes an identity matrix.) How clever!

> Or is it?

> Suppose you encountered this fragment in a larger program. If your knowledge of Fortran is sufficiently deep, you may have enjoyed the clever use of integer division. Possibly you were appalled that two divisions, a multiplication, and a conversion from integer to floating point were invoked when simpler mechanisms are available. More likely, you were driven to duplicating the reasoning we gave above to understand what is happening. Far more likely, you formed a vague notion that something useful is being put into an array and simply moved on. Only if motivated strongly, perhaps by the need to debug or to alter the program, would you be likely to go back and puzzle out the precise meaning.

To me, that's also an example of how some old-style C programmers
think.  The integer division to give 0's is a clever trick, and,
well, clever tricks that take some time to parse are a halmark of
one kind of C programming.  And, well, a good compiler will figure
out the division and multiplication well enough so that there's not
a significant overhead [4].

So I thought I'd use it in class.  But, as always, I planned for more
to discuss in my first class than I was able to cover [5].  And, well,
I didn't quite finish prepping that part of class in any case [6].  So,
let's see what we can do with it here.  I'll consider whether it belongs
in the [Thinking in C and Unix](index-cnix).

Here's what I started with, which mimics the formatting and such.
I generalized it a little bit and updated it to work with C's 0'based
indexing.

    #define COLS 5
    #define ROWS 4
    
      int M[ROWS][COLS];
    
      for (int i = 1; i <= ROWS; i++)
      for (int j = 1; j <= COLS; j++)
      M[i-1][j-1] = (i/j)*(j/i);

---

[1] Sorry, I'm not saying which book or which child.

[2] I'm not old enough to have used them, but I do own a copy.  I wonder
whether people called them "the green edition" and "the red edition".

[3] ...

[4] I should check with some colleagues about that.

[5] After twenty-five years of teaching, you'd think I'd be better at
such things.  But I'm not.  I almost always prepare too much.

[6] That's one of the great things about the C/Unix class; "Let's debug
this seemingly innocuous C code" can be a fun activity.
