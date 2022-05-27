---
title: Uploading student work to Gradescope and other bad decisions
number: 1189
tags: [Rants](index-rants), technology, teaching
blurb: For each and every action ...
version: 0.1
released: 2022-05-26
current: 
---
I finished my grading for spring semester today.  Correction, I
finished most of my grading for spring semester today.  A bunch of
CSC-151 students took incompletes [1], so I'll have to grade those next
week [2].  That means I have time to muse and perhaps even a bit
of an inclination to muse about grading experiences.

As folks may recall, I've adopted [3] a mastery grading system for
CSC-151.  Students must demonstrate a certain level of achievement
on learning assessments (small problems given in quizzes or exams),
mini-projects (homework assignments), reading reflections, and lab
writeups.  The latter two are relatively straightforward: The evening
before class, students are supposed to do a short reading and respond
to some questions; after our lab-based classes, students submit the
work that they've done.  Since those two kinds of work are relatively
straightforward, grade levels on reflections and writeups generally
depend on the number of each submitted.

Unfortunately, not all students were good at keeping up on the
reflections or writeups.  And some didn't realize quite the impact
of neglecting that work.  So, I got a variety of requests for very
late subissions.  And, well, I'm a softy.

But late requests create a problem: The work needs to be sent to
Gradescope, which is where all the work for the class lives.  I
considered changing the deadline on all of the readings (27) and
labs (30).  But that's a lot of deadlines to change.  And, for some
reason, I convinced myself that I'd then need to do bookkeeping
about which work was on time, which was slightly late, and which
was incredibly late.

So I made a decision.  Students would send the work to me and I'd
upload it.  After all, Gradescope has a way for the instructor to
manage and upload submissions.

But uploading to Gradescope and then grading wasn't quite as
straightforward as I expected.  Here are the steps that it seemed
I needed to follow for a reading response.

* First, pull up the Assignments section of the course.  (I do try
  to keep that up in a tab.)
* Find the particular assignment on the Assignments page..
* Click on it.  Well, command-click on it, because I want it to open in i
  a new pane.
* Switch to the new pane
* Click "Manage Submissions", which appears on the left edge of the page.
* Click on "New Submission", which appears on the bottom of the page,
  near the right.
* Enter the student's name or a part of the student's name.
* Click on the student's name.
* Enter the student's name a second time.  As far as I can tell, Gradescope 
  loads the past work by the student and then clears out the student name 
  field [4].
* Click on the student's name again.
* Copy the student's answer from however they sent it to me (Word,
  email, PDF).
* Paste the answer into the appropriate field.
* Click "Submit & View Submission".
* Click "Next Question".  Wonder, "Why can't I just grade it now?"
* Click "Grade".
* Enter the grade and any comments.
* Click "Next Ungraded" (just to be sure)
* Back to the beginning for the next assignment.

Fortunately, there are fewer steps for the labs, which involve file
uploads.

* Find the particular assignment on the Assignments page..
* Click on it.  Well, command-click on it, because I want it to open in i
  a new pane.
* Switch to the new pane
* Click "Manage Submissions", which appears on the left edge of the page.
* Click on "New Submission", which appears on the bottom of the page,
  near the right.
* Drag and drop the files (or click to get a file dialog).
* Enter the student name or part thereof.
* Click on it when it appears.  Fortunately, this time I only have to do 
  it once.
* Click "Upload"
* Wait for the autograder to complete.  Unfortunately, this can take a
  few minutes.  I suppose it's optional.
* Click "Grade", conveniently on the same page.
* Enter the grade and comments.
* Back to the beginning

Is there a moral to all this?  I suppose one would be "Don't allow
your students to submit really late assignments", but that doesn't
fit into my student-centric worldview.  

I guess I could set late deadlines to the end of the semester, but
that would force me to do some paperwork to tell the difference
between on-time, late, and very late submissions.  It might also
make it harder for students to track the work they've done and the
normal late deadlne (two days after it's normally due).  I suppose
I could ask one of my mentors to do the uploading.

Oh well, I'll figure it out when I teach the course again.  Or maybe
I'll convince my youngest son to write my a script to automate the
steps.  I suppose I could write the script myself, but he's better at
it than I am.

---

**_Postscript_**: I seem to recall an early musing in which I confessed
that I find it difficult to write endings.  I still do.  Oh well, maybe
it's something I'll work on as I resume musing and ranting [5].

---

[1] It was a hard semester.  Students had personal emergencies, got
Covid, and more.

[2] Will I also rant or muse about our incomplete process?  Possibly.

[3] Adapted?

[4] Perhaps I should submit a report.

[5] Or vice versa.
