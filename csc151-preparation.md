---
title: Preparing for CSC-151
number: 1266
tags: [CSC-151](index-151)
blurb: Some approximate guidance.
version: 1.0
released: 2024-01-03
current: 
---
Congratulations! You're going to be teaching CSC-151.

Now you need to prepare.

From my perspective, there are two primary kinds of course preparation. You necessarily do some things before the semester begins, such as preparing a schedule of topics, setting up a syllabus, posting materials to the Web site, creating a Gradescope entry for the course, [requesting a Team for the course](https://help.grinnell.edu/sp?id=sc_cat_item&sys_id=da02ed791bda29108b40da49cc4bcb02&sysparm_category=8a7684611bdae5108b40da49cc4bcb88), and so on and so forth. In addition, there's the work you do each day (or almost every day).

I suppose those are things you do for any course. CSC-151 differs a bit in that (a) CSC-151 is a workshop-style class with a daily lab; (b) many of the materials have already been prepared (e.g., we have a Jekyll-based Web site that includes daily readings and labs); and (c) you will likely be working with another faculty member on the course. In many instances, that person will be me.

Some aspects of course prep vary from faculty member to faculty member. Some colleagues write all of their assignments (and, perhaps, all of their autograders) before the start of the semester. Others, including me, write and update assignments as they go. I think most of us write exams and SoLAs [1] a week or two before we give them.

In any case, here's my approximate approach.

Before the semester begins
--------------------------

### Preparing the Web site, syllabus, and such.

I generally use the Web site to organize the work I need to do. First, there's the "big picture" organizational activities.

* _Decide upon the likely schedule of topics_. I tell my students that the schedule is always a work in progress; I expect to update it as students express interest in a topic or show confusion about the material.
* _Organize the timing of exams (SoLAs) and assignments (mini-projects)._ I rarely change the due dates of materials since some students plan their work at the start of the semester. However, I may give students extra time or cancel an assignment, but I will never move something up.
* _Revisit the syllabus._ It never hurts to reconsider policies, including grading policies.

Ideally, all the faculty teaching the same theme of CSC-151 will do this together. At times, one of us will take the lead, and others will comment on it. For example, I've set up a draft for this spring.

### Setting up resources

Most sections of the course ask students to submit their work on Gradescope. Most sections of the course set up a Microsoft Teams Team for the course. Some may use Blackboard.

* _Blackboard_. ITS will set up a Blackboard course for you.
* _Gradescope_. You should be able to log in to [Gradescope](https://www.gradescope.com) using your Grinnell ID and then set up a new course. You can grab your class roster from Blackboard. Make sure to add any other 151 teachers to the course. You should also add the course mentors and graders.
* _Teams_. Use the [Teams Working Group Request form](https://help.grinnell.edu/sp?id=sc_cat_item&sys_id=da02ed791bda29108b40da49cc4bcb02&sysparm_category=8a7684611bdae5108b40da49cc4bcb88) link on [help.grinnell.edu](https://help.grinnell.edu). (I don't guarantee I still have the correct link; I found it using "Browse Services" on that site) Once the Team is set up, you may have to add students and colleagues by hand.

### Additional pre-semester tasks for new faculty

Faculty new to teaching CSC-151 should also do the following.

* _Install all the software you need for CSC-151._ DrRacket and Scamper are our two primary implementations of Scheme. These days, Scamper may not need to be installed, but DrRacket does. Many of us use Microsoft Teams to organize class materials. If you don't have Jekyll installed on your machine, you need Jekyll. I'll assume you already use Git.
* _Grab copies of the various GitHub repos._ I'll discuss those separately.
* _Review the readings to ensure you have a big-picture view of how we approach the material._ It's generally a good idea to do all the labs, but not everyone has time to do so. If you do the labs and notice issues, please make sure to correct them. More experienced faculty should probably revisit them, too.

### Additional pre-semester tasks for experienced faculty

Ideally, experienced faculty will look for ways to improve the course.

* _Design new labs_. We sometimes find that we want to drop some topics and introduce others. For example, some department members decided that structural pattern matching is sufficiently useful that we should cover it in CSC-151, and have added labs for that. I haven't found a way to fit those labs into the image-making version of the course.
* _Update existing labs_. We often take notes on issues we encounter on labs so that we can go back and update them. The month or so before class is a good time to do so.
* _Update [the CSC151 library](https://github.com/grinnell-cs/csc151)_. Perhaps a procedure doesn't work well. Perhaps we want to provide a new procedure to students. This winter, I'm hoping to redo the image and color functions.

Daily class preparation
-----------------------

I generally do my class preparation the night before class. I sometimes do last-minute class preparation on the morning of class. Here's an approximate checklist of activities.

* _Review the topic._ You might have done that already. In any case, you should make sure that you understand the material for the day and that you've identified potential trouble spots.
* _Read and respond to students' reading responses._ Each set of readings comes with a few "self checks". We ask students to answer a few of those on Gradescope. We also give them the opportunity to ask questions. I have reading responses due at 10:00 p.m. the night before class. I generally look at all the ones I've received by 8:00 p.m. That gives me a sense as to what issues are causing difficulty or confusion.
* _Check the lab._ Ideally, we'd do the lab ourselves so that we remember the potential trouble points. I usually don't have time to do that, so my check only involves loading the lab in DrRacket and clicking "Run" to make sure that there are no syntax errors.
* _Check the autograder._ Our autograders are in various states of completion, so it's always worth checking whether the autograder needs more work. Of course, that may involve writing more tests.
* _Set up the lab assignment on Gradescope._ This task should be quick. You create the new assignment (or copy a past one), update the assignment date and due date, add the autograder, and run the autograder on a sample file. At least I think that's all you have to do. For some reason, I tend to forget something. And I forget what it is I forget.
* _Check over the next reading._ Some students will start the next reading soon after class, so you should ensure it's ready. I always find this activity a bit problematic because my brain then focuses on the following topic, rather than the current one.
* _Set up the reading assignment on Gradescope._ Can you tell that we'll spend too much time on Gradescope? Reading assignments are fairly straightforward. Setting one up often involves little more than copying a prior reading assignment and updating the title and due dates.
* _Write the class outline._ I benefit from having an outline of what I intend to do in class. My outlines appear as what I call "eboards" (electronic blackboards). Some folks like to create a slide deck to show in class. Others take notes for themselves. In any case, it is useful to have a few examples at hand for when students ask questions. We'll return to outlines in a future discussion of "approaches to 151" [2].

Other regular activities
------------------------

* _Meet with the Scheme Squad._ We have a weekly meeting of the CSC-151 faculty, the CSC-151 mentors, and the CS department Peer Education Coordinator to discuss how things are going in the course, to plan the upcoming mentor sessions, and to look ahead toward the next week.
* _Meet with the graders._ We are fortunate to have graders for CSC-151. We generally ask our graders to work on lab writeups (a quick check to ensure students are doing the problems) and weekly mini-projects. We meet weekly to review the rubric for the current mini-project, often grading one or two assignments collaboratively and then sitting together to answer questions [3].
* _Write the weekly quiz._ We have weekly quizzes on Fridays. I try to write them on Wednesdays. You and I shoulddiscuss whether we'll use the same quiz or different quizzes [4].
* _Write/revise the weekly mini-project._ We give an assignment (mini-project) every week in which we don't have an exam (set of learning assessements / SoLA). While we often repeat mini-projects, changes in the order of topics or problems with old mini-projects may entail updating a mini-project or writing a new one [5]. The CSC-151 faculty usually collaborate on writing mini-projects, either working together on each one or alternating who is in charge of each [6]. Of course, writing or updating a new mini-project often entails writing a new autograder.
* _Write/find questions for the SoLAs._ We give a set of learning assessments (examinations) every three or four weeks. Each new SoLA usually entails six or so questions on new topics as well as a variety of questions on prior topics that students have not yet mastered [7].
* _Answer student questions._ Students will ask questions during office hours, via email, via Teams, and in other ways. You can decide how best to handle the questions.
* _Grade._ I try to grade quizzes and SoLAs over the weekend so that students get quick responses. I try to grade the meta-cognitive reflections as soon as a I can, but sometimes those fall to the side. The pre-reflections help us see what problems students might have on mini-projects. We may still have a site license to Piazza, and many faculty find that useful for answering questions.
* _Update materials._ Whenever possible, I try to update materials (or at least take notes about what to update) soon after I see what's gone right or wrong. Once I hit the end of the semester, everything gets intertwined and obscured by the fogs of time.
* _Update tokens._ We use a virtual currency known as "tokens" to give students some control over their late work. Students use tokens to turn in work late. Students earn tokens by attending events and writing short reflective paragraphs. I know some faculty use graders to keep track of tokens, but I'm too much of a control freak to do so. I also like reading and responding to their reflective paragraphs.
* _Send out grade reports._ Although students can figure out their current status from Gradescope, I find it helpful to send them regular reminders of what work they have and have not completed. I typically send out the first grade report after grading the first SoLA. Those grade reports also remind me that I should submit academic assessments [8].

We also _run class_ three times per week. Each of us has a different approach to how we structure the class sessions. And that's not preparation. So we'll leave the topic for a separate musing [10].

I've almost certainly left some things out. Nonetheless, I hope this list gives you some sense of the kinds of things you should think about and do as you prepare for and teach CSC-151.

---

[1] Sets of Learning Assessments; the term we use for exams in the mastery-grading approach to CSC-151.

[2] Coming soon to a musing near you.

[3] At least that's the ideal. My ability to do so varies from semester to semester.

[4] It appears that I'm focusing on the coming semester. Here and elsewhere, you'll find that the musing is written to a faculty member teaching with me for the first time (initially, Spring 2024).

[5] I've been planning a longer musing about writing mini-projects. It's on hold until I finish the new instructor's guide to 151.

[6] Feel free to ask me to take on more of this work in your first semester teaching the class.

[7] We use a form of mastery grading in CSC-151. I'm planning a new piece about the current state of mastery grading in the course. For the time being, you can read [an old musing](mastery-grading-2020-12-05.md).

[8] Grinnell asks us to submit notes to Academic Advising when students struggle. The standard CSC-151 syllabus includes a list of times we expect to send such notes. For example, we might send a note when a student misses two classes in a row, fails to turn in an assignment, or has completed below 60% of the learning assessments [9].

[9] We rarely remember to submit all of the Academic Alerts we plan to submit.

[10] I realize that I've left a lot of topics for a separate musing. However, I'd like to keep the length of each musing reasonable. Otherwise, you won't see this material until after the semester has started.
