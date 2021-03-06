Transferring my digital workspace
=================================

It's break, so I can finally bear to send my MacBook in for repairs.
What repairs?, you may ask.  Well, I seem to be getting warnings about
the battery.  While I most frequently use my Mac while connected to power,
I do want to be able to work without an AC adapter, so That seems to be
an important issue.  The up-arrow key popped off and I've had to tape
it down.  That's an aesthetic issue, but it's also a bit o a pain.  And 
my original charger is broken.  I've bought spares, but if I'm dealing
with the other two issues, I should deal with that, too.

Fortunately, I have a multi-year warranty, although not from Apple.  So
I just spent a day ready to send my MacBook back in.  Fortunately,
I have an old MacBook I can use in the mean time.  But my MacBook is
highly customized to my work style.  I have lots of files I rely on
(e.g., copies of old faculty handbooks, notes on various projects),
scripts I've written (e.g., to batch rename files or to speed up my
programming), and more.

So, what did I do?

I started by trying to clean up my Mac a bit.  I usually have a few
hundred items on my Desktop [1,2].  I got that down to a dozen or so:
that silly sketch I use as an icon, a few files that the CSC 151 sample
programs assume are on the desktop, folders for my spring courses,
my recent Kindle downloads, and a few other things.  I also did some
work to clean out my inbox, but not as much as I should have.  Oh well;
that can be an activity on my interim MacBook.

I also made sure that all of my Macs were updated to the same OS version.
I haven't switched to High Sierra yet, so both are now on macOS Sierra
10.12.6.  For some reason, the Apple Store wouldn't do the update, so
I had to download an updater [3].  Interestingly, once I'd done that, I
did get the option to update some more things [4].

Then I needed to get the interim MacBook ready.  I first started to back
it up to my standard backup disk.  But it appears that Time Machine
could not tell the difference between my interim MacBook and my
current one, since I had previously migrated files from my interim (prior)
MacBook to the current one when I purchased the current one [5].  Hence,
it was trying to compare what was on the old MacBook to the current one.
That's a bad idea.  I renamed the old MacBook and, amazingly, something
decided to rename all of the backups from my current MacBook.  Boy,
that was a pain to fix.  Eventually, I got the names straightened out
and the files backed up from both machines.

I considered a wide variety of ways to get files from my current MacBook
(the one going in for repairs) to my interim MacBook (the one that I
will be using for the next few weeks).  I thought about using Migration
Assistant, since that's one of the recommended approaches.  But I kind
of like to know what's happening with what I'm doing.  For example,
what files would Migration Assistant transfer and what ones would it
leave behind?  That's hard to figure out.  So I decided to use the old
standby of `rsync` instead.  What's `rsync`?  It's a command-line tool
that serves as a kind of Swiss-army knife of file transfers.  While it
was originally designed to synchronize files across a network, it can
also synchronize files across disks.

Should I be storing my files in the cloud instead and thereby avoid the
need to do this kind of copying?  Perhaps.  But I don't really like to
store confidential things, such as department records, in the cloud.  And,
as always, storing things in the cloud also means thinking more about my
organizational structures.  Should I, for example, store my Mac `Library`
directory in the cloud [6]?  Thinking about cloud organization can be another
task for my "organization" week of break.  Note that I do store many of my
most common scripts on GitHub [7].

Where was I?  Oh, yeah, planning to copy files from the current damaged
MacBook to my interim MacBook.  To get used to `rsync`, I started
with some `rsync` commands to make a spare backup of what was on what will
serve as my interim MacBook.  For example,

    time sudo rsync -v /Applications/ /Volumes/Backups/OldMacBook/Applications/

It took 30 minutes to separately back up about 32 gb of applications from
the interim MacBook.  And another 12 minutes to back up about 10 gb of
stuff from `/Library`.  Next, I started to back up my home directory.
That took 2.5 hours.

Along the way, I discovered a variety of interesting things.  I was
using something like 15gb (and 25,000+ files) for a Mac Gimp development
directory that seems to have included a whole or partial macports
installation.  I had installed the Android Development kit at some point,
and it left 2gb of cruft in my Library folder [8].  Even after that,
I had something like 40gb in my Library.  What were the big offenders?
5.8gb for Application Support.  2.3gb for Caches.  Of that, Firefox
is responsible for about 1/3 and Google is responsible for about 1/6.
Interestingly, almost 200 mb were from `com.tinyspeck.slackmacgap.ShipIt`,
which turns out to be Slack.  I don't know why a copy of the Slack
application needed to be in the cache, but I cleared it out.  Oh, 20gb
is for mail [9].  5 gb is for iTunes updates which I'm pretty sure that
I can delete.  Yeah, it may be time to invest some money and time in a
good disk cleaner [10].

Once I'd done all of that, I was ready to copy the files from the current
MacBook back to the interim MacBook.  I booted the current MacBook in Target
Disk mode.  I connected them with a Thunderbolt 2 cable and ... um ...
nothing.  I have no idea why, but I couldn't get the current MacBook to mount
on the interim MacBook.  I thought about a two-step process: First,
use `rsync` to back up the current MacBook to a spare disk.  Then use
`rsync` to get everything on the interim MacBook.  But that seemed like
a lot of work.

So I gave in and used Migration Assistant.  I was right:  I had no
clue what it would and would not transfer and it didn't offer anything
I particularly liked for merging my two `rebelsky` accounts. It asked
whether I wanted to delete the `rebelsky` account on my temporary MacBook,
or create something side-by-side [11].  Given the limited amount of space
on my MacBook [12], that didn't seem like an option.  So I just had it
trash my home directory on the interim MacBook, applications folder,
and anything else it wanted to update.

Transferring the files took 2.5 hours, even though I'd already cleaned
out some of the cruft I mentioned earlier.  After transferring files,
I had to re-enter a lot of registration codes; I'm sure there are many
others I'll have to do in the future.  But the interim MacBook seems to
be working fine, if a bit slower than my normal machine.  Now my primary
work machine is slowly wending its way to the repair shop [14,15].

Are there morals to all of this?  Perhaps.  Here are a few.

* My digital workspace is as complex as my physical workspace.
* Even though I'm supposedly a computer expert [16], dealing with
  system repair issues is time consuming for me.
* I should think about putting more of my stuff in the cloud.
* The cloud is not a magic bullet; one still has to deal with
  applications and more.
* You might look forward to some future musing about something I screwed
  up or forgot during this process.
* I'm dealing with a slower computing environment for the next few weeks. 

Let's hope that I get my primary machine back before the start of the semester.

---

[1] It does often look like my physical desktop.

[2] I like the desktop because it's easy to access from a dialog box with
Command-D.

[3] And then realize that I really needed to download the Combo updater.

[4] With an associated 1.5 gb download.

[5] Used, if it matters.  So calling it "new" is perhaps a misnomer.
It is, however, the newer of the two MacBooks.

[6] The Library stores resources for a wide variety of applications.

[7] If you care, those live at <https://github.com/rebelsky/samr-utils>.
They are not good examples of coding style or utility writing or, well,
anything.  But some, like `ctab`, I use whenever I code.

[8] Okay, I guess that means that my Library folder probably doesn't belong
in the cloud.

[9] That number doesn't scare me as much as it should.

[10] It appears that I bought AweCleaner as part of some bundle.
It identified about 3gb of stuff to get rid of.

[11] Nope, no room for that.

[12] 256 gb, which once seemed like an incredibly large amount [14].

[14] I still remember paying something like $1000 for a 100 MB hard drive
soon after Michelle and I were married.

[14] Apple uses FedEx next-day.  My third-party insurance uses UPS
ground.  But Apple won't cover a machine that's more than two or so
years old, so I'm stuck with the third-party.

[15] How slow is slowly?  It took 24 hours to get from Marshalltown to
Davenport.  It looks like it will take a full week from when I shipped
it to when it arrives at the repair center.

[16] Note the word "supposedly".  I'm not a computer expert.  I just
teach computer science.

---

*Version 1.0 of 2018-01-04.*
