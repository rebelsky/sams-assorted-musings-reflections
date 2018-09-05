A draft schedule for the new "digital humanities" CSC 151
=========================================================

*Topics/tags: [CSC151](index-151), Racket, digital humanities, rambly*

When I start to develop a new class, I find it useful to put a few
things in place.  I develop a "big picture" for the course, the general
sense of what I expect students to get out of the course [1].  I reflect
on the core topics that belong in the course.  I sometimes write
an introduction, as I've just done for the forthcoming ["digital
humanities" version of CSC 151](fundhum-intro-00).  And, some point
near the beginning, I figure out the order of topics.  That is, I
put together a schedule.

I developing a schedule, I rely on a variety of resources.  If a colleague
at Grinnell has taught the course, I will often look at their schedule.
I might also see what colleagues elsewhere have done for the course.
If I've planned to use a textboook, I look at the order of topics in
the textbook [2].  But in many cases, I decided that I'd rather use
ad-hoc resources or resources that I write myself, rather than using
a textbook.  In some cases, that's necessary because of the topic or
approach that I've chosen.  For example, I'm pretty sure that there aren't
textbooks that take a workshop-style approach to introductory CS through
the lens of media computation, data science, or the digital humanities.
And even if such books exist, they aren't in Scheme [5].  In others, I
can't find a book that approaches the material in a way that satisfies
me.  I'm picky, and I get frustrated by issues as small as poor
formatting.

Where was I?  Oh, that's right.  I was writing about developing a schedule
and ended up writing about writing materials for my classes.  When I'm
writing texts for my classes, the schedule helps me think about what
to write.  Generally, I try to write materials in order.  The schedule
helps me decide that order.

Since I'm developing a new version of CSC 151 and I'm writing a more
substantial than normal textbook [6], I should really put together a
draft schedule for the course.  And it's definitely a draft schedule;
I expect that as I write individual sections, I'll find that I will
want to reorganize topics.  I also know that teaching the course will
lead to some insights that also encourage me to rearrange topics.

*Constraints*

Where do I start?  I should first figure out the general constraints on
the schedule.  While I could design the course in the abstract, I know
that [the semester matters](updating-course-schedule).  I'd rather design
for a specific semester first and then generalize later.  In this case,
I'm teaching a MWF class in spring 2019.  In spring 2019, the semester
begins on January 21.  January 21 is Martin Luther King Day, which means
that we cancel classes so that students can attend events associated with
diversity and inclusion [7].  That means that we'll only have forty-one
days of class, rather than the more traditional forty-two [8].  And I'll
only have two days of class the first week.  That eliminates a Friday
quiz that week.

Spring break starts on March 16.  That means that we have eight weeks of
classes before spring break [9] and six weeks of classes after spring
beeak.   I've never quite understood why we don't do seven weeks before
spring break and seven weeks after, but I assume it's partially so that
the College's spring break aligns with the local school system's spring
break.

The timing of spring break doesn't matter for the order of the
topics, except that I generally want to avoid a two-day topic that
starts the last day before break and ends the first day after break;
students are unlikely to retain enough information over break.

However, the timing of spring break *does* matter for assignments.  And,
while assignments are probably less important than topics, it seems
worthwhile to start with the timing of assignments.  Come to think of 
it, some assignments, particularly the class project, affect the topics 
we cover.  And I've found it useful to use class time to debrief on
some of the exams.  So it really is worthwhile to start with the large
pieces of work.

*Planning assignments*

I plan to continue the long-standing model of "homework assignments
and take-home exams are due Tuesday evenings".  Given the schedule,
that means I'll have something due weeks 2, 3, 4, 5, 6, 7, 8, 10,
11, 12, 13, and 14.  The week 2 assignment may be a bit complicated
given that the class doesn't start until Wednesday, but I'll figure
something out.

I've traditionally assigned an exam in week three that is due in week
four.  And for the past few years, we've given four take-home exams.
Given [changes to the add-drop timing]((policy-reflections-2018-08-04)), I
find it less necessary to give a take-home exam so early in the semester.
And it will likely make it easier for both the students and for me if
I have three take-home exams rather than four [10].  So let's have the
take-home exams due in week 5, week 8, and week 14.  I'd prefer to have
one due in week 9, rather than week 8, but that's immediately after
break and it's unfair to have work due immediately after break [11].
I don't want to push the exam to week ten because the project will take
weeks twelve and thirteen, and I'd prefer that they have two assignments
between exams.  Let's see where that puts us.

<table border>
  <tr> <th>Week</th> <th>Work</th> </tr>
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
that HW6 or HW7 will be about topic modeling and it's likely the other
one will have to do with tree traversal.  What about the Scheme-free
assignment?  I'm tempted to have that one be about document markup,
which means that the first Friday of class may need to be about markup
rather than Scheme.  I think that will be okay.  In any case, it behooves
me to move on to the schedule before filling in more details of the
assignments.

*Some starting points*

With the big picture of assignments out of the way, I'm now ready to
explore particular topics we'll cover and the way in which I'll order
them.  As a starting point, let's look at the schedule for last spring
(the first spring offering of the data-science CSC 151)

I suppose it wouldn't hurt to look at the schedule from the previous spring
(the last spring offering of the media-computation CSC 151), too.

While the media computation will help inform me, I'll focus on the
data science one as a starting point.

Add: Regular expressions.  More on trees.  HTML and XML and an exercise
in which students have to mark up documents.  [Fortunately, I have
resources for such an exercise; there's a plain-text, not-perfectly
OCR'd version of the _Scarlet and Black_ archive.]

Change: Only three exams.

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

---

*Verison 0.1 of 2018-09-04.*
