---
title: Grading proofs
number: 1409
tags: [Teaching](index-teaching), Technical
blurb: One of my least favorite aspects of teaching.
version: 1.0
released: 2026-05-20
current: 
---
As most people know, there are aspects of teaching that faculty love and aspects of teaching that faculty hate. Things on the positive side include helping something "click" for a student and designing good materials, whether handouts, assignments, or class outlines. I especially enjoy the improv that I find happens in a good class session; my need (and ability) to adapt as students ask questions and make suggestions. There's energy there.

On the opposite end of the scale are the things that sap that energy. Near the bottom is the experience of seeing a student try very hard and still not succeed. Also near the bottom is dealing with issues of academic integrity [1,2]. Grading isn't that near the bottom, but it's definitely on the "things few faculty enjoy" side.

This semester, I've been reminded that some kinds of grading are worse than others. I've been filling in for our upper-level algorithms class [3,4]. Among other things, that means that I've had to grade proofs and proof-like arguments. Other than "I'm sad that the student got this wrong" experiences, this may be my least favorite kind of grading.

You see, not only is it hard to write proofs, it's also hard to grade proofs. There can be multiple ways to prove the same thing, so you can't rely on just a few possible patterns; sometimes, you have to read carefully through a new approach that you didn't expect. The same happens with programs; students can find wonderfully varied approaches. But I've been grading programs for decades; I can read programs, and I know how to test them. Proofs? Not so much.

Even for students who are good at writing proofs, or seem to be good, there's always the challenge of ensuring that they've provided evidence for the small claims and that they've stated assumptions clearly. And getting assumptions right is hard. For example, one of the first things I had to grade in this class (or perhaps that I had to help my graders grade) involved students doing a formal verification of the correctness of a simple algorithm to find the smallest value in an array. Students used invariants, an approach somewhat like proofs by induction. And their invariant was something like "`minVal` is the smallest value in the first `i` elements of `arr`." Sounds good, doesn't it?

Students had to start with a base case. And most of them chose the case when `i` is 0 as their base case. The algorithm had set `minVal` to infinity at the start of the code. And so they claimed that "infinity is the smallest value in the empty set".

They're wrong. It's not. Infinity isn't a member of the empty set, so it can't be the smallest value in the empty set. In fact, the empty set doesn't have a smallest value; it's a meaningless concept.

As computer scientists, they're used to functions having "sensible" default values. For example, in the version of Scheme we use, the sum of all the values in the empty list is 0, and the product of all the values in that list is 1. Why? Because 0 is the additive identity and 1 is the multiplicative identity. That is, it makes things easier, particularly when you implement the procedures recursively.

However, just because code makes "interesting" assumptions doesn't mean they can make the same kinds of assumptions in a proof, at least not an inductive proof. Rather, they must be more careful.

If I recall correctly, almost everyone got this argument wrong the first time. Some got it wrong the second time. I ended up rewriting the problem to make the proof easier [5]. I also spent time talking through the issues with students.

It felt like every proof I graded was like this. That is, students regularly made strange  (and incorrect) assumptions. But I often had to spend some time checking whether their assumptions were reasonable; at times, assumptions I assumed were unreasonable turned out to be provably correct. The students hadn't proven them correct, but at least they were correct.

I'm not sure that we gave them enough examples of good proofs; as I said (or at least I think I said), I started the class midway through. I wrote handouts on proof techniques, I talked to them about what to include in a proof, I even let them know that CLRS had good proofs, but I may not have done enough proofs in class.

In any case, students struggled. And I struggled not only to decide whether or not the proofs were correct, but also to provide them with guidance that would help them write better proofs in the future. 

The form of mastery grading for the course was both a positive and a negative. Students were allowed to redo anything they got wrong. In some cases, they also had to reflect on what mistakes they'd made and why. So the only "penalty" for getting things wrong was that they had to spend time getting them right. That's a positive; we could reach a time when both the student and I were confident that they had a correct proof. The negative? I kept having to do careful reading of the same proof again and again and again. While most students got it right the second time, some took multiple tries. Even with "right the second time", I was looking at what was effectively twice as many proofs.

In the end, grading these proofs took a lot of time and a lot of mental energy. While the students' eventual success was a reward, I'm not sure that either they or I found it worth the work.

Maybe grading proofs gets easier with time. I suppose I'll find that out the next time I teach the course, assuming there is a next time. I know I'll do more examples. I know I'll provide more resources on how to prove things. And I expect I'll choose different problems.

Still, it will be a challenge.

---

[1] Or, more precisely, the lack of such integrity.

[2] Stay tuned for a few musings on the subject.

[3] For the CS folk among the readers, this is our upper-level CLRS-style course.

[4] For the Grinnell CS folk, it's CSC-301, _Analysis of Algorithms_.

[5] I hadn't written the original.
