From Markdown.pl to Pandoc
==========================

*Topics/tags: [Meta-musings](index-meta), markup languages, [the "joy" of code](index-joc)*

For the past few years, I've found it most convenient to write in
Markdown, a simple and common markup language popular with computer
programmers [1].  Perhaps I should say that Markdown is a "family of
markup languages", since there are many variants.

For some reason, when I started using Markdown, I decided to use "pure"
Markdown, relying on `Markdown.pl`, [the original Perl
script](https://daringfireball.net/projects/markdown/).  I don't always
use `Markdown.pl`.  For example, since I use Jekyll to build course
Web sites, I rely on whatever Markdown engine Jekyll uses for those sites.
But for the musings, I've been using `Markdown.pl`.

The other day, I decided that I should use [Pandoc](https://pandoc.org/) 
instead.  A variety of factors inspired that switch.  In part, it was that
I was finding that I was using Pandoc for other tasks.  In part, it
became clear that my colleagues used Pandoc rather than `Markdown.pl`.
In part, it was that Pandoc provides a richer version of Markdown.
The particular feature that I found of interest was Pandoc's support
for simple tables in Markdown.  That feature seemed of particular
utility as I was writing [my initial notes on the schedule for the
new CSC 151](fundhum-schedule-00).

Problem: Doesn't generate the same HTML and I was making some assumptions
about that HTML.  Form of H1 tags.  That problem was relatively easy to
fix.

Problem (not directly related): Different understanding of HTML than
I have.  Consider the following document.

    <html>
      <head>
        <title>Musings and Rants: Sample Document</title>
      </head>
      <body>
        <h1>Sample Document</h1>
        ...
      </body>
    </html>

From my perspective, the `title` tag is *metadata*, information about the
page that should not appear on the page.  In particular, the title is what
most Web browsers use for the title bar and for history.  In designing
titles, I may shorten a title or I may add some context.  Unfortunately,
Pandoc treats it as *content*.  In particular, if I convert an HTML 
document to a PDF, the title appears in a large font at the top of the
page.

Then's there's the issue of `noprint`.

---

[1] Before I started using Markdown, I used Siteweaver, my own simplified 
markup language.  While Markdown doesn't provide the same breadth of 
capabilities as Siteweaver, I find it more appropriate ot use a common
format.

