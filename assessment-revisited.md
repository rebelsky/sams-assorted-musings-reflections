Assessment, revisited
=====================

A week or two ago, I wrote about [measurable course
outcomes](measurable-course-outcomes) and the broader issue of individual
course assessment.  I also had some nice followup conversations
(in person and online) with my colleagues in the Center for Teaching,
Learning, and Assessment.  Hence, I was interested to see a new critique
of assessment come out.

My reading started with an article on _Chronicle_ [1,2].  That article was
written as a followup to another article in _Intersection_, a newsletter
of the Association for the Assessment of Learning in Higher Education [3].
In the _Chronicle_ article, the author suggests that good assessment is
like any good quantitative social science research: It first requires
that you develop and assess your assessment tools.  That's no easy task.
And that remains one of my primary discomforts with the whole assessment
millieux: If each faculty member is developing his, her, zir, or their
own assessments, then they are no really dealing with good data, at
least in the traditional sense of good data.  The AALHE article suggests
something similar: "_it is difficult to use assessment results because
methods for gathering and analyzing data are very poor [4]".

But common assessments are incredibly difficult to develop.  Even if
we ignore the issue that different faculty and institutions may have
different goals for what seem to be similar classes, instruments are
complicated.  I remember at talk at the SIGCSE Technical Symposium [5]
by Allison Elliot Tew in which she suggested that it took the Physics
community something like a decade to develop a validated instrument for
introductory physics.  And my discipline, computer science, agrees much
less about what should be covered in the introductory course.  Tew was
working on an instrument that focused on concepts and that would be
"translated" to multiple programming languages.  I volunteered to help
with the Scheme translation.  I still recall the first few questions I was
supposed to work with.  They were about loops and the value of a variable
after the loop terminates.  But we don't teach loops in our introductory
course; our students achieve repetition through recursion or through
a higher-order procedure like `map` or `reduce`.  More importantly, we
strive to avoid programs that rely on explicit state.  So what seemed
to be common questions turned out to assume a particular mindset [6].

I've tried to write some more uniform assessments.  For example, for
about eight years, we used an end-of-course assessment which was geared
toward exploring how well students thought functionally.  One of the
key problems asked students to do something with a list of numbers.
Most students solved the problem recursively.  Some used `map`.
And perhaps once per class, a student used a combination of `map` and
`section` to provide a beautiful and concise solution.  Over the eight
or so years, we tried a variety of things to get students closer to the
`map` plus `section` solution.  In the end, we decided that the approach,
while beautiful, was not natural for introductory students; they can read
such approaches, but they are unlikely to develop them on their own,
at least in the somewhat stressful situation of a timed assessment.
Our goal was never that every student mastered that higher-order
approach; we simply wanted more students to do so.  From talking to
students, we learned that many more understood the approach than used
it on the assessment.  It was a worthwhile study, but it took a lot
of effort and it focused on one of many learning goals of the course.
And I'd still say that it doesn't match what one would expect for the
kind of data comparable to a good social science research project.

I realize that many folks in the assessment community don't think that
assessment needs to reach the level of a good social science research
project; the goals are (a) to help ensure that the ways that faculty
assess students in the class are tied to their goals for the course and
(b) to let faculty get feedback on how well they are achieving their
goals.  But I kind of agree with the critics that without a formal study
[7], the feedback they get from "assessments" is no better than the
feedback they get from other mechanisms.

You know what?  That's not where I was intending to go in this musing.
Rather, I wanted to reflect on a quotation related to the these articles.
The AAHLE article quotes a piece entitled "Closing the Assessment Loop" [8].
I went back and grabbed the quotation from the original [9].

> An internally driven, formative approach to assessment is based on the
belief that a key factor inhibiting improvements in student learning or
allowing students to graduate without learning enough is that faculty
and staff who deal with students lack high-quality information about
the experiences and conditions that help students learn. If they had
information about how much their students were or were not learning and
the practices and conditions that helped them learn, practitioners would
put this knowledge to work, and improvement would naturally follow

That, my dear reader, may be the crux of the matter.  While I agree that
instructors need information about what my students are learning and about
practices to teach better, I think that most of us have those already.
As I said in [my prior musing](measurable-course-outcomes), we see what
students learn [10] as we interact with them.  We learn from their work.

And, as importantly, at least at Grinnell, most of us have access to 
"high-quality information about ... the practices and conditions that
help [sudents learn]".  Grinnell sponsors regular workshops.  Academic
Advising sponsors talks.  We have Faculty Fridays to help us learn [11].
Many of us attend professional conferences and workshops related to pedagogy
in our discipline [12].  Some of us develop cutting-edge practices to help
student learns.  I think, for example, of the Biology 150 model.

Since the core motivation of assessment, at least as described in this
article, is grounded on a misconception, at least about the faculty I
work with, I find no difficulty in understanding why I and others 
don't trust it.

---

[1] _The Chronicle of Higher Education_, for those outside the academic
circle, or at least outside whichever academic domain abbreviates
its title.

[2] Gilbert, Erik (2018).  An Insider's Take on Assessment: It May 
Be Worse Than You Thought.  _Chronicle of Higher Education_, 12 January 2018.
<https://www.chronicle.com/article/An-Insider-s-Take-on/242235>.

[3] Eubanks, David (2017).  A Guide for the Perplexed.  _Intersection_,
Fall 2017.  pp. 4--13.  <http://c.ymcdn.com/sites/www.aalhe.org/resource/resmgr/docs/Int/AAHLE_Fall_2017_Intersection.pdf>

[4] Italics in the original.

[5] It was in Milwaukee, I think.

[6] I admit that we are the outliers; loops and state are common topics 
in introductory courses.  But I'm confident that our different approach
helps us build better thinkers.  I know that professional programmers
used to a stateful approach often have traditionally had difficulty
transitioning to a pure approach and, more generally, to many functional
concepts.

[7] And, I'd suggest, a formal study that takes place some time after
the students complete the course.

[8]  Banta, Trudy W. and Blaich, Charles (2011). Closing the Assessment
Loop. _Change: The Magazine of Higher Learning_, 43:1, pp. 22--27.
<http://dx.doi.org/10.1080/00091383.2011.538642>.

[9] I found a copy online at 
<http://college.wfu.edu/assessment/wp-content/uploads/Closing_The_Assessment_Loop-Banta_Blaich-2011.pdf>.  It appears the Wake Forest folks did not read the
terms and conditions on the copy they downloaded:

> Any substantial or systematic reproduction, re-distribution, re-selling,
loan or sub-licensing, systematic supply or distribution in any form to
anyone is expressly forbidden.

[10] Or fail to learn.

[11] Ironically, the Dean's office just significantly cut the budget for
Faculty Fridays.

[12] In many years, the majority of the CS faculty attend the SIGCSE
Technical Symposium on Computer Science Education.

---

*Version 0.1 of 18 January 2018.*
