Adding infrastructure for an opt-out email list
===============================================

*Topics/tags: [Rants](index-rants), [the joy of code](index-joc), [overcommitment](index-overcommitment), SIGCSE-infodir, mailing lists*

As many of my readers know, one of my more significant professional
responsibilities is to manage the mailing lists for SIGCSE, the Special
Interest Group in Computer Science Education.  SIGCSE has two mailing
lists: SIGCSE-ANNOUNCE is intended for announcements from the SIGCSE
leaders (the board, the conference chairs, the list moderators) and
SIGCSE-MEMBERS is intended for general discussion.

Recently, we decided to switch SIGCSE-ANNOUNCE from an opt-in list
(that is, people ask to be added) to an opt-out list (that is, members
of SIGCSE are automatically added and must opt-out of the list).
In discussions with ACM, it sounded like the best approach was to rely
on ACM's current system for autopopulating lists.  As I understood it,
that system would grab the list of current members every Friday, remove
those who had unsusbscribed, and update the list.  And I assumed [1]
that it would have a sensible structure.

I was wrong.

There are many flaws in the ACM system.  Given that ACM is an organization
of computing professionals, that makes me sad.  What are the flaws?  Here
are the ones folks have complained about [2]:

* If you click the "Unsubscribe" link in an email message, it unsubscribes
  you without any confirmation.
* The "Unsubscribe" URL has a form that appears to allow you to
  unsubscribe *anyone* from the list.  There appears to be no
  verification that the person doing the unsubscribing is the same
  as the person who is being unsubscribed.
* It can take as much as a week for the unsubscribe request to propagate
  through the system.  Since the listserv software accepts immediate
  updates, that seems like a long time.
* As far as I can tell, when the list is repopulated, any settings the
  user had chosen are erased [3].

It is unlikely that I will get ACM to change their software.  Hence, it
looks like we're going to have to manually manage an opt-out list, or at
least design our own software for managing the list.  The rest of this
musing represents my attempts to think through the associated issues.

We can get the current membership data from ACM.  That data includes
membership number, start date, end date, name, and email address.
There's also additional information, but I think those five parts are what
we need.  Unfortunately, there are some interesting complexities.  First,
there are two lists, one for those with electronic-only subscriptions
and one for those who like getting physical items, too.  Folks may
decide to change which list they are on.  Second, it appears that the
start date represents when they first joined, rather than when they
most recently joined.  That is, if someone allows their subscription
to lapse and then rejoins, we still use their original start date.
Third, we have to download the data manually, or at least I think we do.
I'm not sure how to get around the pair of login screens.

We can also get the current list member

Let's assume that we keep both the previous membership data (from the
previous time we ran this process) and the current membership data
(just downloaded).  Given all that, what are the cases?

* *A new member.*  We can tell that we have a new member because we see
  an ACM membership number that we had not previously encountered.  We
  add this person to the list and send them an email message explaining
  why they were added.  "Welcome to SIGCSE.  All members of SIGCSE are
  automatically added to SIGCSE-ANNOUNCE.  You can unsubscribe.  There's 
  also a second list.  Etc. Etc."
* *A newly-lapsed member.*  That is, someone whose membership has expired
  and who is currently on the mailing list.  In this case, we should remove
  the person from the mailing list and send them a message explaining why
  we have done so.  "Your membership in SIGCSE has expired.  Because the
  SIGCSE mailing list is restricted to current members, we are removing
  you from the SIGCSE-ANNOUNCE list.  We're sorry to see you go and hope
  that you will consider rejoining in the future."
* *A soon-to-be-lapsed member.*  Advance notice is good.  If someone
  is about to be deleted from the listserv in the next pass, we should
  send them advance warning.  "You membership in SIGCSE is about to
  expire.  Because the SIGCSE mailing list is restricted to current members,
  we will remove you from the mailing list in the near future.  Please
  consider renewing your membership." 
* *A member who has just rejoined.*  There seem to be two subcases here.
  If the member had previously opted out of the mailing list, we should
  not add them.  However, if they had been removed from the mailing list
  because their membership had expired, we would need to 

---

Postscript: On a more positive note,  ...

---

[1] Remember what they say about assuming?

[2] I appreciate being part of an organization whose members notice
these things.

[3] I'll need to wait until it's repopulated to know for sure.

