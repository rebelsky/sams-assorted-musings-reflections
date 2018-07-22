The joy of code: An Igpay Atinlay transformer, revisited
========================================================

*Topics/tags: [The Joy of code](index-joc), [Code camps](index-code-camps), [language](index-language), Web*

Recently, I've been working on [code to help our code-camp students
transform Web pages](code-camp-transforming-web-pages).  We're now 
trying to provide our code camp students with some "fun" final project
examples to help them think about the kinds of things they might choose
to do.  For one of the examples, I decided to extend the Pig Latin
example I'd discussed previously to do a somewhat better job.

Once I realized that I could use regular expressions, it became much easier.
The regular expression `#rx"^([^AEIOUaeiou])(.*)` captures the leading
consonants and the remainder of the string.  After that, it's just a 
matter of looking at the various cases and putting things together.
Here's what I wrote to process the parts [1].

    (define (igpay-atinlay-elperhay word leading-consonants remainder)
      (if (string=? "" remainder)
          (string-append leading-consonants "ay")
          (if (string=? leading-consonants "")
              (string-append remainder "yay")
              (if (starts-with-capital? leading-consonants)
                  (string-append (string-upcase (substring remainder 0 1))
                                 (substring remainder 1)
                                 (string-downcase (substring leading-consonants 0 1))
                                 (substring leading-consonants 1)
                                 "ay")
                  (string-append remainder leading-consonants "ay")))))

What's going on here?  Well, I'm a bit [anal retentive](anal-retentive),
so I wanted to make sure that I covered all of the cases.  The first
case is when we have nothing after the consonants.  Does that really
happen?  Yes.  For example, the CS department home page has the word
"CS".  In that case, I'm just adding "ay" to the end.  Anything more
complicated requires some more serious analysis [2].  For words that
have no leading consonants and therefore start with a vowel, I'm adding
"yay" to the end  I realize that there are at least three traditions:
"yay", "way", and "ay".  I'm using the one I first learned.  

Words that start with a capital consonant require a bit more processing.
We need to capitalize the first letter in the vowel portion.  We need
to convert the first letter of the consonant section to lowercase [3].
We need to add an "ay" at the end.  And then we need to shove it all
together.

What's left?  The standard case.  We put the leading consonants after
the rest of the word and then add the "ay".

I've already set up a Web server that will process every word with a
procedure of my choice.  So now I'll just put this procedure in that 
server and see what happens.  Here's the Grinnell Web page [4].

<img src='images/innellgray.png' alt='The Grinnell College Web page, converted[ to Pig Latin.  The Grinnell wordmark still reads "Grinnell College".  The title bar reads
"Innellgray Ollegcay - Ayay ivatepray iberallay artsyay ollegecay inyay Iowayay".  The menus read "Aboutyay", "Admissionsyay and Aidyay", "Academcisyay", "Ifelay@innellgray", "Obalglay", "Afteryay Innellgray", "Alumniyay", "Infoyay Orfay", and "Earchsay".  The banner in the middle of the page reads "Innelliansgray askyay ardhay uestionsqay andyay uestionqay easyyay answersyay".  The word "Scroll" appears unchanged.  A few icons at the bottom read "Equestray Infoyay", "Isitvay", "Applyyay", and "Ivegay".'>

That's not bad.  The College wordmark is an image.  I can't change that.
I also can't change the words on the whiteboard in the primary image [5].
I can't figure out where the word "SCROLL" comes from.  I'm hypothesizing
that it's either an image or added by JavaScript.  I like what's happened
to some of the words that start with a vowel.  "Yay" seems to be a good
thing to add to words like "Admission", "Aid", "Academics", and "Arts".

The complete program seems to work on most Web pages.
I had way too much fun writing it and using it.  What does
the rest of the program look like?  You can find it [in our GitHub
repo](https://github.com/grinnell-cs/lac-examples/blob/master/Final%20Examples/pig-latin-service-improved.rkt)
[6,7].  Why don't have I have it running at a permanent URL?  Because
I'd like to spend some more time on thinking about security issues first.

In any case, it's now time to move on to a more useful [10] example.

---

Postscript: It took me about five minutes to write relatively comprehensive
alt text for the one image I used on this page.  I still don't understand why
others can't be bothered to put forth similar time or effort.

---

Postscript: All the Pig Latin on this page [11] led to the lowest
Grammarly rank for a musing that I've received in a long time.

---

[1] When you call a procedure from `regexp-replace`, it gets the matching
portion as well as each parenthesized portion as parameters.

[2] Arguably, "CS" should become "Eesay Essay" or something like that.

[3] What's the opposite of "capitalize"?  [The InterWeb comes to the
rescue](https://english.stackexchange.com/questions/14575/is-there-an-antonym-for-capitalize-as-in-letter-case).
It appears that the _Chicago Manual of Style_ uses "lowercase" as a verb.

[4] Or at least the top.

[5] Hmmm ... I wonder whether there's alt text for that image.  We haven't
generally been processing alt text.

[6] You can tell that I'm having too much fun with this ... as long as
I had the URL of the GitHub repo, I ran that through the server, too.

[7] If you want to run it yourself, you'll need to install a few
libraries [8].

[8] Let's see ... sxml, html-parsing, html-writing, and
<https://github.com/grinnell-cs/lac-camp.git>.  The two html libraries
may require mcfly and overeasy [9], but the Racket package utilities
handle those automatically.

[9] I did not name those packages.

[10] Although perhaps not as fun.

[11] Or at least in the alt text for the image.

---

*Version 1.0 of 2018-07-22.*
