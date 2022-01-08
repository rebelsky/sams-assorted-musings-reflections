---
title: Yet another draft set of learning outcomes for CSC-151
number: 1182
tags: [CSC-151](index-151), academia
blurb: Rephrasing the wheel.
version: 1.0
released: 2022-01-07
current: 
---
This winter break, the CS faculty have been tasked with writing learning
outcomes for courses that they are teaching in the spring, or at least
for core courses they are teaching in the spring.  

For those not hep to the terminology, learning outcomes are
traditionally measurable changes or achievements we'd expect a
course to instill in students who take the course.  As proponents
of such outcomes suggest, you can't measure the changes in a student's
brain as they learn; more concisely, you can't measure learning.
But folks are enamored of measurement, and so they look for measurable
or more easily observable proxies.

I think I got that right.

Learning outcomes are not just topics.  We don't want to say, for example,
that the course covers balanced binary search trees, or that students have
seen balanced binary search trees.  Rather, we want more active things,
perhaps that students have implemented or analyzed a type of binary search 
tree or that they have applied them to a series of problems.

Here are some examples from CSC-301, _Analysis of Algorithms_, our
upper-division course in algorithms.  It's a CLRS-style course, for
those of you in the field.

* Students can implement a balanced tree.
* Students can read and understand a primary source from the literature of algorithms.
* Given a recurrence relation, students can solve the relation using the Recurrence Formula Theorem [1] and other techniques.

Learning outcomes are also distinct from learning goals, although
I will admit that I lack the depth of understanding to describe the
difference.  At least in some situations, it seems that Grinnell
uses "learning outcomes" for the course and "learning goals" for
larger things, such as the major or an overall Grinnell education.
At least one of my colleagues leading the charge uses the two terms
interchangeably,

In any case, we've been tasked to write them.

I'm glad to hear that we're working on a common understanding of
what goes into our core courses.  We used to have that shared
understanding, some of which was expressed through lists of topics.
Unfortunately, rapid department change and growth have limited 
that shared understanding.  Over-reliance on term faculty hasn't
helped, either.

Since I'm teaching all three sections of CSC-151, _Functional Problem
Solving_, this spring [2], I'm tasked with writing the learning
outcomes for that course.

I hadn't been worried.  When Peter-Michael Osera taught CSC-151, he
wrote a tentative set of learning outcomes, learning outcomes
which I've updated the three times I've taught it since, and which
I've updated again in preparation for teaching the spring sections.
There are twenty-eight of them.  I planned to spend a little bit of
time reflecting on which were core and which were optional, but that's
about it.

The best-laid plans (of M&Ms) gang aft agley, as they say.

Yesterday, I received an email message from one of my chairs that read

> As you prepare your courses, we would like you to develop 5–10 high-level learning outcomes for CSC 151. 

5--10 is a lot less than 28.  I'm also a bit puzzled by the request for
a few high-level outcomes, particularly since we were encouraged to break
more complex or compound learning outcomes into smaller pieces.  Oh well,
I guess I'll have to go in the opposite direction.  It's a good use of
my time, right? [4]

As I said, CSC-151 currently has twenty-eight learning outcomes.  I
group them into groups of seven, reflecting the order in which they are
covered (more or less).  Each group corresponds to one exam [6].
Here's [the current set](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2022Sp/las/).

* Learning Assessments, Phase 1 (LAP 1)
    * Decomposition. Decompose a computational problem into smaller sub-problems amendable to implementation with functions.
    * Procedural abstraction. Take a concrete implementation in Racket and create a procedure that generalizes that behavior.
    * Tracing. Trace the execution of a Racket program using a substitutive model of computation.
    * Primitive Types. Express basic computations over primitive values and their associated standard library functions.
    * Conditionals. Use Boolean expressions and values in a program to produce conditional behavior.
    * Lists. Manipulate lists with fundamental higher-order list functions
    * Collaboration. Explain best practices for solving problems in a collaborative setting.
* Learning Assessments, Phase 2 (LAP 2)
    * Program style. Write and structure program code in ways that make it easier to understand.
    * Local bindings. Refactor redundancy and add clarity in computations with let-bindings.
    * Documentation. Document programs according to good software engineering principles.
    * Testing. Test programs according to good software engineering principles.
    * Regular expressions. Read and write programs that take advantage of regular expressions.
    * List recursion. Design and write recursive functions over lists.
    * Numeric recursion. Design and write recursive functions over the natural numbers.
* Learning Assessments, Phase 3 (LAP 3)
    * Randomness. Write programs that produce unpredictable output.
    * Mental models of memory. Describe or diagram the layout of memory for lists, pairs, and vectors/arrays.
    * Dictionaries. Design and write functions that use dictionaries.
    * Vectors. Design and write functions (potentially recursive functions) that use vectors.
    * Data abstraction. Design data structures to separate interface from implementation.
    * Use higher-order procedures. Use section and composition to simplify computations.
    * Structure textual data. Write and use HTML, XML, and CSS.
* Learning Assessments, Phase 4 (LAP 4)
    * Write higher-order procedures. Write procedures that take procedures as parameters and return procedures as results.
    * Refactoring. Identify repetitious code and factor out the common parts using local bindings or helper procedures.
    * Tail recursion. Transform recursive functions into tail-recursive functions.
    * Tree recursion. Design and write recursive functions over trees.
    * Running time. Use a mental model of computation to count the relevant number of operations performed by a function.
    * Searching. Update or modify fundamental searching algorithms or trace the execution of those algorithms over concrete inputs.
    * Sorting. Update or modify fundamental sorting algorithms or trace the execution of those algorithms over concrete inputs.

Isn't that an awesome list?  

How should I approach the grouping?  I could start by removing the
topic-specific outcomes, such as XML and regular expressions.  Why
are there topic-specific learning outcomes?  Because for the past
fifteen or more years, we've made CSC-151 a topical course; rather
than doing problem solving in the abstract, we've focused on problem
solving in particular topical domains.  Our current domain is
text-based digital humanities.

But it feels more natural to think about the things we should do, rather
than the things we shouldn't do,  Five immediately come to mind, although
perhaps as "topics" rather than as learning outcomes.

* The course introduces computational thinking [6].  We see computational
  thinking most in the learning outcomes related to decomposition and
  abstraction.
* Students employ multiple forms of recursion.
* The course employs functional techniques.  After all, it's called
  _Functional_ problem solving.  Higher-order programming (functions
  as first-class values), recursion (which I've broken out), and a
  lack of side effects are the core aspects of functional problem
  solving.
* Students write programs using the basic tools of a programmer.
  We don't have loops, but we have conditionals, types, bindings,
  and more.
* Students also employ basic software-engineering approaches.
* Students explore different data types, such as lists and arrays.

Whoops.  That's six.  I see a seventh, down at the bottom of my
list. 

* Students consider the basics of algorithm design and analysis,
  including fundamental algorithms and their analysis.

Do I want to add something about contrasting side-effecting and pure
models, or does that belong under functional techniques?  Hmmm ....
It may be that I need to add another learning outcome.  I wonder which
one I should drop.  Oh well, that's a task for another day.

Time to group and rephrase.  Or maybe it's time to group and rephrase.

* **Computational Thinking**. **_Students can solve problems using computational
  thinking tools_**.
    * _Decomposition_. Decompose a computational problem into smaller sub-problems amendable to implementation with functions.
    * _Procedural abstraction_. Take a concrete implementation in Racket and create a procedure that generalizes that behavior.
    * _Data abstraction_. Design data structures to separate interface from implementation.
* **Programming**.  **_Students can employ basic programming structures to solve problems_**.
    * _Primitive types_. Express basic computations over primitive values and their associated standard library functions.
    * _Conditionals_. Use Boolean expressions and values in a program to produce conditional behavior.
    * _Local bindings_. Refactor redundancy and add clarity in computations with let-bindings.
    * _Procedural abstraction_ [7]. Take a concrete implementation in Racket and create a procedure that generalizes that behavior.
    * _Randomness_. Write programs that produce unpredictable output.
* **Software Design**.  **_Students can design and build readable and correct programs_**.
    * _Tracing_. Trace the execution of a Racket program using a substitutive model of computation.
    * _Collaboration_. Explain best practices for solving problems in a collaborative setting.
    * _Program style_. Write and structure program code in ways that make it easier to understand.
    * _Documentation_. Document programs according to good software engineering principles.
    * _Testing_. Test programs according to good software engineering principles.
    * _Refactoring_. Identify repetitious code and factor out the common parts using local bindings or helper procedures.
* **Functional Problem Solving**.  **_Students can solve problems using core functional approaches_**.
    * _Lists_. Manipulate lists with fundamental higher-order list functions, such as _map_, _filter_, and _reduce_.
    * _Use higher-order procedures_. Use section and composition to simplify computations.
    * _Write higher-order procedures_. Write procedures that take procedures as parameters and return procedures as results.
    * _Employ side-effect-free code_.  Students can write non-trivial procedures that lack side effects and explain why that approach is useful.
* **Recursion**.  **_Students can write multiple types of recursive procedures_**.
    * _List recursion_. Design and write recursive functions over lists.
    * _Numeric recursion_. Design and write recursive functions over the natural numbers.
    * _Tree recursion_. Design and write recursive functions over trees.
    * _Tail recursion_. Transform recursive functions into tail-recursive functions.
* **ADTs and Data Structures**.  **_Students can employ structured data types in their programs_**.
    * _Lists_. Design and write functions that use lists [8].
    * _Vectors_. Design and write functions (potentially recursive functions) that use vectors.
    * _Trees_. Design and write functions that use trees or other nested data structures [10].
    * _Mental models of memory_. Describe or diagram the layout of memory for lists, pairs, and vectors/arrays.
    * _Compare and contrast data structures_.  Students can describe the relative benefits of lists and vectors.
    * _Data abstraction_. Design data structures to separate interface from implementation [11].
* **Algorithms**.  **_Students can describe fundamental sorting and searching algorithms and can analyze their efficiency using informal techniques_**.
    * _Searching_. Update or modify fundamental searching algorithms or trace the execution of those algorithms over concrete inputs.
    * _Sorting_. Update or modify fundamental sorting algorithms or trace the execution of those algorithms over concrete inputs.
    * _Running time_. Use a mental model of computation to count the relevant number of operations performed by a function.

Yeah, I think that's a good set of high-level outcomes, along with some associated lower-level outcomes.  What's left?

* **Sample topic-specific learning outcomes**.  These are optional.
    * _Regular expressions_. Read and write programs that take advantage of regular expressions.
    * _Structure textual data_. Write and use HTML, XML, and CSS.
    * _Dictionaries_. Design and write functions that use dictionaries.

Over the years, we've done a bunch of other things in CSC-151, including
many that are not specific to any particular topic.  Here are a few, just
in case folks feel like they are running low on topics.

* **Other optional learning outcomes**.
    * _Metaprogramming_.  Read and write programs that generate other programs.
    * _Objects_.  Create and use objects using a functional model.
    * _Files_.  Write information to files and read information from
      files.  Describe the benefits of files for persistence [12].
    * _Interaction_.  Write programs that provide prompts to users
      and read input from users.
    * _Images_.  Write programs that create images [14].
    * _Variable-arity procedures_.  Write procedures that can take
      variable numbers of parameters [15].
    * _Stacks_.  Implement stacks and/or write procedures that
      employ stacks and/or describe stacks and how they might
      be useful.
    * _Queues_.  Implement queues and/or write procedures that
      employ queues and/or describe queues and how they might
      be useful.  Compare and contrast stacks and queues [16].

I've probably forgotten some.  Oh well.  It's enough for today.  I
like my seven high-level topics.  At least I like them now.  I'll
see what I come up with when we meet again as a department.

---

**_Postscript_**

On the last day of class, I give students a list of things that
make up "the subject matter of the class".  Perhaps they could be
a different way to organize my thoughts on learning outcomes.  
Let's see ... What are they?

* Problem solving.  This topic has effectively morphed into "computational
  thinking".
* The core of CS: Algorithms and data structures.  Yup, both are topics
  (learning outcomes).
  Of course, some of what I expect for both is that students can design
  them, but that's in the outcomes, right?
* Functional programming.  Yup.
* Program and software design.  Yup.
* Scheme and Racket.  We've included Scheme/Racket in the smaller
  LOs, but not the high-level ones.  I think that's appropriate.  CSC-151
  doesn't have to be a Scheme course.  It's just easier to do most of
  these things in Scheme.
* General skills.  I try to help students develop skills at working
  with each other, at answering unexpected questions, at time management,
  and such.  I don't think these are necessary for all faculty to cover
  in the course.
* And beyond.  Back when I was in college, mom suggested that she wanted
  to do a research study on faculty as moral models.  Being the snarky
  son that I am, I said something like "Mom, you are certainly a moral
  model for your students.  But most faculty are not.  I can't think of
  any faculty members who have developed my moral sense."  Now that I
  teach, I've realized that faculty can (and perhaps should) be moral
  models.  That is, we model how to interact with other people; we model
  what is and is not important.  And I think we do so whether or not we
  want to.  When you extend a deadline for a struggling student, you 
  suggest that caring for the individual is more important than
  particular rules.  That's good.  But you also model a disregard for
  rules and policies.  That's (potentially) less good.  Anyway, this
  moral modeling should not be an explicit outcome of CSC-151, even
  if it happens.

---

[1] Formerly the M-word theorem.

[2] As I've said before, I make bad decisions [3].

[3] I used to say "I'm an *i-word*", but I've come to learn that
the i word has been used to institutionalize and otherwise punish
those with cognitive differences and so careful writers avoid using
it.  I wonder if I should go back and change prior musings.  Perhaps
when I have time.  

[4] At least it's a good excuse to muse [5].

[5] Students doing the rhyming assignment in 151 might want to consider
"excuse" and "muse" as an interesting pair of non-rhyming words.  Oh,
wait a minute.  "Excuse", as in "excuse me", does rhyme with "muse".
It's just the noun form that I used that doesn't rhyme.  English puzzles
me.

[6] Here's one of the things I say to my students about computational
thinking,

> In 2006, noted computer scientist Jeannette M. Wing coined the
term _computational thinking_ to describe the idea "that
everyone, not just those who major in computer science, can benefit
from thinking like a computer scientist".

I've forgotten where that quotation comes from.  I wonder if I should
write a reading on computational thinking.

[7] Yup, I've repeated procedural abstraction.  It's both a programming
technique and a computational thinking technique.

[8] Note that this LO [9] is the lists LO in a new form.

[9] Learning Outcome.

[10] Oh boy!  It's another LO that I've duplicated and changed!

[11] Another duplication, this time with no changes.

[12] Remember what I said about splitting up learning outcomes?  I
think there are at least three here.

[14] We do that in the current version of 151.  We just don't make it
one of the core learning goals.  Images help provide a platform to cover
the deeper issues.

[15] Is this a valuable learning outcome?  It's certainly a helpful
technique, but I'm not sure I'd put it at the same level as the
other things we include in the course.

[16] We cover stacks and queues in CSC-161, _Imperative Problem Solving_.
I'm not sure we need to reintroduce them to 151.
