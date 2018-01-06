Updating a course schedule for a new semester
=============================================

This past week, I've been updating my syllabi for a new semester.
You think it would be easy; most things in the course stay the same, it's
just the dates (and details of assignments) that change [1].  So I should
just be able to make a copy and change the dates, right?  But updating
the course schedule never seems that easy.  Let's consider why.

First, I try to consider whether the order of topics from the
past semester is appropriate.  It may be, for example, that I've
decided that I want to move a topic earlier or later in the semester.
For example, I think we'll introduce debugging earlier in the semester
in CSC 151.  It may be that I want to add new topics, which often means
removing other topics.  And, in courses like CSC 151 in which we write
our own readings and labs, it also means that I have to make updates
to the readings and the labs [2].

It's also because of the way I set up my courses.  I try to keep the
source code to my Web site DRY [3] while making materials accessible
from multiple places.  That means, for example, that the due date for
each assignment lives in a single place and then gets propagated to
various other places: The assignment itself, the list of assignments,
the course schedule, and probably some other place that I'm forgetting.
I do repeat myself for the daily course eboards [4] and the documents
that are generated from them.  I should reflect on whether or not that's
good practice [5,6].

Why does my DRY approach mean extra work?  Well, instead of working with
one document (that is, the schedule), I end up working with a variety of
other documents.  In the most recent Jekyll-based site design approach,
which I inherited and adapted from a colleague, the due date for each
assignment lives in the assignment itself and then gets pulled into
the schedule and list of assignments.  That means that I have a lot of
documents to edit: the assignments, the quizzes, the exams, and almost
anything else with a due date [7].

But even if I didn't have a weird site-development strategy [8] and
did not change the order of topics, it would take some time.  Why?
Because Grinnell semesters are not consistent.  In the fall, classes start
on Thursday and we have seven weeks and two days before break.  In the
spring, classes start on Monday or Tuesday [9] and we have eight weeks
before break.  So, while I might have something major due during week
nine in the fall (more than a week after break), I would not generally
have work due during week nine in the spring (the week after break).

The organization of the weeks is therefore a bit different.  If I've set
my topics for the fall so that there is a consistent "theme" for each
week (e.g., data structures), I'm off by a day in the spring.  And a
day is not something that's easy to discard from the semester to et
back on track.  Because of that problem, I sometimes give up on trying
to focus too much on weekly themes.  But there are other problems.
For example, I find that the rhythm of the introductory course works best
if assignments are due on Tuesday evenings and quizzes are on Fridays.
But students will have had one day less of material in the spring,
which means that the assignments have to be somewhat different.

In any case, what seems like an easy task isn't.  And I always find ways
to make it more complicated.  Let's not even get started on what happens
when a course moves from two days per week to three days per week, as 
will happen in both CSC 321 and CSC 322.

Oh well, that's part of the joy of teaching.  And, believe it or not, but
I really do enjoy putting my syllabi together.

---

[1] I may also be updating the [course goals](measurable-learning-outcomes)
for a few courses, but that's a subject for another musing.

[2] Last semester, we introduced debugging in the midst of our discussion
of recursion.  That means that both the reading and lab assume that the
students know recursion.  This semester, we'll be introducing debugging
immediately after they learn functions and long before they learn
recursion.  That means that we have to make some significant changes
to the reading and lab.  But it also has some indirect implications.
For example, I should probably add some problems in subsequent labs that
encourage them to use the debugger.  But those changes are beyond "syllabus
development".  They come with the regular updates to the labs and readings.

[3] "Don't Repeat Yourself".

[4] I use the term "eboard" to refer to the electronic whiteboards I
use during class.  Most of the time, rather than writing on a whiteboard,
I type on the computer.  I should probably write something more extensive
about this practice.

[5] I haven't found a good way to generate parts of the eboards
automatically and, right now, I'm not sure it's worth my time.  The due
dates also take a slightly different form in the eboards, such as "Due
TOMORROW" rather than "Due by 10:30 p.m. on Tuesday, 27 February 2018".

[6] While writing this musing, I did write a script that automatically
extracts the "news" from an eboard, rather than the other way around.

[7] In most cases, I don't have to edit the readings and labs, since the
due date for those does not appear on the pages.  

[8] Adjectives bind to the right, so I could probably just write
"weird site development strategy".  Best to be safe, though.

[9] If MLK day falls on what would normally be the first day of the 
semester, we start the next day.

---

*Version 0.2 of 2018-01-06.*
