A draft schedule for CSC 207 2019S
==================================

*Topics/tags: [Teaching](index-teaching), Java, CS2, rambly, excessively long, insufficiently edited*

This spring, I'll be teaching CSC 207, (Object-oriented Problem Solving,
Data Structures, and Algorithms) for the first time in about five
years [1].  Old-school CS faculty can think of it as CS2 with additional
coverage of some core object-oriented topics.  I'm glad to come back to
CSC 207, since it's one of my favorite classes to teach.  The class has
changed in many ways since I last taught it.  We've moved from a 4x50
schedule to a 3x80 schedule.  We've decided to add about two weeks on
graphs, including mechanisms for representing graphs and some common
graph algorithms.  I'm dropping the "theme" I used the last time [2]
because it's likely that the support code I wrote no longer works.
It's also the case that some of my colleagues have done a nice job of
creating a collection of substantive homework assignments that fit the
model of "interesting projects that students could naturally extend
to make them 'personal projects'".  A colleague has also started [3]
writing a textbook for the course.  I need to figure out how much of their
material I want to use and how much of my own materials I want to use.
Oh, there's also a new version of Java [4].

As I noted in [my discussion of the schedule for CSC
151](fundhum-schedule-00), one of the first things I do in designing a
course is to put together the schedule.  The schedule will necessarily
be different than the last time I taught the course, not only because
it's switched formats, but also because I may need to cover topics in
a different order to prepare students for the homework assignments I'm
adopting [5].  Of course, I could also do the assignments in a slightly
different order.

I suppose the best way to start is to gather some sample schedules to
see whether there are natural commonalities and orderings.  Here goes.
Almost all of them are fall schedules, which means that I'll likely need
to do some shifting around as I plan for a spring course, particularly
a spring course that starts on Wednesday [6].

**Rebelsky 2014F**

We'll start with [the most recent version I taught](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC207/2014F/handouts/schedule.html).

!!quickschedule MTWF 15 < csc207-schedules/rebelsky-2014F

I'll need to make room for five or so classes on graphs [7].  I also need
to cut fifteen classes as I move from fifty-six (56) meetings to forty
one (41) [8].  I can probably combine some of the two-day topics (e.g.,
one day on inheritance, rather than two).  I don't need the discussion
of Ushahidi, the day of presentations, or the project debrief.  I have
five pauses for breath.  Those are important to have in a schedule; they
allow things to shift around if I discover that a topic needs extra time.
If things don't shift, they've also proven useful as a time to go over
topics that may be confusing students.

**Osera 2017F**

Peter-Michael took "ownership" of the course after he came to Grinnell and
I'll likely be using many of his materials.  Hence, it's worthwhile to 
consider his schedule [9].

!!quickschedule MWF 15 < csc207-schedules/osera-2017F

I see that PM uses "Map" rather than "Dictionary".  I guess that makes
sense, given that Java uses "Map" for the purpose.  I'll have to think
about switching; I think "Dictionary" is a clearer term, since "Map"
can also mean something like "a visual depiction of space or values",
but I see that [Dictionary is "obsolete"](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/util/Dictionary.html) [10].  I don't see explicit days on debugging, unit testing,
exceptions, anonymous inner classes, and more.  I assume some of these
topics get incorporated into other issues; for example, I often use
anonymous inner classes to implement iterators.  I don't think I'll do the
days on map/reduce, but I want to see what my other colleagues have done.

**Walker 2018F**

Henry taught [a section this past
fall](http://www.cs.grinnell.edu/~walker/courses/207.fa18/schedule.php).
I know from the last time we both taught 207 that we approach the material
differently.  But I also know that he was planning to do something a
bit more like PM.   Let's see.

!!quickschedule MWF 15 < csc207-schedules/walker-2018F

Henry tends to group things into "units", so there's perhaps
a bit less detail in my summary than there is in the other two
schedules I've listed.  But I can always look at his [detailed
schedule](http://www.cs.grinnell.edu/~walker/courses/207.fa18/schedule.php)
if I need more info.  Henry spends more time on BSTs and generics than
either PM or I.  He does not cover map/reduce; I should feel comfortable
doing without it.  There's an interesting split in the sorting material;
perhaps I should find out why he made that design decision.  I see that
Henry has maintained loop invariants as a topic; we'd discussed moving
those to CSC 301 when we added graph basics to 207.  

**Stone 2018F**

John also taught [a section this past
fall](https://unity.homelinux.net/courses/object-oriented-programming/schedule-of-topics.pdf).
Let's see if his looks like Henry's.

!!quickschedule MWF 15 < csc207-schedules/stone-2018F

Nope; not at all like Henry's.  I'm not sure whether it's comforting or
troublesome that each of us has such a different take on the course.
In the end, I'm relatively confident that we all cover the same core
ideas; we just approach them differently and add different extras.
John, like Henry, includes some time on loop invariants and does not
cover map/reduce.  I'll probably follow their lead in both issues.
I don't see explicit coverage of the Java debugger or unit testing.
That's okay; I'm keeping both in my section because both are topics
I consider essential.  I'm a bit puzzled that interfaces come after
polymorphism; I find that interfaces provide a good ground for discussing
subtype polymorphism.  But we each have our own approach.  As I may have
already noted, PM leaves inheritance to the end of the semester while
the rest of us cover it relatively early on.  John has added two days
on random number generation.  As I said, we each add different extras.
John is also doing a lot more than Henry or PM on graphs.  I probably
won't do as much as John, either.

**Vostinar 2018S**

One more section to go.  Anya taught the course in Fall 2017, the same
semester as PM, and received some encouragement to use his approach the
first time through.  She then taught her own version the next semester.
Anya has generally been creative in how she's adapted courses.
Let's see what she did with the course [when she taught it in Spring
2018](http://www.cs.grinnell.edu/~vostinar/csc-207-spring-2018-schedule/).

!!quickschedule MWF < csc207-schedules/vostinar-2018S

I see that she's moved inheritance much earlier in the semester.  That
seems like a good idea.  She's kept map/reduce.  There is a nice tie
to CSC 151 in using map/reduce, so I may consider keeping it [11].  We'll see
whether it fits when I include other topics that I don't see covered 
as explicitly.  I don't see an explicit day on unit testing, but I know
that Anya covers JUnit, since some of the labs reference it.  Maybe
everyone else assumes that students will pick it up as they go.

Anya's also added some interesting HackerRank problems.  I'll have to
consider whether or not I want to include some of those.

**Detour: Outcomes from department planning**

Last summer, the department sat down and made a list of what
belongs in the course.  I see I even wrote [a musing in preparation for that
meeting](algorithms-et-al-2018-06-25).  Here's a slightly edited version
of the list we came up with.

* Object-oriented model of computation
    * Polymorphism
        * Subtype
        * Parametric, with Java Generics
    * Inheritance
* Core ADTs and data structures
    * Arrays
    * Lists
        * Linked and array-based
    * Trees 
        * Binary search trees (not balanced)
    * Maps
        * Hash tables with chaining
        * Hash tables with probing
    * Graphs
        * Nodes and vertices
        * Representation: Adjacency matrix versus adjacency list
        * Traversals
        * Minimum spanning tree (Kruskal)
        * Shortest paths (Dijkstra)
    * Heaps
* Software construction
    * More testing
    * Version control with git
* Other algorithmic issues
    * Amortized analysis
    * Sorting
    * Post-hoc analysis of program correctness
* Optional
    * Lists: Fold and filter
    * [Im]mutable data structures

Interesting.  I had thought we'd decided to put "something from the primary 
literature" in CSC 207, just to get students started thinking about how you
deal with translating those kinds of descriptions of algorithms into code.
I've traditionally used skip lists, but I've also considered timsort [12].  
I also see that we have not put the set ADT anywhere.  I expect it naturally
goes with union find, which we cover in CSC 301.  I don't see iterators
mentioned explicitly, but it seems that we all cover them.

**Putting it together**

It looks like it will make the most sense if I start with something
like Anya's schedule and adapt it to my preferences.  I'd like to add
sections on unit testing, debugging, loop invariants, quadratic sorts,
and the list ADT [14].  I might also want to make it clear where arrays,
input and output, exceptions, Javadoc, and such go.

You know what?  I've figured out what I want to do with anonymous
functions.  It makes sense to do anonymous functions immediately
after iterators so that we could, for example, make filtered iterators [16].
I think it also makes sense to do them before sorting because we can
use anonymous functions as comparators [17].

Here's my first draft of the schedule.

!!quickschedule MWF < csc207-schedules/rebelsky-2019Sa

I'd like room for at least one more pause for breath toward the end
of the semester.  But I'm not sure what I'd cut for that.  It may be that
we could do without deletion in BSTs [19].  It also doesn't feel like
four days are enough on graphs.  But, once again, I'm not sure what I'd cut
to free up that space.

Oh well, at least I have a starting point.  I'm likely to make some
changes to deal with other issues, such as the timing of SIGCSE [20].

Next up: Making the Web site, adding detail to each day [21], choosing
readings [22], and choosing labs [24].  I should also decide on the
assignments and make sure that I cover the necessary prerequisite
materials before the assignments are due.  All of those tasks can wait
until another day.

I've also reminded myself that I don't want a lab each day; I know that
there's real benefit to think-pair-share activities, particularly as we
do design work, so I want to make sure to include time for such activities.
I'll figure that out as I do the rest of the work.

---

[1] I last taught it in the Fall of 2014, so it's slightly less than
five years.  Arguably, it's four years and one month since the end
of the last time I taught it and when I'm starting to teach it again.
But "five years" seems like a reasonable estimate.

[2] We explored ways to extend and use
[Ushahidi](https://www.ushahidi.com), a social mapping platform originally
designed to map election violence in Kenya.

[3] But not finished.

[4] I'll muse about versions of Java in the near future.

[5] I'm probably adapting the assignments, rather than just adopting
them wholesale.

[6] This is one of those years in which MLK day falls on the first day of
class.  Instead of classes, we have a variety of talks and such.  Or at
least we're supposed to have a variety of talks and such.

[7] Maybe as few as three, maybe as many as six.

[8] Why did I hyphenate "fifty-six" but not "forty one".  In the first case,
it's serving as an adjective.  In the second, it is not.

[9] PM seems to have removed his course Web site, so I'm relying on files
he sent me.

[10] Dictionary has been marked as "obsolete" since at least
[Java
1.5](https://docs.oracle.com/javase/1.5.0/docs/api/java/util/Dictionary.html).
I assume it was changed because someone realized that the use of an
abstract class was not appropriate, rather than because "Map" is such
a preferable name.

[11] Upon further reflection, I see that I covered these kinds of issues
in a lab I called "[anonymous functions](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC207/2014F/labs/anonymous-functions.html)".

[12] That [earlier musing](algorithms-et-al-2018-06-25) also explains
why I call it "timsort".

[14] I don't mean `java.util.List`.  I like students to design their
own list ADT and to reflect on the issues that distinguish lists from,
say, arrays, on the one hand, and pairs (nodes), on the other.  It's
also a chance to read Joe Bergin's [Lists with "current" considered
harmful](https://csis.pace.edu/~bergin/papers/ListsWithCurrent.html) [15].

[15] At some point, Bergin is going to retire and I'll lose access to
that paper.  I should probably make a local copy.

[16] Whoops.  I see that Anya already had them in that order.  I'm just
doing it a bit earlier.

[17] More precisely, as [`java.util.Comparator`](https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/util/Comparator.html) objects [18].

[18] Am I the only one irritated that Oracle has
changed the form of Java API URLs between Java 10 and
Java 11?  The Java 10 documentation for Comparator is at
<https://docs.oracle.com/javase/10/docs/api/java/util/Comparator.html>.
The Java 11 documentation is at
<https://docs.oracle.com/en/java/javase/11/docs/api/java.base/java/util/Comparator.html>.
I understand why they added `java.base`, but it makes it harder to 
switch between sets of documentation.  Since Google tends to return
old documentation, it also means a few extra steps to find the
current docs.

[19] Or that we could do it as a homework assignment or exam problem.

[20] I try to choose topics that others can more readily teach for the
days that I'll be away.  That means either topics with clear labs or
"standard" topics that don't require an understanding of my particular
approaches.

[21] As [my old syllabus](https://www.cs.grinnell.edu/~rebelsky/Courses/CSC207/2014F/handouts/schedule.html) suggests, I like to have a list of topics for each day.  I'm currently debating between the list of topics and the "blurb" that I tend to write for each class.

[22] While I anticipate relying on PM's material for much of the class, I
also know that I prefer my approach to some topics.  And I have written
most of the material for the course.  

[23] Neither PM nor I have written anything on graphs.  I'll address that
issue closer to the time graphs come into play.

[24] Once again, I'll need to choose between PM's materials and mine.  In
the first few instances I've checked, such as inheritance, I've found
a preference for my approach [25].

[25] That's not so surprising.

---

*Version 1.0 of 2018-12-29.*
