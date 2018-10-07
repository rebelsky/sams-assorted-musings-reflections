A bug, or perhaps not
=====================

*Topics/tags: [Rants](index-rants), short*

The other day, I looked at one of my pages and said to myself, 

> Hmmm ...  I think I've found a bug in Pandoc.  At least I've found a
way in which Pandoc processes Markdown differently than Markdown.pl does.

What's the bug?  An input of

    [A] [Wikipedia](https://www.wikipedia.org)

should result in an output of

    <p>[A] <a href="https://www.wikipedia.org">Wikipedia</a></p>

However, Pandoc gave

    <p>[A] [Wikipedia](https://www.wikipedia.org)</p>

Am I sure about what the output should be?  Pretty sure.  It's what
Markdown.pl gives.  It's also what GitHub gives.

I decided to be a responsible citizen and submit a bug report.
The [Pandoc bug reporting guidelines](http://pandoc.org/bugs.html)
suggest that one should first search the list of open issues.  I started
looking at [all 453 open issues](https://github.com/jgm/pandoc/issues),
or at least the titles.  Then I realized that I could probably narrow the
search to ones that included the word "link".  After some time checking
whether or not the bug was already reported, I decided to report the bug.
The first instruction was "Check your version".  Then I realized that we
have an ancient version of Pandoc installed in MathLAN.  We have version
1.17.2, which I think was released in 2016.  Pandoc 2.0 was released a
year ago.  The latest is version 2.3.1.

It's time to put in a ticket [1].  In the mean time, I wonder if I can
install a newer version for myself [3].

That may also explain why Pandoc didn't always seem to match the docs.

Of course, now I've found that the flags I was using are no longer correct [4].
And I need to rebuild all of the Web pages, since many of them suffered from

---

[1] Now that ITS runs MathLAN, all software requests are supposed to go through 
our ticketing system.  Back when we had a faculty member maintaing the system,
all I had to do was walk down the hall [2].

[2] Or send an encrypted email message.

[3] The answer is "yes".

[4] The `-S` flag was removed.

---

*Version 0.9 of 2018-10-06.*


