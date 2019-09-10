Learning new (programming) languages
====================================

*Topics/tags: [The joy of code](index-joc), rambly, long*

As I think I mentioned in [my most recent musing on my
sabbatical](sabbatical-2019-08-30), one of my goals for this
sabbatical is to explore a few "new" languages.  What languages?
Right now, I'm inclined to look at [Clojure](https://clojure.org/),
[Kotlin](https://kotlinlang.org/), and [Rust](https://www.rust-lang.org/).
I may also look at the incorrectly-named "C Sharp" [1] and a few
of the new dialects of Smalltalk, such as [Pharo](https://pharo.org)
[2].  In addition, it's probably time to continue my deeper dive
into [Racket](https://racket-lang.org/) as my knowledge tends to
be of the core Scheme aspects of Racket, rather than its newer
features.  Some colleagues will probably tell me that I should
re-learn [Haskell](https://www.haskell.org/), which I last used
seriously in about 1995 [3].  Since there have been significant
updates since then, it's likely a very different language.

Why do I want to learn new programming languages, other than to
increase the number of programming languages I can put on my imaginary
résumé [4]?  As I've said, _while the natural language you speak
may not affect how you think_ [5], _the programming
language(s) you use can significantly affect how you approach
problem solving_.  You'd think that after thirty or so years teach
CS, there wouldn't be more for me to learn.  You'd be wrong.  For
example, learning Ruby just a few years ago helped me reconceptualize
some issues in object-oriented programming [6].

So, why this particular set of languages?  Let's start with Clojure.

**Clojure**

As part of my not-quite-successful pledge to read something new
each day, I read an article by Robert C. Martin entitled "[Why
Clojure](http://blog.cleancoder.com/uncle-bob/2019/08/22/WhyClojure.html)"
in his _The Clean Code Blog_.

This 'blog post was referenced on the Racket Users mailing list.  I
appreciate reading yet another experienced programmer who eventually
realizes that the Lisp family of languages are the best way to go for
most projects.  Martin focuses on Clojure, a Lisp-like language.
From what I can see from his posting, Clojure has some interesting 
variations of the standard Lisp syntax, including a hash for something
like lambda and implicit arguments.  Here's how he writes a program
to print the squares of the first twenty-five integers.

> `(println (take 25 (map #(* % %) (range))))`

The implicit parameter (`%`) is an interesting choice, as is the
implicit lazy evaluation [7] or at least a tightly linked stream
model [8].  In any case, the post suggests that I should probably
spend some time learning Clojure.  As I mentioned in [the notes on
my sabbatical](sabbatical-2019-08-30), I may even consider what 151
would look like if taught in Clojure [9].

I also appreciate two particular paragraphs from the post.

> Smalltalk was small and elegant and beautiful. It spawned the Design Patterns revolution. It spawned the Refactoring revolution. It spawned the TDD revolution. It helped to spawn the Agile revolution. Smalltalk was a language of tremendous impact.

> Finally, Lisp is functional. And the future is looking very functional to me.

I've been predicting success for functional programming for more
than twenty years, so it's good to see someone relatively famous
say it, too.  And the paragraph on Smalltalk reminds me that I need
to learn more about Smalltalk.

Other than supporting my world view, what is it about Martin's post that
makes me want to learn more about Clojure?  In part, it's that Clojure
seems to have chosen a different approach to Lisp-like languages.  In
part, it's that Clojure can compile to both JVM [11] and JavaScript [12].
That means that Clojure programs can easily run on a variety of platforms,
including on the Web.  In each case, it means that one can take advantage
of the large set of libraries associated with each platform.

**Kotlin**

I know almost nothing about Kotlin.  But one of our recent alums, Amanda
Hinchman-Dominguez, is involved in the Kotlin community and speaks
highly of it.  Like Clojure, Kotlin compiles to JVM code [15], giving
it the advantages of a widely adopted platform and a large collection
of libraries. Youngest Son tells me that Kotlin is becoming the language
of choice for Android development [16].

Kotlin comes from the IntelliJ community or, more precisely, from
part of the JetBrains corporation, makers of IntelliJ.  IntelliJ
is one of the most popular IDEs [19] for Java.  We don't tend to
use IntelliJ at Grinnell because it's not open source.  However,
given our problematic experiences with Eclipse over the past few
years, there's a chance that we may consider it again [20].

At first glance, Kotlin looks like yet another language with C-like
syntax and modern object-oriented and functional programming
features---such as classes, lambdas, streams---as well as a bunch
of useful syntactic sugar [21].  And it seems that the Kotlin folks
take functional programming seriously; I guess I should not be
surprised that at least one Grinnell alum has a role in the Kotlin
community.

Are there other reasons to learn Kotlin?  I can see some advantages
to knowing a "modern" language that is growing in popularity.  And
[a lot of programmers seem to really like
Kotlin](https://insights.stackoverflow.com/survey/2019#most-loved-dreaded-and-wanted)
[23].

I also see that the folks at JetBrains have [an educational
platform](https://www.jetbrains.com/help/education/educational-products.html).
That may also be worth checking out [25].

**Other languages**

What about Rust, Smalltalk, C#, Racket, Haskell, and the rest I mentioned?
I'll leave discussion of those languages to another musing or musings.
Perhaps I'll muse about those as I learn them, rather than in advance.

**Learning languages**

I find that I approach learning languages in a variety of ways.  I try
*tutorials*, but I often find them frustrating.  Why are they frustrating?
At times, it's that they are too slow for an experienced programmer.  At
times, it's because I consider the approach they take wrong [27].  Nonetheless,
tutorials can be a good way to start.

When I know a bit about a language, I often *write meaningful, or at least
somewhat meaningful, programs*.  I regularly program to meet my
needs or for fun.  Writing or rewriting a program in a new language
can help me learn more about that language.  For example, I deepened
my knowledge of Ruby by rewriting my grading software in Ruby [28].
That rewrite also helped turn a Perl hack into something a bit more
elegant.  I deepened my knowledge of Liquid and Jekyll by working
on my course Web sites [29].

I often find it useful to *read books about new languages*.  Reading
books gets me away from the computer [30] and can encourage me to 
think more broadly about subjects.  However, I'm primarily a "hands on"
learner, so much of my reading inevitably pushes me toward the keyboard.
Nonetheless, books are useful.  While I think I learn better from printed
books, I'm finding it increasingly useful to read PDFs on my iPad,
since I can more easily mark them up and copy key portions to a
separate set of notes.  I also appreciate the free access to
[Safari](https://learning.acm.org/e-learning/safari) I get along
with my membership in ACM [31,32].  I have to see what note-taking
is like on that platform.

At times, I learn a language by *writing instructional materials*.  Having
to explain something helps you learn it better.  Of course, there are 
also times you learn something incorrectly and therefore share your
inadequate understanding with others [33].  Nonetheless, I am considering
trying to rewrite a few 151 or 207 lessons in Clojure and Python.

Somewhere in that, I find that *playing with a language* helps me learn
it.  "Playing" can me a host of different things.  At times, I try to
make things fail.  At times, I try to understand how it behaves differently
than languages I know.  I recall experimenting with closures in Python
when I was first learning Python and finding myself disappointed.  I
understand that things are better now [34]. 

In any case, I've written enough [35].  It's time to go play with
some languages [36].

---

[1] Why is it incorrectly named?  Because it's written with "C#", and "#"
is not the sharp sign.

[2] I see that I have a sketch of a musing about discovering Pharo.  I
may even finish that musing.

[3] I remember the joys of GHC, the Glasgow Haskell Compiler, also
known as the Glorious Haskell Compiler.  I see that [it still
exists](https://www.haskell.org/ghc/).

[4] As an academic, I have a curriculum vitae rather than a résumé.  I
don't list languages on my CV.

[5] I seem to recall something about Hilary Putnam's claims about such
an issue.

[6] Sandi Metz' [_Practical Object-Oriented Design in
Ruby_](https://www.poodr.com/) also had an impact.

[7] In simple terms, lazy evaluation is an approach in which you only
evaluate as much of something as you need.  In this case, although we're
using an infinite list of integers, since we only need the first
twenty-five, we only build the first twenty-five.

[8] Streams are like lists that you build on demand.  In some languages,
they provide a compromise between pure lazy evaluation and more standard
evaluation models.

[9] I look forward to any comments my fifth-year colleagues [10] may have
on Clojure.

[10] Or anyone else, for that matter.  It's just that my fifth-year
colleagues are more likely to (a) read my musings and (b) have an
opinion on the matter.

[11] The Java Virtual Machine.

[12] Youngest Son would probably say that it "transpiles" to JavaScript.
I'm not sure how I feel about the rewriting of a long-standing poorly-chosen
name [14].

[14] Computer scientists tend to use the term "compile" for "translate
a program from a high-level language to an executable", or something
like that.  It's a horrid term, since "compile" traditionally means
"put things together".  If I understand my computing history,
"compile" was usually the *last* step of the translation; you joined
together translated high-level language files with libraries to
create the executable.  And even that simplifies things a bit.  In any
case, it seems strange to use "transpile" instead of "translate".

[15] And, it appears, transpiles to JavaScript.

[16] It appears he's correct.  A quick Web search reveals [a seemingly-valid article
that makes the claim](https://techcrunch.com/2019/05/07/kotlin-is-now-googles-preferred-language-for-android-app-development/) and [a Kotlin page on the official Android developer site](https://developer.android.com/kotlin).  Ah, here's the real deal: [the announcement on the official Android Developers Blog](https://android-developers.googleblog.com/2019/05/google-io-2019-empowering-developers-to-build-experiences-on-Android-Play.html) [17].

> Today [18] we’re announcing another big step: Android development will become increasingly Kotlin-first. Many new Jetpack APIs and features will be offered first in Kotlin. If you’re starting a new project, you should write it in Kotlin

[17] I would write that as "Android Developers' 'blog", but what do I know?

[18] 7 May 2019.

[19] Integrated Development Environments.

[20] Of course, if we switch from Java to something else in our Data
Structures and Algorithms course, the question of Java IDE will no
longer be important.

[21] "Syntactic sugar" is a term for language constructs that don't
enhance the capabilities of the language [22], but make it more
convenient to write some things.

[22] Yes, dear readers, I do know that the Church-Turing thesis suggests
that all languages are equally powerful.  But there's a difference
between the addition of an object model and a more concise way to
represent, say, setters and getters.  I'd call the addition of objects
an enhancement to the capabilities of the language and a concise way
to add setters and getters a form of syntactic sugar.

[23] Of course, a lot of programmers really like Python and that doesn't
mean that it's a beautiful language.  I think there was even a time that
a lot of programmers liked Perl [24].

[24] I still like Perl, at least for certain tasks.

[25] I realize that some of my colleagues may object to using commercial
products.  However, I see that there is a "community" version of
IntelliJ and, well, it appears that the commercial/community pairing
is becoming almost inevitable in many FLOSS endeavors [26].

[26] Racket appears to be primarily open.  However, recent discussions
on the Racket Users mailing list suggest that the way Racket was developed
means that some licensing issues are unclear.

[27] Somewhere in my unorganized collection of notes for musings, I have
notes on why I dislike the Ruby tutorial that we tend to use for our
software design course.

[28] Unfortunately, I haven't done enough Ruby programming since then,
so lots of that knowledge has faded a bit.

[29] I realize that deepening my knowledge of Liquid may have damaged
my brain.  Liquid is an unpleasant language.

[30] Except when I read them on an electronic device.

[31] Students: Student membership in ACM is fairly cheap ($19/year)
and, at last count, gave you access to Safari.

[32] I may have to take back my comments about the joy of having
Safari as an ACM benefit.  I've just spent fifteen minutes trying
to get that benefit to work correctly, and the
[FAQ](https://learning.acm.org/faq/safari-faqs) does not tell me
what to do when I get a message like, "Your membership was canceled,
Samuelrebelsky. Please contact your administrator or O'Reilly
Support."

[33] If I recall correctly, _Experiments in Java_, which I wrote about
two decades ago, describes the `import` statement incorrectly.  At the
time, I was wedded enough to C that I thought that `import` was much
like `include`.  However, `import` is more about namespaces and
linking than including code.

[34] More on that issue in a subsequent musing.

[35] Perhaps I've written too much.

[36] And environments.

---

*Version 1.0 of 2019-09-09.*
