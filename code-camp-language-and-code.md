Designing a new code camp on language and code
==============================================

*Topics/tags: [Code camps](index-code-camps), digital humanities, Racket*

This spring, my code-camp co-director and I made a dangerous decision:
Instead of offering two code camps this summer, we would offer three [1].
There were some good reasons to make that decision.  Most importantly,
offering a third camp gives us the opportunity to serve more students;
all three camps filled.  Adding a new topic also allowed us to provide a
different opportunity for students who had taken a code camp last summer
[2].  Keeping the prior two topics meant that the research students
would have the chance to work with existing curricula in the first two
camps and to design their own curriculum for the third.

We selected "language and code" as the topic for the third camp.
There were a few reasons for the choice.  Part of our goal is to get
kids to think about computer science in different ways; writing programs
that generate and analyze language seems very different than the more
typical ways they use computing.  For that reason, I had indicated in the
original proposal that we would offer a "digital humanities" camp in the
third year of the project [3].  I'm also planning a "digital humanities"
version of CSC 151 in spring 2019 and the camp provides a good way to
start thinking about the design of that course.  Choosing activities that
build upon each other make me more efficient.

In two weeks and a day, we'll be offering the language and code camp.
That doesn't sound bad, does it?  But next week, we're offering the
"data science for social good" camp, which means that all of the research
students will be serving as counselors for ten-hour days.  So we'll only
have one week to prepare a one-week code camp [4].  That's a bit scary;
I generally give myself four hours for each hour of new curriculum
I prepare.  But we do have eight research students and one or two
directors to work on the new curriculum.  Plus, about a third of the
time in camp is non-technical time: snacks and meals, games, scavenger 
hunts to introduce kids to the College and to Noyce, and so on and so
forth.  

But there's still a lot of curriculum to plan.  So I'm going to do a
bit of the work that I would normally leave to the students, such as
designing the overall shape of the curriculum and perhaps even planning
some of the activities.  It looks like I may also need to build some
associated libraries [5].  I'm not sure how much I'll get done; after
all, I'm also in code camp for ten hours per day and I do have things
to do with my family in the evenings.  But I'm going to try.

So, let's start with the overall curriculum.

I've made two core decisions: We're going to use Racket as the primary
programming language and we're going to do a lot with HTML.  There are a
few reasons for the choice of Racket.  We wanted a different language for
the students who are repeating.  It also allows me to develop materials
that I might be able to use in the new CSC 151 [6].  And I've seen on
the racket-users mailing list that there are some projects out there to
use Racket for digital humanities.  Plus, in building confidence we can
tell the students that they are using the same language that our college
students are using.

What about HTML?  Learning the basics of HTML is a nice way for students 
to see the power of code in building things; there's something especially
empowering of "I can write this by hand, rather than use a tool."  I've
also seen from Erik Simpson's digital humanities course that there's a value
to students understanding underlying representations of data.

What resources do I have as I plan the curriculum?  Certainly, I can
use anything I've written for my classes in the past.  I've also run a
small HTML exercise for GSP [7].  Let's see ... day two of [my GSP "lab"
experience](https://www.cs.grinnell.edu/~rebelsky/Workshops/GSP2015/)
was about Web pages.  There was a post on the
racket-users group about [a few-hour digital humanities
workshop](https://dustycloud.org/misc/digital-humanities/).
I might be able to find some ideas from Erik Simpson's [Lighting the
Page](http://www.math.grinnell.edu/~simpsone/Connections/Digital/index.html).
Erik does some nice things with hypertexts, expandable texts,
and Twitter bots.  I have the [syllabi for our data science
camp](https://codecamp.sites.grinnell.edu/dataforsocialgood/day-1/),
which should help me think about how to break down individual days.
My awesome students have also prepared a large list of ideas for
mini-projects for the code-camp students to do along the way [8].
That's a lot to work with.

What will the curriculum look like?  Here's a sketch.  I'll fill in 
additional details in a future musing [9].

Day one is when we introduce the camp and its goals.  We spend some time
with "get to know you" activities, teach them about algorithms, and
introduce them to the primary languages they will be using.

On day two, the students will learn how to use the languages together,
writing Racket programs to generate Web pages and text.  We'll also
introduce them to a few programming ideas, such as conditionals and types.

On day three, the students will use Racket to analyze different kinds
of documents, primarily text documents and Web pages.  Along the way,
we'll give them more tools for working with lists and strings.  On day
three, students will also start to think about their projects.

On day four, students will learn how to transform documents.  I think we'll
try to introduce regular expressions.  Students will also start to work
on their projects.

Finally, on day five, students complete and present their projects.  A full day
of coding isn't that much fun, so we will insert extra activities throughout
the day, including an awards ceremony or two.

And there you have it.  I *think* that's a sensible overview.  We're
covering less than I'd like and I'm not quite sure that I've given enough
time for "mini projects".  But I'm also already worried about the amount
we are covering.  We'll see what happens as I fill in additional details
and then my students and colleague critique it.

---

[1] One could argue that I'd made the decision three years ago, with a
prior co-director, since we'd said something like "one camp in the first
summer, two camps in the second summer, and three camps in the third summer".
However, we have been revisiting the original decisions, such as the plan
to offer residential camps.

[2] Things didn't quite go as planned.  We have about a third in the
"data science for social good" camp who are repeating the camp.

[3] Why was it in the original proposal?  Because Grinnell was in the
midst of a big "digital bridges" initiative and grant proposals tend to 
be more successful if they tie to campus priorities.

[4] We had assumed that we could be using some of last week to prepare.
However, this summer's students decided to significantly change the
"data science for social good" curriculum and that took more than we
had planned.

[5] I've already mused a bit about [part of one of the libraries](joc-one-of-macro).  There will be others.

[6] I did mention that I like to find ways to share work between projects.

[7] GSP: Grinnell Science Project.  GSP provides a host of activities to
support students who are traditionally underrepresented in the sciences,
including first-generation students, domestic students of color, and women
in some disciplines.

[8] It doesn't seem appropriate to link to their raw notes.

[9] Yes, I know that I plan followup musings all the time and don't always
get to them.  I expect to get to this one.  And, in any case, the full
curriculum for the camp will be available in three weeks.

---

*Version 1.0 of 2018-07-08.
