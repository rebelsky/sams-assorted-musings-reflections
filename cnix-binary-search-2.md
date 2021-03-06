Adventures in binary search, part the second: Designing tests
=============================================================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

---

*A simulated group interview, continued.*

Welcome back!  I hope you enjoyed our awesome snack bar.  As I said,
we at Microgoogazonbook really pride ourselves on the snack bars, which
are filled with healthy and brain-enhancing food and drink.  

What?  Could you repeat that question?

Where are the other applicants?  Oh, they decided they wanted to try
applying to Yahoo instead.  They'll be fine.

In any case, it's time to consider how we might test your binary search
procedures.  Here at Microgoogazonbook, we will likely run any core
algorithm, such as binary search, thousands or millions of times.  Hence,
we want to be absolutely sure it's correct.  Formal proof is the gold
standard.  However, we accept that thorough tests often need suffice.
Since we plan on running the code so many times, it's worth some extra
resources to conduct the tests.

So, what tests would you conduct?  You in red: What would you test?

> I'd check every value that is in the array.

That seems reasonable, once we have an array.  You should certainly
make sure that it works correctly for all the elements.  That shouldn't
even cost that much.  But what elements would you put in the array,
and what size?  Ah, I see that our octopus is still here.  Young
tentacled being, what do you think?

> As long as the array meets the preconditions, it doesn't matter what
  the particular values are.  We can just write something like

     for (i = 0; i < size; i++)
       {
         assert (search (a[i], a, size) == i);
       } // for

Good. Since binary search is only doing comparisons, it shouldn't matter
whether it's searching for 1, 2, and 3 in `{1,2,3}` or for 7, 11, and 42 in
`{7,11,42}`.  I also appreciate how well you could indicated that indentation
using your tentacles.  

But what size array should we test?  You, cowering in the back: What do
you think?

> Well, it's important to test edge cases.  So I'd test an array with
0 elements.  If you were willing to devote the computing resources, I'd
also test an array with `INT_MAX` values, presumably 0 through `INT_MAX-1`.

Good answer!  I bet Sun wishes that they had you on staff.  Then they
wouldn't have screwed up binary search in Java.  Other than "really small"
and "really large", what other size arrays would you test?  Ah, you jumping
up and down.

> I'd test a variety of different sizes.  Sometimes divide-and-conquer
algorithms work really well on arrays whose size is a power of two and
fail on neaby sizes; sometimes it's the other way around.

That sounds reasonable.  Let's try every array size from 0 to 32.  That
should be enough different sizes.  Oh, and we'll also test one really
ginormous array.  Are we done?  You, in the blue, what do you think?

> No.  We're not done.  We haven't seen what binary search does if the
value is *not* in the array.  We should look for a value smaller  than
the smallest value.  We should look for a value larger than the largest
value.  We should look somewhere in the middle, working in a way that 
the search goes left-then-right.  We should look somewhere else in
the middle so that the search goes right-then-left.

You are correct that we should look at the edges of the array, as well
as within the array.  Making sure that binary search goes back and forth
is a good way to stress the algorithm.  So, what positions would you choose?
Let's hear from someone we haven't heard from yet.

> Since you checked every position in the array, you should also check
*between* every two positions in the array.

Wow, that strikes me as overkill.  Don't you agree with that person in
blue that a few in the middle are necessary?  What about the rest of you?
Raise your hands if you think we should just check a few positions.

[A number of students raise their hands.]

Damn!  I'm pretty sure you just raised your hands because I said something
about "overkill".  Didn't anyone every teach you to question authority?
It's cheap to check between every two positions.  It may even be easier
for the programmer to write code that checks between every two positions
than it will be to figure out how to make binary search switch directions.
Let's just be thorough.

So, we now have a general approach:

   For every array size from 0 to 32 
     For every position in the array
       Make sure that search finds the value at position i
       Make sure that search does not find the value that should
         occur between position i and position i+1
     Check the edges.

Is there an easy way to do those check?  Back in the misty eons of time,
when I learned binary search, my professor suggested that we 
put 2*i into position i to ease computation.  That makes sense to me,
and it should make sense to you.  Since I see that many of you are not
yet ready to follow coding standards, I'll provide a solution to you.

    /**
     * test.c
     *   A more comprehensive set of checks.
     *
     * <insert appropriate FOSS license>
     */
    
    // +---------+-------------------------------------------------------
    // | Headers |
    // +---------+
    
    #include "search.h"
    #include <stdio.h>
    
    // +------+----------------------------------------------------------
    // | Main |
    // +------+
    
    int
    main (int argc, char *argv[])
    {
      int tests = 0;        // A count of tests we've run
      int errors = 0;       // A count of errors in the code
      int vals[32];         // Values to search
      int i;                // Counter variable
      int size;             // Size of array we are searching
    
      // Initialize the array with even numbers
      for (i = 0; i < 32; i++)
        {
          vals[i] = i*2;
        } // for
    
      // For each size of array
      for (size = 0; size <= 32; size++)
        {
          // For each position in the array
          for (i = 0; i < size; i++)
            {
              tests += 2;
              // Check for a value that's at that position
              if (search (i*2, vals, size) != i)
                {
                  fprintf (stderr, 
                           "Failed to find %d at pos %d in array of size %d.\n",
                           i*2, i, size);
                  ++errors;
                } // if
              // Check for the value that comes after that position but
              // before the next position
              if (search (i*2 + 1, vals, size) != -1) 
                {
                  fprintf (stderr,
                           "Incorrect result for %d in array of size %d.\n",
                           i*2 + 1, size);
                  ++errors;
                } // if
            } // for i
          // Before the front of the array
          ++tests;
          if (search (-1, vals, size) != -1) 
            {
              fprintf (stderr,
                       "Incorrect result for -1 in array of size %d.\n",
                       size);
            } // if
        } // for size
    
      // Report on total number of errors.
      fprintf (stderr, "%d tests, %d errors\n", tests, errors);
      if (errors > 0)
        {
          fprintf (stderr, "I believe that Yahoo is still hiring.\n");
        } //
    
      // We're done
      return errors;
    } // main

That test should take most of you under fifteen minutes to write.  And
it does some very thorough testing.  So it's worth your time.  I can tell
you from personal experience that a surprising number of programs fail just
a few of these tests, which is one of the reasons I think it's worth our
time to do all of them.

A few of you might eventually end up on the testing team, but, sadly enough,
it's rare that we have a novice SWE who can think this broadly about testing.
I'd encourage you to practice and practice some more.

Once you test your code again and make sure that it's working, take a trip
back to the snack bar.

*To be continued.*

---

*In part the third, we will consider some techniques whereby we might be
better able to write correct code.*

*Stay tuned!*

---

**Citations**

The test suite in this essay is closely modeled on one by
Jon Bentley in _Programming Pearls_, originally published in _Communications
of the ACM_.

> Jon Bentley. 1983. Programming pearls: Writing correct
programs. _Commun. ACM_ 26, 12 (December 1983),
1040-1045. DOI=http://dx.doi.org/10.1145/358476.358484

The idea of students self-identifying as octopi is due to MK.

---

*Version 1.0.1 of 2017-02-06.*
