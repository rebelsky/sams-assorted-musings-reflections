---
title: Writing a lab
number: 1274
tags: [CSC-151](index-151), [Teaching](index-teaching), [Overcommitment](index-overcommitment)
blurb: One of the places my time goes.
version: 1.0
released: 2024-02-25
current: 
---
Today I wrote a (partially) new lab for CSC-151, _Functional Problem Solving_. Why do I have labs in CSC-151? Because it's a workshop-style course; we have a lab almost every day of the course.

CSC-151 has been a workshop-style class for more than twenty-five years. Why, you may ask, am I writing a new lab at this point? It's slightly complicated.

One of the primary characteristics of CSC-151, beyond that we teach it using a workshop-style approach, is that we have a "theme" for each section of the course. This year, I decided to return to an old theme of image making, but to approach it differently. Why image making? Because it remains my favorite theme and because we found that students are generally better at finding and fixing errors in procedures that produce images than procedures that produce, say, text [1,2]. Why not just use the old version? Because that version relied on some fragile software and would not run on students' computers. This one was supposed to be better. And last semester went well, but not perfectly.

This semester, I decided to make a large change: Instead of having students use an image-making library that comes with the DrRacket language/environment, I wrote a new version of that library that I think makes more sense [3]. That may not have been the best decision. In any case, having the new library means that I have to check each lab and reading to see if it needs updating.

However, neither is the real reason I was writing a new lab. Rather, last semester, I found that students had a bit of extra struggle with the introduction to list recursion because we had not previously covered `car`, `cdr`, `cons`, and `null`, the basic building blocks of Scheme lists. For some reason, in the transition from the old image-making CSC-151 to recent themed CSC-151, the lab that introduced those concepts had disappeared. I looked at the old lab to reuse it, and there were parts I could use, but I also had to eliminate some parts that were no longer appropriate. More importantly, we've changed the format of labs so that instead of having separate instructions and code files, we put everything in one code file. That change got introduced during the pandemic to better support pair programming and it has worked quite well.

So, I needed to write a (partially) new lab. And today is a weekend day, which means that I potentially have time.

How long did it take?

The new lab has six sections, plus one extra section for those who finish the main part early. I took the first three sections from an old lab from a decade ago, but had to rework them somewhat for the new format. I also added a few tests for the students. I combined a few problems from two decades ago for a fourth section. Once again, I had to rework them somewhat. The other two sections and the extra section are brand new.

All of that, put togehter, was about two and a half hours. I think that's pretty good/efficient.

In the old days, after I wrote a new lab, I'd ask my awesome colleague, Janet Davis, to proofread it [8]. I don't have Janet to do so, and my latest co-teacher is a bit overwhelmed right now. So it becomes my job to proofread. These days, "proofreading" means that I write an autograder and then do the lab. I don't always have time for either. When I don't write a real autograder or do the lab, issues invariably occur during class time. I'd rather avoid those.

Today was a good day for writing the autograder. Many exercises were conceptual and did not require coding. Hence, I did not need to write autograder problems. I'd also written some tests when writing the lab, so I could just reuse those. Once again, it still takes some work to get the code in the right format and to make sure it works. I found about half a dozen errors in the lab by doing so. And it didn't take much time. About 45 minutes to write the autograder and another 15 minutes to write the lab's solutions. 

What else? About five minutes to make the corrections to the lab. About five minutes to set things up on Gradescope and test them. About twenty minutes to make some updates to the reading on list composition and decoposition.

All told, I spent close to four hours writing a lab and its autograder. And that's a lab in which (a) I can borrow problems from past labs and (b) about half the problems are not autograded. Fortunately, I only have a few new labs to write this semester.

Making minor revisions to labs for a new library is much less time consuming.

---

**_Postscript_**: If you wish, you can read [the general instructions for the lab](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2024Sp/labs/list-composition.html) or the [Racket code file the students work with](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2024Sp/code/labs/list-composition.rkt)

---

[1] I don't know about procedures that produce sound.

[2] I did encounter an exception this weekend. A student was trying to calculate the size of the outside of an outlined triangle, given knowledge of the width and height of the triangle and the width of the outline. They couldn't get the right answer, but they couldn't tell why. Or maybe that's not an exception; they could see that they had the wrong answer, and that might have helped them understand why.

[3] I started a long musing on the work to write the new library. I ran out of time to post it.

[4] Poor Janet. That proofreading often happened the day before our classes. In this case, I'm being somewhat responsible in that we won't have the lab until Wednesday, and I'm writing it on Sunday.
