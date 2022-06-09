---
title: Cycles of technology
number: 1191
tags: [Miscellaneous](index-misc), technology
blurb: Can neural networks muse?
version: 1.0
released: 2022-06-07
current: 
---
As some of you may know, I'm a bit of a Papert-style Constructionist
[1,2].  In particular, I believe that students learn better by doing
and experimenting, especially when they are free to explore topics
of interest.  I have not mastered integrating Constructionism with
the perspective that "everyone should learn _x_ to get on to the
next class" [3], which means that my classes are not fully Constructionist.
Nonetheless, I look for ways to incorporate it into my teaching and
research.

The other day [4], I was looking for books by Papert [6].  And I
was reminded that, before he started experimenting with how children
learn, Papert worked with Minksy on "Perceptrons", a model of
computer learning and artificial intelligence.  Perceptrons were one
of the early  kinds of neural networks.

I ended up on Amazon's page for one version of the book and found
the following in a review.

> But of even greater significance, the history of the perceptron demonstrates the complexity of analyzing neural networks. Before this reference, artificial neural networks were considered terrific, after this reference limited, and then in the 1980s terrific again. But at the time of this writing, it is realized that despite physiological plausibility, artificial neural networks do not scale well to large or complex problems that brains can easily handle, and artificial neural networks as we know them may actually be not so terrific. [8]

I found the review amusing, in part, because about fifteen years
after it appeared, neural networks once again became popular, this
time as one of the critical mechanisms for machine learning.  As the
reviewer notes [9], one thing that made them popular in the 1980s
was that folks began to understand you could implement multi-layer
networks.  But it took until the 21st century until we had enough
computing power (and, I suppose, data) to make neural networks a
success.

---

It should not surprise me that it takes some ideas many years to
become popular or successful.  For example, we've been teaching
functional programming in the first CS course at Grinnell since
about 1995.  I kept telling students that "functional programming
will become the next hot paradigm after object-oriented".  These
days, it's hard to use a modern Javascript toolkit without some
understanding of anonymous and higher-order procedures [10].  Of
course, I wasn't completely correct: We've reached a stage in which
modern languages no longer focus on a single paradigm; multi-paradigm
programming is the way to go.

Functional [11] programming also has a long history.  John Backus,
the primary architect of FORTRAN [12], wrote about the power of the
functional paradigm in his 1977 Turing Award lecture [14].  Another
John, John McCartney, included functional aspects in the original
version of LISP [15] in the late 1950s.  Going back even further,
Church's Lambda Calculus from the 1930s grounds the development of
functional thinking.  Was it popular when McCarthy decided to add
it to LISP?  I'm not sure.

Moving forward, Paul Graham took advantage of functional programming
in building Yahoo Stores in the mid 1990s.  But it turned out that
too few programmers could understand functional programming to
maintain them, so Yahoo Stores got rewritten in some object-oriented
language [16].

Why is the functional approach now so important?  Is this another
case in which we needed to wait until computers were powerful enough?
I'm not sure.  Many advances made functional languages more tenable
to those who complained about their inefficiencies, particularly
inefficiencies associated with garbage collection.  Or, given how
much some people struggle with the functional model, perhaps we
just needed to wait until there were enough people who'd studied
LISP (or its variants) who had leadership positions.  Someone out
there might knows.  Maybe I should ask my youngest son.  Or maybe
one of my colleagues can share wisdom.

---

A few years ago, I attended a talk by Alan Kay in which he demonstrated
how easy it is for a child to make a drivable car in Scratch.  I'd
swear I'd seen him give a similar talk at EdMedia 2001 [17], long
before Scratch existed.  And, as Kay suggested in 2018 (or whenever
I saw him most recently), all of the ideas he was showing were
available in Smalltalk [18] in the late 1970s.  Some great versions
of Smalltalk existed long before Scratch, including versions for
the Mac.  Why didn't Smalltalk become more popular?  And why are
there now many variants?  More questions I don't understand.  But
I do think I need to learn one better.

---

Then I find myself thinking about IDEs.  Tom Reps developed the
Synthesizer Generator in the early 1980s. While I see elements of
structure editing in modern IDEs, I still wonder whether his vision
of editors that only permit syntactically correct fragments will
become the standard.  Or perhaps they are common.  It doesn't help
that I'm still tied to a vi [20] mindset.

---

I realize that these are just a few examples.  The cycles are not
uncommon.  Or at least the long delays between great idea and
popularity are not uncommon.

I wonder what unpopular computational idea/technology---with a small
core of adherents and that has lost (or never had) broader
support---will next become popular.  If I knew, I suppose I could
become famous or rich or influential [21].  Oh well.  I do well
enough.

But what if I got to choose?

Hmmm ...

I remain enamored of HyperCard and HyperTalk.  They empowered
their users, and they did so in ways differnt than the Web or
Scratch.  Even my amazing wife could make her own stacks.  I still
don't understand why Apple killed it [22].  In any case, I'd love
to see a return of something more like HyperCard.  Maybe it exists
and I don't know about it [23].

However, as I said, HyperCard was about user empowerment.  And,
sadly enough, it's not clear that user empowerment is at the center
of most technology development.  I don't think "user empowerment"
will ever reach the top of technology's wish list; it's too hard
to monetize.

So let's look for something more in the domain of programmers.  I
know!  A broader embrace of referential transparency would be
awesome.

Or perhaps amusing.

Just not as exciting.

Of course, most people don't find the mathematics of neural networks
all that exciting, and, at the core, that's what _Perceptrons_ is
about.

---

**_Postscript_**: I thought about including a note about hypertext
being one of those cycling technologies, but I expect enough has
been written about that.

---

**_Postscript_**: Now I wonder whether "(re)-learn Smalltalk and
LiveCode" should be parts of my "what to do in your spare time"
plans.  I should also play more with PostScript [25].

---

**_Postscript_**: Other potential topics that come to mind as
possible front-runners include program synthesis, language-oriented
programming, and textual user interfaces.

---

[1] Papert-style Constructionism is not the same as Social Constructionism.
The former is an educational theory focused on learning by doing; the
latter is a hypothesis on the broader construction of knowledge.

[2] One of my friends who studied under Papert says that I'm not nearly
enough of a Constructionist.  It was interesting to watch them teach and
sad to see College-age students' discomfort with the model.

[3] Perhaps I never will.

[4] To be precise, "the other day" means "yesterday" [5].

[5] All my troubles were so far away.

[6] I'm still hoping to find affordable copies of the two anthologies
on Constructionism.  I'll probably ILL [7] them later this summer.

[7] Inter-library loan.

[8] Schneider, Howard (27 Nov. 2000).  Deja Vu.  Amazon.com review.
Available at <https://www.amazon.com/Perceptrons-Introduction-Computational-Geometry-Expanded/product-reviews/0262631113/>.

[9] That note is in the part that I did not include.

[10] There's still not enough understanding of the value of referential
transparency.  Programmers are too wedded to state.

[11] Grammarly says that I use "functional" too much and should
therefore change it to "available programming".  Sorry, Grammarly,
but it's not the same thing.

[12] I feel like it should be written ForTran, since it's an
abbreviation of "Formula Translator".  Nonetheless, the FORTRAN
team named it with all caps, so I use that form.

[14] Backus, J (1998). "Can Programming Be Liberated From the von Neumann Style? A Functional Style and its Algebra of Programs."  _Communications of the ACM_, Vol. 21, Num. 8. pp. 613-641.  <https://dl.acm.org/doi/10.1145/359576.359579>

[15] As you might expect, I'd prefer LiSP, for "List and Symbolic Processor".

[16] Perhaps one of many reasons that Yahoo has not retained its leadership
in technology.

[17] It's hard to believe that I chaired a conference with Alan Kay as
keynote.  I should have talked to him more.

[18] I have no concerns about that capitalization, although I did almost
write it as SmallTalk [19].

[19] I also have trouble remembering whether it's "JavaScript" or
"Javascript".

[20] "vi" is pronounced "vee eye".  It appears that "vi" stands for
"visual instrument".  

[21] I suppose that would also require marketing skills and the right
amount of luck.

[22] Here's a claim that I've taken from the unexpectedly-found Web page at <https://retrocomputingforum.com/t/why-hypercard-had-to-die-article/583>.

> You have a historical error here. I was on the HC team when it
was killed. It was killed when Claris was returned to Apple in 1992,
long before Steve Jobs returned (1997). This is the reason I left
the team. The official reason given to us by the execs was "there
is no way to make money on a product we give away for free". I
believe that Jean Louis Gassee was the man mover behind this despite
opposition from John Sculley who was on his way out anyways. It was
part of J.L. general attempt to kill all multi-media work at Apple.
I believe he was paving his way to BeOS and wanted to destroy the
competition.

I believe the page took that claim from elsewhere.

[23] I have heard that LiveCode serves as a kind of successor.  But
it doesn't have the widespread adoption that HyperCard had.  And it's
not free [24].

[24] There was a community edition of LiveCode.  However, [it has
been discontinued](https://livecode.org).

[25] Capitalization verified.
