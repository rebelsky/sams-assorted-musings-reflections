---
title: Learning objectives for CSC-207 (2023Fa)
number: 1244
tags: [Teaching](index-teaching)
blurb: The task continues
version: 1.0
released: 2023-08-01
current: 
---
As I mentioned [yesterday](csc151-2023fa-learning-objectives), it's the time of the summer when I start getting my fall classes ready and I tend to start by drafting the learning objectives.  I used to start with a list of topics.  However, our assessment-centric institution has pushed me towards objectives (goals, outcomes, whatever).

Yesterday, I mused about [the learning objectives for CSC-151, _Functional Problem Solving_](csc151-2023fa-learning-objectives).  Today, it's time to look at CSC-207, _Object-Oriented Problem Solving, Data Structures, and Algorithms_.  CSC-207 is the third course in our introductory sequence, a variant of the course that has historically been called "CS2" [1,3,4].

I love CSC-207.  It's the point in their Grinnell CS career where students start delving deeply into the core ideas of software design and computer science.  They build larger, multi-file programs, using version control and a form of test-driven development.  They also build and analyze abstract data types, data structures, and algorithms [5].

As I sat down to prepare the learning objectives, I looked back at the most recent sections I've taught.  The last time I taught the course was in [the spring of 2019](https://rebelsky.cs.grinnell.edu/~rebelsky/Courses/CSC207/2019S/01/home/).  That semester, I used a draft of a textbook that a colleague was writing, as well as their homework assignments.  I was surprised to see that I had previously taught the course five years prior, in [the spring of 2014](https://rebelsky.cs.grinnell.edu/Courses/CSC207/2014F/home/).  At that time, I was using my own draft textbook.  I don't think my colleague has moved forward with their textbook, so I've decided to return to mine.  If I have time, I'm moving it to [Runestone Academy](https://landing.runestone.academy), a platform for open textbooks [6].

More importantly, I looked at a colleague's recent section.  They were using a variant of a set of learning objectives another colleague had proposed, but we'd never had time to discuss as a department [7].  Here's what they had.

**Universal Learning Outcomes**

* Create correct multi-file programs in Java 11+ to meet requirements specification.
* Collaborate with one or more other students in creation of programs and completion of labs.
* Apply object-oriented design principles to the creation of Java programs: Abstraction, Encapsulation, Inheritance and Composition, and Polymorphism —ad hoc, parametric (a.k.a. generics) and subtyping.
* Use and build core abstract data types to design solutions to programming tasks: Arrays, Lists, Maps and Sets, Stacks and Queues, Hash Tables, Heaps, and Trees.
* Use and implement core algorithms to design solutions to programming tasks: Sorting, Searching, Iteration, and Traversal.
* Analyze run-time complexity of algorithms.
* Create effective unit tests of Java programs using tools such as JUnit.
* Use Java’s Exception libraries to detect and handle run-time errors.
* Use version control software program, such as Git, to maintain multiple versions of software under development.
* Exercise good practices in code documentation and create documentation for Java programs using Javadoc.

**Other skills (Instructor-specific)**

* Debugging and Evaluation.- Experience code from a different perspective by testing, reviewing, and refining their code.
* Communication.- Demonstrate effective use of written and verbal communication by creating reports (Labs write-ups) with other peers by discussing and consensus on acquired knowledge.
* Independence and Curiosity.- Habitualize learning programming languages within the scope of individual assignments through self-driven, hands-on exploration and problem-solving practices.

It's a nice set of outcomes.  However, I'm never satisfied to leave things as they are.  In particular, I found that I wanted to separate some of the compound learning objectives into smaller objectives.  Those of you who read my prior musing shouldn't be surprised to hear that.  I also wanted to group them according to broad categories (object-oriented programming, software design, ADTs and data structures, and algorithms).

Here's what I ended up with, once I separated things, regrouped outcomes, and then added a few outcomes from my spring 2019 offering.

**Learning Assessments, Object-Oriented Programming**

* **Data abstraction**: Apply abject-oriented design principles to separate interface from implementation.
* **Encapsulation**: Apply object-oriented design principles to design and build classes.
* **Subtype polymorphism**: Write polymorphic code that works for objects in all classes that implement an interface or subclass a class.
* **Parametric polymorphism**: Write polymorphic code for structures that can work with a variety of uniformly typed objects, such as lists of X.
* **Composition**: Combine objects/classes to build new objects/classes, implementing the _has-a_ relationship.
* **Inheritance**: Build new objects/classes in terms of other objects/classes, impliementing the _is-a_ relationship.
* **Mental Models of Java Objects**: Describe the layout of objects in memory.

**Learning Assessments, Software Design**

* **Project design**: Create correct multi-file programs in Java to meet specifications.
* **Collaboration**: Work with one or more other students on the creation of a program.
* **Testing**: Write effective unit tests using a framework such as JUnit and practice test-drive development.
* **Version control**: Employ collaborative cversion control software, such as Git, to maintain multiple versions of software under development.
* **Documentation**: Exercise good practices in documenting code and create documentation for Java programs using Javadoc.
* **Professional ethics**: Understand and explain the responsibilties of a software designer.

**Learning Assessments, Data Types and Data Structures**

* **Array-based structures**: Implement one or more data types using arrays.
* **Linked structures**: Implement one or more data types using linked structures.
* **Iterators**: Design, implement, and use iterators for one or more data types.
* **Lists**: Implement and use array-based and linked lists.
* **Stacks and Queues**: Implement stacks or queues; use both.
* **Dictionaries/maps**: Design a dictionary ADT and implement it in multiple ways, such as with associative arrays, binary search trees, or hash tables.
* **Hash tables**: Implement dictionaries with hash tables using either probing or chaining.
* **Binary Search trees**: Implement dictionaries with binary search trees.
* **Heaps**: Describe heaps and how they are built.  Use heaps for Heapsort.
* **Graphs**: Describe graphs and basic algorithms on them.
    
**Learning Assessments, Algorithms**

* **Big-O notation**: Read and interpret the formal definition of Big-O.
* **Analysis of iterative algorithms**: Conduct informal big-O analysis of iterative algorithms and nested loops.
* **Analysis of recursive algorithms**: Conduct informal big-O analysis of recursive algorithms. 
* **Merge sort**: Explain, implement, and analyze variants of the merge sort algorithm.
* **Quicksort**: Explain, implement, and analyze the Quicksort algorithm.
* **Heap sort**: Explain, implement, and analyze the heap sort algorithm.
* **Graph and tree traversal**: Explain various graph traversal algorithms.
* **Loop invariants**: Describe the use of loop invariants in algorithm design.

I knew that wasn't a final set.  For example, it seemed appropriate to add my colleague's "communication" goal.  On the other hand, communication is implicit in documentation, collaboration, and version control.  There seem to be fewer natural ways to assess communication beyond the ways I'm assessing those three other issues.

So I sat down to muse about the topic.  And I realized that I had written a set of learning outcomes for the spring 2014 version.  What were those?  Let's see.

**Object-Oriented Design**

I expect that at the end of the semester, you will have mastered the basics of object-oriented design.  In particular, I expect that you will be able to

* describe and use the three pillars of object-oriented design: encapsulation, inheritance, and polymorphism; 
* identify and use a variety of basic design patterns, including Model-View-Controller, Factory, Iterator, Singleton, Adapter, and Decorator.
* identify objects that will contribute to a program or solution, design those objects, and implement those objects.

**Design and Analysis of Algorithms**

I expect that at the end of the semester, you will have significantly extended your skills in the design, implementation, and analysis of algorithms.  In particular, I expect that you will be able to

* describe and implement classic algorithms, including
  binary search, sequential search, insertion sort, selection sort, heap sort, Quicksort, and merge sort;
* design new algorithms using a variety of approaches including greed, divide and conquer, and dynamic programming;
* analyze the running time efficiency of algorithms using big-O notation; and
* use loop invariants to better design and verify iterative algorithms.

## Design and Analysis of Abstract Data Types and Data Structures 

I expect that at the end of the semester, you will have significantly extended your skills in the design, implementation, and analysis of abstract data types and algorithms.  In particular, I expect that you will be able to

* describe and distinguish between the terms "abstract data type" and "data structure";
* describe and implement classic ADTs and data structures, including expandable arrays, lists, stacks, queues, dictionaries/maps, hash tables, binary search trees, and trees;
* design new ADTs using the PUM (philosophy, uses, methods) approach; and
* design new data structures using the LIA (layout, implement, analyze) approach.

## Software Construction

I expect that at the end of the semester, you will be a competent beginning software developer.  In particular, in addition to having the skills described above, I expect that you will be able to

* design, implement, and run unit tests;
* develop software using an integrated development environment (in our case, Eclipse);
* collaborate on and keep track of the development history of code using a version control system* (in our case, Git); 
* read, understand, and modify code that you did not write;
* design and develop libraries for use in other programs;
* use libraries in your own programs; and
* responsibly incorporate code that you did not write into your own program.

## Java

I expect that at the end of the semester, you will be a competent beginning Java programmer.  In particular, I expect that you will also be able to

* write programs using the imperative core of Java;
* signal and recover from errors using Java's exceptions;
* construct simple graphical user interfaces using JavaFX; and
* describe and use a variety of special Java constructs including anonymous inner classes and "lambdas".

Hmmm ... it appears that my desire to decompose complex learning objectives is a comparatively new approach.  It almost certainly stems from my decision to use smaller learning assessments (ten-to-fifteen-minute question).  I like the introductory material.

If I recall correctly, I was treating learning objectives differently.  At the time, I was treating them as my goals for what I was helping students learn, rather than what I'd assess students on.  The assessments related to these outcomes, but did not address them explicitly.

---

[1] It was called CS2 because it had that label in one of the first ACM/IEEE Computing Curricula.  The only other number I remember from that report was CS7, the upper-level algorithms course, which many people call "a CLRS-style class" these days [2].

[2] CLRS is "Cormen, Leiserson, Rivest, and Stein", the authors of one of the most popular books on algorithms.

[3] These days, some people call it CS3.  I don't like that name, since it's not a common usage.  CS3 has also been used to mean "baby software design", among other things.  I can't believe that some major conferences have accepted papers that refer to Data Structures and Algorithms as CS3.

[4] We've added object-oriented programming principles to the traditional CS2 dagta structures and algorithms.

[5] Building and analyzing algorithms, data structures, and ADTs represent the core of computer science, at least in my world.

[6] Stay tuned for my musings about my attempts.

[7] We tried this summer, but didn't get as far as I would have liked.
