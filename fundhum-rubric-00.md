A grading rubric for one version of the FunDHum project
=======================================================

*Topics/tags: [CSC 151](index-151), teaching, digital humanities*

Years ago, when Janet Davis, Matt Kluber, and I were designing the
then-new MediaScheme version of CSC 151, we created a project that I
called "A procedure is worth 1000 pictures" [1].  That project asked
students to work in groups on procedures that produced an "interesting"
series of images, with the added complexity that they had to handle
issues of scaling and changing aspect ratios.  We asked for an artist's
statement so that they had to make clear what concepts they intended
to explore in their computational work.

That project was a successful part of the course.  But it was hard to
grade.  What makes a project strong?  What makes a project weak?  So
after a few years of offering the project, Janet Davis and Jerod Weinman
put together a thorough rubric for grading projects and we used it for
the remaining years in which we offered that version of 151.

What is a rubric?  It's a set of standards that you use when grading
something.  Most typically, a rubric identifies a variety of components
that you expect to see in the work (e.g., the thesis and argument in a
research paper or the code quality, efficiency, and documentation in a
programming assignment) and assigns a value to each.  More sophisticated
rubrics, like the one Janet and Jerod designed, provide additional
information on the scale used for each component.

When Sarah Dahlby Albright, Titus Klinge, and I designed the new data
science version of 151, we needed to come up with a new form of project.
Our first stab at it, "find a data set and do something with it", was a
bit open-ended, which meant that a rubric would also help us grade that.
I sketched some notes, and Titus turned them into a full-fledged rubric.

Now that I'm working on a new project description of the digital
humanities version of 151, it's time to develop a new rubric.
And, since I was presenting on the project at the Obermann seminar
[2], it seemed appropriate to design a rubric for that project,
too.  I have two different potential project structures.  Given my
limited time, I worked on a rubric for [the more open-ended project
structure](fundhum-project-00).

I admit that I have mixed feelings about grading rubrics.  I appreciate
that they can signal to students what is and is not important in a
project.  It's one thing to say "I expect you to include documentation
in your program"; it's another to say "documentation is worth ten points
of your final score".  In many ways, detailed rubrics can help avoid
bias in grading.

But Rubrics feel artificial to me.  It's partially that I don't find
always find that the whole is equal to the sum of the parts.  At times,
a missing part suggests to me that the whole is unacceptable: A paper
without a compelling thesis is pointless no matter how good the writing
and argument are; a program that passes its unit tests but leaks memory
has no value.  At times, it seems unfair to expect excellence in all parts
for overall excellence; A paper with a particularly novel or informative
point of view might be worth an A, even if the writing is only adequate.
And then there's the issue of what to do when something is just plain
wrong.  What happens when a student misinterprets a source and that
misinterpretation is the core of their argument?  Okay, for situations
like that, I'm not sure having a rubric is any worse than not having a
rubric; the natural solution is probably to request a rewrite.  

There are, of course, ways to handle each of these situations if one
can predict them in advance.  You can require certain components and
give a zero on the whole assignment if they are missing.  You can write
formulae that assign more credit for whatever students do best.  But,
in the end, all of this feels much to mechanistic to me; I prefer a
holistic approach to most of the work I encounter.

And there are those frustrations that come from rubric-based grading;
a submission that makes you go "wow!" that nonetheless gets a low grade
because the students missed something, a submission that checks off
all of the boxes, and so gets a high grade, but does nothing other than
check off those boxes.  Those cases crop up much too often.

Unfortunately, I don't have a better solution.  And so, for the major
project in CSC 151, I will have a project rubric.  Here's a draft of
a possible rubric.  At least it gives me a starting point.

```
NAME: 

PROJECT THEME: 

PROJECT PROPOSAL (25 points total)
----------------------------------

PROPOSAL FORM (5 points): The proposal has the appropriate form.

[ ] 5 The proposal includes all of the required components: a heading 
      (with authors) and title, a short description of the project
      goals, a description of the materials, and a description of the
      algorithm or algorithms.

[ ] 4 The proposal is missing one component.
      
[ ] 2 The proposal is missing two or more components.

Comments:

PROPOSAL WRITING (5 points): The proposal uses correct spelling, grammar,
and style.

[ ] 5 The proposal not only uses correct spelling and grammar, but also
      demonstrates particular facility with language.

[ ] 4 The proposal uses correct spelling and grammar, with at most
      two or three errors.

[ ] 2 The proposal does not use correct spelling and grammar.

Comments:

PROPOSAL PROJECT STATEMENT (5 points): The project statment is
complete and accurate and reveals an understanding of the purposes
and processes of the digital humanities.

[ ] 5 The project statement clearly describes the goals of the project 
      in a form in language appropriate for a general audience,
      demonstrates a deep understanding of the digital humanities,
      and suggests a project that is likely to provide compelling
      results.

[ ] 4 The project statement fails to completely achieve one of 
      the primary goals (e.g., shows a less than comprehensive view
      of the digital humanities, fails to address the appropriate
      audience, or fails to motivate the project).

[ ] 3 The project statement fails to completely achieve two of
      the primary goals.

[ ] 2 The project statement fails to completely achieve three or
      more primary goals.

[ ] 0 No project statement.

Comments:

PROPOSAL MATERIALS STATEMENT (5 points): The proposal describes the
source of the materials (that is, where you obtained them), the
subject or content, the form (e.g., is it plain text, XML files,
numeric data, images?), and the scope of the materials (i.e., how
much material is there?).

[ ] 5 The materials statement clearly indicates the source, the subject or
      content, the form, and the scope.

[ ] 4 The materials statement indicates the source, form, content, and
      scope, but leaves some minor questions about the content,
      form, or scope.

[ ] 3 The data description clearly indicates the source of the materials, 
      but leaves questions about the form or scope of the data.

[ ] 0 The data description does not indicate the source of the materials.

Comments:

PROPOSAL ANALYSIS PLAN (5 points): The proposal analysis plan is
complete and accurate.

[ ] 5 The proposal includes a description of each algorithm to be implemented
       as well as an outline of how they will be implemented and used.

[ ] 4 The proposal accurately describes the algorithms but leaves a question 
      or two remaining about how they will be implemented or used.

[ ] 3 The proposal has some minor inaccuracies or raises several
      questions regarding the algorithms to be implemented or used.

[ ] 2 The proposal is significantly incomplete and/or inaccurate in its
      description of the algorithms to be implemented or used.

Comments:

PROJECT (40 points total)
-------------------------

FILES (5 points): The submission includes all required files.

[ ] 5 The submission includes a Racket file, a copy of the materials to be
      analyzed, and instructions for using the the code with the materials.
      The instructions work.

[ ] 4 The submission includes all three components but a little additional
      work is necessary in order to use the algorithm with the materials.

[ ] 2 The submission includes all three components but significant additional
      work is necessary in order to use the algorithm with the materials.

[ ] 0 Missing one of the three components.

Comments:

ALGORITHMIC TECHNIQUES (15 points): The project uses a novel algorithmic
technique.

[ ] 15 The algorithms implemented are non-trivial and use many new techniques 
       and/or combine techniques in a novel way.

[ ] 12 The algorithms implemented are non-trivial but most techniques are
       similar to those covered earlier in the course.

[ ] 10 The algorithms implemented are too simple or use only techniques 
       covered previously in the course.

[ ]  8 The algorithms implemented are trivial or rely almost entirely on code 
       from previous assignments or labs.

Comments:

CODE QUALITY (10 points): The code is elegant, concise, and efficient.

[ ] 10 The code is nearly flawless in concision and efficiency, or 
       impressive in its elegance.

[ ]  9 The code has a few minor problems with concision or efficiency.

[ ]  8 The code has one significant problem with efficiency or several 
      problems with concision.

[ ]  6 The project has significant problems with concision and efficiency.

Comments:

CODE READABILITY (10 points): The code is well-documented and easy
to understand.

[ ] 10 All procedures are documented with 6P-style documentation. Procedure, 
       parameter, and variable names are crystal clear. Code is
       correctly formatted. Short comments explain the purpose of
       expressions that might otherwise be unclear.

[ ]  9 All procedures are documented with the 6Ps and there may be a few
       internal comments where needed. Procedure, parameter, and variable names
       are mostly clear. Code is formatted correctly.

[ ]  8 Most procedures are documented with the 6Ps. Procedure, variable, 
       and parameter names are at least suggestive. Formatting is mostly 
       correct.

[ ]  4 There is little documentation. Much of the code is incorrectly 
       formatted. Several procedures, variables, or parameters have opaque or
       meaningless names.

Comments:

FINAL REPORT (25 points total)
------------------------------


REPORT FORM (0 points): The report has the appropriate form.

The report must include all of the required components: a heading
(with authors) and title, a short description of the project goals,
a description of the materials, a description of the algorithm or
algorithms, an explanation of the results, and a description of
necessary followup work.  Reports that lack any of these components
will receive a score of zero.

Comments:

REPORT WRITING (5 points): The report uses correct spelling, grammar,
and style.

[ ] 5 The report not only uses correct spelling and grammar, but also
      demonstrates particular facility with language.

[ ] 4 The report uses correct spelling and grammar, with at most
      two or three errors.

[ ] 2 The report does not use correct spelling and grammar.

Comments:

REPORT PROJECT STATEMENT (5 points): The project statment is
complete and accurate and reveals an understanding of the purposes
and processes of the digital humanities.

[ ] 5 The project statement clearly describes the goals of the project 
      in a form in language appropriate for a general audience,
      demonstrates a deep understanding of the digital humanities,
      and suggests a project that is likely to provide compelling
      results.

[ ] 4 The project statement fails to completely achieve one of 
      the primary goals (e.g., shows a less than comprehensive view
      of the digital humanities, fails to address the appropriate
      audience, or fails to motivate the project).

[ ] 3 The project statement fails to completely achieve two of
      the primary goals.

[ ] 2 The project statement fails to completely achieve three or
      more primary goals.

[ ] 0 No project statement.

Comments:

REPORT MATERIALS STATEMENT (5 points): The report describes the
source of the materials (that is, where you obtained them), the
subject or content, the form (e.g., is it plain text, XML files,
numeric data, images?), and the scope of the materials (i.e., how
much material is there?).

[ ] 5 The materials statement clearly indicates the source, the subject or
      content, the form, and the scope.

[ ] 4 The materials statement indicates the source, form, content, and
      scope, but leaves some minor questions about the content,
      form, or scope.

[ ] 3 The data description clearly indicates the source of the materials, 
      but leaves questions about the form or scope of the data.

[ ] 0 The data description does not indicate the source of the materials.

Comments:

REPORT ANALYSIS PLAN (5 points): The report analysis plan is complete
and accurate.

[ ] 5 The report includes a description of each algorithm to be implemented
       as well as an outline of how they will be implemented and used.

[ ] 4 The report accurately describes the algorithms but leaves a question 
      or two remaining about how they will be implemented or used.

[ ] 3 The report has some minor inaccuracies or raises several
      questions regarding the algorithms to be implemented or used.

[ ] 2 The report is significantly incomplete and/or inaccurate in its
      description of the algorithms to be implemented or used.

Comments:

REPORT RESULTS (5 points): The report results section is complete and
accurate.

[ ] 5 The report includes a summary of important results and suggests
      clear and reasonable next steps.  (Not all projects will produce
      results; in those cases, the "non results" are equally important,
      and still require suggested next steps.)

[ ] 4 The report leaves some question about the results or the next
      steps.

[ ] 2 The report leaves qustions about results and next steps.

PRESENTATION (10 points total)
------------------------------

[ ] 10 The presentation is appropriate in length, is organized well, and 
       and provides a complete overview of the materials, approach,
       and results.  It also includes a brief overview of the
       algorithms implemented.  Questions are answered well.

[ ]  8 The presentation is organized well but too long. It also fails to
       overview one or more aspects of the project or leaves some important 
       questions (explicit or implicit) unanswered.

[ ]  6 The presentation is disorganized and too long. It also fails to
       overview several aspects of the project and leaves many important
       questions about the project unanswered.

Comments:

OTHER COMMENTS
--------------

Total: ___/100
```

---

[1] I was trying to riff on the statement that "a picture is worth
1,000 words".  Maybe I should have called it "a procedure is worth
1,000,000 words".

[2] More on that in a subsequent musing.

---

*Version 1.0 of 2018-11-06.*
