This year's sabbatical
======================

*Topics/tags: [Overcommitment](index-overcommitment), academia, write, long*

I'm on sabbatical this year.  When people hear about the sabbatical, they
tend to ask two questions: _Weren't you on sabbatical last fall?_ and 
_What do you plan to do on sabbatical?_ [1].  The answer to the first question
is a bit more straightforward: I had a fellowship in Fall 2018 and fellowships
are separate from sabbatical [2].  I feel privileged to have had the
fellowship and I plan to continue the work from that fellowship during
my sabbatical.

The answer to the second question is a bit more complex.  A year ago,
when I needed to plan for the sabbatical, I wrote [an extended set of
notes on my plans](sabbatical-2019-draft).  For those who don't want
to read the whole thing, here's the most important paragraph.

> I’m planning four projects: I should put the new CSC 151 materials in a generally-usable form. I should wrap-up the code-camp work, whatever that means. I should rework the mediascheme materials to work only in DrRacket. And I should reboot the MIST project. [...] also may be working on the SIGCSE volunteer system, but that’s probably not worth mentioning in the application. [3]

But, well, things change.  Among other things, new opportunities [4] arise
and some dry up.  There's also more to sabbatical than the primary projects.
As I sit down to begin my sabbatical, it seems worthwhile to revisit my
plans.

The first answer I give to most people is to pat my belly and say "My 
health is my first priority."  And it really needs to be.  I'm out of
shape.  And my shape is too round.  So exercise and weight loss are
an essential part of sabbatical.  I'm hoping that the reduced stress of
sabbatical [5] will make it easier to find the time to focus on those
issues and that they will remain a focus once I return to work.

When I wrote about planning to write more about the code camps, I had
not yet submitted the latest set of papers on the code camps for review.
I was surprised to find that both were accepted [6].  Given the messiness
of our data [8], I don't think that there's much more I can write for
my professional community about those camps.  However, given the impact
the camps had on our community and the number of requests I've been getting
to offer camps again, it's worth considering how we can continue to offer
them now that the grant has expired [9].

In terms of new opportunities [11], the most significant is that I have
been asked to take a more active role in the ACM Special Interest Group
on Computers and Society.  SIGCAS is an important group, but is struggling
with identity issues and a lack of volunteers.  I've volunteered to help
try to address these challenges.  But working with ACM is, well, a
challenge of its own [12].  I'm also a bit uncomfortable with this much
responsibility.  This sabbatical activity, more than my others, invokes
some anxiety.

As long as we're on the subject of projects not in the sabbatical plan,
I should mention at least one internal project.  Fall 2021 will mark the
50th anniversary of the individually advised curriculum [14].  A symposium
on "The liberal arts in the 21st century and the open curriculum", or
some such, seems like a good thing .  When I asked about it recently,
it sounded like no one else was thinking about such a possibility.
It may be that I'm more passionate about the option than others and may
therefore take some lead in moving us forward [16].

I hope to be able to teach Tutorial in Fall 2020.  I should spend some of
my sabbatical time planning the topic and readings for that Tutorial.
Expect a musing in the near future on those issues.

A variety of smaller opportunities are also cropping up.  I'm now
scheduled to do two external reviews and one set of grant reviews.  I
expect more such opportunities are on their way.

Perhaps it's better to think about what I *won't* do.  I've resigned
from all of my on-campus committees.   I've indicated that I won't help out
with some major department projects.  I'm debating which meetings to attend
and to miss.  I probably need to attend department meetings.  I probably
don't need to attend division meetings.  What about faculty meetings?
I probably shouldn't attend.  However, important things are discussed at
faculty meetings and I may feel blindsided by changes when I return if I
do not attend.  We shall see.

What else?  I should clean my lab.  Michelle has suggested two hours per
day until it's in a sensible state.  I'll see if that will work.  I also
have to clean up my home office, the basement, and the various other places
I hoard things.  I'd also like to make some book crates to better organize
the books that are scattered in those various places.  And, as I move the
books into crates, I should catalog them.  If a book's not worth cataloging,
I should get rid of it.

One of my colleagues tells me that they read an article or a book
chapter each day of their sabbatical.  That seems like a worthwhile goal.
I might add "long Web page" to the list of kinds of readings.  In any
case, I have a much too large reading list, and I should work on it.
I'll also try to read for pleasure each day.  I may muse on some of
these kinds of readings.

I hope to continue musing each day.  Musing does really make me happy,
even when my musing is mostly ranting.  There's something positive
about writing.

The Innovation Fund deadline is soon.  I need to decide whether I want
to ask for funding for my two long-standing projects related to Grinnell:
A more humanistic approach to assessing the quality of a students'
liberal arts education [20] and a return of Scholars Convocation to
a weekly event.  This year seems like the one in which to propose such things,
even if they won't go into effect until the following year.  I wonder
what departments I can get to buy in to the "curriculum defense" model.

What about the main projects?  I haven't looked at MIST in four years.
If I recall correctly, we had a few large open questions, particularly
how we would deal with user-defined functions.  The software infrastructure
that we relied on has also changed significantly in the past four years.
It may be necessary to do a complete rewrite.

My first step in working on the three versions of CSC 151 is to build a
better system for generating documentation pages.  We lost all of the
carefully written documentation when [we switched from the old DocBook
site to the more modern Jekyll](dumb-things-site-builder).  Since most
of the documentation exists in source code files, I should write a program
to automatically extract and format it.  

Next up will likely be starting to rebuild the MediaScheme course to use
the built-in Racket libraries.  I'll miss GIMP [21], but the system will
be much more stable without trying to do inter-process communication.
After all of that, it will probably be time to combine the libraries
for the three courses.  And after that?  I'm not sure.  I'd like to
do something better with regular expressions.  I need to change my
approach to hash tables and, perhaps, get them into all three courses.
I should rethink structs and objects.  There's also the long-standing
question of whether I should design a fourth version of the course,
one focused on computing for social good.  I keep wanting to do such a
course, particularly because it strikes me as yet another way to help
diversify our department.  Nonetheless, I seem to lack the clarity of
vision for a full-course design.  Perhaps that's a task for my next leave.

It may also be worth exploring other Lisp/Scheme variants for CSC 151.
I see, for example, that ClojureScript allows one to compile Clojure
to JavaScript, which would be cool for writing Web apps in CSC 151.  I
should probably spend at least a few days considering such issues and
having the joy of learning a new language.

I'd also like to think a bit about CSC 207.  I had a lot of fun teaching
it last year and look forward to being able to teach it again.  But with
new Oracle licensing, and a much faster update cycle, Java is becoming 
less appropriate for the classroom.  We've talked about switching to 
C# [22], Ruby, and even some modern Smalltalk dialect.  We should also
consider Rust and Kotlin.  But the choice is not mine; that's really
something we should talk about as a department.

What about the SIGCSE volunteer system?  I'm not one of the Volunteer
Coordinators for the next SIGCSE, so that's not really in my wheelhouse
any more.  It also sounds like SIGCSE wants to move on to something a
little more robust.  I wish my successors luck in finding something
with all the features of the current system.

Let's see ... where do things stand?  Of the big projects, I've dropped
two (overview of code camps and SIGCSE volunteers) and added at least
one more (SIGCAS and perhaps working on the anniversary).  There are
the normal slew of "smaller" things.  And more will probably come up.
Oh well; I won't count on completing everything.

What else?  During my last sabbatical, I was happiest when I was making
art.  Building the book crates will help scratch some of that itch.  Building
MIST and the MediaScheme course may also help.  But I might also need to
carve out more time for something a bit more serious, particularly if I
can find a way to get the Laser Cutter in my lab working.

In the end, my health, both physical and mental, is the most important thing
to work on.  I wonder if the Dean will agree when I write my report at
the end of the year.

---

[1] Some also ask _What's happening to your advisees?_  I'm keeping them.
However, since 30+ graduated in the spring, I'm down to a dozen or so.

[2] And, for the next few years, MAP credits are another thing altogether.

[3] Rebelsky, Samuel.  2018.  A draft of my 2019-2020 sabbatical proposal
_SamR's Assorted Musings and Rants_.  Found online at <https://www.cs.grinnell.edu/~rebelsky/musings/sabbatical-2019-draft>.  Dated 20 August 2018.

[4] Or expectations.

[5] Fingers crossed.

[6] It was not a typical year; I submitted more things than normal and
had a higher percent than normal accepted.  In addition to two code-camp
papers, I also had a paper with Janet on the software design course
accepted [7] as well as a panel proposal in which I was a panelist.

[7] It even won an award: Second best paper in the experience reports
track.

[8] Among other things, we had not planned for returning students (or
the effects of having returning students) and we found that we had to
modify the instrument midway through the project.

[9] I'll likely muse about the issue in the future.  For now, one idea
is to offer only one camp each summer and make it part of the broader
work of my research team [10].

[10] The odds are that MIST will again take its place as my primary
research project.  A craft of code camp might be a nice pairing to MIST.

[11] Or expectations.

[12] Amazingly, I hear the same thing from almost everyone who works
with ACM.

[14] Also known as the individually mentored curriculum, the open curriculum,
and the no-requirements curriculum [15].  

[15] I've probably missed a few other names

[16] With some effort, I was able to find a time that all but one of
the fifteen-plus people I'd been writing to could meet.  We came up
with some useful ideas. However, the anniversary of the open curriculum
(and the Tutorial) coincides with the demisemiseptcentennial [17]. Looking
back on the scope of the sesquicentennial and the model for how that was
organized, the group decided to pass the responsibility on to Council to
assign a task force.  But there's some likelihood that I'll get put on
that task force [19].

[17] An invented word [18] meaning "175th anniversary".  It's 1/2 of 1/2
of seven hundred years.

[18] Not by me.

[19] The Dean mentioned something about my involvement in the anniversary
in her opening remarks.

[20] I mention the idea of a "curriculum defense" in [one of my musings
on course tags](course-tags-2018-03-30).  I'd like to follow up on that.

[21] The GNU Image Manipulation Program.

[22] Microsoft pronounces that "C sharp".  Unfortunately, they neglect
to note that the character that follows the C is a pound sign [23], #, not a
sharp, &sharp;.  It's also not a Sharpe, but that's a completely different
matter.

[23] Also octothorpe, hash, mesh, and more.

---

*Version 0.2 of 2019-08-30.*
