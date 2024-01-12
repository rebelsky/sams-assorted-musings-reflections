---
title: Fun with ChatGPT: Finding angles between points
number: 1270
tags: [ChatGPT](index-chatgpt)
blurb: Getting things wrong.
version: 1.0
released: 2024-01-11
current: 
---
Today I was continuing work on [the new CSC-151 graphics library](csc151-image-models-v1). One of the things I needed to do was to find the angle between three points. Why? I was writing a `rectangle?` predicate and a polygon with four points is a rectangle if the angles between successive points are all ninety degrees.

My brain is not functioning fully, so I decided to ask ChatGPT to write the code for me. Here's what it came up with.

---

_Please write me a scheme procedure that finds the angle between the points a, b, and c._

> Sure, to find the angle between three points A, B, and C, you can use the following scheme procedure:

```
(define (distance-squared p1 p2)
  (+ (* (- (car p2) (car p1)) (- (car p2) (car p1)))
     (* (- (cdr p2) (cdr p1)) (- (cdr p2) (cdr p1)))))

(define (dot-product v1 v2)
  (+ (* (car v1) (car v2))
     (* (cdr v1) (cdr v2))))

(define (magnitude v)
  (sqrt (+ (* (car v) (car v))
           (* (cdr v) (cdr v)))))

(define (angle-between-points a b c)
  (let ((ab (cons (- (car b) (car a)) (- (cdr b) (cdr a))))
        (cb (cons (- (car b) (car c)) (- (cdr b) (cdr c)))))
    (acos (/ (dot-product ab cb) (* (magnitude ab) (magnitude cb))))))

;; Example usage:
;; (define point-a '(1 2))
;; (define point-b '(3 4))
;; (define point-c '(5 6))
;; (define angle (angle-between-points point-a point-b point-c))
;; (display angle)
```

> This scheme procedure calculates the angle between three points A, B, and C using the dot product and the magnitude of vectors. Make sure to replace the example points with the actual coordinates of your points.

---

Looks okay, doesn't it? Perhaps. It doesn't use the form of procedure definition i provide, and it makes the undocumented assumptions that both points and vectors are represented as pairs, but it seems to get the math right.

Unfortunately, it also makes a common mistake among beginning Scheme programmers. That is, it fails to distinguish between pairs and two-element lists. When you take the `cdr` of a pair of real numbers, you get a real number. When you take the `cdr` of a list of two real numbers, you get a list of one real number. Here's what happens when you run the sample code.

```
> (define point-a '(1 2))
> (define point-b '(3 4))
> (define point-c '(5 6))
> (define angle (angle-between-points point-a point-b point-c))
. . -: contract violation
  expected: number?
  given: '(4)
```

Whoops!

Let's see if we can get it to fix the code.

---

_I get an error when I run that code. -: contract violation expected: number?  given: '(4)._

> I apologize for the oversight. It seems there is an issue with the input points or the way they are defined. The error suggests that the code expects numerical values, but it is receiving a list with a single element.

> Here's an updated version of the code that ensures the points are defined correctly:

> [Exactly the same code, with the example usage uncommented.]

> Ensure that your points are defined as pairs of numbers. If the issue persists, please provide the specific points you are using so I can assist you further.

---

Hah! Funny! ChatGPT suggests that the same code will suddenly work correctly.

--- 

_I am using the points '(1 2), '(3 4), and '(5 6)._

> Thank you for providing the points. The issue seems to be related to the `magnitude` function. Let's fix that:

> [Exactly the same code.]

_That seems to be the same code. And I get the same error when I run it._

> I apologize for the confusion. It appears there is an issue with the way the points are used in the example. Let's update the example usage to ensure it works correctly:

```
;; Example usage:
(define point-a '(1 . 2))
(define point-b '(3 . 4))
(define point-c '(5 . 6))
(define angle (angle-between-points point-a point-b point-c))
(display angle)
```

---

Yay! ChatGPT fixed its error.

But I realize that's a strange set of points to choose for an angle procedure. They are colinear, so the "angle" will just be $\pi$.

---

**_Postscript_**: I've decided that I'm going to use the Racket library for complex numbers instead.

