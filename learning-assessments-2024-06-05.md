---
title: Learning assessments
number: 1288
tags: [Teaching](index-teaching)
blurb: Assessments, objectives, outcomes, goals, and the ilk.
version: 1.0
released: 2024-06-05
current:
---
As most readers know, I've moved to a form of [mastery grading](mastery-grading-2020-12-05) in my classes [1]. These days, the two central aspects of my approach to mastery grading are mini-projects and learning assessments. Mini-projects are essentially homework assignments. We call them mini-projects because we hope students can extend some into personal projects. Even though we use many kinds of learning assessments, Learning Assessments (with capital letters) (also LAs) are small problems that we use to check their understanding/mastery of core course topics. Think of each LA as comparable to a quiz or a problem on an examination, something that students should be able to finish in fifteen minutes or so.

What do LAs assess? As I said, the core course topics. Of course, these days, we phrase "core course topics" as "learning objectives", "learning goals", or "learning outcomes". I'm never exactly sure what distinguishes the three. I think "outcomes" are what you get after assessing learning goals or objectives. Goals vs. objectives? Even though I know the terms are used differently in different contexts, I believe Grinnell uses "objectives" for smaller things (e.g., "course learning objectives") and "goals" for larger things (e.g., "department learning goals"). 

In any case, we've moved from a "students should learn X" (e.g, "students should learn linked lists") to something much more action oriented (e.g., "students should be able to describe, implement, and use linked lists"). And, like many institutions of higher education, Grinnell has caught the assessment bug [2]. So, in addition to saying, "students should be able to do X", we want to make sure that they can do X. Fortunately, mastery grading makes that easy. As their name suggests, LAs provide one form of assessment. Mini-projects provide another [3].

I struggle to find the appropriate granularity of learning objectives. For example, one of my colleagues has a learning objective of "Use and build core abstract data types to design solutions to programming tasks: Arrays, Lists, Maps and Sets, Stacks and Queues, Hash Tables, Heaps, and Trees". I count nine different data structures or ADTs there. And so, in writing learning assessments, I had nine different LAs, one per data structure or abstract data type [4,5]. Instead of "use and build", I had "describe and implement".

But I could have had eighteen, or even twenty-seven, just for those nine structures. _Describe_ each of the nine. _Implement_ each of the nine. _Use_ each of the nine. They represent different skills and different kinds of knowledge. In grading LAs, I saw some students who could describe a data structure but couldn't implement it and others who provided great implementations but inadequate descriptions.

What's the right granularity? One question? Nine? Eighteen? Twenty-seven? More? For this category, I plan to stick with nine, at least for the time being.

I have similar questions about sorting. They learn about five major sorting algorithms in CSC-207: insertion sort, selection sort, merge sort (top-down or bottom-up), Quicksort, and heap sort. Does each deserve it's own learning objective and LA? Certainly, many students who can implement insertion sort can't implement Quicksort. And what about the variants of each algorithm? Quicksort on lists differs from Quicksort on arrays.

I also have another issue in designing learning objectives and learning assessments. There are topics that we expect faculty to cover in particular courses. For example, we expect that students in CSC-161 will work from the command line and use a debugger and that students in CSC-207 will use an IDE [6] and a shared revision control system [7]. When we used to list topics we expected everyone to cover, we'd say that. But now, if we want to ensure that everyone who teaches a class covers a topic, we need to have a corresponding learning objective. And if we have a learning objective, we should have a learning assessment. What does an LA for "Student can develop programs in an IDE" look like? For Git/GitHub, it's a bit easier; I mostly ask for the log of a collaborative project. Or should I combine IDEs and version control systems?

As my CSC-207 students know [8], I'm often a minimalist. When designing an ADT, I want them to focus on a small set of operations core to the ADT, rather than everything that might be useful. What does minimalism mean for LAs? It could mean "design as few LAs as possible". Or it could mean "design fine-grained LAs that test only one thing". I prefer the latter.

However, when you shoot for fine-grained LAs, or at least when I shoot for fine-grained LAs, I end up with a lot. I wrote [fifty learning outcomes for CSC-207](csc207-2023fa-learning-objective). I ended up covering forty-eight of them in the course and testing my students on forty-five or so. I know it sounds like a lot. But when we do fine-grained assessments, you get more. Would it be better to combine the five sorting algorithms into one LA and the nine ADT/DS problems into a second one? Nope. But it would decrease the count.

For now, I'm sticking with lots of small objectives, rather than a few over-arching objectives. 

---

[1] Wow. I wrote that musing three-and-a-half years ago. It's time to write something new.

[2] Or been forced by our accreditors to catch that bug.

[3] For larger, higher-order, or more complex skills, I still believe that "I know it when I see it" is the best assessment. For example, we don't have a way to assess "Grinnellians are prepared to serve the common good in work and in life", or whatever our mission statement says.

[4] I had a slightly different set of ADTs and data structures.

[5] Data structures are more implementation oriented; Abstract Data Types (ADTs) are a bit more conceptual.

[6] Integrated Development Environment.

[7] Usually Git and GitHub.

[8] Or should know.
