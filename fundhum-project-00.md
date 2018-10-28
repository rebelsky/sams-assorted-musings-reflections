Designing a project for my digital humanities class (draft 0)
=============================================================

*Topics/tags: [CSC 151](index-151), Racket, teaching, digital humanities, long, rambly*

For about as long as we've been teaching a "themed" version of CSC 151,
we've included an end-of-semester project.  The project serves a variety
of purposes.  It gives students a sense of ownership of their work; people
feel differently about projects they design than projects we design.
It expands students' understanding of possibilities; seeing what other
students undertake reveals very different approaches to computing.
It reminds them that they need more than technical skills to succeed;
because the project requires a written report, a short presentation,
and an even shorter question and answer session, students must draw upon
and build on those skills.

Looking back on the old MediaScheme version of CSC 151, it's clear
that the project evolved over the multiple semesters we offered it.
Our instructions got more specific.  We added examples [1].  We wrote
a rubric [2].  We revised the rubric.  We tried different timings and
approaches to classroom time.  We ended up with a pretty good structure,
if I do say so myself.

Two things about the MediaScheme project will be hard to translate to
other projects.  First, we could choose a very consistent structure:
Students had to write a procedure, `series`, that took three arguments:
a width, a height, and a number between 0 and 999.  Second, we told
them that a member of the studio art faculty would assess their work.
The structure meant that we knew students would be challenged to make
write algorithms that stretched and scaled the image appropriately,
thereby exercising their "algorithmic muscles", as it were.  The external
audience meant that students needed to concern themselves with more
than algorithms; they had to think about what would make an image
(or series of images) compelling.  Translating those characteristics to
a new project will prove challenging.

There are ways that I could restrict the project.  I could
limit the data set that students are using; for example,
I might require that they use our digitized version of the
_Scarlet and Black_ or to [the Statistical Accounts of
Scotland](http://stataccscot.edina.ac.uk/static/statacc/dist/index.html)
[3].  I could limit the kind of project they do, such as requiring
everyone to do a language generation project or a mapping project.

On the other hand, there are some exciting things about moving to a more
open project model.  It certainly gives students more opportunities to
explore their passions.  It provides a broader range of possibilities [4].
And I'll probably have to worry a bit less about repetition from year
to year [5].

One of the downsides of having a more open-ended project is that it's
much harder to predict workload.  Students may also spend more time
on "background" work, such as identifying an appropriate data set.
There's also a challenge of being able to grade the projects uniformly.
However, a good rubric can help with that.

The other strength of the MediaScheme project was that they knew they
would have an artist look at their work.  I could give them an audience,
of sorts, telling them that we will invite one of the digital humanists on
campus to critique their work.  That's an issue to consider for the future.

For this draft, I'm going to use the "open-ended project" model.  I may
add a short mention of the audience.  Let's see what I can come up with.
I have as resources [the latest version of the MediaScheme project
description](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2017S/assignments/project.html)
and [the latest version of the new, and
not nearly as polished, Data Science project
description](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/assignments/project.html).

---

**Preliminaries**

*Summary*: You will design and propose a novel project in the digital 
humanities; develop, implement, and apply appropriate algorithms; and
present your findings in both written and oral form.  

*Purposes*: The project provides you with the opportunity to explore some
aspect of the digital humanities in more depth and to do work that is
novel and creative.  We also intend that it will encourage you to reflect
more purposefully on the design of algorithms.

*Collaboration*: I encourage you to work in groups of size three.
(In class, we will discuss different roles for those three collaborators.)
You may also choose to work alone or in a group of two or four people.
You may discuss this assignment and your work on the assignment with
anyone, provided you credit such discussions when you submit the
assignment.

**Scope**: You project should be of a scope that your group can
complete it over a two-week period with approximately five hours of
work per week per group member.

**Introduction**

At this point in the course, you have explored a variety of kinds of
"humanistic data" and algorithmic techniques for dealing with them.
We have, of necessity, examined only a limited range of algorithms and,
even then, looked at only the basic issues associated with each.
One of the more compelling aspects of the digital humanities, at least
from my perspective, is that there is such a broad range of opportunities
to do or discover something new.  You can extend algorithms in different
ways.  You can tune algorithms to different kinds or collections of works.
You can build tools that others may use.

**Components**

*Part one: Project proposal*

You will begin by forming a group, deciding upon an approach to the
project, and identifying the materials that you will use as the core
of your project.  Please feel free to be creative in your choice of
materials; while we have primarily been using works from Project Gutenberg
and data from the US Government [6] in our weekly projects, you can use
any collection that you can identify or create.

Based on those preliminary discussions, you will write a *project
proposal* in which you provide a broad overview of the goals of the
project, specify the materials you will work with, and describe the
algorithm or algorithms you intend to implement.

That is, your project proposal should include at least three sections.
A *project statement*, intended for a general audience, should explain
the broad goals of the project.  Why are you undertaking this study?
What do you hope to learn?  A *materials statement* should provide
a more in-depth explanation of the materials you plan to use and where you
obtained them.  Finally, an *analysis plan*, intended for a technical
audience, should describe the algorithms you expect to implement.

A typical project proposal will be approximately two double-spaced
pages.  You should write your proposal in narrative form, using
correct grammar and spelling.

We will do our best to respond to your proposal promptly.  However,
given the time constraints of this project, you should move forward 
to subsequent steps before you receive feedback.

*Part two: Project*

You will have about one week to implement your project.  That is, you
will implement the algorithms you have designed, use those and other
algorithms to explore your materials, and, one hopes, come up with
some observations that can be used in a more comprehensive study.

You will submit your program code, the materials you analyzed, and
instructions for using your program with those materials.

*Part three: Report*

A final project report should accompany your project code.  This report
will probably draw heavily on the project proposal.  You may find that you
need to modify your analysis plan to describe the algorithm you developed
(plans and results often differ significantly), including details of
the Racket implementation.  In addition to the first three sections,
you should also describe your initial "results".

As you know, algorithmic analysis is only one step in many digital
humanities projects.  Hence, your report should also suggest subsequent
work that might be done as part of a complete project.  Have you discovered
issues that would benefit from close reading?  Do we need to look at
other materials to learn more?  Is it worth turning to the literature
and placing this work in a broader context?

*Part four: Lightning presentation*

You will give a two-minute presentation to your classmates and a select
group of visitors during the designated "presentation days".  We will also
reserve approximately two minutes for questions and answers.

**Selected approaches**

Some of you will immediately identify a project of interest.  However,
others may need a few suggestions to get started.  Here a few possible
approaches you might find interesting.  You will, of course, need to
choose the materials with which you work.

*Sentiment analysis*.  You might write an algorithm that takes a
piece of text and identify the sentiment expressed in the piece.
Is it positive, neutral, or negative?  While much work in sentiment
analysis is done using machine learning techniques (which we don't
expect you to undertake), you could experiment with algorithms that
look at word choice and word proximity for certain words.

*Topic modeling*.  You wrote a simple topic modeling algorithm for
a homework assignment.  You might extend that algorithm and apply
it to a new data set.

*Language generation*.  We've explored two models of language generation,
one using generative grammars and one using statistical methods.  You
might look at ways to combine or extend those models, applying them to
a particular genre or author.  If you do choose a language generation
project, make sure to reflect upon what we can learn about the source
texts you've chosen; language generation that's just for the fun of
seeing what you get does not suffice as a project.  It may be, for
example, that you manually explore the structure of an appropriate
sampling of sentences in the works and use those in your grammar.

*Tool building*.  You might build a tool that other FunDHum students
could use in future projects.  If you choose to develop a new tool, you
will still want to identify some materials that you can use to assess
the efficacy of your tool.

*Mapping*.  In our exploration of mapping, we read Barry Lopez's "The
Mappist".  Although you do not have the time to gather data of the kind
that Benefideo used in his maps, you could, nonetheless, find ways of
mapping things that reveal important and unexpected connections.  If you
choose this kind of project, one of your challenges will be to develop
appropriately sophisticated algorithms; you already know how to map data,
mapping alone does not suffice.  You might, for example, develop algorithms
that extract information from more complex data sources in preparation
for mapping them.

If none of the above sounds interesting, you might spend some
time exploring the Web for other possibilities.  For example,
[HyperCities](http://www.hypercities.com/) provides a wide variety of
projects that you might find of interest.

We will spend some time in class discussing possible approaches to
the project.

---

I also plan to put together a new rubric [7] and to write some extended
examples of each kind of project.  Those will likely have to wait until
I write the rest of the course.

Now that I've finished this draft, I find that I also want to consider
another kind of project. I'll explain more tomorrow.

---

[1] And, on occasion, removed examples.

[2] More accurately, Janet or Jerod wrote a rubric.

[3] One of my Obermann colleagues has a variety of projects that explore
language use in the Statistical Accounts.

[4] Of course, even though the range of possibilities seems limited for
the MediaScheme project, the results vary widely.

[5] I'm glad to be done with way too many fractals.

[6] I need to spend more time thinking about the non-textual data that
we will use in this course.

[7] I see that [the rubric that Titus
Klinge wrote for the data science version of
151](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/assignments/project-rubric.txt)
will be a pretty good starting point.  

---

*Version 1.0 of 2018-10-27.*
