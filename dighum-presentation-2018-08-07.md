Preparing for a presentation on the new digital-humanities CSC 151
==================================================================

*Topics/tags: [Talks](index-talks-speeches), CSC 151, Digital humanities*

This coming Thursday, I'm giving a short presentation
at the [2018 Digital Bridges for Humanitistic Inquiry
symposium](https://dbsymposium2018.com/schedule/) about the new version
of CSC 151 that focuses on the digital humanities.  It's a bit strange
to be presenting about that topic now, since I've yet to develop the
full syllabus for the class, let alone teach it [1].  But I was asked
to speak, and so I shall.

The Digital Bridges folks are sensible and asked for slides in advance
of the presentation.  In part, that helps the panel chair organize things.
In part, it likely helps ensure that we don't prepare for the talk at
the last minute [2].  So I'm spending today trying to get the slides in
order.  Musing about the task at hand is likely to help me do a better
job, or at least will help get me started.

What are the guidelines?  Let's see ...

> We are then asking you to discuss the project you’ve worked on with
support from the Digital Bridges grant for 5-7 minutes (tops). If you
would like to use images (PPT, Keynote, etc.) we ask that you send us
**no more** than 5 slides.

> In your presentation about your project, we encourage you to do two
things: (1) Introduce yourself very briefly.  (2) Explain what the
project is, why it is exciting, and how you are using it—concisely
and energetically. (à la 3-minute thesis).

Five slides.  That's not a lot.  I usually go through ten slides in a
five-to-seven-minute talk.  I assume one of them should be a cover slide.
I'll do without the traditional future work, questions, and citations
slides.  In this case, everything I'm talking about is future work.
They've already planned a Q&A session.  And I can just put citations on
the slides.

So, what do I want to talk about?  I've [recently decided that
the course should have three topical foci](csc151-dighum-blurb):
document representation (with SXML), document synthesis, and document
visualization and analysis [3].  But I'm in a session entitled "Teaching
Textual Analysis".  Does that mean I should focus on the last issue?  Nah.
So I should give a short overview of what it means to teach those things.
I'll probably want to mention something like topic modeling [4] and
what it means to do an intermediate overview of the LDA algorithm [5].
So that's two of the five slides: One on "approaches to digital humanities
in the CS classroom" and one on "understand and build the algorithm".

I also need a cover slide to introduce everything.  That leaves me
with two more.  A "context" slide is likely to be useful.  That slide
can provide past history.  For example, CS regularly provides students
who serve as programmers for digital humanities projects; many of them
have indicated that working on those projects broadened their horizons.
But it's also worth mentioning that we regularly do "themed" versions of
CSC 151 and the reasons we do so [6].  And I should make it explicit that
the primary learning outcomes of the course relate to computer science
concepts, not digital humanities concepts.  Or maybe that should be a
separate slide.  I can see some value from having a scale balanced
toward CS.

That leaves me with five slides.

* Slide 1: Cover
* Slide 2: Context
* Slide 3: Content
* Slide 4: Comp Sci
* Slide 5: Combining

I could do slides two through five as bullet points.  There is, after
all, some value to bullet points.  For example, having text on the screen
helps people who get distracted re-orient themselves [7].  Text-based
presentation are also more likely to stand on their own.  Plus, it's
much faster to write bulleted presentations.

But I know that image-based presentations are more effective.  So once
I've put together the bullet points, I'll work on finding appropriate
images.  (I may even mention likely images along the way.)

**Context**

* Focus: Introductory CS course.  *Hmmm ... what image represents introductory
  CS?  Maybe some program code.* [ 8]
* Supporting interactions between CS and the Humanities.  
* Evidence: Themed courses increase diversity.  *I'd like to combine two
  images with an arrow between them.*
* Workshop-style course.  *I can probably find a pair-programming image.*
* Using Scheme.  *I'll probably use the DrRacket logo.*
* Future work.  *Maybe a calendar?*

Agh!  Building that as an image-based slide took an hour.  Revising it
took another hour.  And, well, it's a bit of a mess in the static form.  
Now I remember why I'm always tempted to fall back on text.

**Content**

* Document format: XML.  *I'll generate some sample XML.  Should I
  also draw a tree?  Nah, not for this audience.  What about the great
  Paul Graham quote on XML [9]?  I'll paraphrase and not put it on the
  slide.*
* Document creation.  *I can draw a simple web of arrows and maybe add
  a bit of Scheme code to show the combination.*
* Document analysis.  *I'm lazy.  I'll just draw a magnifying glass.*
* Computer science.  *I'll keep the picture from the previous slide.*

**Computer Science**

I can't resist.  I'm redrawing the previous slide with the CS picture
overlapping everything else.  But what should the bullet equivalents be?

* Algorithms
* Data Structures
* Efficiency
* Elegance
* Ethics
* Reuse
* Robustness [10]
* Recursion

**Combining**

Okay; that's a  horrible title.  I was just having too much fun with
"Co" words.  Really, the last slide is an example.  And I'm tired.
For this one, I'll stick with bullet points.

* Context: Why is topic modeling a useful tool?
* Algorithm: How does LDA work?
* Data: How do we store/represent the data LDA uses?
* Implementation: Build a simplified version.
* Experimentation: What are the effects of changing [this part]?
* But not: Let's understand the statistics  

**Epilogue**

All told, I spent a bit over four hours on the slide deck.  I could have
spent more, but I had to turn it in.  The worst parts are (a) knowing that
I really need to redesign the whole thing and (b) realizing soon after
I sent them in that I wanted ot make more changes.  Oh well, that' s an
issue for another time.

Coming in a future musing: My attempt to write out the text of my
presentation.  I'm not accustomed to writing presentations; I generally
ad lib.  But it seems like I might be better writing this one.  We'll see
if I have time.

---

[1] I'm spending the fall developing the course and I'll teach it in the
spring.

[2] I will note that I wrote some of my best talks, including my legendary
"finish in exactly five minutes" lightning talk at SIGCSE, in the evening
before the talk.

[3] Is that four things?  From my perspective, visualization is a part of
analysis.  So I'll leave it as three.

[4] Reminder to self: [This article by David
Blei](http://journalofdigitalhumanities.org/2-1/topic-modeling-and-digital-humanities-by-david-m-blei/)
seems to be a good introduction to what topic modeling is.

[5] My students are not expected to know statistics or to be particularly
fond of mathematics, so it is unlikely that we will delve deeply into the
intricacies of why the algorithm works.  But they *can* implement it.

[6] Should I include the Maria Klawe quote about diversity and themed
intro courses?  Probably.

[7] I'm one of the audience members who regularly needs reorienting.  When
I hear an interesting idea, I start turning it over in my head and sometimes
lose track of the main presentation.

[8] In the end, I selected a "Computer Science is more than coding" picture
from <https://www.edsurge.com/news/2015-12-02-computer-science-goes-beyond-coding>.

[9] From Paul Graham's "What Made Lisp Different": 
<http://www.paulgraham.com/diff.html>

> 9\. The whole language always available. There is no real distinction between read-time, compile-time, and runtime. You can compile or run code while reading, read or run code while compiling, and read or compile code at runtime.

> Running code at read-time lets users reprogram Lisp's syntax; running code at compile-time is the basis of macros; compiling at runtime is the basis of Lisp's use as an extension language in programs like Emacs; and reading at runtime enables programs to communicate using s-expressions, an idea recently reinvented as XML. 

[10] I had not originally included "robustness" in the list.  But it's
an important point I wanted to include.  Plus, now I get three "R" words.

---

*Version 0.91 of 2016-08-06.*
