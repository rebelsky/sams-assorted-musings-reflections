---
title: Writing assignments
number: 1277
tags: [CSC-151](index-151), [Teaching](index-teaching), [Overcommitment](index-overcommitment), unedited.
blurb: Another place my time goes.
version: 1.0
released: 2024-03-17
current: 
---

I realize that the title of this musing is ambiguous. It could be about instructors writing assignments (or an instructor writing assignments). It could be about students doing assignments (a task known as "writing" in some areas). It could be about assignments that teach writing. tIs the first of the three. I'm too lazy to retitle it.

---

This semester, as in many semesters, I'm writing and revising assignments in my courses. I did a relatively good job with my most recent set of assignments for CSC-207, so those have been moderately easy and quick to update. CSC-151, on the other hand, has been more of a challenge. This semester is the second time I've taught a version of the new image-based CSC-151 and first time I've used a new library that I've written for the new course.

The first version of the image-based CSC-151 [went pretty well](csc151-2023fa-eoces). But I'm a tinkerer. I wanted to make it better [1]. In addition, fall and spring seem different because they start on different days of the week. So I added the planned library and rearranged topics slightly. Unfortunately, the new library required that I spend extra time rewriting homework assignments ("mini-projects", in the parlance of our class), and the rearrangement suggested that I needed to write some new ones. Some of last semester's assignments needed significant work. For example, I probably shouldn't have had the first recursion assignment focus on deep recursion and I shouldn't have had that assignment do some types of recursion that could better be handled by `map`.

Last week, I wrote a brand-new list-recursion assignment. We haven't graded it yet, but I think it's much better than the homework assignment that it replaced. And I was able to repurpose that one into a new pre-recursion [2] assignment. I keep telling myself that I can write a new assignment in a few hours. But I'm wrong. Always. Let's consider the brand-new list recursion assignment and the assignment that followed that. 

First, let's consider the new assignment.

I begin a new assignment by considering the topics I want the assignment to cover and what kinds of problems (or ideally, what overarching problem) will best correspond to those topics. In this case, since we were dealing with lists, using lists of images or colors seemed like the best approach. 

I considered an image-transformation exercise in which they get lists of colors surrounding each pixel; however, those lists seemed fairly small and there wasn't much to do with the lists other than, say, averaging them or finding an extreme value. Both of those  approaches are likely better handled by one of the higher-order list procedures they know, such as `reduce`.

So I decided to work with lists of images. What kinds of things can you do with lists of images? You can combine neighboring images; a first step for reduction. Of course, you also need lists of images to combine, so that gives problems in which you need to generate lists.

I spent about an hour thinking about problems.

Then, I sat down to write the assignment and implement solutions to the problems on the assignment. Sometimes, I write the assignment first and then write solutions. However, I find it better to draft solutions at the same time so that (a) I can make sure that the problems are appropriate, (b) I can identify hints and helpers that I shold provide, and (c) I can create sample output. After about 90 minutes of writing text and code, I realized that a primary idea for the assignment did not work well. It wasn't quite a "back to the drawing board" moment, but it was clear that I needed to step back and change the approach significantly.

I spent another thirty minutes or so choosing a new approach (or set of approaches). Central to that was using sequences of digits as a "code" for making lists of images and for transforming images. And, once we make lists of images, combining them is appropriate.

On to writing the assignment and the corresponding code. I didn't have one large chunk of time, but I was able to find a few one-hour chunks. I had planned to time myself, but didn't manage to do so. Let's say about three and a half hours. That's "a few hours", right? See, I can write a new assignment in a few hours.

But there's more to writing an assignment than, um, writing the assignment and the answer key. At least there is in my world. 

Next up was writing a template for the students to start with. I think it's better for me to put all the utility code together and arrange what I want from them than to let them do so themselves. It certainly makes things better for the graders, since the answers are nicely divided. And it saves the students time that would be wasted, finding, copying, and pasting code. It took perhaps half an hour to write the template and ensure that it ran.

After that? Writing a rubric. For CSC-151 [3], a good rubric is essential. Not only does it help clarify expectations, it gives them a checklist of the things they should try to complete. A checklist serves them better than having to read through the assignment for all the details, some of which they might accidentally miss. Writing the rubric took another thirty minutes.

Although our graders don't usually need an answer key, our evening tutors benefit from sample solutions. It took another thirty minutes to fit my messy solutions into the template and to add a few notes to help them help students.

You might think I'd be done at that point. But I wasn't. After all of that, my next task is to write an "autograder". The autograder doesn't give them a grade. Rather, it tests the procedures they write. Some tests they should pass trivially. For example, did they write a required procedure? Some tests require more work. For example, does the procedure produce correct output on some typical input? And some tests are more challenging. For example, how well does their procedure handle "edge cases", such as empty lists?

Autograders serve multiple purposes. First of all, an autograder shifts the grader's [4] responsibility from checking whether procedures work correctly to looking at issues of style, design, and efficiency. Nearly as importantly, autograders provide students with feedback while they are developing their code. Since students can see their autograder results each time they submit, and we permit an arbitrary number of submissions up until the assignment is due, they can quickly find out how close they are to specifications. Too often, students think they've written correct code and havn't tried enough different inputs. Autograders help them catch that.

And, admittedly, writing an autograder helps me catch errors in my code and in the assignment's design.

Unfortunately, writing an autograder is a time-consuming activity. This one has 109 tests. Those took me about three hours to write. Maybe a bit more. And I should have written more. But that's about all I could spare for one assignment.

After writing the autograder, I need to set up things on Gradescope. That includes creating the assignment, uploading the autograder, testing the autograder, adding the rubric, creating a pre-reflection assignment, creating a post-reflection assignment, and, perhaps, a few other things. Another thirty minutes.

How much time was that?

* Design: 1 hour
* First writing session: 1.5 hours
* Redesign: 0.5 hours
* Additional writing sessions: 3.5 hours
* Template: 0.5 hours
* Rubric: 0.5 hours
* Sample code: 0.5 hours
* Autograder: 3 hours
* Gradescope: 0.5 hours

Damn! 11.5 hours. Even when I'm pessimistic, I think I can write a new assignment in about eight hours. Perhaps I over-counted, but I don't think so. I'll need to time more carefully next time [5].

And I forgot something. Rather than putting images in the assignment itself, which is a very time-consuming task, I recorded a video. That was another thirty minutes. So twelve hours, all told. Ouch!

You can see [the assignment that resulted from that work](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2024Sp/mps/mp05.html). The autograder and video are currently private [6].

---

I expected the next assignment to be smoother. It was an assignment on fractals I'd written (and rewritten) the previous semester. I had sample code, an autograder, a rubric, and more.

But it needed changes.

What changes?

There were a few problems that stumped students who approached them in the wrong way. I needed to add some clarifying text for those problems. I also wanted to revisit the assignment to decide if anything needed to be simplified or extended. Perhaps most importantly, I needed to update the assignment to match our new image-making library.

Rewriting the text, the template code, and the rubric took a little over an hour. Mayhaps as much as ninety minutes. I cut some procedures that are now part of the standard library. I rewrote some sample code to use the newer versions of some procedures (e.g., replacing `square` with `solid-square`). I added some starter code for the students (e.g., `thinly-outlined-square` and `solid-right-triangle`). Some of these procedures were called for by the revised library (e.g., `solid-right-triangle` is not in the new library, but `right-triangle` was in the old library). Others, like `thinly-outlined-square`, were intended to make their lives easier.

Rewriting the autograder and sample code took another ninety minutes. Why so long? One reason was that there were a lot of procedure calls to check and replace. Both the autograder and sample code contain complete sets of solutions, each of which needed updating. Since these images are complex, the autograder had its own "approximately the same" procedure for comparing images. I had to update that for the new image model. I also discovered that some changes had made the triangle fractals work a bit differently, which entailed updating tests and adding a bit of commentary in the assignment.

I thought I was done after all that. I was wrong.

As I started to play with the sample code, I realized that the code did not behave as I expected. After some experimenting, I discovered that the revised "overlay" code I'd written to better handle overlaying multiple images did not play nice with rotation. Why not? Because the revised code relies on a transparent background to help align overlaid images. But when you rotate a transparent background, it still takes up space. And that issue came into play when we were stacking rotated shapes on top of each other. Fixing that problem was difficult; it involved some conceptualization and some coding. I ended up trimming rotated partially-transparent images. I'm afraid I'll find some examples for which that was the wrong choice. For now, it seems to work for the assignment, so I'm going to let things stand. It took around two hours to fix the code, not least because I misunderstood how the libraries my library depends on work [7].

Here's [the new fractals assignment](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2024Sp/mps/mp06.html). 

How much time did the full rewrite take? Somewhere between five and six hours. And I still need to send the revised solution set to the evening tutors and fine-tune some aspects on Gradescope. It's sad that it takes me longer to write the assignment than it will take most students to write their solutions.

---

So, there you have it. One of the many reasons I always seem a bit behind. One of the many reasons faculty members reuse assignments. Probably one of something else, too.

Oh well. It will be better the next time I teach the course. I won't have a new library to deal with. Any updates will be minor cleanups designed to clarify the assignment. At least that's what I hope.

---

Before I sign off from this musing, I should look ahead. Let's see. I have three assignments left to assign in CSC-151 this semester. 

The next one is probably "pixel problems", which gave students experience with vectors and with images as collections of pixels. That one took me a while to write, not least because I had to write a lot of supporting code. Unfortunately, I must throw away most of that code because the image model has changed. On the other hand, the new image model gives me some other features that are likely useful. I also need to drop one problem that ended up being too mathy and, therefore, overly difficult. Let's say it's a five-hour rewrite (fingers crossed).

After that, we have "word clouds". The word clouds assignment worked really well. Unfortunately, I haven't yet put text into our new image library, and that assignment relies on text. Perhaps two hours to rewrite the assignment once I've updated the library, because students misunderstood some aspects. How much time to update the library? That's going to take a little while to figure out. I'm hoping I can get a reasonable set of functions in place in under four hours.

Finally, we have the two-week group final project. I wanted to rewrite this one completely. We'll see how that goes. If I'm going to rewrite it, I should do so during spring "break". Or at least I should get started during spring break. Can I do it in a day? We'll see.

My co-instructor's going to get fed up with me soon.

---

[1] Yes, I realize that perfect is the enemy of good. But better isn't always the enemy of good.

[2] Precursion?
t
[3] At least for my version of CSC-151.

[4] "The grader" is sometimes me. But for assignments, it's usually a student we've hired and trained for the task.

[5] I hope there won't be too many "next time"s.

[6] Feel free to email me if you'd like a copy.

[7] I had expected that "transparent blue" and "transparent white" would have different encodings. They don't. Every transparent color seems to become transparent white.
