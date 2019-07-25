A revised draft schedule for the new "digital humanities" CSC 151
=================================================================

*Topics/tags: [CSC151](index-151), Racket, digital humanities, teaching, short*

About a month ago, I put together [a draft schedule for the course
tentatively entitled _A Functional Approach to Digital Humanities_
(_FunDHum_)](fundhum-schedule-00).  As I continue to make slow progress
on writing the testbook for _FunDHum_, I find myself naturally thinking
about revising the topics I will cover and the order in which I will
cover them.  That is, although the proposed schedule influences what 
topics I address and how I address them, addressing those topics also
leads me to revise the schedule.

Here's the original draft of the schedule ("draft 0", in my parlance).

!!quickschedule MWF < csc151-schedules/fundhum-00

Some time in late October,  I started thinking about two particular 
changes to that schedule.

First, I realized that I wanted to include dictionaries (hash tables) in
the course; they prove useful for many too many things to leave them out.
If I recall correctly, writing the [draft of the first version of the
final project](fundhum-project-00) led me to think about the need for
hash tables.

Second, as I wrote a new set of materials on evaluating expressions,
I found that evaluation really seemed to need a day of its own.

_Issues to address_: A second day on procedures and order of evaluation,
or maybe just about evaluation.  A day on hash tables.

* _Step one_: Combine Booleans and conditionals.  _Step two_: Add
hash tables to vectors (ouch!).
* _Other issues_: Move structures earlier.  Reflect on Friday topics.
* _Missing_: I/O.  Pauses for breath other than "Discuss exam".

Here's the new version [1].

!!quickschedule MWF < csc151-schedules/fundhum-01

Some time thereafter, I realized that there were way too many problems
with this schedule.  First, debugging seems to show less utility until
students have done a bit of recursive programming [2].  Second, it
doesn't make much sense to introduce vectors or pair structures until
students know recursion, since they need recursion to process those
kinds of structures.  Third, I seem to have moved the week of the
exam 2 discussion.  Finally, there are still no "pause for breath" days.  
I'm not sure that I'll ever get those into the schedule.  

Time to try again.  I have noted that if I'm covering hash tables, I
probably don't need to cover association lists.  Linear search is a
natural operation to discuss, but we don't need association lists to
do that.

!!quickschedule MWF < csc151-schedules/fundhum-02

I don't have the third exam and project explicitly in this schedule.  The
plan was to have the project proposal due week 12, the project due week
13, and the third exam due week 14.  But now I'm finding myself wondering 
if I want to move those around a bit, with the exam due week 12 and
the project due week 14.  Will it be awkward to present without having
finished the project?  Possibly.

Is this the final version of the schedule?  Probably not.  But it should
serve for the time being.

---

[1] No, I have not highlighted the changes.

[2] Is that really the case?  I may have to reflect on that matter again.
There can be good reasons to get it in early.

---

*Version 0.2 of 2018-12-18.*
