---
title: Farewell MathLAN Web Server
number: 
tags: [Technology](index-technology)
blurb: You shall be missed.
version: 0.1
released: 
current: 2020-01-10
---
Last year, ITS made the decision to decommission the MathLAN Web
Server or at least many of the primary uses of the MathLAN Web
Server.  In many ways, the decision was reasonable; while serving
pages from home directories made sense two decades ago, it now seems
to be a bit of a security risk.  Unfortunately, the risk has gotten
worse of late, not least because updates to our Drupal server often
get delayed [1].

So, over the next [fill in period of time] [2], we'll be moving our
personal Web areas.  For example, the page you previously found at
<https://www.cs.grinnell.edu/~rebelsky/cv.html> will now be found
at <https://rebelsky.cs.grinnell.edu/cv.html>.  As I suggested,
putting our Web areas on a separate machine makes sense; that way,
even if someone breaks in through a Web page, they can't access
other files in our home directories.  I'm less certain about the
transition to separate servers for each person.  It does keep the
system more secure; if someone can break in through, say, a student
account, they still can't access my Web files.

What about the departmental pages that live on the MathLAN Web
server?  That's still to be determined.  We'll likely move the
documentation of the museum collection to Islandora or some other
College site designed for archiving.  But the information about the
department and such?  I have no clue.  We discussed putting it on
the primary www.grinnell.edu site, but I'm not sure how Communications
would feel about that, and what arrangements we could make to ensure
that the department can make timely updates.  It may be that we
retain www.cs.grinnell.edu as a separate server, but only use it
for CS department pages.  In any case, I'm assuming that ITS,
Communications, and CS will be able to figure out some direction
forward.

As I said, I still don't understand all of the details of what
happens next, even with individual sites.  For example, while I
know what's happening with the individual sites, I don't know what
will happen when we want to teach students how to create their own
sites with raw HTML and CSS.  Having students create Web pages in
class used to be a five-minute task: Create a `public_html` directory,
change permissions, copy this HTML file, open it in your Web browser,
make some changes to the file, observe that the changes show up,
create your own.  Now we're going to have to have them transfer
files over to a separate server.  It's not as easy and not as
natural.  And students might even have to configure their servers.
Bleh.  Doing Web development in class will also have to be a less
spur-of-the-moment activity, since I expect that the
`username.cs.grinnell.edu` sites will need to be set up in advance
[5].  On the other hand, having separates sites may provide some
advantages, at least for some situations.  Nonetheless, I'm glad that
I have spring semester to figure things out before I teach this stuff
next Fall.

It makes me sad to know that the server is going away, at least in
the sense I think of it.  The MathLAN Web server [3] was the first
Web server on campus.  It was set up before I arrived at Grinnell.
Knowing our SysAdmin, it probably existed within a year or two of
the initial creation of the World Wide Web.  I don't like to lose
that bit of history.  It's also been an important force on campus;
it was the first place that Grinnellians [4] could play with building
Web pages, then the first place the Grinnellians could play with
building database-backed Web pages, then the first place Grinnellians
could play with building more complex Web services, and then, once
again, the only place in which people could create their own sites.

Farewell, MathLAN Web Server.  You supported a great deal of learning.
You shall be missed.

---

Postscript: Adjusting to the change in URLs is likely to require a
significant amount of work on my part.  I'll report on that in a
subsequent musing.

---

[1] It's not clear where that responsibility lies.  Some of the delay has
to do with department inattention, but some also belongs in ITS.

[2] The time frame is not clear.  I understood that it would happen over
winter break.  But there's only one week of Winter break left, and we
have not yet had the opportunity to play with even a test site.

[3] More precisely, www.math.grin.edu.

[4] Students, faculty, and staff.

[5] Students may already have `username.sites.grinnell.edu` sites.
However, those will often be WordPress sites and may even serve as
student portfolios.  The raw HTML experimentation should happen
elsewhere.
