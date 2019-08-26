Proto musings: Coding experiences
=================================

*Topics/tags: [The joy of code](index-joc), Facebook memories, short*

A little bit ago [1], Facebook popped up with an old post.

> July 19, 2011

> This afternoon, I'm trying to hunt down my latest heisenbug. This
is a fun one. It's in a GIMP plugin I'm writing. It crashes when run
normally. It crashes at the same point with a malloc error when run
through gdb. It runs fine through valgrind. At least I've learned how
to use gdb and valgrind on GIMP plugins.

That paragraph feels a bit like the start of a musing, or at least what
passes for one of my musings these days.  How does it differ from one of
my current musings?  It lacks an introduction that gives context.  It lacks
endnotes [2].  It's ... what's the word? ... oh, that's right: brief.

But we can address those issues.

First, let's work on the backstory.  In summer 2011, I was likely working
on a new version of the "mediascheme" course.  The focus of that course
was writing programs to make images.  The course had been going on for
a few years at that time, but, if I recall correctly, we were trying
to move from the custom UI we had developed to a system in which we
could use the official DrRacket editor [3].  The primary plugin we were
working on was to allow DrRacket to communicate with the GIMP.  I learned
a lot about interprocess communication using DBus [4].  But getting things
right was hard; the project required a lot of translation between different
representations of data [5].

But, well, it's hard to write correct code, especially when you're
not only dealing with the interaction between different systems (Racket,
Gimp, DBus), but they are systems that you don't completely understand.
And, well, C is a language that makes it easy to get things wrong.

I tend to debug my C programs with gdb, the GNU [6] debugger [7].
But you usually debug programs by starting them with gdb, and plug-ins
run as separate processes.  So I learned how to attach gdb to a running
process [9]  But sometimes a debugger isn't enough; sometimes you need
to understand how memory is being used.  At the time, I used valgrind to
help with that [10].  I cannot recall how I managed to get valgrind
involved.

Where was I?  Oh, that's right, I was attempting to turn the proto-musing
into a real musing. I suppose I should have put the explanations of gdb
and valgrind in endnotes [12].  I'm just left to explain "heisenbug".
I tend to use the term to describe a bug that goes away when you try
to isolate it, most typically with a debugger or memory profiler or
something like that.  It doesn't quite fit with Heisenberg's Uncertainty
Principle [14], for which it is named, because we're not trading off
two observations.  Still, it borrows the idea that certain kinds of
observation can affect your results.

How am I doing on the broader project?  Background? Check.  Endnotes?
Check [15].  Length?  It's certainly much longer.  I guess I'm done.
I had fun.  I hope you did, too [16].

---

Postscript: I almost forgot; many musings now include postscripts.  I
suppose I should include one of those, too.

---

Postscript: I couldn't find a way to fit it into the musing [17], but
it seems worth mentioning that during my sabbatical I plan to attempt
one more rewrite of the media computation curriculum, this time without
Gimp [18].  We'll see how it goes.

---

Postscript: I suppose I should have done a bit of editing, too.  I rarely
use "this" as a pronoun.

---

[1] Okay, it was about a month ago.

[2] Or are these footnotes?  There's only one "page", so it's hard to
tell the difference.

[3] There's a small chance that it was the transition from  our first
custom editor to our second, but I don't think so.

[4] DBus is an inter-process communication mechanism available on some
flavors of Linux that, in effect, lets you do inter-process procedure
calls.

[5] There's even a chance that I had to deal with endian-ness.

[6] GNU is a recursive TLA for "Gnu's Not Unix".  GNU software is at
the root of most versions of Linux.

[7] Well, at the time, I used GDB.  These days I sometimes use lldb [8].

[8] I still wish I remembered the name of the debugger I used in
grad school.  It even had a theme song, which included the chorus,
"It's the best damn debugger that there's ever been."  I recall enjoying
that debugger more than any I've used since.

[9] At least that's what I recall.

[10] I also mispronounced it as "val grind".  However, it turns out that
it's pronounced differently [11] because it's named after something from
Norse Mythology.

[11] Sorry, I'm not good at spellings that help give the phonemes.

[12] At least the explanations had notes.

[14] If I recall correctly, the principle states that if you can precisely
determine the velocity of a particle, you cannot precisely determine
the position, and vice versa.

[15] Or maybe check-minus.

[16] Although I doubt it.

[17] Or, more precisely, I was too lazy to fit it into the musing.

[18] Whoops!  I never explained what the Gimp [19] is.  It's the GNU [20]
Image Manipulation Program, an open-source alternative to Adobe Photoshop.

[19] Or GIMP.

[20] Remember that TLA?

---

*Version 1.0 of 2019-08-15.*
