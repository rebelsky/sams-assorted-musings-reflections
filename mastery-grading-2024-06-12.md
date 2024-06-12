---
title: My current approaches to mastery grading
number: 1290
tags: [Teaching](index-teaching), topical revisit
blurb: I'm still working to master it.
version: 01.0
released: 2024-06-13
current: 2024-06-05
---
One of the important contemporary trends in higher education is the use of equitable grading practices. As the name suggests, such practices are designed to help ensure better equity in how students learn. There are many such practices. For example, one might give students a choice of how best to demonstrate their knowledge [1], or one might focus more on what students have learned rather than when they learn [2].

Starting a few years ago, I've been using a form of equitable grading (or perhaps semi-equitable grading) called "mastery grading". To be more precise, I've been using various forms of mastery grading. Mastery grading is a variant of specifications grading and falls under the umbrella of "it's important *what* students learn not *when* they learn it." I consider that philosophy particularly important for CSC-151, our introductory course in computer science, since students enter the course with a wide range of knowledge.

Since I've referred to our mastery grading approach in multiple musings, my muse suggested that I take a step back and describe my current methods of mastery grading. I'll note that I started by using ideas I learned from my colleague, Peter-Michael Osera, but have since modified them based on my experiences as well as conversations with other colleagues. I've also attended a few conference sessions on mastery grading in CS, read some papers, and such.

Two kinds of work form the core of my current mastery grading approach: learning assessments and mini-projects. Learning assessments are small, quiz-sized problems. Each learning assessment corresponds to one of the course's learning objectives (or at least the measurable learning objectives). Mini-projects are mid-sized homework assignments that ask students to apply their knowledge to new problems, ideally larger ones.

In CSC-151, I give students two forms of learning assessments: weekly in-class quizzes and approximately monthly take-home "sets of learning assessments" (SoLAs), akin to take-home exams. In the most recent sections of CSC-151 I taught, I had learning assessments for [twenty-four different learning objectives](csc151-2023fa-learning-objectives). In CSC-207, I aim to give a few take-home LAs each week. I didn't meet that goal this past fall. I started spring 2024 with [fifty different learning objectives](csc207-2024fa-learning-bojectives) but ended up testing students on forty-six or so.

What about mini-projects? I strive for weekly mini-projects. In CSC-151, students get a week off from mini-projects when I assign SoLAs. In CSC-207, students get a week off from mini-projects when they or I seem to need some time off.

Students also have work beyond mini-projects and learning assessments. They read a few pages from what we might call a "textbook" [3] in advance of each class and then turn in responses to a few questions [4]. They work with a partner in class on a lab and turn in a "lab writeup" that consists of their solutions to problems. They must write [metacognitive "pre-reflections" and "post-reflections"](metacognitive-wrappers-2023-09-04) for each mini-project and SoLA.

So that's five kinds of work: LAs, mini-projects, reading responses, lab writeups, and metacognitive reflections.

Where does grading enter the picture? Part of it has to do with the grading scales for each kind of work. LAs, reading responses, lab writeups, and metacognitive reflections are graded on a Satisfactory/Not satisfactory/Not attempted scale. Although these four categories have the same scale, we approach them differently. If a student demonstrates mastery of a topic on an LA, they earn a grade of "Satisfactory". Otherwise, they earn "Not (yet) satisfactory". In the other three categories, as long as the student has tried, they earn "Satisfactory", so they are essentially on a "Satisfactory/Not attempted" scale.

Because mini-projects are more extensive, their grading scale has more values: Exemplary, Meets Expectations, Redo, Incomplete, and Not Attempted. "Meets Expectations" is what the name says: They've answered all the problems more-or-less correctly with few stylistic mistakes. If a student does so well that we'd be happy making their solution an example for other students, they can earn "Exemplary". If they haven't yet achieved "Meets expectations", they generally earn a "Redo". If they haven't attempted many of the problems, they may earn an "Incomplete". 

In addition, most mini-projects contain a rubric that indicates what they must do to reach each level.

What about the philosophy of "it's not important when a student masters a topic"? I handle that by permitting students to redo work. For LAs, that generally means that they try another question on the same topic on the next SoLA. For mini-projects, they receive feedback on what they missed and what they need to do to achieve each level. They can then try again. I usually set a "redo" date for each mini-project (as well as a "second redo" due date and, at times, a "third redo" due date).

Since readings, lab writeups, and metacognitive reflections are timely (in that students need to do them at the assigned time to get the value), I don't generally allow students to redo them or to turn them in more than a few days late. However, as I noted, almost any attempt on these gets them a "Satisfactory" mark.

Students procrastinate. So what encourages them to do LAs and mini-projects the first time through rather than on the redo attempts? I try to send them regular messages about what they are missing. I hope that those reminders provide some encouragement. There's also a "charge" for redoing mini-projects if you did not submit the first time. I'll wait until another musing to describe the token system we use when we charge students for redos or late assignments.

Okay. Where are we? There are five kinds of work. Most are graded on the Satisfactory/Not binary. Mini-projects have a more complicated grading scale. Once everything is graded, how does it turn into a letter grade? We start with LAs. If a student gets a "Satisfactory" on most of the LAs, they have an A in LAs. If they miss a few more, they have a B. A few more, and they have a C. For an A on mini-projects, they need an E on about half and an M on the rest. A B requires fewer Es. A C requires still fewer Es and even permits an R or two.

The *lower* of the LA grade and the MP grade determines their base grade. We then offset upwards by the higher grade. So, an LA grade of C and an MP grade of A gives them a C+ or a B-.

Assignments in the remaining categories only affect grades if students skip too many. Students can miss some number of those (say, six). Any more, and their grades start to drop. For the vast majority of students, it's not an issue. They do the daily work and get the credit.

I'm not thrilled that this form of mastery grading takes so long to describe. I've yet to come up with a good summary. I realize that it sounds like a grading system only a computer scientist would design, but I'm pretty sure it came from mathematicians.

---

Why do I like mastery grading? I hope the reasons are apparent. The process encourages students to persist. At the end of the semester, I have evidence that most of my students have mastered most of the material. And students generally react positively to the approach.

The downsides? Since we have yet to automate the writing and grading of most assignments, it's a lot of work for the instructor. It's also not quite equitable: Students who struggle must spend more time on the course than others. And the students who struggle often have the least extra time.

---

**_Postscript_**: I last wrote about mastery grading [three-and-a-half years ago](mastery-grading-2020-12-05). At least, I last wrote a longer musing focusing on mastery grading then; I've mentioned it many times since. Overcommitted readers may wish to compare my descriptions.

---

[1] Mom was doing that more than thirty years ago.

[2] I suppose the common European (British?) practice of putting all the weight on a final exam also achieves that goal.

[3] Most of these readings were written by a member of the department. In most cases, it was me.

[4] Students seem to read more carefully when they have to answer questions. They are also more likely to read in advance of class if they have to turn something in.