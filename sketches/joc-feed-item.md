The joy of code: Feed items
===========================

_One in a series of notes about short programs I've enjoyed writing._

Now that I've started [an RSS feed for the musings](rss-feed), it seemed
appropriate to write a small script to generate the appropriate feed for
one item (entry) in the file.  For now, my goal is to generating
something that I'll just use by hand.  Over the long term, my goal
is to automate the full feed.  But even if I'm generating things by hand,
it seems reasonable to do some of the work by code.

Before we go too far, I should note that I've made some strange [1]
decisions about the organization of these musings.  In particular, since
I had not anticipated going for half a thousand musings, I did not plan
for this scale.  So ...

* Each musing gets its own file, in Markdown format, in the same directory.
  (It probably makes sense that each gets its own file.  But they should
  not be in the same directory.)
* That Markdown file effectively contains two pieces of information about the
  musing: Its title and its 


---

[1] Bad.
