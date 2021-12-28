---
title: Cite the damn source!
number: 1176
tags: [CSC151](index-151), [academia](index-academia), excessive quotations
blurb: What am I doing wrong?
version: 1.0
released: 2021-12-27
current: 
---
Today I wrapped up grading for the semester.  I'd written a long
commentary about the amount of work I had to do.  However, for
perhaps the first time ever, I decided to cut part of the musing
because it wasn't all that relevant.  For reasons that I may discuss
elsewhere, I ended up grading and regrading some assignments during
finals week.  I want to focus on one part of one CSC-151 [1] assignment
that frustrated me.

I suppose I should start with some background.  CSC-151 is currently
digital humanities [2], or at least text-based digital humanities.
In a [relatively early
assignment](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2021Fa/assignments/mp03.html),
we ask students to do a simple form of sentiment analysis.

Here's the text.

> **_Part the third: Sentiment analysis_**

> Another common approach to text analysis is called "sentiment
  analysis". Broadly, sentiment analysis is intended to determine the
  writer’s overall sentiment in a piece of writing. Are they happy?
  Sad? Angry? Enthusiastic? Rumor has it that Amazon uses sentiment
  analysis in selecting reviews to prioritize and for other things,
  too.

> The most straightforward form of sentiment analysis involves
  looking at word frequencies. A document with more positive than
  negative words is likely to be interpreted as positive. A document
  with more negative than positive words is likely to be interpreted
  as negative.

> Conveniently, there are two long lists of positive and negative words available to you.

> > <http://ptrckprry.com/course/ssd/data/positive-words.txt>

> > <http://ptrckprry.com/course/ssd/data/negative-words.txt>

> **Please read the notes at the top of those files before you use them.**

> Document and write a procedure, `(posneg str)`, that takes a string as an input and returns the string `"positive"` if the percent of positive words is at least 5% higher than the percent of negative words, the string `"negative"` if the percent of negative words is at least 5% higher than the percent of positive words, and the string `"neutral"` the rest of the time.

Doesn't sound too bad, does it?  At this point in the assignment,
they should have written a procedure that converts a string into a
list of words, a procedure to read words from a file, and a procedure
to count how many words in one list appear in another list [3].

You may note that there's a boldfaced piece of text in the assignment.
It asks them to look at the files before they use them.  

How do the files begin?  Let's take a look at the positive words file.

> ```
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Opinion Lexicon: Positive
;
; This file contains a list of POSITIVE opinion words (or sentiment words).
;
; This file and the papers can all be downloaded from
;    http://www.cs.uic.edu/~liub/FBS/sentiment-analysis.html
;
; If you use this list, please cite one of the following two papers:
;
;   Minqing Hu and Bing Liu. "Mining and Summarizing Customer Reviews."
;       Proceedings of the ACM SIGKDD International Conference on Knowledge
;       Discovery and Data Mining (KDD-2004), Aug 22-25, 2004, Seattle,
;       Washington, USA,
;   Bing Liu, Minqing Hu and Junsheng Cheng. "Opinion Observer: Analyzing
;       and Comparing Opinions on the Web." Proceedings of the 14th
;       International World Wide Web conference (WWW-2005), May 10-14,
;       2005, Chiba, Japan.
;
; Notes:
;    1. The appearance of an opinion word in a sentence does not necessarily
;       mean that the sentence expresses a positive or negative opinion.
;       See the paper below:
;
;       Bing Liu. "Sentiment Analysis and Subjectivity." An chapter in
;          Handbook of Natural Language Processing, Second Edition,
;          (editors: N. Indurkhya and F. J. Damerau), 2010.
;
;    2. You will notice many misspelled words in the list. They are not
;       mistakes. They are included as these misspelled words appear
;       frequently in social media content.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
> ```

Yes, that's right, the files begin with an explicit request that you
cite the authors of the word lists.

The request to cite should not surprise my students.  Grinnell makes
academic honesty, including proper citation, part of Tutorial, a course
every Grinnell student takes [4].  Tutorial students even have to sign a
statement that they have read and understood our policy.

> I have read the Grinnell College policy on academic honesty.  I
  am aware of the importance of citing properly, reporting findings
  accurately, and collaborating ethically.  I am also aware of the
  potential consequences if I fail to live up to these expectations
  [5,8].

Because citation and reuse are important issues in computing, I
also require students to read [my statement on academic
honesty](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2021Fa/handouts/academic-honesty)
and [the CS department's statement on academic
integrity](https://www.cs.grinnell.edu/policies/academic-integrity.html).
And every code file I distribute for them to modify includes a
section for acknowledgements [11].

But just to be safe, I also make it clear in the rubric for the 
assignment, which students receive.

> ```
[ ] In part three, cites the positive-words and negative-words files.
```

I bet you can tell where this is going, particularly given the title of
the musing.

I thought maybe one or two students would forget to cite these
sources or would cite them incorrectly [12].  However, many more
than one or two failed to cite; some even failed to cite on their
redos, including some of my best students.  

I found myself screaming "_Why can't you cite the damn source?_"  Well,
maybe not screaming, at least not out loud.  But I was frustrated.

However, that's not the right question.  The right question may be
"_Given all of this infrastructure, why don't students cite the
source?_" Some are probably overwhelmed enough by the assignment
that they skip over parts.  Pause. Correction.  I know that some
skip over parts; I can see it elsewhere in their work.  This course
may be the first time they've seen a rubric along with an assignment,
so it may be that some of them don't read the rubric.  The Internet
culture also encourages reuse but does not necessarily encourage
crediting.  Some students may have been taught that if an instructor
points you to a resource, you need not cite it.  Other reasons are
probably at play, too.  Perhaps I should talk to my students to
find out their reasons.

Of course, "Why don't students cite the source?" is also the
wrong question.  A better question is "_How do I better encourage
students to cite properly?_"  I had thought this was a good way:
I explicitly point them to the start of the source, and I include
citation in the rubric.  I had hoped that would be enough to not
only remind them about citation, but also to get them in the habit
of citing all the materials they use.

Maybe I should meet with some educational specialists.  I bet
the amazing BB has some ideas.  I'll chat with her in the new
year.

---

**_Postscript_**: After reading this musing, you may feel like I 
should report the students who have failed to cite these sources
correctly.  However, the College has encouraged us to use some
judgement in these cases.  Particularly since I explicitly link
to the sources in the assignment, I can see an argument that this
is more "lack of craft" than anything else.

---

**_Postscript_**: The files of positive and negative words mentioned
in this musing are the work of Hu, Liu, and Cheng.  See the files
themselves and the following papers for additional notes.

Minqing Hu and Bing Liu. "Mining and Summarizing Customer Reviews."
_Proceedings of the ACM SIGKDD International Conference on Knowledge
Discovery and Data Mining_ (KDD-2004), Aug 22-25, 2004, Seattle,
Washington, USA.

Bing Liu, Minqing Hu and Junsheng Cheng. "Opinion Observer: Analyzing
and Comparing Opinions on the Web." _Proceedings of the 14th
International World Wide Web conference_ (WWW-2005), May 10-14,
2005, Chiba, Japan.

---

[1] CSC-151 is "Functional Problem Solving", the primary introductory
CS course at Grinnell, intended for both prospective majors and for
non-majors.

[2] What are the digital humanities?  Here's a slight variant of
[the introduction I give to my
students](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2021Fa/readings/fundhum-intro.html).

> Although one can develop algorithmic and computational thinking skills by exploring algorithms abstractly, we will find it much more useful to focus on a particular problem domain. In this course, that problem domain is the relatively new field of Digital Humanities. 

> What are the Digital Humanities? Perhaps we should start by considering the Humanities themselves. From my perspective, humanists study the works of humanity, including language, philosophy, religion, and art. Of course, scientists and social scientists might also study these areas. However, humanists and scientists approach their study differently. While scientists tend to employ the scientific or experimental method, humanists often attend more to the particular details or broader contexts of individual works, frequently guided by an underlying theory or framework.

> What about the digital humanities? Because the field is evolving, the community has not agreed upon a consistent definition. That’s almost certainly a good thing; definitions can limit possibilities, and fields need room to grow. At the same time, some limits are useful. For the sake of this course, we will consider the aspects of the digital humanities that relate to the ways in which algorithmic thinking and digital tools can contribute to humanistic work, particularly humanistic work that involves text written in natural language. I use the term “contribute” carefully; as a computer scientist, I know that computers cannot replace the careful thought and analysis that undergird humanistic study. However, these technologies can reveal new topics and modes of inquiry and provide new modalities for presenting results. 

[3] Unfortunately, not all of them have realized that they can reuse the
procedures they've already written, rather than rewriting new variants
of them.

[4] To be completely accurate, I should note that some transfer students
do not take Tutorial.

[5] Grinnell College. 2017.  _Academic Honesty: Scholarly Integrity,
Collaboration, and the Ethical Use of Sources (2017&ndash;2018)._
Grinnell, IA: Grinnell College [6].

[6] The 2017&ndash;2018 version is the one that pops up first on
the College's search page.  I was too lazy to find a more recent
version [7].

[7] A different search led me to [a faculty resources page](https://www.grinnell.edu/about/offices-services/academic-advising/faculty-resources) that
includes a link to the academic honesty booklet.  So you can also read
[the 2021&ndash;2022 version](https://www.grinnell.edu/sites/default/files/docs/2021-09/2021-22_Academic_Honesty_booklet_accessible_0.pdf).

[8] Back when Judy Hunter ran the Writing Lab, I fought very hard
to ensure that the Academic Honesty handbook included more than
just proper citation and plagiarism as potential issues of academic
honesty.  I'm glad to see that other issues are mentioned here; I
used to add them to the form myself [9].

[9] Yes, I realize that this is a kind of bragging.  But I've come
to the conclusion that I made some important changes at Grinnell
that are hidden from public view, and I consider it reasonable to
make them more visible.  I'm pretty sure I also wrote the initial
version of much of the text about improper collaboration, as well
as some of the examples [10].

[10] You may find it strange that I am not cited.  However, since
this is an institutionally authored document, it does not seem
necessary to cite the authors.

[11] I prefer the British spelling.

[12] I tend to be casual on citation format; I care much more that
students cite than about the details of how they cite.  However, these
sources have very explicit citation guidelines.
