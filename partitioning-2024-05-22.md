---
title: Partitioning arrays
number: 1283
tags: [Technical](index-technical), teaching, algorithms, unedited
blurb: Questioning approaches.
version: 1.0
released: 2024-05-22
current: 
---
This semester, like many semesters, I taught a course in data structures and algorithms. These days, I'd call it a course in abstract data types, data structures, algorithms, and object-oriented programming. The course is currently number CSC-207. When I started at Grinnell, it was CSC-152. But it's mostly the same material.

One of my favorite algorithms in the course is called _Quicksort_ and was published by C.A.R. "Tony" Hoare in 1961. It is the [64th algorithm published in _Communications of the ACM_](https://dl.acm.org/doi/pdf/10.1145/366622.366642). It's fairly straightforward.

To sort a nontrivial (sub)array of values, you first rearrange ("partition", in Hoare's parlance) the values so that the small ones are on the left and the large ones are on the right. You then recursively sort the small ones and the large ones.

It's a simple, straightforward, idea. But there are some hidden complexities. First, how do you determine what is small and what is large? Ideally, you'd determine the median. Anything smaller than the median is small and anything larger than the median is large. Unfortunately, finding the median is a non-trivial problem. Hoare's idea was that we could choose a random element of the array and it would work relatively well in most cases. There's even a formal proof of that.

In essence, Quicksort is a _divide-and-conquer_ sorting algorithm that partitions the elements into smaller and larger elements using a _randomized pivot_ and then recursively sorts the two parts. 

What about partitioning? In some sense, it depends on the data. If the data are in a list, you can just grab elements off the list and put them in one of two (or one of three) lists. But if the data are in an array, you'd like to rearrange the array in place. That's Hoare's partition algorithm, [Algorithm 63 in _Communications of the ACM_](https://dl.acm.org/doi/pdf/10.1145/366622.366642).

We'll discuss the details of Hoare's partition in a moment. But first, we'll take a step back in time and consider things computer scientists and computer programmers once had to worry about. One things was memory. If you could rearrange the values in place, you didn't have to worry about allocating extra memory. Since memory was limited and expensive, your program could process larger inputs if you were able to rearrange in place.

Then there's the question of accessing memory. In general, there are two primary operations we can do: We can read from memory and we can write to memory. These days, there are multiple layers of abstraction in writing and reading values since there's a "memory hierarchy". I suppose there may have been one then, too. In any case, since it's costly to read and write, or it was costly, we want to limit the number of times we read or write values. And, as I recall, writing used to be much more expensive (in terms of the time for the operation) than reading. Hence, in writing a partition algorithm, you would try to limit the number of times you read and wrote values, paying particular attention to the writes.

This semester, like most, I taught a simplified variant of Hoare's partition method, one that partitions the array into two parts, with the pivot at the middle. However, on the take-home learning assessments, many students seemed to choose a very different approach. That puzzled me. Where were the learning something else? And why were they using a clearly inferior approach? The answer to "where" may be obvious: [GeeksForGeeks](https://www.geeksforgeeks.org/implement-various-types-of-partitions-in-quick-sort-in-java/).

But is it inferior? Let's take a quick look.

## Hoare's partition algorithm, simplified

We'll start with a simplified version of the simplified version of Hoare's algorithm that I normally cover. The algorithm uses two indices, which I'll call `small` and `large`, to partition the array into three parts. Everything to the left of `small` is small. Everything to the right of `large` is large. Everything between the two still needs to be processed.

Here's a pictoral invariant.

```
+-------------+-------------+-------------+
|  smaller    | unprocessed |   larger    |
+-------------+-------------+-------------+
              |             |
              small         large
```

What about the pivot? We have that hidden, off to the side.

At every step, we move `small` to the right over small elements and `large` to the left over large elements. Eventually, either the two meet or `small` is immediately before a large element and `large` is immediately after a small element. At that point, we swap and move the two again.

When implemented correctly, this version of partition looks at each element exactly once and moves each element at most once. That's pretty efficient. It's hard to do better.

How does it differ from Hoare's partition? In two ways. First, Hoare's is intended to work on subarrays in addition to full arrays. That's the version I normally teach. Hoare's is also a tripartite partitioning algorithm: Instead of dividing the array into small and large parts, Hoare's also creates a section for elements equal to the pivot. I teach that one as the _Dutch National Flag_ algorithm and use it as a reason to learn about invariants.

## Lomuto's partition algorithm

What about the algorithm many of my students were using? GeeksForGeeks calls it "Lomuto's Algorithm". [Wikipedia](https://en.wikipedia.org/wiki/Quicksort) tells me that it was published by Jon Bentley in one of his Programming Pearls columns. 

Once again, we can think about the algorithm in terms of the state of the system midway through the algorithm. Once again, we have smaller, unprocessed, and larger values, but in a somewhat different arrangement.

```
+-------------+-------------+-------------+
|  smaller    |    larger   | unprocessed |
+-------------+-------------+-------------+
              |             |
              small         i
```

The primary step of this partitioning algorithm is much simpler. We look at the element at position `i`. If it's large, we just advance `i`. If it's small, we swap it with the first larger element and advance both `small` and `i`.

Once again, we only have to look at each element once. But we may have to do a lot of swapping. Consider the following, where `S` stands for small and `L` stands for large.

```
+-------------------------+
| L S S S S S S S S S S S |
+-------------------------+
```

We'll have to swap each of those `S` elements as we progress through the array. That's a lot of swaps. In contrast, Hoare's algorithm would only have to do one swap, of the first large element with the last small element, and then skip over the remaining small elements.

Arguably, each `swap` also requires us to look at values, so the Lomuto algorithm may require significantly more memory reads in addition to those extra writes. [Wikipedia](https://en.wikipedia.org/wiki/Quicksort) tells me that it's about three times as many.

## An unnamed algorithm

There's a third algorithm that seems a bit like Hoare's and a bit like Lomuto's. A student found it on [YouTube](https://www.youtube.com/watch?v=tIYMCYooo3c), where it seems to be written by "The Coding Channel". In this version, we use the rightmost element as the pivot. (We can, of course, swap any element to that place.) We then iterate from left to right. If we encounter a small element, we skip over it. If we encounter a large element, we swap the pivot left and then swap the large element with the eleemnt that is now immediately after the pivot.

Here's the visual invariant.

```
+-------------+-------------+-+-----------+
|  smaller    | unprocessed |p|  larger   |
+-------------+-------------+-+-----------+
              |             |
              i             pivot
```

What does that weird multi-way swap look like? Consider the following.

```
+-------------+-------------+-+-----------+
|  smaller    |6    ...    3|5|  larger   |
+-------------+-------------+-+-----------+
              |             |
              i             pivot
```

6 is bigger than 5 (the pivot), so it needs to go where the 5 is. The 5 needs to move left to where the 3 is. And the 3 needs to move where the 6 is.

```
+-------------+-----------+-+-+-----------+
|  smaller    |3    ...   |5|6|  larger   |
+-------------+-----------+-+-+-----------+
              |           |
              i           pivot
```

In this case, we can't move `i` because the value we just swapped over can be small or large.

A nice part of this algorithm is that the pivot automatically ends up in the right place. But it's a bit more complicated to implement and it seems to require a bit more swapping.

### Comparing the algorithms

As I said, I was raised [1] in a time when you worried about the number of array accesses and you worried even more about the number of writes. From that perspective, Hoare's appears to be a clear winner. I expect that Lumoto's is the one that students will find easiest to implement.

Let's see how they work in practice.

_Sam goes away for too much time to write code. You can find the code at <https://github.com/Grinnell-CSC207/partition-experiments>._

I wrote two variants of Hoare's algorithm and one variant of Lumoto's. I ran Quicksort with each of them five times each on five different arrays of size 10,000,000. Why five times per array? Because I'm choosing random pivots, and the choice of pivot affects the partition.

What did I discover?

In terms of calls to read values from the array, Hoare's required between 319 million and 345 million calls, with a median of 329 million. In contrast, Lomuto's crequired between 445 million and 495 million, with a median of 479 million. Lomuto's requires about 1.5 times as many reads.

In terms of calls to writes values, Hoare's required between 120 million and 123 million, with a median of 122. In contrast, Lomuto's required between 287 million and 337 million, with a median of 306 million. Lomuto's requires about 2.5 times as many writes.

That sounds much worse, doesn't it? I was right about write [2]!

I also ran a timer [3]. Hoare's took between 1017 and 1293 milliseconds, with a median of 1078. Lomuto's took between 962 and 1222, with a median of 1081. 

Damn! They are basically indistinguishable in practice. 

I wonder how many other things I learned as a young computer scientist are no longer relevant?

Maybe I should try the tripartite Quicksort.

---

[1] Raised? Trained? Perhaps "I learned CS".

[2] Sorry.

[3] For Java folks, I got `System.currentTimeMillis()` before and after the call to Quicksort.
