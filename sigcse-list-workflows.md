SIGCSE mailing list workflows
=============================

*Topics/tags: [Overcommitment](index-overcommitment), SIGCSE, email, rambly*

One of my professional responsibilities is co-moderator [1] of
the the SIGCSE [2] mailing lists.  As a moderator, I have only a few
responsibilities: I appove or reject posts and I handle new member
requests.  But it's not quite as simple as it sounds.  Let's think about
the various workflows I must follow.

*Handling posts.*  To handle an incoming post, I skim through it and see
whether or not it seems to meet our policies.  What are those policies?
First, it should be relevant to the list.  The SIGCSE-members mailing
list is for discussion of computer science education.  Most members
realize that.  But we get the occasional strange conference announcement.
For those, I look for the keywords "teach", "learn", and "educa..." [3].
A conference announcement with none of those keywords is unlikely to
be relevant to our membership [4].  There are a few exceptions for
conferences that focus on students, but not many.

Next, I check for the secondary policies.  Does it rely on an attachment?
If so, it is not appropriate for our mailing list.  Does it quote an
inordinate amount of material?  If so, it makes the reading experience
much less good for our subscribers who read in digest form [5].

There are also a few other cases, such as posts that seem irrelevant or
intended only for the original poster [6].  

I am then left with three primary options.  I can approve the post,
reject the post, or ask the author to repost.  The first option is the
easiest.  I click a link in the post, the system processes the approval,
and the message goes off to the list.  The second option is a bit harder.
I need to log in to the moderation site, find the post, and click the
"reject" button.  The third option is the most time consuming.  In that
case, I also write a polite message to the poster.  For those who have
seem to have violated the policies, I explain those policies and ask
them to repost.  For those who may have inadvertently carbon-copied the
mailing list, I check to see if that was their intent.  In the few other
cases, I do whatever seems most appropriate.

It is rare that I simply reject; I generally think our posters deserve
the courtesy of an email message.  But there are some messages that are
relatively easy to reject without additional followup.  As I noted, I
generally reject conference announcements that are irrelevant to SIGCSE.
But there are a few that *might* be relevant; in those cases I try to
send followup.  One-line messages that are clearly intended for another
poster and not for the list rarely warrant a followup.  And, of course,
spam just gets deleted.

Unfortunately, not all requests to approve messages on the listserv come
to me through email.  The listserv only forwards messages for approval
if they come from current members who submit using their corresponding
email address.  However, if someone submits from an address not on
the mailing list, the only way to know that is by logging in to the
administrative interface [7].  About half the mail that comes in that
way is from subscribers.  The rest is a mixture of spam, messages from
members who are using a different mailing address [8].  The interface
is a bit different, but I handle these in the same way: I approve,
reject outright, reject with followup message, request clarification,
or check with the SIGCSE Chair [9].

Of course, those processes are only for the SIGCSE-MEMBERS mailing list.
I also moderate the SIGCSE-ANNOUNCE mailing list.  SIGCSE-ANNOUNCE
is primarily for messages from the SIGCSE Board or the chairs of
SIGCSE-affiliated conferences.  Most people understand that.  I end up
rejecting a bit of spam (with no followup message) and some message from
normal members who don't understand the structure (with a followup
message) [10].

*Subscription requests*.  As a list moderator, I am also responsible for
subscriptions to both the SIGCSE-MEMBERS and the SIGCSE-ANNOUNCE mailing
lists.  At present, there are two ways that people request subscriptions.
Some email us directly at `infodir@sigcse.org`.  Others click a link
somewhere that automatically generates an email address for us.  The 
process is much the same for both cases: I check whether they are current
members and either subscribe them or send a message of the form "These
mailing lists are only for members of SIGCSE.  You are not a member.
Please consider joining."

Unfortunately, checking membership is not always a trivial operation.
I keep a local copy of a relatively recent membership list on my computer,
so my first approach is to grep [11] that list.  Next, I check the
ACM Database.  Unfortunately, the ACM's database is clunky.  I need to
log in twice.  If I know the person's ACM ID [12], the search is fast.
If I have to search by last name, it's slow.  It's been better these
past few months, but I recall searches taking as much as a minute.

Fortunately, adding someone to the list is comparatively painless.  If
it's one of those automatically generated subscription messages, I can
just click a link.  Otherwise, I log in to the Listserv interface [14],
navigate to the subscribers page, and enter their subscription information.
Fortunately, it's a sensible UI, I can use one of two formats, both of
which are easy to pull off a mail message: "user@university.edu First Last"
or the more traditional "First Last <user@university.edu>".  In contrast,
the Lyris list I manage at work requires that I enter name and email address
separately, which is less convenient [15].

*Bounce messages*.

*Everything else*.

---

[1] Officially, my title is "Information Director" or "Co-Information
Director" or perhaps "Information Co-Director".  The Information Directors
primary responsibility is to manage the SIGCSE mailing lists.  We also
do a few other things, such as suggest and implement policy.

[2] SIGCSE is the Association for Computing Machinery (ACM) special 
interest group for Computer Science Education.

[3] Searching for "educa" handles "educate" and "education".

[4] I don't think there's been an ACM Federated Conference while I've
been a moderator, but I'd approve that.  I'm not sure that my predecessors
would have.

[5] Many mail readers hide the quoted material, so not all of our readers
know when they are quoting a lot of material.  But our typical digest
readers don't have the same experience; they have to wade through too
much repeated material.  We'd like to make their experience better.

[6] I'm surprised at the number that seem to be a reply-all.  Some clearly
address a broader audience than the original sender but many do not.

[7] No one told me that when I started; it took me about six months to
figure it out.

[8] E.g., name@university.edu rather than name@cs.university.edu or
vice versa.

[9] Didn't I just say that there are three primary actions?  Now I seem
to have listed five.  But that's okay, I've split "reject" into two parts
and I've added the rare, but still important, "check with SIGCSE chair".

[10] At one time, I was one of those members who did not understand the
structure.  I think that's how I ended up in this position.

[11] search

[12] Only in the cases in which they've privded it via their email message.

[14] In most cases, I'm already logged in.  I spend too much time on
the Listserv.

[15] It doesn't really matter when you are adding one or two folks.  But the
additional time and effort builds up as you add more and more.

---

*Version 0.7 of 2018-10-09.*
