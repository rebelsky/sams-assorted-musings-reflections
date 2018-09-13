A draft schedule for the new "digital humanities" CSC 151
=========================================================

*Topics/tags: [CSC151](index-151), Racket, digital humanities, rambly, excessively long, insufficiently edited*

When I start to develop a new class, I find it useful to put a few
things in place.  I develop a "big picture" for the course, the
general sense of what I expect students to get out of the course [1].
I reflect on the core topics that belong in the course.  I sometimes
write an introduction, as I've just done for the forthcoming ["digital
humanities" version of CSC 151](fundhum-intro-00).  And, some point
near the beginning, I choose the order of topics.  That is, I put together
a schedule.

In developing a schedule, I rely on a variety of resources.  If a
colleague at Grinnell has taught the course, I will often look at
their schedule.  I might also see what colleagues elsewhere have done
for the course.  If I've planned to use a textbook, I review its order
of topics [2].  Nonetheless, in many cases, I decided that I'd
rather use ad-hoc resources or resources that I write myself, rather than
using a textbook.  In some cases, that's necessary because of the topic or
approach that I've chosen.  For example, I'm pretty sure that there aren't
textbooks that take a workshop-style approach to introductory CS through
the lens of media computation, data science, or the digital humanities.
And even if such books exist, they aren't in Scheme [5].  In others, I
can't find a book that approaches the material in a way that satisfies me.
I'm picky, and I get frustrated by issues as small as poor formatting.

Where was I?  Oh, that's right.  I was writing about developing a schedule
and ended up writing about writing materials for my courses.  When I'm
writing texts for my courses, the schedule helps me think about what
to write.  Generally, I try to write materials in order.  The schedule
helps me decide that order.

Since I'm developing a new version of CSC 151 and I'm writing a more-substantial-than-normal-for-SamR textbook [6], I should put together a
draft schedule for the course.  And it's definitely a *draft* schedule;
I expect that as I write individual sections, I'll find that I will
want to reorganize topics.  I also know that teaching the course will
lead to some insights that also encourage me to rearrange topics.

*Constraints*

Where do I start?  I should first figure out the general constraints on
the schedule.  While I could design the course in the abstract, I know
that [the semester matters](updating-course-schedule).  I'd rather design
for a specific semester first and then generalize later.  In this case,
I'm teaching an MWF class in spring 2019.  In spring 2019, the semester
begins on January 21.  January 21 is Martin Luther King Day, which means
that we cancel classes so that students can attend events associated with
diversity and inclusion [7].  That means that we'll only have forty-one
days of class, rather than the more traditional forty-two [8].  And we'll
just have two days of class the first week.  That eliminates a Friday
quiz that week.

Spring break starts on March 16.  That means that we have eight weeks of
classes before spring break [9] and six weeks of classes after spring
break.   I've never quite understood why we don't do seven weeks before
spring break and seven weeks after, but I assume it's partially so that
the College's spring break aligns with the local school system's spring
break.

The timing of spring break doesn't matter for the order of the
topics, except that I generally want to avoid a two-day topic that
starts the last day before spring break and ends the first day afterward;
students are unlikely to retain enough information over break.

However, the timing of spring break *does* matter for homework
assignments.  And, while they are probably less critical than the topics,
it seems worthwhile to start with the timing of assignments.  Come to
think of it, some assignments, notably the class project, affect the
topics we cover.  And I've found it useful to use class time to debrief
on some of the exams.  So it is worthwhile to start with the large pieces
of work.

*Planning assignments*

I plan to continue the long-standing model of "homework assignments
and take-home exams are due Tuesday evenings".  Given the schedule,
that means I'll have something due weeks 2, 3, 4, 5, 6, 7, 8, 10, 11,
12, 13, and 14.  The week-two assignment may be a bit complicated to
write given that the class doesn't start until Wednesday, but I'll figure
something out.

I've traditionally assigned an exam in week three that is due in week
four.  And for the past few years, we've given four take-home exams.
Given [changes to the add-drop timing]((policy-reflections-2018-08-04)), I
find it less necessary to give a take-home exam so early in the semester.
And it will likely make it easier for both the students and me if
the course requires three take-home exams rather than four [10].
So let's have the take-home exams due in week 5, week 8, and week 14.
I'd prefer to have one due in week 9, rather than week 8, but that's
immediately after spring break, and it's unfair to have work due then
[11].  I don't want to push the exam to week ten because the project
will take weeks twelve and thirteen, and I'd prefer that they have two
assignments between exams.  Let's see where that puts us.

<table border class="schedule">
  <tr> <th width="10%">Week</th> <th>Work</th> </tr>
  <tr> <th>2</th> <td>HW1: A Scheme-free assignment</td> </tr>
  <tr> <th>3</th> <td>HW2: First Scheme Assignment</td> </tr>
  <tr> <th>4</th> <td>HW3: TBD</td> </tr>
  <tr> <th>5</th> <td>Exam 1</td> </tr>
  <tr> <th>6</th> <td>HW4: TBD</td></tr>
  <tr> <th>7</th> <td>HW5: TBD</td></tr>
  <tr> <th>8</th> <td>Exam 2</td></tr>
  <tr> <th>10</th> <td>HW6: TBD</td>
  <tr> <th>11</th> <td>HW7: TBD</td></tr>
  <tr> <th>12</th> <td>Project Proposal</td></tr>
  <tr> <th>13</th> <td>Project</td></tr>
  <tr> <th>14</th> <td>Exam 3</td></tr>
</table>

I'll figure out the details of the particular assignments later.  I know
that HW6 or HW7 will be about topic modeling and the other will probably
have to do with tree traversal.  What about the Scheme-free assignment?
I'm tempted to have that one be about document markup, which means that
the first Friday of class may need to be about markup languages [12]
rather than Scheme.  That should be okay.  In any case, it behooves me to
move on to the schedule before filling in more details of the assignments.

*Some starting points*

With the big picture of assignments out of the way, I'm now ready to
explore particular topics we'll cover and the way in which I'll order
them.  As a starting point, let's look at [the CSC 151 schedule for last
spring](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/home/schedule), the first spring offering of the data-science CSC 151.

!!quickschedule MWF < csc151-schedules/datacsci-2018S

I also thought about looking at [the CSC 151 schedule from the previous
spring](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2017S/schedule/),
which represents the last spring offering of the media-computation
CSC 151.  That was a four-day-per-week course, which means that it
won't necessarily be as helpful as I design another three-day-per-week
course.  Still, it will be helpful for me to reflect on the topics that
we have traditionally covered [14].

!!quickschedule MTWF < csc151-schedules/mediascheme-2017S

That schedule is a bit of a surprise.  I know that I had not planned
a week to discuss exam 3.  I can't quite remember why I felt it
necessary, but I *think* it was to help students delve more deeply
into problem-solving processes.  It's also clear that I did a lot of
combining of pairs of related topics as I moved from fifty-six class
sessions to forty-two class sessions [15].  And, as one might expect,
I was able to drop some of the topics that tied to images, such as RGB
colors, drawings as values, and geometric art.

*Adding and dropping topics*

What will look different in the new course?  As I mentioned, I'll have only
forty-one class sessions rather than forty-two.  While many general
topics will persist, the particulars of most of those topics will change
to draw upon whatever I settle on as the particular aspects of digital
humanities to emphasize.

There are also things that I need to add.  As I noted earlier, I've decided
to start with document markup.  I'll need to add that in the first week of
class.  XML documents are trees, and I would, therefore, like to do more
with trees in the class.  I will certainly change the focus of the
"Trees" topic will from BSTs [16] to XML trees.  But I also want to add some tree processing earlier
in the semester, using simplified Scheme equivalents of XPath and XSLT.
I should add a day on regular expressions.  That may be early in the
semester.  More broadly, it may be useful to devote a day to discussing
each of the first two exams and not just the first exam.  Such days are
often particularly helpful in giving students additional perspective on
approaches to problem solving.

A few of my colleagues have suggested that my perspective on the digital
humanities relies too heavily on text.  In part, that's because my
experience is mostly with text-based DH and my experience affects
my perspective.  But it's also an issue of accessibility: Text
is more broadly accessible than graphics.  And, I must admit,
it's easier to come up with appropriately complex examples with
text than graphics.  In any case, it's an issue that I should
think about more deeply.  For the time being, I'll keep one day on
graphics and visualization using the core Racket graphics tools.
Maybe we'll even start with some graphics; after all, the [snowman
example](https://dustycloud.org/misc/digital-humanities/Snowman.html)
is a nice way to start learning Racket with images.  And it does appear
that the `pict` package uses a relatively pure approach to graphics [17].

I should also think about a day on using maps.  Unfortunately, it's
harder to use something like Google Maps in Racket than it is in, say
JavaScript.  I see that [there's a Racket to JavaScript compiler called
Whalesong](https://www.hashcollision.org/whalesong/), but it's no longer
in [the current list of Racket packages](http://pkgs.racket-lang.org/).
But perhaps I can write something using the [Google Static Maps API](https://developers.google.com/maps/documentation/maps-static/intro).  It seems relatively
straightforward.  But [Google charges](https://developers.google.com/maps/documentation/maps-static/usage-and-billing) [18].  I wonder if there are free
resources for education.  Following some links led me to some [Google
Earth resources](https://www.google.com/earth/outreach/learn/), including
one entitled [Visualize your data on a custom map using Google My
Maps](https://www.google.com/earth/outreach/learn/visualize-your-data-on-a-custom-map-using-google-my-maps/).  But that seems manual, rather than scripted.
In any case, it's something I should come back to later.

Beyond the digital humanities, I've started to think about different
aspects of Racket I might or might not include.  Rackets structs seem
like useful ways to group data.  I've also debated switching how we do
local variables [19].

Where does that leave me?  If I remember everything I just wrote,
I want to add the following topics: HTML/CSS, processing XML, regular
expressions, visualizing data, maps [20], structs, and a discussion of
the second exam.  I've lost one day.  So I need to find eight things
to remove or combine.  "Displaying data" (Monday, Week 5) is becoming
"visualizing data".  I can drop "tables" (Monday, Week 4) The early
discussion of files (Wednesday, Week 4) is mostly in the context of CSV;
I can probably merge it into the first string day [21].  I see that we
had gone from one 50-minute project work day to three 80-minute work days
[22].  I suppose I should go back down to one [23].  That's five days.
I still need to find three more things to cut or merge.

At first glance, the discussion of [local procedure
bindings](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/readings/letrec)
(Wednesday, Week 8) seems to be a bit much.  After all, `letrec` only
takes a few minutes to introduce.  But we also talk about named let.
We also re-emphasize the husk-and-kernel strategy that we introduced a
bit earlier (Wednesday, Week 6).

Given that we revisit husk-and-kernel with local procedure bindings, do
we need a whole day on precondition testing?  Could we, perhaps, combine
it with documentation (Monday, Week 3)?  I traditionally run the documentation
"lab" by having the class collaborate to write documentation.  But we
could use some of the time to write husks and kernels.  It's risky,
but it's worth trying.

I suppose that I could combine the wrapup and the course evaluation.
I like the wrapup as an "overflow" time for presentations.  And it's
somewhat pointless to introduce new topics in the last week of the
semester.  So it appears that the answer is "No, I should not merge
them."

What's left to cut?  There are two days in which we "revisit" topics,
one on higher-order procedures (Monday, Week 10) and one on files
(Wednesday, Week 10).  In the former case, students learn how to *write*
the higher-order procedures that they've been using [24].  We'll need to
keep that class.  What about files?  The students will learn how to read
files early in the semester.  The late-semester files topic is mostly
about ports and output.  It's strange to teach an introductory class
in which they don't write files or write interactive programs [25].
But we don't use files much in the class.  And students get puzzled
by much of what we do with files (not only the relationship between
a port and a file, but also the patterns for recursion over files).
So I'm going to temporarily make a somewhat controversial decision and
drop that subject.  I'll need to revisit that decision with my colleagues.

At this point, I feel like I've cut as much as I can.  So perhaps I will
not add as much as I had planned.  One option is to move some of the
learning to homework assignments.  It's probably not the best decision,
but, for now, I'm going to merge visualization and maps into a single day
[26] and assume that I'll come up with appropriate assignments.

*A revised schedule*

Of course, the syllabus is more than the list of topics.  I need to come
up with the right ordering.  For example, in the media computation
course, we went from making the "drawings as values" the initial focus
to making RGB colors the initial focus.  When we moved to the data
science model, lists became the initial focus.  That approach also let
us introduce `map`, `filter`, and `reduce` relatively quickly.  While I
won't only use text, it appears that strings and text will be the initial
focus of the digital humanities course (along with the quick graphics
introduction on the first day).

What are some issues at play?  I'd like them to see conditionals before
they take the first exam.  I'd like to see them start to study recursion
before they take the second exam so that I can include one or two
questions on recursion [27].  I ended up moving randomness immediately
after the introduction to recursion because I plan to include [random text
generation](code-camps-lac-language-generation) as part of the randomness,
and some examples help illustrate recursion.  Here's what I have so far
[28].

!!quickschedule MWF < csc151-schedules/fundhum-00

But the high-level schedule does not cover all of the details.  For
example, what aspects of lists do I cover when?  Procedures like
`compose` and `section` don't appear anywhere.  Do I introduce them
when I introduce procedures or do I wait until, say, I start on lists?

If I use graphics in the new introduction to Scheme, I lose the
coverage of numbers we traditionally begin with.  While the basics of
numbers are straightforward, there are some subtleties that we also
cover.  Where, for example, will we consider exact and inexact numbers?
One possibility is to add them to the day in which we explore Boolean
values and predicate procedures (Wednesday, Week 5).

I also note that, at first glance, this does not look like a list
of digital humanities topics.  That makes some sense, at least to me.
After all, it's still a computer science course.  The digital humanities
content gets incorporated in the context of each individual subject [29].
And the choice of digital humanities as the focus influenced both the
subjects we will cover and the ordering of those subjects.

It's not a perfect schedule, but it's enough to get me started on writing
the daily readings and labs.  It's also a good starting point to begin
conversations with others about content and approach.  I've already
mentioned that some colleagues are concerned about the seeming
text-centric nature of the course.  I'll need to talk more with them
about what else they'd like to see.  For example, is it just more options
for visualization, or are we also going to need to consider more kinds
of data?

Terrifyingly enough, it seems that I'll also need to produce a more
detailed course schedule in which I explore the issues I've just
mentioned.  What will the details of each day include?  What will the
digital humanities topics be?  Those additional details will help me
write and will help my colleagues understand what we do and do not cover
in the course.

However, that's a task for another day [30].  I'll probably intersperse
that work with writing.  And, as I know, writing the readings and
labs will also help me reflect more carefully on the schedule [31].

It's time to get started! [32]

---

Postscript: As I begin to fill in the additional details, here's a
question to think about:  I traditionally have students write a "Nut
butter and fruit spread sandwich" algorithm on the first day of class.
It's an entertaining exercise.  Should I switch to something more DH
oriented?

---

Postscript: That first day mentioned in the previous Postscript is not
really part of the text that I'm writing.  Does that mean that I also
need to start thinking about an instructor's guide?  Agh!  That's scary.

---

Postscript: Right after finishing this musing, I received a message
from _Chronicle_ announcing a new advice guide on [How to Create a
Syllabus](https://www.chronicle.com/interactives/advice-syllabus), just
released today.  I'll add that to my list of things to reflect on.

---

Postscript: How long does it take to draft a schedule for a class?
As this musing may suggest, it can take a long time.  All in all, I spent
about one full day on it, spread out over multiple days.  That estimate
includes the time I spent writing about developing the schedule.
However, it does not include the hour or so I spent writing [a program
to make it much faster to put together one of the schedule tables](https://github.com/rebelsky/samr-utils/blob/master/quickschedule) I use in this
musing [33].

---

[1] At times, I express those as course goals or learning outcomes.
More frequently, I express them in the course description.

[2] If there are multiple potential textbooks, I might use the
ordering of topics as a way of choosing which is appropriate [3].

[3] I also consider cost, quality of instruction, accuracy, and a host
of other issues.

[4] And even when I'm teaching a course that others have taught.

[5] Or Racket.

[6] At least that's the plan.

[7] Some folks seem to think that MLK day means "I can show up at school
a day late."  It doesn't.  Someday I'll muse about the faculty's vote
about MLK day.

[8] I wondered whether the faculty would vote to start classes on Friday
on years in which MLK day fell on the first day of class so that we
could maintain forty-two days of class in those years.  I don't think
anyone even proposed that model.

[9] Well, eight weeks of classes minus one day of classes.

[10] I may come to regret that decision.

[11] I'd also like to be able to use break to get grading done.

[12] Well, HTML to start with.

[14] We offered the media computation version for about a decade.
The schedule shifted over that decade, but it generally kept the same
topics.  However, we did lose objects and meta-programming at some point.

[15] No, I don't plan to go back.  I prefer the new
[three-by-eighty](eighty-minutes-2017-09-11) format.

[16] Binary Search Trees.

[17] If I do begin with simple graphics, I'll need to think about ways
to make that accessible and about alternatives.

[18] Maybe it's not as bad as I think.  See
<https://cloud.google.com/maps-platform/pricing/>, which suggests that
one can get up to $200 in free credit.

[19] We've always used `let` (and `let*` and `letrec`).  The Racket
community uses internal `define`.  My current inclination is to stick
with `let`.

[20] That's "map" as in "Google Maps", not as in "apply a procedure
to each element of a list" nor "mentored advanced projects".

[21] Let's hope that I don't overload my students.

[22] I'm counting the presentation preparation.

[23] The project introduction is also a kind of work day.  And that
day is 30 minutes longer than it was in the old version of the course.

[24] Speaking of procedures ... I wonder if I should introduce `section`
and `compose` when we first cover procedures.  If not, where do I
introduce them?  Perhaps with lists.

[25] Almost all the interaction in the work they do stems from the
interactive nature of Scheme.

[26] I'll still write two separate readings.

[27] It would also be nice to have a homework assignment on recursion.
However, that does not seem possible.  I'll make sure to keep the
recursion on exam two very simple.

[28] In all honesty, I should admit that I've played with the schedule a
bit to get it to this point.
I chose
not to discuss ordering or, more precisely, not to present the sequence
of draft schedules, because the musing already seemed much too long.

[29] Or at least *most* individual subjects.  I'm not sure, for example,
how much digital humanities content will appear in the discussion of
debugging.

[30] Or, more precisely, for another few days.

[31] For example, I may be doing XML too early because it relies on
students understanding a particular representation of XML.

[32] More precisely, tomorrow is a time to get started.

[33] I'll explain more about that software in a future musing.

---

*Version 1.0 of 2018-09-12.*
