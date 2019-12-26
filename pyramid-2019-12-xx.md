The Pyramid
===========

*Topics: [Autobiographical](index-autobiographical), technology*

In my recent [musing about my undergraduate workload](samr-undergraduate-work-2019-12-28), I
mentioned the Pyramid computer that CS and Math shared.  The Pyramid
was an "interesting" computer; Unix had been developed on DECs, and
the Pyramid was one of the first attempts to run Unix on a different
architecture.

I don't know much about the underlying details of the Pyramid [1], or
why we bought it instead of another DEC [5], but I do have some
memories of the computer.  In that earlier musing, I mentioned two:
We had a weak security model and my abuse of that model got me in
trouble.  Here are a few more.

The Pyramid always crashed the night before OS homework was due
because it couldn't handle the load of student work.  Each time,
the class instructor said something like, "In the real world, you
plan ahead for these kinds of situations" and then took off 10% if
our work wasn't in on time.  My reaction to that policy was to begin
the work the day after it was due; the Pyramid crashed less often so
I was much more efficient, and I often ended up with the same penalty
as my classmates.

The Pascal compiler turned case statements with ranges into way too
many conditional jumps.  For example, `case x of 1..5000` resulted
in 5000 conditional jumps rather than the two or three that
it should have produced.  I'm pretty sure that this design led to
the Pyramid crashing regularly, since you could inadvertently fill 
temporary storage with an ill-designed range [6].

Like most Unix systems, the Pyramid had Emacs.  But it didn't have
real Emacs.  Just as it was a clone of the DEC Unix system, so was
the Emacs a clone of Stallman's classic.  Hence, instead of the
original Emacs or GNU Emacs, we had Gosling Emacs [7].  Since I had
spent the past year or two mastering DEC-20 Emacs, I considered
Gosling Emacs a sin unto Emacs and learned vi instead [8].

---

[1] I see from [the Wikipedia
page](https://en.wikipedia.org/wiki/Pyramid_Technology) that they
were a RISC [2] system as compared to DEC's CISC system [3].

[2] Reduced-Instruction-Set Computer.

[3] Complex-Instruction-Set Computer.  I haven't looked at DEC assembly
for at least two decades, but I recall it being surprisingly close to
a high-level language [4].

[4] Or at least a high-level language for the time.

[5] We did have a DEC-20 running TOPS-20.

[6] I'm perfectly serious about that.

[7] Yes, James Gosling.  How many programmers name their programs after
themselves?

[8] Gosling has done some important work.  I would not include Gosling
Emacs nor the choice to name it after himself.  But what do I know?  I
was probably just an overly opinionated undergraduate [9].

[9] Is that redundant?

---

*Version 0.1 of 2019-12-26.*
