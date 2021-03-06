On Software Hammers
===================

*I'm spending this week in a workshop on the digital liberal arts,
particularly the use of data (or capta) in the digital liberal arts
(or digital humanities).  The workshop is raising a variety of issues
for me to write about, from what I see as modern versions of the "two
cultures" issue to questions of the appropriateness of software.  Today
was busy, so I'm delaying the deeper essays until later.*

*Apologies to my non-technical readers (and to my technical readers) for
this somewhat technical article.*

There's an old adage: *If all you have is a hammer, everything looks like
a nail.*   Today, as I worked with software for "Web scraping", I realized
just how much this adage plays out as people use tools for the digital
humanities (and in many other arenas).

A common problem in working with data of any sort is finding and filtering
information from a larger data set.  So our project was to play with a
tool for doing that with Web pages, using a tool called *OutWit Hub
Light*.  What kinds of things can we do?  Well, consider the following
"source code" for part of a Web page, taken from
<http://www.grinnell.edu/news-archives> and reformatted for clarity.

    <div class="views-row views-row-2 views-row-even">
      <div class="views-field views-field-created">
        <span class="field-content">June 1, 2016</span>
      </div>
      <div class="views-field views-field-title">
        <span class="field-content">
          <h2 class='news-item'>
            <a href='/news/faulconer-gallery-outreach-parks'
               title='Read this news article'>
             Faulconer Gallery Outreach in the Parks
            </a>
          </h2>
        </span>
      </div>
    </div>
    <div class="views-row views-row-3 views-row-odd">
      <div class="views-field views-field-created">
        <span class="field-content">May 26, 2016</span>
      </div>
      <div class="views-field views-field-title">
        <span class="field-content">
          <h2 class='news-item'>
            <a href='/news/grinnell-welcomes-alumni-2016-reunion'
               title='Read this news article'>
              Grinnell Welcomes Alumni to 2016 Reunion
            </a>
          </h2>
        </span>
      </div>
    </div>

(No, you may not criticize the HTML.  That's probably the topic for another
essay, or perhaps a latter part of this essay.)

Suppose we want to extract the dates of all the news articles.  What do
we do?  As a computer scientist (or at least a computer programmer), I
know that I have two main options, both of which have to do with the
context of the text.  I can look for the particular text that appears
before and after the date, and try to make sure that it is unique.  In
this case, I see that the date is preceded by `<span class="field-content">`,
but so is other information in the page.  However, when that span follows
`<div class="views-field views-field-created">`, I know that it's the
date of the article.  So I can use that exact set of text, which is what
we were expected to do today.

But Web pages, at least well designed Web pages, are hierarchically
arranged documents.  So I really should be able to describe what I want
structurally, rather than in terms of particular text that appears.
In this case, I want the contents of the span elements with class
`"field-content"` that fall within div elements with class `"views-field
views-field-created"`.  (It's too late at night for me to write the
JavaScript for that, but it's pretty straightforward.)

Those sound similar.  And they are for the date.  But what happens when we
get to the title of the article?  The text matching approach says that we
should look for `title='Read this news article'>`.  But that's a strange
artifact in the text, and isn't really a sensible way to describe what
we want.  What do we want?  We want the text content of the entries with
class `news-item`.  In using the structural model, I'm paying attention
to how the data are arranged, not the particular code that's there.
It makes more sense to a reader.

In the workshop, the tool we used only handled the textual context,
not the structural context.  And that's a problem.  Why?  First, it's
incredibly fragile.  As we experimented, we realized that if you get
the number of spaces or carriage returns wrong in the context, the
match fails.  That means that even a small change in the original page
can break our filter.  The textual context is, well, not particlarly
contextual.  Would you really expect to see the title of a news article
after something that says `Read this news article`?  And what happens
when the software that generates that stupid repeated text gets fixed
so that there's different text in each case?  You can write a more
complicated pattern to account for the fact that the URL may change.
However, in the end, that pattern will end up replicating most of the
structural context but in a less readable form.

So, where's the hammer?  In some ways, OutWit Hub is the hammer.
It gives you one primary way of dealing with Web pages, and so you use
that method.  But it actually strikes me that *regular expressions*
are the real hammer here.  Most digital humanists quickly learn about
regular expressions (hopefully, including the Kleene stars invented by
my great-grand advisor).  And regular expressions are their hammers.
You process text, even annotated structured text, by looking for textual
patterns.  However, regular expressions are not always the right tool.
Sometimes we should use a language that lets us talk about the elements
of the structure, such as JavaScript and the Document Object Model.
Sometimes, we want to look for things that can't be expressed by regular
expressions.  (The obvious, but silly, example is looking for palindromes
in a longer text.)  Knowing more than regular expressions helps.

Just as learning about relational databases helps you design better ways
to organize your data than strict tables (which create repeated values),
learning techniques for dealing with structured data helps you manipulate
those data better.  And learning how to program gives you a sense of
other things that might be possible when whatever models you've learned
break down.

Is there a moral in this all, other than "learn more tools" or "understand
the limitations of your tools" or "make friends with people who know more
tools"?  I think there are some good morals for the "CSC 151 with digital
humanities" course (and corresponding library code) if I ever design it.
I should teach regular expressions, but I should also focus on giving them
tools for manipulating structured documents and help them write their
own tools for doing so.  (Each day, I'm getting a bit more excited
about that class.  Now I just have to find time to design and teach it.
Not this summer, though.)

There is one other moral: Generate Web pages that are easy for people to
process.

---

Although I said that I wasn't going to, I wrote the JavaScript code
for getting the date.  It's either the time of day, my knowledge of
JavaScript, or the design of JavaScript and the DOM, but this is the
first thing that I came up with.

    parts = document.getElementsByClassName("views-field views-field-created")
    Array.from(parts).map(function(x) { return x.getElementsByClassName("field-content")[0].firstChild })

No, I don't understand why I can't just use `parts.map`, which would make this
a bit better.

A more concise, but less precise, solution is to use the `textContent`
method.

    parts = document.getElementsByClassName("views-field views-field-created")
    Array.from(parts).map(function(x) { return x.textContent.trim() })

That strategy seems to work for the title of the news item, too.

    parts = document.getElementsByClassName("views-field views-field-title")
    Array.from(parts).map(function(x) { return x.textContent.trim() })

Yeah, that's more than I'd want to teach most peopel in an introductory 
session.

---

This was supposed to be a quick essay.  It wasn't.

---

*Version 1.0 released 2016-06-01.*

*Version 1.0.1 of 2018-02-25.*
