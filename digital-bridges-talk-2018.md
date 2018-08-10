An approximation of my talk for the Digital Bridges conference
==============================================================

*Topics/tags: [Talks](index-talks-speeches), digital humanities, CSC 151*

In [a recent musing](dighum-presentation-2018-08-07), I discussed the
[slides for my then-forthcoming talk about my plans for the upcoming
digital-humanities-themed CSC151](dighum-presentation-2018-08-07).  But
what about the words I will say?  I was debating between ad-libbing,
which is my normal mode of presenting, and reading a speech, which I've
started to do in some situations.  I've decided to write out an approximation
of the talk as a way to prepare to present.  Whether or not I actually
read the talk will depend on a variety of issues [1].

If you'd like to follow along, you can still access [the deck of Google 
Slides](https://docs
.google.com/presentation/d/15-N0GkmdIKUkzCkEsXFvMfvmCIpjHxPGo1yus-eSewY/edit?usp
=sharing).

---

Good morning.  I'm Sam Rebelsky. I'll be one of the Obermann Digital
Bridges Fellows this fall.  *Change slide*.  Let me start with some
background.

Teresa said that we should introduce ourselves.  *Click to bring
up a picture of SamR*.  As I said, I'm Sam Rebelsky. I use he-him-his
pronouns [4,5].  I've been at Grinnell for twenty-one years.
My colleagues know that that I am opinionated and outspoken.  Since we
are in a country in which Congress has proposed legislation that
encourages high-schools to replace foreign language with "coding" [6],
let me begin by saying that (a) computer programming is not the same as
computer science and (b) among other things, we ask students to learn
a foreign language so that they gain insight into cultures and people
other than their own, which helps them better understand "the other",
to help them develop a stronger understanding of the structures of their
own language, and to build their strengths in navigating ambiguity.
Programming languages provide none of those benefits.

*Click to bring up "computer science" picture.  I'm a computer scientist.  
*Click to bring up "connections to humanities" pictures [7].
I'm here to talk about interactions between CS and the humanities from
my perspective as a computer scientist.  

As you might expect, my colleagues across campus [8] rely on the CS
students to provide support for their digital humanities projects.  
Students who have worked on these projects --- I think particularly
of Jennelle Nystrom, the Reverend Harry Baker, and Ezra Edgerton ---
regularly reported that working on these projects changed their view
of CS.  They also encouraged me to think about ways in which we
could introduce these kinds of ideas earlier in the CS curriculum.
Jennelle also helped me understand how computer scientists approach
these problems differently than "programmers".

For these reasons, and many others, I'm working on a new version of
our introductory course that use "digital humanities" as a theme.
Unfortunately, unlike the other projects you've heard about, mine is
a future project, rather than a past project.  *Click button to bring
up a calendar icon*.  I'm developing the course this fall and won't be
teaching it until spring 2019.

The design of the course is very much informed by current departmental
practices [9].  *Click button to bring up a picture of students pair
programming.* We teach the introductory course in a workshop style.
Students read a few pages before class and spend the majority of class
time working in randomly assigned pairs on a series of problems while
the class mentors and I look over their shoulders and ask and answer
questions.

*Click button to bring up DrRacket logo*.  We use the Scheme
programming language, a variant of Lisp.  That won't change.  I'm
happy to talk offline about the many benefits of using Scheme.

*Click button to bring up an icon of a palette*.  And, for a bit
more than the past decade, we've been teaching the course through
the lens of image making.  Matthew Kluber in Studio Art, Janet Davis
in CS, and I worked to develop that course.

All three practices share one particularly important goal.  *Click button
to bring up an image that represents diversity.*  All have been shown to
encourage a more diverse group to consider and to persist in computer
science.  Maria Klawe, President of Harvey Mudd, notes in particular
that "themed" introductory courses are one of the most successful ways
to support women in the discipline.

I am developing this new course, in part, to encourage a cadre of students
to consider the digital liberal arts from multiple perspectives and to
develop students who can better support digital humanities projects.
I also find this an exciting topic to explore.  At the same time, I hope
that a digital humanities version of the course will continue to grow
diversity in the discipline.  *Click slide to bring up yet another arrow.*

As these courses change who takes the first CS course and who persists in
CS, we hope that we diversify who "does" computer science.  *Click button
to show arrow pointing back to CS.*  Diversifying the discipline is a
core part of our mission.  Given computer technology's great impact,
the people who develop that technology should represent a wide variety
of identities and perspectives.  *Click*.  And that can change the world.

*Click button to bring up citations.*  *Don't say anything.*

*Click button to bring up next slide.*  So, what might go in an
introductory computer science course with a digital humanities theme?
I learned from sitting in on Erik Simpson's course that it's important
to consider multiple aspects and that it's better to focus on a few than
to give a complete buffet

*Click button to bring up structure image.*  We will spend some time
talking about representations of data, focusing on XML and XML-like
structures.  These structures are particularly natural in a Scheme-based
course.  For example, Paul Graham notes that in many ways, the designers
of XML "rediscovered" the power of Lisp's s-expressions.

*Click button to bring up generation image.*  There is power in making
new things.  While we will explore nonlinear writing, we will also
consider ways to write documents that use code to support dynamic content.

*Click button to bring up analysis image.*  I would be remiss
if I did not include text analysis as a core topic.

We will also cover computer science topics.  *Click button to bring up
CS image.*

*Click button to bring up citations.*  

To be perfectly honest, this is our introductory course in computer
science.  Hence, *click button to bring up view with CS dominating*,
computer science is really our focus.  What do I mean by that?

Among other things .... *Click.*  Students learn to develop and analyze
algorithms.  *Click.* Students think deeply about the ways in which
we organize data.  *Click.* They consider the efficiency and efficacy
of their algorithms and the way data representation affects that
efficiency.  *Click.*  They think of code as language and explore
issues of elegance.  *Click.*  They acknowledge and consider their
ethical responsibilities.  *Click.* The develop general code and
algorithms that can be reused in other situations.  *Click.*  They
reflect on ways their code may break and how they recover from such
situations.  *Click.*  And they learn some complex ways of thinking,
particularly recursion.

*Click to bring up citations*.  *Click to bring up slide on topic
modeling.* Since this is an analysis session, let's consider the example
of topic modeling.  It comes up, in part, from conversations that Liz
Rodriguez and I had when guest teaching Erik's class.  Many people use
topic modeling as a black box, and that's fine.  But I want my students
to approach it as computer scientists.  I'll begin by looking at how
topic modeling can be used and emphasize that it is not intended to
provide answers, only ideas and directions.  Students will then read and
dissect a simplified version of the LDA algorithm.  That also provides
an opportunity to think about how we store the data and what it means
to store the data in different ways.  What is gained?  What is lost?
I know that students only really understand the subtleties of an algorithm
when the implement it.  And they understand it even better when they play
with the implementation.  But we won't cover everything.  At least in this
case, I don't consider it important for students to delve deeply into the
mathematics and statistics that show that the LDA algorithm is "correct".

I have a lot to learn.  I also have more than thirty paired readings
and labs to write and both homework assignments and a large project
to design.  Hence, I look forward to the time that the Digital Bridges
fellowship will provide me.  And, as I said, this is future work.
Things are likely to change.  For example, yesterday's conversations have
gotten me to consider ways in which I might use APIs for Google maps or
Twiter in the course.  I look forward to conversations with some of you
on how to navigate the relationships between the approaches and what I
might or might not include.

---

Damn!  Grammarly thinks that will take me nine minutes to read.  I have
seven.  I could try to be fast.  I could time myself.  Or I could cut
some things.

I timed myself.  It's closer to seven minutes.  I should be fine.
Reading it aloud also encouraged me to make a few changes.

---

Postscript: Although I discussed my thought processes in my musings about
[writing the blurb for this course](csc151-dighum-blurb) and [the slides
for the talk](dighum-presentation-2018-08-07), I had neither the time nor
the energy to discuss the many edits I made while writing this talk.

---

[1] What issues?  In part, it will be the custom I see people using
[2].  In part, it will be my own state of mind.  I know that having
things written down helps me remember to cover everything I intend
to cover.  In part, it will be the technology available.  And,
unfortunately, ITS managed to shut down MathLAN and our Web server when
I was working on writing this talk.  It made the job much less pleasant.

[2] I will admit that I had assumed that more of the presenters would
be reading their own speeches.  But I saw very few do so on the first day.
Of course, one of the more articulate presenters did read from prepared
notes, or at least seemed to.  Surprisingly, none of the ones I saw used
the "animated slides that I've made key to my presentation [3].

[3] The legendary [Erik Simpson](erik-simpson) isn't using slides at all.

[4] I've been taught that it's important to normalize the introduction
of pronouns.  People should not feel required to give their pronouns,
but it's important to feel comfortable doing so.

[5] No, I will not be reading these endnotes.

[6] Terrifyingly enough, one of the panelists suggested the same thing
at the College level.  I felt I had to reply.

[7] I should have found a bridge!

[8] And soon to be next door!

[9] If I could still edit the slides, I might temporarily hide the 
arrows and image connecting us to the humanities.

---

*Version 1.0 of 2018-08-09.*
