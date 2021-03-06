Unsubscribe
===========

I help run the electronic mailing lists for one of my professional
organizations [1].  That means that I get to approve or reject each
post, add members to the list, answer questions, send out notes about 
etiquette, and all sorts of other things [2].

One nice feature of the mailing lists is that it's really easy to
unsubscribe.  Every message you receive from the list ends with
a link that says "Unsubscribe".  If you follow the link, you'll end
up on a page that says "Are you sure that you want to unsubscribe
from the list?" and choices of "Cancel" and "Confirm".

That sounds reasonable, right?

In practice, it turns out to be problematic.  For example, it seems that
we regularly have the situation in which someone forwards a message from
the list to someone else, and that other person clicks "Unsubscribe" [3].
Magically, a list member who had no intention of leaving the list has been
booted off.

So, how can one fix this "obvious" UI [4] problem?

It would be nice if the mailing list software said "Are you sure that 
you want to unsubscribe EMAIL ADDRESS from MAILING LIST?" so that the
person unsubscribing see what they are doing.  But would venture
to guess that at least 50% of people don't read the text associated with
an unsubscribe page; they just click "Okay" [5].  And some small portion
would choose to unsubscribe anyway, even if it isn't them.  Nonetheless,
this would be a big improvement, and I've asked my technical contact
at ACM [6] to send this request to the folks at Listserv.

It might be nice to send a confirmation message about the unsubscription
[7].  As list moderator, I get such a message.  These days, I forward
it along to the former subscriber, along with a message something like
the following.

> It appears that you have unsubscribed from the SIGCSE-members
mailing list.  We've had some recent issues with people accidentally
being unsubscribed, so we are writing to make sure that each instance is
intentional.  Did you intentionally unsubscribe from the SIGCSE-members
mailing list?  If not, would you like us to resubscribe you?

But that process could happen automatically, rather than manually.
Folks could click something like "It was an accident, please restore
my subscription".  Alternately, they could confirm that they had
unsubscribed.  After all, most mailing lists ask you to confirm that
you've subscribed [8].  But I'm not in the mailing list industry; it
could be that people generally get upset when they unsubscribe and then
get another message [10].  

Alternately, the "unsubscribe" page could ask people to enter their
email address and the system could match the email address to the one
supposedly associated with the request.  That would avoid most accidental
unsubscribes.  But it can have an effect on intentional unsubscribes.
For example, I get much too much fundraising email from the Democratic
Party [11].  I kept trying to unsubscribe, but the mail kept coming.
Eventually, I realized that I was trying to unsubscribe from my primary
email address, but the spam was coming to my secondary email address.
So the "match the email" system failed to achieve my goal as subscriber.

What seems like an easy UI problem is not so easy.

But it's a common enough problem that you would expect that (a) someone
would have studied the issue [14], (b) someone would have come up with a
reasonable solution, and (c) Listserv would have adopted it.  Of course,
UI components and process can now be patented, so it could be that there
is a sensible mechanism and the patent system prevents Listserv from
implementing it.

For the time being, we make do with a simple work-around: I act as the
human check on the system and send a "Did you intend to unsubscribe?"
message.  It could be better, but it could be worse.

---

On a related note, the problem got bad enough recently that I sent
a note to the list.

> You may notice an "UNSUBSCRIBE" link at the bottom of your messages
from SIGCSE-members.  When you *or anyone else* clicks on that link, you
are unsubscribed from the mailing list.  We've had multiple instances of
members being unsubscribed by someone to whom they forwarded a message.
Hence, when you forward a message from the list to someone else, please
make sure to remove the "UNSUBSCRIBE" link.

The responses were interesting.  A few folks who had been unsubscribed
recently wrote back to say "Ah, that's probably what happened to me."  A
few others wrote back and made comments on the lack-of-sense of this UI.
My favorite went as follows.

> As we learn that the root cause of a false alarm in Hawaii was
likely poor design of the underlying software used in the system,
I find it ironic that the software for member communications of the
premier professional society in the world for computing apparently has
similar problems!

And I thought I was snarky!  In any case, this subscriber has clearly
not dealt much with ACM software.

---

[1] SIGCSE-members and SIGCSE-announce, the two mailing lists of the
ACM Special Interest Group for Computer Science Education.  SIGCSE-members
is our general mailing list; SIGCSE-announce is for announcements from 
the board and a few others.

[2] At some point, I'll post a note about my workflows.

[3] While it feels a bit rude to unsubscribe someone else, I think most
recipients don't realize what they were doing.  They think "Oh, I just
got a message that I don't really want and I'm not sure about the source.
I should unsubscribe."

[4] User interface.

[5] Or "confirm" in this case.

[6] It's taken a few years, but I now seem to have a really good technical
contact at ACM.  They have to deal with way too many strange questions
from me.

[7] Is "unsubscription" a word?

[8] Ours tells you that you've been subscribed, but gives you some options
for unsubscribing.  It also has a few screenfuls [9] of information that
evidence suggests no one reads.

[9] Should that be "screens full"?

[10] While I'm okay asking for a wording change on a page, it does
not strike me as productive to suggest that they change their whole
unsubscription model.

[11] My politics should not be a surprise to anyone.  I also get fundraising
email from the Green party [12], but much less frequently.

[12] I've voted for two different Green presidential candidates and I do
contribute.

[14] Someone may have studied the issue.  But my quick search of the
ACM digital library doesn't reveal any studies.

---

*Version 1.0 of 2018-01-17.*
