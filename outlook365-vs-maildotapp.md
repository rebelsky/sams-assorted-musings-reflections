Outlook 365 vs. Mail.app
========================

*Topics/tags: [Rants](index-rants), technology, technical, email*

About a year ago, messages from Grinnell students started arriving
with awkward formatting.  They looked something like this.

    Dear
     Sam,

    Here
     is my reading journal for CSC 322.

    Question
     1. Explain the code on p. 24 of Metz.

    ...

That is, each paragraph-like unit started with one word and continued
on the next line with a leading space.  I found that form irritating to
read and, from my perspective, it showed a lack of care on the part of
the students.

But then I came to realize that it may not be their fault; it may be 
their software's fault.  That is, perhaps Office 365 is violating some
rules about mail formatting because, like most Microsoft products,
it does everything under the assumption that everyone works in the
Microsoft universe [1].  I read mail in the macOS Mail.app, which
isn't in that universe.  And, well, Mail.app could be at fault, too.

I hadn't seen one of those badly messages formatted messages for a while,
or perhaps I hadn't been paying attention.  But today I received another
one, and decided to look a bit deeper.  In particular, I looked at the
raw source [2].  Like most formatted mail messages, this message was
sent with MIME, the Multipurpose Internet Mail Extensions, a message
format designed, in part, by Grinnell alumnus Nathaniel Borenstein '80.
There's one part for the plain text version and one for the formatted
version.

The plain text version looks like this [3].

    --_000_SN6PR05MB4669DE0B805735987BD73707B7C90SN6PR05MB4669namp_
    Content-Type: text/plain; charset="Windows-1252"
    Content-Transfer-Encoding: quoted-printable

    Dear Sam,


    Here is my reading journal for CSC 322.


    Question 1. Explain the code on p. 24 of Metz.


    ...

That seems okay, except for the strange charset (most people use
UTF-8 or something similar) and the extra space between paragraphs.

What about the formatted version?  Here's how it starts.

    --_000_SN6PR05MB4669DE0B805735987BD73707B7C90SN6PR05MB4669namp_
    Content-Type: text/html; charset="Windows-1252"
    Content-Transfer-Encoding: quoted-printable

    <html>
    <head>
    <meta http-equiv=3D"Content-Type" content=3D"text/html; charset=3DWindows-1=
    252">
    <style type=3D"text/css" style=3D"display:none;"><!-- P {margin-top:0;margi=
    n-bottom:0;} --></style>
    </head>
    <body dir=3D"ltr">
    <div id=3D"divtagdefaultwrapper" style=3D"font-size:12pt;color:#000000;font=
    -family:Calibri,Helvetica,sans-serif;" dir=3D"ltr">
    <p style=3D"margin-top:0;margin-bottom:0"></p>
    <span id=3D"docs-internal-guid-55963ac5-7fff-b79a-f6d2-880169af904a" style=
    =3D"font-family: Calibri, Helvetica, sans-serif, Helvetica, EmojiFont, &quo=
    t;Apple Color Emoji&quot;, &quot;Segoe UI Emoji&quot;, NotoColorEmoji, &quo=
    t;Segoe UI Symbol&quot;, &quot;Android Emoji&quot;, EmojiSymbols; font-size=
    : 16px;">
    <p dir=3D"ltr" style=3D"margin-top: 0pt; margin-bottom: 0pt; line-height: 1=
    .38;"><span style=3D"font-size: 11pt; font-family: Arial; background-color:=
     transparent; font-variant-numeric: normal; font-variant-east-asian: normal=
    ; vertical-align: baseline; white-space: pre-wrap;">Dear
     Sam,</span></p>
    <br>
    <p dir=3D"ltr" style=3D"margin-top: 0pt; margin-bottom: 0pt; line-height: 1=
    .38;"><span style=3D"font-size: 11pt; font-family: Arial; background-color:=
     transparent; font-variant-numeric: normal; font-variant-east-asian: normal=
    ; vertical-align: baseline; white-space: pre-wrap;">Here
     is my reading journal for CSC 322.
    </span></p>
    <br>
    <p dir=3D"ltr" style=3D"margin-top: 0pt; margin-bottom: 0pt; line-height: 1=
    .38;"><span style=3D"font-size: 11pt; font-family: Arial; background-color:=
     transparent; font-variant-numeric: normal; font-variant-east-asian: normal=
    ; vertical-align: baseline; white-space: pre-wrap;">Question
     1. Explain the code on p. 24 of Metz.</span></p>
    <br>
    ...

All of those "`=3D`"'s are encoded equals signs.  Since equal signs have
other meanings in electronic mail, they need to be encoded.  What about
that HTML?  Let's see what the CSS spec says about the `white-space`
style attribute, which has been set to `pre-wrap`.

> This property specifies two things:
> * whether and how white space inside the element is collapsed
> * whether lines may wrap at unforced soft wrap opportunities 

> Values have the following meanings, which must be interpreted according to the [White Space Processing](https://www.w3.org/TR/css-text-3/#white-space-rules) and [Line Breaking](https://www.w3.org/TR/css-text-3/#line-breaking) rules:

> `normal`

> > This value directs user agents to collapse sequences of white space into a single character (or in some cases, no character). Lines may wrap at allowed soft wrap opportunities, as determined by the line-breaking rules in effect, in order to minimize inline-axis overflow. 

> `pre`

> > This value prevents user agents from collapsing sequences of white space. Segment breaks such as line feeds are preserved as forced line breaks. Lines only break at forced line breaks; content that does not fit within the block container overflows it. 

> `nowrap`

> > Like normal, this value collapses white space; but like pre, it does not allow wrapping. 

> `pre-wrap`

> > Like pre, this value preserves white space; but like normal, it allows wrapping. 

> ... [4]
 
What does this say about line breaks?  I read this as "_any line breaks are preserved, but too-long lines are also wrapped_".  But I suppose it could be
interpreted [5] in other ways.  Fortunately, the designers of CSS did their
best of avoid ambiguity.  We can read the [White Space Processing rules](https://www.w3.org/TR/css-text-3/#white-space-rules), or more precisely,
the Segment Break Transformation Rules.

> 4.1.2. Segment Break Transformation Rules

> When `white-space` is `pre`, `pre-wrap`, `break-spaces`, or `pre-line`, segment breaks are not collapsible and are instead transformed into a preserved line feed (U+000A).

But what's a segment break?  That definition also appears in the same
section.

>  For CSS processing, each document language–defined segment break and each line feed (U+000A) in the text is treated as a segment break, which is then interpreted for rendering as specified by the white-space property. 

Wasn't that fun?

In any case, my deep dive into these descriptions suggests that Mail.app
is getting things right in terms of line breaks and that Office 365 is 
getting things wrong.  On the other hand, I would think that the rule
about collapsing whitespace would suggest that the whitespace at the
start of the line should be collapsed.  In that case, Mail.app is doing
things wrong.

What happens if I open the HTML in a Web browser?  I tried Firefox for
Mac, Safari, and Chrome for Mac.  In every case, there's no line break
in the middle of the paragraph.  For example, the "Dear" and "Sam"
appear on the same line.  Is there a conspiracy to ignore the CSS standards?

Have I mentioned how much I hate computers?

---

[1] Microsoft is not alone in this approach.  For example, I regularly
find that photos that I take on my iPhone appear with a different rotation
on the Web.

[2] View -> Message -> Raw Source

[3] I've replaced the text with my sample content.

[4] <https://www.w3.org/TR/css-text-3/#white-space-property>

[5] There's enough passive voice in the preceding text that I've
started to use it, too.  Perhaps, "I suppose that program designers
could interpret it in other ways, too."

---

*Version 1.0 of 2018-11-06.*
