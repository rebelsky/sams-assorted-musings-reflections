Why Scheme?
===========

More precisely, "Why did you make us use Scheme in this algorithms
assignment?"

_Part of the implicit series "Sam posts things he's written that day
and then muses about them."_

In the [first
assignment](http://www.cs.grinnell.edu/~rebelsky/Courses/CSC301/2017F/assignments/assignment01.html)
in [this semester's CSC
301](http://www.cs.grinnell.edu/~rebelsky/Courses/CSC301/2017F/) [1], I
asked students to implement the heap data structure [2].  In Scheme [3].
It appears that the students have been grumbling about that choice.
Many say that they don't remember Scheme from the first course [4].
But I am allowed to assume knowledge from prerequisite courses.  And they
should know Scheme.

So here's my response.

---

Dear Algorists [6],

I hear that some of you have been wondering why we asked you to use
Scheme for the first assignment (or at least the first problem on the
first assignment).  The answer is easy.

**Because we want to help you learn and to learn efficiently.**

That may not make sense to you, so let me provide a bit more explanation.
(I should also note that the decision was mine.  Since I'm the "senior"
teacher of this class, Prof. Vostinar agreed to follow my lead on
assignments.)

We both know from experience (our own and that of our students) that
you learn data structures and algorithms much better when you implement
them. Implementation helps reveal subtleties that may not be obvious
when you just work with an algorithm or structure in the abstract [7]

Most of you have already implemented heaps in Java.  You won't learn
much from doing so again.  In addition, it sounds like many of you
have an inappropriate attachment to the `ArrayList` class and my long
experience suggests that people too often misuse that class.

If we assume that all of you know Scheme, C, and Java and we've decided
that you should not use Java for the problem, that leaves C or Scheme.
You're implementing a polymorphic type (and you should be; polymorphism
is good practice).  While polymorphic types are not too difficult
in C if you know and understand macros, it's still easier in Scheme.
In addition, few of you know and understand macros.  You can also write
polymorphic types in C using pointers but pointers can be painful.

So we chose Scheme because it gives you the best ratio of learning
to effort.

Now, I did not take into account how much you'd forgotten about Scheme.
I assumed that you remembered and continued to use Scheme.  But, even
if you didn't, there's not a lot of Scheme you need to know for this
assignment.  You need to know how to use vectors.  You need to know how
to use higher-order procedures.  You need to do a bit of sequencing.
That's it.  The overhead should not be that high.

But, more generally, Scheme should be your go-to language for most
quick-off algorithm and structure implementations.  You don't have to
deal with memory management, which makes it better than C.  You don't
have to deal with the mental overhead of Java syntax.  Scheme provides
a quick way to get things done.

Consider, for example, part of problem 2 in which you are doing a
diagonal sweep.  You want to arrange a bunch of points depending on
their taxicab (Manhattan) distance from the origin.  (In graphics, the
origin is the top left.)  What do you need to do? Use the sort routine
(either one you've written or the built-in one) with a comparator that
prioritizes values with the lower distance.  We'll assume that we are
representing points as dotted pairs.

<pre>
(define taxicab-distance-from-origin
  (lambda (pt)
    (+ (car pt) (cdr pt))))

(define closer-to-origin?
  (lambda (pt1 pt2)
    (< (taxicab-distance-from-origin pt1) (taxicab-distance-from-origin pt2))))

(define diagonal-sweep
  (lambda (list-of-points)
    (sort list-of-points closer-to-origin?)))

(define random-point
  (lambda ()
    (cons (random 100) (random 100))))

(define random-points
  (lambda (n)
    (if (zero? n)
        null
        (cons (random-point) (random-points (- n 1))))))

; Interactions pane
> (define sample (random-points 8))
> sample
'((35 . 51) (9 . 46) (13 . 19) (78 . 5) (37 . 36) (88 . 94) (30 . 54) (39 . 74))
> (diagonal-sweep sample)
'((13 . 19) (9 . 46) (37 . 36) (78 . 5) (30 . 54) (35 . 51) (39 . 74) (88 . 94))
</pre>

Think about how much more time all of that would take to write in C
or Java.  In C, you'd have to worry about the memory management issues.
In Java, you'd need to add a lot of cruft to write the comparator.

Ruby and Python will give you similar efficiencies.  ML should, too.
(I'll admit that I don't use ML much.)  But to make it easier for you
to get help, I chose Scheme.

I hope that makes sense.

p.s. Yes, I do know that the code above does not quite meet the spec.
But it's not hard to update the comparator to select the leftmost point
if the points are on the same diagonal.

---

That is, it's not that we *made* them use Scheme [8], it's that we *let*
them use Scheme.

I'm perfectly serious.  Students should be able to play with ideas much
more quickly in Scheme than they can in C or Java.  They could also use
Ruby or Python or a host of other scripting languages.  But Scheme is
a language that all of our majors know [9], and so that's the one I tell
them to use.

In rereading that text, I see that I continue to use "But" too much.  I
should work on that.

---

[1] Our upper-level class entitled "Algorithm Analysis".  It covers algorithms
and data structures.

[2] I still plan to muse about heaps.  Maybe this will give me an incentive.

[3] Scheme is a functional programming language; a derivative of LISP.
It was designed at MIT as a teaching language.  We actually use
[Racket](http://racket-lang.org/), itself a derivative of Scheme.

[4] Yes, we teach the first course in Scheme.  If I haven't done so
already [5], I'll explain why in a subsequent musing.

[5] Nope, it doesn't seem that I have.

[6] The term "Algorists" is due to our class mentors.

[7] Watching the students work on this assignment, it's clear to me that
they got some benefits from trying to implement things.  It's also clear
that many need more practice writing code.

[8] Although we did.

[9] Or should know.

---

*Version 1.0 of 2017-08-30.*
