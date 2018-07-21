Transforming Web pages
======================

*Topics/tags: [Code camps](index-code-camps), Racket, Web, technical, rambly*

As you may recall from [a recent musing](web-of-racket), we are having our
"Language of Code" students write a variety of kinds of activities with Web
pages: they are generating Web pages, writing forms and simple form handlers,
and analyzing Web pages.  We'd also like to have students *transform* Web
pages.

Of course, that leaves me [1] with the questions of *In what ways will
students transform Web pages?* and *What tools will they need to transform
Web pages?*  Let's consider some possibilities.

* They could transform some/all of the page into Pig Latin [2].  That 
  example can also provide a good basis for other text transformations.  
* They could add some interesting statistics or commentary to the end of
  the page.  For example, we could add counts of paragraphs, images, and
  italicized words.  (A more sensible thing would be to provide a list of
  all the alt text.)
* They could change the appearance by modifying the styles.

The Pig Latin example may be the most complicated of the tasks I've come
up with.  But that makes it a good starting point.  I'll first consider
how I'd write that program and then think about what tools the students
will need.

I'll start by writing a simple procedure to convert any word into its
Pig-Latin equivalent.  Let's see .. what's the algorithm?  Pig Latin,
at least as I learned it, involves taking the first letter of the word,
placing it at the end, and then adding "ay".  For example, "pig" becomes
"igpay".  What if the word starts with a vowel?  I was taught to add
"yay" at the end.  So "aardvark" becomes "aardvarkyay".

    ;;; Procedure:
    ;;;   igpay-atinlay
    ;;; Parameters:
    ;;;   word, a string
    ;;; Purpose:
    ;;;   Convert word into Pig Latin, or some reasonable facsimile thereof.
    ;;; Produces:
    ;;;   ordway, a string
    ;;; Preconditions:
    ;;;   Word contains only letters.
    ;;; Postconditions:
    ;;;   ordway is the Pig-Latin equivalent of word.
    (define (igpay-atinlay word)
      (if (starts-with-vowel? word)
          (string-append word "yay")
          (string-append (substring word 1)
                         (substring word 0 1)
                         "ay")))

We could make it a bit more sensible by handling capital letters.  Let's
see.  In cases that start with a consonant, I'll need to capitalize the 
second letter.  But the word may not have a second letter.  So I'll need
to special-case that, too.  Okay, we're already getting beyond what the
middle-school students can probably do.  But it's still worth demonstrating.

Whoops!  My students remind me that Pig Latin is more complicated than that.
For example, we might have words that start with multiple consonants.  Oh
well; I'll leave that as another "for future work" exercise.

Next, we  need to transform things.  That's a job for XSLT (or,
[SXSLT](https://docs.racket-lang.org/sxml/sxslt.html)) and [regular
expressions](https://docs.racket-lang.org/reference/regexp.html), right?
That is, I'll use SXSLT to find all the strings and regular expressions
to transform them [3].  

Let's work inside out.  Can I apply `igpay-atinlay` to every word in a
string?  Fortunately, `regexp-replace*` will take a procedure as the
replacement.

    > (regexp-replace* #rx"[a-zA-Z]+" "This is a simple test." igpay-atinlay)
    "Histay isyay ayay implesay esttay."

Next, we need to identify all of the strings.  That turns out to be
surprisingly easy.  I can use the SXpath `"//text()`.

    > (define (silly element context root) (display element) (newline) element)
    > ((sxml:modify (list "//text()" silly)) `(html (head (title "Sample")) (body (p "This is " (i "italicized")))))
    Sample
    This is 
    italicized
    '(html (head (title "Sample")) (body (p "This is " (i "italicized"))))

Now, let's put those together and see what we get.

    > (define (helper element context root)
        (regexp-replace* #rx"[a-zA-Z]+" element igpay-atinlay))
    > ((sxml:modify (list "//text()" helper)) `(html (head (title "Sample")) (body (p "This is " (i "italicized")))))
    '(html (head (title "Amplesay")) (body (p "Histay isyay " (i "italicizedyay"))))

Whoo!  It works.  But there's no way that I'd try to teach any of that to
the middle-school students [4].  So, it's time to come up with the appropriate
set of procedures to support this kind of action.

My first inclination was to write a procedure of the form
`(transform-words page proc)` that takes each word on the page and applies
`proc`.  But I had my research students working on this project.  When
I reached the point that I was going to write that procedure, they had
another set in mind.  Let's see ... they gave me this list [5].

* `(page-transform-elements page tag procedure)` identifies every element
  on the page that starts with `tag` and applies the given procedure.
  That seems to be the most straightforward way to change a tag.
* `(page-delete-elements page tag)` identifies every element on the page
  that starts with `tag` and deletes it.  That seems a bit excessive.
  But I'll assume that they have some good ideas for using it.
* `(page-replace-text page pattern replacement)` identifies every copy
  of pattern and replaces it with the given replacement.  The students
  asked for replacements that are text (easy) and elements (harder).
  I decided to add a replacement procedure to support the Pig Latin
  example.
* `(page-add-to-end page newelement)` adds a new element to the end of
  the body of a page.

That seems like a reasonable set.  Adding to the end supports the "add
commentary" approach I wanted [6].  I suppose `page-transform-elements`
would let me add a style tag.  But it probably requires a bit more to
work with the individual element.  By the time I use these procedures
in CSC 151, I'll probably add that.  For now, these seem like a reasonable
set.  Certainly, my students ended up having a lot of fun with just the
basic "replace one word with another" approach.  I enjoyed replacing
all instances of my name with my icon.

I look forward to seeing what variations the campers come up with.

---

[1] Well, us, since this should be a collaborative endeavor.

[2] I don't expect perfect Pig Latin, but something approximating it.

[3] I won't ask students to do this; I'm just thinking about the steps 
necessary for whatever procedure I write.

[4] I was going to say that I wouldn't teach any of that to my CSC 151
students.  But I'm beginning to think that I want to teach them SXpath
and regular expressions.

[5] More precisely, they gave me a set of requirements that implied this
list.  For example, "we want to replace all copies of *string1* with
*string2*" and "we want to replace all copies of *string1* with an
appropriate image tag".

[6] I've even tested it.

---

*Version 1.0 of 2018-07-20.*
