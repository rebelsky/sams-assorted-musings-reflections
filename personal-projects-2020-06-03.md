---
title: Perspectives on personal projects
number: 1080
tags: [Miscellaneous](index-misc), things I was writing anyway
blurb: Reflections for/from a conversation.
version: 0.2
released: 
current: 2020-06-03
---
Today, I had a conversation with a colleague at another institution
about personal projects [1].  As is occasionally the case, I thought
it would be useful to turn my thoughts regarding the conversation
into a musing, not least because the colleague assumed that I'd
already mused about the topic.

For those who aren't sure, in the world of computing a _personal
project_ is much what it sounds like, a project that you take on
mostly because it relates to your personal interests.  Personal
projects, particularly those that are posted publicly, often serve
as good resources when you are hunting for jobs and internships
because they show off your interest in computing, reveal something
about you as a programmer, and give your interviewer something to
talk to you about, if only "What was the most challenging part of
the project."

In some way, personal projects are a purer form of the [constructionist
perspective](constructionism-2020-06-03); people learn by building
things of personal interest that they expect others to look at or
use.  And that's a reason that I like them.

Nonetheless, I will admit that I have significantly mixed feelings
about personal projects.  I like them for the reason I just mentioned.
I like them because they help students get employed.  I like them
because they provide a service to others; once you've written, say,
a cool app to help you keep track of how your sailboat is doing in
a race, others can take and build upon it [2].

However, there are many significant problems with companies using
personal projects as a mechanism for identifying or selecting
candidates.  The most obvious is that it reinforces a particular
stereotype about who is best suited for a tech job, suggesting that
it is those who love technology so much they play with it all of
the time.  At least at the pre-college level, that tends to be white
males.  It also assumes that people have time to play with technology;
some people have other commitments, whether it's a need to work,
or an expectation that they help out with family tasks, or that they
do things other than computing.  Wouldn't you prefer an employee who
thinks about things other than technology?  Who does swing dance [4]?
Who volunteers in ways that make the world a better place?  Who interacts
with a broad range of people in person [5]?  I expect that some of the
reasons that we have so many problems in the software industry is that
too many of the people who develop software look inward rather than
outward.  Prioritizing people with personal projects propagates that
problem.

Personal projects are also supposed to arise naturally.  You identify
something you want to do.  You realize that as a student of computing,
you have the ability to write a program that helps.  You write the
program.  Boom!  You're done, or so you think.  You realize others
might benefit from your code.  You share the program.  Boom!  You're
done.

So when people write personal projects primarily to pursue positions,
the primary persuasive part is passed over.  You should write code
because you want to, not because you have to.  Can those hiring tell
which kind of personal projects are "authentic" and which are not?  I
don't hire people based on personal projects, so I don't know [6].  But
I expect that interviewers look at how people talk about the project,
their enthusiasm for the subject, how they "geek out" about a technique
they learned along the way.  That makes me wonder whether some students
might be better off avoiding personal projects rather than building some
that will then undermine them at the next stage.

I don't think that's what my colleague was expecting me to have
written about personal projects, so let's move on to the next steps.
Let's suppose you're someone who knows some programming, you are
not someone who naturally makes things on your own, but you want
to try writing a personal project or two, either because you accept
the unfair system that exists or because you think you might enjoy
writing personal projects once you get a few under your belt.

For many people, *identifying the project* is the hardest part.
That may seem strange, since that's supposed to be the easy part.
But you need to develop a mindset in which you regularly say to
yourself "I could be more efficient if I had software to help with
this" or "I would learn more about this if I wrote software" or "I
would have more fun with this if I wrote software".  So what is
"this"?  I'll admit that I have trouble suggesting it for others,
so I'll run through some personal projects I know about or have
written.

* Someone practicing music might want an easy way to review sections
  of a longer piece at different tempos, since many people learn to
  play a piece by practicing part very slowly and then at increasing
  tempos.
* When I'm editing text in vi, I often want to underline a line.  After
  watching me do that by hand for the nth time, one of my students
  asked me why I didn't just write a program to do that.  I had a
  working version the next day.
* You might be dissatisfied with how a Web page is presented (or,
  more likely, a series of related Web pages) and find a way to
  scrape the data from them and represent them in another way.  For
  example, a decade or so ago, I got sick of reading comic strips
  one strip at a time and having to click a next arrow.  So I wrote
  a script to extract a month at a time and put them on a single
  page.  I've written and then lost a number of scripts to extract
  info from our schedule pages.
* You might be dissatisfied with how pandoc handles endnote marks in
  extended Markdown so you write an extension to pandoc (or a separate
  Markdown preprocessor).
* You might have a game you play and want a computer opponent for when
  humans are not available.
* You might want to send MIDI commands to your keyboard using a new
  interface you have designed because you find the one on the keyboard
  inelegant or insufficient.  (Lots of keyboards have hidden features
  that you can only access if you can write particular codes to them.)
* You run a swing dance club and want to make sure that you rotate
  partners in a "fair" way, whatever "fair" means to you.
* A year or two ago, Google showed off how one of its machine learning
  technologies could be applied to a series of related images and you
  could then take the resulting model and use it to remake other images
  in using the model.  I've seen a wonderful picture of North Campus
  redone using a Van Gogh model.  I also don't understand anything
  else about this model.

That last example suggests a somewhat different kind of personal
project.  In that case, you've seen something interesting in the
world, and want to see what you learn by trying it yourself.

That example also suggests to me a second aspect of personal projects:
You should use personal projects as *an opportunity to explore new
technologies*.  I think about the grade management system that I
wrote for myself [7].  I wrote the first version about a decade
ago.  About two years ago, I decided to rewrite it.  Although I had
used Ruby in the context of Ruby on Rails, I had never written a
Ruby application or library.  So that was an opportunity to learn.
And I had fun thinking about how grading schemas [8] could be
represented as objects [9].

A few personal projects will likely be a combination of the two
issues: You'll hear about a new technology and you'll decide that
it would be fun to write something with that new technology.  It
might even be as simple as you've run through the tutorial for the
technology and constructed something.  Now you make it personal.
The React tutorial teaches you how to make tic-tac-toe?  Extend it
for an Othello game or some game you invent.  The options are
endless, provided you have the time and the inclination.

That's a lot to consider, isn't it?  Where would I suggest you start?
From my pespective, Web scraping to present information in a new way,
one that you find more useful, is an excellent kind of project.  We all
spend time on sites saying "Wow, my life would be so much easier if they
did *this*."  Try doing it.  In some cases it will be easy.  In some,
it will be too hard.  But you'll learn from trying.

Do I have anything else to suggest?  Yeah.  Not all personal projects
have to be building technology.  Writing about technology, particularly
writing your own tutorials, can be a very different kind of personal
project.  As I understand it, my former student Philip Keily even
found ways to monetize his writing.  Philip provides more information
in [a short video](https://www.youtube.com/watch?v=8i2tN-qeKVA) and
[a book](https://philipkiely.com/wfsd/) [10].

---

[1] At the time I wrote that sentence, I was planning for that 
conversation.

[2] At least if you've written it as open-source software [3].

[3] You should.

[4] Dance swing?

[5] At least when the pandemic is over

[6] I also don't think hiring should be based on personal projects, but
you knew that by now.

[7] Yes, I like reinventing the wheel.

[9] You have your kinds of fun, I have mine.

[10] Philip's book is priced for software developers, not students.
I believe Grinnell students who ask nicely might convince Philip to
send them a free copy.  I don't know how he'll feel about students at
other institutions asking. 
