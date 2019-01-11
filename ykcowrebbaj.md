ykcowrebbaJ
===========

*Topics/tags: [Miscellaneous](index-misc), Web, [CSC 151](index-csc151), typography*

*Warning: Some of the text in this musing is likely to be particularly difficult for those with dyslexia.*

In [the discussion of XML in CSC
151](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2019S/readings/xml),
I use a quotation from Lewis Carroll's [1] [_Through the
Loooking-Glass_](https://www.gutenberg.org/ebooks/12).  It looks something
like the following.

>  ‘What manner of things?’ said the Queen, looking over the book (in which Alice had put ‘_The White Knight is sliding down the poker. He balances very badly_’) ‘That’s not a memorandum of _your_ feelings!’

> There was a book lying near Alice on the table, and while she sat watching the White King (for she was still a little anxious about him, and had the ink all ready to throw over him, in case he fainted again), she turned over the leaves, to find some part that she could read, ‘—for it’s all in some language I don’t know,’ she said to herself.

> It was like this.

> > \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ _YKCOWREBBAJ_
> >
> > \ \ \ \ \ \ \ _sevot yhtils eht dna,gillirb sawT’_  
> > \ \ \ \ \ _ebaw eht ni elbmig dna eryg diD_  
> > \ \ \ \ \ \ \ \ \ \ \ \ _,sevogorob eht erew ysmim llA_  
> > \ \ \ \ \ \ \ \ \ \ _.ebargtuo shtar emom eht dnA_

I took the text from [Project Guttenberg's HTML version of the
book](https://www.gutenberg.org/files/12/12-h/12-h.htm).  But
something in that text was bothering me.  Is it bothering you, too?

Did you miss it?

While the letters in each line of Jabberwocky are written in
reverse order, the letters are not flipped.  What does it look like
in a printed version?  Fortunately, the Web contains a wealth of
resources, and I was quickly able to find [a PDF of a relatively early
edition](http://www.gasl.org/refbib/Carroll__Alice_1st.pdf).  Here's what
that section looks like.

<img src="images/ykcowrebbaj" alt="The first lines of Jabberwocky, written in a mirror image" width="400">

That is, they mirrored the text in the book.  That makes it worth
considering for the reading in which I present the work.

When I was working in Scribble, I didn't really have a way to
achieve the mirror image.  But [now I'm working in Markdown and
HTML](csc151-adventures-markdown) and have a bit more control.

Stack Overflow provided me with [instructions for mirroring
text](https://stackoverflow.com/questions/5406368/can-you-use-css-to-mirror-flip-text).  So, with a little bit of effort, including figuring out styles
in kramdown and a few subtleties, I was able to achieve the following
output using `<span style="transform: scale(-1,1); display:inline-block;">`.

> > \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ <span style="transform: scale(-1, 1); display:inline-block;">_JABBERWOCKY._</span>  
> >   
> > \ \ \ \ \ \ <span style="transform: scale(-1, 1); display:inline-block;">_'Twas brillig, and the slithy toves_</span>  
> > \ \ <span style="transform: scale(-1, 1); display:inline-block;">_Did gyre and gimble in the wabe;_</span>  
> > \ \ \ \ \ \ \ \ \ \ <span style="transform: scale(-1, 1); display:inline-block;">_All mimsy were the borogoves._</span>  
> > \ \ \ \ \ \ \ <span style="transform: scale(-1, 1); display:inline-block;">_And the mome raths outgrabe._</span>  

Not bad.  That achieves the indended effect, including the backwards
slope of the italic letters.  For some reason, I find myself particularly
appreciating the backwards "m"s (<span style="transform: scale(-1,1);
display:inline-block;">*m*</span>).  On the other hand, the code I used
for indentation is a hack.  But that's an issue for another day.

Here's a question for the digital humanists out there: How would you
mark up the mirrored Jabberwocky in XML?  Would you put it in
readable order with a tag that indicates mirroring, or would you use
the backwards words, as Project Gutenberg did?  How about the lines
of the poem?

---

Postscript: Why do so many people spell "borogoves" as "borogroves"? [2]

---

Postscript: For some reason, it seems appropriate to write a bit of
Jabberwocky backwards *and* to mirror it.  Let's see ...

> > \ \ \ \ \ \ \ \ \ \ <span style="transform: scale(-1, 1); display:inline-block;">_.YKCOWREBBAJ_</span>  
> >   
> > \ \ <span style="transform: scale(-1, 1); display:inline-block;">_sevot yhtils eht dna ,gillirb sawT'_</span>  
> > \ \ \ \ <span style="transform: scale(-1, 1); display:inline-block;">_;ebaw eht ni elbmig dna eryg diD_</span>  
> > \ \ <span style="transform: scale(-1, 1); display:inline-block;">_,sevogorob eht erew ysmim llA_</span>  
> > \ \ \ \ <span style="transform: scale(-1, 1); display:inline-block;">_.ebargtuo shtar emom eht dnA_</span>  

Yes, that's the text in the correct order, but with each letter mirrored.
Reading it makes my brain hurt.  But it also makes me want to explore this
approach more.

But typing text backwards is hard.  I'm tempted to figure out ways to
get the computer to reverse text for me.  Let's see.  Oh, [it's easy](https://developer.mozilla.org/en-US/docs/Web/CSS/unicode-bidi).

> <span style="transform: scale(-1,1); display:inline-block; direction: rtl; unicode-bidi: bidi-override;">Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.</span>

If anyone cares, here's the code I used to generate that fascinating output.

     <span style="transform: scale(-1,1); display:inline-block; direction: rtl; unicode-bidi: bidi-override;">Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.</span>

I love the Web.

---

[1] Or is that Charles Lutwidge Dodgson's?

[2] At least Google asks, "Did you mean: _borogoves_" [3].

[3] Why doesn't Google end its questions with a question mark?

---

*Version 1.0 of 2019-01-10.*
