Frustrated with fonts and formatting
====================================

*Topics/tags: [Rants](index-rants), typography, marketing, long, rambly*

Late in the spring, I spent some time [updating my workflow for digital
memos and letters](joc-letterhead) to accommodate the College's revised
typeface choices and wordmark.  I thought I had things the way I wanted
them.

Then I decided to submit a sample to Communications
[1].  In doing so, I realized that I should probably use
[Renner\*](http://indestructibletype.com/Renner.html) rather than
[Josefin Sans](https://fonts.google.com/specimen/Josefin+Sans) as
a substitute for Futura, even though I liked the latter font more.
Renner\* is closer to Futura.

Of course, Renner\* had an "a" that I don't like and didn't have
monospaced numbers.  But it's an open font, so I could feel comfortable
changing it.  And I did, creating a font that I called RennerAlt.
Making a variant was less complicated than I thought it would be.
[FontForge](http://fontforge.github.io/en-US/) was remarkably easy to use.
I felt good.

Amazingly, Communications approved my design except that (a) they wanted
me to make my left margin align to the left edge of the "G" in the
wordmark, and (b) they wanted me to use ragged-right (aka left-justified)
text.  I appreciated the general approval, particularly because the
letterhead had my personal Web site rather than the `grinnell.edu`
that I refuse to use [2].

Then things started to go wrong.

Most importantly, `html2ps` would randomly crash on body text (in
[Besley\*](http://indestructibletype.com/Besley.html)) with a "G", but
only on Linux and not on my Mac.  (My Mac has a slightly older version
of Ghostscript.  Does that make a difference?).  And it didn't crash on
every "G", only some.  Is that an issue with the design of Besley\*?
I don't know.  It may mean that I have to change the choice of typeface.
It's frustrating.  And it's one of those bugs that comes and goes.

What about the suggestions from Communications.  I like fully
justified text, so I'm ignoring the request to use ragged-right.
But it seemed reasonable to try the wider left margin.  Unfortunately,
`html2ps` does not behave sensibly.  First, I tried adding a `margin-left`
entry to the `body` tag.  That made no difference.  Next, I added
a `margin-left` entry to the paragraph tag.  That made no difference.
Just to make sure that I was getting the term right, I tried `margin-left`
with `blockquote`.  That worked.  I can't tell why it doesn't work with
the others.  But I don't want to use an extra blockquote around the body;
that's inelegant and incorrect.  So I kept trying.

Eventually, I discovered that I could add `margin-left` to a magic
`@page` style entry.  That worked.  But it did some strange things to
the encapsulated PostScript file I included as it attempted to fit it
into the new width.  So I had to change that file, which I did mostly
by experiment.  I didn't like 1.5-inch left margins [3] because they
felt too large. I decided that I'd reconsider whether or not to
follow that recommendation.

You think those would be enough problems.  But they weren't.  While things
looked great on screen, when I printed out the letterhead and showed it to
a colleague, the first thing they asked was "Why are there these white
spots where bars cross; is there an xor of sorts?"  It appears that the
printed Renner\* has a problem in the locations where portions of
the letter cross.  It happens only in the printed copy, not onscreen [4].
It happens with both the original version and my alternate version.

I asked myself, "Is it time to go back to the drawing board, or at least
back to Josefin Sans?"  But summer hit, so my decision was simply to leave
all of the problems until later.

"Later" finally arrived this fall.  I had a new memo to
write, and I decided that it was worth a bit of time to play
with fonts and perhaps even with document spacing.  [Industrial
Type](http://indestructibletype.com) has upgraded and renamed Renner\*.
It is now [Jost\*](http://indestructibletype.com/Jost.html).  There are
many more variants available, including nine weights in the standard
version and even more if one is using new OpenType technologies [5].

I was hopeful at first.  Jost\* supposedly includes an option for the
simpler "a" that Futura uses.  It also has the monospace numbers that
I want, which it calls "tabular numbers".  However, for some reason
that I cannot understand, my workflow did not work with Jost\*.  It may
have been a naming issue.  It may have been something else.  But I kept
having problems with one of the faces I used.  Eventually, I decided
to create versions with alternate names; for some unknown reason, that
approach worked.

I like Jost\* more than Renner\*.  I may be able to stick with it.
If not, at some point, I'll probably design my own alternative to Futura.
I plan to call it Pastura.

What about that wider left margin?  Let's see what I can do about that.
Currently, the left and right margins are 2.5cm [6].  That means that the
text width is 8.5in - 5cm, or about 6.53in.  If we
switch the left margin to 1.5 inches and the right margin to 1 inch, we
end up with a text width of 6 inches.  I initially guessed that I would
need to inversely scale the width of the bounding box for the Encapsulated
Postscript.  That bounding box is 536 units wide.  My calculations suggest
that I need a bounding box that is 583 units wide, or 47 additional units.

Nope.  That scaled the wrong direction.  Okay, let's try a bounding box
that is 492 wide (536 x 6/6.53), or 44 fewer units.  Yup, that
seems to get the sizes right.  Now, what about placement?  I know!
I'll temporarily add a vertical line that expands beyond the header and
into the document.  That will help me do the alignment.  Wow!  That was
much more efficient than the last time I tried it.

Does it look right?  Let's compare it to the sample document that I
received from Communications [7].  My simulation is close, but not 
perfect.  But I now have enough tools to play with the margins and 
such that I think I could achieve something closer to their example.
However, it appears that they are using a 9pt font and both the left and
right margins are 1.5 inches [8].  As much as I'd like to be a team
player, I'm not willing to use a 9pt font, nor am I willing to use a
1.5-inch right margin.

Hmmm ... If I'm willing to make those compromises, can I make others?
What if I shift the laurel leaf left a bit?  As long as I've aligned
the text with the left edge of the "G" in Grinnell, I should be fine.
Maybe a left margin closer to 1.25 in, with the laurel leaf shifted
appropriately, will work.  Here's the current state of my sample,
including the vertical line I am using for alignment [9].

<img src="images/rebelsky-letterhead-aligned" width="600" alt="The start of a memo.  It includes a laurel leaf at the top left and a vertical red line that shows the alignment of various parts.">

Here's an example I got from Communications.

<img src="images/college-letterhead-example" width="600" alt="The start of a letter that illustrates the Grinnell letterhead.">

Are they close enough?  The typefaces are different but similar enough
to meet our goals.  I am using a slightly heavier weight, medium rather
than book.  My first inclination was to say "that's okay".  However,
on second thought, I'm going to fix that.  My left margin is a bit
smaller, but not annoyingly so.  My right margin is certainly smaller.
However, that's a decision I've made intentionally, as are the fully
justified margins.  I can tell the difference between the 9pt and 10pt
typefaces, and I do prefer the 10pt.  It looks like the red of
the laurel leaf is slightly different.  I've used `{ 0.854902 0.160784
0.109804 setrgbcolor }`.  Is that correct?  What does [our visual language
page](https://www.grinnell.edu/about/offices-services/communications/brand/visual-identity)
say?  In standard RGB, Grinnell Red is (218,41,28).  Yes, that translates
to those percentages.  Oh, that's right; I grabbed the percentages from
the SVG file: Of course they are correct.

It appears that I now have something I'm relatively happy with and that
matches enough of the new stationary standards that it sufficiently meets
the goal of a common look and feel [10].  I'll take that as a success.

---

[1] I'd rather be straightforward about what I'm doing.

[2] When they let me put personal content, such as these musings, on
`grinnell.edu`, I'll reconsider that choice.

[3] The left edge of the "G" in the wordmark is approximately 1.5 inches
from the left edge of the page.

[4] Now that I'm examining the problem a few months later, it appears
to have happened in the onscreen version, too.

[5] I'm not.  I also don't need very many weights at present.

[6] I didn't choose the 2.5cm margins; they seem to be the standard defaults
in `html2ps`.

[7] I appreciate their willingness to share a sample letterhead with
me.  I do, however, wish that our official _Style Book_ was ready.

[8] The size of the right margins are hard to tell in a ragged-right
example.

[9] Yes, it will go away in the future.

[10] It meets those goals better than most of the official documents I've
seen from the College in the past three months.

---

*Version 1.0 of 2018-09-23.*
