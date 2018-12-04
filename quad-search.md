Quad search
===========

*Topics/tags: [The joy of code](index-joc), technical, long*

The other day, a student asked me to conduct a mock interview with them [1].
So I dug deep into the recesses of my brain and pulled out one of the kinds
of interview questions that often serve as part of the traditional "write
an algorithm at the whiteboard" interviews [2].  At this point, I think
most of the common questions have been published on the Interweb, but our
students are generally responsible in that they try to solve problems,
rather than memorize solutions.

In any case, the problem that I chose is one I think of as "quad search".
It goes as follows.

> Your input is a two-dimensional array, _A_, and a value, _v_.  _A_ has
_n_ columns and _n_ rows [3].  Your goal is to determine whether the value
appears in the array [4].

> The array is arranged as follows: Each value in the array is strictly 
less than the value to its right and the value below it.

Most students start by putting up an example array to ensure that they
understand what's going on.  Here's one five-by-five array.


     1   8   9   23   24
     4   9  10   40   42
     5  18  19   41   43
    11  21  22   50   51
    23  24  25   61   62

Can you devise an efficient algorithm for this problem?

>  

> 

> 

>  

> 

> 


Do you have one yet?

>  

> 

> 

> 

> 

> 


There's a simple O(_n_\*_n_) solution: Look at every position.  If you find
the value return true.  If not, return false.

There's a nearly-as-simple O(_n_\*log_n_) solution: Do binary search on each
row.

However, as we suggest to our students, you should always ask yourself:
_Can I do better?_

The student suggested one possible starting approach: Traverse the diagonal
until you either find the value you're looking for, a value greater than
the value you're looking for, or the end of the array.  For example,
if we were looking for 22 in the array above, we'd check 1, 9, 19, 50,
and then stop.

     1   8   9   23   24
     4   9  10   40   42
     5  18  19   41   43
    11  21  22  *50*  51
    23  24  25   61   62

We now have a natural dividing point.  Everything below and to the right
of the too-large value (50, in this case) is larger than the value we're
looking for.  (Proof by transitivity.)  Everything above and to the left of 
the prior diagonal value is too small.  (Proof by transitivity.)  Hence,
we can "throw away" a bunch of values.

     X   X   X   23   24
     X   X   X   40   42
     X   X   X   41   43
    11  21  22    X    X
    23  24  25    X    X

We then recurse on the two remaining quadrants.  Since they aren't
necessarily square, the recursive case is a bit more complex, but it
seems doable.  And, well, you don't want to make copies of the
two quadrants, so you need a helper that has the start row and
the start column.

These non-square areas complicate the analysis of the algorithm.  For a
square matrix, you know that you are guaranteed to throw away at least
half of the matrix.  But for a non-square subarray, you can't make that
guarantee.  Consider, for example, a 2x10 or 10x2 subarray.  So I didn't
ask for a deep analysis and spent the rest of the board interview asking
the student to generate pseudocode and to think about troublesome cases.

I thought I knew a better algorithm, but I couldn't recall it during
the interview.  So, something in the back of my head kept bugging me
to try to figure out how efficient this algorithm was.  I decided to
start with an experiment in which I determined the most expensive 
value to search for and the location associated with that value.

The details of the `twod` type I defined are straightforward enough that
they're not worth repeating here.  But let's look at the algorithm
as I implemented it.

    /**
     * The kernel of the first version of the quadsearch algorithm.
     */
    int
    qs1_kernel (twod *twodp, int val, int colfrom, int colto, int rowfrom, int rowto)
    {
      if ((colfrom >= colto) || (rowfrom >= rowto))
        return 0;
      int col = colfrom;
      int row = rowfrom;
      int elt;
      // Explore the diagonal until we encounter a value greater-than or
      // equal to val
      while ((col < colto) 
             && (row < rowto) 
             && ((elt = get (twodp, col, row)) < val))
        {
          col++;
          row++;
        }
      // Did we run out of elements?  Then it's not there
      if ((col >= colto) && (row >= rowto))
        return 0;
      // Did we run out of rows?  Then we need to look at the rest.
      else if (row >= rowto)
        return qs1_kernel (twodp, val, col, colto, rowfrom, rowto);
      // Did we run out of columns?  Then we need to look at the rest.
      else if (col >= colto)
        return qs1_kernel (twodp, val, colfrom, colto, row, rowto);
      // Did we find the element?
      else if (val == elt)
        return 1;
      // Otherwise, we need to search the two quads
      else
        return qs1_kernel (twodp, val, col, colto, rowfrom, row)
               || qs1_kernel (twodp, val, colfrom, col, row, rowto);
    } // qs1_kernel

    /**
     * The first version of the quadsearch algorithm.
     *
     * Returns 1 if the value is in the array and 0 otherwise.
     */
    int
    qs1 (twod *twodp, int val)
    {
      return qs1_kernel (twodp, val, 0, twodp->cols, 0, twodp->rows);
    } // qs1

Getting the special cases right in the kernel was a little harder than
I expected.  I screwed up the last recursive call in my first attempt
and needed to draw a diagram to figure out the right bounds.  I probably
should have drawn the figure to start with.  After that change, my unit 
tests suggested it was correct [5].

Next up was the code for finding the worst value to look for.  I set up
a systematic NxN array to make things a bit easier to check.  Here's the
sample 10x10 array.

       0   2   4   6   8  10  12  14  16  18
      20  22  24  26  28  30  32  34  36  38
      40  42  44  46  48  50  52  54  56  58
      60  62  64  66  68  70  72  74  76  78
      80  82  84  86  88  90  92  94  96  98
     100 102 104 106 108 110 112 114 116 118
     120 122 124 126 128 130 132 134 136 138
     140 142 144 146 148 150 152 154 156 158
     160 162 164 166 168 170 172 174 176 178
     180 182 184 186 188 190 192 194 196 198

Here's the code I used to explore the different costs.  (I annotated the
`qs1_kernel` code to increment `QS_GETS` every time it called `get`.)

    // Check cost
    int maxgets = 0;
    int totalgets = 0;
    int worst = 0;
    int count = 0;
  
    for (val = -1; val < 2*N*N; val++)
      {
        QS_GETS = 0;
        qs1 (predictable, val);
        if (QS_GETS > maxgets)
          { 
            maxgets = QS_GETS;
            worst = val;
          }
        totalgets += QS_GETS;
        count += 1;
      } // for val
    printf ("Most expensive value: %d, taking %d gets\n", worst, maxgets);
    printf ("Average cost: %d\n", totalgets/(2*N*N+1));

Can you tell what value to search for that will result in the most
calls to `get`?

>

>

>

>

>

>

My experiment suggests that it's 196 or 197.  Why?  Let's think about it.
We explore the diagonal until we find the 198 in the lower-right-hand
corner.  That's ten steps, or *n* steps, in the general case.

      X   X   X   X   X   X   X   X   X   18
      X   X   X   X   X   X   X   X   X   38
      X   X   X   X   X   X   X   X   X   58
      X   X   X   X   X   X   X   X   X   78
      X   X   X   X   X   X   X   X   X   98
      X   X   X   X   X   X   X   X   X  118
      X   X   X   X   X   X   X   X   X  138
      X   X   X   X   X   X   X   X   X  158
      X   X   X   X   X   X   X   X   X  178
     180 182 184 186 188 190 192 194 196  X

Now we have a column and a row to explore.  The code has us explore the
column first.  Each has nine values to examine (or *n*-1 in the general
case).  So our cost is 28 calls to `get` [6].

The experimental analysis suggests that this algorithm takes slightly
less than 3\*_n_ steps, making it an O(_n_) algorithm.  But I don't
think I want to prove that running time.

---

Writing that algorithm inspired me to think about another, slightly
different, approach.  Rather than traversing the diagonal, we could
look in the "center" of the subarray (middle row, middle column).
If the value matches, we're done.  If the value is too small, we
can throw away the upper-left quadrant and recurse on the other
three quadrants.  If the value is too large, we can throw away the
lower right quadrant and recurse on the other three quadrants.

Interestingly, my initial implementation of that algorithm ended up
being *worse* than the diagonal algorithm.  In particular, my search
for -1 resulted in 46 calls to `get`.  Is the problem the algorithm
or my implementation?   Here's the implementation.  Perhaps someone
wants to look for flaws.

    int
    qs2_kernel (twod *twodp, int val, int colfrom, int colto, int rowfrom, int rowto)
    { 
      if ((colfrom >= colto) || (rowfrom >= rowto))
        return 0;
      
      int col = (colfrom + (colto - colfrom)/2);
      int row = (rowfrom + (rowto - rowfrom)/2);
      
      int elt = GET (twodp, col, row);
      int result;
      if (elt == val)
        result = 1;
      else if (elt < val)
        result = qs2_kernel (twodp, val, col+1, colto, rowfrom, row+1)
                 || qs2_kernel (twodp, val, colfrom, col+1, row+1, rowto)
                 || qs2_kernel (twodp, val, col+1, colto, row+1, rowto);
      else // if (elt > val)
        result = qs2_kernel (twodp, val, colfrom, col, rowfrom, row)
                 || qs2_kernel (twodp, val, col, colto, rowfrom, row)
                 || qs2_kernel (twodp, val, colfrom, col, row, rowto);
      return result;
    } // qs2_kernel
    
    int
    qs2 (twod *twodp, int val)
    {
      return qs2_kernel (twodp, val, 0, twodp->cols, 0, twodp->rows);
    } // qs2

I've used three subarrays.  I wonder whether it might make more sense
to try two subarrays.  Let's see. The only code I have to change
is the recursive calls.

      if (elt == val)
        result = 1;
      else if (elt < val)
        result = qs3_kernel (twodp, val, col+1, colto, rowfrom, row+1)
                 || qs3_kernel (twodp, val, colfrom, colto, row+1, rowto);
      else // if (elt > val)
        result = qs3_kernel (twodp, val, colfrom, colto, rowfrom, row)
                 || qs3_kernel (twodp, val, colfrom, col, row, rowto);

That strategy cuts it to 30 calls to `get` in the worst case, which is
still the value -1.  But if I change the array size to 20x20, the number
of calls to `get` is 71.  That result suggests that the worst case is
not just 3\*_n_.  Doubling again to 40x40 yields 163.  My algorithm
does not seem to be linear.

---

Let's check that diagonal algorithm again.  A 10x10 array requires 
28 calls to `get`.  A 20x20 array requires 58 calls to `get`.  A
40x40 array requires 118 calls to `get`.  A 41x41 array requires
121 calls to `get`.  Yup, that's pretty clearly taking 3\*_n_-2.

---

I could probably make the diagonal algorithm more efficient by adding some
special cases.  If the subarray is one-dimensional (e.g., a single column
or row), binary search should suffice.  And we could also use binary
search on the diagonal to find the first value greater than or equal
to the sought value.  Would that make a huge difference?  I'm not sure.
It adds enough complexity to the code that it's likely that I would get
something wrong.  But if I expected to run the algorithm millions of
times, it might be worth considering [7].

---

That's one of the things I love about algorithm design (and, more
generally, about computer science).  You come up with an idea.  You
write code to explore the idea.  You come up with other ideas, some
of which may even seem better.  But you can explore them and learn
from the exploration.

---

[1] Unfortunately, a mock interview is not one in which I get to mock the
student.

[2] There are many problematic issues about these interviews, and they've
been shown to prioritize a certain kind of candidate.  Nonetheless, they
continue to be a central part of most tech recruiting for both internships
and full-time positions.

[3] Why is that we talk about two-dimensional arrays as rows-by-columns
but two-dimensional matrices as columns-by-rows?  It always confuses me.

[4] An alternate version of the algorithm asks you to return the position
of the value in the array.

[5] I used a similar strategy for testing quadsearch that I use for testing
binary search: I built an array systematically and then searched for every
value in the array and a reasonable set of values not in the array.

[6] 3\*_n_ - 2, in the general case.

[7] If I expected to run the algorithms millions of times on the
same data, I'd reorganize the data.

---

*Version 1.0 of 2018-12-03.*
