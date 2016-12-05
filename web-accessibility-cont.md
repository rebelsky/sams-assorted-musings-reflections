Web Accessibility, Continued
============================

*This essay was originally going to be an email message to a few
colleagues.  But, as I was writing the message, I realized that it felt
more like an essay than a letter, and I'm pretty sure that the folks I
was going to send it to read my essays anyway.  If not, I'll forward it
along to them.*

A few days ago, our Faculty Friday [1] involved a presentation from the
library faculty on support for research and scholarship.  Now, their
model of research is what I'd usually call "library research": finding
sources to inform your writing, or data to analyze.  While that's not the
kind of research that I do, that's okay; a lot of research on campus takes
that form.  Toward the end of their presentation, they showed off some
mechanisms we might use to present student research.  Unfortunately, the
two examples they gave, a video and a Web site, had accessibility
issues.  I found that particularly frustrating, given that the prior
day, we'd had a public presentation about the final recommendations of
our task force on disability and accessibility [3].  The video should
be easy to fix; someone just needs to manually caption that video,
rather than counting on the automatic captioning.  The Web site is more
problematic, and it's the subject of this essay.  I think the site, and
some of the commentary surrounding it, suggest issues that we need to
address.

So, let's consider the site, <http://haenfler.sites.grinnell.edu/>.
It's the course site for Ross Haenfler‘s course on Deviance and Youth
Subcultures.  Now, the content of it looks really cool, with student
essays (or subsites) on afropunk, bronies, riot grrls, and more.  And the
images are also really neat.  It's almost enough to make me want to be
a student again.  In addition, the `sites.grinnell.edu` suffix suggests
that we're finally finding a way to provide the promised venue for
student and faculty Web work [4].  That makes me happy.

But behind those two large positives are some significant problems.  The
site contains all of these cool images.  None of them seem to have an alt
tag [5], the most basic step in Web accessibility.  That's problematic,
and the most obvious accessibility issue of the Web page.  Unfortunately,
it also leads to a number of other things that I find problematic.

When I raised the issue at the Library presentation, the buck got passed
to one of our Digital Liberal Arts Specialists who had helped set up
the site.  His responses?  First, to say that he told students about a
accessibility, including alt tags, when he started them working on the
site and that it's hard to get students to follow guidelines.  Second,
to say that it would get cleaned up at the end of the project.  Third,
to suggest that we'd use SiteImprove to identify accessibility issues.
Let's consider each of those responses.

I realize that new Web authors have difficulty with things like
accessibility.  However, I was commenting on the top-level of the site,
which I'm pretty sure that the faculty member developed the top-level in
consultation with the DLAS [6].  It's not a student issue that we don't
have alt tags there. It's a faculty and instructional designer issue.
Those two should know better.

Next is the question of when to address accessibility.  It is easier
and cheaper to address accessibility from the start, rather than to go
back and retrofit a site [8].  For example, when you add an image; add
a description.  That way, the person who understands the image is the
one adding the explanatory text.  Thinking about accessiblity from the
start helps ensure that the overall design of the site is accessible.
Rebuilding a site because of an inaccessible overall design is a huge
and expensive PITA [9], as I think we've already found in many other
situations.

That leads us to the third claim, that automated tools
suffice to let us know what's going on.  The first thing I did
with <http://haenfler.sites.grinnell.edu/> is to run it through
[WAVE](http://wave.webaim.org/), a free Web accessibility evaluation tool.
Interestingly, WAVE finds neither errors nor alerts on the page.  How can
that be, given the ever-changing images which seem to have no alt tags?
That took a little exploration on my part.  It turns out that the cool
slideshow feature that they use does so by rotating the background image.
Since background images are usually not needed by the viewer, they aren't
required to have alt tags.  However, these images do convey meaning to
the viewer, and therefore need alt tags.  

Even if we ignore that problem, there's the whole question
of using a rotating slide show (aka "carousel").  I'm not
experienced enough in Web accessibility to know whether or not
these rotating slide shows have general accessibility issues,
but I would think so.  Let's see what I can find on the Interweb.  [One
article](http://www.accessiq.org/create/content/carousels-and-slideshows-accessibility-for-developers)
suggests that

>  [T]he best way to make a carousel accessible is to give the user control of it. This guideline has two main points. The amount of time available to perform an action required of the user can be modified or stopped by the user, and the user can easily control any moving content, both of these in an accessible manner.

As far as I can tell, this slide show doesn't meet those guidelines.
What does the W3C say?  Well, they have [some in-progress
guidelines](https://www.w3.org/WAI/EO/Drafts/tutorials/sliders/).
In addition to user control, they suggest that captions are helpful,
as is a header for the carousel itself.  The slide show on this site
doesn't meet those guidelines, either.

And so we are back to my prior comment: *You don't add accessibility at
the end; you design in accessibility from the start.*  I don't envy Ross
or the DLAS in having to go back and turn this inaccessible slideshow
into an accessible slideshow, or in having to go back and caption and
annotate the slides.

I think `sites.grinnell.edu` uses WordPress.  (Okay, I know it uses WordPress,
since the `haenfler.sites.grinnell.edu` says that it's a WordPress site.)
Before we go too far in having our faculty and students use WordPress, we
should make sure to identify a subset of WordPress templates that are
accessible, and restrict folks to using those templates.  If WordPress has
no accessible templates, we need to build some.

Now, I realize that some of the folks at the College charged with
designing Web sites have difficulty understanding accessibility (not
[our primary Web designers](anderson-dralus.html), but folks responsible
for things like <http://pioneers.grinnell.edu>).  Nonetheless, that is not
an excuse for this site, or for any other site on campus with significant
accessibility issues.

---

I'll note that we also need to think more carefully about things beyond
accessibility.  For example, it's not clear why the "Subcultures and
Sociology" subdomain is `haenfler`.  Yes, I know that Ross Haenfler
is teaching that course.  But what happens when he teaches a course
on another subject?  Will that be `haenfler2.sites.grinnell.edu`?
Shouldn't our names reflect the course or topic, rather than the prof?
I see that we get to choose the subdomain name.  However, I would hope
that those skilled in such issues would suggest sensible domain names.

One final comment, because I'm irritated.  I'm glad to see that
`sites.grinnell.edu` uses an alt tag for the image at the top of the page.
However, "Grinnell_002" is not an acceptable alt tag.  Our Head Chief
Badgerer or her frequently badgered minions should know better.

Nevermind.  I'm wrong.  That wasn't my final comment.  One additional
comment because I'm even more irritated.  On the [request a
site](http://sites.grinnell.edu/request/) page, there's the following
statement.

> Grinnell College has adopted an Academic Sites Policy that defines
the purpose, requirements, and support commitments for academic
websites. Please read the policy ([DRAFT]<http://web.grinnell.edu/cts/reclaim/AcademicSitePolicyVersion5.pdf>).

"Yeah. No.", as my students are fond of saying.  We have not yet
adopted the policy.  That's why it's a *draft*!  It hasn't passed
through the Instructional Support Committee.  Claiming that it has
already been adopted when no official body has signed off on it is
inappropriate.

---

I hate being critical of well-meaning individuals.  I really appreciate
the hard work that is going in to sites.grinnell.edu.  But that hard
work needs to be accompanied by some broader considerations.  Otherwise,
the work will be even harder in the future.

---

[1]: Faculty Fridays are a relatively new regular event at Grinnell.
Each Friday, folks in the Dean's office and the Center for Teacher,
Learning, and Assessment identify a topic of interest to a broad range
of faculty and invite us to lunch and discuss (or hear about) the topic.
Faculty Fridays don't replace the good old Faculty House Wednesday lunches
[2], but they do provide a useful way for faculty to chat together about
issues of interest.

[2]: I hope to see those return some time soon.  The once per semester
social Faculty Fridays don't quite cut it.

[3]: You will not be surprised to hear that I said something like that
in the middle of the presentation.  That is, I said something like "I find
it troublesome that the two things you just showed us have accessibility
issues, particularly given that we just had the public release of our
accessibility task force report" and then went on to explain.  Oh, yeah,
I probably said something like "It's not only our legal responsibility,
but our moral responsibility, to make sure that our sites are accessible."
I'm not very polite about these issues.

[4]: I believe that thanks are due to the Head Chief Badgerer of the
Forum Basement.

[5]: Alt tags are pieces of code that you associate with images in Web 
pages that describe the image.  They allow people with limited vision
to understand the images.  Alt tags also help those with limited
bandwidth, or those who may not understand the images.

[6]: I have no idea whether or not other people turn "Digital Liberal
Arts Specialist" into "DLAS".  However, given our propensity for
TLAs and FLAs [7] at Grinnell, I'm pretty comfortable using it.

[7]: Three-letter acronyms and four-letter acronyms.

[8]: It may even be our legal responsibility for official College sites.

[9]: Pain In The Neck.

---

*Version 1.0 of 2016-12-04.*
