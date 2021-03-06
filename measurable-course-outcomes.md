Measurable course learning outcomes
===================================

_In preparation for the forthcoming reaccreditation, the Dean's office
has started asking us to send our course syllabi to our academic support
assistants [1].  If I understand, they worry that the accreditors
may want to see course syllabi, so they want to have them on hand for
those requests [2].  To help, they've sent out a set of guidelines [3] that
they recommend we use, but don't require [4].  And, given the state of
education today, one of the first things they suggest is that we provide
"*Learning outcomes:* Measurable goals are a central feature of a course."_

_While I haven't drunk the kool aid [5] of measurable course learning
outcomes, I do think it's worthwhile to try to follow recommendations
[6].  So I've been thinking about learning outcomes.  In fact, I always
think about learning outcomes; I end each of my classes with a review of
what students might have learned._

_At first glance, measurable learning outcomes make sense.  They represent
the things you expect all students to take away from the course and they
suggest that we have a responsibility to measure those things so that we
know whether or not students are, in fact, learning what we think they do.
But measurable learning outcomes bother me.  This musing is my attempt to
think more carefully through why they bother me._

---

"Include five to eight measurable learning outcomes in your syllabus."
I hear it from my administrators.  I hear it from colleagues whose
opinions I value.  The College probably hears it from accreditors.  But
the requirement bothers me.  Let's consider some reasons why.

First, I find that many outcomes are not measurable
or at least not naturally measurable.  Our [Mission
Statement](https://www.grinnell.edu/about/mission) [7] notes that

> The College aims to graduate individuals who can think clearly,
who can speak and write persuasively and even eloquently, who can
evaluate critically both their own and others' ideas, who can acquire new
knowledge, and who are prepared in life and work to use their knowledge
and their abilities to serve the common good.

As far as I can tell, we've spent a decade just trying to figure out how
to measure "write persuasively and even eloquently".  We haven't even
started to explore "[use] their knowledge and their abilities to serve
the common good".  But our inability to measure these things does not mean
that they aren't valuable.  In fact, I'd say that these broad goals are
*more* valuable than many of the things that we can measure. 

In fact, even though we can't measure these kinds of things, I would say
that our classes are small enough that most faculty can say that they see
changes in their students, even if they don't explicitly measure them.
Our students read better, think better, and argue better after most
classes.  We've seen the student's work [8] at the beginning of the semester.
We see their work at the end of the semester.  Students change [9].

That's not to say that some outcomes aren't measurable.  We can, for
example, measure students' ability to write a program or to express a
non-trivial thesis.  I would say that most students enter the first CS
course unable to write a program in Scheme and leave the course able
to write a program in Scheme.  It's clear that many students enter
Grinnell with difficulty writing a compelling thesis.  By the time they
leave, most have learned how to write much more interesting theses,
guided by documents like Erik Simpson's "[Five ways of looking at a
thesis]"(http://www.math.grinnell.edu/~simpsone/Teaching/fiveways.html)
[10].

However, from my perspective, those outcomes are less interesting than
the broader outcomes.  "Write a program in Scheme" is one component of
"Think like a computer scientist" [11]; "write a non-trivial thesis"
is one component of "write persuasively and even eloquently".  If we
focus in the syllabus on the things we can measure, we may lose the more
important things that we cannot so easily measure.

Second, I've had bad experiences with College-wide measurements.
In measuring writing, Grinnell first tried evaluating student papers
from their first course and from a senior-year course.  But we didn't
always gather the assignments.  In a few cases, we observed that students
went from writing tight five-paragraph essays in their first course to
disjoint, twenty-page essays in their last course.  But when we talked
to faculty about some of those longer essays, we discovered that the
goal was often not to write a coherent essay, but to record a series of
observations or ideas.

A subsequent attempt asked faculty to evaluate a variety of
characteristics of student papers on a five-point scale; things like
"includes a compelling thesis" and "transitions well between paragraphs"
[12].  Given that my experience is that incoming Grinnell students are
generally competent writers but have significant room for improvement,
I was surprised to see that the initial averages were high.  So I asked
a senior colleague how they rated their students.  They said something
like "Most of my Tutorial students are good writers, so they generally
earn a four for the different categories."  I responded something like,
"4 represents 'achieves the level we expect of Grinnell students'.  
Does that mean that your Tutorial students are achieving the level you
expect of students in your senior seminar?"  And they responded "No; of
course not.  But they achieve the level I expect of students in Tutorial."
It's hard to measure growth if you don't have a consistent scale.

I should note that I am happy with the current measurement approach, which
involves gathering both papers and assignments from early in students'
careers and late in their careers and having a group of faculty from
across the College read and compare those papers.  But that is an
incredibly time-consuming measurement.

So I guess that's my second challenge with measurable outcomes: My
experience is that measurements are difficult to develop, difficult
to administer, and often are less reliable than we would expect.
I will admit that this concern is less significant than the concern that
focusing on measurable outcomes means we de-emphasize less measurable, but
potentially more important outcomes.  But it's still a (related) concern.

Third, I have difficulty matching the expected number of outcomes.
Five to eight seems like a reasonable number.  But that also hides a
number of smaller (and more measurable) outcomes.  For example, hidden
within "Can write a non-trivial Scheme program" is a few dozen smaller
things that I expect students to do with Scheme: Write a procedure;
include parameters in the procedure; call a procedure; sequence
operations by nesting; sequence side-effecting operations in the body
of a procedure or `let`; define local variables with `let` or `let*`;
know the difference between `let` and `let*`; understand lists and the
core operations on lists, such as `cons`, `car`, `cdr`, and `null?`;
understand the different kinds of numbers (integers, reals, and complex
numbers, each of which can be exact or inexact) and the operations on
them; use conditionals and predicates; and so on and so forth.  And that
ignores the higher-level things, such as design an algorithm, design tests
for the algorithm, consider edge cases, decompose a problem, and more.

Believe it or not, but I *do* try to test each of those smaller things 
throughout the semester.  Each time we sit down to write an exam [14],
my co-teacher and I make a list of both the core Scheme concepts and the
broader program design concepts we've considered recently and try to ensure
that each is captured in a problem.  Now, we might leave out a few; a
student who knows `car`, `cadr`, and `cdr` probably does not need to be
tested on `cddr`.  But we do try to be comprehensive.  

Is this just an issue with me struggling to get the right "size" of the
learning outcome?  I'm not sure.  I'm testing the question of whether they
can program, but I'm testing it at a lower level.  It's also clear that
the "measurable outcomes" folks wouldn't be happy with me saying "I have
eighty-five outcomes for this course."

Fourth, I am definitely more of a process person than a product person.
I care that students have *done* things in my class, even if they don't
all learn the same thing from that activity.  

For example, each class period I randomly pair students to work
on problems.  That means that each student works with a wide variety
of other students throughout the semester.  I have multiple goals in that
pairing.  I believe that almost no matter what students do after they
graduate Grinnell, they will have instances in which they need to work
with other people.  Often they will have someone who thinks differently
than they do.  Sometimes they will have a great partner.  Sometimes they
will have someone who prefers to allow them to do most of the work.
Sometimes they will have someone who refuses to cede authority.  Most of
the time, they'll have a cooperative partner, but someone who still thinks
differently.  A key goal for many of my courses is that students *practice*
working with other people.  

Most students appreciate that practice.  But they also experience
different outcomes.  I've had students who enter the course thinking
"I work much better on my own" and leave saying "While I prefer to work
on my own, there are circumstances in which I do better with
a partner."  I've had others leave the course saying "I really like to
work with other people, but sometimes I have to work on my own to make
sure that I master the material."  Most leave with better collaboration
skills.  And I could probably measure these, at least indirectly, such as
through partner surveys.  But I'm not sure that it's worth it.  I see the
students improve.  My class mentors see the students improve.  Why add 
another layer of complexity to the course?

Fifth, I don't expect that every student will take the same thing away
from my course, and I don't think they have to.  There are things
that every student will do.  But there are also many things that are
individual learning outcomes, often more minor outcomes.  For example,
on the last day of class this semester, one student said that one of
the most important things they learned in my class was just how many
interesting things happen on Grinnell's campus [14].  Is that a necessary
learning outcome?  No.  Did some students know that entering the class?
Certainly; I had at least one student who was able to comment on most
of the announcements I made in class.  Is it still an important learning
outcome for that student, and many others?  Yes.

While that example is tangential to the primary focus of my courses, I
also see differences in what people take away related to computer science.
For example, in the introductory course, some students say that they
learned a more focused way of looking at a variety of problems.  Others
may have entered with a focused way of looking at problems.  And others
may not see broader applicability.  That's okay.  It's important to me that
students find what is important to *them* from my course.  And perhaps that's
a key issue: if we look primarily at the common learning outcomes, we miss
the individual outcomes.

---

Okay, that's probably enough.  I seem to have found many of my primary
concerns with measurable learning outcomes.  The biggest concern is that
the focus on measurable outcomes is that they tend to crowd out other
outcomes, both common outcomes that are difficult to measure explicitly
and individual outcomes that don't fit into the "outcomes for all"
expectation.  But I also worry about the granularity of measurement that
is appropriate, the focus on measuring things that we already observe
in other ways, and the emphasis on product over process.

At times, I wonder if it's just that the folks who focus on measurable
outcomes have had very different teaching experiences than we do
at Grinnell.  With small classes, you see students learn and you can
often tailor learning outcomes to individuals.  If your experience
is primarily in larger classes, it seems unlikely that you can see
learning in individual students and you are more likely to focus on broad
instruments rather than on the individual.  Or maybe I'm just biased.

I do think I have an appropriate compromise solution [15].  My section
on learning outcomes will begin with something like this statement [16].

> In my experience, each student enters this course with their own
goals and expectations and leaves the course with their own, individual
learning outcomes.  However, there are some common goals I have for
this course.  They include the following.

I will then mix together things we might consider measurable learning 
outcomes (e.g., "can write a non-trivial program in Scheme"; "can
write a recursive procedure"; "can read and interpret an algorithm") with 
less measurable outcomes (e.g., "thinks better about problem solving").

In any case, I look forward to working with my colleagues in the Dean's
Office and the Center for Teaching, Learning, and Assessment about this
part of my syllabus [17].

---

[1] The _Faculty Handbook_ suggests that we should be sending them to
our department chairs, so it's not that much different to send them to
the ASAs.

[2] I'm amazed by the number of things they are asking us to do "Just
in case the accreditors decide to ask for it."  But I also understand that
reaccreditation can induce anxiety.

[3] As you might expect, I had about a dozen critiques of the guidelines.
I'm keeping those private.

[4] The _Faculty Handbook_ is clear that faculty have control over the
structure of their syllabi.  So they really can't require particular
components.

[5] If "Kool-Aid" still a registered trademark?  How about in the context
of "I've drunk the Kool-Aid"?

[6] Stop laughing.  If the recommendations are reasonable, such as the
suggestion that we write about accommodations and religious holidays,
I'm happy to follow them.  And I'm willing to try things that might not
be as reasonable.

[7] You can also read [my notes on the Mission
Statement](grinnell-mission-statement).

[8] I define "work" broadly.  It might include something as complex as
a paper or examination or something as "simple" as classroom participation.

[9] I admit that we don't see the changes happen in all students in every
course.  But we see them happen to most students in most courses.

[10] <http://www.math.grinnell.edu/~simpsone/Teaching/fiveways.html>.

[11] Or at least "start to think like a computer scientist".

[12] Those are not the exact questions.  I don't have the instrument
at hand.

[14] Four exams per semester.

[14] In many courses, I give a modicum of extra credit for a selected
set of events on campus, typically major academic talks (e.g., [Scholars
Convocation](convocation) or Rosenfield Symposia) or musical events,
department talks and discussions, peer support activities (e.g., attending
a peer's play, concert, or athletic event), and a few other things.  Since
I give extra credit, I announce these events and encourage students to
announce their own.

[15] It doesn't really have to be a compromise as I have control over my
syllabus.  But, as I said earlier, I am trying to cooperate in this
endeavor.

[16] And yes, I know it needs work.

[17] Don't you feel sorry for them?

---

*Version 1.0 of 2017-12-31.*

