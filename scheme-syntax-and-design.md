Scheme syntax and program design
================================

*Topics/tags: [The joy of code](index-joc), Racket, technical, long*

Because [my inbox clogs](index-email), I've tried to cut down on the
number of mailing lists that I belong to.  However, I've remained on the
"[Racket Users](https://groups.google.com/forum/#!forum/racket-users/)"
mailing list because I regularly teach in Racket/Scheme.  It's a quite
busy list, so I often have to skim mesages or just delete messages
without reading them [1].  Today, I ended up reading a message in the
middle of a discussion that got me thinking a lot about program design.

One of the current threads [2] has to do with the syntax of Racket.  Racket
is a variant of Scheme, which means that it has the same syntax "issues" [3]
that most LISP variants have: There are a lot of parentheses, some people
find prefix notation irksome for math, and it can seem overly verbose.  Of
course, it also has the benefits that go with that syntax: Unambiguous
expressions, a natural correspondence between code and data, and an ease
of writing programs that transform programs [4,5].

In any case, one of the list members [6] gave the following example,
which I've modified slightly.

> Suppose you have a structure that stores first, middle, and last
names and that you want to extract the initials as a string.

> In Python, you would write something like
> ```
> user.first[0] + user.middle[0] + user.last[0]
> ```

> However, in Racket you would more likely have to write something
more like
> ```
> (string (string-ref (person-first user) 0)
>         (string-ref (person-middle user) 0)
>         (string-ref (person-last user) 0))
> ```

> The Racket seems to require more syntactic and cognitive overhead [7].

---

It's an interesting example.  I would agree that the Python [9] is a
bit easier to read, but that's due to a variety of issues.  In part, it's
that many things are overloaded [10].  For example, `+` can be used for strings
or characters or numbers or whatever.  Brackets can be used for strings or
lists or arrays [12].  Even `first`, `middle`, and `last` are effectively
overloaded.

And is "a bit easier to read" a function of the syntax or the choice
of method names?  What if we had something more like

```
(string (ref 0 (first user)) (ref 0 (middle user)) (ref 0 (last user)))
```

or

```
(string (initial (first user)) (initial (middle user)) (initial (last user)))
```

While they are slightly longer than the Python, I find that they are
similarly readable, as long as you put your brain in Scheme mode [14].
And it's not hard to define these extra functions [15].  For example,

```
(define ref
  (lambda (index str)
    (string-ref str index)))
(define first person-first)
```

If we cared more about general functions, we could write something
more like the following.

```
(define ref
  (lambda (index thing)
    (cond
      [(string? thing)
       (string-ref thing index)]
      [(pair? thing) ; Let's assume pairs are lists
       (list-ref thing index)]
      [(vector? thing)
       (vector-ref thing index)]
      [else
       (error "ref: cannot index into" thing)])))

(define first
  (lambda (p)
    (cond
      [(person? p)
       (person-first p)]
      [(pair? p)
       (list-ref p 0)]
      [(string? p)
       (string-ref p 0)]
      [(vector? p)
       (vector-ref p 0)]
      [else
       (error "first: cannot take the first part of" p)])))
```

Those redefinitions of `ref` and `first` also suggest a broader issue
at play: We're unlikely to change the `+` operator or the bracket
notation in Python.  However, if we decide to change behavior in 
one of our procedures (e.g., if we realize taht we should handle
empty strings), we can easily do so in the procedures we've written.

---

What about cognitive load?  I actually find that the Python, rather
than the Racket, requires a higher cognitive load.  I have to ask
myself whether first, middle, and last are strings or arrays or ...?
I can tell that from their usage in the (original) Scheme code: My code
is clearly assuming that they are strings.  For all I know, the Python
code could be extracting three arrays of numbers from `user` and then
adding their initial elements together.

Of course, there's also the question of how one defines the structures
for this code.  Here's the Racket code [16].

```
(struct person (first middle last))
(define user (person "Taylor" "Jamie" "Smith"))
```

Here's the corresponding Python code [17].

```
class Person:
  def __init__(self, first, middle, last):
    self.first = first
    self.middle = middle
    self.last = last
user = Person("Taylor", "Jamie", "Smith")
```

In this case, I find the the Racket code is both syntactically and
conceptually easier to handle.  I realize that the structure of the
Python code is straightforward, but it is longer than the Racket and
does require more work to read (e.g., to make sure that the parameters
are being assigned to the field with the same name).

---

Another reader on the list [18] suggested the following as a way of providing
more abstraction.

> ```
> (define (get-initial str)
>   (string-ref str 0))
> 
> (define (first-initial person)
>   (get-initial (person-first person)))
> (define (middle-initial person)
>   (get-initial (person-middle person)))
> (define (last-initial person)
>   (get-initial (person-last person)))
> 
> (define (get-initials person)
>   (string
>    (first-initial person)
>    (middle-initial person)
>    (last-initial person)))
> ```

That's also a lot of extra code.  However, as they suggest, it makes
the code fragment much more readable.

---

As I reflected on both examples, I realized that as a teacher of CS,
I'd also want my students to think about this problem a bit differently
than either approach suggested.  I admit that I tend to push my students
to general solutions and general approaches, perhaps earlier or extremely
than is necessary.  Anyway, I would prefer that my students think of
this problem using what I might call a "map-reduce" model.

* I have multiple things I want to extract from the `person` structure.
  If I'm doing multiple things to the same datum, that's a chance to 
  use something like `map`.
* I then want to combine the results.  That's a task for `reduce`.

So, I'd want a solution that looks more like the following

```
(reduce string-append
        (map (section substring <> 0 1)
             (map-fun (list first middle last)
                      user)))
```

If I wanted it a bit more readable and a bit more robust, I might
push my students to write something closer to this.

```
(define first-char
  (lambda (str)
    (if (string-equal? str "")
        ""
        (substring str 0 1))))
```

Now we can write

```
(reduce string-append (map first-char (map-fun (list first middle last) user)))
```

Alternately, by taking advantage of our knowledge of the underlying
struct, we might even be able to write

```
(reduce string-append (map first-char (struct->list user)))
```

Of course, that requires that we make the fields of our `person` struct
transparent.

---

Since some of the ease of writing in Python had to do with objects, 
I also started to consider whether it might make sense to use objects
rather than structs.  I haven't done much with objects and classes
in Racket.

---

[1] Or, worse yet, I leave them in my inbox.

[2] Or, at this point, sets of threads. 

[3] Sorry for the scare quotes.

[4] We often call those _macros_.

[5] This ability is a natural implication of the similarity of code and
data.

[6] I've decided to leave the names to the citations, since the particulars
of who said what are less important than what they've said.

[7] J. Zamora.  17 July 2019.  "Re: [racket-users] The case, and a proposal, for elegant syntax in #lang racket2"
Available online at <https://groups.google.com/d/msg/racket-users/ewWuCvbe93k/8KU2677vCAAJ>. [8]

[8] At least until Google decides to discontinue the GoogleGroups mailing lists.

[9] I've chosen Python because the syntax works in Python.  It may be
that they intended another language, such as JavaScript.

[10] Arguably, some of these could be considered polymorphism, rather
than overloading.  But I'll leave it to people better informed than I [11]
to make that determination.

[11] Hi PM.

[12] Assuming that the language differentiates between lists and arrays.

[14] Among other things, reading code inside-out.

[15] Ideally, we would have defined them already as part of our "standard
library".

[16] Or, more precisely, a variant of the racket code used in the 
example.

[17] I am not an expert Python programmer.  Perhaps others would write
it differently.

[18] Robert R.  17 July 2019.  "Re: [racket-users] The case, and a proposal, for elegant syntax in #lang racket2".
Available online at 
<https://groups.google.com/d/msg/racket-users/ewWuCvbe93k/Wh7mmHbEAQAJ>

[19] Here's a definition of `map-fun`.

```
(define map-fun 
  (lambda (list-of-funs val)
    (map (lambda (f) (f val)) list-of-funs)))
```

---

*Version 0.5 of 2019-07-18.*
