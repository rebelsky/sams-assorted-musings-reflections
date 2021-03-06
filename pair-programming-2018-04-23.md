Pair programming with my class mentor
=====================================

*Topics/tags: [The joy of code](index-joc), [teaching](index-teaching)*

As I've noted previously, [pair programming plays a large role in Grinnell's
CS curriculum](working-in-pairs-on-hw-2018-02-23).  We see many benefits in
programming in pairs.  Some are similar to the benefits that professional
programmers see, such as better code, the opportunity to consider alternative
approaches, and the joy of working with other people.  Some are specific to
student experience, such as meeting new people and learning about your own
and others' talents.

As an old faculty member, I have too few chances to program and even fewer
chances to pair program.  I do write some software, sometimes [for 
myself](software-for-grading), sometimes as part of my research.  But much
of that coding is done late at night, alone in my home office.  I do, at
times, grab a colleague when I find a bug.  In most cases, they serve mostly
as a sounding board.  Like many programmers, I find that the opportunity to
talk through my code provides a good way to find errors.

But once in a while, I do have the opportunity to pair with another person
for a few minutes or a few hours.  A few years ago, I paired with Youngest
Son for one of my research projects [1].  That was great.  This past Friday,
my class mentor [2] and I decided to spend our weekly meeting time trying to
figure out how to add a feature to one of the class projects [3].

I will admit that I had forgotten how much I appreciate working with
someone else.  I served as driver and my class mentor served as navigator.
We have enough trust that she was willing to make suggestions and
challenge what I was doing.  If I recall, one of her most important
comments was "Sam, that may solve the problem at hand.  But shouldn't
we prepare for the future?  I'd rather throw away the bad decision from
the past group and write the right thing now than write code that only
follows that past decision."  Of course, she was right.  So we ended up
writing code that supported either decision as to how to organize data.
Since I don't regularly program in Ruby or Rails [4], she also served
as a great reference and checker.  "No, Sam, that's not how you do it."
"Sam, I looked that up, here's how they recommend doing it. [5]"  We
only worked together for about twenty minutes, but we got a lot done.

Then I cleverly asked someone who more regularly works in Rails to do a
code review of the pull request.  And, well, it's clear that my class
mentor and I don't regularly write Rails code and that we were working with
a code base that was developed by novice Rails programmers.  We got way
too many good suggestions on how to improve what we had done.

Nonetheless, I'm pleased by what we accomplished in twenty minutes.  I
also feel lucky to have such an awesome class mentor.  I'll miss her when
she graduates.

I should find more ways to pair program with other folks who are willing
to challenge my coding decisions.  I also drive too much; I wonder how
I'd do as navigator.

---

[1] I know more about program design than he does.  He knows more about the
ins and outs of JavaScript than I do.  I think we both found it an interesting
learning experience.

[2] I prefer not to identify current students by name in my musings.

[3] The students had spent a lot of time with code from a previous semester
and some not-so-clearly documented Gems.  Both the mentor and I had spent some
one-on-one time with students.  

[4] And I certainly don't regularly use the Gem we were using.

[5] One of the "recommended" approaches we chose was identified in a subsequent
code review as a clear violation of the Law of Demeter.  Oh well, we can't
be perfect.

---

*Version 1.0 released 2018-04-23.*

*Version 1.0.1 of 2018-04-24.*
