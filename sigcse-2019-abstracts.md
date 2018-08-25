Draft abstracts for SIGCSE 2019
===============================

*Topics/tags: [Code camps](index-code-camps), teaching, editing, things I was writing anyway, very long*

**_Warning!  Although much of this musing is about editing, I have
not edited the narrative in the musing.  It's just late and much, much
too long.  Proceed with caution._**

As I noted in [yesterday's musing](sigcse-2019-planning), today I need
to write 250-word abstracts for three potential papers for SIGCSE 2019,
one on our "data science for social good" camp, one on our "language and
code" camp, and one on the design of CSC 321 and CSC 322.  In ending
that musing, I was debating whether to write one musing per abstract or
one combined musing.  I was also consdiering whether to show process or
just product.  Right now, I am inclined to write a single extended musing
and to describe some of the editing process.

I find short abstracts to be a fascinating form of writing.  Obviously,
you need to be brief.  And there's a lot to put in that brief text:
The context of your work, the key results, other related issues.
But you have to convince someone that your work is of sufficient
interest for them to read further, attend your talk, or look for your
longer article.  Given those constraints, I'm sometimes surprised at
how casually some folks tend to treat their abstracts.  I've certainly
reviewed papers in which the abstract is too brief, or duplicates the
introduction [1], or does not sufficiently describe the work.  But it
is hard work.  And I'm far from an expert.  I don't know that I'll ever
achieve the sparkling brilliance I see in some abstracts [2].  But, like
my musings, my abstracts are usually sufficiently workmanlike to pass 
muster [3].

It's also a bit strange to write the abstract first.  Aren't you supposed
to write the abstract *after* you've written the whole paper and know
what it's really about?  But that's okay; it's an approach I usually use.
I begin with an abstract to frame what I'm going to write or how I'm
going to put together the disjoint materials I've already written.
I write the paper or join materials and add transitions.  Then I go
back and update the abstract and the introduction.  But the abstracts
come first.  

In the end, these abstracts don't have to be perfect.  We'll get to
update them when we submit the full papers in a week.  And, in the
case of any papers that are accepted, we'll have a chance to revise 
the abstracts again.  I'll try to keep that in mind.

On to the writing [4].

**Exploring the Effects of a Summer Middle-School Camp Emphasizing Data Science for Social Good**

I have an abstract from last year that may be a good starting point.
Let's see what my students and I wrote [5].

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
It's definitely how we think of the project.  That is, we began with
the question of how we could address issues of underrepresentation,
we developed the camps using a CSGEd focus, and we have some results
that may be useful for others.

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
  But don't I cite him?  I'll have to look.  While the paper should
  better describe computing for social good, that description does not
  belong in the abstract.
* One reviewer wanted a better definition of data science.
* One reviewer was concerned about the range of things we covered in
  that first summer (micro:bits, Jupyter, JavaScript [6], BlockPy, and
  Python).  We narrowed that a bit in the second summer.  And they don't
  appear in the abstract.  But I'll need to think about that issue in
  rewriting the paper.  I do think that the progression from block-based
  language to textual language makes sense.  And Jupyter is just a
  platform for writing Python programs.  Come to think of it, it may be
  worth mentioning the "from block-based languages to professional tools"
  progression.
* A few reviewers raised concerns about the way we present the data.
  I should think about that and make better charts this year.
* One reviewer wanted more consideration of related work, particularly on
  the design of other coding camps and on other "computing for social good"
  initiatives.  That's an issue to consider for the paper.
* One reviewer wanted more information about the structure of the camp.
  I'll make sure to include more detail.  It seems like I need to look
  back and see what was and was not there.
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
dssg [7] camps to the "in this paper" paragraph.  In part, the change
happened because I found myself writing "In this paper" twice: once
when describing the particular camps and once when detailing what went
into the camps.

I have not yet checked the length.  Getting an abstract to the proper length
is usually the last step.  I should step away from the abstract for a little
while to let my brain re-tune.  Before doing that, I'm going to get some
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
societal issues but also convince others to address problems.

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
third.  Yup.  Eight sentences.  It's also seven words too long.  My
average word length is 5.5 characters, and my average sentence length is
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

> As computing expands its roles in our everyday lives and the
opportunities for careers in computing expand correspondingly, leaders
and pundits have called for computing and computer science education
to be added earlier and earlier in students careers.  Such calls have
led to the creation of a wide variety of offerings for students at
middle-school and even elementary levels [8].  Summer "code camps"
targeted at middle-school students are one of the more popular approaches.
Such camps often emphasize "fun" aspects of computing, such as games
and robots.  However, research at the collegiate level suggests that
meaningful applications of computing, such as computing for social good,
are more successful and building and sustaining interest, particularly
among students from groups traditionally underrepresented computing.

> For the past three years, we have offered summer "code camps" for middle
school students that explore different approaches to computing than are
traditionally used for summer camps.  One of our more recent camps focuses
on ideas from the digital humanities, or DH, the application of computing
approaches as a component of humanistic models of inquiry.  Because it
reveals different ways to apply algorithmic and computational thinking,
DH has the potential to attract students who might not otherwise
consider computing of value.  Nonetheless, DH as an introductory topic
is not only under-represented at the middle-school level, but also at
the collegiate level.

> In this paper, we report on our first offering of our digital-humanities
middle-school camp.   We introduce central issues in the digital
humanities, explain the rationale for the camp design, describe the
camp curriculum, and reflect on successful and less successful aspects
of the camp.  We also present preliminary data on the effects of the
camp on students' self-efficacy and interest in computing.

I'll admit that while all of the language is "new", my brain clearly
wants me to follow a particular model: Provide context, describe what
we're doing, and indicate what's in the paper.  It's a reasonable model
and I'm not sure that I want to change it.  I suppose I could take a
slightly different approach to the material and treat the digital humanities
issue as the context ("The digital humanities are ...") and then use the
second paragraph to suggest why we are offering them at the middle-school
level.  That feels harder to do, but I'm going to try free writing an
abstract under that model, too.

> One of the long-standing problems in computer science education
is how to attract students who might not otherwise be interested in
CS, particularly those from traditionally underrepresented groups.
A number of approaches have shown success, such as media computation
and computing for social good.  However, the gap in enrollments among
both women and domestic students of color continues.  It is therefore
worth pursuing other approaches.  One possibility is to emphasize ideas
from the digital humanities, or DH, the application of algorithmic and
computational approaches to support inquiry in the humanistic disciplines.
Because of its focus on problems traditionally studied on "the other
side of campus", DH shows potential to attract a very different group of
students to computer science.

> In this project, we explore the use of digital humanities topics in
a week-long "code camp" intended for middle school students.  Even though 
the use of DH as a topic in introductory CS is still in its infancy, we
considered it useful to see what effect DH-style topics would have on
students who do not yet know what "the humanities" are.

> We report on our first offering of this camp.  We introduce central
issues in the digital humanities, explain the rationale for the camp
design, describe the camp curriculum, and reflect on successful and less
successful aspects of the camp.  We also present preliminary data on the
effects of the camp on students' self-efficacy and interest in computing.

Yes, it's still context, activity, content.  But it's a very different
set of context, activity, content.  I find myself fond of the first
paragraph. I'm less thrilled with the second paragraph, which suggests,
in effect, that our students are primarily test subjects in a very
experimental experiment.  The third paragraph is essentially the same 
as in the prior abstract [9].  If I'm keeping this form, I'll definitely
need to rewrite the second paragraph.  In either case, I should probably 
also think more about my definition of the digital humanities.  Let me
see what one of my reference works says: 

> For us, digital humanities simply represents a community of scholars
and teachers interested in using or studying technology.  We use humanities 
techniques to study digital cultures, tools, and concepts, and we also
use computational methods to explore the traditional objects of
humanistic inquiry. [10,11]

I think of the first half of this definition as a key aspect of Science
and Technology Studies (STS).  It's also not an aspect of DH that will
be as explicit in my course [12].  I'm clearly more interested in the use of
computational methods.  What did I write?  In the first sketch, I wrote
"the application of computing approaches as a component of humanistic
models of inquiry".  In the second, I wrote "The application of
algorithmic and computational approaches to support inquiry in the
humanistic disciplines".  I like that both focus on the computational
tools as part of the inquiry.  But "humanistic models of inquiry" is
a bit wordy and "humanistic disciplines" is a bit limiting.  Perhaps
just "humanistic inquiry".  I'm also not sure about "approaches'.  What
other words could I use?  "Tools" feels too primitive, even though it's
partially accurate.  "Thinking" is too broad and does not necessarily imply
the use of computation.  Perhaps "algorithms and computation".

> Digital humanities (DH), the use of algorithms and computation in
support of broader humanistic inquiry.

I can live with that.

Where was I?  That's right.  I have two abstracts, one that uses code camps
as a context, one that uses the digital humanities.  Which should I use?
I'll put that issue on hold as I return to the first abstract and try to
put it in its final stage.

**DSSG, Revisited**

Writing an abstract for another code-camp paper gives me another set of
language for the first paragraph.  But if I use the language from that
paper here, I'll have the problem of too-similar introductions [14,15].
Plus, I like the way this introduction carefully grounds itself in those
two important actors problems.  So let's take another look at this
abstract.  At this point, I expect that I'll be thinking more about
individual words, about breaking up some of the longer sentences, and
about cutting a few words from the text.

> The underrepresentation within CS of women, domestic students of
color, and lower-SES students remains a national issue. Recent studies
demonstrate two critical factors: Persistent stereotypes about "who
does computer science" can cause members of these groups to preclude interest
in the field (Cheryan and Plaut 2010); many also perceive computing as
"irrelevant" and "asocial" (Guzdial 2009).  While these issues must
be addressed at multiple ages and levels, many suggest that we should
start early, before students have developed both types of stereotypes
(McGill, Decker, and Settle 2015).

> As a step in combating (mis-)perceptions of ability and relevance,
we developed and conducted a spectrum of week-long summer "code camps"
for regional middle-school students.  These camps emphasize meaningful
uses of computing, on building self-efficacy, and on broadening
understanding of who does and can do computer science.  In this paper, we
focus on our "data science for social good" camp, in which students
explored computational approaches to data science through a lens of
computing for social good (Goldweber 2013), discovering how computing
helps them not only better understand societal issues but also convince
others to address problems.

> We discuss the rationale for the curriculum and its content, including
our uses of pair programming, personal projects, and a growth model that
brings students from block-based programming to professional Jupyter
data notebooks.  We consider the effects the camps have on students'
self-efficacy and perceptions of computer science.  We conclude with
recommendations and guidelines for those intending to offer similar camps.

You know what?  While that's not perfect, it's good enough.  Minor tweaks
won't matter much.  In a few days, I may decide on a completely different
approach.  But it's not worth my time to come up with that different
approach right now.  And it looks like it's short enough (245 words).
Let's just hope that the submission system thinks so, too [16].  Now I
just have to look forward to entering information on two years worth of
student collaborators/co-authors on the EasyChair system.

However, I am asking myself it was worth that much time and effort to
write something that is not significantly different than the original.

**Developing soft and technical skills through multi-semester,
remotely mentored, community-service projects**

I'm moving on to the abstract for the CSC 322 paper before finishing the
abstract for the digital humanities camp paper.  Why?  Because I'm starting
to run out of energy and time and it's important to get this abstract done.
I realize that the abstracts don't have to be perfect.  We'll have a chance
to revise them when we submit the full drafts of the papers.  

The current draft title (above) is a mouthful.  It's certainly something
I need to work on.  But it strikes me as a good starting point for what
we want to write about.  Should I free-write this abstract or should I
do a bit of planning first?  Let's try to plan a bit first.

I'm going to try to break the context, project, content model a bit.
But it's hard to break.  So while I'll give a short context, I'm going
to try to focus more on the project and the content.

I think it's appropriate to begin with a fairly generic statement about
software design courses.  E.g., "There are a range of models of software
design courses".  In the full paper, I'l make sure to review the literature
again to get a better sense of that range.

Then I'll describe the course itself.  What are the key aspects
of the course?    We use multi-semester projects so that students
have the experience of joining a project in the middle.  We build
non-mission-critical software for local nonprofits, software they'd like to
have, but can't afford and that won't damage their work if the students
fail to produce it in a timely manner.  We use alumni as remote mentors
for the course.  All three aspects help the students build soft skills;
they learn to work as a team, they learn to work with non-technical
clients, they learn to work with remote partners (or managers), and
they learn to think about their successors.

We've also decoupled the content from the project, which allows students
to return to projects in subsequent semesters [17].  Returning to a project
allows a student to develop leadership skills and potentially provides
other students with a useful resource.

We've now taught the course for four years and have a variety of war
stories to share, from uncooperative IT departments to inadvertent data
leaks to newspaper articles [18].  I should probably include something 
about those lessons in the last paragraph.

So I guess it will follow something like my standard model.  I really
should challenge myself to write differently.  But not tonight.

> There are a wide variety of approaches to the undergraduate software
design or software engineering course.  Some courses focus on formal
methods.  Others explore methodologies and core design issues.  And,
while most include a project, the project can vary from the central
focus of the course, the part that all other learning hangs on, to something
that is useful, but secondary to the primary learning in the course.

> For the past four years, we have taught a reimagined software design
course that includes both typical and atypical components.  Projects form
the core of the course: Students work in small teams (4-6 people) to
build non-mission-critical software for local nonprofits.  In contrast
to projects in many software design courses, which students expect
to finish in a single semester, we focus on projects that will often
require multiple semesters to finish.  Among other things, this model
gives students an experience they rarely encounter, that of working with
legacy software.  Our partner nonprofits report that they can rarely
afford the commercial equivalents to the software the students develop,
which both incentivizes the students to build the software and gives
the partners patience when projects take more time than predicted.

> Because students are working with non-technical clients, we provide
them with alumni mentors who help them navigate not only technical
problems, but also the challenges of working with a real-world client.
By using alumni, we broaden students' understanding of their work and
how it applies to their post-college careers.  

> These aspects of the course also help us develop our students' "soft
skills".  They learn to work with a team, to communicate with non-technical
clients, to work with remote collaborators (or mentors), and to think
ahead to the successors who have to take on the project in the next
semester.  As we tell our students, in many ways these skills are more
important than the technical skills they develop in the course.

> In this paper we report in more detail about the design of the
course and provide suggestions for those who might want to adopt a
similar approach.  For example, how do you recruit and manage partners
and alumni.  We also report on the many issues we have encountered
throughout the years.  What happens when a student posts the class AWS
key to a public repository and someone scrapes it?  How do you recover
from the inadvertent posting of private information?  What challenges
might a change in management at a community partner entail?

That's clearly too long.  And I don't need the first paragraph.  That's
good to see.  I guess I won't need to follow my normal approach.  How
much do I need to cut from the remaining paragraphs?  My computer says
that it's about 340 words.  That means cutting ninety words, or about
one fifth.  

> For the past four years, we have taught a reimagined software design
course with both typical and atypical components. Projects form the
core of the course: Students work in small teams (4-6 people) to
build non-mission-critical software for local nonprofits. Rather than
emphasizing projects that students finish in a single semester, we choose
projects that typically require multiple semesters to complete. Since
students usually enroll for the course for one semester, this model
gives students an experience they rarely encounter, that of working with
legacy software. We provide each team with an alumni mentor who helps
them navigate not only technical problems, but also the challenges
of working with a real-world, non-technical client. By using alumni,
we broaden students' understanding of their work and how it applies to
their post-college careers.

> These aspects of the course also help us develop our students'
"soft skills". They learn to work with a team, to communicate with
non-technical clients, to work with remote collaborators (or mentors),
and to think ahead to the successors who have to take on the project in
the next semester. As we tell our students, in many ways, these skills
are more important than the technical skills they develop in the course.

> In this paper, we report in detail about the design of the course and
describe many of the challenges associated with this model, including
projects that inadvertently reveal confidential information or keys
to costly services, clients who switch management and, therefore,
expectations, and projects that become obsolete before they are
finished. We also provide suggestions for those who might want to adopt a
similar approach, such as strategies for recruiting and managing partners
and alumni.

Hmmm ... that's a slightly different model.  What we did; why
it's valuable; and what we'll tell you.  Yeah, I can go for that.
I don't think the writing is good enough yet, but I like the
structure.  Unfortunately, it's still too long; about 280 words.
So I need to cut another 10%.  Let's run it through [Grammarly
Premium](https://grammarly.com) first.  Unfortunately, Grammarly
doesn't have many suggestions.  So I'm on my own.  I wish I were less
tired.  What happens if I just cut the examples in the last paragraph?
That makes it short enough.  But I really like the examples in the
last paragraph.  And the paragraphs end up having a long, medium, short
structure that I don't like.  So I'm going to keep some of the examples
and look for other parts to cut.

> For the past four years, we have taught a reimagined software design
course with both typical and atypical components. Projects form the
core of the course: Students work in small teams (4-6 people) to build
non-mission-critical software for local nonprofits.  These projects
typically require multiple semesters to complete. Since students usually
enroll for the course for one semester, this model gives students the
novel experience of legacy software. We also provide each team with an
alumni mentor who helps them navigate not only technical problems, but
also the challenges of working with a real-world, non-technical client.

> These aspects of the course also help us develop our students'
"soft skills". They learn to work with a team, to communicate with
non-technical clients, to work with remote collaborators (or mentors),
and to think ahead to the successors who have to take on the project in
the next semester. As we tell our students, in many ways, these skills
are more important than the technical skills they develop in the course.

> In this paper, we report in detail about the design of the course and
describe many of the challenges associated with this model, including
projects that inadvertently reveal confidential information or keys
to costly services, clients who switch management and, therefore,
expectations, and projects that become obsolete before they are
finished. We also provide suggestions for those who might want to adopt a
similar approach, such as strategies for recruiting and managing partners
and alumni.

This abstract falls into the category of "abstracts I expect to throw away
and replace after I write the paper".  But it should suffice for now.
It covers most of the core issues.  The writing isn't horrible.  It'll do.
I just wish I'd written it earlier so that I could get comments from my
co-author [19].

**DH code camp, revisited**

Where was I?  Oh, that's right, I was trying to decide whether my context
was "code camps" or "digital humanities".  There's not room for both.  It
also won't be coherent with both.  In thinking about the project, the
code camp context was what motivated us.  But would the digital humanities
aspect be more compelling to my readers?  You know what?  I think I'll
leave the DH introduction for next year's DH151 paper.  So it's time to
do a bit of cleanup of the free-written abstract.

> Over the past decade, politicians, leaders, and pundits have called
for computing and computer science education opportunities to be made
available earlier and earlier.  Such calls have led to the creation
of a wide variety of offerings for students at middle-school and
even elementary levels, including summer "code camps" targeted at
middle-school students.  Such camps often emphasize "fun" aspects of
computing, such as games and robots [20].  In contrast, research at the
collegiate level suggests that *meaningful* applications of computing,
such as computing for social good, are more successful and building and
sustaining interest, particularly among students from groups traditionally
underrepresented computing.

> In this project, we developed and offered a summer camp that draws
upon ideas and approaches from the digital humanities.  The digital
humanities, or DH, explores the use of algorithms and computation in
support of broader humanistic inquiry.  Because DH reveals different ways
to apply algorithmic and computational thinking, DH has the potential to
attract students who might not otherwise consider computing.

> In this paper, we introduce central issues in the digital humanities,
explain the rationale for the camp design, describe the camp curriculum,
and reflect on successful and less successful aspects of the camp.
Among other things, we consider how to introduce digital humanities topics
to students who have not yet heard of the humanities and explore the
utility of such topics for this age group.  We also present preliminary
data on the effects of the camp on students' self-efficacy and interest
in computing.

Now that I've contextualized the use of DH in the last paragraph,
I find myself wondering whether I want to return to the DH-first
abstract.  I guess the question is really whether I want to begin with
underrepresentation or with call for changes to education.  And in what
I have here, I wonder whether the coneection between "meaningful" and
"digital humanities" is sufficiently clear.  The last sentence of the
second paragraph tries to make that argument, but it may not be enough.

Once again, I have to remember that this is really just a draft.
We will get to rewrite the abstract if we finish the paper.  We'll get
to rewrite it again if it is accepted.  It's grammatically correct.
It's the right length.  I'll go with it.

---

Tomorrow I'll start on writing the papers.  WIll I muse about those
papers?  Probably not.  I'm not even sure whether finishing [21] three
papers will leave time or energy for daily musings.  We shall see.

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

[4] Or at least *trying* to write.

[5] If I recall correctly, one of my research students wrote the original
draft of the abstract, I made some significant edits, and the other
students then suggested minor updates.  The student may have based it
on the abstract of one of my previous papers.

[6] Did we really cover JavaScript?  Not this year.

[7] Data science for social good.

[8] If I were citing things in this abstract, I'd almost certainly insert
a citation to the work of Decker, McGill, and Settle.  I'd also insert
citations for some government reports on computer literacy.

[9] Ah, the wonders of copy and paste.

[10] Battershill, Claire and Ross, Shawna.  2017.  _Using Digital
Humanities in the Classroom: A Practical Introduction for Teachers,
Lecturers, and Students_.  London; New York: Bloomsbury Academic.

[11] Battershill and Ross also make it clear that there's no one
definition of digital humanities and, in practice, many digital humanists
embrace that complexity.

[12] I've always said that we have a responsibility to think about the
broader implications of computing, with is a less formal humanistic 
approach.  I will, of course, maintain that approach.

[14] As you've seen, that's one of the reasons I wrote a new first
paragraph for the second abstract.

[15] The problem of too-similar abstracts is also a problem of two similar
abstracts.

[16] I find that the submission system seems to count words differently than
other programs do.  

[17] We've changed that approach a bit this year.  The two are coupled
in the first offering but students can return to the course to just 
take the project.  There are some interesting administrative issues
with that design.

[18] The last of those three is positive.  The others were good learning
experiences.

[19] That applies to all of the abstracts.  It's also a powerful incentive
to finish the drafts early next week.

[20] I can cite our overview paper/poster for this claim.

[21] Or even attempting.

---

*Version 1.0 of 2018-08-24.*
