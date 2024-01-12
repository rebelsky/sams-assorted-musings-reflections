---
title: Distractable
number: 1269
tags: [Overcommitment](index-overcommitment)
blurb: One of the causes of overcommitment. Perhaps a symptom.
version: 1.0
released: 2024-01-09
current: 
---
Today I planned to work on [the image library for CSC-151](csc151-image-models-v1). Here's how that went.

First, I started [a musing about that library](csc151-image-models-v1). After all, it's better to get my thoughts in order before writing.

When I was halfway done with musing, I started exploring my various implementation options. I've been using Racket structs, but I decided to consider objects, especially since I was designing what looked like an inheritance hierarchy. I ended up sticking with structs.

Rather than working with images, I decided I needed to work on the color model. While the `2htdp/image` library has a perfectly serviceable color model, I don't like the name of that model because it uses `color` to mean `rgb color`. Of course, I'm going to use `rgb` to mean `rgba` color, so perhaps I shouldn't complain.

While working on the revised color library, I decided that it was important to improve my documentation. That meant starting to work on a type predicate library [1]. That meant considering whether I should put those new procedures in the forthcoming CSC-151 reference. 

Working on the CSC-151 reference reminded me that I should be writing tests [2]. And I tend to be a bit excessive on tests. For example, here are the tests for the new `nonnegative?` predicate.

```
(test-true "zero is not negative (exact)" (nonnegative? 0))
(test-true "zero is not negative (inexact)" (nonnegative? 0.0))
(test-true "negative zero is not negative (exact)" (nonnegative? -0))
(test-true "a small exact integer is nonnegative" (nonnegative? 3))
(test-true "a small rational is nonnegative" (nonnegative? 1/312231))
(test-true "a small real is nonnegative" (nonnegative? 0.00000001))
(test-true "a large exact integer is nonnegative" (nonnegative? (expt 3 100)))
(test-true "a large rational is nonnegative" (nonnegative? (expt 11/3 100)))
(test-true "a large real is nonnegative" (nonnegative? (expt 1.23 101)))

(test-false "-1 is not nonnegative" (nonnegative? -1))
(test-false "a small negative exact integer is not nonnegative" (nonnegative? -3))
(test-false "a small negative rational is not nonnegative" (nonnegative? -1/11))
(test-false "a small negative real is not nonnegative" (nonnegative? -0.0000002))
```

Writing these tests meant that I should be setting up a test infrastructure for the CSC-151 libraries. I took the easy way out: I set up a directory with separate test files for each procedure I wanted to test.

I also started writing reference pages for these procedures. Or perhaps I started writing the reference pages and decided those pages should also have tests. I forget.

Working on the reference pages reminded me that I wanted to find a way to identify deprecated procedures [3]. Why am I documenting deprecated procedures? Um, I'm not sure.

As I updated the scripts to build the reference pages, I realized that I had some other issues I wanted to explore, such as how I would handle multiple versions of a procedure [4]. So I started writing reference pages for the zero-parameter, one-parameter, and two-parameter versions of `random`. And I spent some time working on the underlying "summarize documentation" code.

Then I realized that I was being distractable. The only solution to being distractable is, of course, to write a musing about being distractable. So I started this musing. While writing it, I did some more of the tasks above.

At that point, I had to make dinner and clean up from dinner.  By the time I was done, it was 7pm and I had not yet started writing the primary library. Oh well, back to colors. I finished colors at 8pm. Then I was stuck with the question: Should I keep coding or should I post my musings?

I haven't covered all the other ways in which I distracted myself today: listening to shows on StageIt, making food for my family, looking at stuff on ebay [5], booking hotel rooms, answering SIGCSE TS [6] emails, and such. It also doesn't help that I slept until 10:00 a.m. [7].

Fingers crossed that I'll get the library done tomorrow. Unfortunately, there's some shoveling to do and I have at least three meetings scheduled [8].

---

[1] I'm not sure why I don't find `any/c` and `or/c` satisfactory. I want `any?` and `any-of`.

[2] I'm including tests in the reference materials. Well, I'm *trying* to include tests in the reference materials. Perhaps I'm trying to include tests in *selected* reference materials.

[3] A deprecated procedure is one that still exists but that programmers are discouraged from using. I'm still deciding wht to do about documentation for such procedures.

[4] What procedures have multiple versions? One that comes to mind is `random`. `(random)` procedures a real number between 0 (inclusive) and 1 (exclusive). `(random n)` produces an exact integer between 0 (inclusive) and `n` (exclusive). `(random lb ub)` produces an exact integer between `lb` (inclusive) and `ub` (exclusive). 

`map` also has multiple versions. Or at least I think of it as having multiple versions. `(map fun lst)` builds a new list by applying `fun` to each element of `lst`. `(map fun lst1 lst2 ... lstn)` builds a new list by applying fun to the corresponding elements of each of its parameter lists. While the first `map` is encompassed by the second one, I prefer to document them separately.

`square` has multiple versions, as I observed in [that musing about the image library library](csc151-image-models-v1). Of course, those multiple versions are one reason I marked `square` as deprecated.

[5] Sorry Micki.

[6] "SIGCSE TS" is the annual Technical Symposium of the Association of Computing Machinery's Special-Interest Group on Computer Science Education. The conference used to be called "SIGCSE", but we now refer to it as "SIGCSE TS" to distinguish it from "SIGCSE" the special-interest grouop

[7] At some point I'll muse about my sleep issues.

[8] SIGCSE TS 2025 [9], my therapist, and our money manager.

[9] Yeah, I'm simultaneously working on SIGCSE TS 2024 and SIGCSE TS 2025. At some point soon, SIGCSE TS 2024 will become less time consuming [10].

[10] At least until we hit conference time.
