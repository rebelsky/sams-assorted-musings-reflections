An alternate project design for my digital humanities class
===========================================================

*Topics/tags: [CSC 151](index-151), Racket, teaching, digital humanities*

As I noted in [a prior musing](fundhum-project-00), we end [1] each
semester of CSC 151 with a two-week final project.  In that musing, I
described a very open-ended project.  Writing about the open-ended project
has gotten me to think a bit more about alternatives.  In particular,
I wonder whether it might be better to have all of the students in
the class work on the same collection of materials to provide an
"environmental scan" of the materials [2].

What's the advantage of restricting the project in this way?  In some
ways, it means that each student project contributes to a larger whole.
There can be a broader sense of accomplishment when you see that, as a
class, you have provided a rich collection of materials for others to use.
It may be that I can even frame it in such a way that there's an obvious
audience for the work.  For example,

> A few years ago, Professor Timothy Arner [3]
and his students developed [4] [_The Grinnell
Beowulf_](https://digital.grinnell.edu/islandora/object/grinnell:5317),
a translation of the poem along with appropriate scholarly apparatus
to support use of the translation in the classroom.  While that work
provided Arner with a deep understanding of the material, recently,
Arner has been wondering whether the tools of the digital humanities
might permit him to discover new aspects of the text and has asked our
class to conduct some analyses that might provide some preliminary new
directions for his scholarship.  Over the next two weeks, you will form
small teams, develop new algorithms, and use those algorithms to provide
some potential insights into the text.

There are certainly a wide range of opportunities for materials the
students can work with, whether hypothetical (someone is probably
interested in our _Scarlet and Black_ archives), potential (as in the
Arner example), or real (I'll need to chat with the CTLA and Vivero
folks about such issues).

Another advantage of such an approach is that the students won't have
to spend time gathering and, perhaps, reorganizing the materials.  That
means that they will have more time to spend designing their algorithms
and discovering potential areas of interest in those materials.

Are there downsides to the "one set of materials" approach?  Certainly.
The materials are likely to be less interesting to the students
than materials they choose themselves.  Not everyone will care about
[_Beowulf_](https://digital.grinnell.edu/islandora/object/grinnell:5317)
or the [Statistical Accounts of
Scotland](http://stataccscot.edina.ac.uk/static/statacc/dist/home) or
[_Cats_ fanfic](https://www.fanfiction.net/play/Cats/) or [the _Scarlet
and Black_ archives](http://usiagrc.arcasearch.com/Research.aspx)
or whatever.

Like many things, it's a balance.  And "Which approach?" could be a good
discussion topic for the Obermann group.  So let's see what I can come
up with.

---

**Preliminaries**

*Summary*: You will contribute to the analysis of [materials] by
developing a new algorithm, applying it to those materials, presenting
your findings in both written and oral form, and identifying potential
areas of investigation based on those findings.

*Purposes*: The project will provide [audience] with a richer set
of resources and research questions for their study of [materials].
It will also give you the opportunity to explore an aspect of the
digital humanities in more depth and to do novel and creative work.
We also intend that it will encourage you to reflect more carefully
on the design of algorithms.

*Collaboration*: We encourage you to work in groups of size three.
(In class, we will discuss different roles for those three collaborators.)
You may also choose to work alone or in a group of two or four people.
You may discuss this assignment and your work on the assignment with
anyone, provided you credit such discussions when you submit the
assignment.

**Scope**: You project should be of a scope that your group can
complete it over a two-week period with approximately five hours of
work per week per group member.

**Introduction**

As you may know, [audience] studies [topic].  Recently, they have
identified [materials], which they expect will be useful to their study.
They have heard that digital humanities techniques can provide new
insights into materials and have asked our class to develop algorithms
that might suppport or provide some new directions for their scholarship.

Throughout this semester, we have seen a range of "humanistic data"
and algorithmic techniques for approaching them.  But there are many
opportunities to do more: We can develop more sophisticated versions
of algorithms we've already seen or we can develop new algorithms or
approaches.  You will do so with [materials].

**Stages**

*Stage zero: Preparation*

You will begin by exploring [materials] and considering ways in which
you might approach those materials.  You can find some starting points
below.

You will then form a group and decide upon an approach to the project.

*Stage one: Project proposal*

Based on those preliminary discussions, you will write a *project
proposal* in which you provide a broad overview of the goals of the
project and describe the algorithm or algorithms you intend to implement.

That is, your project proposal should include at least two sections.
A *project statement*, intended for [audience], should explain
the goals of your project.  Why are you undertaking this study?
What do you hope to learn?  How might it contribute to their broader
understanding of [topic]?  An *analysis plan*, intended for a technical
audience (e.g., your classmates) should describe the algorithms you
intend to implement and what prior work you will draw upon in implementing
those algorithms.

A typical project proposal will be approximately one-and-a-half
double-spaced pages.  You should write your proposal in narrative form,
using correct grammar and spelling.

We will do our best to respond to your proposal promptly.  However,
given the time constraints of this project, you should move forward 
to subsequent steps before you receive feedback.

*Stage two: Project*

You will have about one week to implement your project.  That is, you
will implement the algorithms you have designed, use those and other
algorithms to explore [materials], and, one hopes, come up with
some observations that [audience] can use in identifying deeper
scholarly questions.

You will submit your program code and instructions for using that code.

*Stage three: Report*

A final project report should accompany your project code.  In it, you
will once again, provide a non-techincal overview of the project along
with a more detailed description of the algorithms.  In addition, you
will discuss your results.  In particular, you should suggest ways in
which what you have discovered in using the algorithm might provide a
starting point for future study and suggest possible directions.  Have
you identified an opportunity for close reading?  Do your results suggest
that it would be valuable to look at additional materials?  Are there ways
in which it would be valuable to turn to the literature to gather a broader
context?  Do we perhaps need to extend algorithms further or try other
approaches?

While the third section of your final project will necessarily be new,
you may use your project proposal as a starting point for the first
two sections.  Our experience suggests that both sections will need some
revision.  You will often find that once you've started to use preliminary
algorithms on particular inputs, you will change your goals somewhat and
even the ways you think about the design of your algorihtm.  In addition,
when you implement an algorithm, you often discover additiona issues and
subtleties that may lead you to update your description of the algorithm.

*Stage four: Lightning presentation*

You will give a two-minute presentation to your classmates, [audience],
and a select group of visitors during the designated "presentation days".
In your presentation, you should describe your goals, your algorithm,
and your findings.  We will also reserve approximately two minutes for
questions and answers.

**Selected approaches**

Some of you will immediately identify an approach you would like to take.
However, others may need a few suggestions to get started.  Here a few
possible starting points.

*Topic modeling*.  You wrote a simple topic modeling algorithm for
a homework assignment.  You might extend that algorithm, tune it for
[materials], and apply it. 

*Statistical analysis*.  You might develop tools that allow you
to understand some broad features of individual elements, such as
sentence length or word choice, and then apply them to unearth potential
relationships between different elements of [materials].  Are there
structures or words that occur more frequently in some parts or others
and what does that say about the relationships between those parts?

*Mapping*.  You might develop algorithms that select place names from
[materials] and visualize the use of those place names within the corpus.
There are many ways you could treat those place names.  You could,
for example, show the sequence of the use of names, potentially finding
meaning in how name use changes over the work.  You could identify the
parts of [materials] each place name appears in and use that to show
similarities and differences.  You could look at nearby words and show
those as a way of understanding the context in which the place names
are used.

*Emotion analysis*.  The approach of "sentiment analysis" takes a piece of
text and identifies the overall sentiment of the piece.  Is it primarily
positive, neutral, or negative?  But it may be more interesting to look at
other emotional characteristics?  Does a work express anger, or sadness,
or confusion?  Often, these kinds of analysis are done using machine
learning techniques, which we do not expect you to undertake.  However,
you might choose other characteristics of interest (e.g., particular
words or phrases) that you think will help explore such questions.

*Visualization*.  You might explore new ways to visualize [materials],
exploring connections based on subject, length, word choice, metadata,
and such.

If the short examples above do not suffice, you might spend some
time exploring the Web for other possibilities.  For example,
[HyperCities](http://www.hypercities.com/) provides a wide variety of
projects that you might find of interest.

We will spend some time in class discussing possible approaches to
the project and will form groups, in part, based on the approach that
you wish to take.

---

I will need to spend more time on the selected approaches.  It might
even be useful to provide some sample outputs (maps, texts, whatever)
that illustrate each technique.

---

[1] Well, nearly end.  There's usually one more take-home exam.

[2] I take the term "environmental scan" from my colleague, [Erik
Simpson](erik-simpson).  I am not sure that I am using it in the
same way that Simpson does.

[3] These days, he's Associate Dean Timothy Arner.

[4] "Wrote".  "Produced".  "Created".  What's the right word?

---

*Version 0.1 of 2018-10-28.*
