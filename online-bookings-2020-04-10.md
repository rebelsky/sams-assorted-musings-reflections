---
title: Web-based software for making appointments
number: 1045
tags: [Teaching](index-teaching)
blurb: Software transitions.
version: 1.0
released: 2020-04-10 
current: 
---
For many years, I held mostly "open" office hours.  That is, I set
times that I would be in my office and took students on a first-come,
first-served basis.  I also allowed some sign-up times, particularly
during preregistration.  And, because it's me [1], I also had an
open-door policy, approximately, "If my door is open, you can come
in and ask questions.  However, understand that I may not always
be up to answering them at the time."

At some point, I decided that I would be better off having office-hour
sign-ups, rather than completely open office hours.  Why?  Mostly
because I didn't like students having to wait their turn in the
hallway, but also because that process sometimes ended with students
still waiting when my office hours were over and I had to go off
to class or a meeting or something else.  So I moved to a sign-up
sheet outside my office, with fifteen-minute appointments.  Fifteen
minutes was not enough for some meetings, and too much for others,
but it generally worked.  And at least students knew when they were
meeting with me.  If a meeting was short or no one was signed up
during a slot, I took walk-ins.  These are still my practices.  And
there are variants.  For example, I've had a few semesters in which
I had students sign up for a regular weekly appointment or appointments.
These are usually students with great tenacity and a growth mindset,
but who struggle with CS.  I'm happy to support them.

I like this new approach (or these need approaches).  But it (they)
needed some updates.  With a sign-up sheet outside my office, I
would only know what appointments I had when I was in my office.  And
students would often email me to see if I had open slots and, if so,
when those were.  So I decided to switch to online bookings.

I started with youcanbook.me.  My wonderful instructors at Global
Online Academy used it.  And it had a nice conceptual design; I could
mark times as "Office Hours" in my Google Calendar, and they would 
automatically appear on my youcanbook.me booking calendar.  That
made it easy to make adjustments on the fly, such as adding office
hours when students are working on an exam, or removing them when
I am out of town.  I used it for a few years.  I also asked ITS if
they supported something similar, but the answer was "No."

Then youcanbook.me decided that taking the times from my Google
calendar was a premium feature.  It may also have removed other
features I cared about.  I don't remember.  All I know is that I'm
a cheapskate.  So I went looking for another solution.  Eventually,
I settled on Acuity Scheduling.  It wasn't quite as easy to
use as youcanbook.me, but it got the job done.  Most importantly,
it was relatively easy for my students to use and it put their
appointments on one of my calendars.

On Tuesday, the College released a memo indicating that we should
avoid software not approved by the College.  There isn't a complete
list of approved software available, but one of the approved lists
did suggest that we have a license for Microsoft Bookings.  So
yesterday, I tried to figure out how to use it.  I think I have the
basics set up, at least for now.  So I can step back and think a
bit about the aspects I like or don't like [2].

Microsoft does not understand short URLs.  Where youcanbook.me gave
me <https://rebelsky.youcanbook.me> and Acuity Scheduling gave me
<https://rebelsky.as.me>, Microsoft insists on
<https://outlook.office365.com/owa/calendar/SamuelARebelsky@grinco.onmicrosoft.com/bookings/> [3].
I don't think my students will be able to remember that, and I
certainly can't fit it on the paper hang tags I usually put outside
my office.  Fortunately, I have an account on bit.ly, so I've set
up <https://bit.ly/book-samr>.  Not quite as elegant, but it works.

Microsoft does not seem to have embraced the idea of free-form input
or automatic data incorporation.  It doesn't share youcanbook.me's
ability to draw from a calendar.  It doesn't share Acuity Scheduling's
parsing of user input.  That is, rather than saying "I'm available
8-11 and 1-3 next Tuesday", I get to fill out separate fields for
start time and end time for Tuesday and then click a button to add
a separate set of times for Tuesday (where I again fill in two fields).
I still haven't figured out how to make different hours available
each week.

And then there's the email issue.  You'd think that the confirmation 
that comes for my appointments would come from <rebelsky@grinnell.edu>.
But no, they come from <SamuelARebelsky@grinco.onmicrosoft.com>.  Such
a trustworthy, academic-sounding address.  "GrinCo: We make you smile!"
I've put in a help ticket to figure out how to change it.

Of course, Microsoft Bookings isn't designed for academics.
The front page keeps track of how much you've made from bookings.
I wonder how the College would feel about me charging for meetings
with students.  In any case, I've set the cost to zero.  And it thinks
that I want to handle hours from lots of people.  I think that means
that people booking an appointment need to select my name from a
pop-up list with just one entry.  Or you did; I seem to have fixed
that.

Speaking of the client UI, it's worth looking at that a bit., There's
an *I* for info, but instead of presenting the info when you hover
over the button, you must click it and then click a close button.  Why
can't it appear when you select a service?

What bothers me more is that it only shows one day of availability
at once.  That's so 1990's technology.  All the other schedulers
I've used have shown a week or two of availability on one screen.
It's not a big thing, but it adds to the workload for the user.  I
suppose that's my general experience with Microsoft products; they
don't keep up with modern UI practices.  Perhaps it will be something
to study in my HCI course next spring.

On a more positive note, I see that when I schedule activities in
my Google calendar that conflict with my available booking times, 
the booking options disappear.  That's a good design.  But I'm seeing
some things unavailable when I thought I had them available.  I'll
need to check on why that is happening; perhaps it's things I've
listed as all-day meetings.  I also like that I can create multiple
"services" with multiple lengths.  There are also some other features
I like, but I don't think I'll reveal them yet.

Now I want to see what other folks on campus are doing with this.
I think there's a way to look up all the Bookings Calendars at an
institution or at least an institution to which you belong [4].  I
only see fourteen, including two associated with GrinnellCollege.
One of the two seems to be available at
<https://outlook.office365.com/owa/calendar/GrinnellCollege@grinco.onmicrosoft.com/bookings/>.
There's one person I can book appointments with, "John".  I wonder
which John that is.  It appears that John will do an "Initial
Consult" starting any time after 3:00 a.m. on weekdays.  I'll go
with 8:00 a.m.  What else can I figure out?  I see that one colleague
has two different booking organizations for different purposes.  I
wonder if I can archive the same.  Yup [5].  Ah, what fun.

I'd like to have an initial message on my booking page.  I could
include one with youcanbook.me and Acuity Scheduling.  But I still
haven't figured out how to do it with Bookings.  Let's run through
the tabs.  **Home**.  Nope.  That just tells me my revenue and lists
features.  **Calendar**.  Nope.  That lists the calendar.  **Booking
Page**.  While that sounds promising, it does not include an option
for introductory text.  **Customers**. Nope.  But it's good to see
Microsoft will keep a record of everyone who books with me.  Since
that might be FERPA-protected information, I'm glad to know that
Microsoft is an Officer of the College [6].  **Staff**.  That's
just me.  I can't even add any information about myself.  Not even
a picture.  Bleh.  **Services**.  We've discussed those already.
I like the ability to add them.  But that's not a greeting.  **Business
Information**.  I can enter a *Business name*, a *Business address*,
a *Business phone*, a *reply-to email*, a *Website URL*, a *Privacy
policy URL* [7], a *Terms and conditions* URL [8], a *Business
type*, a *Currency*, a *Business logo*, and *Business hours*.  But
no *Business description*.  And that's it.

I cannot find a way to add an introductory message.  And it seems like
such a natural feature.  Oh well, I guess Microsoft Bookings meets
"the majority of [my] functional needs" [9].  I'll still put in a [help
desk ticket|https://help.grinnell.edu] in case I missed anything.

Wait until I take on Microsoft Teams!

---

**_Postscript_**: I am not sure whether "Bookings" or "Teams" are
registered trademarks.  If they are, please mentally replace
"Bookings" with "Bookings®" and "Teams" with "Teams®" throughout
this document.  Oh, you should probably do the same with
"Microsoft®" and "MS®" [11] and likely a bunch of other stuff I"ve
forgotten.

---

**_Postscript_**: As noted in the page footer, the opinions expressed
herein are my own and should not reflect on the Microsoft Corporation,
Grinnell Corporation, or any other entity.

---

[1] Or, perhaps, because it's Grinnell.

[2] More the latter than the former.

[3] No, <https://outlook.office365.com/owa/calendar/rebelsky@grinnell.edu/bookings/> does not work.

[4] Found it!  How?  We'll leave it as an exercise for the reader.

[5] Guessing the fairly obvious organization name I chose is left as
an exercise for the reader.

[6] Or something like that.

[7] "You have no privacy" sounds good.

[8] I wonder if the College has a default one.

[9] Grinnell College (nd). _The importance of only using approved software_.
<https://grinco.sharepoint.com/sites/its/SitePages/UsingApprovedSoftware.aspx>.
Undated.  Last visited 10 April 2020 [10].

[10] Usually, I insert a snide comment about how we hide important policies
behind a password wall.  However, since we seem to be a model for other
institutions in responding to the novel coronavirus, I'm glad that this
document is not available as a model for others to adopt or adapt.

[11] As long as you don't mean Mississippi.
