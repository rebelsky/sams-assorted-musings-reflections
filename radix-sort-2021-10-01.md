---
title: The speed of radix sort
number: 1167
tags: [Misc](index-misc), Technical
blurb: More joy with C
version: 1.0
released: 2021-10-01
current: 
---
This semester, I'm teaching CSC-301, _Algorithm Analysis_.  I love
CSC-301; I consider the material the heart of computer science.
Students learn techniques for designing, implementing, and analyzing
data structures and algorithms.  Students also learn some of what
many consider the "primary literature" of computer science; the
data structures and algorithms that most good computer scientists
know how to use and implement.  The course involves theory (or at
least math), but students also learn a lot from implementing
algorithms.  That is, like all the best CS courses, it combines
both sides of the discipline.

I'm either incredibly nice or fairly mean: I make them implement
algorithms in each of the three languages they should know from
prerequisite courses: Scheme, C, and Java [1].  I don't ask them to
implement each algorithm in each language, but I'll suggest, for
example, that they should do balanced search trees in Scheme and
Quickselect in C. 

We're currently exploring issues related to sorting.  We've talked
about general issues of sorting and proven that all comparison-based
sorting algorithms are in Omega(nlogn).

Today we did the two primary O(n) sorting algorithms: bucket sort
and radix sort [2].  I love radix sort.  If you do it by hand,
which I have students do, it's almost impossible to tell what's
happening.  Then, in the final round, the values "magically" end
up in sorted order.  The informal proof of correctness also involves 
loop invariants, which can be a nice lead into our discussion of
loop invariants.  I think I have that scheduled for next week.

As I noted, we did radix sort by hand.  That is, I had my students
do a live demo of radix sort using a set of large cards with letters
and corresponding binary values today.  I think the students had
fun.  And it was a reminder that you can execute algorithms without
understanding them [3].  In some years, I've prepared "punch cards",
which permit me to do parallel radix sort.  Unfortunately, with the
office move this year, I couldn't find them [4].

Surprisingly, I ended up with about twenty minutes left at the end
of class.  That's rare.  Traditionally, I over-prepare rather than
under-prepare.  So I said, 

> We can implement radix sort in C in the next fifteen minutes, right?

And we set forth.  I cheated a bit.  I was the driver and asked all
of them to be navigators.  But I followed reasonable driver practices;
I explained what I was doing at every step, I checked in quickly, and
I asked questions when I was stuck.  They were also good navigators,
catching stupid mistakes on my part, such as switching the array I used
for accumulating the values with zero at a particular position and
the array I used for the ones.

I also cheated in that I didn't decompose the program into separate
files.  But with fifteen minutes, one just sees if they can get
something working.

I haven't written radix sort in the past five years.  Come to think
of it, I'm not sure if I've ever written radix sort.  But I've
recently written code to convert `argc` to an array of integers and
also code to print out an array of integers [5].  So those tasks
were quick.  And radix sort is a straightforward algorithm.

The first compile was a failure.  I'd given the wrong signature for
`main`.  I also thought I was using `strtol` wrong and so replaced
it with `atoi`.  (It is likely that I was using `strtol` correctly,
and the incorrect signature for `main` was the cause.)

The second time through, the compile worked.  And it sorted a variety
of inputs!

Monday, we may need to have a discussion as to the implications of
the speed at which I wrote that code, particularly with regards to
my assumptions of what they can get done in eight hours.  (I usually
rely on a four-to-one ratio of their time to mine.)

---

For those who care, here's the code.

```
#include <stdio.h>
#include <stdlib.h>

/**
 * A quick and dirty implementation of radix sort.
 *
 * Sam Rebelsky
 * And the Students of CSC-301-02 2021Fa
 */

// +-----------+-----------------------------------------------------
// | Constants |
// +-----------+

#define MAX_VAL 2048
#define BITS 11

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Sort vals, of size n, using radix sort.
 */
void
radixSort(int vals[], int n) {
   int bitmask = 1;
   int zeros[n];        // Place to store zeros
   int ones[n];         // Place to store ones
   int z = 0;           // Number of values in the zeros array
   int o = 0;           // Number of values in the ones array

   for (int k = 0; k < BITS; k++) {
     // Clear out the arrays
     z = 0;
     o = 0;
     // For each value in vals
     for (int i = 0; i < n; i++) {
       // Add to the correct helepr array
       if (vals[i] & bitmask) {
         ones[o++] = vals[i];
       }
       else {
         zeros[z++] = vals[i];
       }
     } // for
     // Shove them back in vals in the correct order
     int i = 0;
     for (int j = 0; j < z; j++) {
       vals[i++] = zeros[j];
     } 
     for (int j = 0; j < o; j++) {
       vals[i++] = ones[j];
     } // for
     // Shift to the next digit
     bitmask = bitmask << 1;
   } // for
} // radixSort

void
printInts(int vals[], int n) 
{
  printf ("{ %d", vals[0]);
  for (int i = 1; i < n; i++) {
    printf (", %d", vals[i]);
  } // for
  printf (" }\n");
} // printInts

int
main (int argc, char **argv)
{
  int vals[argc - 1];
  for (int i = 1; i < argc; i++) {
    vals[i-1] = atoi(argv[i]);
  } // for
  radixSort(vals, argc-1);
  printInts(vals, argc-1);
} // main
```

Such a beatiful algorithm, even if it's not a great setting.

---

[1] The argument for nice: I'm building their skills at thinking
in multiple paradigms and in programming in different languages.
The argument for mean: I require that they recall languages that
they may not have used in a while.  Plus, depending on the student,
C, Java, or Scheme may feel like a form of torture.  I find joy in
each.  Of course, I use techniques that are more fun in Java, like
anonymous inner classes and lambdas.

[2] If we've just proven a lower bound of Omega(nlogn), how are we
able to sort in O(n)?  The lower bound is only for *comparison-based*
sorting algorithms.

[3] We run the algorithm, looking at the results as we go.  Then I
challenge them to explain what just happened.

[4] Arguably, I might not have been able to find them in my old office.
However, I did find my other sorting cards, so it's more likely that they
got separated in the move.

[5] I said something like, "This is probably the 150th time I've written
code to print an array of integers."  I didn't say "You think I'd learn
to keep it handy."  But it may have been faster to rewrite it than to
find it.
