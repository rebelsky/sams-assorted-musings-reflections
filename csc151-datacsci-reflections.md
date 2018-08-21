Reflections on the new data-science-themed CSC 151
==================================================

*Topics/tags: [CSC 151](index-151), teaching [1], Scheme, Racket, data science, long, rambly*

In the summer of 2017, Sarah Dahlby Albright, Titus
Klinge, and I developed [a new version of CSC 151 that
used "data science" as the theme](new-csc151-2017-08-07).
I taught two sections in the fall and [a section in the
spring](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/home/).
Titus also taught a section in the fall and a section in the spring.
I won't be teaching it this fall; instead, I'm taking the semester to
develop a third version of [CSC 151](csc151-evolution) that emphasizes
"[digital humanities](csc151-dighum-blurb)" [4] that I will teach in
the spring.  

That doesn't mean that the "data science" version won't be offered.
Since CSC 151 is key to the Grinnell CS curriculum [6], others will
be teaching CSC 151 this fall.  And, since the "data science" [7]
curriculum is a bit more robust than the mediascheme curriculum [8],
my colleagues will be following the new curriculum, using the readings
and labs we developed last year.

A week or two ago, one of those colleagues asked me to summarize what
I would change about this new CSC 151.  I consider it useful to reflect
on those matters, not just to support my colleagues who have to deal with
materials that I developed, but also to help myself prepare to design 
the next version of the course.

---

Let's start with what went well with the new version.  We were able to
get rid of the dependence on a custom interprocess communication library
written in C.  Things crash much less often.  Students are also able to
run the class examples on all three major platforms (Linux, Mac OS,
Microsoft Windows).  That's a significant advantage, but it's mostly behind
the scenes.

We rearranged the curriculum so that students work with higher-order
procedures over lists (e.g., `map`, `reduce`) starting in the second 
week of the semester.  That's worked well.  We also introduce `section`
and `compose` early and that has worked well.  In teaching the course,
we want to help students think differently about how you define procedures
and to get accustomed to techniques of higher-order programming [9].  The
`map`-early ordering has worked well.  We also introduce and use strings
much earlier.  More broadly, the order of topics seems to function well.

Like the earlier mediascheme course, The "data science" version includes
a substantial project.  The project remains engaging and students feel
a clear sense of ownership.  We've also added explicit work days;
those have proven useful to the students.

I will note that I find the "[find
a data set and do something interesting with
it](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/assignments/project)"
projects less interesting than the old "[a procedure is worth 1000
pictures](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2017S/assignments/project)"
projects.  And I miss the way in which those old projects helped students
realize just how broadly applicable and creative CS can be.  I don't know
the right way to deal with this issue. Nonetheless, it seems worthwhile
to note.  One possibility is to encourage students to develop new ways
to visualize a data set.

More broadly, I find the image-making theme more exciting than the
data science theme.  But that may just be me.

---

Let's turn to things that can be changed, or that are worth considering
changing.

The datacsci [10] students seem less comfortable using *lambda expressions* than
do the mediascheme students.  Too often, the datacsci students want to map
something over a list and struggle to build an expression with compose and
section when a lambda expression would be more straightforward.  We need
to emphasize the benefits of using lambda with `map` (and `filter` and
`reduce`).  Pay attention when you introduce procedures and make sure
to re-emphasize how to use anonymous lambda procedures.

For sighted students, *visualization* is a powerful tool.  While we do
present some visualization techniques and procedures, we could use more
emphasis on visualization.  It may be that an early homework assignment
or a few extra problems will be enough.

There have been significant *changes to MathLAN*
since the spring.  The [getting started with GNU/Linux
lab](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/labs/linux)
needs to be rewritten and tested.

We've had four *take-home examinations* each semester with the first
exam assigned in the middle of week three.  We had that early exam so
that students could better understand the level of the course before
the add/drop deadline.  With the change in the add/drop deadline, that
no longer seems necessary.  I would consider switching to three exams,
one assigned week four and due in week five, one assigned week eight or
nine and due in week nine or ten, and one assigned in week thirteen and
due in week fourteen.  I am not sure whether I would change the number
of problems on the exams; six seems to have worked well.

Since data munging and data cleaning are two core aspects of our approach
to data science, we should consider adding a paired reading and lab on
*regular expressions* [11].  However, I'm not sure what we could cut to
make room for that additional material.

We've tried to include *ethical considerations* implicitly in much
of what we do in the class.  But they could use a bit more emphasis.
It might be worth having students read the ACM Code of Ethics.  Of course,
the ethics of data are a bit different, so it might also be worth having
students read something about those issues, too.  I'm not entirely sure
where that fits best.

Our *sample datasets* are not particularly exciting.  We use a set
of zip codes which provides a good starting point for thinking about
visualizations (and helps students realize when they switch latitude
and longitude).  It also requires some relatively straightforward
cleaning.  We use course registration data because it's familiar
to students.  But we could come up with some more compelling sets.

---

Here are a few moderate-length additions that would be useful.  If my
colleagues ask nicely, I may find the time to write something up for
each of them in the first few weeks of the semester [12].

Students would benefit from a *style guide*.  We discuss style both implicitly
and explicitly, but the material is not all in one place.  It may be useful
to put everything together, along with examples.

It has been suggested that we might want to walk students more
explicitly through various *problem-solving strategies*: You have
a computational problem to solve or a procedure to write.  Now what?
I model approaches in class, but students might benefit from a list 
of steps accompanied by examples [14].

And a big one: We lost the *online reference* when we switched from the
old mediascheme version.  We should reintroduce it.  But that will take
some effort.

---

Then there are the issues that aren't worth considering for this fall's
course, but might be worth exploring in the future.

It may be worth revisiting approaches *local bindings*.  We've generally
told students to use `let`, `let*`, `letrec`, and named `let`.  The Racket
community seems more fond of internal `define` statements.  I worry that
a student who does not learn `let` will find that their Scheme education
is incomplete [15].  There's also the (slight?) value considering the
nesting of `let` and `lambda` [16]; it helps students think more deeply
about scope and the lifetimes of scopes.  In contrast, internal `define`s
seem a bit easier to understand and require less indentation.

Racket has a reasonable approach to
[*structures*](https://docs.racket-lang.org/reference/structures.html)
(records, objects, whatever you want to call them).  We might want to
consider introducing the basics of structures.

At one point, we taught one approach to *objects* in CSC 151.
Students modeled objects as functions that take messages (and
additional parameters) as input.  They used local bindings
to create state.  I don't think I'd recommend revisiting
this approach, but something is comforting [18] about having
functional, imperative, and object-oriented concepts introduced
in our first course.  And Racket does have [a reasonable object
system](https://docs.racket-lang.org/reference/mzlib_class.html).

---

That's a lot.  What are the highest priorities?  Reference pages
because they make students' lives easier.  Better coverage of `lambda`
expressions, since it is both straightforward and useful.  More coverage
of ethical considerations.   Those three seem worth the most effort.
Fixing the introduction to MathLAN is also necessary, but should not
be complicated.  If you have time, I'd also look for additional data
sets and work them into the course as appropriate.

---

Postscript: Now I'm starting to worry about the new FunDHum [19] course.
There are lots of things I want to add, such as simple XML trees, regular
expressions, structures, and annotating data.  But what can I drop from
the current course to make room?  And I'm pretty sure that I only have
forty-one days in the spring, rather than the standard forty two [20].
Oh well, finding room will be one of my (many) challenges.

---

[1] Or at least "teaching computer science" [2].

[2] Or perhaps "teaching *introductory* computer science" [3].

[3] Or is that "teaching introductory computer science *at Grinnell* and
*with Racket*"?

[4] One useful thing about topics like "data science" and "digital
humanities" is that there are many interpretations of each term, so you
have a wide array of choices about what to focus on [5].

[5] Alternately: No matter what you do, someone will say that you missed
a critical point.

[6] And, I would say, a valuable part of many students' liberal arts
educations.

[7] I will continue to put "data science" in quotation marks to emphasize
that we don't do everything that someone expects in a data science course.

[8] More accurately, the software for the mediascheme curriculum is
less robust.

[9] Yes, this is our introductory course.  We teach CS differently at
Grinnell.

[10] Data Science + CSC = datacsci.

[11] I realize that some of my colleagues feel that because Racket regular
expressions mimic the syntax of regular expressions in Perl and other
similar languages, they are confusing and potentially harmful to students.
I accept that the broader community uses this ugly syntax.

[12] Even if they don't ask me, I may try to find the time.

[14] Here's a sketch of potential steps.  (1) Make sure that you
understand what the procedure is supposed to do by identifying sample
inputs and outputs.  (2) Reinforce your understanding by documenting the
procedure.  (3) Try one of the "basic" approaches to designing algorithms:
(a) see if you've previously solved a similar problem and adapt that
solution; (b) work a few examples "by hand" and then generalize; (c)
use one of the basic patterns we've identified; (d) identify relevant and
useful procedures and think about how we might combine them.  (4) Run
your algorithm by hand on a few examples.  (5) Turn your sample inputs
and outputs into tests.  (6) Convert your algorithm to Scheme code.
(7) Run the tests.

[15] Of course, I've accepted that they will survive without learning
`set!` and continuations, to name two other useful concepts.

[16] That is, there's a difference in efficiency between
`(let (...) (lambda (x) ...))` and `(lambda (x) (let (...) ...))`.
Consider, for example,

    (define fun
      (let ([square (lambda (x) (* x x))])
        (lambda (x)
          (square (square x)))))

and

    (define fun
      (lambda (x)
        (let ([square (lambda (x) (* x x))])
          (square (square (x))))))

You can't do anything like the first version with `define`.

[17] That state got introduced with a `let`.  That's another reason to
keep `let`.

[18] I had originally written "something *nice* about ...".  Because "nice"
is overused, Grammarly suggested, "beautiful" or "sweet".  I settled on
"comforting".

[19] "A functional approach to digital humanities" -> "FunDHum".

[20] It appears that the question is "How many times should a 
Grinnell MWF class meet in a semester?"  Or perhaps it's just *a* question.

---

*Version 1.0 of 2018-08-19.*
