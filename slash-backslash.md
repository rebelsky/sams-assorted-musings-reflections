---
title: Slash and backslash
number: 1033
tags: [Language](index-language), short, rants
blurb: Learn the difference.
version: 1.0
released: 2020-03-19
current: 
---
When you say "slash", most people [1] envision the "**/**" character.
Some folks may also refer to that character as "forward slash".
When you say "backslash" [2], most people [3] envision the "**\\**"
character.  In the land of computers, slashes [4] have been used for
a wide variety of situations, such as to represent division in
mathematical expressions or in pairs to preface one-line comments
in some variants of the C programming language.  But one of the
most important uses is in URLs [5].  Consider, for example, the
URL.

<https://www.grinnell.edu/admission/visit> [7]

I would pronounce that as

> aitch tee tee pee ess colon **slash** **slash** dub dub dub dot 
grinnell dot ee dee you **slash** admission **slash** visit.

Of course, most people write it without the leading "https://".  In
that case, the pronunciation becomes somewhat shorter,

> dub dub dub dot grinnell dot ee dee you **slash** admission **slash** visit.

or even

> grinnell dot ee dee you **slash** admission **slash** visit.

Seems simple enough, doesn't it?  

So why do I keep hearing people refer to things like "grinnell dot ee-dee-you
**backslash** admission **backslash** visit" [8]?.  That phrase describes
"grinnell.edu\\admission\\visit", which is not the same thing, even though
on some systems it will redirect to the correct URL.  I've heard
folks on NPR use the wrong term.  I've heard administrators at Grinnell
use it.  But *why*?

As far as I can tell, it's because Microsoft decided to use backslashes
to separate directories in hierarchical file systems, originally
on MS-DOS and now on MS-winDOwS, and the mis-speakers have heard
technical people say "backslash" when describing file locations and
think they should be using that term when they speak "computer-ese".

Given that Microsoft uses backslashes, why does the Web use slashes?
Presumably, because the Web was built on Unix systems and Unix uses 
forward slashes.  

Given that Microsoft uses backslashes, why does Unix use forward slashes?

That's the wrong question.  Hierarchical file systems in Unix came before
hierarchical file systems in MS-DOS.  More precisely, Unix (with hierarchical
file systems) came before any form of MS-DOS, and flat file systems
on MS-DOS came before hierarchical file systems on MS-DOS.

So the better question is: Given that Unix uses forward slashes,
why does Microsoft use backslashes?  To answer that question, I
turned to the Interweb.  Eventually, I ended up on [a 'blog post
from Larry Osterman at Microsoft from
2005](https://docs.microsoft.com/en-us/archive/blogs/larryosterman/why-is-the-dos-path-character) entitled "Why is the DOS path character \"\"?" [9,11].
The answer is fairly straightforward: Some MS-DOS tools, developed by
IBM, used a slash character for command-line flags.  It appears that
VMS had made the same decision.  Since slash meant "flag", Microsoft
chose backslash for their separator.  I'm pretty sure that the
original Macintosh System used colons.

In the end, none of that should matter to the matter at hand.  The
ways in which the use of the slash and backslash have evolved are of
interest to some [12], but not all.  However, everyone should care that
we use a correct and unambiguous name for characters, and "backslash"
is *not* the correct name for "/".  Use slash.

---

_**Postscript**_: Finding the Larry Osterman 'blog post was an
interesting adventure.  The [first page I found about the use of
backslashes in
MS-DOS](https://www.howtogeek.com/181774/why-windows-uses-backslashes-and-everything-else-uses-forward-slashes/amp/)
took most of its information from the Osterman post.  It gives the
URL <http://blogs.msdn.com/b/larryosterman/archive/2005/06/24/432386.aspx>
for that post.  Unfortunately, Microsoft does not seem to consider
it worthwhile to ensure that links remain consistent.  That link
redirects to <https://docs.microsoft.com/en-us/archive/blogs/>.  It
took a bit of searching to find the right page, particularly because I
was doing it on my cell phone and because the word "backslash" does not
appear in the article.  The final link I found it at was
<https://docs.microsoft.com/en-us/archive/blogs/larryosterman/why-is-the-dos-path-character>,
which bears little resemblance to the original URL.

---

_**Postscript**_: Can you find the missing right brace in the Osterman
piece?

---

_**Postscript**_: Slash fiction is a genre of fanfic named for the slash
that appears between two character names, usually of the same gender,
as in "Kirk/Spock slash fiction".  I don't think I've ever heard anyone
refer to it as "backslash" fiction.  Now I wonder if there is some form
of "backlash fiction" that one could hybridize with slash fiction to
make "backslash fiction".  Something like that.

---

a link to a more authoritative page


---

[1] Or at least most Americans in the twenty-first century.

[2] Or "back slash", to match the spacing of "forward slash".

[3] See the prior endnote.

[4] Forward slashes.

[5] I've normally pronounced that as "You-are-els".  I suppose some
might refer to them as "Earls" or "Hurls", but with a silent "H".

[6] Aitch.

[7] I fell like I know the student who appears on that page.

[8] No, I have not heard that particular phrase.  But you know what I
mean.  At least I hope that you do.

[9] Aren't you impressed that I found a way to avoid smart quotes [10] in
that title?

[10] One of my colleagues would insist that I call those "quotation marks"
rather than "quotes".

[11] Are you surprised that there's no backslash in the title?  I am.  I
assume it has to do with the wonder of Web formatting.   But there wasn't
one in the original, so I'm not including one here.

[12] Including me.
