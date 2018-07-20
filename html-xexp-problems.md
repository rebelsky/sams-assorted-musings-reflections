Problems with converting between HTML and s-expressions
=======================================================

*Topics/tags: [Rants](index-rants), Racket, [Code camps](index-code-camps), technical*

As regular readers may recall, last month I was working on [a variety 
of Racket procedures for working with HTML](web-of-racket) for our
[summer code camp on Language and Code](code-camp-language-and-code).
I thought things were going well.  Then my research students started 
to try some "interesting" things [1].  For example, they found some
sample pages that treated tag attributes as singletons, such as
`<input disabled>` [2].

I've been using `html-parsing` to convert HTML to xexp expressions.
Let's see what it does.

    > (html->xexp "<html><body><input name='example' disabled></body></html>")
    '(*TOP* (html (body (input (@ (name "example") (disabled))))))

That seems to make sense.  In xexp expressions, the attributes are indicated
by the `@` symbol.  As I mentioned previously, the Web server uses xexpr
expressions rather than xexp expressions.  To convert between the two,
I've been dropping the `*TOP*`, the `@`, and a few other things.  My
code converted the xexp about to the following xexpr.

    '(html (body (input ((name "example") (disabled)))))

That seems reasonable, right?  What happens when I try to serve it?  Let's
see ...

    Exception

    The application raised an exception with the message:

    response/xexpr: contract violation;
     Not an Xexpr. Expected an attribute value string for attribute (disabled), given nothing

    Context:

    '(html
      (body
       (input
        ((name "example")
         '(disabled)))))

That sucks.  I tried a variety of other things, such as putting the 
`disabled` in as a symbol, rather than a list.  Eventually, I decided
to see what the [xexpr parser](https://docs.racket-lang.org/xml/index.html)
does.

    > (string->xexpr "<html><body><input name='example' disabled></body></html>")
    . . string::44: read-xml: lex-error: at position 1.43/44: expected = in attribute disabled

That also sucks.  I wonder if it has something to do with the extra
`name='example'` attribute.  Let's get rid of it.

    > (string->xexpr "<html><body><input disabled></body></html>")
    . . string::29: read-xml: lex-error: at position 1.28/29: expected = in attribute disabled

Hmmm ... it appears that the xexpr library doesn't like some kinds of valid
HTML.  At least the xexp library will read it!

Is it that it's bad HTML?  I'm not sure that makes a difference, since I
have to handle it in any case.  Let's see ... Singleton tags *are* allowed
in HTML.  I found some information in [the official HTML documentation at
W3C.org](https://www.w3.org/TR/html/syntax.html#elements-attributes).
They even give the `<input disabled>` example and say that it's
supposed to represent `<input disabled="">`.  

Nonetheless, I'm not getting anywhere
with xexpr expressions.  Let's see if the
[html-writing](https://docs.racket-lang.org/html-writing/index.html)
package correctly generates that output.

    > (xexp->html (html->xexp "<html><body><input name='example' disabled></body></html>"))
    "<html><body><input name=\"example\" disabled=\"disabled\"></body></html>"

Nope.  That's wrong.  I guess I'm stuck writing a procedure to clean up
the xexp, either as part of transforming it to an xexpr or before converting
it back to HTML.  Let's see ...

...

I'll probably send a note to either the racket-users mailing list or to
the authors of the two useful libraries.

What's that Stevie Wonder says?  "If you believe in things that 
you don't understand, then you suffer."  Yeah, I need to make sure
that I really understand the systems and libraries I'm using, including
when they deviate from standards.

---

[1] The "air quotes" are intentional.

[2] In reality, they were working with the Grinnell home page, which
has something like the following [3].

    <blockquote class="instagram-media" data-instgrm-captioned ...>

[3] I wonder if "instagram" is intentionally misspelled in the 
`data-instgrm` captioned.  Given the way tools for the Web are designed,
I think the answer is probably "yes".


---

*Version 0.1 of 2018-07-19.*
