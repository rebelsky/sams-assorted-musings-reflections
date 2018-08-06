A blurb for the new CSC 151
===========================

*Topics/tags: [Teaching](index-teaching), CSC 151, Digital humanities, writing and editing*

In spring 2018, I'll be teaching a new version of CSC 151, Grinnell's
introductory course in cmoputer science that uses the Digital Humanities
as its theme.  This will be the third-and-a-half new version of the
course that I've designed or helped design in my career.  Why half?
When I first taught the course, nearly two decades ago, I kept the
structure of the course generally the same, but made some significant
changes to the course materials and to the pedagogy [1].  A bit more than
a decade ago, Janet Davis, Matthew Kluber, and I reworked the class to
focus on the theme of image making.  At the time, we planned that that
would be the first of multiple "themes" that we developed for the course
so that students could choose a theme closer to their personal interests.
But rewriting the whole course is a lot of work; after all, it's a course
in which we have a daily reading and lab [2].  Last summer and fall,
Titus Klinge, Sarah Dahlby Albright, and I developed a new version of
the course that used the CS side of Data Science as the theme.  And now
I'm developing a third version [3].

The other day, I got a request from the Registrar's office to provide a
blurb for the new version of the course.  I was tempted to reply that I am
on a nine-month contract and am therefore unable to work during the summer
[4].  However, I do believe in collaborating with people across campus,
particularly when the strange policies are not their fault.  Hence,
I'm attempting to write a blurb for the course.  I'll admit that it's a
bit strange to write a blurb for a course that I have not yet designed;
after all, designing the course is my primary goal for the fall.  But I
guess I'll need to do my best.  A musing seems like the best place to 
draft the text.

What do the previous blurbs look like?  Here's the one for the image-based
151.

> In this section of CSC 151, we will ground our study of functional
problem solving in media computation. In particular, we will explore
mechanisms for representing, making, and manipulating images. We will
consider a variety of models of images based on pixels, basic shapes,
and objects that draw. The course will be taught using a workshop style:
In most class sessions, students will work collaboratively on a series
of problems. Includes formal laboratory work.

Here's the data science blurb, which I wrote last year.

> In these sections of CSC 151, we will ground our study of functional
problem solving in approaches related to the practice of data science. In
particular, we will explore and develop algorithms and programs
that gather, reorganize, filter, combine, analyze, and visualize both
structured and unstructured data. The course employs a workshop format:
In most class sessions, students will collaboratively explore a variety
of problems and collections of data. Includes formal laboratory work.

Wow, I certainly have a style for these blurbs.  It goes something like
this [5].

> In this section of CSC 151, we will ground our study of functional
problem solving in approaches related to *topic*. In particular,
we will *activities*.  The course employs a workshop format: In most
class sessions, students will collaborate on a variety of problems.
Includes formal laboratory work.

That's something I should be able to write relatively quickly.  I might
even be able to describe something that resembles what we'll actually
do.  But what is it that we'll do?  I'm still trying to work that out.
We'll certainly consider ways to represent documents, probably focusing
primarily on XML and HTML [6].  I'm actually looking forward to that aspect,
since it gives a clear reason to consider trees.  And I should certainly
give them the opportunity to write one or two simple hypertexts.  I find
algorithms for language generation interesting.  We are likely to use a
[grammar-based approach](code-camps-lac-language-generation)
as well as a more [statistical
approach](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/assignments/assignment07).  However, from my perspective, the most important aspect
of the digital humanities to consider is the algorithmic processing of
texts as a starting point in the analysis of those texts.  And, while I
like thinking of that output in textual terms, I know that it is also useful
to find ways to visualize what the algorithms "discover".   So, "represent,
create, analyze" seem to be the core activities [7].

Here's a start.

> In this section of CSC 151, we will ground our study of functional
problem solving in approaches related to the digital humanities,
investigating ways in which computing changes the ways in which people
write and analyze texts.  In particular, we will consider models
for representing texts, computation-based techniques for developing
interactive texts, and algorithms and visualizations that help us
explore and analyze texts.  The course employs a workshop format: In
most class sessions, students will collaborate on a variety of problems.
Includes formal laboratory work.

But, well, that middle sentence isn't really parallel.  We have "models
for *representing*", "techniques for *developing*", and "algorithms and
visualizations *that help*".  Two gerunds and something else.  But I
can't bring myself to write "for *exploring* and *analyzing*", since the
algorithms should be used as a starting point for exploration and
analysis, not for the exploration and analysis themselves.  So I'm going
to get rid of the gerunds.  I also know from my reading of Williams that
I should make actors explicit.  Here's the next try.

> In particular, we will consider models that scholars use to represent
texts, techniques that authors use to create interactive texts, and algorithms
and visualizations that scholars use as they explore and analyze texts.

I don't like the doubling of "scholars".  I don't like the repetition of
"use".  The latter seems easier to fix than the former.  But perhaps I
can fix both at once.

> In particular, we will consider ways computers help us represent
texts, create interactive texts, and explore and analyze individual
texts and corpora.

But that loses the "algorithms" and "visualization" that I consider core
to what we do.  I'm also not sure how I feel about the repetition of the
word "texts".  Let's try again.

> In particular, we will examine models of documents, develop interactive
narratives, and design algorithms and visualizations that help us explore
and analyze corpora and individual texts.

Better.  How do I feel about the three "ands" in the last part?  It's a
bit excessive, but probably acceptable.  But "interactive narratives"
may not be completely accurate.  At least in some cases, the idea is that
we will fill in information computed from elsewhere.  That's not so much
"interactive" as "dynamic".  Yeah, that's a better word.  How does it
feel when I put everything back together?

> In this section of CSC 151, we will ground our study of functional
problem solving in approaches related to the digital humanities,
investigating ways in which computing changes the ways in which people
write and analyze texts.  In particular, we will examine models of
documents, develop dynamic narratives, and design algorithms and
visualizations that help us explore and analyze corpora and individual
texts.  The course employs a workshop format: In most class sessions,
students will collaborate on a variety of problems.  Includes formal
laboratory work.

What are the primary verbs?  *Ground.  Study.  Investigate.  Change.
Write.  Analyze.  Examine.  Develop.  Design.  Explore.  Analyze.  Employ.
Collaborate.*  It appears that I've only duplicated "analyze".  I know
that there's some benefit in repetition, but this seems to be a case in
which less repetition is better.

What does [Grammarly](https://www.grammarly.com/) say?  It tells me to
hyphenate "problem solving".  I don't think that's necessary.  It tells me
that if I pay for the upgrade, it will tell me about one wordy sentence.
I'm pretty sure I know which sentence is wordy, and I'm comfortable
with it.  It tells me that it will take someone 20 seconds to read it
or 39 seconds to speak it.  It ranks me relatively low on readability,
noting that "Your text is likely to be understood by a reader who has
at least some college education, but it may not be easy to read."  Yeah,
I'm okay with that.

Of course, it's not clear that anyone actually reads these blurbs [8].
It may not be perfect, but it's probably close enough for now.  I'll
call myself done.

---

Is this the last "new" version of CSC 151 that I'm designing?  Almost
certainly not.  Many aspects of the image-based CSC 151 were quite successful
and I'd like to bring it back.  Unfortunately, the most difficult issue
in the course was the interaction with GIMP, which, while exciting,
made it hard for students to run the software on their own computers [9].
In addition, it appears that we did not fully understand all of the issues
associated with writing C-based libraries for DrRacket and the system crashed
once in a while, usually at the least opportune time.  Hence, I'd like to
rewrite the course to use DrRackets own image system, which has evolved a lot
since we first designed the course.  Of course, after I rewrite the course,
I'll also need to rewrite the blurb.

---

Postscript: I've reported on what Grammarly says about the blurb.  What
does it say about this whole document?  We'll just consider some of the
highlights [10].  Blurb has a rank of 92.  Document has a rank of NN.
Blurb takes 20 seconds to read.  Document takes NN.  Blurb is hard to
read.  Document is ....

---

[1] Among other things, I split the readings from the labs and instituted
take-home exams instead of in-class exams.

[2] At the time, the course met four days per week.  So we wrote close to
fifty readings/labs.

[3] Better yet, I have a fellowship that will give me the time to develop
a new version.

[4] My understanding is that I would *have* to give that reply if I were
receiving external funding for the summer.  More on that issue in another
musing.

[5] I could not resist editing a little bit.

[6] And the representation of XML and HTML as SXML in one or more of
its [multiple forms](https://docs.racket-lang.org/sxml-intro/index.html#%28part._.Confusion%29).

[7] I wanted to write "seem to be the *trifecta*" or "seem to be the
"*triumvirate*".  But neither is really the right word.  Perhaps it will
come to me later.

[8] It used to be that they appeared in the printed schedule of classes.
I'm not sure if they still do, but few people receive the printed
schedule.  The blurbs do appear in Web Advisor/Self Service.  However,
they appear as a bit of a mess.

[9] We did come up with solutions, but they generally involved either
installing a virtual machine or installing an X-windows client..

[10] Or lowlights, as it were.

---

*Version 0.8 of 2018-08-06.*
