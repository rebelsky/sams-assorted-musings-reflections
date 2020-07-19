---
title: A chicken and egg problem and other situations in software selection
number: 1098
tags: [Teaching](index-teaching)
blurb: Increasing complications.
version: 1.0
released: 2020-07-18 
current:
---
I have a "chicken and egg" problem.  You know, "Which came first?
The chicken or the egg?" [1].  I suppose my problem is more prospective
rather than retrospective, something of a "Which *should come*
first, the chicken or the egg?"

The problem is one of software selection.  Or perhaps it's a class
of problems.  As I plan for online teaching this fall [2], I'm
thinking about software to use for a variety of situations.  What
should I use for pair programming?  What should I use for collaborative
brainstorming?  What should I use for collaborative authoring?

While I have more software selection questions than normal right
now, these kinds of questions are not new.  Software always plays
some role in my teaching.  And, as a computer science educator, I
also end up exploring a wide variety of kinds of software for my
students to use in our classes: programming languages, libraries,
integrated development environments (IDE), version control systems, testing
frameworks, database management systems, markup languages, and more.

Up to March 2020, the processes I used likely shared many characteristics
with the processes other faculty use.  Let's start with the processes
for major pieces of software, such as the IDEs I will recommend to
students in a class.  While some students will choose their own IDE
and support themselves, most will not know what to use.  For those
students, I'll recommend an IDE, provide some supporting materials
to help them use it, and often arrange aspects of the course to
make it easier for students to use the IDE.  For example, when I
teach our data structures and algorithms course with Java and
Eclipse, I set up GitHub repositories with preconfigured project
descriptions, which makes it much easier for students to load them
into Eclipse.

So, how would I choose an IDE?  I'd probably start by gathering a
list of expectations.  Some will be relatively concrete, such as
"integrates well with my preferred version-control system", "supports
unit testing", and "runs on macOS, Windows, and Linux" [3].  Others
will be a bit more abstract, like "easy for students to understand"
or "encourages good practices".  For introductory-level courses, I'd
likely prioritize an environment designed for novices.  For upper-level
courses, I might want something that is used in industry.

In developing that list, I'd be talking to colleagues, both at
Grinnell and at other institutions.  I might even post a request
to the SIGCSE-members list, but I'd probably combine such a request
with a request for suggested IDEs.  "What do you look for in an IDE
for _course or language_?  Which did you select?  Why?"

At the end of this process, I'd have a list of criteria and a list
of candidate IDEs.  I would then download the IDEs, experiment with
them, and talk to colleagues in the department.  Since we don't
tend to change those all that often (it's nice for students to be
able to support each other across years), so that conversation would
have been going on throughout the semester.  Since I'd be committing
to software for at least a semester---and more likely multiple
years---I'd spend a lot of time trying out each option, perhaps even
seeing how it performs on different platforms.

After that, I'd start restructuring my course around the new IDE.
I'd write instructions for the start of the semester.  I'd set up
code for assignments to work with the IDE.  Things like that.

It's a time-consuming process.  But, as I said, it's one I expect most
faculty do for some set of software they use, particularly software
integral to their teaching.

But Grinnell now requests that much of the software we use in the
classroom be vetted by lawyers, proceed through additional on-campus
processes, contracted, and more.  Here's what a recent letter on the
subject says.

> Software requests are perhaps one of the more complicated technology requests since the review process is necessarily multi-faceted. Each request requires **significant time** by multiple teams within ITS, purchasing and accounting, the Office of the Dean, and often general counsel because the risks of using unapproved software can be significant; risks whose effects are amplified multi-fold in the current environment. Completion of the online central software request form initiates the review process. The review process includes assessments that examine many factors before determining whether a specific piece of software can be purchased or used. These include the privacy of software users; data security; cyber security of the College network and data; accessibility requirements; fiscal responsibility and cost control; and that appropriate indemnifications are in place. Likewise, compliance rules such as FERPA must be upheld, which often requires contract negotiation with the software vendor.

> The software budgeting and purchasing policy describes the key policy components involved, and it is important to know that all academic-related software requests include a review by the Office of the Dean. Each software review produces an array of assessments from which an institutional risk decision is made, and the length of the process is dependent upon the complexity of the software, the data that is involved, and the responsiveness of the vendor.
The College has a very large portfolio of approved software, but the complexities of licensing requirements mean that there is not a full list available. ITS publishes a list of key general-use software and a list of software that is available on the campus lab image that you can reference, and updates are planned to expand the listing. If you have questions regarding whether a particular piece of software is available, but you do not see it on the list, please reach out to the Deputy Chief Information Officer.

I understand that this cumbersome process is part of our approach
to risk management.  I appreciate that we are considering important
issues like accessibility and privacy.  I would have chosen a
lighter-weight process, but we'll get to that at another time [4].

Why is this a "chicken and egg" problem?  Let's return to the IDE
example.  Suppose I've gathered a list of five possible IDEs along
with my carefully considered criteria.  Do I want to spend the time
evaluating software carefully if I have no idea whether it's going
to be accepted or whether I'll even get any sort of answer before
the semester starts?  It's tempting to just send all five IDEs to
the software request process as I begin my evaluation.  Since
evaluation is likely to take a week or more, it shortens the time
between the conclusion of my evaluation and the decision.  It also
means that I may choose to delay my deeper evaluation until after
I get a response from ITS and the Dean's Office.

But asking for all five IDEs when I know I'm only going to be using
one is a waste of College resources.  Others will have to assess
the software in ways other than I would assess it.  Someone may have
to look at contract language.  Given that the College has only
limited time to consider software, will my requests hinder other
requests, requests that may be more important?

Which should come first: my review or their review?  If my review
comes first, I may be wasting my time, time that is in short supply
(and currently uncompensated).  If their review comes first, I may
be wasting their time.  Both seem like losing choices.

My current strategy is a hybrid.  I spend time evaluating software,
but less than I would historically.  I narrow my choices as much
as possible.  I send off one or two requests.  And then I cross my
fingers.

---

I did say that was one kind of example of software selection.  Here's
another.  I hear about a cool teaching technique from a colleague
at another institution, perhaps in a conversation, perhaps from a
mailing list or article.  We'll suppose it mentions a particular
piece of software.  For example, "Here's a cool way I used Trello
in my class." Before July 2020, I might try the example on my own
and, depending on how it went, either start learning more about the
software and start incorporating the approach in my class, or decide
that it was a failed experiment and go on to something else.  We
learn by experimenting, by trying, sometimes even by failing [5].

But that's not quite so possible any more.  Now I need to submit a
request for the software and wait.  No more spur-of-the-moment
experiments.  Less agility.  Less fun [6].  Perhaps even less
innovation but that's hard to tell; you can get innovation with
careful planning as well as with quick on-off experiments.  I much
prefer the latter to the former.

---

I don't blame the folks in ITS; they are just enforcing a rule.
And I've had some really good experiences with my colleagues in
ITS, including suggestions of other approaches, good explanations
of choices, a willingness to listen, even a few quick responses.

I understand the need for some risk management.  But the quality
of our teaching may also be at risk; does anyone consider that?
It appears that we have adopted a policy more appropriate for a
large corporation than an educational institution [7].  Certainly,
if the review we do were common, our contract review form would
have already analyzed most of the software we've requested.

I am not a lawyer.  I will never be a lawyer.  But I also wonder
whether our approach protects us as well as we think it does.
Suppose there was an inadvertent leak of student data from a piece
of software.  I'd much rather defend that suit by being able to
suggest that the use of that piece of software is "common practice" 
in academia than by acknowledging that we'd done a review.

But what do I know?

I don't even know which comes first.

---

**_Postscript_**: Where did this onerous policy come from?  I have
no idea.  No one has told us.  Perhaps no one wants to take the
blame.  Part of me wonders whether it was one of President Kington's
final actions as Grinnell's President; the process does seem to
share some aspects of governmental red tape.  Part of me wonders
that because Risk Management got (necessary) authority during the
start of the pandemic, they used that authority to impose this
policy.  In the end, it doesn't matter.  The policy is there.

---

[1] The answer to that is easy, dinosaur eggs long predated chickens.
And yes, I do realize that the question is intended to be "Which came
first, the chicken or the chicken egg?"

[2] CSC 151 needs to be online; our classrooms can only support
six or seven students with physical distancing.

[3] "Runs in the cloud" is a very different option.

[4] Perhaps even later in this musing.

[5] As a tenured faculty member, I am perhaps more comfortable doing
something new in the classroom, knowing that it may fail.  But I'm pretty
sure that I experimented in the classroom long before I had tenure, even
when I was on less-secure visiting positions.  If you have good rapport
with your students (and, I expect, if you have the privilege of being
a large, white-presenting, authoritative-sounding male), they'll forgive
a few failed attempts.

[6] At least less fun for me.

[7] Someone told me that our contract-review firm did not have other
educational clients, but [it appears that they have a wide
variety](https://www.icontracts.com/about/customers/), including
Boston College and The Rochester Institute of Technology.  

