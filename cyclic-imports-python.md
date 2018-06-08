Cyclic imports in Python
========================

*Topics/tags: [Rants](index-rants), code, Python*

As is typical, I have committed to too much this summer.  I'm running
three code camps for middle-school and late-elementary students,
one of which we need to design from scratch [1].  That's probably
enough to occupy more than enough time.  But I also agreed to do a
variety of other things.  One of those is to supervise a student
who is trying to complete a Grinnell-specific port of [Project
Callisto](https://www.projectcallisto.org/), Web-based software that
provides a secure and supportive mechanism for survivors of sexual
assault to record and, optionally, report.

The reasons that Grinnell didn't just hire Callisto to build that port
are complex; some are clearly beyond my pay grade.  I do know that we
wanted a form of "branching", so that we could provide different sets
of questions depending on the circumstances.

My CSC 322 students have been working on the Callisto port for two
semesters.  It's time to finish the project, not only because we want
it up and running, but also because it's been a bit of an outlier in
the course: Everything else is code that students designed from scratch
in Ruby on Rails.  This project uses Python and Django code developed
by others.  If I'm passing the course on to someone else, they shouldn't
have to support students working in two languages and environments.

In any case, the student is wrapping things up and I'm doing the best
I can to support them, even though I don't particularly enjoy programming
in Python and don't regularly use Django.

This week, we've been working on a major architectural change.  When we
started working it, Callisto was two separate pieces of software:
[callisto-core](https://github.com/project-callisto/callisto-core),
which does the main work, and
[django-wizard-builder](https://github.com/project-callisto/django-wizard-builder),
which one uses to build the set of questions and works as a module for
callisto-core.  My students struggled a lot dealing with two projects.
It appears that the Callisto developers did, too.  Last December, [they
merged django-wizard-builder into the main repo](https://github.com/project-callisto/callisto-core/pull/345/files#diff-a299d942742e723a3e76557e808956e2).
Since the two student teams made lots of changes to both projects, we're
manually merging our two versions.

With some reference to the main project's merge, we were able to get most
of the work done.  It would have been easier if some of the messages
were clearer.  A few times, we'd have a hidden reference to the old
wizard-builder that took some time to track down or that we didn't think
to change at first [2].

Then we hit what first seemed to be a confusing problem.  A module
called `models` couldn't find a class in a module called `managers`,
even though we could see the class.  My student thought that since
models were involved, it was a problem with the database.  However,
I was fairly sure that it had to do with the underlying Python code.
We scratched our heads for a few minutes and then realized that the two
classes had a fascinating cyclic dependency.  `managers` imports `models`
and `models` imports `managers`.  Cyclic dependencies generally cause
problems and different languages deal with them differently.

As far as I can tell, Python does something straightforward.  Suppose
module A imports module B and vice versa.  If we import A, Python [3] adds
A to the list of imported classes and starts processing the lines until
it hits the `import B` command.  At that point, it starts importing B.
That is, Python adds B to the list of imported classes and then starts
interpreting the lines of B until it hits the `import A` line.  At that
point, it realizes that A is already in the list of imported classes
and continues on in B.  That's a good thing.  Otherwise, we'd get an
infinite recursive cycle of imports.  However, if B *uses* any part of
A [4], we get into trouble because, well, Python has only read just a
little bit of A.

In general, programmers try to avoid cyclic
dependencies.  But, well, we're dealing with the code we've
inherited and, as far as I can tell, the cyclic dependency between
[`models`](https://github.com/project-callisto/callisto-core/blob/master/callisto_core/wizard_builder/models.py)
and
[`managers`](https://github.com/project-callisto/callisto-core/blob/master/callisto_core/wizard_builder/managers.py)
persists in the latest version of Callisto.  We could rewrite the code
to eliminate the dependency, but it will take some consideration.  So,
for the time being, we chose a bit of a hack.  Exploring the code, we
saw that `models` called part of `managers` during initialization, but
not vice versa.  So we had to ensure that the `models` module was imported
first.

We solved that problem in about five minutes.  But boy, do I feel unclean.

---

[1] We need to design the camp from scratch, not the student.

[2] For example, it's really uncomfortable updating auto-generated
migration files.

[3] When I say "Python", I really mean "the Python interpreter".

[4] More precisely, if B's initialization routine uses any part of A.

---

*Version 1.0 of 2018-06-07.*
