Identifying the missing value
=============================

*Topics/tags: [The joy of code](index-joc), technical, interview questions, short*

Today another student asked me to give a mock interview [1].  This
interview involved smaller questions, rather than one big problem.
One of the questions I asked falls in the category of questions that
try to test intuition, but mostly test whether you've seen the problem
before or not.  Nonetheless, I thought the conversation we had was
fun, and so I'm reporting it here.

Let's start with the problem:

> You have an array of size _n_-1 containing values between 1 and _n_.
No value appears twice.  One value does not appear at all.  Identify
the missing value.

If your brain works just right, you've come up with an efficient solution
almost immediately.

I'll give you a bit of time [3] to think about it.

One.

Two.

Three.

Four.

Five.

Six.

Seven.

Eight.

Nine.

Ten.

Eleven.

That should be enough. Do you have a solution?  Here's a typical one.

> Sort the array from smallest to largest.  If the first value is not
one, one is missing.  If the last value is not _n_, _n_ is missing.
Otherwise, iterate the array until you find a "gap".

How efficient is the algorithm?  One should, of course, give both time
and space complexity.  The answer is "It depends".  On what?  On the
sorting algorithm you use.  If you use one of the efficient in-place
compare-and-swap algorithms [4], the algorithm requires O(_n_ log _n_)
time and O(1) space.  However, for numbers in a restricted range, bucket
sort or radix sort may be more appropriate.  In that case, the algorithm
requires O(_n_) time and O(_n_) space.

As is my habit, I asked "_Can you do better?_" [6].  In this case, it's
pretty clear that you have to look at every element at least once, so
"better" means O(_n_) time and O(1) space.

Can _you_ do better?

Eleven.

Ten.

Nine.

Eight.

Seven.

Six.

Five.

Four.

Three.

Two.

One.

Eventually, the student came up with an in-place bucket-sort algorithm
and an argument that it ran in O(_n_).

But I'm mean.  So I asked him to assume that the array was immutable.
Do you have a solution in that case?  Let's pause again.

Cosine.

Tangent.

Secant.

Sine.

Three.

Point.

One.

Four.

One.

Five.

Nine.

I believe the answer most interviewers want their subjects to come up 
with is as follows.

> I know that the sum of the numbers from 1 to _n_ is _n_*(_n_+1)/2.
So I can sum the numbers in the array and subtract it from that number,
giving the missing number.

Wasn't that fun?

---

Postscript: If I give away all of my mock interview questions in these
musings, what will I do when I have to do my next mock interview?  Perhaps
I'll need to build up my stock.

---

[1] No, I did not mock them all that much, except when (a) they forgot
about heap sort and (b) they claimed that lookup in hash tables is 
linear [2].

[2] I prefer to hear the adjectives "amortized" and "expected" when
talking about hash tables.

[3] Or at least a bit of space.

[4] Heap sort and Quicksort are the traditional choices [5].

[5] Yes, this is the point that the student forgot about heap sort.

[6] "Can I do better?" is a question I encourage students to ask
themselves regularly when they write algorithms.

---

*Version 1.0 of 2018-12-19.*
