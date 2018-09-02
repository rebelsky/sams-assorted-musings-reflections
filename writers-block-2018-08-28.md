Writer's block
==============

*Topics/tags: [Writing](index-on-writing)*

I write.  I write a lot.  I write email messages to a wide variety
of people.  I write readings [1], assignments, labs, and more for my
classes.  I write recommendation letters.  I write professional papers.
I write daily [2] musings.

Most of the time, writing comes easily.  I sit down with ideas at hand.
If it's a longer piece, I sketch an outline.  If not, I just begin.
I write [3].  I edit.  I put it aside [4].  I come back and edit and
write and revise.  I get feedback [5].  I come back and edit and write
and revise some more.  When things are going well, I generally don't need
to do significant amounts of work once I've gotten the first draft down;
while I refer to them as "rough drafts", they are often relatively smooth
[6].

I have a lot to write.  I need to make progress on materials for the
new digital humanities class.  I have a paper to write for SIGCSE and
another paper to rewrite.  None of this should be challenging to write,
or at least not painful to draft.  These are topics I think about
regularly and models of writing that I commonly follow.

So why did I having trouble writing?

What do I mean by "trouble writing"?  In part, I mean that for the past
three and a half days [7], whenever I sat down to write, I had trouble putting
my thoughts in coherent enough order to even record them in writing [8].
In part, I mean that when I did manage to put those thoughts in order
and then compared what I was writing to things I've written in the past,
I would find that my new writing appeared to lack something in the prior
efforts.  In part, it means that any writing I was able to do seemed to
take longer and feel less enjoyable.

I don't think it's the stress of having things due.  Usually, I do my
most productive [9] writing when I'm working at the last minute.  Give
me a deadline and a page length, and I'm on it.  I love the adrenaline
that accompanies that context.

But it wasn't happening.  I even found myself struggling to muse about
my inability to write.

So I asked myself, "What should I do about it?"  Here are some options
that came to mind [10].

* I could find something else to write about.  Perhaps I just need to
  give my inner writer another thing to write about, and they'll find
  the spirit to get moving on other topics.  But I tried that earlier
  today; I wrote half of a musing about some technical issues.  It
  didn't help me make progress on the things I needed to read.
* I could do more something closer to the traditional form of free-writing.
  Maybe if I turned off my inner editor and let things flow, things would flow.
* I could accept that I'm not going to get things written right now.
  But I do want to submit at least one paper to SIGCSE.  As I've said
  [before](sigcse-2019-planning), I'd like to have my students' work in
  a form that it can be submitted.  And there's another paper that I'd
  like to get off my long-term to-do list.
* I could push ahead, even though it's hard, and hope that things get
  easier as I go.
* I could introspect in order to figure out why I'm having difficulty.
* I could read a bit on something related.  Maybe I've been in "produce"
  mode for too long, and I need to go into something more like "consume"
  mode.
* I could employ one of my common paper-related time-wasting activity.
  That is, I could set up the online writing environment, make sure that
  I have files and macros and such all prepared, and so on and so forth.
  Come to think of it, I need to do that anyway, not only for the SIGCSE
  papers, but also for the broader CSC 151 project [11].
* I could muse about the issue.  However, as I noted, even this musing
  seems to be a challenge.

Putting together the list helped a bit.  Once I finished
listing options I sat down to do the "trivial" stuff; I created
a new repository for each paper, I downloaded the new [ACM LaTeX
template](https://www.acm.org/publications/proceedings-template).
I prepared the set of files I like to put together for a LaTeX paper
for SIGCSE [12].  Then I started filling in the various files.  I copied
and pasted the abstract.  I wrote a new set of keywords.  I gathered a
few appropriate pieces for the bibliography.  Finally, I started in on
the outline.  The outline, in particular, seemed to get my brain flowing.
While I didn't write anything close to a smooth draft, thinking about
the structure of each paper also meant that I thought about what to put
in each section.  So, for the first paper I started, I was able to get
some writing done.  That helped me do a bit on the second.  What about
the previous article that I was trying to edit?  I did not have time for
that one.

Unfortunately, I spent about five or six hours today on non-productive
work.  So, even though I worked a relatively long day, I did not make
as much progress on my writing as I'd like.  I'm now tired enough that I
don't think I'll write all that well.  But at least I've broken through my
writer's block.  At least I hope I have.  I'll see how much progress
I actually make tomorrow.

Fingers crossed!

---

Postscript: I had originally tagged this musing as "short".  But it
certainly did not end up that way.

---

[1] Perhaps "readings" is not the best word.  Would "narrative technical
material" or "short instructional sections" be better?  I've used "readings"
for a decade or more; I'll stick with that term for now.

[2] More or less.

[3] More accurately, I engage in my typical model of simultaneously
writing and editing.  That is, I start trying to do something more akin
to free writing.  But I tend to stop every few sentences and think about
where the sentences belong, about some issues of wording, or whatever.
If there's an outline in place, I tend to jump around a lot, adding different
paragraphs in the section that feels right at the time.

[4] Well, I don't always put things aside, particularly not email and
musings.

[5] That happens less frequently than I'd like, but I can pretend.

[6] If you are regularly read my musings, you have some sense of my
smooth "first draft" style.  In many cases, the things I post correspond
to what I would consider first drafts for a more professional paper.
Maybe they're a bit rougher.  On occasion, they're a bit more polished.
Most frequently, though, they correspond to my normal "close enough for
most situations" writing.

[7] Since I finished the [abstracts for SIGCSE 2019](sigcse-2019-abstracts),
more or less.

[8] The same may be said of the sentence.

i9] Although not necessarily my best.

[10] I wrote about them in the present tense because I wrote them while
I was stuck.  I've left them in the present tense, even though I've
moved much of this musing to the past tense, because remain strategies
I can use.

[11] However, the CSC 151 project still needs to wait on my decision about
the formatting system(s) to use for that project.

[12] Let's me see.  Since I use multiple files, I generally create a
`Makefile`.   The ACM LaTeX format requires `ACM-Reference-Format.bst` and
`acmart.cls`.  I tend to create two "master" files, one for the version
that includes the authors (`main.tex`) and one for the anonymous version
(`anonymous.tex`) [14].  Each of those files then includes a common
abstract (`abstract.tex`), body (`body.tex`), list of ACM descriptors
(`ccsxml.tex`), and set of keywords (`keywords.tex`).  They may have
separate bibliography files (`main.bib` and `anonymous.bib`), since
I'm supposed to anonymize references to our own work.  They may
have separate acknowledgments files (`acknowledgments.tex` and
`acknowledgments-anonymous.tex`).  I think that covers the gamut.

[14] I may not need a version with authors.  But something in the back
of my head says that I have to submit both an anonymous version and an
attributed version.

---

*Version 1.0 released 2018-08-28.*

*Version 1.0.1 of 2018-09-02.*
