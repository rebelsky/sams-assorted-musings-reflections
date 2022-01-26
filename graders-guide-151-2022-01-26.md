---
title: A grader's guide to CSC-151
number: 1183
tags: [CSC-151](index-151), Things I had to write anyway
blurb: General guidance for my generous graders.
version: 1.0
released: 2022-01-26
current:
---
_As I noted earlier, I'm thinking about ways to improve CSC-151.  One
important step is to give better and clearer guidance to my graders.
Today's musing is my draft of "A grader's guide to 151"._

## Introduction

Dear CSC-151 Graders,

Welcome to the CSC-151 grading team.  And **Thank you!**  CSC-151
asks students to do a lot of work: eight mini-projects, daily labs,
daily reading responses, and lots of learning assessments.  Prompt
and thoughtful grading helps students do better in the course.

Traditionally, instructors grade daily reading responses and learning
assessments while graders grade daily lab write-ups and weekly
mini-projects (with the exception of the last mini-project, which
the instructor normally grades).  Graders are also generally
responsible for re-dos of mini-projects.  Some instructors may also
ask graders to help with reading responses and LAs.  Some may
contribute to the grading of mini-projects.

## Primary Responsibilities

As a grader, you have three main responsibilities.  Your most
important responsibility is to give feedback to the students.  That
is, you should help students understand what they are doing well
and what they should improve.  While correctness is important, I
expect that you will also give regular and thoughtful feedback on
style and program design.  I've included a basic style checklist
at the end of this guide, but that's just to give you the flavor
of the kinds of things I want you to discuss.  Let me know if
you have questions about program style.

Your second most important responsibility is to provide information
to me.  I like to hear what common problems you see; such problems
normally suggest that I need to review a topic and cover it
differently the next time.  Common problems also provide excellent
topics for weekly Mentor sessions.  I also like to hear about
students who have done a particularly nice job or a particularly
poor job.

Your third responsibility is to provide grades to the students in a 
timely manner.

To support grading, we will have a weekly meeting.  During most meetings,
we will look at the upcoming mini-project, discuss approaches to grading,
and consider how things are going.  You will also have the opportunity
to spend some time grading with me there and to get some feedback.

## Dividing Work

We have nine graders for three sections of CSC-151.  Three of the
graders will be responsible for Monday labs (due Tuesday), three
will be responsible for Wednesday labs (due Thursday), and three
will be responsible for Friday labs (due Sunday).  Each grader should
plan to do about 1/9 of the MPs, although you should be willing to do
a bit more if someone needs to pull back a bit.

## Timeliness goals

As I noted, I'd like to get grades back to students as soon as we
can.  Here are the more particular goals.

* _Mini-Projects_: Received Thursday night, graded by Sunday night.
* _Mini-Project Redos_: Graded by Sunday night of SoLA weeks.  That
  means that there may be a few weeks before they get these back; if
  you can do them more promptly, that's awesome.  But I expect that
  SoLA weeks will be the only spare time you have.
* _Labs_: Graded within a day or two of when they are due.  Monday
  labs are due Tuesday night and should be graded by Thursday night.
  Wednesday labs are due Thursday night and should be graded by
  Sunday night.  Friday labs are due Sunday night and should be graded
  by Tuesday night.

## Weekly meetings

Here's an approximate agenda for our weekly meetings.  

You should read the assignment (MP) and the rubric in preparation
for the meeting.

* We will discuss where things stand in terms of grading.  Are we behind?
  Are folks expecting obstacles this week?  Can other folks help pick up
  some of the slack?
* We will quickly go over the rubric, giving you a chance to ask questions.
* I will grade one assignment "live", trying to explain what I'm doing as
  I go.
* Each of you will grade one or two mini-projects while we are all
  together.
* I'll randomly pick one or two of your graded mini-projects and we'll
  go over them.

## Grading Mini-Projects

Note that there are five aspects to grading the mini-projects.

* You should add comments to the code about style and design.
* You should fill out the rubric.
* You should assign a grade based on the rubric and the autograder results.
* You should give the students a checklist of things to fix so that they
  know what changes to make to get to the next level (and, preferably, to 
  get to an E).
* You should provide positive feedback on some aspect of the project.

**Step Zero: Read the assignment and rubric**

As noted above, we'll have time in our weekly meetings for questions
about the rubric.  You can also message me on teams.

**Step One: Read and comment on the code**

Your goal here is to get a broad sense of the code.  As you are looking
at the code, you should add comments about style and program design.

Please encourage students to give more details in their citations
acknowledgements than just a name.  In particular, they should 
specify what help or procedures they got from those sources.
"I got help from E. Tutor" is incomplete; "I got help from E.
Tutor on the design of _this procedure_" is much preferred.

As appropriate, you should add items to the checklist.  For example,
if you notice a common formatting issue, you should mention it.

**Step Two: Review the autograder results**

Ideally, the student will have passed all of the autograder tests.
If not, you may want to re-review the code relating to the failed
tests.

**Step Three: Fill in the rubric**

I think this is straightforward.  It may be useful to have a printed copy
of the rubric at hand; we'll give that a try.

Once again, you should add notes to the checklist about anything missing.

**Step Four: Select the appropriate grade**

The rubric plus the autograder should give you information on the grade.
(I'm hoping to redo the autograder so that it indicates which levels it's
testing.)

**Step Five: Add anything appropriate to the checklist**

If you think of anything else that would be useful to fix, please note
it there.

**Step Six: Send me feedback**

Let me know if there are common problems you observed.  Also, tell me
about students who did particularly well or particularly poorly.

## Grading Labs

At the start of the semester, you should generally look at the whole
lab.  Most of your comments will be about style, with the occasional
note about correctness.  If students have made what seems to be an
appropriately serious attempt, they get credit for the lab.

While grading labs, you should pay attention to common problems and
then inform me about such problems.  If you see students struggling,
please share their names with me.

## A Style Checklist

This is an incomplete list of more style issues you might attend to.
You should also review [my style guide](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2022Sp/handouts/style-guide).

```
[ ] The code should have been reindented with Ctrl-I.  (We won't hit this
    one for the first week or so.)
[ ] There should be blank lines between procedures so that code does not
    run together.
[ ] Spaces belong before open parens but not after immediately them.
    Spaces should also separate parameters.
    Good: `(+ (* 2 3) 4)`
    Bad: `( +(* 2 3 )4)`
[ ] Students should avoid too-long lines (both in terms of too much stuff
    in one line and in terms of going too far to the right).
[ ] In most cases, parameters should all be on the same line or each on 
    its own line.  Make sure that students avoid what I'd call "dangling
    parameters", those that follow a multi-line expression.
    Bad: `(* 2 (+ 3
                  4) 5)`
[ ] Students should spell correctly.
[ ] Students should avoid repeated code and repeated calculations.  (This
    may have to wait until they know variables/let.)
[ ] Students should not use `length` to determine if a list has only one
    element (or only two elements or ...).
[ ] If possible, avoid using `append`.  In general, `cons` is much better.
```
