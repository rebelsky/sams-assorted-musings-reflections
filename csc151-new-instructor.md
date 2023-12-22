---
title: Starting a guide for new CSC-151 instructors
number: 1263
tags: [CSC151](index-151)
blurb: A guide for my colleague(s).
version: 1.0.1
released: 2023-12-21
current: 2023-12-22
---
This coming spring, one of my awesome new colleagues [1] is co-teaching CSC-151 with me. This will be the first time they've taught CSC-151, and I may be less available than usual, so it seemed like a good time to start gathering the information on CSC-151 for the colleague and future colleagues [2]. The information may also be useful for students (current and prospective), class mentors, faculty at other institutions, and, um, others I have not yet determined.

I expect that there's enough information that this guide will require multiple musings. I'm not yet sure what information will end up in this introductory piece and what will end up in separate documents. I started with a quick outline of topics, and we'll see where I get from there. Since life is busy these days [3], I found myself writing this a bit at a time and thinking about it a bit more.

**About the course**

CSC-151, _Functional Problem Solving_, is Grinnell's primary introductory course in computer science [4]. It serves as the first course in the CS major. It also serves as an optional introduction to computational thinking.

We have four or so primary learning goals for the course. We want to introduce students to notions of _computational thinking_. We want to give them experience _developing and implementing algorithms_. As the course title suggests, we want to introduce the power and value of _functional thinking_, exploring various issues from higher-order programming, such as `map` and `reduce`, through side-effect-free programming. And we want to help our students develop skills in _collaboration_, primarily collaboration within those prior domains.

There are other broader goals for the course within the department. Most importantly, it should be _welcoming_ to all students, independent of their background in computing. The course should also help _build community_ within the department.

We rely on many pedgagogical techniques and components to help achieve those goals. We have a _workshop-style class_ (also known as a flipped classroom because we think students learn better from doing than listening. We ask students to use _pair programming_ as they develop solutions in class because working in pairs builds community, strengthens their collaboration skills, and helps students develop an appreciation for multiple approaches. (Of course, we don't immediately assume that students will naturally develop these skills; we spend time in class considering how and why to work with others.) To reduce stress and increase equity, we use a form of _mastery grading_ for the class. And we teach it in a variant of the _Scheme_ programming language.

Rather than using an existing text, like _Structure and Interpretation of Computer Programs_ (SICP) or _How to Design Programs_ (HtDP), we rely almost exclusively on locally developed readings and labs.

We'll return to some additional details, particularly our approach to mastery grading and our support for community, in subsequent musings.

**Why Scheme?**

We've been teaching CSC-151 in Scheme since before I arrived at Grinnell in 1997. Every few years, we discuss whether or not to change the language. And, for better or worse, we continue to choose Scheme as our introductory language. Here are a few reasons:

* Scheme and functional programming help level the playing field [5]. Students with prior programming experience cannot necessarily use what they have learned in a course where we discourage side effects, use recursion as our primary device for repetition, and regularly ask students to use procedures like `map`.
* Scheme encourages interactive development. Because Scheme comes with a REPL [6], students may be more inclined to decompose their programs as they write and experiment with smaller functions.
* Scheme has a simple and straightforward syntax. While Scheme has a lot of parentheses, once you understand the basic model, it should be straightforward to write syntactically correct expressions.
* Scheme is functional. We want students to learn functional modes of thinking early.
* Basic Scheme has a simple computation model. Since there are no side effects, we can have students use a substitute model of computation to understand what is happening in their programs.
* Students can't easily find (bad) solutions to assignments on the Web. Although it's good that students take the initiative to look for ideas online, some students look for too much "help". And there's a lot of bad advice out there for languages like Python and Java. There's less advice and less bad advice for Scheme. My initial investigations suggest that ChatGPT does less well with Scheme than it does with other languages.

As I said, we've explored other options. We've considered Python (powerful, interactive, but a complex computation model and much too much bad advice), Haskell (almost everything we like about Scheme, but a bit less straightforward), Ruby (more OOP than functional), JavaScript (too much bad advice, a less clear language model), and others I forget. But we keep coming back to Scheme. Scheme gets the job done. I assume we'll revisit the question again in the near future. Perhaps we'll move to a functional subset of Python [7], as has been suggested in the past.

**A workshop-style class**

As noted above, CSC-151 is a workshop-style class. As I understand it, there are multiple models of workshop-style classes. For CSC-151, we ask students to read some background material before class and to respond to a few questions to check their understanding. We then spend the majority of class time with students working in pairs on a set of problems.

I know that some forms of workshop-style science are a bit more open ended. For example, faculty might ask students to develop experiments that allow them to calculate the force of gravity or the speed of light, to conduct those experiments, and then to report on them. In many cases, those classes also don't ask students to read materials in advance. 

I get the constructionist / constructivist approach. I like the idea of students finding projects of interest and learning as they complete those projects.  However, my experience suggests that not all students do well with completely open-ended classes and that most students fail to explore the nooks and crannies of the topics they learn. If our goal was only that they can write programs, I might consider something more open-ended. But we want to develop particular kinds of computational thinking, and I find that focused questions help. There's also the question of what I'd call "learning the lab equipment", the syntax and semantics of the language and the basic operations. In some sense, class periods focus on those ideas and the mini-projects (homework assignments) are (or can be) more open ended.

No one who has taught the class of late has pushed for a more open style of lab. And no one has pushed for moving toward more of a traditional lab/lecture model [8]. Both issues are up for future discussion.

I'll also note that while traditional workshop-style science classes tend to have groups of three or four, we do our best to stick to pair programming.

**Themed courses**

For almost twenty years, we've been teaching CSC-151 as a "themed" course. That is, we try to ground the problems of the course in a particular domain or theme. When we moved to a themed model, we expected to develop a variety of themes and permit students to choose the one that most interested them. In practice, we've often found it most natural to have one theme per semester [9], not least because that means that faculty can share work developing assignments (mini-projects) and exams (learning assessments).

Our first themed course was one that emphasized image making through scripting the GNU Image Manipulation Program, inspired by the Georgia Tech Media Computation Course. We collaborated with studio art faculty on ensuring that the course had a deeper design component. We also tried to get students to think about the value of scripting an application. That version lasted about a decade.

We then developed a "data science light" version of the course, one that encouraged students to think about ways to process large data sets. Following that was a digital humanities version that emphasized textual analysis. There was, of course, crossover between the two versions.

Last year [10], a music/sound-making version was introduced. That version also saw the introduction of Scamper, Grinnell's own implementation of Scheme.

This year, we introduced a new version of the image-making course, one that just relies on DrRacket. That's the version you'll be teaching, at least if you're teaching in Spring 2024. We haven't restored all the aspects of the old version, and may be adding new aspects as time goes on.

I think that's it. There are currently four versions: data science light, digital humanities with text analysis, music making, and image making.

At some point, I expect we'll get develop versions. I've heard about plans for a new data-science version. I'd also like to see one that emphasizes computing for social good. I don't know what ideas others will bring to the class.

**Software**

As you might expect, we use lots of software to support the course. Here's an incomplete list.

We have two implementations of Scheme available to us: _DrRacket_ and _Scamper_. When Scamper is more robust, we'll move to only using Scamper. For Spring 2024, we'll stick with Scamper. I'll report more on the differences in a future musing on course options.

We have _custom Racket libraries_ for the DrRacket version of the course. These include some additional image-making procedures, an alternate syntax for regular expressions, and some higher-order procedures I find useful as I get students to think functionally.

We build the Web site with _Jekyll_. I suppose I need to provide instructions for our Jekyll sites, too. Historically, we've deployed those to our personal sites (now on sites.grinnell.edu). However, there is also a [csc151.cs.grinnell.edu](https://csc151.cs.grinnell.edu). I admit to being a fan of individual sites, particularly since I put things on my course site that others may not want on their sites, such as my philosophy of teaching and learning.

We use _Git_ (and _GitHub_) to maintain the readings, labs, and other Web site materials, as well as various libraries and utility programs. There are enough Git repos involved that I need a separate document to describe them all.

Students primarily submit their work (mini-projects/assignments, learning assessments/exam and quiz questions, reading responses, labs, metacognitive reflections) on _Gradescope_. Gradescope is also tied to Grinnell's _Blackboard_ LMS. I don't use that connection; I don't know if others do.

We need to convert the CSV files we can download from Gradescope into grade reports. For that, we need _custom grading software_. There are multiple versions out there. PM wrote one. Barbara Johnson writte a custom spreadsheet. I've written one. You can write your own. Or you can use one of ours.

I'm a fan of using _autograders_ for our mini-projects. Autograders permit students to check their work (at least when they don't crash the autograders). Autograders also make our graders' work easier. I've been writing my autograders using [a custom library](https://github.com/grinnell-cs/racket-autograder-gradescope). It and they almost certainly need updating.

Is that it? Probably not. But it's all that comes to mind right now.

**Some dangers of teaching with Sam**

You may be wondering why this section is here. I'll admit that I am not entirely sure. When I started taking notes for this musing, I wrote "The dangers of teaching with Sam", which suggested that I had some dangers in mind. Unfortunately, enough time has passed that I don't know what those were. I'll try to come up with some, as well as a lead in.

For better or worse, you are stuck teaching the same semester as Sam [11]. While that carries some benefits, such as the wisdom of an experienced faculty member, it also brings some drawbacks. Let's consider a few.

_I tend to do things at the last minute._ If I am tasked with writing a homework assignment, you may find that it's not ready until after class. I'll present the ideas in class, and I won't have everything written down. And it will evolve. Since it's written at the last minute, it will likely have some issues. Feel free to blame me if students complain. My old colleague, Janet Davis, may have some comments on what it was like to teach the first mediacomputation version of the course, when I usually didn't have labs ready until five minutes before class. Fortunately, most of the materials for CSC-151 have already been prepared and used. Perhaps it won't be so bad.

_I tend to change things on the spur of the moment._ I trust my instincts more than I trust my planning. For example, even after carefully planning a lab for a day, if students seem confused about a topic, I may go into an extemporaneous lecture (or, more likely, an extemporaneous interactive discussion). These tendencies tend to make my section of the class fall out of synch with other sections. We'll try to leave some unplanned days to account for those situations, but it won't be perfect.

_I'm a softy._ I've reached the stage in my career in which I've decided that being kind with my students is much more important than being strict with them. Or perhaps I've always believed that. In any case, I have policies like "There's no penalty for taking a mental health day, provided you notify me." I am unlikely to change either the policies or my behavior, even if those teaching other sections have different policies.

_I'm snarky_. I'm snarky with my family. I'm snarky with my colleagues. I'm snarky with my students. I've tried not to be. But I'm not the same person when I'm not snarky, and I seem to be a better teacher and colleague when the snark escapes. Most people who work with me figure out that "snark is love". 

_I'm blunt_. Feel free to be equally blunt with me.

_I write too much_. That may be evident from this musing. It may be evident from some of the ancillary documents on the CSC-151 site. I'm not sure how this affects my co-teachers, but it seemed worth mentioning.

Yeah, those are issues you should be aware of [12]. Or some of them.

**CSC-151 is a collobarative course**

I've mentioned already that we want students to learn to collaborate well. But we also collaborate on the development of the course. Any faculty member who teaches the course is welcome to update the course. You should certainly correct mistakes of spelling, grammar, logic, or presentation on any the course pages. We should discuss issues like assignments and order of topics; just because it's worked one way doesn't mean it can't work better another way.

After a semester or two of teaching the course, you should feel free to make larger changes. Maybe you think we should add a component or remove a component. Maybe it's time to get rid of Jekyll. If I knew what should be done, I would have done it already.

In any case, the course already benefits from the pedagogical contributions of a variety of faculty but it can still use more.

**Wrapping up**

I've told you a bit about the course and some of its underpinnings. I've written a lot. While there's certainly more to write, I think this is enough for one musing. Stay tuned for more.

---

**_PostScript_**

The preceding may or may not be enough to get my new colleague started. As I noted, there's certainly a lot more to write. Here's my quick list of other musings that I should write soon. I may come back and add links and notes when I write them.

* In spite of the apparent uniformity of CSC-151, there are a variety of options in how you arrange and teach a section, from the version of Scheme to use to how you structure class meetings. I considered calling these "controversies", but they aren't all that controversial. Mostly, it's a matter of differences of opinion. 
* I should better explain our approach to mastery grading, particularly our emphasis on small learning assessments and mini-projects.
* I should describe the software that we use to take grade information from Gradescope and report on how students are doing. At least I should explain my version of the software.
* I hope that you don't need to write any autograders right now. But when you do, it will be useful to have some guidance. Perhaps that will even give me an incentive to restructure the autograding software.
* As I noted above, we have half a dozen or more GitHub repos. A guide to the repos (and to our customary protocols for using those repos) seems called for.
* I'd swear that I've written a history of CSC-151, but I might write a new one (or update the old one).

---

[1] I have many awesome new colleagues.  But we need more.  I also have awesome more-experienced colleagues.

[2] I suppose it may be useful for old colleagues, too.

[3] And always.

[4] We also offer CSC-105, The Digital Age.

[5] Is that too much of a sports metaphor?

[6] Read-Evaluate-Print-Loop, for those not familiar with the jargon.

[7] No, not Pyrat.

[8] There are some differences of opinion on how much time to spend in class preparing students for lab. We'll return to that issue in another musing.

[9] Fall 2023 was an exception.

[10] "Last year" means "academic year 2022-23".

[11] Or perhaps you may be stuck teaching with Sam. Certainly, the colleague for whom I originally wrote this piece will be teaching with me. I assume others will also end up in that position.

[12] Or "those are issues of which you should be aware". 
