Abusing software
================

*Topics/tags: [Project Callisto](index-callisto), technology*

*Trigger warning: This musing contains some discussion of Project Callisto,
Web-based software for recording and reporting sexual assualt.*

As I've mentioned recently, for the past year, my CSC 322 students have
been working on a port of [Project Callisto](...), Web-based software for
recording and reporting sexual assault.  One of the important features
of Callisto is that you can enter a report without submitting it and
have the Title IX office get notified when there's a "match", someone
else who reports the same person.  When my students starting working
with Callisto, they turned off matching.  In part, there were questions
about whether Grinnell wanted that feature.  In part, it seemed strange
that matching relied on the survivor entering the Facebook page of the
person they identified as their assailant.

Now we're talking about re-enambling matching.  I'm a bit worried.  One
of the Callisto installations we've looked at says

> Match: When you enter someone's name and someone else enters the name,
you and the Title IX office get notified me.

Maybe it's just me, but that feature strikes me as ripe for abuse.  What
do I mean?  Suppose you suspect River Smith of sexual assault on campus.
You could create a new email address (e.g., on Gmail), enter a mostly
blank report, and identify River as the potential assailant.  If you
get a match, you have "evidence" that someone else has accused them.
Since you haven't provided any direct evidence or report to the Title
IX office, you could argue that you have not provided a false report.

An assailant could do something similar.  Want to know if someone
reported you?  Identify yourself as an assailant in the matching system,
but don't submit a report.  When you hear about a match, you know that
someone has entered a report about you [1].  Since assailants are
increasingly suing colleges for the penalties they receive, I could see
some using this strategy as the first step in sending a subpeona for
information.  "Someone identified my client on Project Callisto.  That 
may have impacted how the College tried my client.  I demand the report."

Can we solve that problem?  Certainly.  It strikes me that the best first
step is that we ensure that Callisto *not* notify someone of a match.  
Rather, we can have a match trigger notification to the Title IX office
and then they can decide whether or not to contact the reporters.  I would
guess that there would be a policy something like "If the reports have an
associated Grinnell address, contact people to hear if they would like to
submit the report.  Otherwise, ignore it."


---

[1] Or perhaps is using the strategy in the prior paragraph to see
if anyone identifies you.
