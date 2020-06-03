---
title: Perspectives on personal projects
number: 1080
tags: [Miscellaneous](index-misc)
blurb: Reflections for/from a conversation.
version: 1.0
released: 2020-06-03 
current:
---
Today, I had a conversation with a colleague at another institution
about personal projects [1].  As is occasionally the case, I thought
it would be useful to turn my thoughts regarding the conversation
into a musing, not least because the colleague assumed that I'd
already mused about the topic.

For those who aren't sure, in the world of computing, a _personal
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
or an expectation that they help out with family tasks, or that
they do things other than computing.  Wouldn't you prefer an employee
who thinks about things other than technology?  Who does swing dance
[4]?  Who volunteers in ways that make the world a better place?
Who interacts with a broad range of people in person [5]?  I expect
that some of the reasons that we have so many problems in the
software industry stem from the too-many people who develop software
who look inward rather than outward.  Prioritizing people with
personal projects propagates that problem.

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
to try writing a personal project or two, perhaps because you accept
the unfair system that exists or because you think you might enjoy
writing personal projects once you get a few under your belt or
because you lost your summer internship and need something else to
occupy your time.

For many people, *identifying the project* is the hardest part.
That may seem strange since that's supposed to be the easy part.
But you need to develop a mindset in which you regularly say to
yourself "I could be more efficient if I had software to help with
this" or "I would learn more about this if I wrote software" or "I
would have more fun with this if I wrote software".  So what is
"this"?  I'll admit that I have trouble suggesting it for others,
so I'll run through some personal projects I know about or have
written.

* Someone practicing music might want an easy way to review sections
  of a longer piece at different tempos; many people learn to
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
  one strip at a time and having to repeatedly click the next button.
  So I wrote a script to extract a month at a time and put them on
  a single page [7].  I've written and then lost several scripts
  to extract info from our schedule pages.
* You might be dissatisfied with how pandoc handles endnote marks
  in extended Markdown so you write an extension to pandoc (or a
  separate Markdown preprocessor).
* You might have a game you play and want a computer opponent for
  when humans are not available.
* You might want to send MIDI commands to your keyboard using a new
  interface you have designed because you find the one on the
  keyboard inelegant or insufficient.  (Lots of keyboards have
  hidden features that you can only access if you can write particular
  codes to them.)
* You run a swing dance club and want to make sure that you rotate
  partners fairly, whatever "fair" means to you.
* A year or two ago [8], Google showed off how one of its machine
  learning technologies could be applied to a series of related
  images and you could then take the resulting model and use it to
  remake other images in using the model.  I've seen a wonderful
  picture of North Campus redone using a Van Gogh model.  I also
  don't understand anything else about this model.

That last example suggests a somewhat different kind of personal
project.  In that case, you've seen something interesting in the
world, and want to see what you learn by trying it yourself.

That example also suggests to me a second aspect of personal projects:
You should use personal projects as *an opportunity to explore new
technologies*.  I think about the grade management system that I
wrote for myself [8].  I wrote the first version about a decade
ago.  About two years ago, I decided to rewrite it.  Although I had
used Ruby in the context of Ruby on Rails, I had never written a
Ruby application or library.  So that was an opportunity to learn.
And I had fun thinking about how grading schemas [9] could be
represented as objects [10].

A few personal projects will likely be a combination of the two
issues: You'll hear about a new technology and you'll decide that
it would be fun to write something with that new technology.  It
might even be as simple as you've run through the tutorial for the
technology and constructed something.  Now you make it personal.
The React tutorial teaches you how to make tic-tac-toe?  Extend it
for an Othello game or some game you invent.  The options are
endless, provided you have the time and the inclination.

Oh, I mustn't forget the last step.  Ideally, you should be doing
your development on one of those public sites, such as Github.  Share
early and often, as they say [11].

That's a lot to consider, isn't it?  Where would I suggest you start?
From my perspective, Web scraping to present information in a new way,
one that you find more useful, is an excellent kind of project.  We all
spend time on sites saying "Wow, my life would be so much easier if they
did *this*."  Try doing it.  In some cases, it will be easy.  In some,
it will be too hard.  But you'll learn from trying.

Do I have anything else to suggest?  Yeah.  Not all personal projects
have to be building technology.  Writing about technology, particularly
writing tutorials, can be a very different kind of personal
project and a good way of learning.  As I understand it, my former
student Philip Kiely even found ways to monetize his writing.  Philip
provides more information in [a short
video](https://www.youtube.com/watch?v=8i2tN-qeKVA) and [a
book](https://philipkiely.com/wfsd/) [12].

---

Of course, my colleague's goal was not to have muse [14].  Their
goal was that we talk about personal projects and then think through
how you might run a session with students to help them think through
personal projects [15].  What might such a session look like?

* I'd ask them to read this musing in advance of the meeting.  I might
  even ask them to watch PK's video.
* We'd work together to make a sample list of potential personal projects.
  I might even group them into categories: Let's build a list of cool
  Web scraping opportunities; Let's think about some extensions to
  tic-tac-toe; Let's ....
* We'd work together to make a sample list of interesting technologies
  that might be worth learning.
* Given time, we might even look at how you'd start building a project.

---

My colleague also asked about the issue of attention: How do you keep
yourself on task to complete a personal project.  In the traditional
(mythical?) world of personal projects, that's not an issue; you are
so compelled by the personal project that you naturally spend the time
on it.

But over here in the real world, things get in the way.  You have other
responsibilities [16].  How do you make sure that you spend time on the
personal project?  We brainstormed a variety of strategies.

* You could set aside time each day (or week) in your calendar.
* You could set deadlines for yourself.
* You can work in a pair on a project.  Often, we work to satisfy our
  responsibility to others more than we work to satisfy our responsibility
  to ourselves.
* You could set up a broader "community of responsibility", a group
  of people who check in together to see how each is doing and
  encourage each other.

You can guess which is my favorite.  The other aspect I like about
a good community is that you can rely on it not only for encouragement
but also for advice.  If you are part of a group who are all working
on, say, Web scraping with Rust [17] or extending the standard React
tic-tac-toe game when you get stuck, you have a natural community to
reach out to for advice.

---

**_Postscript_**: As I've noted before, I learn a lot from [Mark
Guzdial's 'blog on computing education
research](https://computinged.wordpress.com/).  I wonder if he's
written anything about these issues.  I also don't know what research
there is on personal projects.  My two-minute search on his 'blog
reveals nothing.  Maybe I'll drop him a note.  But not today.

---

[1] At the time I wrote that sentence, I was planning for that 
conversation.

[2] At least if you've written it as open-source software [3].

[3] You should.

[4] Dance swing?

[5] At least when the pandemic is over

[6] I also don't think hiring should be based on personal projects, but
you knew that by now.

[7] I also pay for a subscription so that the creators get compensated.

[8] Maybe more than that.

[9] Yes, I like reinventing the wheel.

[10] You have your kinds of fun, I have mine.

[11] I don't know if anyone says that.

[12] Philip's book is priced for software developers, not students.
I believe Grinnell students who ask nicely might convince Philip to
send them a free copy.  I don't know how he'll feel about students at
other institutions asking. 

[14] However, they did say that it wouldn't hurt to have a musing to which
they could point their students.  I don't think they expected me to write
something like this.

[15] It turns out that wasn't their goal, either.  I'm going to pretend
that it was.

[16] Classwork, in most cases.  All those other things I mentioned
earlier, too.

[17] Would you do Web scraping with Rust?  I'm not sure.
