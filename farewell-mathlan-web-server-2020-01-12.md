---
title: Farewell MathLAN Web Server
number: 984
tags: [Miscellaneous](index-misc), technology
blurb: You shall be missed.
version: 1.0
released: 2020-01-12
current:
---
The MathLAN Web server [1] was the first Web server on campus.  It
was created before I arrived at Grinnell.  Knowing our SysAdmin, it
probably existed within a year or two of the initial creation of
the World Wide Web.  I don't like to lose that bit of history.  It's
also been an important force on campus; it was the first place that
Grinnellians [2] could play with building Web pages, then the first
place the Grinnellians could play with building database-backed Web
pages, then the first place Grinnellians could play with building
more complex Web services, and then, once again, the only place in
which people could create their personal sites [3,4].

Last year, ITS decided to decommission the MathLAN Web Server (or
at least many of the primary uses of the MathLAN Web Server).  In
many ways, the decision was reasonable; while serving pages from
home directories made sense two decades ago, it is now clearly a
security risk.  Unfortunately, the risk has gotten worse of late,
not least because updates to our Drupal server often get delayed
[5].

So, over the next [fill in period of time] [6], we'll be moving our
personal Web areas to separate servers.  For example, the page you
previously found at <https://www.cs.grinnell.edu/~rebelsky/cv.html>
will soon be found at <https://rebelsky.cs.grinnell.edu/cv.html>.
More importantly, the files that used to live in
`/home/rebelsky/public_html` on the MathLAN file server will soon
live on a separate machine.  More importantly, files that are not
in my `public_html` directory *won't* be accessible to the Web
server.

As I suggested, putting our Web areas on a separate machine makes
sense; that way, even if someone breaks in through a Web page, they
can't access other files in our home directories or files in other
people's directories.  I'm less certain about the transition to
separate servers for each person.  It does keep the system more
secure; if someone can break in through, say, a student account,
they still can't access my Web files.

What about the departmental pages that live on the MathLAN Web
server?  As far as I know, what is happening with them is still to
be determined.  We'll likely move the documentation of the museum
collection to Islandora or some other College site designed for
archiving.  But the information about the department and such?  I
have no clue.  We discussed putting it on the primary www.grinnell.edu
site, but I'm not sure how Communications would feel about that,
and what arrangements we could make to ensure that the department
can make timely updates.  It may be that we retain www.cs.grinnell.edu
as a separate server but only use it for CS department pages.  In
any case, I'm assuming that ITS, Communications, and CS will be
able to figure out some direction forward.

As I said, I still don't understand all of the details of what
happens next, even with individual sites.  For example, while I
know what's happening with the individual sites, I don't know what
will happen when we want to teach students how to create their 
sites with raw HTML and CSS.  Having students create Web pages in
class used to be a five-minute task: Create a `public_html` directory,
change permissions, copy this HTML file, open it in your Web browser,
make some changes to the file, observe that the changes show up,
create your own.  Now we're going to have to have them transfer
files over to a separate server.  It's not as easy and not as
natural.  And students might even have to configure their servers.
Bleh.  Doing Web development in class will also have to be a less
spur-of-the-moment activity since I expect that the
`username.cs.grinnell.edu` sites will need to be set up in advance
[7].  

You might say that almost no one creates raw HTML pages anymore.
And, if you said that, you would be correct.  But our goal is not
for people to build Web pages.  Rather, it's for students to
understand the underlying technologies, such as the hierarchical
structure of Web pages or the separation between content and
appearance that CSS supports.  We want the students to understand
these issues so that they can build programs that build or analyze
Web pages.  So having them run their own servers is tangential to
our learning goals.

I'm hoping that having separates sites and giving students more
administrative control may provide some advantages, at least for
some situations.  Nonetheless, I'm glad that I have spring semester
to figure things out before I teach this stuff next Fall.

It makes me sad to know that the server is going away, at least in
the sense I think of it.  Farewell, MathLAN Web Server.  You supported
a great deal of learning.  You shall be missed.

---

Postscript: Adjusting to the change in URLs and infrastructure is
likely to require a significant amount of work on my part.  I'll
report on that in a subsequent musing.

---

[1] More precisely, the original `www.math.grin.edu`.

[2] Students, faculty, and staff.

[3] I've written about that issue in [an earlier
musing](long-term-concerns-2019-12-13).

[4] These days, sites.grinnell.edu is helping pick up that role again.

[5] It's not clear where that responsibility lies.  Some of the delay has
to do with department inattention, but some also belongs in ITS.

[6] The time frame is not clear.  I understood that it would happen over
winter break.  But there's only one week of Winter break left, and we
have not yet had the opportunity to play with even a test site.

[7] Students may already have `username.sites.grinnell.edu` sites.
However, those will often be WordPress sites and may even serve as
student portfolios.  The raw HTML experimentation should happen
elsewhere.
