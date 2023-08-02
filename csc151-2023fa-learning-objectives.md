---
title: Learning objectives for CSC-151 (2023Fa)
number: 1243
tags: [Teaching](index-teaching)
blurb: How many? Which ones?
version: 1.0
released: 2023-08-01
current: 
---
It's the time of the summer when I start getting my fall classes ready. I even feel a bit behind; there's less than a month until the first day of classes. Agh!

In any case, one of the first things I do when putting together a class is to summarize the learning objectives for the course (or at least the primary topics) [1]. The design of the class should be structured around those goals. In addition, since I'll be using a form of mastery grading in my fall classes, the learning objectives are central to the grading system.

Today, we'll consider my preliminary design for the learning objectives for my section of CSC-151 [2]. This fall, I'm returning to a version of CSC-151 that emphasizes image making and manipulation. The last time I taught such a course was in the spring of 2017. 

The last time I taught CSC-151, I identified twenty-eight learning objectives, about two for every three days of class. I broke the assessment of those up over four sets of learning assessments (SoLAs) [3], with seven LAs per set.

I've been away from CSC-151 for more than a year. In the interim, my colleagues have designed a new version of the course, one based on the composition of electronic music [4].  Their version has only _fifteen_ learning objectives. I'm pretty sure part of their course design philosophy was to pick as few as they could. In addition, fifteen learning objectives allowed them to get by with three SoLAs.

In planning for this fall's CSC-151, I went through both lists of learning objectives, as well as the list of topics from the old media-computation version of CSC-151. I tried to stay as minimalist as I could. Nonetheless, I ended up with 24, which I've grouped into four sets of six.

Why have I identified **nine** more learning objectives than my colleagues, about 60% more? Perhaps I think of the course differently. Perhaps I think of learning objectives differently. Perhaps I'm just excessive. It's something to investigate---or at least something to muse upon.

Let's start with the data. Here are my colleagues' learning objectives.

**Phase One**

* **Decomposition**. Decompose a computational problem into smaller sub-problems amendable to implementation with functions.
* **Procedural abstraction**. Take a concrete implementation in Racket and create a procedure that generalizes that behavior.
* **Tracing**. Trace the execution of a Racket program using a substitutive model of computation.
* **Primitive types**. Express basic computations over primitive values and their associated standard library functions.
* **Lists**. Manipulate lists with fundamental higher-order list functions.
   
**Phase Two**

* **Code style**. Correct the formatting and style of an existing program.
* **Software Engineering in the Small**. Write appropriate levels of documentation and unit tests for functions.
* **Local bindings**. Refactor redundancy and add clarity in computations with let-bindings.
* **List recursion**.  Design and write recursive functions over lists.
* **Numeric recursion**.  Design and write recursive functions over the natural numbers.

**Phase Three*

* **Dictionaries**.  Design and write functions that use dictionaries.
* **Vectors**.  Design and write functions (potentially recursive functions) that use vectors.
* **Tree recursion**.  Design and write recursive functions over trees.
* **Running time**.  Use a mental model of computation to count the relevant number of operations performed by a function.
* **Sorting and Searching**.  Update or modify fundamental sorting and searching algorithms or trace the execution of those algorithms over concrete inputs.

Not a bad list. It includes key aspects of computational thinking (e.g., decomposition and procedural abstraction), programming basics (e.g., naming variables with local bindings, procedures, a few data types), some recursion, and other topics.

What does my list look like? Here goes! I've also added a few comments on the changes I've made (in italics).

**Phase One**

* **Decomposition**. Decompose a computational problem into smaller sub-problems amendable to implementation with procedures.
* **Procedural abstraction**. Take a concrete implementation in Racket and create a procedure that generalizes that behavior.
* **Tracing**. Trace the execution of a Racket program using a substitutive model of computation. This LA may only be completed in class.
* **Primitive types**. Express basic computations over primitive values and their associated standard library functions.
* **Conditionals**. Use Boolean expressions and conditional operations to produce conditional behavior.   _I added this core aspect of programming. I think colleagues felt it would appear within other topics, such as recursion._
* **Collaboration**. Explain best practices for solving problems in a collaborative setting. _I added this topic. Collaboration is a focus of the course and should therefore be listed as a learning objective._

**Phase Two**
 
* **Code style**. Write and structure code in ways that make it easier to understand.
* **Documentation**. Document programs according to good software engineering principles. _I broke their "Software Engineering in the Small" into two parts. To me, documentation and testing are separate issues and should be assessed separately._
* **Testing**. Test programs according to good software engineering principles. _A different skill._
* **Lists**. Manipulate lists with fundamental higher-order list functions.
* **Lambda-free anonymous procedures**. Use `section` and composition to simplify computations. _Section and composition provide a different way to think about building procedures. I spent enough time reading Backus' Turing Award Talk [5] that I consider this approach a key aspect of functional thinking._
* **List recursion**.  Design and write recursive functions over lists.

**Phase Three*

* **Ethical considerations**.  Consider implications of the power of computing. _My colleagues had added a day on ethical considerations (in addition to the ethical considerations I hope we consider throughout the semester). We show value by making it a learning outcome._
* **Local bindings**. Refactor redundancy and add clarity in computations with let-bindings.
* **Numeric recursion**.  Design and write recursive functions over the natural numbers.
* **Vectors**.  Design and write functions (potentially recursive functions) that use vectors.
* **Diagramming structures**.  Use our mental model of memory to describe or diagram the layout of memory for lists, pairs, and vectors/arrays. This LA may only be completed in class. _Just as students should be able to trace the evaluation of code, they should also understand how data are arranged._
* **Dictionaries**.  Design and write functions that use dictionaries.

**Phase Four**

* **Data abstraction**.  Design data structures to separate interface from implementation. _The data version of procedural abstraction._
* **Randomness**.  Write programs that produce unpredictable output. _In my model, students should understand the difference between stateful and stateless programs. Randomness is one such difference._
* **Higher-order programming**.  Write procedures that take procedures as parameters and return procedures as results. _Another key aspect of functional programming._
* **Tree recursion**.  Design and write recursive functions over trees.
* **Running time**.  Use a mental model of computation to count the relevant number of operations performed by a function.
* **Sorting and searching**.  Update or modify fundamental sorting and searching algorithms or trace the execution of those algorithms over concrete inputs.

As I reflect on these changes, what do I see as some differences?

_I include some learning outcomes to show the value of nontechnical topics_. That's why collaboration and ethics are there.

_I prefer to separate compound topics._  For example, my colleagues felt that conditionals were naturally covered elsewhere while I wanted them made explicit. I also split the "software engineering" outcome into two outcomes. I also considered splitting sorting and searching. However, we cover those toward the end of the semester, and I wanted to limit how much of the final topics I want to test students on.

_I like higher-order programming._  I think students need to be able to use higher-order procedures like `compose` and `section`. I also think students need to be able to write their own higher-order procedures. I realize that students will be using `filter`, `map`, and `reduce` in their work with lists and elsewhere. However, I'd prefer that students also be able to write procedures like those.

_I want to further emphasize that students should think about data as well as algorithms._  Data abstraction is a crucial aspect of computational thinking (separating how data are used from how they are organized). And students often need a mental model of data layout to understand issues like running time.

_I'm not always predictable._  Perhaps that's why I added randomness.

I found myself tempted to add learning objectives that correspond to the three models of image making we will use in the course (images as functions from positions to colors, images as collections of manipulated shapes, and turtle graphics). However, 24 learning objectives already seem like enough (or more than enough).

Is my set of 24 learning objectives better than my colleagues' 15?  Not necessarily.  There are reasons to prefer each approach.  I'll be meeting with the other Fall 2023 instructor sometime in the next few weeks to discuss whether or not we want common learning outcomes---or at least how many common learning outcomes we want. For example, I know the other sections tend to use pattern matching to decompose lists, but I prefer not to. I would expect pattern matching to be one of the learning outcomes for the other section.

In a few weeks, you might be able to see where the discussions have led us.

---

**_Postscript_**: Coming soon: Learning objectives for CSC-207.

---

[1] I struggle with the difference between learning goals, learning objectives, and learning outcomes.   In reading the informal literature about these kinds of issues, I see that I'm not the only one who has difficulty telling the difference; I'm not even sure that they are used consistently. I'll try to stick with "learning objectives" for the things I hope students learn in the course and "learning assessments" for one of the smaller mechanisms I use to determine whether or not a student has reached a learning objective. You can think of those as quiz questions or exam problems.

[2] There are three sections of CSC-151 this fall. My section has a different "theme" than the other two sections.

[3] SoLAs are a bit like exams. One important difference is that if you miss any LAs on a SoLA, you can re-try new learning assessments for the same outcomes on the next SoLA.

[4] Or at least sequences of computer-generated sounds.

[5] Backus, John F. (1978).  Can Programming Be Liberated from the von Neumann Style? A Functional Style and Its Algebra of Programs. _Commun. ACM_ 21 (8), August 1978.
