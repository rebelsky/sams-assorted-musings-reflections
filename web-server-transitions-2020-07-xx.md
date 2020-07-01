---
title: Adventures in Web server transitions
number: 
tags: [Technology](index-technology)
blurb: So many complexities!
version: 0.1
released: 
current: 2020-01-10
---
As I noted in [a recent musing](farewell-mathlan-web-server-2020-01-11),
my Web pages are moving from <https://www.cs.grinnell.edu/~rebelsky/>
to <https://rebelsky.cs.grinnell.edu> [1].  Dealing with that move
is going to be an adventure, particularly because I have about
36,000 files [2] in my `public_html` hierarchy.

Why isn't it just a matter of copying files over?  There are lots of
reasons.  

The most significant issue has to do with how files are connected.
We connect files in multiple ways.  For example, we might link two
one page to another so that you can click on a phrase in one page
and end up on the other, or we might assign a style sheet to a Web
page so that the Web browser knows how to render the page.  There
are three basic ways we refer to these other files: We can provide
a full URL, including the site name; we can provide a relative URL,
specifying where the other file is relative to the current one on
the same server; or we can do something in-between, an absolute
"from the root" path to a file on the same server.  For example,
another musing might link to this in any these ways

* Absolute: `https://www.cs.grinnell.edu/~rebelsky/musings/adventures-web-server-transition-2020-01-12.html`
* Relative: `adventures-web-server-transition-2020-01-12.html` or
  `./adventures-web-server-transition-2020-01-12.html` or even
  `../musings/adventures-web-server-transition-2020-01-12.html`
* From-the-root `/~rebelsky/musings/adventures-web-server-transition-2020-01-12.html`

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

Suffixes.

Canonical URLs.

Fun with Hypothes.is.

CGI scripts.

Behind-the-scenes programs.  Will I have to build pages in one place
and then transfer them over?

Google.

---

Postscript: I still haven't figured out what I'm going to do about
my normal teaching processes.  For those who haven't been in my
class, I use the computer as my white board, typing in a terminal
window.  Since I type in Markdown, I can quickly convert that file
to HTML.  That means that students can easily read what I'm typing
on their individual computers as well as on the big screen and that
the materials are available after class.  It also means that students
who are sick in their rooms can follow along if they so choose.

However, I don't think our new Web model will easily support this
approach.  I probably can't do live editing on the new servers [3]

---

[1] Yes, other folks pages are moving too.

[2] "files" include Web pages (`.html`), cascading style sheets
(`.css`), server-side scripts (traditionally `.cgi` or `.php`), 
Javascript (`.js), and more.

[3] Or at least I don't think I can; I haven't had the opportunity
to check yet.
