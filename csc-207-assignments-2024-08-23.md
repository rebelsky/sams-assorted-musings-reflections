---
title: Assignments for CSC-207
number: 1303
tags: [CSC-207](index-csc207), long and boring
blurb: One of those musings that almost no one else cares about.
version: 1.0
released: 
current: 2024-08-23
---
We're closing in on the start of the semester, and I'm trying to wrap up the planning for CSC-207. One of the tasks I'd hoped to accomplish this summer was to revisit the assignment for CSC-207. Since I give weekly assignments, starting in about week 2, there can be about a dozen assignments in the course. However, I usually give somewhat fewer so that students can get weeks off.

I'm fairly happy with the assignments from last semester. However, as I [noted recently](csc-207-2024fa), it's worth considering new versions of others I've given in the past or that my colleagues have given. While I wouldn't give "the vending machine assignment" verbatim, it is an assignment that students reports helps them learn a lot (and, unfortunately, tends to stress them a bit too much). And I've been teaching this course, off and on, for about twenty-five years, so there are likely assignments I've written and forgotten about.

I'm not sure whether anyone else will care much about these notes. However, putting them in a musing encourages me to do a slightly more thorough job of considering options.

Here goes ...

Assignments from [last semester](https://rebelsky.cs.grinnell.edu/Courses/CSC207/2024Sp/mps/)
------------------------------

### Mini-Project 1: Classical encryption

This assignment asks students to write programs that encrypt and decrypt text using Caesar and Vigenere ciphers. I borrowed this assignment from PM and have been gradually changing it. It's intended as a first assignment to get students used to Java without objects, GitHub, and multi-file programs. If I keep this assignment, I should rephrase it as an opportunity to use libraries that students develop.

### Mini-Project 2: Fun with fractions

I wrote this one some years back. In class, I use fractions as one of the first compound objects that students write. The assignment asks them to write text-based calculators. It gives students more experience with multi-file programs, with the basics of object-oriented programming, and a bit of something like delegation. (E.g., to multiply two fractions, you'll need to ask the numerator of the first to multiply itself by the numerator of the second.) This assignment is where students first have to struggle with issues like "the multiplication operation only takes one parameter".

### Mini-Project 3: Text layout

I designed this one too many years ago to get students to think about subtype polymorphism. We have various kinds of blocks of text, each of which contains other kinds of blocks of text. It is, in effect, a simplified version of what happens in typical code-based UI layout (for those who still do code-based UI layout). That is, each text block is like a UI component.

This assignment feels like it's getting a bit stale. Perhaps I should focus less on the underlying text and more on making "interesting abstract ASCII art" or some such. We could have things like triangles (which require storage of only the number of rows) in addition to other options. Hmmmm ...

Let's see ...

* An n-by-m rectangle of some character is a text block.
* An n-by-n right triangle of some character is a text block.
* An n-high isosceles triangle of some chracter is a text block.
* The positioning of two textblocks side-by-side is a text block.
* The positioning of two textblocks above each other is a text block.
* A text block surrounded by an outline is a text block.

Oh, yeah. This also introduces them to recursive types (which are, perhaps, a natural aspect of some kinds of subtype polymorphism).

Now that I'm looking at this assignment in a new light, I think it's worth keeping and rewriting.

Mayhaps I need a better name than "text block". Perhaps "AsciiImage".

### Mini-project 4: Associative arrays

This assignment is relatively straightforward: I ask students to implement unordered associative arrays. The assignment provides the opportunity to design and build a "real" library (although I provide most of the API). I also use it as our group testing exercise; everyone needs to provide new tests.

The failure of the class to maintain a working collaborative GitHub is an important lesson. (Perhaps this year they'll do better.) But I suppose that could hold for any assignment where I ask for a collaborative test suite.

The assignment also leads naturally into the next assignment.

### Mini-project 5: Augmentive and alternative communication devices

I adapted this assignment from Catie Baker at Creighton. I had wanted to give students the opportunity to reflect on issues of accessibility, and Baker's assignment does a good job. Students also get opportunities to build the back end of a GUI application (which means they work as part of a larger project) and to use and extend the associative arrays they built for the prior project. Nothing does as well to teach you about what you did wrong as to use your code in a new context.

Hmmm ... as I look at those last two projects, I definitely seem to be one of those people who believes that students learn from (controlled) failure.

Detour
------

_Whoops! I was hoping that this activity would give me incentive to swap out assignments that were working less well. So far, I like all of them. Well, to be clear, I think the text layout assignment needs reworking, but I like a significantly reworked/renamed version of the text layout assignment._

Back to last semester
---------------------

### Mini-project 6: Sorting out sorting

What good is a data structures and algorithms class without some sorting activity? Last year, I asked students to implement some core sorting algorithms (merge sort, Quicksort, insertion sort) and then to write their own hybrid sorting algorithm (somewhat like TimSort). They were allowed to use generative AI to help them write their own sorting algorithm. We then had a competition between sorting algorithms.

The competition is a lot of fun. However, not all the students took the "write your own sorting algorithm" seriously. "I wrote Bogosort" was an answer from too many students.

Last semester's students also noted that they'd never written selection sort. I should probably add that option.

I know that some of my colleagues have asked students to gather data about their sorting algorithms in order to see how they behave in practice. Do I want to add something like that?

### Mini-project 7: Blockchains

Another assignment I adapted from Peter-Michael. In the assignment, students implement a simple blockchain to keep track of interactions between two people. They learn about nonces and more. I like the assignment
