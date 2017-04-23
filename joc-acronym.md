The joy of code: Making acronyms
================================

We've recently hit the point of the semester in CSC 151 [1] in which we
reinforce and extend students' understanding of higher-order programming.
They've been using `map`, composition, anonymous functions, and functions
as parameters since about week four [2].  So, when I say "reinforce and
extend", I mean both that we are talking a bit more about how and why we
use such procedure and we've introduced `apply` and ways of returning
newly defined functions.  

The nested `lambda` expressions they write start out being a bit puzzling,
but provide great expressive power.  For example, we ask them to write
`both`, a procedure that takes two predicates as parameters and returns a
new predicate that holds only when both of the original predicates hold.
Here's a definition, along with the 6P-style documentation, and some
sample uses.

<pre>
;;; Procedure:
;;;   both
;;; Parameters:
;;;   p1, a unary predicate
;;;   p2, a unary predicate
;;; Purpose:
;;;   Create a predicate that holds when p1 holds and p2 holds.
;;; Produces:
;;;   newpred, a unary predicate
;;; Preconditions:
;;;   No additional
;;; Postconditions:
;;;   For any value, val, (newpred val) = (and (p1 val) (p2 val))
(define both
  (lambda (p1 p2)
    (lambda (val)
      (and (p1 val) (p2 val)))))
</pre>

<pre>
> (define odd-integer? (both integer? odd?))
> odd-integer?
#<procedure>
> (odd-integer? 4)
#f
> (odd-integer? 5)
#t
> (odd-integer? 3.2)
#f
> (define singleton? (both pair? (o null? cdr)))
> singleton?
#<procedure>
> (singleton? (list 1))
#t
> (singleton? (list 1 2 3))
#f
> (singleton? 5)
#f
</pre>

You don't need something like `both` to achieve either of these results,
but it does make the code a bit nicer once you're used to it.  Of course,
that claim leads us to some discussion of elegance.  Here's an example
we considered today.  The students recently wrote `acronym`, which 
takes a list of strings as a parameter and returns the corresponding
acronym, built by taking the first letter of each string and joining
them together.  You can write such a procedure recursively. But
it's much nicer to write something like the following [3].

<pre>
(define acronym
  (lambda (strings)
    (list->string (map (r-s string-ref 0) strings))))
</pre>

Why is this nicer?  It's more concise than the corresponding recursive
procedure.  It permits parallelization, since we could apply the anonymous
"first character" procedure simultaneously and might even be able to
distribute the `list->string` across multiple processors.  It's also an
example of the general map-reduce technique [4].

Today I asked them to write a more concise version of `acronym`.  They
struggled.  So we broke it apart.  There are two main things we're
doing: We are building a list of the first character of each string,
and we're combining those strings together.  Somewhere in the back of
our head, we should say to ourselves "If you are building a procedure of
one parameter that applies two functions in sequence, you should use
function composition."  But let's delay that a bit.

Suppose we only wanted to build the list.  How would we do that?  The
code above suggests that we'd write something like the following.

<pre>
(define initial-characters
  (lambda (strings)
    (map (r-s string-ref 0) strings)))
</pre>

Interesting.  That meets a pattern we should know about: We're taking a
two-parameter procedure and filling in one parameter with a constant.
I know!  That's sectioning.  In this case, we're filling in the first
parameter of `map`.  So we could rewrite `initial-characters` using
`l-s` [5].

<pre>
(define initial-characters (l-s map (r-s string-ref 0)))
</pre>

I read that as "we apply a procedure that gets the initial character 
to each element of a list".

You may recall that we said that compute an acronym, we make a list
of initial characters and then convert that to a string.  Here's that
description, in code.

<pre>
(define acronym (o list->string initial-characters))
</pre>

Isn't it nice how closely that matches our English?  Will it work?
Let's see.

<pre>
> (acronym (list "Gnu" "Image" "Manipulation" "Program"))
"GIMP"
> (acronym (list "Grinnell" "Independent" "Musical" "Productions"))
"GIMP"
</pre>

Yup, it works.

We could stop there.  Our code is elegant and relatively concise.  I
think it may even be more readable than the original, with the `lambda`.
But we can make at least one more change.  There's no reason to 
separately define `initial-characters`, since we only use it once.
Hence, we could instead write

<pre>
(define acronym (o list->string (l-s map (r-s string-ref 0))))
</pre>

I'll admit that this isn't quite as beautiful as the prior approach.
But, with some practice, you learn to read code like this and realize
that it matches what we say, just with slightly stranger syntax.

It's times like this that I remember why I really love Scheme.  I hope
that our students eventually see the joy in this approach.  

---

[1] "Functional Problem Solving", the first course in the major.

[2] Amazingly, these concepts aren't too bad if you encounter them early.

[3] Note that `r-s` is short for `right-section`, a procedure that takes
a binary procedure and a constant as input, and returns a new procedure that
takes one input and then applies the binary procedure to that input and
the constant.  For those who speak Scheme,

<pre>
(define r-s
  (lambda (proc right)
    (lambda (left)
      (proc left right))))
</pre>

<pre>
> (map (r-s - 3) (list 4 2 1 6))
'(1 -1 -2 3)
</pre>

I hope that they find it empowering to realize that they can write many
of the procedures they've been using for most of the semester.

[4] I should probably tell the students that they're learning map-reduce.

[5] `l-s` is what we use for `left-section`.  You can probably guess
the definition of `l-s`, but I'll include it here anyway.

<pre>
(define l-s
  (lambda (proc left)
    (lambda (right)
      (proc left right))))
</pre>

<pre>
> (map (l-s - 3) (list 4 2 1 6))
'(-1 1 2 -3)
</pre>

---

*Version 1.0 of 2017-04-21.*
