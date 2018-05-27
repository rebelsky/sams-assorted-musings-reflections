The joy of code: (Re)building my letterhead
===========================================

*Topics/tags: [The joy of code](index-joc), marketing, typography, long, rambly*

Grinnell College is in the midst of developing a new visual identity for 
the College [1].  Among the changes are an updated "wordmark" [2], new
[typefaces](grinnell-typefaces-2018-05-17), and, as you might expect,
new letterhead and new business cards [3].

I write a lot of recommendation letters which are almost exclusively in
electronic form.  I also write a lot of other letter-like documents, such
as memos or thank-you notes to donors, that also live in electronic
form.  If I'm going to support our visual identity, I need to revise
the processes and resources I use to write those documents.  So, let's
see what I have to do.

(Note: Those who don't want to read up on the whole process can just look
at the [sample](images/sample-letterhead).)

**Step 0: Review workflow** [4]

I developed my workflow for generating these documents about fifteen years
ago, when we made the last significant change to our visual identity.
What is that workflow?  It's a bit strange.  I wanted something that
let me generate nice looking documents quickly and work on our Linux
workstations.  Working on Linux workstations ruled out Microsoft Word.
I also edit more quickly in `vi` than I do in Word.  I suppose I could
have used TeX or LaTeX; both certainly make nice-looking documents.
But if I recall correctly, I had difficulty finding the right way
to import both the Laurel Leaf logo and my signature and place them
correctly.  LaTeX also seems like overkill for a quick memo.  Or maybe 
I was just burnt out on TeX variants; I'd done too much TeX consulting
in grad school.

In any case, I decided on a fairly nontraditional
workflow.  I compose most of my letters and memos in HTML, use
[`html2ps`](http://user.it.uu.se/~jan/html2ps.html) to convert the HTML
to PostScript, and then use `ps2pdf` [5] to convert the PostScript to a
PDF document.  (That's also similar to the workflow I used to use to make
PDFs of my course Web pages, so that may be why I chose that workflow.)

What about the images and other things that need careful placement?  At
the time, they would only give us a `jpg` of the Laurel Leaf, so I
hand-crafted an encapsulated PostScript file with the Laurel Leaf, the
College name, and my contact information.  That allowed me to get the
spacing just right.  A few hacks with the bounding box and it ended up
placed perfectly on each page.

It's a strange workflow, but it's served me well.  Including HTML tags
while I write is easy [6].  I write and edit faster in `vi` than I do
in any other program.  Once I've created the HTML, my standard Makefile
does the rest.  And the resulting letters and memos look nicer than most
of what I see on campus.  Plus, the files are small, which makes them easy
to upload to places.

I'm not going to change the workflow, so I have to update the resources.

**Step 1: Identify necessary changes**

I will need to change the fonts in the letterhead and the body of 
my letters.  That means figuring out how to tell both `html2ps` and
`ps2pdf` to use other fonts.

I will need to figure out which fonts I'm supposed to use.

I will need to update my custom header,
Fortunately, I can grab an [SVG file of the
wordmark](https://www.grinnell.edu/sites/default/files/logo.svg)
from [our visual identity
page](https://www.grinnell.edu/about/offices-services/communications/brand/visual-identity).
And it's easy to convert SVG to encapsulated PostScript, or at least I
think it is.

**Step 2: Convert the Wordmark**

I actually converted the wordmark relatively early in the process.  I
find some aspect of the text in the wordmark disturbing and my original 
goal was to experiment with the wordmark (e.g., to change the font size
or the letter spacing).  I'm better with PostScript than I am with SVG [7],
so I started by finding software that converts SVG to PostScript.  Fortunately,
[Cairo](https://cairographics.org/) seems to do the trick.  I don't love
the generated PostScript [8], but I can work with it.

Looking at the generated PostScript was interesting.  As far as I can
tell, neither the original SVG nor the PostScript embed the font; hence,
we simply have paths for each of the letters.  Even with that change,
I would have expected that the letters would have been drawn in order.
But they are not.  If I have it right, here's the order in which they
are drawn.

    G_______ _______
    G_____l_ _______
    G__n__l_ _______
    G_in__l_ _______
    Grin__l_ _______
    Grin__l_ C______
    Grin__l_ Co_____
    Grin_el_ Co_____
    Grin_ell Co_____
    Grinnell Co_____
    Grinnell Co__e__
    Grinnell Co__e_e
    Grinnell Col_e_e
    Grinnell Colle_e
    Grinnell College

I checked the SVG and they appear in the same order there.  The SVG also
has a strange little bit in which it draws an oval with no fill over the
center of the "g".  I can't tell whether or not that's still in the
generated PostScript.

**Step 3: Identify appropriate typefaces**

As far as I can tell, there are six typefaces involved in our institutional
identity.  Are you ready?

* [Futura PT](https://typekit.com/fonts/futura-pt) serves as our primary 
  sans serif family.
* Since Futura is a commercial typeface that is not traditionally
  available on workstations [9], we are told we can use
  [Arial](https://en.wikipedia.org/wiki/Arial) instead.  I've already
  written about [why Arial is not an appropriate substitute for
  Futura](grinnell-typefaces-2018-05-17) [10].
* [Freight Text Pro](https://typekit.com/fonts/freight-text) serves as our
  primary serif font.
* Since Freight Text Pro is a commercial font that is not traditionally
  available on workstations, we are told that we can use
  [Georgia](http://www.myfonts.com/fonts/ascender/georgia-pro/) as an
  alternative.  Of course, Georgia is also a commercial font.  However,
  some version of Georgia usually accompanies Microsoft products, which
  it appears Communications assumes we will use.
* We use a bastardized version of 
  [Berlingske](https://playtype.com/font/berlingske-serif) for
  our wordmark.  Why do I say "bastardized"?  Because our friends at
  Oologie decided that they should redraw some of the letterforms [11].
  The lowercase "g" has a serif that is supposed to echo the Laurel
  Leaf.  The uppercase "G" uses a very different serif than in the
  original.  And the lowercase "r" looks nothing like the distinctive
  "r" that characterizes Berlingske.
* The department name [12] is supposed to appear underneath the wordmark
  and we're supposed to use [Berlinske
  Sans](https://playtype.com/font/berlingske-sans) bold there.

That's a lot of commercial faces.  And they haven't provided an
alternative for Berlinske Sans Bold, which means that it's almost
impossible for someone to build an equivalent electronic version of
the letterhead.  I'm also a bit concerned about the use of four different
faces in one document.  That seems like a strange design decision.  In
the old model, we used only one face; I found that provided a compelling
unity.  Oh well, my job is not design; it's adaptation.

Think about the message we could send if we instead chose to use
open-source faces.  And wouldn't it be even cooler if we were
like the [Cooper Hewitt Museum](https://www.cooperhewitt.org/)
and [commissioned a noted type designer to create
a new typeface which we then released under an open-source
license](https://www.cooperhewitt.org/open-source-at-cooper-hewitt/cooper-hewitt-the-typeface-by-chester-jenkins/)?
That would be a great way to reinforce the idea that Grinnell and
Grinnellians contribute to society.  But no, we blow our advertising
budget on people who can't craft reasonable prose.

Now, what can I use as open-source substitutes?

* I spent the most time on Futura since that's such a distinctive font.
  I found three open-source fonts that share many characteristics with
  Futura, including the mixed-height letters and the tail-less lowercase
  "t": [Renner\*](http://indestructibletype.com/Renner.html) [14], [Glacial
  Indifference](https://fontlibrary.org/en/font/glacial-indifference),
  and [Josefin Sans](https://fonts.google.com/specimen/Josefin+Sans).
  I see that the bold form of each is narrower than Futura bold, but I'll
  live with that.  After all, if Communications thinks Arial is a reasonable
  substitute, almost anything close will suffice
* I didn't try quite as hard for Freight Text Pro.  In [a previous
  musing](grinnell-typefaces-2018-05-17), I identified
  [Besley\*](http://indestructibletype.com/Besley.html) as a
  possibility.  Part of me thinks that a version of [Computer
  Modern Serif](https://en.wikipedia.org/wiki/Computer_Modern)
  [15] would be amusing.  I suppose if I'm thinking
  about Computer Modern, I should also consider [Concrete
  Roman](https://fontlibrary.org/en/font/cmu-concrete).  
  [Born](http://www.carlosdetoro.com/born/), which I found somewhat
  randomly, actually matches the more slab-like serifs relatively well
  without being a full slab face.  I've seen a recommendation for
  [Source Serif Pro](https://fonts.google.com/specimen/Source+Serif+Pro)
  as a reasonable alternative.
  [Neuton](https://fonts.google.com/specimen/Neuton) has been recommended
  as an alternative to Georgia.
  [Merriweather](https://fonts.google.com/specimen/Merriweather) seems
  like another font with a large x-height and relatively slab-like
  serifs.
* Fortunately, I don't need to find an alternative to Berlingske Serif.
  I have the wordmark in SVG and don't need anything else.
* I was tempted to use something like Arial as the alternative to Berlingske
  Sans.  But that seemed wrong.  I'm lazy, and it's
  only a few words, so I think I'll just use [Alegreya
  Sans](https://fonts.google.com/specimen/Alegreya+Sans).

While I think Renner\* generally does the best job of matching Futura,
it's lowercase "a" looks very different and I really wanted a Futura-style
lowercase "a" [16].  I know that Josefin Sans differs particularly in the
use of angled bars in the "e", but I also find that it captures the "feel"
of Futura the best.  I had planned to settle on that.  But once I made
letterhead in the various faces, I decided that Glacial Indifference
actually seemed to do the best job.

For Freight Text Pro, I quickly eliminated the Knuth fonts.  I think that
part of Communications' goal is that we use something slightly different
and, well, to many people with whom I communicate, CMR is a familiar font.
It also seems wrong to use TeX fonts in something other than TeX.  It
turns out that Born lacks either an italic or a bold.  I really need all
three styles.  Source Serif Pro has a bold, but no italic.  Besley\* feels
a bit too old [17].  I think I'll try Merriweather, at least for the
initial experiments.

I suppose I could have asked Communications which they'd prefer that I
use [18].  Maybe I'll do that in the future.

**Step 4: Determine how to use TrueType and OpenType fonts in Ghostscript (also install fonts)**

My initial Web searches worried me.  The [Ghostscript Font Documentation](https://ghostscript.com/doc/current/Fonts.htm) made it seem like I needed to edit 
a list of fonts that appears as part of the global settings and therefore not 
accessible to ordinary users [19].

But it turned out to be remarkably easy.  I just needed to put the fonts
in some directory and set the environment variable `GS_FONTPATH` to
point to that directory.  On my Mac, Font Book puts them in `~/Library/Fonts`.
So ...

     export GS_FONTPATH=/Users/rebelsky/Library/Fonts:${GS_FONTPATH}

I'll set up a matching directory on MathLAN and then synchronize them
with a single command.

    rsync -avz ~/Library/Fonts/ rebelsky@ssh.cs.grinnell.edu:Library/Fonts

That worked well.

**Step 5: Write the PostScript for the letterhead**

I have the old .eps letterhead file.  I have the new wordmark converted to
eps.  I know how to use fonts.  This should be straightforward, right?
It's mostly a case of shifting things around and finding the right position,
or so I hope.

But first, I should fix some of the program design issues from the last
time around [20].  I have about a dozen lines of text that I place at the
right side of the page.  In the past, I was using an absolute location
for each line.  This time through, I should allow PostScript to compute
the placement of each line.  Let's see ...

We'll start by defining a few variables

    % X position of address line.  Should not change.
    /address-x 574 def

    % Y position of current address line.  Modified by the line, contact,
    % and skip procedures.
    /address-y 191 def

Next, we'll define the procedures for normal lines, contact lines, and
skipping a bit of extra space.

    % amt skip
    %   Skip a bit in the address section
    /skip {
      address-y exch sub /address-y exch def
    } def

    % string line
    %   Print the next line in the current font
    /line {
      address-x address-y moveto showright
      fontsize 1 add skip
    } def
    
    % label info contact
    %   one of the label/info pairs
    /contact {              % label info
      gsave
      AddressPlain fontsize selectfont
      color-black
      dup                   % label info info
      address-x address-y moveto showright  % label info
      stringwidth pop       % label width
      address-x exch sub    % label new-x
      10 sub                % label newer-x
      address-y moveto              % label
      AddressItalic fontsize selectfont
      showright
      fontsize 1 add skip
      grestore
    } def
    
Did I mention that I love stack-based languages?

Now that I have that in place, the address section is relatively 
straightforward.

    % Name
    AddressBold fontsize 1 add selectfont
    color-red
    (Samuel A. Rebelsky) line
    color-black
    
    % Title (or titles)
    1 skip
    AddressItalic fontsize selectfont
    (Professor of Computer Science) line
    
    % Lab
    5 skip
    AddressPlain fontsize selectfont
    color-grey
    (Grinnell Laboratory for Interactive Multimedia) line
    (Experimentation and Research) line
    color-black
    
    % Address
    5 skip
    (Department of Computer Science) line
    (Grinnell College) line
    (1116 8th Avenue) line
    (Grinnell, Iowa  50112  USA) line
    
    % Contact
    5 skip
    (office) (641-269-4410) contact
    (fax) (641-269-4285) contact
    (cell) (641-990-2947) contact
    
    % More info
    5 skip
    (rebelsky@grinnell.edu) line
    5 skip
    AddressBold fontsize selectfont
    color-red
    (www.cs.grinnell.edu/~rebelsky) line
    color-black

As you might expect, the nice thing about this form is that it's easy
to add and drop lines.  It probably needs a little more work (for example,
I might have the `contact` procedure offset by a particular amount, rather
than the width of the text plus 10, but I'm relatively happy for the 
moment.

**Step 6: Convince `html2ps` to work with other fonts**

I started out reading [a guide to fonts in
`html2ps`](https://www.tufat.com/docs/html2ps/howto_fonts.html) [21].
After way too much time had passed, I found myself confused by references
to PHP and wondered whether I was reading the right documentation.
In the end, it seemed that I'd found the wrong version of `html2ps`.
This seems to be by someone named Darren and is written in PHP.  The [one
I use](http://user.it.uu.se/~jan/html2psug.html) is by Jan Kärrman and
is written in Perl.

It appears that `html2ps` will only work with `pfa` files [22].  So I'll
start by trying to create those files.  I have [Font
Forge](https://fontforge.github.io/) on my computer [23].  Do I want
to convert the easy way or the more general way?  That is, do I want
to just open each face in FontForge and then export as a `.pfa` or
do I want to figure out how to script FontForge?  Let's start by
seeing how hard scripting is.  The [documentation](http://fontforge.github.io/en-US/documentation/scripting/) suggests that I should write something
like the following.

    #!/usr/local/bin/fontforge
    # Copied from http://fontforge.github.io/en-US/documentation/scripting/
    i=1
    while ( i<$argc )
      Open($argv[i])
      Generate($argv[i]:r + ".pfa")
      i = i+1
    endloop

Of course, the FontForge executable on the Mac is in a very different
location.  So I tried using

    #!/Applications/FontForge.app/Contents/Resources/opt/local/bin/fontforge

And ... well, things did not go as planned.  Here's the error message I
received.

      File "/Users/rebelsky/bin/convert2pfa", line 4
        while ( i<$argc )
                  ^
    SyntaxError: invalid syntax

So I tried using the simpler sample program, without a loop.  That gave
me an error, too.  After way too much futzing around, I realized that
(a) the command-line version needs a `-script` flag when it's running a
script and (b) the command-line version needs a `-lang=ff` flag to
indicate that it's using the old school FontForge scripting language [24].
So the line really needs to be

    #!/Applications/FontForge.app/Contents/Resources/opt/local/bin/fontforge -lang=ff -script

Yup, that worked.

All that's left is to write the `html2ps` resource file.  That should
be relatively straightforward.  Here's what I wrote assuming that I'd
use Merriweather.

    BODY {
      font-family: merriweather;
    }
    
    @html2ps {
      font {
        merriweather {
          names: "Merriweather-Regular Merriweather-Italic Merriweather-Bold Merriwe
    ather-BoldItalic";
          files: "/Users/rebelsky/Library/Fonts/Merriweather-Regular.pfa /Users/rebelsky/Library/Fonts/Merriweather-Italic.pfa /Users/rebelsky/Library/Fonts/Merriweather-Bold.pfa /Users/rebelsky/Library/Fonts/Merriweather-BoldItalic.pfa";
        }
      }
    }

**Step 7: Reconsider typeface choices**

Once I'd started to put everything together, I realized that I needed to
rethink some of my choices.  Glacial Indifference did a fine job in the
header.  However, I realized that I might also need it for some parts of 
the body, which meant that I needed four fonts: Roman, italic, bold, and
bold-italic.  Glacial Indifference lacks a bold-italic.  That meant
switching to Renner\* or Josefin Sans.  Alternately, I could just stick
to the primary serif font for section headings in the body.  While I
really like Josefin Sans, it feels too edgy.  

Of course, that choice of font ultimately depends on the primary font.
In the end, I decided that Besley\* seemed to work the best.  And, once
I'd decided to use Besley\*, I was able to employ a bit of a hack.
Instead of using a sans-serif font for the headings, I used Besley\*
fatface for the bold and bold italic.  That actually seems to work pretty
well.

Now that I've made that decision, I have a bit more freedom for the 
header.  Since I don't have to use the sans serif font in the body, I 
might be able to stick with Glacial Indifference.  No; now that I look
closer, I see that Glacial Indifference doesn't use a uniform width for
digits.  Since I have phone numbers in the header, that strange design
decision makes things look messy.  I guess I'm going with Josefin Sans.
I'll just deal with edgy in the header.  Unfortunately, it looks like it
also has non-uniform digit widths.  Do these designers not think people
will use their typefaces for numbers?  Oh well, time to rewrite
the `contact` script to use a uniform offset.

I think I'm done.  What does the new letterhead (and body text) look
like?  If you didn't look at the beginning, you can now.  Here's a
[sample](images/sample-letterhead).

**Step 8: Review outcomes**

Most importantly, I can once again generate electronic memos and
letters that seem to follow the College guidelines [25,26].

I've cleaned up some PostScript code I wrote fifteen years ago to
make it more adaptable.  I always enjoy improving my code [26].

I now know more about using alternative typefaces in both Ghostscript
and `html2ps`.  That knowledge may benefit me in the future.

I've gotten to play with different typefaces.  I really do enjoy thinking
about type.  I haven't had enough time to do so in the past few years.
I've also installed some useful software, particularly Cairo and
FontForge.

I've now looked at the new wordmark and letterhead enough that they
don't bother me nearly as much as they used to.

I understand my system well enough that I can switch typefaces if
Communications insists that I use others [28].

Unfortunately, my letters, which used to be only a few kilobytes,
are now up to a few hundred.  It's probably the fonts that now must
be included.

Nonetheless, it was an enjoyable exercise.  And I really do appreciate
being able to write nice-ish looking memos and letters that meet design
standards.  Now I need to get back to grading and reviewing.

---

[1] It could be that Communications has finished developing that identity.
But I don't think we've been told about all the aspects.

[2] The wordmark consists of the logo plus the associated "Grinnell 
College".  I don't think we called our previous thing a "wordmark"
because the words were separated from the logo.

[3] Folks on campus may be able to see them in [the online
store](https://marcomcentral.app.pti.com/printone/login.aspx?company_id=22188)
if they creating an account on the store.

[4] I'm listing a series of steps.  I didn't quite do the work in this
order.  Many steps intertwined with other steps.

[5] Part of the [Ghostscript](https://www.ghostscript.com/) suite of
tools.

[6] I can also use Markdown if I so choose.

[7] Believe it or not, but I find some joy in programming in stack-based
low-level languages.

[8] For example, they rename `gsave`, which saves the graphics state, to
`q` and `grestore`, which restores that state, to `Q`.  I assume that they
assume saving and restoring will be done often enough that this change
makes the file much smaller.  But it also makes it much less readable.
For those who care, here are some of Cairo's other bindings.

    /q { gsave } bind def
    /Q { grestore } bind def
    /cm { 6 array astore concat } bind def
    /w { setlinewidth } bind def
    /J { setlinecap } bind def
    /j { setlinejoin } bind def
    /M { setmiterlimit } bind def
    /d { setdash } bind def
    /m { moveto } bind def
    /l { lineto } bind def
    /c { curveto } bind def
    /h { closepath } bind def
    /re { exch dup neg 3 1 roll 5 3 roll moveto 0 rlineto
          0 exch rlineto 0 rlineto closepath } bind def
    /S { stroke } bind def
    /f { fill } bind def
    /f* { eofill } bind def
    /n { newpath } bind def
    /W { clip } bind def
    /W* { eoclip } bind def
    /g { setgray } bind def
    /rg { setrgbcolor } bind def
    /d1 { setcachedevice } bind def

[9] There are a few Futura fonts on Macs.

[10] You might want to read [this even stronger opinion on
Arial](https://www.marksimonson.com/notebook/view/the-scourge-of-arial).
I'm particularly fond of the following.

> Despite its pervasiveness, a professional designer would rarely—at
least for the moment—specify Arial. To professional designers, Arial
is looked down on as a not-very-faithful imitation of a typeface that
is no longer fashionable.

[11] Does our license with the font manufacturer allow derivative works?
Or is that Oologie's responsibility.

[12] The examples I've seen include "Division of Science" or "Computer
Science Department".  I find it fascinating that they order the modifiers
in that way since most people refer to them as the "[Science Division](https://www.grinnell.edu/academics/areas/science)"
and the "[Department of Computer Science](http://www.cs.grinnell.edu/)".

[14] Yes, the asterisk is part of the name.

[15] I see that both
[PostScript](https://www.ams.org/publications/type1-fonts) and
[TrueType](https://www.checkmyworking.com/cm-web-fonts/) versions are
available.

[16] I realize that because these are open fonts, I might be able to modify
them.  That seems a bit extreme, even for me.  On the other hand, it would
be fun to learn more about font design.  Perhaps in the future.

[17] Yes, I realize that's part of the intent.

[18] I did write and ask something like, "Our Linux workstations don't
have Arial or Georgia.  Are there open-source variants you'd suggest?"
I got no reply.  But now I have some fonts to suggest, so maybe they'll
have opinions.

[19] Yes, I have root privileges on my Linux box.  I'd rather not have
to use them.

[20] I told you this was a "joy of code" musing.  You just had to wait
long enough.

[21] Or trying to read.

[22] PostScript Type 1 in ASCII, and therefore somewhat human readable.

[23] I added it somewhere in this long and tedious process.

[24] FontForge switched to Python at some point.

[25] Since we don't have a published set of guidelines yet, I can't be
quite sure.

[26] I have done one subtle thing that likely violates the guidelines.
I wonder if anyone will notice.

[27] No, I don't just write bad code so that I have an opportunity
to improve it.

[28] If they tell me to switch typefaces, will they provide me with
commercial ones or will they identify other open-source typefaces 
they prefer?  The most likely answer is they'll let me stick with
the typefaces I'm using.

---

*Version 1.0 of 2018-05-25.*
