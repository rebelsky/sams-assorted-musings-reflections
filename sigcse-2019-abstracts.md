Draft abstracts for SIGCSE 2019
===============================

*Topics/tags: [Code camps](index-code-camps), teaching, things I was writing anyway*

As I noted in [yesterday's musing](sigcse-2019-planning), today I need
to write 250-word abstracts for three potential papers for SIGCSE 2019,
one on our "data science for social good" camp, one on our "language and
code" camp, and one on the design of CSC 321 and CSC 322.  In ending
that musing, I was debating whether to write one musing per abstract or
one combined musing.  I was also debating whether to show process or just
product.  Right now, my inclination is to write a single extended musing
and to include some of the editing process.

I find short abstracts to be a fascinating form of writing.  Obviously,
you need to be brief.  And there's a lot to put in that brief text:
The context of your work, the important results, other related issues.
But you have to convince someone that your work is of sufficient
interest for them to read further, attend your talk, or look for your
longer article.  Given those constraints, I'm sometimes surprised at
how casually some folks tend to treat their abstracts.  Certainly, I've
reviewed papers in which the abstract is too brief, or duplicates the
introduction [1], or does not sufficiently describe the work.  But it
is hard work.  And I'm far from an expert.  I don't know that I'll ever
achieve the sparking brilliance I see in some abstracts [2].  But, like
my musings, my abstracts are usually sufficiently workmanlike to pass 
muster [3].

It's also a bit strange to write the abstract first.  Aren't you supposed
to write the abstract *after* you've written the whole paper and know
what it's really about?  But that's okay; it's an approach I usually use.
I begin with an abstract to frame what I'm going to write or how I'm
going to put together the disjoint materials I've already written.
I write the paper or joint materials and add transitions.  Then I go
back and update the abstract and the introduction.  But the abstracts
come first.  Here goes.

**Exploring the Effects of a Summer Middle-School Camp Emphasizing Data Science for Social Good*

I have an abstract from last year that may be a good starting point.
Let's see what my students and I wrote [4].

> The underrepresentation of women, students of color, and people
from lower-SES backgrounds within computer science remains a national
issue. Recent studies demonstrate one reason: persistent stereotypes about
"who does computer science" can cause minority groups to preclude interest
in the field (Cheryan and Plaut 2010).  Unfortunately, these stereotypes
are not the only threat to diversifying the discipline. Engaging a diverse
group of individuals in computer science is unlikely so long as computing
curriculum is perceived as "irrelevant" and "asocial" (Guzdial 2009).
Confronting the stigma of triviality applied to computer science, much
like approaching student perceptions about who can do computer science,
is a necessary step for increasing the perceived applicability of the
discipline.

> As a step in combating the perception that programming curriculum
is irrelevant, we developed and ran a week-long summer coding camp for
local middle school students that camp applied principles of computing
for social good (Goldweber 2013) with data science techniques to encourage
campers to consider how computing could help them explore societal issues.
Throughout the week, campers learned how to extract meaning from their
work and gained experience collaborating in pairs to solve problems.

> In this paper, we discuss the camp curriculum and its emphasis on
the applications of computing. We also consider the effects of the
camp on the self-efficacy of campers and their perceptions of computer
science. We also present some recommendations for those intending to
conduct similar camps.

Interesting.  That's a bit more of an "academic" tone that I normally use.
But I don't think that's a problem.  The three-stage approach (context,
project, results) seems like a successful way to approach the abstract.
It's certainly how we think of the project.  That is, we began with the
question of how we could address issues of underrepresentation, we
developed the camps using a CSGEd focus, and we have some results that
may be useful for others.

However, the context paragraph is long.  I should find ways to make it a
bit shorter.  I might want to say more about the camps itself in the
middle paragraph and the conclusions in the last paragraph.  And I need
to incorporate issues related to our second offering of the camp.  

I should also see what last year's reviewers said about the paper itself.
Those comments might prove useful in thinking about how to "sell" the
work.

* One reviewer was concerned that we had citations in the abstract.
  That's a critique I'll have to consider and research more deeply.
  I understand the concern that the abstract may have to stand by itself.
  But it strikes me as wrong to present ideas that are not mine without
  citing them.  I should look at how frequent citations appeared in
  last year's SIGCSE.  For now, I'm keeping the citations.
* A few reviewers wanted more of a description of "computing for social
  good".  One also wanted an explanation of who "Goldweber" is.  Maybe I
  should describe Mikey as "Former SIGCAS chair" or something like that.
  But don't I cite him?  I'll have to look.  The paper should definitely
  have more about what computing for social good is, but that does not
  belong in the abstract.
* One reviewer wanted a better definition of data science.
* One reviewer was concerned about the range of things we covered in
  that first summer (micro:bits, Jupyter, Javascript [5], BlockPy, and
  Python).  We narrowed that a bit in the second summer.  And they don't
  appear in the abstract.  But I'll need to think about that issue in
  rewriting the paper.  I do think that the progression from block-based
  language to textual language makes sense.  And Jupyter is just a
  platform for writing Python programs.  Come to think of it, it may be
  worth mentioning the "from block-based languages to professional tools"
  progression.
* A number of reviewers raised concerns about the way we present the data.
  I should think about that and make better charts this year.
* One reviewer wanted more consideration of related work, particularly on
  the design of other coding camps and on other "computing for social good"
  initiatives.  That's an issue to consider for the paper.
* One reviewer wanted more information about the structure of the camp.
  That definitely belongs in the paper.  I'll need to look back and see
  what was and was not there.  
* One reviewer has a set of particularly telling questions about the particular
  effects of data science in building student confidence and enthusiasm.
  I'm not sure that we can tease that out from the data.  However, we do
  know from experience that the notion of using a professional tool was
  particularly important for our campers.

It looks like most of the comments should impact what we write in the
revised paper more than what we write in the abstract.  The most important
issues for the abstract are the citations, which I'm ignoring, and the
range of languages, which I should add.  I don't think I need to add
definitions of computing for social good or data science to the abstract.
Here's my first stab at updating the abstract.

> The underrepresentation of women, domestic students of color, and people
from lower-SES backgrounds within computer science remains a national
issue. Recent studies demonstrate two important factors: persistent
stereotypes about "who does computer science" can cause minority groups to
preclude interest in the field (Cheryan and Plaut 2010) and many perceive
computing as "irrelevant" and "asocial" (Guzdial 2009).  While these
issues must be addressed at multiple ages and levels, many suggest
that we should start at a comparatively young age, before students have
developed both kinds of stereotypes (McGill, Decker, and Settle 2015).
As a step in combating perceptions of ability and relevance, we have
developed and conducted a series of week-long summer "code camps"
for regional middle-school students that focus on meaningful uses of
computing, on building self-efficacy, and on broadening understanding
of who does and can do computer science.

> In this paper, we focus on two offerings of a camp in which students
learned computational approaches to data science through a lens of
computing for social good (Goldweber 2013), discovering how computing
could help them not only better understand societal issues but also
convince others of issues that need to be addressed.  In particular, we
discuss the rationale for and content of the camp curriculum, including
our uses of pair programming, personal projects, and a growth model
that brings students from block-based programming to professional data
notebooks in Jupyter.  We consider the effects of the camps on the
students' self-efficacy and their perceptions of computer science.
We also present some recommendations and guidelines for those intending
to offer similar camps.

While I've kept a lot the same, that ended up being more of a structural
change than I anticipated.  Somewhere in the middle, I decided that I should
separate our broader project (designing non-traditional code camps) from
the two particular camps.  That change led to me moving the basics of the
broader project into the context paragraph and the quick overview of the
dssg [6] camps to the "in this paper" paragraph.  In part, the change
happened because I found myself writing "In this paper" twice: once
when describing the particular camps and once when detailing what went
into the camps.

I have not yet checked the length.  Getting an abstract to the proper length
is usually the last step.  I should step away from the abstract for a little
while to let my brain retune.  Before doing that, I'm going to get some
advice from [Grammarly Premium](index-grammarly).  Should I list all of
the advice?  Sure.  I'm going to ignore a lot, but it's worth documenting.

* Grammarly suggests that I should use "remain" rather than "remains" in
  "The underrepresentation ... remains".  It's wrong.  But I can see why;
  it's a complicated subject.
* Grammarly suggests that I should replace "two important factors" with
  "two critical factors", "two crucial factors", or "two essential
  factors".  I'm not sure that they are essential factors.  But "critical"
  seems good, if a bit more extreme than I'd like.
* Grammarly recommends that I avoid the passive in "must be addressed".
  That's a use of the passive voice that I'm comfortable accepting.
* Grammarly suggests that I use "problems" rather than "issues" in
  "issues that need to be addressed".  I'm comfortable with that change.
  More importantly, it reminds me that I have repeated "be addressed",
  which now seems awkward.  Perhaps make it active "to address problems".
* Grammarly does not like the repetition of the word "camps" and suggests
  that I use "fields" instead.  But they aren't the same thing.

That's it.  As I've said, I tend to write good, workmanlike, prose.  So
it's unlikely that Grammarly will find much wrong with it.  But it's not
the kind of prose that makes you pay attention to the writing.  I guess
that's okay; my primary goal is to convey a message.  Let me go through
it one more time before setting it aside.

> The underrepresentation of women, domestic students of color, and people
from lower-SES backgrounds within computer science remains a national
issue. Recent studies demonstrate two critical factors: Persistent
stereotypes about "who does computer science" can cause minority groups to
preclude interest in the field (Cheryan and Plaut 2010), and many perceive
computing as "irrelevant" and "asocial" (Guzdial 2009).  While these
issues must be addressed at many ages and many levels, many suggest
that we should start at a comparatively young age, before students have
developed both kinds of stereotypes (McGill, Decker, and Settle 2015).

> As a step in combating (mis-)perceptions of ability and relevance,
we developed and conducted a variety of week-long summer "code camps"
for regional middle-school students that focus on meaningful uses of
computing, on building self-efficacy, and on broadening understanding
of who does and can do computer science.  In this paper, we focus on two
offerings of a camp in which students explored computational approaches to
data science through a lens of computing for social good (Goldweber 2013),
discovering how computing could help them not only better understand
societal issues but also convince others of to address problems.

> In particular, we discuss the rationale for and the content of
the curriculum, including our uses of pair programming, personal projects,
and a growth model that brings students from block-based programming
to professional data notebooks in Jupyter.  We consider the effects
of the camps on the students' self-efficacy and their perceptions of
computer science.  We conclude with recommendations and guidelines for
those intending to offer similar camps.

As you can see, re-reading it made me want to go back to the original
three-paragraph model.  I'm having trouble with the first sentence of
the last paragraph.  I want to put something about "design and redesign"
in, but it was awkward to have "we discuss the rational for, the design
and redesign of, and the content of the curriculum".  My next version
fo "rationale for and the content and evolution of".  That also felt
too wordy.  Next up was switching the order of "content and evolution".
That didn't work either.  Next was "evolving content of".  But that
felt wrong.  In the end, I went back to "rationale for and content of";
the evolution can be part of the paper and need not be in the abstract.

Before I put it aside, I'd like to see what Grammarly says about the
length and writing level.  It suggests that there are 1732 characters
which represent 256 words and eight sentences.  Only eight sentences?
Wow!  Those are long sentences.  Is Grammarly right?  I count three
sentences in the first paragraph, two in the second, and three in the 
third.  Yup.  Eigth sentences.  It's also seven words too long.  My
average word length is 5.5 characters and my average sentence length is
32 words.  Yeah, that's long.  My readability score is 24, which means
that "Your text is likely to be understood by college graduates but may
not be easy for many to read."  I might want to address that issue when
I come back to it.

**A Middle-School Code Camp Emphasizing Digital Humanities**

There are a variety of ways I could approach this abstract.  I could
start with the form of the prior abstract and swap in the digital
humanities (language and code) issues.  But I worry that that approach
starts to make our papers sound or feel repetitious or generic.  So it
may be that I should write this one "from scratch" and then come back
and consider what from the prior abstract might fit.  Or I may want
to try a hybrid strategy.  I'm going to start with a bit of free writing.

> As computing continues to expand its role in our everyday lives and the
opportunities for careers in computing expand, leaders and pundits have
called for computing and computer science education to be added earlier
and earlier in students careers.  Such calls have led to the creation
of a wide variety of offerings for students at middle-school and even
elementary levels [7].  Summer "code camps" targeted at middle-school
students are one of the more popular approaches.  However, such camps
often emphasize "fun" aspects of computing, such as games and robots,
rather than more meaningful applications.


**Developing both soft and technical skills through multi-semester,
remotely mentored community-service projects*

Yeah, that's a mouthful.  I need to work on the title.  But it strikes
me as a good starting point for what I want to talk about.

> Many traditional software design courses focus on technical issues,
helping students learn methodologies and tools for designing and analyzing
software systems.  For example, a course might introduce and compare
agile and plan-and-document methodologies while also providing students
with more in-depth understanding of key design patterns.

---

In the end, these don't have to be perfect.  We'll get to revise them
when we submit the full papers in a week.  And, for any papers that are
accepted, we'll have a chance to revise them again.  So I think this
is an acceptable starting place.

Now on to writing the papers.  I'm not sure how, if it all, I'll report
on that writing within the daily musings.  I'm also not sure whether 
finishing three papers will leave time or energy for daily musings.  
We shall see.

---

[1] At times, word for word.

[2] Hmmm ... maybe this year I should read through all the abstracts and
pick out the ones I find particularly compelling.  Then I can analyze what
I find compelling about them.  That analysis may help me in the future.
I'll add that task to my "hope to do, but may not have the time" list.
I should also acknowledge that what I find interesting may not be what 
others find interesting.

[3] Yeah, that's a good example.  Two mediocre metaphors ("workmanlike"
and "pass muster") thoughtlessly included in a sentences.  Plus, I used
a to-be verb.

[4] If I recall correctly, one of my research students wrote the original
draft of the abstract, I made some significant edits, and the other students
then suggested minor updates.  The student may have based it on a the
abstract of one of my previous papers.

[5] Did we really cover JavaScript?  Not this year.

[6] Data science for social good.

[7] If I were citing things in this abstract, I'd almost certainly insert
a citation to the work of Decker, McGill, and Settle.  I'd also insert
citations for some government reports on computer literacy.

---

*Version 0.1 of 2018-08-24.*
