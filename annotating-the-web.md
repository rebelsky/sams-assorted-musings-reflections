Annotating the Web
==================

Topics/Tags: autobiographical, research, hypertext, intellectual property,
the Web

*Disclaimer: I'm using this musing to reflect on a number of issues.
It may be even less linear and structured than normal.*

Recently, my colleagues in Grinnell's [Center for Teaching, Learning,
and Assessment](https://www.grinnell.edu/academics/centers/ctla)
have started using [hypothes.is](https://web.hypothes.is/)
to collaboratively annotate Web pages.  For example,
you can see [some notes on my musing on measurable course
outcomes](https://via.hypothes.is/http://www.cs.grinnell.edu/~rebelsky/musings/measurable-course-outcomes).
Their use of Web annotation software got me thinking about my early
research career at Grinnell [1].

I arrived at Grinnell in the fall of 1997 with two projects that I
collectively referred to as "violating Web norms".  What did I mean
by that?  In one project, my students and I built tools that gathered
data about Web browsing, violating what were, at that time, privacy norms
[3], so that we could study the ways in which more successful and less
successful students used Web-based course resources.  I'll write more
about that in a subsequent musing.  In the second project, we built 
tools that allowed students to manipulate the pages they viewed,
thereby violating norms of ownership.

What motivated that second project?  The Web was young.  The Web had
only been around for a few years.  Altavista was probably the leading
Web browser.  People still thought it would be useful to have a "table
of contents" for all the pages on the Web [4].  But I saw conflicts
between how the Web was being used by those encountering [5] the underlying
ideas for the first time and those who thought about hypertext more
broadly.  

Most scholars of hypertext of the time
pointed to Vannevar Bush's 1945 article "[As We May
Think](https://www.theatlantic.com/magazine/archive/1945/07/as-we-may-think/303881/)"
as an important precursor to the Web and as providing important guidance
for necessary development.  Bush's model of hypertext was much richer
than that of the early Web.  Among other things, he envisioned people
who would put together articles (or "trails") by finding a sequence of
useful pages in different sources, annotating those pages, inserting a
few pages of their own, and linking it all together.  While the Web had
"live links", those links were limited to the original authors of the
text, so The Web provided essentially none of the features necessary
for Bush's more collaborative model.

In my arrogance, I thought I could make a difference.  I had students work
on building tools for annotation (that is, adding notes to arbitrary Web
pages) and trail blazing (that is, adding links to arbitrary Web pages).
At the time, it seemed possible that a group of smart students could build
such tools.  The projects were also a good level for students in that
they could both apply knowledge from classes (e.g., to parse the HTML)
and consider new issues (e.g., How do you deal with an annotation that
is associated with a piece of text on a page that then changes?  In
fact, how do you know whether the page has changed?).  The students
did a lot and learned a lot.  

Of course, it was also a huge detour from my graduate research on lazy
functional programming.  Sometimes you adapt your research to meet the
needs of your students.  I also thought it was an important and fun
issue.

In the second summer or so, we discovered that someone patented a
project similar to one of these.  If I recall correctly, it was a tool
that allowed people to annotate Web pages in some way or other.  And so
I asked the administration what support I had for figuring out whether
my project violated (or perhaps negated) that patent.  The answer was
surprising, approximately "Grinnell claims no ownership of your patentable
material and so provides you with no resources in situations like this."
I like the idea that Grinnell makes [6] no claims on my IP.  However,
I'm pretty sure that it should have under US law, particularly given
that that's a requirement of the Bayh-Dole Act of 1980 [7].

I seem to recall there was also a hullabaloo about annotation and linking
tools at the same time.  If I recall correctly, people were writing on
the new WhiteHouse.gov site and adding inappropriate links.

In spite of those issues, the projects were also fairly successful.
The students' work garnered a few "Outstanding paper" awards at large (1000+
person) conferences and at least one standing-room-only presentation [9].

Then the Web got much more complex.  It's much different to deal with
a static page with no separate layout information than a page with CSS
or a dynamically generated page with JavaScript.  It did not seem that
a faculty member teaching five courses per year and a rotating cadre of
undergraduates could keep up.  And so my research went necessarily went
in other directions.

Do I think we did useful stuff?  Yes.  Did anyone use it, other than us?
Nope.  Were there significant IP issues, many of which I was not equipped
to deal with?  Certainly.  In response to those issues, I did start a
side project on how page authors can provide meta-data on what is and is
not reasonable to do to their page.  I think the Web still needs such
a standard.  Were others working on similar issues at the same time?
Certainly.  Did any of my work have any influence?  Probably not; most
of what we came up should be natural, at least if you pay enough
attention.  I'm just surprised that it took more than a decade for folks
to pay enough attention that we're finally seeing good collaborative
annotation tools.

Would I be better known and wealthy if I'd pursued this approach
seriously?  Perhaps.  Many people who built new Web technologies
did pretty damn well.  Am I bitter?  Not really.  I love what I do
and I'm well compensated.  But, once in a while, I do wonder what would
have happened if I'd pursued these projects, and others like them [10],
more seriously.  But I'm not good at bringing projects to fruition.
My marketing skills also leave something to be desired. C'est la vie.
I also know that some fairly awesome projects, like [Print What You
Like](http://www.printwhatyoulike.com/) never got as far as I would have
expected them to.

Is there a moral to all this?  Probably not.  I'm just glad that there
are now good annotation toolkits.  I wonder how they deal with pages
that change.  I also wonder if there are good trail-building kits yet.
Does anyone know?

---

Postscript: You may annotate this page with Hypothes.is or other
annotation toolkit, provided it is clear that the added text is not
my own.  You may add links to the page (or to other people's view of
the page), provided it is clear that the links were added and are not
my own.  You may excerpt portions of this page to present in other pages,
provided you provide an appropriate citation.  You may include this page
(or portions thereof) in a Frame.  Please contact me about other potential
(re-)uses.

---

[1] I started writing this musing on January 7, 2018.  It took almost
three months to finish it [2].  In that time, I also saw Erik Simpson talk
about annotation systems in his Lighting the Page course.  I also see
that we have a talk this coming Tuesday by Dr. Jeremy Dean, Director of
Education for Hypothes.is.  The announcement of that talk help spurred
the release of this musing.

[2] I spend about 1.5 hours changing the notes from the draft into the
final musing.  So "started writing" may be a bit of misnomer.  Of course,
things likely would have gone faster if I had not managed to delete a
few paragraphs of new text before I saved it.

[3] How norms have changed.  At this point, I think everyone expects that
almost every page you visit will try to gather information from you.

[4] Yes, that's one of the origins of Yahoo.

[5] Or even developing for it.

[6] Well, made.

[7] It took nearly twenty years, but Grinnell now has a Patent Policy of
sorts.  It is, as in way too many other circumstances, still awaiting the
associated procedures and documents [8].

[8] Or at least it was when I last looked.  I resigned my position on the
Patent Policy Task Force during my overcommitted fall.

[9] The student who gave the SRO presentation just won a technical Oscar.
She's clearly a spectacular thinker.

[10] What other topics? I was working on Web-based teaching by 1994.
I even published an early paper on it in the 2nd WWW Conference.  I had
built a Markdown-like tool to simplify the construction of Web sites by
1995.  John Stone even asked me about it when I interviewed at Grinnell
[11].  I wrote an e-commerce toolkit in 1996, primarily for my friends
at Jessica's Biscuit who ran a mail-order cookbook store [12].  There are
probably a few more that I've forgotten about.

[11] Until I wrote this musing, I would have sworn that I called it
"Web Raveler".  But I didn't start using that name for it until after
I arrived at Grinnell.  I had forgotten that I called the prior version
"Site Weaver".   And yes, I know that you don't care about those piddling
details.

[12] In high school, one of my jobs was to run the mimeograph machine
for their newsletter.

[14] This is just a sampling.  I'd forgotten how productive these early 
projects were.  I wonder if I can reach that level of productivity again.

[15] The trip to Denver for this conference remains one of my favorite
memories of my time working with students.  We drove there and back
and played car games along the way.  I've added that trip to my list of
potential musings [16].

[16] I suppose if I include the driving trip to Denver, I should also
include the trip to Montreal.  After all, that's one of the reasons that
I can say "My children had a famous comedian as a sitter", or at least
I think it is.  I wonder if I can remember all of the students who went
and figure out what they are doing now.  I'd say that I can probably
identify a current job for at least 80% of them.

[17] I realize that it may appear that as chair of the conference, I could
have had an influence on the selection of outstanding paper.  But once
our reviewers had identified an anonymous version of this paper as a
candidate for outstanding paper, I withdrew from the selection process
for outstanding papers.  My co-chair and the AACE directorship selected
those papers.

---

**Selected references**

_Here are some of the papers my students and I wrote on these and related 
topics._

Samuel A. Rebelsky (1994). A web of resources for introductory computer
science. In _Proceedings of the 2nd International WWW Conference ’94:
Mosaic and the Web_ (Chicago, Illinois, USA, October 17–20, 1994),
I. Goldstein and J. Hardin, Eds., pp. 487–497.

Samuel A. Rebelsky (1996). Improving WWW-aided instruction: A report from
experience. In _EdMedia 1996 World Conference on Educational Multimedia,
Hypermedia, & Telecommunications_ (Boston, Massachusetts, USA, June
17–23, 1996), P. Carlson and F. Makedon, Eds., Association for the
Advancement of Computing in Education, pp. 103–108. Received outstanding
paper award.

Samuel A. Rebelsky (1997).  Courseweaver: A tool for building course-based
webs. In _Proceedings of the EdMedia’97 World Conference on Educational
Multimedia and Hypermedia_ (Calgary, Canada, June 14–19, 1997),
T. Muldner and T. C. Reeves, Eds., Association for the Advancement of
Computing in Education, pp. 881–886

Samuel A. Rebelsky and Christopher De Beer '98 (1998).  A customizable
shorthand system for hypertext authoring. In _Proceedings of the Webnet
’98 World Conference of the WWW, Internet, and Intranet_ (Orlando,
Florida, USA, November 7–12, 1998), H. Maurer and R. G. Olson, Eds.,
Association for the Advancement of Computing in Education, pp. 744–749.

Raphen Becker '99, Kevin McLaughlin '99, and Samuel A. Rebelsky (1999).
Project Clio: Tools for tracking student use of course webs. In
_EdMedia 1999 World Conference on Educational Multimedia, Hypermedia,
& Telecommunications_ (Seattle, Washington, USA, June 19–24, 1999),
B. Collis and R. Oliver, Eds., Association for the Advancement of
Computing in Education, pp. 981–986.

Sarah Luebke '00, Hilary Mason '00, and Samuel A. Rebelsky (1999).
Annotating the World Wide Web. In _EdMedia 1999 World Conference on
Educational Multimedia, Hypermedia, & Telecommunications_ (Seattle,
Washington, USA, June 19–24, 1999), B. Collis and R. Oliver, Eds.,
Association for the Advancement of Computing in Education, pp. 409–414.

Corinne Glynn '02, Rachel Heck '01, Sarah Luebke '00, Weichao Ma '01,
Hilary Mason '00, Erin Nichols '02, Eleanor Raulerson '02, Isabel Staicut
'03, and Samuel A. Rebelsky (2000).  Blazing trails on the world wide
web. In _EdMedia 2000 World Conference on Educational Multimedia,
Hypermedia, & Telecommunications_ (Montreal, Quebec, Canada, June
26–July 1, 2000), J. Bourdeau and R. Heller, Eds., Association for
the Advancement of Computing in Education, pp. 335–340. Received
outstanding paper award.

Gregory Fuller '03, Joseph Simonson '02, Ananta Tiwari '04, and Samuel
A. Rebelsky (2002).  Clio’s assistants: A tool suite for exploring
student web usage.  In _EdMedia 2002 World Conference on Educational
Multimedia, Hypermedia, & Telecommunications_ 
(Denver, Colorado [15],
USA, June 24–29, 2002), P. Barker and S. A. Rebelsky, Eds., vol. 1,
Association for the Advancement of Computing in Education, pp. 550–555.

Angela Kmiec '04, Melissa P. Pinchback '04, and Samuel A. Rebelsky
(2002).  Summarizing links: Issues and interfaces. In _EdMedia 2002 World
Conference on Educational Multimedia, Hypermedia, & Telecommunications_
(Denver, Colorado, USA, June 24–29, 2002), P. Barker and S. A. Rebelsky,
Eds., vol. 2, Association for the Advancement of Computing in Education,
pp. 1005-1010.  Received Outstanding Paper award [17].

---

*Version 1.0 of 2018-04-01.*
