---
title: Experiments in portfolio mastery grading
number: 1261
tags: [Teaching](index-teaching), [Overcommittment](index-overcommitment)
blurb: A good idea that needs some work.
version: 1.0
released: 2023-12-17
current: 
---
Near the beginning of the pandemic, following the model of my colleague, Peter-Michael Osera, I adopted [a form of mastery grading](mastery-grading-2020-12-05) in CSC-151, _Functional Problem Solving_, the first class in the CS major [1]. Mastery grading is, itself, a variant of specifications grading. The basic idea is that we emphasize *that* students demonstrate they have achieved the measurable learning objectives in the course [2] rather than *when* they achieve those objectives. If a student fails to complete an assessment to standards, they get chances to try again.

The mastery grading approach seems particularly appropriate for introductory computer science. CS often requires different modes of thinking than many students have encountered, so they learn the material at different rates. And we cover mind-bending topics like recursion and higher-order programming in the course. We should make it okay for students to take a little extra time to learn things. We also face the situation that students enter the course with a wide range of backgrounds: Some students have had significant CS exposure in high school; others have never encountered computational thinking. Even those with some background have varied experiences; some have mastered recursion, others haven't even seen it.

Mastery grading isn't a panacea. And, while it's a move in the direction of equitable grading, it is not completely equitable. For example, students who struggle will likely have to spend more time working on the material than others, particularly as they are asked to re-do work they've already spent time on.

Still, I've found it a successful approach. Hence, I've started to adopt variations in my other classes.

---

This past semester, I taught CSC-207, _Object-Oriented Problem Solving, Data Structures, and Algorithms_ [3] for the first time since the pandemic. As I just noted, I decided to find a way to use mastery grading in the course. Since 207 is a higher-level course, I decided to consider some approaches that fit the course better. One idea that sprung to mind was the use of portfolio grading, at least as I think about portfolio grading. As I understand it, portfolio grading involves students deciding what parts of their work for the semester best demonstrate that they have achieved the learning goals of the course and to submit that work along with a few narrative paragraphs.

My organizational skills were not up to snuff this semester, so I did not release the portfolio problems until right before the last week of the semester. I also used somewhat fine-grained learning objectives [4]; students had about 27 different pieces of evidence to provide. All that meant that I had to be fairly quick in giving responses so that they could provide better evidence if the evidence that they first gave needed corections or otherwise failed to suffice.

But 27 learning objectives times 29 students is nearly 800 separate pieces of work to grade. And, as I learned, portfolio solutions are more challenging to grade as the smaller problems I typically give in CSC-151. Fortunately for me [5], not all students turned in solutions by Monday of finals week, so I had only 400 or so things to grade. Still, I finished my first round of grading Monday night of finals week. I finished my second round of grading Wednesday night. I finished a partial round of grading by 1pm on Friday, focusing on new submissions to the harder problems. Although all work was due by 5pm on Friday, I kept grading until about 4:15pm. I'm pretty sure some students managed to get four or five submissions in for some problems [6].

---

At this point, you may be asking why I asked them to show evidence for 27 different learning objectives. It's complicated. CSC-207 has a few big-picture learning objectives. In no particular order, I'd phrase them as:

* Given a problem, students can choose or design an abstract data type (ADT) appropriate to store the data for the problem, implement that ADT or choose an implementation, and design and implement an algorithm to solve the problem [7].
* Students are familiar with the core literature of abstract data types, data structures, and algorithms. 
* Students can informally analyze both iterative and recursive algorithms using Big-O (or the common interpretation of Big-O).
* Students can appropriately apply basic object-oriented techniques, including encapsulation, polymorphism (subtype and parametric), and inheritance in writing programs [8].
* Students can develop moderate-sized programs in the Java programming language.
* Students can collaborate on the development of moderate-sized programs using appropriate tools.
* Students can describe the ethical responsibilities of a computing professional.

There are also the learning objectives that I don't try to measure: Students should be able to teach themselves new ideas and approaches, find resources on the Interweb, appreciate the perspectives and contributions of others, develop a passion for certain kinds of problem solving, and such.

As you might have noted, many of these are compound learning objectives. Some are explicitly compound. See, for example, the first outcome or the object-oriented outcome. Others are implicitly compound. For example, the core literature of ADTs includes stacks, queues, priority queues, lists, dictionaries, trees, and graphs. They should know Quicksort and mergesort (and perhaps heapsort or bucket sort). They should be able to traverse trees and graphs, using both depth-first and breadth-first approaches.

I'm not sure that a single small piece of evidence will suffice for most compound learning goals. And if they miss one part of the compound learning goal, do I want to ask them to try the whole thing again again? Grading a solution to a compound goal seems no simpler than grading a set of solutions to the subgoals.

Therefore, I use finer-grained learning objectives. I had hoped that students could provide evidence and a short paragraph in under fifteen minutes each. Seven hours over two weeks should be a reasonable workload. Another two or so to correct the few misunderstood problems, and we'd still be far under the twenty or so hours the College says that I should assign over week 14 and finals week [8].

I'm also not alone in focusing on fine-grained learning objectives. The recommendations from my professional societies for undergraduate CS education lists something like 2000 fine-grained learning objectives, not all of which students have to achieve.

---

How did it go? Fairly well, but less well than I'd hoped. As I've already noted, not all students got feedback quickly enough to prepare revised solutions, particularly when they needed to revise more than once. I also spent far too much time grading in a very short period; I needed to spread it out over the semester. Those issues seem relatively easy to address. For example, I can distribute many of the portfolio problems earlier in the semester and grade them with some regularity. In some cases, I might also provide more detailed instructions [9].

On the other hand, I found an advantage of giving these problems late in the semester; it required students to go back and reflect on what they'd learned. They may not have appreciated it while doing the exam, but I hope they do in the future.

Still, it's too much work for them at the end of the semester. It's also too much for me.

I also identified other issues at play. For example, y fine-grained learning goals include "Students can analyze an iterative algorithm" and "Students can analyze a recursive algorithm". I probably shouldn't have allowed student to choose their own algorithms. For iterative algorithms, many gave simple nested loops, such as those used in selection sort. For recursive algorithms, a surprising number provided the inefficient solution to Fibonacci. I accepted those solutions, even though neither really pushed them to to handle subtle issues of analysis. Next time, it seems that a few of the problems should be a bit less open-ended---not so much "Provide work that demonstrates that you've mastered X" but "Demonstrate that you've mastered X by doing the following". I hope that most learning objectives fall intothe former group.

What else went wrong? Oh, as I noted, some students needed more detailed instructions. For example, one learning objective read _Implement a dictionary ADT in multiple ways, such as with associative arrays, binary search trees, or hash tables._ While I was hoping for two or three examples ("multiple ways"), many students gave only one the first time through. Students also confused data abstraction and procedural abstraction.

I'm not sure what to do with student answers on one problem that make me question their mastery of other objectives. For example, students should know parametric polymorphism ("generics", in Java terminology). Yet lots of them, when writing a stack, gave me a stack of integers. Does that mean that they haven't mastered the concept? It suggests that they have not sufficiently embraced it. I generally gave credit for such solutions, but it makes me worry.

Finally, I discovered that Gradescope doesn't always do what I'd like. For example, I can't see old versions of a student's submission or my corresponding comments. Having those available makes grading redos easier.

---

I think that's it. 

What should I do next semester?

Spread them out, but leave a few for the end of the semester to encourage students to reflect. Or perhaps repeat a few at the end of the semester [10]. I'll probably leave "design an ADT" and "implement an ADT" as end-of-semester problems. 

In some instances, ask them to solve a particular problem rather than provide evidence that they've achieved the learning objective. These include "design an ADT", "implement an ADT", "analyze an iterative algorithm", and "analyze a recursive algorithm".

Make the prompts as specific as possible so that students do not get confused. As part of that, set up different submission forms for different problems, including a way to separate code from commentary [11]. Speaking of submission forms, I should set up separate submission forms for each redo.

Consider further decomposing some learning objectives. For example, "implement and use stacks" might be decomposed into "implement stacks" and "use stacks". While that increases the number of problems, it makes it easier to both do and grade them. It may also make it easier to redo them, in that a student who gets part of a compound objective wrong now only needs to redo part of it.

I'll report back on how the revised approach goes.

---

[1] It also serves as one of our general education courses in computational thinking.

[2] I have many learning goals for my courses that I don't think we can naturally measure, such as a passion for the discipline, the ability to learn on your own, or an appreciation for the skills and perspectives of others.

[3] How's that for a long name?

[4] More on that in a minute.

[5] Although not for the students who didn't turn things in; they got much less feedback.

[6] It's hard to track.

[7] You can perhaps see why I decompose learning objectives.

[8] The powers that be decided that a 4-credit class should require twelve hours of work per week. Since we meet for four hours per week, that's eight hours of work in week fourteen and another twelve hours during finals' week, for a total of twenty hours.

[9] As I discovered, some were less clear than I would have hoped, at least to some of the students.

[10] Maybe that doesn't make sense. If they've already achieved the learning objective, why should I check them again? And won't they just copy their prior answer?

[11] Will Gradescope permit that? We'll see.
