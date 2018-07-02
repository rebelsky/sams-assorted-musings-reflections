The joy of code: Writing a one-of macro
=======================================

*Topics/tags: [The joy of code](index-joc), Racket, digital humanities*

One of the many projects we're considering for our code camp on
"Code and Language" is an exercise in language generation.  We're
going to use a fairly simple generative grammar.  For example, to
say that a simple sentence is a subject, a transitive verb, and an
object, we might write something like the following

    (define (simple-sentence)
      (combine (subject) (verb-transitive) (object)))

At least to start, we'll just have them make a list of words for the
transitive verb.

    (define (verb-transitive)
      (one-of "watches" 
              "throws" 
              "admires" 
              "observes"))

In that form, `one-of` is relatively easy to write; we just randomly
select between the arguments.  

    (define (one-of . vals)
       (list-ref vals (random (length vals)))))

However, some definitions might involve procedure calls, including
potentially expensive procedure calls.  Here's a silly example that
shows that we do "unnecessary" procedure calls.

    (define (hack val)
      (display "Processing ... ")
      (display val)
      (newline)
      val)

    > (one-of (hack "a") (hack "b") (hack "c"))
    Processing ... a
    Processing ... b
    Processing ... c
    "a"

As that example suggests, we did processing for all three possibilities,
even though, conceptually, we only needed to process one.  The issue
gets more complicated in a "realistic" situation.

    (define (noun-phrase)
      (one-of (noun)
              (combine (adjective) (noun-phrase))))

Yeah, that's recursive.  So we need `one-of` to have a different
evaluation strategy than is traditional in Scheme [1].  The normal
way to get other evaluation strategies is through macros.  I needed
to write `one-of` as a macro.  But I don't write Racket macros nearly
often enough.  Let's see what I figured out.

The last macro I wrote took the following form:

    (define-syntax NAME
      (lambda (stx)
        (let ([datum (syntax->datum stx)])
          (cond
            [(symbol? datum)
             (datum->syntax stx '(quote <macro:NAME>))]
            [(null? (cdr datum))
             (error "NAME: requires at least one parameter")]
            [else
             (datum->syntax stx
                            CODE)]))))

What's going on here?  As you can tell, we're using `define-syntax` instead
of `define`.  I realize that Racket has a wide variety of ways to write
macros.  That's the one I learned.  The parameter is the text of the
program, which is of type syntax.  To work with it, I'm converting it to
a datum.  But someone can use `one-of` in a variety of ways, not all of
which are correct.  Let's see.  They could just type the name.

    > one-of

If `one-of` were a procedure, we'd see the output. 

    #<procedure:one-of>

What I've written will generate the following text.

    <macro:one-of>

It's not perfect, but I think it's close enough for beginning programmers.
Another alternative would be to just say "bad syntax", or something similar.

What else could they do that is "wrong"?  They could skip the parameters.

    > (one-of)

But calling `one-of` with no parameters makes no sense.  One of *what*?
So we issue an error message.

    > (one-of)
    . . one-of: requires at least one parameter

Now we just have to write the real code.  My first time through, I wasn't
thinking, and I just wrote something similar to the procedure version.

             (datum->syntax stx
                            (list-ref (cdr datum) 
                                      (random (length (cdr datum)))))]))))

My initial experiment suggested that it worked fine.

    > (one-of (hack "a") (hack "b") (hack "c"))
    Processing ... a
    "a"
    > (one-of (hack "a") (hack "b") (hack "c"))
    Processing ... b
    "b"
    > (one-of (hack "a") (hack "b") (hack "c"))
    Processing ... b
    "b"
    > (one-of (hack "a") (hack "b") (hack "c"))
    Processing ... a
    "a"
    > (one-of (hack "a") (hack "b") (hack "c"))
    Processing ... c
    "c"

But then I used it in a more "realistic" situation.

    > (define (transitive-verb) (one-of "attacked" "observed" "threw"))
    > (transitive-verb)
    "observed"
    > (transitive-verb)
    "observed"
    > (transitive-verb)
    "observed"
    > (transitive-verb)
    "observed"

Whoops!  I need to *delay* the evaluation until later.  For some reason,
my initial inclination was to build a vector of program text [2], select
randomly from that at run time, and then call `eval` [3].  

             (let ([options (list->vector (cdr datum))])
               (datum->syntax stx
                              `(eval (vector-ref ,options
                                                 (random (vector-length ,options))))))]))))

I said "for some reason", because this is clearly a strange hack.  Still,
I got to use backquote and comma [4], which made it fun.  And it looked
like it worked okay.

    > (define (transitive-verb) (one-of "attacked" "observed" "threw"))
    > (transitive-verb)
    "observed"
    > (transitive-verb)
    "threw"

But `eval` is dangerous.  In particular, there are scoping issues that I
hadn't considered.  See, for example, the following not-very-realistic
example, in which I've added a parameter to `transitive-verb` to allow
an additional choice.

    > (define (transitive-verb x)
        (one-of x "attacked" "observed" "threw"))
    > (transitive-verb "coded")
    "threw"
    > (transitive-verb "coded")
    "attacked"
    > (transitive-verb "coded")
    . . ../../../../Applications/Racket v6.5/collects/racket/private/kw.rkt:929:25: x: undefined;
     cannot reference an identifier before its definition

Whoops!  Okay, what's a better way to delay evaluation in situations like
this?  How does Scheme delay evaluations?  Well, I know that evaluation
is delayed for `if`, `cond`, `or`, `and`, `case`, and similar functions.
So I could generate a giant case statement.  Let's see if I can write
such code.

    (define-syntax one-of
      (lambda (stx)
        (let ([datum (syntax->datum stx)])
          (cond
            [(symbol? datum)
             (datum->syntax stx '(quote <macro:one-of>))]
            [(null? (cdr datum))
             (error "one-of: requires at least one parameter")]
            [else
             (let ([len (length (cdr datum))])
               (let kernel ([options '((else "?????"))]
                            [remaining (reverse (cdr datum))]
                            [num (- len 1)])
                 (if (null? remaining)
                     (let ([code (cons 'case
                                       (cons `(random ,len)
                                             options))])
                       ; (write code) (newline)
                       (datum->syntax stx code))
                     (kernel (cons (list (list num) (car remaining))
                                   options)
                             (cdr remaining)
                             (- num 1)))))]))))

You'll note that I have a `write` in the middle.  That's so that I can
see what code I'm generating.  I realize that there's probably a better
way to do so, but that's a useful quick and dirty hack.  Here's an
example.

    > (define (abc) (one-of (hack "a") (hack "b") (hack "c")))
    (case (random 3) ((0) (hack "a")) ((1) (hack "b")) ((2) (hack "c")) (else "?????"))

Yup, that's the code I want!  I've included an `else` clause that should
never be called.  Why? Because I make it a habit to always included
such clauses.  I'd rather get not-quite-right output when things go
wrong than have my program crash [5].  Let's see if it works for the strange
`transitive-verb` example from before.

    > (define (transitive-verb x)
        (one-of x "attacked" "observed" "threw"))
    > (transitive-verb "coded")
    "observed"
    > (transitive-verb "coded")
    "attacked"
    > (transitive-verb "coded")
    "coded"
    > (transitive-verb "coded")
    "threw"

I could stop there.  However, before I wrote that code, I said to myself
"Wow, generating a giant case statement is inelegant.  There must be a
better way."  And then I remembered the thing that I should have realized
in the first place; thunks are probably the way to go [6].

    (define-syntax one-of
      (lambda (stx)
        (let ([datum (syntax->datum stx)])
          (cond
            [(symbol? datum)
             (datum->syntax stx '(quote <macro:one-of>))]
            [(null? (cdr datum))
             (error "one-of: requires at least one parameter")]
            [else
             (let ([len (length (cdr datum))]
                   [thunks (map (lambda (exp) `(lambda () ,exp))
                                              (cdr datum))])
               (let ([code `(let ([vec ,(cons 'vector thunks)])
                              ((vector-ref vec (random ,len))))])
                 ; (write code) (newline)
                 (datum->syntax stx code)))]))))

That was surprisingly hard to get correct.  I'm pretty sure that writing
"generate a case" version took half as much time.  But the new version
feels cleaner, somehow.  What code does it generate?  Let's see ... [7].

    > (define (abc) (one-of (hack "a") (hack "b") (hack "c")))
    (let ((vec (vector (lambda () (hack "a")) 
                       (lambda () (hack "b")) 
                       (lambda () (hack "c"))))) 
      ((vector-ref vec (random 3))))

Note that the extra set of parentheses around the call to `vector-ref`
are what tells Scheme to evaluate the thunk.  Does it work?  Let's see.

    > (abc)
    Processing ... a
    "a"
    > (abc)
    Processing ... a
    "a"
    > (abc)
    Processing ... c
    "c"

    > (define (transitive-verb x)
        (one-of x "attacked" "observed" "threw"))
    > (transitive-verb "coded")
    "observed"
    > (transitive-verb "coded")
    "coded"
    > (transitive-verb "coded")
    "observed"
    > (transitive-verb "coded")
    "attacked"

It appears to work.  Now I can put together a complete example.

What have I learned from all of this?  I probably shouldn't code when
I'm tired.  I should pay more attention to Scheme scoping rules.  I need
to learn more about macros and pay attention to when things are evaluated.
Yeah, that's enough for now.

---

[1] Traditional Scheme evaluation strategy is "evaluate the arguments
then pass the evaluated arguments to the procedure."

[2] You may recall that we were using lists.  `vector-ref` is much more
efficient than `list-ref`; it seemed worth the extra effort.

[3] `eval` is one of those wonderful and wonderfully dangerous tools
available in Scheme.

[4] For the students reading this, backquote is a lot like quote,
except that you can use a comma to force evaluation of some terms.

[5] I'm not sure why I trust that the `list-ref` will work correctly
but I don't trust that the `case` will work correctly.  I'll need to
reflect on that issue.

[6] A thunk is a zero-parameter procedure.

[7] I've reformatted for clarity.

---

*Version 0.9 of 2018-07-02.*
