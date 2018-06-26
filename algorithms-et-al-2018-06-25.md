Algorithms, data structures, abstract data types, formal languages, and the rest
================================================================================

*Topics/tags: [Teaching](index-teaching), curriculum, computer science, bulleted, rambly*

Tomorrow, the department will have a conversation about the topics and
relationship of our core "algorithms and theory" courses.  Like most
CS departments [1], we have three such courses: an early course in data
structures, algorithms, and abstract data types that was traditionally
called CS2, that was CSC 152 when I started at Grinnell, and is now CSC
207; an upper-level course in algorithms and algorithm analysis
that is traditionally referred to as CS7 [2] and that we call CSC 301;
and an upper-level course in theory that I think was traditionally
referred to as CS16 and that we call CSC 341: Automata, Formal Languages,
and Computational Complexity [3].  

While each course shows many similarities to the "traditional" content
for that type of course, Grinnell does some things differently.
For example, as the title suggests, we normally put computational
complexity (e.g., NP completeness) in the theory course rather than
in the advanced algorithms course.  We've also been including loop
invariants and some formal methods at various parts of the curriculum.
The courses are also different at Grinnell than at some other places
because of our multi-lingual/multi-paradigm curriculum; teaching the
data structures course with a new language is different than teaching
it in a language they learned in the prior course.  And, as I think
I've mentioned previously, the Dean's office now expects us to put
"preparation for research" in more of our courses.

Since we have some new people teaching almost all of these courses, it's 
clearly time to take a step back and look at what we expect to cover in
each course.  In preparation for the meeting, I'm doing my best to make
a list of the core topics I expect to see in these courses and which course
I expect to see them in.  I've taught CSC 152 and CSC 207 about a dozen
times, most recently in 2014, and I've taught CSC 301 twice, most recently
in Fall 2017.  I've never taught our Theory course and I never plan to.
So I'll focus more on topics that go in the first two courses.  Note also
that this is primarily my opinion; I expect that we'll have some interesting
discussions tomorrow.

Both CSC 207 and CSC 301 are about abstract data types, data structures,
algorithm design, and algorithm analysis.  Both also introduce students
to core elements of the "literature" of computer science, the data
structures and algorithms that everyone should know how to implement.
CSC 207 provides the basics and CSC 301 expands upon those basics.

Let's see ... here's my quick summary of topics I expect to see covered
in the three courses.  I've probably missed some, but this serves as
a reasonable starting point.  If I were more responsible, I'd check
Curriculum 2013 and our response to Curriculum 2013 to see what we claim
we're actually teaching.  Note that I believe that a student does not
understand a data structure until they build it (or discuss how they
would build it); using Java's implementation of, say, hash tables or
array lists, doesn't count.

**Core ADTs** [4]

* Lists, stacks, and queues: CSC 207 [5].  I admit that I also have a
  non-traditional view of lists that I should probably write more about
  sometime [6].  I'm not sure whether or not I'll bring that up in the
  discussion.
* Priority queues: CSC 207.
* Dictionaries or Maps or Tables: CSC 207.  Our field is horrible on
  standard terminology so we have three terms for essentially the same
  concept: I think of all three of these ADTs as being
  structures that store key/value pairs (or input/out pairs) and that
  let you look up a value based on its key.
* Trees: CSC 207.
* Graphs: CSC 207.
* Sets: CSC 301, potentially introduced in CSC 301.

**Core data structures**

* Linked linear structures, including doubly-linked and circularly
  linked implementations of linear structures: CSC 207.
* Array-based linear structures: CSC 207.
* Binary trees: CSC 207.
* Binary search trees: CSC 207.
* Balanced binary search trees: CSC 301.  Students should see at least
  one tree balancing mechanism.  I don't know that it's important whether
  it's AVL trees, red-black trees, or 2-3 trees.  Red-black trees didn't
  exist when I took algorithms and some of the rotations are hard, but they
  do seem to be the standard.
* Hash tables: CSC 207.  Students should see both chained and probed
  implementations of hash tables.
* Heaps: CSC 207.  Students may consider heaps in the context of priority
  queues but should certainly see them in the context of heap sort.
* Graphs: CSC 207.  Students should see at least two implementations of
  graphs.  (I usually cover at least three: adjacency matrices, adjacency
  lists, and edge lists.)
* Tries: CSC ???.  I'm not sure that we regularly cover tries in any
  course, but we should.
* Union-find structures: CSC 301.

**Algorithm design techniques**

* Divide and conquer: CSC 207, revisit in CSC 301.
* Greed: CSC 207, revisit in CSC 301.
* Dynamic programming: CSC 301.
* Approximation algorithms: Optional; we've covered those in some sections
  of 207, 301, and 341.  As the classes are feeling increasingly packed,
  I don't worry too much about overlap.
* Parallel and distributed algorithms: CSC 211 or CSC 213.  Perhaps additional
  coverage in CSC 301.
* _Um, I think I'm forgetting some.  Oh well, those are the most important
  ones._

**Algorithm analysis**

* Big-O, informal: CSC 207.
* "Counting" analysis of iterative algorithms: CSC 207.
* Big-O, formal definition: CSC 207, revisit in CSC 301.
* Big-O proofs: CSC 301.  By "proofs", I mean showing some of the expected
  properties of Big-O, such as "if f is in O(g) and g is in O(h), then
  f is in O(h)."
* Informal analysis of recursive algorithms: CSC 207.
* Techniques for solving recurrence relations: CSC 301.  I generally 
  prefer that students learn three techniques: "top-down" expansion,
  "bottom-up" development, and recursion trees.  Students seem
  to prefer different approaches, so we should give them the option to
  find the one that is most natural or intuitive to them.
* The master theorem: CSC 301.  Students should see the master theorem.
  I'm not sure that it's worthwhile having them prove it or understand
  the proof.  That will certainly be something we discuss.
* Other related sets, such as big Omega, little o, and Theta: CSC 301.
* More detailed analysis of hash tables [7]: Optional for CSC 301.

**Standard algorithms**

* Linear and binary search: CSC 207.  We've covered them in CSC 151, but
  students should revisit them.
* O(n*n) sorting algorithm (insertion and selection): CSC 207.  Students
  have discussed both in CSC 151.
* Merge sort: CSC 207.  Formal analysis in CSC 301.  Students have also
  seen merge sort in CSC 151.
* Quiksort [8]: Hand-waving analysis in CSC 207.  Probabilistic analysis 
  of Quicksort optional in CSC 301.
* Heap sort: CSC 207.
* Radix sort: I'm not sure.  It needs to go somewhere.
* Bucket sort: I'm not sure.  It needs to go somewhere.
* Dijkstra's shortest path: CSC 207.  One of the graph topics we
  moved to CSC 207 last year.
* Tree (and graph) traversal: CSC 207.  It looks like the current curriculum
  has in-order and preorder but does not mention breadth-first or depth-first.
  We'll need to discuss that some more.
* String matching: CSC 301.
* Approximate string matching: CSC 301.
* Some variant of knapsack: CSC 301.
* Minimum spanning tree (Prim and Kruskal): CSC 301.
* Network flow algorithms: CSC 301.
* A bunch of other algorithms I forget: CSC 301.

**Other algorithm issues**

* Characteristics of sorting algorithms, such as stability: CSC 207.
* P and NP: Introduce in CSC 301, formalize in CSC 341.  I don't feel
  strongly about this issue, but it's been our past practice and I worry
  about adding too much to CSC 301.
* NP Reductions: CSC 341.  It looks like we didn't do a lot of those 
  in recent years; it may be valuable to do more.
* Loop invariants: CSC 207.  I expect that we'll debate this one a bit.
  Last summer, we agreed to move program verification out of CSC 207
  and into CSC 301 to make room for more coverage of graphs in CSC 207,
  but I think of loop invariants as an important design technique that
  students should see CSC 207.
* Program verification: CSC 301.  As I just noted, we recently agreed
  to put program verification in CSC 301.  It's had a variety of places
  in our curriculum, including what used to be our third course, our
  languages course, and, um, somewhere else.
* Proofs of algorithm correctness: CSC 301, with some hand-waving proofs
  in CSC 207.
* Lower bounds on sorting algorithms: CSC 301.  A proof that
  comparison based algorithms require at least nlogn steps.
* "Read the literature": CSC ???.  Students should have the experience
  of reading an algorithm or data structure from something a non-textbook
  source and then implementing the algorithm or data structure.  I tend
  to like Skip Lists (randomized data structures make a nice pairing to
  randomized algorithms) or timsort [10] (students benefit from seeing the
  optimizations that people make in practices) [11].

**Program development and design**

_Program development stuff generally gets covered in CSC 207.  I'm just
listing these for completeness._

* Git: CSC 207.
* Unit testing: CSC 207.
* Encapsulation, polymorphism (subtype and parameter), and inheritance: 
  CSC 207.
* Broader OOP issues: CSC 324.  We used to do more OOP in CSC 207,
  but it seems that most of us have accepted that there's not enough
  room for it in CSC 207 and we've increased the coverage in our software
  design courses.

**Models of computation**

_I don't think most of the CSC 341 material will be up to debate.  The
only big question is how much coverage of NP completeness there is in 
each of CSC 301 and CSC 341._

* Finite automata: CSC 341.
* Pushdown automata: CSC 341.
* Turing machines: CSC 341.
* Lambda calculus: CSC 341.  (Optional?)

**Grammars and languages**

* Regular expressions: CSC 341.
* Context-free grammars: CSC 341.
* Decidable and undecidable languages: CSC 341.

**Other important theory topics**

* Church-Turing Thesis: CSC 341.
* Halting Problem: CSC 341.
* Cryptography: Optional for CSC 341.  I wouldn't normally list cryptography
  here, but I see that my colleagues have covered it in recent years.

**Other issues**

We probably won't discuss them, but there are a variety of other topics that
we should eventually consider for CSC 207.  We've been using Java for as long
as we've had the course.  It's good to have a language designed for programming
in the large that is relatively nannyish about types [12].  But a host of
other languages have come into play since we started using Java.  Part of
me wonders whether we should switch to C# [14].  

There's also the question of what Java features to use.  For example,
I am much more fond of anonymous inner classes than my colleagues;
before lambdas got added to Java, I used them for things like Iterators.
The last time I taught the class, I used lambdas for that purpose.
But I don't think my colleagues do.  Should lambdas be permitted?  Required?
Expected?

I also know that I have to look at all of the new features that have
been added to Java [15], such as what appears to be a REPL [16] added
in Java 9 and [a tracing mechanism](http://openjdk.java.net/jeps/328)
on track to be added in Java 11.  
However, Java's new features are a subject for another musing.

**Wrapping up**

I've mused too long on these topics.  I know that I've missed a bunch
of things.  But I've thought about enough that I'm ready for tomorrow's
conversation.  Will I report back?  I'm not sure.  Perhaps at the time
that I prepare to teach CSC 207 in the spring.

---

[1] Or at least most liberal arts CS departments.

[2] At least I think it is traditionally referred to as CS7.  My quick
Web search suggests that Curriculum 1978 calls CS7 "Data Structures and
Algorithm Analysis"; I tend to put data structures in CS2.

[3] I see that Curriculum 78 refers to CS 16 as "Automata, Languages,
Computability".

[4] ADT: Abstract data type.

[5] Students have also discussed all three in CSC 161 and have discussed
lists in CSC 151.

[6] What's a list in the ADT sense?  I think of list as an iterable collection
in which the client manually controls the order of iteration when they build
and mutate the collection.  I *hate* that the Java designers decided that
lists should also be indexed.

[7] I find it useful to do an analysis of hash tables that assume a random
distribution of data and a good hash function.  There are certainly hash
functions that are clearly problematic, such as "sum the ASCII values
of the characters in the string", which creates nice little bell curves
around multiples of the ASCII values for `'m'` and `'n'`.

[8] Hoare called it either Quicksort or quicksort (the capitalization
standards make it hard to tell; it appears as "QUICKSORT" in the title, as
"Quicksort" at the start of a sentence, and as "quicksort" in the code)
[9].  One should not call it QuickSort or Quiksort or Quick sort or
Qwiksort or any of the other abominations that appear.

[9] C. A. R. Hoare. 1961. Algorithm 64: Quicksort. _Commun. ACM_ 4, 7 (July 1961), 321. DOI=<http://dx.doi.org/10.1145/366622.366644>

[10] In his [description of timsort](https://hg.python.org/cpython/file/1589203ff116/Objects/listsort.txt), Tim Peters writes,

> This describes an adaptive, stable, natural mergesort, modestly called
timsort (hey, I earned it <wink>).

So I'm going to call it timsort.  I realize that most people refer to
it as "TimSort" and that [Wikipedia](https://en.wikipedia.org/wiki/Timsort) 
calls it "Timsort".  I'd rather follow the original author's naming
convention.

[11] Yes, I know that [some versions of timsort are broken](http://www.envisage-project.eu/proving-android-java-and-python-sorting-algorithm-is-broken-and-how-to-fix-it/).

[12] The other languages students generally learn in our curriculum are
basic Scheme, C, and Ruby.  Java provides a useful contrast.

[14] As I've noted in the past, I'd like to call that "C pound" but
Microsoft seems to want to call it "C sharp", even though it's not really
a sharp sign.

[15] The last time I taught CSC 207, Java 8 was relatively new.  I'm somewhat
scared to see that Java 11 is on track to be released this fall, which means
that I should at least consider Java 11 for my spring CSC 207 classes.

[16] REPL stands for "Read-Eval-Print Loop".  REPLs provide a more interactive
way to play with code.

---

*Version 1.0 released 2018-06-25.*

*Version 1.0.1 of 2018-06-26.*
