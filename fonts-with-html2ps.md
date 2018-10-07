Using custom fonts with html2ps
===============================

Hmmm ... these are OTF fonts.  Can I use them with html2ps.

I think the question is whether I can use them with Ghostscript.

https://www.ghostscript.com/doc/current/Use.htm

`-SFONTMAP=`

Perhaps switch to https://wkhtmltopdf.org/

---

Using the fonts with Ghostscript.

Step one: Determine the default search path using `gs -help`.

Step two: Create `/usr/local/share/fonts/default/TrueType`.

Step three: Copy the font there.  (I'm doing this mostly as an experiment.
In the furture, I hope to set an appropriate path.)

Nope, that was overkill.  All I had to do was add the font directory
to the global variable `GS_FONTPATH` and use something like
`/JosefinSans-Bold findfont`.  Much too easy.

---

What about OpenType fonts?  I see a lot of info here.

https://www.preining.info/blog/2015/04/setting-up-cid-fonts-for-ghostscript-technical-notes/

https://www.preining.info/blog/software-projects/cjk-fonts-ghostscript/

But it turns out it's just as easy, provided I set the font path correctly.

---

On to HTML2ps.

https://www.tufat.com/docs/html2ps/howto_fonts.html.  Or is that
the wrong version of html2ps?  This seems to be by someone named
Darren and is written in PHP.  The [one I use](http://user.it.uu.se/~jan/html2psug.html) is by Jan Kärrman and is written in Perl.  How long did I spend
trying to figure things out for the wrong version.

Hmmm ... I may only be able to do this with PostScript fonts.  Conveniently,
there are ways to translate TrueType and OpenType fonts to PostScript
fonts.

I guess I get to use ttf2pt1.sourceforge.net/index.html or 
https://fontforge.github.io/scripting-tutorial.html.


