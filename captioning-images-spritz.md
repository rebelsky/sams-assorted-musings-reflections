Captioning animated GIFs
========================

*Topics/tags: [Teaching](index-teaching), accessibility*

Although I traditionally write most of the assignments for my classes,
this semester in CSC 207, I'm trying an experiment in which I adopt [1]
assignments that one of my colleagues wrote.  While the course is not
"themed" like CSC 151 [2] or CSC 161 [3], the assignments have an implicit
theme of "things you could extend to create personal projects", or at least
I think they do.

[The second
assignment](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC207/2019S/01/assignments/assignment02)
is to create software the supports [rapid serial visual
presentation](https://en.wikipedia.org/wiki/Rapid_serial_visual_presentation),
a speed-reading technique the works by showing one word at a time.

There's an animated GIF that shows how a commercial version of this
technique works.

<img src="images/spritz1.gif" alt="Spritz @ 250 WPM.  We see a sequence of words, one at a time, at the center of the screen, with a letter near the middle of each word colored red and centered between short vertical lines.  The text reads something like the following: ''Welcome to spritzing!  We are starting you out at 250 words per minute, a little over the average reading speed of 220 words per minute.  Don't worry, we'll go faster in a moment.  In fact, people are already spritzing at over 1,000 wpm.  At that rate, you could read a 1000 page novel in about ten hours.  What could you do if you could double your reading speed with the same or better compre- hen- sion?  What if you tripled it?  Our goal is to get the entire world reading with Spritz and have over 15% of the world's textual content read by our method by 2016.''">

I've made a commitment to captioning all of my images with alt text.  My first question was _What alt text should I use?_.  My colleague just used "Spritz @ 250 WPM", which did not seem sufficient to me [4].  A short description of what's happening seems appropriate.

> We see a sequence of words, one at a time, at the center of the screen, with a letter near the middle of each word colored red and centered between short vertical lines.

But there's text in the image that some people may read.  Is it my
responsibility to present that text?  That's not really the focus of
the image.  Unfortunately, something in me said "You should transcribe
the text", and so I did.  It was harder than I thought it would be,
primarily because I had no way to pause or rewind; I just had to wait
until the text repeated.  Here's what I came up with.  You can decide
how well I did.

> Welcome to spritzing!  We are starting you out at 250 words per minute, a little over the average reading speed of 220 words per minute.  Don't worry, we'll go faster in a moment.  In fact, people are already spritzing at over 1,000 wpm.  At that rate, you could read a 1000 page novel in about ten hours.  What could you do if you could double your reading speed with the same or better compre- hen- sion?  What if you tripled it?  Our goal is to get the entire world reading with Spritz and have over 15% of the world's textual content read by our method by 2016.

Getting the segmentation of "comprehension" was particularly hard.  For
some reason, my brain didn't want to identify where the word broke.  Strangely
enough, once I figured out the parts, it's easy to see them.

After I finished transcribing it, it struck me: My colleague
probably didn't create the GIF.  There must be other
copies out there with better alt attributes.  So I went looking.
[ZDnet](https://www.zdnet.com/article/this-app-makes-reading-500-words-per-minute-easy/)
just describes it as "spritz-250-wpm.gif".  Not very helpful.  [Business
Insider](https://www.businessinsider.com/spritz-speed-reader-app-2014-3)
just has "Spritz".  Perhaps even less helpful.
[3Media](http://www.3media.com/blog/spritz-increase-your-reading-speed-to-600-words-per-minute/)
calls it "200wpm".  That's not even the right speed.

I guess I'll stick with my description and transcription.

There's also a question of whether the assignment itself is accessible.
Someone with significant visual impairments would be unable to tell if
they had successfully written the program.  I suppose if I had such a
student, I'd need to figure out an alternative assignment.  I suppose
one option would be something that uses audio output rather than visual
output, perhaps using [FreeTTS](https://freetts.sourceforge.io/).  I'll
deal with that issue if or when it arises.

On the other hand, variants of this assignment might even provide support
for people with partial visual impairments.  I recall talking to one
student with vision problems who said something like "I'd like text editor
in which the cursor stays at the same place, in the center of the screen,
and the text moves by as I type."  I expect that some ambitious students
who completed this assignment could leverage that idea into something
like that student wanted [5].

---

The assignment also included a small usability study.  That made me
ask myself whether IRB approval was required.  And so I sent a note
to our compliance officer to ask.  Fortunately, the answer was that
the study was such that it did not require an IRB proposal.

I've come to the conclusion that because my brain asks about
accessibility, IRB approval, and things like that, I'm much slower at
getting work done.  I don't know what to do about it, but it's clear
that it has an effect.

---

[1] Or adapt.

[2] CSC 151 has had themes of media computation and data science.  This
spring's version will have a theme of digital humanities.  At some point,
we should develop a version with a theme of computing for social
good.

[3] CSC 161 currently has a theme of robotics, using Scribbler 2 Robots
with IPRE Fluke2 boards.  Scribbler 2 robots are no longer made, and
it looks like the IPRE vision of "robots will soon be cheap enough that
each student can purchase their own robot" has not worked out.  I expect
we'll develop a new theme for the course before the robots and boards
we own die.

[4] It is, unfortunately, better than a lot of the alt text I see.

[5] I wonder if that student still wants such an editor.  I wonder 
if anyone else would want that editor.

---

*Version 1.0 of 2019-01-16.*
