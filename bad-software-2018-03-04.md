Bad software
============

Each of our classrooms has a projection system.  It used to be that the
projection system used a purely physical interface to connect the computer
on the podium to the projector.  But we have multiple inputs and someone
in ITS [1] decided it would be much better to have a software-based system.
That way, for example, they could monitor and fix problems remotely.

About four years ago, we got new interfaces between the computers and the
projectors.  They made some strange decisions at the time.  For example,
even though VGA was clearly on its way out, they chose to use VGA rather
than, say HDMI.  That means that we've had to continuously find and
replace dongles for all of our classrooms.  And the fancy touch-screen
user interface never seemed to work quite right all of the time.
Worse yet, it wasn't consistent.  In particular, the configuration in my
primary classroom (3813) was different than it was in other classrooms.
So, when I arranged my window and font sizes for my primary classroom,
it didn't work well in the other classrooms, and vice versa.

This past summer, they decided to "upgrade" the system in 3813 to use
HDMI.  I thought it was a good thing.  But then I discovered that whoever
designed the UI apparently never bothered to take a user-interface design
course, the contractors who installed the system apparently didn't bother
to test it, and it seems to me like we got a lemon of a system.

Let's start with the old one.  In the old software-based system, you'd
click the input you wanted (Mac, PC, laptop, or DVD player), click
the On button, and then wait a few minutes for the projector to start.
In the new system, you click the input button (again, Mac, PC, laptop,
or DVD player).  Then it asks "Do you also want to turn the projector on?"
So you click "Yes".  But it's a strangely designed modal dialog [2],
so after clicking "Yes", the dialog stays up until you hit "OK" [3].
Then it waits two minutes, about long enough for the projector to actually
start up, and then puts up a new modal dialog that says something like
"Wait for the projector to start".  So what used to be two button clicks
has now ended up being four button clicks [4].  And for no clear purpose.

It that's not enough, not all of the dialogs are even correct.  You may
recall that I said that they switched from VGA to HDMI.  So what happens
when you click the "Laptop" button?  It asks whether you want to use VGA
or HDMI.  But there's no VGA input.  So why have that question?  "Bad
programming", is that I'm told.  It's senseless.

The first time I tried to use the VGA connection to my laptop, a 15"
MacBook Pro, the color scheme was off.  Way off.  And it wasn't just
off on the projector; it was also off on the monitor.  ITS [5] came in
to look at it.  They couldn't figure it out.  We decided to leave it
as a winter break project.  At some point, they figured out that the
Macintosh HDMI output does not match the HDMI input the system expects.
Couldn't our contractors have tested the system with real computers?
It appears not.  So, even though my Mac has an HDMI output, I'm *still*
stuck using a dongle.  Let's hope it doesn't disappear from the room.

I might put up with all of this if the system worked well.  But it's
become even less reliable than it used to be.  I'd say that the odds
are about one in three that something will go wrong.  This past Monday,
I arrived in my classroom fifteen minutes early.  I made sure that
it was on the PC and hit the enter key.  Nothing showed up on the
monitor or the projector.  I switched to the Mac, and while the Mac
showed up on the monitor, nothing showed up on the projector.  So I
rebooted the PC.  It eventually showed up on the monitor [6], but not
the projector.    Then I turned the projector off and on.  That had the
great effect of making the monitor stop working with the PC and didn't
fix the projector.  At that point, I had reached the start of class.
I called ITS.  Someone from ITS came.  They also turned the projector
off and on.  It made no difference.  They called someone else from ITS.
They turned the projector off and on and moved the cart.  That fixed it.
But it ended up wasting ten minutes of class time.

I've had lots of other problems with the system.  The "Mute Image"
button doesn't work [7].  They've had to physically reboot the hardware part
of the system at least twice [8].  At some point when they rebooted it,
the resolution changed and we have not been able to get it back to the
old resolution.  I don't know why they don't just accept that we got a
lemon and ask the vendor to fix it.

I should note that while this situation is bad for me and my students,
it's equally painful for ITS.  They get regular "tickets" from me about
problems.  And it appears that the system is not easy to debug.  Worse
yet, it sounds like the folks called upon to support the damn system
may not have recommended it.    And a system that reports that the software
is correct, but ony works when you re-download the same software, is not
something I'd want to have to deal with.

I'm not sure what's worse, having to use bad software or having to
support bad software.

But I do really wish that the software we bought made my life easier
rather than more difficult.  I don't relish having to get to class fifteen
minutes early each day to make sure that the software works.

---

[1] DT

[2] A modal dialog box is one that you must respond to before you can
do anything else.

[3] Or maybe "Close".

[4] I used one of the old systems today.  It turns out that I was wrong.
Those systems also require a complex sequence.  First you tap the screen
to get out of sleep mode.  Then you click the system you want.  Then a
new screen shows up that says "Please wait while the system starts
up."  You can click *anywhere* on it.  That's still significantly better 
than having to click a "Close" box repeatedly.

[5] Well, the A/V Center, but they are part of ITS.

[6] You know how I said they never checked the laptop connection with a
Mac?  I'm pretty sure they never checked the PC connection with a Linux
box.  Some signals that should be sent back and forth aren't.

[7] My experience in reporting the problm:  I waited two
weeks. Eventually, they said said "The programming is correct".  I waited
to see if they did anything else.  So I said "But it doesn't work."
They said "This is the second room we have had in which image mute stopped
working and programming was correct. Visited the other room yesterday
and resent programming and image mute worked once programming was sent
again. Visited this room this morning and did the same. Image mute is
working now."  If the program needs to be re-downloaded, then I would
say that the program is *not* correct.

[8] Rebooting the physical part requires someone to unscrew the back of
the podium.  I hope that re-downloading the program doesn't.

---

*Version 0.96 of 2018-03-07.*
