Exploring Kotlin
================

*Topics/tags: [The joy of code](index-joc)*

As I mentioned [recently](new-languages-2019-09-09), one of my goals
for leave is to learn or extend my knowledge of a variety of programming
languages.  The first one I'm exploring is [Kotlin](https://kotlinlang.org).
The high-level comments from _Kotlin Programming: The Big Nerd Ranch Guide_
suggest some reasons to consider Kotlin.

> [S]ince Java was released in 1995, much has been learned about what makes for a good programming language. Java is missing the many advancements that developers working with more modern languages enjoy.  Kotlin benefits from the learning gained as some design decisions made in Java (and other languages, like Scala) have aged poorly. It has evolved beyond what was possible with older languages and has corrected what was painful about them. 

First way to learn: Kotlin Koans in the IntelliJ Community Edition
with Educational Tools installed.  Harder to get started than I
would have liked.  The instructions ("Task description") didn't
show up for some reason.  A few restarts and it started working,
but it was strange (annoying) that I had to spend so much effort.
(Upon further reflection, it may be that it needed to donwload
a giant Gradle project.)
It seems easier to do in the browser.  But vi (well, vim) plugin!

Some ugly formatting conventions (or at least I assume they are 
conventions).  Consider this piece of code, taken from the
[documentation on lambdas](https://kotlinlang.org/docs/reference/lambdas.html)

```
items.fold(0, { 
    // When a lambda has parameters, they go first, followed by '->'
    acc: Int, i: Int -> 
        print("acc = $acc, i = $i, ") 
    val result = acc + i
    println("result = $result")
    // The last expression in a lambda is considered the return value:
    result
})
```

The parameters of the lambda are `acc` and `i`.  Can you tell what the
body is?  Indentation suggestions that it's only the `print` statement.
However, it's actually everything up to the close brace.

Would Kotlin make a good alternative to Java for CSC 207, our course in
object-oriented programming, data structures, and algorithms?  Let me
consider what I expect in a language for that course.

*A sensible object-oriented framework*.  CSC 207 is where we introduce
OOP in our curriculum.  Among other things, that means that there
should be support for encapsulation, inheritance, and both kinds
of polymorphism [1].

*Fairly serious compile-time type chacking*, or something similar.  I
realize that there's an increasing move toward languages that trust
the programmer.  We accommodate that with both Scheme (run-time
type checking and heterogeneous types) and C ("You want to call that
integer a pointer?  Sure, why not?").  Nonetheless, I find it valuable 
for students to encounter a language that doesn't trust them.  "You
seem to be using a variable that may not have been initialized.  I
won't compile your program!" or "You seem to be treating an integer
as a Boolean; that does not make sense."

*Wide adoption*.  While our primary goal is to get students to think
like computer scientists, they also need jobs and intenrhips [2].
Knowing a widely-used language helps.

---

[1] No, not country and western.  Parametric and subtype.

[2] Or vice versa.

