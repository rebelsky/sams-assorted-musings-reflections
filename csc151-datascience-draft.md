A draft description of the new CSC 151
======================================

About two decades ago, John Stone and Henry Walker restructured CSC
151, the introductory course in Grinnell's sequence.  It had been a
workshop-style [1] Pascal course and they turned it into a workshop-style
Scheme course.  That course existed in various forms for about a decade.
And then about a decade ago, Janet Davis and I reworked the course to do a
form of media computation, using Scheme in conjunction with the GNU Image
Manipulation Program [2].  We had intended to offer multiple versions of
CSC 151, and allow students to select which version to take.  However,
it's worked better to offer nearly-identical sections each semester so
that experienced faculty teaching the course can mentor younger faculty
teaching the course.

But it's come time to develop a new version of the course.  In conjunction
with the College's new Data Science Initiative, my students and I [3] will
be developing a new version of CSC 151 that focuses on data science.  Along
the way, we will also be changing the teaching model from four fifty-minute
classes per week to three eighty-minute classes per week [4].  

But since we have a new version, I need to write a new description.  Let's
see ... Here's the current description.

> CSC 151-01 & 02 - Functional Problem Solving (Media Scripting)  
> 4 credits (Fall and Spring)  
> In this section of CSC 151, we will ground our study of functional problem solving in media computation. In particular, we will explore mechanisms for representing, making, and manipulating images. We will consider a variety of models of images based on pixels, basic shapes, and objects that draw. The course will be taught using a workshop style: In most class sessions, students will work collaboratively on a series of problems. Includes formal laboratory work.

So, what should the new version look like?  The first sentence can be similar, substituting "data science" for "media computation".  The second sentence needs some context for what data science is.  What does Wikipedia [5] say?

> Data science, also known as data-driven science, is an interdisciplinary field about scientific methods, processes and systems to extract knowledge or insights from data in various forms, either structured or unstructured,[1][2] similar to Knowledge Discovery in Databases (KDD).

'Eh.  I don't think I want to use that form.  Oh, look!  If I bother to read
further on Wikipedia, I learn that

> When Harvard Business Review called it "The Sexiest Job of the 21st
Century"  the term became a buzzword, and is now often applied to business
analytics, or even arbitrary use of data, or used as a sexed-up term
for statistics. While many university programs now offer a data science
degree, there exists no consensus on a definition or curriculum contents.

Okay, I guess that means I'm free to define it how I want, within reason.
I'll probably focus on the activities we do.  The next sentence in the
current description focuses on image models.  I can probably talk about
kinds of data instead.  And then I can steal the last sentence.

> CSC 151-01 & 02 - Functional Problem Solving (Data Science)  
> 4 credits (Fall and Spring)  
> In these sections of CSC 151, we will ground our study of functional problem solving in problems grounded in data science.  In particular, we will consider mechanisms and processes for gathering, reorganizing, filtering, combining, analyzing, and visualizing data.  Along the way, we will consider numeric, textual, and geographic data. The course will be taught using a workshop style: In most class sessions, students will work collaboratively on a series of problems. Includes formal laboratory work.

Hmmm ... That was easier than I thought.  I was dreading writing it,
but I got it done relatively quickly.  But I should be sensible, and
think about how to improve the text.  Let's see ... How do I feel about
"functional *problem* solving in *problems* ..."?  That's a bit redundant,
isn't it?  I'll need to think a bit more about that issue.  I'm not sure
how I feel about all of the "ing" forms [6].  I may want to make those
a bit more active.  How do I feel about the passive voice in "will be
taught"?  I'm having trouble coming up with another way to phrase it, but
I'll try something else just to think through it.  On to version two.

> In these sections of CSC 151, we will ground our study of functional
problem solving in approaches related to the practice of data science.
In particular, we will explore and develop algorithms and programs
that gather, reorganize, filter, combine, analyze, and visualize data.
Along the way, we will consider numeric, textual, and geographic data. The
course employs a discovery-based format: In most class sessions,
students will work collaboratively on a series of problems. Includes
formal laboratory work.

I stole "discovery-based" from the Physics department [7].  I'm trying
to decide whether or not I like it more than "workshop-style", "flipped",
"active learning", "flipped", or whatever.  I prefer "explore and develop
algorithms and programs" to "consider mechanisms and processes", although
I worry a bit about the repeated "and".  Do I need the "Along the way"?
Do I want to add other kinds of data?  Or maybe fewer?  Perhaps just
"structured and unstructured".  And then I can use that in the one
central sentence.  Let's give that a try.

> In these sections of CSC 151, we will ground our study of functional
problem solving in approaches related to the practice of data science.
In particular, we will explore and develop algorithms and programs
that gather, reorganize, filter, combine, analyze, and visualize both
structured and unstructured data.  The course employs a workshop format:
In most class sessions, students will work collaboratively on a variety
of problems.  Includes formal laboratory work.

Do I like "work collaboratively"?  I could write "collaborate", although
they won't really collaborate on problems.  I could revisit the previous
sentence and say "collaboratively develop algorithms and programs", but
that seems long.  Perhaps "collaboratively explore".  I might also add
"data sets".  

> In these sections of CSC 151, we will ground our study of functional
problem solving in approaches related to the practice of data science.
In particular, we will explore and develop algorithms and programs
that gather, reorganize, filter, combine, analyze, and visualize both
structured and unstructured data.  The course employs a workshop format:
In most class sessions, students will collaboratively explore a variety
of problems and collections of data.  Includes formal laboratory work.

Okay, that's about as far as I can get on my own.  What does
[Grammarly](https://www.grammarly.com/) say?  It identifies one "critical
issue" and one "advanced issue".  What's the critical issue?  It thinks
that I should say "Problem-solving" rather than "problem solving".
I think it's wrong.  There's no reason to capitalize.  Hyphenation might
be necessary if I wrote "problem-solving approaches", but adjectives are
right associative, so "functional problem solving" should be correct.
But let's see what Google says in response to the questions "Should one
hyphenate problem solving?" and "Should one hyphenate problem-solving?"
The staff of _Writer's Relief_ [8] note the following.

> Rule 2: If the compound adjective comes after the noun it describes, no hyphen is needed.

> Example 4: On Monday, Mrs. Thomas taught her class many skills, including problem solving.

> Since problem solving follows the noun (skills), no hyphen is needed.

Similarly, Mark Nichol of _Daily Writing Tips_ writes

> Many writers insert a hyphen in “decision making,” “problem
solving,” and the like, though such treatment is justified only when
the compound modifies a following noun (“decision-making apparatus,”
“problem-solving skills”). However, similar noun+verb compounds,
like eye-opener, are valid.

Do I want to know what Grammarly thinks the advanced issue is?  Sure.
Let's do a temporary upgrade to see how helpful it is.  Ah, it doesn't
like "Includes formal laboratory work" since there's no subject.  
Welcome to the world of course descriptions!

Now, let's move on to [the Hemingway
Editor](http://www.hemingwayapp.com/).  I can tell in advance that it
will be unhappy with that long sentence I just crafted (too long to be
easily readable), as well as with "collaboratively explore", since it
doesn't like adverbs.  But let's see.

Well, I was right that it highlighted "collaboratively".  But it notes
that I have only one adverb, which meets the goal of three or fewer
for a piece of this length.  It notes no uses of passive voice.  I guess
it was good that I looked at that one.  It suggests no simpler phrases.
It says that no sentences are hard to read.  It says that no sentences
are very hard to read.  It's readable by someone in the eighth grade.

Wow, both tools were spectacularly unhelpful.  Or maybe my writing is
just acceptable "as is" [10,11].

---

In case you missed it, here's the full final version of the 
description.

> _CSC 151-01 & 02 - Functional Problem Solving (Data Science)_  
> _4 credits (Fall and Spring)_  
> _In these sections of CSC 151, we will ground our study of functional
problem solving in approaches related to the practice of data science.
In particular, we will explore and develop algorithms and programs
that gather, reorganize, filter, combine, analyze, and visualize both
structured and unstructured data.  The course employs a workshop format:
In most class sessions, students will collaboratively explore a variety
of problems and collections of data.  Includes formal laboratory work._

---

[1] Aka "flipped classroom", although no one used that term at the time.

[2] "GIMP" may be one of the worst acronyms ever.

[3] And maybe a colleague.

[4] The new course schedule guidelines passed by the faculty a few
years ago make it very hard for a department to offer a lot of courses
in the four-by-fifty model.  Math, which also relied on that model,
has successfully converted those courses to the three-by-eighty model.
Our job is a little more complex because we write a daily reading and
lab for each class.

[5] <https://en.wikipedia.org/wiki/Data_science>

[6] I have trouble remembering the term "gerund", or even exactly when
it applies.

[7] <https://www.grinnell.edu/about/offices-services/academic-advising/publications/registration-suggestions/physics>

[8] <http://writersrelief.com/blog/2008/03/hyphen-rules-dont-let-misused-hyphens-muddle-your-adjectives-or-your-writing/>

[9] <http://www.dailywritingtips.com/hyphenation-in-compound-nouns/>

[10] As I say, "workmanlike".

[11] I also spent some time editing.

---

*Version 1.0 of 2017-03-20.*
