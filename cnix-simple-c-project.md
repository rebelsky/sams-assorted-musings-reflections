A simple C project
==================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

*This essay isn't so much about how C programmers think or how Unix
programmers think.  Rather, it's about how I think about some working
on code.  I've written this essay for a variety of reasons: It will
help you understand a bit more what I mean by "Thinking like SamR";
it should expand your horizons a bit; and it will serve as a kind
of prelude to our upcoming discussion of GNU Make.*

Let's think about what you would do if you were creating a simple C
project.  In order to create a project, you start with a problem.  So,
we're going to build a library of math utilities.  Since I only have
limited space, or at least limited time, our library will have only
one procedure, `gcd`, which computes the greatest common divisor of
two integers.

Are you ready to think about that project?  Good.  Let's get started.

Here's the first question: What files do you expect to create?  I mean
the files that you will write with a text editor, such as your `.c` and
`.h` files.  Don't include the ones that you'll use a compiler or other
program to generate from the initial ones, such as `.o` files.  

Have you made the list?  No?  I was serious.  I want you to think about what
goes in a simple library project.

Okay, I'll assume that you've followed the instructions this time.
Compare your answer to mine [1].  Did you come up with the same
list I did?  Past experience suggests that your list is smaller [4].
That's okay; that's why we're doing these exercises.

Next question: What files do you expect to generate from these source
files?  It's okay if you don't come up with all of the ones I'd expect;
I just want you to think through the problem.

Are you done?  Good.  Compare your answers to mine [5].

Next, write the instructions to generate that second set of files.
For example, how are you going to generate the executables?  

You know what's next.  Compare your answers to mine [6].

We're almost ready to start writing code.  Just one more question: What
is the signature of `gcd`?

A Header
--------

Now that you've figured that out, it's time to write `gcd.h`.  Here's
my version.

    /**
     * mathlib.h
     *   A simple library of math utilities.
     *
     * <Insert appropriate open-source license.>
     */
     
    #ifndef __MATHLIB_H__
    #define __MATHLIB_H__
    
    // +------------+----------------------------------------------------
    // | Procedures |
    // +------------+
    
    /**
     * Compute the greatest common divisor of two positive integers.
     */
    extern int gcd(int x, int y);
    
    #endif // __MATHLIB_H__

You can ignore the lines that begin with pound signs. While most C 
programmers include them in their headers, you'll need to know more 
about the preprocessor to understand why we have them.

Tests
-----

What next?  Well, we'll think better about the procedure if we write
the tests.  And yes, you should write your own list of tests before
reading my list of tests.

Here's a question that came up while I was writing my tests and thinking
about edge cases.  What should we do if the user gives a zero or a
negative integer for one or both of the parameters?  There are two
basic approaches: We can make it the responsibility of `gcd` to check
the parameters and to return a special value when it gets an invalid
parameter, or we can make it the responsibility of the caller to ensure
that preconditions are met.  We'll use the latter approach.

What are my other edge cases?  Well, we know that the greatest common
divisor of 1 and anything (or anything and 1) is 1.  So we should do
some tests using 1 in each parameter position.  We should probably
worry about large numbers, so maybe something close to the largest
integer.  I know that many people use Euclid's algorithm to implement
GCD, so I might choose some pairs that require a lot of repetitions
in that algorithm, such as neighboring pairs of Fibonacci numbers.

I'll try a variety of moderately small values for the other experiments.

Here's my test suite.  Yours may differ.  I've made it fairly thorough
because I expect to be using my utilities in a variety of cases, so it's
particularly important to make sure that it works right.

    /**
     * test-gcd.c
     *   Tests for the mathlib gcd procedure.
     *
     * <Insert appropriate open-source license.>
     */
    
    // +---------+-------------------------------------------------------
    // | Headers |
    // +---------+
    
    #include <assert.h>
    #include <limits.h>
    #include "mathlib.h"
    
    // +------+----------------------------------------------------------
    // | Main |
    // +------+
    
    int
    main (int argc, char *argv[])
    {
      // Identical numbers
      assert (gcd (5, 5) == 5);
      assert (gcd (11, 11) == 11);
      assert (gcd (24, 24) == 24);
    
      // Some "obvious" answers
      assert (gcd (6, 3) == 3);
      assert (gcd (3, 6) == 3);
      assert (gcd (21, 6) == 3);
      assert (gcd (6, 21) == 3);
      assert (gcd (10, 25) == 5);
      assert (gcd (5, 25) == 5);
      assert (gcd (50, 70) == 10);
      assert (gcd (70, 50) == 10);
    
      // Relatively prime
      assert (gcd (10, 9) == 1);
      assert (gcd (9, 10) == 1);
      assert (gcd (502, 9) == 1);
      assert (gcd (9, 205) == 1);
    
      // One of the parameters is 1.
      assert (gcd (1, 1) == 1);
      assert (gcd (1, 5) == 1);
      assert (gcd (5, 1) == 1);
      assert (gcd (24, 1) == 1);
      assert (gcd (1, 25) == 1);
    
      // Large integers
      assert (gcd (INT_MAX, INT_MAX) == INT_MAX);
      assert (gcd (3 * (INT_MAX / 3), INT_MAX / 3) == INT_MAX / 3);
      assert (gcd (INT_MAX / 3, 3 * (INT_MAX / 3)) == INT_MAX / 3);
      assert (gcd (5 * (INT_MAX / 5), INT_MAX / 5) == INT_MAX / 5);
      assert (gcd (INT_MAX / 5, 5 * (INT_MAX / 5)) == INT_MAX / 5);
      assert (gcd (14 * (INT_MAX / 14), INT_MAX / 14) == INT_MAX / 14);
      assert (gcd (INT_MAX / 14, 14 * (INT_MAX / 14)) == INT_MAX / 14);
      assert (gcd (311 * (INT_MAX / 311), INT_MAX / 311) == INT_MAX / 311);
      assert (gcd (INT_MAX / 311, 311 * (INT_MAX / 311)) == INT_MAX / 311);
    
      // Fibonacci
      assert (gcd (21, 13) == 1);
      assert (gcd (13, 21) == 1);
      assert (gcd (63, 39) == 3);
      assert (gcd (39, 63) == 3);
      assert (gcd (55, 34) == 1);
      assert (gcd (34, 55) == 1);
      assert (gcd (550, 340) == 10);
    
      // And we're done.
      return 0;
    } // main

Implementation
--------------

Now, we're ready to implement the function.  We'll use [Euclid's
algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm).  You should
sketch the code yourself, particularly if you've never written it before.

Here's my program.

    /**
     * mathlib-gcd.c
     *   The greatest-common-divisor procedure for mathlib.
     *
     * <Insert appropriate open-source license.>
     */
    
    // +---------+-------------------------------------------------------
    // | Headers |
    // +---------+
    
    #include "mathlib.h"
    
    // +---------------------+-------------------------------------------
    // | Exported Procedures |
    // +---------------------+
    
    /**
     * Compute the greatest common divisor of two positive integers.
     */
    int 
    gcd(int x, int y)
    {
      if (y == 0)
        return x;
      else 
        return gcd (y, x % y);
    } // gcd

Running our tests
-----------------

Hmmm ... is it really that simple?  Should I make sure that `x` is
greater than `y` and swap them if it isn't?  Well, let's see if this
version works.

    $ cc -g -Wall   -c -o test-gcd.o test-gcd.c
    $ cc -g -Wall   -c -o mathlib-gcd.o mathlib-gcd.c
    $ cc -o test-gcd test-gcd.o mathlib-gcd.o
    $ ./test-gcd
    $

Yay!  Our tests passed.  I'm pretty confident that the original is correct.
(I know that Euclid's algorithm is correct.  I wanted to make sure that
I didn't get something wrong in trying to implement it, particularly since
I didn't pay attention to which input was larger.)

A Command-Line Application
--------------------------

We're now ready for the last step, writing a short command-line utility.
After all, who knows when you'll need the gcd of two numbers or more
numbers?

Guess what?  Writing this utility is your next assignment.  Write a
C program that uses our library to compute the greatest common divisor
of a sequence of one or more integers entered on the command line.

    % gcd 5 25
    5
    % gcd 17 82
    1
    % gcd 3570 4200
    210
    % gcd 3570 4200 48
    6
    % gcd 3
    3

Make sure to do appropriate error checking.  You should make sure that
there's at least one command-line parameter, that all of the parameters
represent valid integers, and so on and so forth.

What about the library?
-----------------------

We'll consider building and libraries in future modules.

---

[1] I would probably create five files: A `.c` file containing the code
for `gcd`; a `.h` file for others to include, a program that tests `gcd`,
a command-line executable [2], and a Makefile to manage the whole project.
We'll call those `mathlib-gcd.c`, `mathlib.h`, `test-gcd.c`, `gcd.c`,
and `Makefile`.  In some cases, I'd think about creating an interactive
test program, but I generally don't like interactive test programs.
I should also write a separate test for the command-line program, but
I'll leave that aside for now [3].

[2] As a long-time Unix programmer, I believe in the worth of creating
simple command-line tools from my libraries.

[3] That decision is probably a bad one.  I seem to recall that the last
time I tried to write the command-line program, I inserted a subtle bug.

[4] I guess there's a small chance that your list is larger.  In three
or so offerings of this class, I don't think I've encountered other suggestions,
but I suppose that some student will surprise me at some point.

[5] Every `.c` file will have a corresponding `.o` file.  That's three.
I'll have two executables, one for the test and one for the command-line
program.  We should also build a library (or shared library) from 
`mathlib-gcd.o`.  But you probably don't know about libraries yet, so
we'll leave that for a separate essay.

[6] Surprise!  I'm not putting the answers here.  You'll find my answers
later in the essay.

---

*Version 1.0 of 2017-01-06.*
