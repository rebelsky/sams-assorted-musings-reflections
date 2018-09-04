An introduction for the new "digital humanities" CSC 151, take zero
===================================================================

*Topics/tags: [CSC151](index-151), Racket, digital humanities*

Now that my SIGCSE submissions are done, it's time to buckle down and work
on my primary focus for the fall, the new digital humanities version of
CSC 151.  I've decided to start by writing a draft introduction to the
readings and labs.  As I've said before, I realize that the introduction
is supposed to come last.  However, I find that writing an introduction
helps me ground my thinking and gives me a broad roadmap for what I plan
to do.

Trying and failing to write parts of the introduction will also
help me figure out what else I need to reflect on; for example, I'm finding
that I need to do some more background reading on "the humanities" [1]
and that I clearly need to expand my scope of understanding about the
digital humanities.

In any case, I'm going to write the introduction now to ground my
thinking.  I expect to come back and revise it multiple times: after I've
outlined the course, after I've done more reading about the humanities
and the digital humanities, before I need to present it to the other
Obermann fellows at our bi-weekly seminar [2], after I've reread _Style_
and want to think about my style, and after I've written the rest of
the primary material.

---

Welcome to a Functional Approach to the Digital Humanities, or *FunDHum*
[3,4].  FunDHum provides a "workshop style" introduction to computer
science grounded in examples from the digital humanities and employing a
functional programming approach using the Racket programming language.
What does that all mean?  Let's unpack each term.

*Computer Science*.
Although you will find that computer scientists don't always agree on
all the details, most agree that the core of computer science is the
study of algorithms and data structures.  That is, computer scientists
think about the instructions and processes one might write or use to
accomplish a task and ways to organize information to support those
instructions and processes.  In many ways, computer science is the study
of problem solving in formal domains; we consider how to make explicit
the requirements of a problem, to develop a solution in a formal language
(most typically a programming language), and to analyze that solution
for both correctness and efficient use of resources.  Whether or not you
continue your study of computer science, I hope that FunDHum will help you
think you think more carefully about solving problems.

You will develop your skills in algorithmic thinking in a variety of ways,
but most frequently by writing and exploring computer programs in which
you represent the algorithms and data structures that you have created.
Since you will be writing programs, we will also consider some issues
of software design, including ways to write programs to make them more
readable and maintainable by other humans and the use of both experimental
testing and formal reasoning to help ensure that the programs you
write meet their goals.  Since you are writing in a language, albeit an
artificial language, we will also explore issues of style and elegance.

To some, "computer programming" is the same as "computer science".  While
programming can be part of the work of a computer scientist, it is often
only a small part of that work.  Some computer scientists study the limits
of computing, what is and is not computable.  Many explore the design of
algorithms and data structures for particular domains, from the details
of how to implement algorithms in physical circuitry to the abstract
questions of how to represent intelligence.  Some consider the implications
of computing: Computing allows us to accomplish many tasks that previously
seemed impossible, such as gathering and analyzing the purchasing or
viewing habits of large segments of society; we have a responsibility to
think through the implications of such abilities and, when possible to
find ways to avoid broader harm.

*Digital Humanities*.
Although one can develop skills in algorithmic thinking by exploring
algorithms abstractly, we will find it much more useful to focus on
a particular problem domain.  In FunDHum, that problem domain is the
relatively new field of Digital Humanities.  But what are the Digital
Humanities [5]?  Perhaps we should start by considering the Humanities
themselves.  From my perspective, humanists study the works of humanity,
including language, philosophy, religion, and art.  Scientists may
also study these areas.  However, humanists and scientists approach
them differently.  While scientists tend to employ the scientific or
experimental method, humanists often attend more to the particular
details or broader contexts of individual works, frequently guided by
an underlying theory or framework [6].

What about the digital humanities?  Because the field is evolving,
no one consistent definition has appeared.  That's almost certainly a
good thing, definitions can limit possibilities and it is important that
the field have room to grow.  At the same time, some limits are useful.
For the sake of FunDHum, we will consider the aspects of the digital
humanities that relate to the ways in which algorithmic thinking and
digital tools can contribute to humanistic work.  And I use the term
"contribute" carefully; as a computer scientist, I know that computers
cannot replace the careful thought and analysis the undergirds humanistic
study.  However, these technologies can reveal new topics and modes of
inquiry and provide new modalities for presenting results.

Let's consider a few examples.

An early form of digital humanities involved using computers to find
patterns in medium or large corpora, such as the works of Shakespeare
or a digitized collection of 18th century British novels.  This form of
analysis is often termed "distant reading" to contrast it with the close
reading that is core to many forms of humanistic study [11].  It also
suggests the potential benefits of stepping back and looking at a larger
group of works [12].  While distant reading incorporates a wide variety
of practices, one of the more popular is that of "topic modeling", the
use of computers to find groups of words that tend to appear together
[14].  Of course, the topics themselves are not the end result.  Rather,
discovering an unusual grouping of words may lead the scholar to a set
of readings which she can then explore more closely through traditional
techniques.  She may find the group of words useful; she may find the
unexpected connections between works useful.  She may conclude that the
connections appear to be specious.

"Place" plays a large role in many works and humanists are increasingly
finding that mapping tools can provide a useful mechanism for both
exploring and explaining the role of place.  Mapping place names in, say,
Hamlet, may suggest that although the primary action takes place in one
location or set of locations, other places play enough of a role in the
play that they influence the action [15].  Mapping tools need not be
applied only to traditional literary texts.  I know, for example, of an
informative project involving place names in the songs of Kendrick Lamar
[16].  In many such situations, the maps may lead the scholar to closer
analysis of the text or texts.  At the same time, the maps themselves
can serve as a kind of product of scholarly inquiry, providing evidence
for a broader argument about the role of place.

In some cases, maps can also be the primary result of humanistic inquiry.
Consider, for example, the experience of immigrants in American in the
21st century.  TO DO

*Workshop-style learning* [17].
We have established that FunDHum introduces computer science through
problems and approaches drawn from the digital humanities.  But how
should one teach and learn these materials?  Computer science has
traditionally been taught in much the same way that the natural sciences
are traditionally taught, through lecture and associated lab.  However, it
is clear that most students learn computer science better by doing rather
than by listening.  Hence, FunDHum is designed to support a so-called
"workshop style" approach.  For each class period, students will read
a few pages that provide some background information [18].  Class time
is then devoted to students working in pairs on a series of problems.

Why pairs?  Because research suggests that programmers work better in
pairs, in both the classroom and in regular practice.  How much better?
Studies suggest that two people working together are regularly more
productive than two people working separately [19].  It's not just that
"two heads are better than one"; we also know that having to describe a
thought process to someone else improves that thought process and helps
find flaws.

If you're reading through FunDHum on your own, I would suggest that you
follow a similar approach.  You won't learn this material by just reading,
so make sure that you work through the various problems.  You may even
want to design some on your own.  And, if you're fortunate enough to have
a friend who might be interested in these topics, try to work as a pair.

*Functional programming in the Racket Programming Language*.  As noted
above, you will learn methods of algorithmic thinking, in part, by writing
programs that represent your algorithms and data structures in a formal
language, one that computers can understand.  We call such languages
"programming languages".  Although Python, PHP, and R are the most
popular programming languages for the digital humanities, we'll be
using the Racket programming language [20].

Why Racket?  There are a number of reasons.  Like Python, Racket was
designed for both novice and experienced programmers.  Its syntax is
straightforward and simple, although filled with parentheses [21].
It comes with an affiliated program development environment, DrRacket,
that is particularly supportive of new programmers.  DrRacket makes it
easy to develop, to experiment, and to debug.  As importantly, Racket
encourages particular approaches to algorithm and program design; I think
that emphasizing those approaches will make you a better algorithmic
thinker and programmer.  Among other things, Racket supports a model
of programming called "functional programming" which is characterized
by an emphasis both on functions as basic values and on writing procedures
that do not affect the state of the system.  Functional approaches are
at the heart of many modern programming languages and I've found it
important to begin with them early.

**Particular emphases**

The digital humanities are broad.  We could not hope to cover all the 
approaches and algorithms from the digital humanities in a year, let
alone in a single semester.  That's okay; my goal is not to teach you
everything.  Rather, I hope to expose you to enough algorithmic concepts
and ways of thinking about humanistic "data" that you can learn new 
things and, as importantly, design your own algorithms.

In FunDHum, we will emphasize three core aspects of the digital humanities:
data representation, authoring of non-traditional texts, and, most
centrally, algorithms for analyzing and manipulating text.
.
*Representation*.  One of the broad problems in the digital humanities
is how to represent data electronically to support a broad variety
of algorithms.  Consider, for example, the markup appropriate for an
electronic version of a book.  It's clear that we want to provide the
textual content of the book.  But an algorithm should be able to easily
access the "parts" of that book, not just chapters, but also section
headings, authors, and so on and so forth.  Scholars of the book might
care about the details of the layout, including the positions of line
and page breaks or the typeface choices throughout the book.  And,
while a book may exist in the abstract, we may also want to encode the
information associated with a particular printed instance of the book,
including the marginalia and the ownership history, if available.

While we will not be able to cover the full range of issues that digital
humanists face, we will explore a variety of such issues and practice
developing our own schemas for representing information.  Along the way,
we will explore common formats for representing and annotating textual
data, focusing primarily on "markup languages" [23] like HTML and XML
and simple file formats for storing additional information.

*Authoring*.  Your daily experience with the Web tells you that computers
have changed the ways in which people write, from the abbreviated text of
Twitter and SMS messages to the multiply linked documents of Wikipedia
and the World Wide Web.  We will explore various techniques for building
"algorithmically supported" documents, documents that draw some of their
content from algorithms, such as algorithms that analyze or reframe
other documents.

*Textual analysis*.  Algorithms are core to the study of computer science.
Hence, the design of algorithms that we can use to analyze and manipulate
texts form the central core of the course.  These algorithms will,
of course, rely on the ways in which we choose to represent data.
And they can be used in service of the documents we author.  We will
consider seemingly straightforward issues of textual analysis, such
as word frequencies, as well as the complexities they raise, such as
identifying words with similar stems.  We will also explore more complex
algorithms, including the basic aspects of topic modeling.

**Context**

It would be irresponsible of us as computer scientists and humanists if
we did not consider the broader context of the work we do.  At times, we
will consider the implications and potential pitfalls of the algorithms
we write and data we represent.

It is clear to most people that computer technology is changing the
world.  Unfortunately, the people who develop computer technology do not
necessarily represent a full breadth of perspectives; fewer than 20% of
computing professionals self-identify as women and even fewer identify
as people of color.  Since technology often reflects the perspectives,
this lack of diversity is troubling, not just because it means that many
kinds of technology better support or prioritize certain groups, but also
because of missed opportunities for other approaches and techniques [23].

One of the kinds of difference that many often miss is that of difference
in ability.  As developers find themselves excited by new technologies
and new opportunities, they forget to consider how others might encounter
those technologies, particularly those who have limited sight, limited
hearing, or limited movement.  The digital humanities also find themselves
hampered by the lure of new technologies; far too many digital humanities
projects are inaccessible to the differently abled, whether they represent
highly visual interfaces that cannot be used by the visually impaired,
or archives of auditory materials that lack transcripts, or complex
user interfaces.  Whenever possible, we will ask ourselves whether the
approaches we are using are broadly accessible and, if they are not, we
will consider ways in which we could make them more accessible.

**Looking ahead**

There you have it.  FunDHum introduces algorithmic thinking through 
three core approaches to the digital humanities: data representation,
algorithmic texts, and textual analysis.  In the lessons to come, you
will explore the fundamentals of algorithm design, develop your own
algorithms, and enhance both your problem-solving skills and your
ability to represent things precisely.

Let's get started.

---

Postscript: Why did I call this "version zero", rather than "version one"?
Because I wanted to clarify just how rough I intended the draft to be.
And yes, I know that it's very rough.

---

Postscript: I'm pretty sure I had a note somewhere here that I wanted to
include some form of sentiment analysis in the course.  But that note
seems to have disappeared.  I've added this postscript to remind myself.

---

[1] A subject always interesting to define.

[2] That's in four or so weeks.

[3] If you want to read that as "Fund the Humanities" for "Fun with the
Digital Humanities", that's fine with me.

[4] Or should that be FunDhum?  Like the final version of the
introduction, the final name for the work and the final acronym will
come in the future.

[5] And should they be capitalized?

[6] After writing that paragraph, I did a quick Web search to see what
others have written [7].  I see that the Stanford Humanities Institute
writes

> The humanities can be described as the study of how people process and document the human experience. Since humans have been able, we have used philosophy, literature, religion, art, music, history and language to understand and record our world. These modes of expression have become some of the subjects that traditionally fall under the humanities umbrella. Knowledge of these records of human experience gives us the opportunity to feel a sense of connection to those who have come before us, as well as to our contemporaries. [8]

But it may also be useful for me to reflect on [their page about research
in the humanities](http://shc.stanford.edu/how-humanities-research-conducted).
While I don't find the opening promising [9], a few paragraphs in the middle
seem particularly pertinent.

> A hallmark of humanistic study is that research is approached differently than in the natural and social sciences, where data and hard evidence are required to draw conclusions. Because the human experience cannot be adequately captured by facts and figures alone, humanities research employs methods that are historical, interpretive and analytical in nature.

> Professors who engage in humanities research are often posing questions about common assumptions, uncovering new meanings in artistic works, or finding new ways to understand cultural interactions. This type of inquiry can produce clearer pictures of the past, uncover the many insights that we can draw from our forbears, and in turn, help us better to prepare for the future. [10]

[7] I plan a more substantial search at a future date.

[8] <http://shc.stanford.edu/what-are-the-humanities>

[9] "Humanities research often involves an individual professor researching in a library in order to write a book."

[10] <http://shc.stanford.edu/how-humanities-research-conducted>.

[11] Bode's "The Equivalence of 'Close' and 'Distant' Reading; or, Toward
a New Object for Data-Rich Literary History" is on my reading list for
this project.

[12] There's a potential to insert something about "not being able to see
the forest for the trees", or vice versa.  Or would that be insulting?
I'll have to think about that in the next draft.

[14] Should I find a way to incorporate Firth's "You shall know a word
by the company it keeps"?  Perhaps in the assignment that guides students
through a simplified version of topic modeling.

[15] I know I heard this example somewhere.  I wonder if I can find the
source.  Unfortunately, searching for "map" and "hamlet" doesn't work
well, because a "hamlet" is also type of place.

[16] I wonder if Mark has written anything about that project?  I should
check.

[17] Do I want to include a description of workshop-style teaching here?
I think I do.  It's part of the design of the materials.

[18] Should I record videos, too?  I'm not sure.  I don't particularly
like videos.  I don't know that I have time.  But I do understand that
many students find them useful.

[19] Do I need to dig out those studies?  Probably.  If I recall correctly,
Laurie White was involved in some in the SIGCSE literature.  Once again,
finding the particulars is a task for subsequent draft.

[20] Racket *should* be one of the more popular programming languages
for the digital humanities.  I doubt my course and the accompanying
textbook will make a difference, but I can hope.

[21] Should I claim that humanists should appreciate the implied
parenthetical remarks?  Probably not.

[22] Do I want to explain the difference between markup languages and
programming languages?  No here.  Maybe when I introduce them.

[23] When I started writing the introduction, I had a clear view of
how I was going to fit the diversity paragraph into the introduction.
I've forgotten it now.  But I have difficulty writing anything major
that does not reflect in some way on issues of broadening participation
in computing.

---

*Version 0.5 of 2018-09-04.*
