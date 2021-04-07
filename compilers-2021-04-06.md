---
title: How should a student learn compilers and interpreters?
number: 1132
tags: [Miscellaneous](index-misc), technical
blurb: And related questions.
version: 1.0
released: 2021-04-06
current: 
---
At the end of today's session of [CSC-282: _Thinking in C and
Linux_](https://rebelsky.cs.grinnell.edu/Courses/CSC282/2021SpT2/syllabus/),
a student asked me about compilers.  They had some explicit questions:

> How do I learn about compilers?  Since there's not a compilers course
  anymore, can I do an independent study in compilers and interpreters?

I think there was also an implicit question or statement.

> Why did you cancel Compilers?  It sounds like a cool course.

I would agree that Compilers is a cool course.  The Compilers course
also plays an important role in my life; teaching Compilers at
Dartmouth got me started in my professional career.  And Grinnell
is definitely a "programming languages" department; I'm pretty sure
it's the most common area for our students to pursue in graduate
school.  The Compilers course also sits at the intersection of
theory and practice; I believe some schools that track courses give
it "theory credit" and others give it "systems credit".  We used
to give it "project course credit".  At that point, students could
take either CSC-362, _Compilers_ [1], or CSC-323, _Software Design_
[2].  Our theory was "Students should take a course in which they
work in a team to build a large software project".  Evidence suggests
that a compiler is among the largest projects students build as
undergraduates.

So, why did we do away with the Compilers course?  My memory is a
bit foggy, and I may be combining two curricular changes, but the
rationale went something like this.  

We had created a new software design course [3].  It seems like as
a department, we felt that *all* of our students needed to do more
than just work on a big project; they also had to more carefully
consider issues of teamwork and project design, from methodologies
such as agile and waterfall, through good practices guided by design
patterns, to the experience of working with nontechnical clients.
The design of the new software design course was also such that it
had to be offered at least annually---preferably, each semester---so
that students could work on multi-semester projects for our local
clients.  So we moved Compilers from meeting the "build something big"
requirement to a "Languages" requirement, which students could meet
with either Compilers or our Programming Languages course, CSC-302 [4].

"What Programming Languages course?", you may ask.  We did
away with that course, too.  Why?  Well, traditionally the Programming
Languages course teaches students the core programming paradigms:
Imperative, Functional, Object-Oriented, and Declarative (or some
subset of Declarative, such as Logic).  Since our introductory
sequence covers three of the four paradigms, it was not clear whether
we needed a traditional PL course.  And, as we considered one of
the ACM/IEEE Computing Curricula, probably Curricula 2013, but
perhaps its predecessor [5], we decided that we needed more choices
in our curriculum and that languages could be an option in the
major, rather than a requirement.  We cut Compilers and some other
four-credit courses to make room for more two-credit courses.  We
did include a course on Programming Language Implementation,
CSC-312, which I recall a colleague planning as a 2+2 course: They
would teach it as a two-credit half-semester course, and students
could enroll for a "plus two" to continue it for the second half
of the semester [6].

That course is still on the books.  But it's much more of an
"interpreters" course than a "compilers" course; the focus is less
on parsing and lexing and translation and more on thinking about
how you represent different kinds of issues.  At least I think it
is.  When we've offered it, it's drawn upon the Friedman and Wand,
_Essentials of Programming Languages_ text [7].

Unfortunately, we remain significantly understaffed for the number of
majors we have.  It's hard to find bodies to staff the two-credit
courses.  Our external reviewers have also recommended that we do
away with the two-credit courses.  I expect we'll end up with one
programming language course after everything shakes out, but it will
probably be whatever PM comes with, perhaps a hybrid PL/HCI course [8].

So, that's why we don't currently have a Compilers course.  At least I
think that's why we don't have a Compilers course. 

Let's move on to one of the more explicit questions.

> Can I do an independent study in compilers and interpreters?

Grinnell College policies do not allow students to do an independent
study in a topic that matches a regularly offered course.  Arguably,
CSC-312 is a regularly offered course, even though it hasn't been
offered in the past few years.  So one could argue that we shouldn't
offer an independent study in compilers and interpreters.

But there's another reason this student probably can't do an independent
study in compilers and interpreters: The CS faculty are fairly close to
the limits of their bandwidth; I don't think any of us have the time or
energy to supervise such an independent.  When I was chair [9], I would have
strongly discouraged my colleagues from taking on such an independent.

That leaves the last question.

> How can I learn about compilers and interpreters?

I'm not sure that I have a great answer to that.  It depends a bit
on *why* you want to learn about compilers and interpreters.  Do
you want to include a language in a project you are building?  Use
one of those plug-in Scheme interpreters [10].  Domain-specific
languages are all the rage these days.

But we'll assume that you just want to understand the underlying
ideas better.  Most of the modern research in compilers is on
optimization, which may be beyond what an undergraduate would want
to do [11].  But lexing, parsing, translation, semantics, internal
representations, and such?

You could take a MOOC.  I see that Alex Aiken runs a free one that's
offered on [Stanford Online](https://online.stanford.edu/courses/soe-ycscs1-compilers).  That appears to be a standard compilers class.

You could try to build one yourself.  I'd recommend starting with an
interpreter, perhaps even a simple Scheme interpreter.  The Friedman
and Wand _Essentials of Programming Languages_ books is likely something
that a few students could work through together.

I don't think I told the student all of that.  I just told them "Talk to
PM, or maybe Charlie."

If my readers have something else to suggest, I'm happy to pass it
along to my students.

---

[1] Was that the number?  It feels right.  _Sam checks._  Yup.  I
taught it five times between the fall of 1998 and the fall of 2011.

[2] Maybe it was CSC-223.  It's had both numbers.  We might even want
to consider moving CSC-324 back to CSC-224.

[3] By "we", I mean "Janet".  And by "Janet", I mean "my amazing
colleague, Janet Davis".

[4] I taught that one six times between the spring of 1998 and the
spring of 2011.

[5] If I recall correctly, CC 2013 added back in some PL stuff that
the prior Computing Curriculum cut.  Given the preponderance of functional
approaches in modern programming, I wonder if those earlier designers
regret cutting functional programming from the core curriculum.

[6] There are times that the members of our department are way too
enthusiastic about doing extra work in support of our student's learning.

[7] There's a different Friedman, Wand, and Haynes text, right?

[8] I also don't know what will happen with HCI.  I'm enjoying teaching
it this term, and I think it's important to have HCI somewhere in our
curriculum, but fitting it into our regular schedule will be hard.

[9] I'm calling myself "Former Chair", at least for this year.

[10] Or "plug in \[language of your choice\]" interpreters.

[11] Was the gap between the course and the current research a reason
we cut both Compilers and Programming Languages [12]?  I don't think so, but
I'm not sure.

[12] Isn't much of the current research in PL based around type theory?
