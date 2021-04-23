---
title: I (still) hate Ellucian Self-Service Academic Planning
number: 1135
tags: [Rants](index-rants), technology
blurb: A comparatively calm rant.
version: 1.0
released: 2021-04-22 
current: 
---
It's once again preregistration time [1].  And, once again, I'm stuck
spending way too much time online fighting with our advising system.
I find it amazing how frustrating it can be to use the system. 
The only appropriate response I can find is to muse/rant about it [2].

I never know what to call the software.  We used to refer to it as
"Web Advisor", but "Web Advisor" is a suite of products, and, as
far as I know, the Web Advisor suite doesn't even include the
academic planning software.  That software appears to be part of
Ellucian Self Service [3].  On Self Service for Faculty, the link
to use it is labeled "Advising".  But the [faculty
instructions](https://grinco.sharepoint.com/sites/Registrar/Shared%20Documents/How%20to%20Approve%20Online%20Registration%20Via%20AcademicPlanning.pdf)
call it "Academic Planning", which is how the link appeared in Web
Advisor [4,5].  On the student side, the instructions call it
"Student Planning", but I think it's just the part of Student
Planning called "Plan & Schedule".

My biggest problem with Academic Planning is that it does not behave
well when two people are working on the same student's plan at once,
say when the student and their advisor are talking about it over a
video conference.  That should be a solved problem, right?  I mean,
folks at Microsoft and Google [6] have figured out how to have a
dozen or more people work on the same document?  How hard should
it be to deal with the same student record?  Apparently, too hard
for the people at Ellucian.  If you try to do something and someone
else has made a change, you need to reload before you can make any
changes.  It doesn't even notify you automatically.  Rather, when
you try to make a change, you get some sort of "Operation Could Not
Be Completed" error.  At this point, I think almost every Academic
Planning user has figured out that that means you need to reload
the page.

Unfortunately, when you reload the page because of the error, you
invariably end up somewhere else in Academic Planning.  If I'm
trying to add a course the student and I have agreed upon, and we
get a conflict that forces me to reload, I end up back at the
student's schedule for Spring 2021.  And that's strange because
most students have no courses scheduled for Spring 2021.  Grinnell replaced
Spring 2021 with Spring 2021 Term 1 and Spring 2021 Term 2.  But
Spring 2021 sticks around.  If I'm trying to approve a course after
a student has made changes, it fails, and I reload, I'm back at the
schedule for Spring 2021.  And I can't just click "Next" to go to
Fall 2021.  I have to skip over the two new terms and, in some
cases, the summer term.  The human overhead is painful.

Even with their attempts to preserve data integrity by disallowing 
changes by multiple users, data don't seem consistent.  I've regularly
found myself deleting a course in the Calendar view [7], only to
have it reappear in the List view, the Timeline view [8], and the
Progress view.  As far as I can tell, it only works to delete
something if I do it in the timeline view.

And then there's the joy of deleting courses in the Timeline view.
During advising, it is inevitable that a bunch of extra courses
build up as we think about options.  Is there an easy way to delete
them all?  Nope.  One at a time.  And each time we delete one,
there's a warning that pops up.  What puzzles me most is that I get
the warning even if I'm deleting a course from a past semester that
the student didn't take.  What do the designers think?  "We better
be careful.  Maybe the student will build a time machine and go
back in time to take the course."

I wouldn't care, except that all of those proposed-but-not-taken
courses show up in the progress view.  I don't want to see those
courses.  I want to know what the student *has* taken and what the
student *will* take.  Those are the courses that tell me whether
or not the student is on track.  A course shouldn't be "Planned"
if it's for a past semester!

I wish the folks at Ellucian would follow standards.  For example,
the standard way of writing a mailto link is to separate all of the
addresses with commas.  But Ellucian likes semicolons.  When people
complain about it in the user forums (and they do), the answer is
"They should just copy and paste the addresses into a word processor
and then use search and replace to change the semicolons to periods."
That's not the right answer.  The right answer is "Oh, that should
be a trivial fix for us.  We'll make it today."  Technology is
supposed to make things easier, not to make more work [9].  It
bothers me more because at least one colleague has told me that the
incorrect mailto link crashes their mail client.

Then there the things that suggest that their programmers used the
system as an excuse to get paid to learn Web 2.0 [10,11].  Why can't
they load all of my advisees at once, rather than only when I scroll
the page?  Why are the error messages and warnings in the
upper-right-hand-corner of the page, rather than someplace central
that is easy to see?  At least the scrolling of advisees has gotten
faster; when we first got it, it could take more than a minute for
me to get to the bottom of my list [12].

Then there are the bugs that appear and disappear.  The times I
can't successfully search for courses.  The times the links all
magically disappear and I'm stuck on a page with the info, but not
the links.  I suppose such issues are part of any modern Web software;
they just seem to happen more often with Academic Planning.

I don't blame the Registrar's office.  I don't blame Grinnell.
We're using standard software [15] that I'm pretty sure costs a ton
[16,17].  I just wonder why companies like Ellucian don't do a
better job at software and UI design.

---

**_Postscript_**: I wonder how much human time is lost to the bad
designs in Academic Planning.  I'm pretty sure that each forced
reload requires at least a minute of time.

---

[1] Preregistration is also referred to as Open Registration.  Even the
Registrar's office isn't sure what term to use.    The email from the
Registrar's office on April 9 was titled "Fall 2021 Open Registration".  But
the email reminders I got today for my students who have not yet registered
were all titled "Fall 2021 Preregistration".

[2] I'm working on keeping my blood pressure reasonable, so I won't be
at my normal level of rant.

[3] Such a strange metaphor.  Why is it better to serve ourselves?  And
students can't serve themselves; they need their advisors to help.

[4] Is it "Web Advisor" or "WebAdvisor". 

[5] I wasn't sure whether we even had Web Advisor anymore.  I'm pretty
sure that Ellucian is sunsetting the product.

[6] And bunches of other companies.

[7] "Course Plan" -> "Calendar", from the Faculty Side.  I'm not sure that
students have other options.

[8] Can students see this one?  I use it all the time to skim through a
student's history.

[9] For those who care, my ITS Ticket about this issue has been in the queue
since November of 2019.  I don't blame ITS; Ellucian should fix their damn
software.

[10] At least things have gotten better since the days of Web advisor, where
the programmers didn't seem to understand basic Web design principles like 
"Don't provide a page that has only one button; just skip the damn page" or
"If you can only select an action for one student, use buttons, not menus."

[11] \[This comment about our old Web contractors was removed by my new
sense of calmness.\]

[12] Of course, that was at the point that I had 50+ advisees [14].

[14] Even before the heart attack, I had decided that that would never happen
again.

[15] With some mods to manage the strangeness that is Grinnell.

[16] I'm not sure that "ton" is an appropriate metric for the cost of software.  I
also don't know that you can separate the costs of SelfService from the costs of
Ellucian Colleague.

[17] I expect that the amount we pay Ellucian is officially private information under
our contract with Ellucian.  You don't want customers comparing costs, do you? [18]

[18] By "you", I mean the generic large-scale software vendor.
