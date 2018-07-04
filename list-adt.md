The list ADT [1]
================

*Topics/tags: [Teaching](index-teaching), [joy of code](index-joc), ADTs*

What's a list?

To most humans, the term "list" is fairly obvious.  It's a
collection of values that have been written down in order.
[Google](https://www.google.com/search?q=list) says that a list is

> a number of connected items or names written or printed consecutively,
typically one below the other.

Lists are also something that we use in computer science.  But it's never
clear to me whether or not we agree on what a list should be.  To some,
"list" means "linked list".  To others, it means "indexed collection
of values".  Given that "indexed" isn't part of the traditional idea of
lists, why do so many programmers and computer scientists include it in
their definition?  Probably because some designer at Sun decided to put
an index operation in Java's list interface.

When I talk about lists, I do my best to pick a minimalist perspective.
A list is a collection of elements (duh) that you can iterate (not
every collection is necessarily iterable) and in which the client
chooses manually specifies the order of iteration (e.g., "this comes
before this").

---

[1] ADT: Abstract Data Type

---

*Version 0.1 of 2018-07-02.*
