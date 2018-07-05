Tracing citations
=================

*Topics/tags: [Teaching](index-teaching), short*

As I was preparing my notes for [a panel at
reunion](https://www.cs.grinnell.edu/~rebelsky/musings/reunion-panel-2018-05-31),
something about binary search came up.  I teach binary search a lot.
Binary search an important algorithm and provides one of the first
instances in which students learn the power of divide and conquer.  But
binary search is also useful for other reasons.  It's an algorithm that
seems simple, but has some subtleties that make it hard to implement
correctly.  So I also use it to talk about ways to verify algorithms.
I use it as an example to consider how we test more thoroughly than is the
norm in unit testing.  I use it to introduce loop invariants.  And, best
of all, even the supposedly correct implementation that Sun/Oracle used
in Java had a bug.

But you knew that already.  I've written about [the algorithm and the
appropriate signature in C](cnix-binary-search-1), [a good strategy
for testing binary search](cnix-binary-search-2), and [strategies for
writing a correct binary search algorithm](cnix-binary-search-3).

I can't exactly remember what was on my mind as I was incorporating
binary search into a panel about post-truth America, other than "I like
my students to learn to think about how they can tell an algorithm
is correct; I find examples like binary search useful to help them
understand that these are hard problems and even experts make mistakes."
There must have been something more.

Anyway, in writing my notes for the panel, I was thinking
about binary search and decided to verify my memory to the
effect that "Although binary search was first published in
the 1950's, the first correct version of binary search wasn't
published until the early 1960's."  I started with the [blog post
about someone at Google finding a bug in the standard Java binary
search](https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html).
In that post, Joshua Bloch traces the statement to Bentley.

> In _Programming Pearls_, Bentley says "While the first binary search was
published in 1946, the first binary search that works correctly for all
values of n did not appear until 1962." [1]

I didn't have the second edition of _Programming
Pearls_ at hand, so I looked back to [the original
column](https://dl.acm.org/citation.cfm?doid=358476.358484).  There, 
Bentley traces the comment on correctness to Knuth.

> In the history in Section 6.2.1 of his _Sorting and Searching_, Knuth
points out that while the first binary search was published in 1946,
the first published binary search without bugs did not appear until 1962." 
[2], p 1040.

The first version of Bentley [3] mimics this text with a slight change
in punctuation [4].  What about the second edition?  That will take some
more time to find.



Sam notes that the first edition of Bentley mimics the original paper.  What
about the second edition.  And those are very different things.

---

The Google 'blog also says that Bentley's implementation is wrong.  Is it?
The one in CACM is in Basic.  Does Basic have limitations?

---

[1] Joshua Bloch.  2006.  Extra, Extra - Read All About It: Nearly
All Binary Searches and Mergesorts are Broken.  _Google AI Blog_
(2 June 2006).  <https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html>.

[2] Jon Bentley. 1983. Programming pearls: Writing correct programs. Commun. ACM 26, 12 (December 1983), 1040-1045. DOI=<http://dx.doi.org/10.1145/358476.358484>

[3] Jon Bentley.  a1986.  _Programming Pearls_.  Reading, MA: Addison-Wesley.

[4] In the book (P. 36) Bentley writes,

> I was amazed: given ample time, only ten percent of professional programmers
were able to get this small program right.  But they aren't the only ones
to find this task difficult: in the history in Section 6.2.1 ....

In contrast, the paper has a full stop after "find this task difficulty"
and "in the history" starts a new sentence.

the 
paper starts a new sene

---

*Version 0.5 of 2018-07-04.*
