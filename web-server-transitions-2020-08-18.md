---
title: Adventures in Web server transitions
number: 1108
tags: [Miscellaneous](index-miscellaneous), Technology [1], Rambly
blurb: So many complexities!
version: 1.1
released: 2020-08-18 
current: 2020-08-18
---
**_Warning!  This musing is too technical for non-technical people and
not techincal enough for technical people.  It's also rambly and
unedited.  But my muse insisted I get something out, particularly
since this has been on my "to write" list since January 12.  Deal._**

As I noted in [a no-longer-recent
musing](farewell-mathlan-web-server-2020-01-11), my Web pages are
moving from <https://www.cs.grinnell.edu/~rebelsky/> to
<https://rebelsky.cs.grinnell.edu> [2].  As I looked at the task ahead,
I knew it would be an adventure.  Here are some of the things I
worried about along the way.

_Paths and URLs_.  While I try to use relative URLs, I haven't always done so.
It's not always possible to do so, either.  I've put further notes on this
issue at the end, since I wrote them first [3].

_CGI scripts_.  I'd swear they didn't work in January, when I started the
adventure.  But they work now [4].  So all is good.

_http-to-https redirects_.  The Web relies on two basic protocols,
plain Hypertext Transfer Protocol (http) and Secure Hypertext
Transfer Protocol (https).  Most modern Web servers that permit
secure access automatically redirect http requests to https requests.
I believe some pundits even suggest that you should never use
non-secure [6] http.  I didn't expect to need to fiddle with this
issue but the redirects were not enabled automatically.  I wish I'd
written down what I did, because I'm pretty sure I'll need to regenerate
a certificate at some point.

_File suffixes_.  The MathLAN Web server was configured to automatically
negotiate file suffixes.  For example, if you visited
<https://www.cs.grinnell.edu/~rebelsky/musings/web-server-transitions-2020-08-18>,
our server would figure out that you wanted the file with the `.html`
suffix [7].  Our new servers were not configured that way.  Why?  I'm not
sure.  But it seemed that I would need to learn more about Apache
configuration as part of this transition.  More details after this list.

_Error handling_.  What happens when you request a page and the page does
not exist?  You typically get an error message.  I assumed that the default
configuration would have a useful error message.  I was wrong.  Here's
what you see.

> **Not Found**

> The requested URL was not found on this server.

> Additionally, a 404 Not Found error was encountered while trying to use an ErrorDocument to handle the request.

More on error handling will also appear after this list.

_Canonical URLs_.  You can often refer to the same Web page with
multiple URLs.  For example, you can refer to the home page for the
musings as <http://www.cs.grinnell.edu/~rebelsky/musings/index.html>
or <http://www.cs.grinnell.edu/~rebelsky/musings/index> or
<http://www.cs.grinnell.edu/~rebelsky/musings/> or
<http://www.cs.grin.edu/~rebelsky/musings/> or
<http://www.math.grin.edu/~rebelsky/musings/> or
<http://www.math.grinnell.edu/~rebelsky/musings/> or a bunch of
other things.  To help various Web software, you often associate a
"canonical URL" with each page.  That URL is not supposed to change.
So what happens when my URLs have to change?  I'm not sure.  The
biggest issue will be with [hypothes.is](https://web.hypothes.is).
I haven't had time to investigate the issue.  For now, I'm hoping
I can keep the old URLs as canonical and rely on redirects.

_Building pages_.  I rarely author in raw HTML.  Instead, I rely
on a host of programs to build the pages, from scripts I wrote more
than twenty years ago [7] to Jekyll and Pandoc.  While I know that
modern practice is to build the pages in one place and then transfer
them elsewhere, I like to build pages in place.  That's not going
to work any more, at least not with Pandoc [8].  Time to change my
workflow!  I wonder what that means for the eboards?   And what
about my custom scripts?  I almost forgot about those.  I'll get
back to you on them.

_Google PageRank_.  Some of my Grinnell pages have existed since
before there was a Google [9].  That meant that many of them had
some historical PageRank value, or something like that.  All I know
is that some of my pages show up surprisingly easily in Web searches.
I wonder if I'll lose that, too.

---

**_Negotiating file suffixes_**

It appears that my original communications with our hosting company
about this issue were not clear or not clear enough.  They dealt with
the issue that <https://rebelsky.cs.grinnell.edu/origin> should load
<https://rebelsky.cs.grinnell.edu/origin.html>, but not with any of
the other suffixes, like `.cgi`, `.jpg`, or `.png`.  The reason was
fairly obvious; they added a rewrite rule.

    RewriteRule ^([^\.]+)$ $1.html [NC,L]

But that's only for the single case of "no suffix means use `.html`".
I wanted a more general solution.  After some time playing, I realized 
that "There's a standard server setting for that".  It appears that I
can't edit the Apache config file, but I can add the following to the
top-level `.htaccess` file.

    Options +MultiViews

It took awhile to find that setting.  After all, if you think of
it as "suffix completion", realizing that the proper feature name
is "Content Negotiation" takes some time.  I just wish (a) the folks
at Reclaim hosting would have suggested this and (b) we had started
with configurations that matched that MathLAN Web server.

---

**_Error handling_**

Apache lets you configure how to handle errors.  I had assumed we'd have
some default setup, but it appears we do not.  That's okay; it gives me
an excuse to learn a bit more about this issue and maybe even figure out
how to use it with the musings.

Here's what [the documentation I received](http://www.htaccess-guide.com/error-documents/) suggests as a basic approach.

    ErrorDocument 404 /error_pages/404.html

Of course, that's not really the best way to handle errors, but
it's a start.  And yes, it works.  But I like nicer messages.  Let's
see what I can figure out.  Let's start with [the real
documentation](https://httpd.apache.org/docs/2.4/custom-error.html).  That
suggests that I can access the some environmental variables.  But
then I need to worry about sanitizing my inputs.  And it appears
that I can't install new CPAN modules on GrinnellSites.  Bleh.
Well, I'll stick with a simple script.  I shouldn't be spending my
time on such tasks right now.  Classes start in less than two weeks.
But I now have a framework in place.  And the Apache-related environment 
variables should be safe.  Right?  Fingers crossed.

You can see what it does by going to a URL like
<https://rebelsky.cs.grinnell.edu/blahblahblah>.

Eventually, I'm going to write a custom handler for the musings, one
that figures out which musing you want if you only type part of the
title.  But that's an adventure for another day [10].

---

**_Building Sites_**

As I mentioned earlier, I know that current practice is to build sites
on one host and then push them to another.  But I really like building
them in place.  Among other things, it means that it's easy to, say,
quickly push a formatted version of an eboard.  I guess that's not going
to happen any more.

For the Jekyll subsites, things should be easy.  I have a script to push
the pages.  I just don't use it.  I may have to update it.

For the musings, things will be a little bit harder.  Basically, I need
to write instructions for copying over the html files.  `rsync` is the
typical command.  I just need to get the settings right.  Here's my first
step.

    time rsync -avz *.html rebelsky.cs.grinnell.edu:/home/rebelsky/public_html/musings
    time rsync -avz images rebelsky.cs.grinnell.edu:/home/rebelsky/public_html/musings

I didn't really need two separate commands, but it seemed a bit easier to
do things that way.  About 18 seconds to sync the `.html` files.  A
bit longer to sync the images.  And when I write "a bit longer", I seem to
mean "a lot longer".  Four minutes and forty-five seconds, to be exact.
But that's probably because it was transferring files.  What happens if
I try again?  1.4 seconds and 1 second, respectively.  I love rsync.

What's left?  That's right, the hacky set of scripts I wrote right before
and after I came to Grinnell that I refer to as "Siteweaver".  Basically,
an extended version of Markdown before there was Markdown (and before I
was smart enough to write something better than what I wrote).  Amazingly,
even though I haven't touched the code in nearly forever (e.g., one of the
key libraries was last updated February 3, 2003), it seems to have ported
fine, once I remembered what I needed to move [11].  It appears that 
mediocre, simplistic, old Perl code ports well.

---

**_The joy of references_**

_I started this musing in January 2020.  Here's a slightly updated
version of some of the text I wrote back then, having to do with the
problems of references._

One part of the adventure was dealing with the 36,000 files [12] in
my `public_html` hierarchy.

Why wasn't it just a matter of copying files over?  There are lots of
reasons.  

The most significant issue has to do with how files are connected.
We connect files in multiple ways.  For example, we might create a
link from
one page to another so that you can click on a phrase in one page
and end up on the other or we might assign a style sheet to a Web
page so that the Web browser knows how to render the page.  There
are three basic ways we refer to these other files: We can provide
a full URL, including the site name; we can provide a relative URL,
specifying where the other file is relative to the current one on
the same server; or we can do something in-between, an absolute
"from the root" path to a file on the same server.  For example,
another musing might link to this in any these ways

* Absolute: `https://www.cs.grinnell.edu/~rebelsky/musings/adventures-web-server-transition-2020-08-18.html`
* Relative: `adventures-web-server-transition-2020-08-18.html` or
  `./adventures-web-server-transition-2020-08-18.html` or even
  `../musings/adventures-web-server-transition-2020-08-18.html`
* From-the-root `/~rebelsky/musings/adventures-web-server-transition-2020-08-18.html`

Which is the best strategy?  It depends on what you're doing.  These days,
I often use relative URLs because it makes it easier to move sites around.
But I haven't always done that.  I know that [some sites recommend
"from the root" URLs](https://www.wimpyplayer.com/docs/common/urls.html),
like the third of my examples above, and I've certainly used that strategy
in the past.  I see that I even use it for my home page.  Oh, that's
right; I have a wide variety of pages in multiple directories that use
the same template.  They should also use the same URLs to reach things.

So, what will happen when my pages move?  Ideally, those that use relative
URLs will be fine.  Those that use absolute URLs may work, at least for
a bit of time, because we're supposed to have automatic redirects from
the old CS URLs to the new ones.  But the "from-the-root" URLs?  Those
will all break.  I wonder how many files have that issue.

A day or two later, I figured out an evil hack.

    ln -s /home/rebelsky/public_html /home/rebelsky/public_html/~rebelsky

That seems to work.

At some point, I need to look through and see what I've broken.  But
for now, I'm pretty happy, or at least as happy as I can be.

---

**_Concluding thoughts_**.  This started out as a somewhat overwhelming
project, not least because the first few things I tried didn't work.  Each
time I came back to it, something new seemed to go wrong.  But these last 
few days have gone smoothly.  I figured out the content negotiation.
I figured out the error handling.  I was able to write a quick script
to shove the musings on the new site.  Technology isn't supposed to
work like that; something must be wrong [14].

Am I done?  No.  I need to a pass through the old site to see what I
haven't copied to the new site.  I need to make a list of the different
workflows for the different subsites.  I probably need to set up a few
repos for the things not yet in repos.

Someday, I'll also need to clean up the random cruft that lives on
my Web site.  But that someday is not today.

In any case, I'm done enough for now.  I wonder when our SysAdmin expects
to be able to move the links.

---

**_Postscript_**: I still haven't figured out what I'm going to do about
my normal teaching processes.  For those who haven't been in my
class, I use the computer as my white board, typing in a terminal
window.  Since I type in Markdown, I can quickly convert that file
to HTML.  That means that students can easily read what I'm typing
on their individual computers as well as on the big screen and that
the materials are available after class.  It also means that students
who are sick in their rooms can follow along if they so choose [15].

However, I don't think our new Web model will easily support this
approach.  I probably can't do live editing on the new server.

---

**_Postscript_**: I was right.  Or maybe I was wrong.  In any case, after
I "published" this musing, I learned that the rsync commands I wrote did
not work as expected.  I wonder why not.  I'll need to consult with
a colleague.  But not tonight.

**_Update_**: After two more minutes, I realized that I had written
the path incorrectly in the `rsync` command.  I've fixed it above.
But it's definitely time to quit now.

---

**_Postscript_**: Thanks to our Linux SysAdmin and our GrinnellSites
Admin for dealing with all of my questions and issues.

---

[1] I keep telling myself that I need a page of technology musings.  Some
day I'll even create it.

[2] Yes, other folks pages are moving too.

[3] I'm not sure that makes sense to me, either.

[4] It looks like I can even send electronic mail, but only to
grinnell.edu email addresses [5].

[5] I'm sure that feature will be disabled now that I've mentioned it in
a public posting.  That's okay; I wasn't planning to rely on it.

[6] insecure?

[7] I still use the Siteweaver software that I wrote right as I
came to Grinnell.  Among other things, most of the pages in my home
directory get built with Siteweaver.

[8] The response about using Pandoc on the server was, approximately, 
"It's compatible with CPanel, but installing it requires root access
that we don't normally give.  Wouldn't you rather set up a site on our
new Cloud platform?"

[9] If I recall correctly, the Web search engine I used back then was
build by the now-defunct Digital Equipment Corporation.

[10] A day after I clean up the repo.

[11] The primary Perl script and the directory of Perl modules.  I had
notes as to where things belong.

[12] "files" include Web pages (`.html`), cascading style sheets
(`.css`), server-side scripts (traditionally `.cgi` or `.php`), 
JavaScript (`.js), and more.

[14] I was right.  Something was wrong.  I also need to work out a new
workflow for my CV.  

[15] Yes, students have really done just that.  Some have even messaged
me with questions during class.

