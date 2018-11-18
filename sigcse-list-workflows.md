SIGCSE mailing-list workflows
=============================

*Topics/tags: [Overcommitment](index-overcommitment), SIGCSE, email, long, rambly*

One of my professional responsibilities is co-moderator [1] of the
SIGCSE [2] mailing lists.  As a moderator, I have only a few primary
responsibilities: I approve or reject posts, I handle new member requests,
and I read and address bounce messages.  But it's not quite as simple
as it sounds.  Let's consider the various workflows I follow.  I assume
my co-moderator follows similar workflows.

*Posts.*  To handle an incoming post, I skim through it and see
whether or not it seems to meet our policies.  What are those policies?
First, it should be relevant to the list.  The SIGCSE-members mailing
list is for discussion of computer science education.  Most members
realize that.  But we get the occasional strange conference announcement.
For those, I look for the keywords "teach", "learn", and "educa..." [3].
A conference announcement with none of those keywords is unlikely to
be relevant to our membership [4].  There are a few exceptions for
conferences that focus on students, but not many.

Next, I check for the secondary policies.  Does it rely on an attachment?
If so, it is not appropriate for our mailing list [5].  Does it quote an
inordinate amount of material?  If so, it makes the reading experience
much less good for our subscribers who read in digest form [6].

There are also a few other cases, such as posts that seem irrelevant or
intended only for the original poster [7].  

I am then left with three primary options.  I can approve the post, reject
the post, or ask the author to repost.  The first option is the easiest.
I click a link in the email message I received, the system processes
the approval, and the posting goes off to the list.  The second option
is a bit harder.  I need to log in to the moderation site, find the
post, and click the "reject" button.  The third option is the most time
consuming.  In that case, I also write a polite message to the poster.
For those who seem to have violated the policies, I explain those
policies and ask them to repost.  For those who may have inadvertently
carbon-copied the mailing list, I check to see if that was their intent.
In the few other cases, I do whatever seems most appropriate.

It is rare that I simply reject postings; I generally think our posters
deserve the courtesy of an email message.  But some messages are
relatively easy to reject without additional followup.  As I noted, I
typically reject conference announcements that are irrelevant to SIGCSE.
But there are a few that *might* be relevant; in those cases, I try to
send followup.  One-line messages that are intended for another poster
and not for the list rarely warrant a followup.  And, of course, spam
just gets deleted.

Unfortunately, not all requests to approve messages on the listserv come
to me through email.  The listserv only forwards messages for approval
if they come from current members who submit using their corresponding
email address.  However, if someone posts from an address not on
the mailing list, the only way to know that is by logging in to the
administrative interface [8].  About half the mail that comes in that
way is from subscribers.  The rest is a mixture of spam, messages from
members who are using a different mailing address [9].  The interface
is a bit different, but I handle these in the same way: I approve,
reject outright, reject with followup message, request clarification,
or check with the SIGCSE Chair [10].

Of course, those processes are only for the SIGCSE-MEMBERS mailing list.
I also moderate the SIGCSE-ANNOUNCE mailing list.  SIGCSE-ANNOUNCE
is primarily for messages from the SIGCSE Board or the chairs of
SIGCSE-affiliated conferences.  Most people understand that.  I end up
rejecting a bit of spam (with no followup message) and some message from
normal members who don't understand the structure (with a followup
message) [11].

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
so my first approach is to grep [12] that list.  Next, I check the
ACM Database.  Unfortunately, the ACM's database is clunky.  I need to
log in twice.  If I know the person's ACM ID [14], the search is fast.
If I have to search by last name, it's slow.  It's been better these
past few months, but I recall searches taking as much as a minute.

Fortunately, adding someone to the list is comparatively painless.
If it's one of those automatically generated subscription messages, I
can just click a link.  Otherwise, I log in to the Listserv interface
[15], navigate to the subscribers page, and enter their subscription
information.  Fortunately, it's a sensible UI: I can use one of
two formats, both of which are easy to pull off a mail message:
"user@university.edu First Last" or the more traditional "First Last
\<user@university.edu\>".  In contrast, the Lyris list I manage at work
requires that I enter name and email address separately, which is less
convenient [16].

*Bounce messages*.  Once in a while, we get bounce messages.  It's then
our responsibility to read through those messages and try to determine
appropriate responses.  In some cases, the mail handler has decided that 
a message is spam and is informing us of that decision.  That happens most
frequently with job advertisements.  There's also at least one system that
refuses to accept messages with shortened URLs.  Those cases are easy;
we just ignore the bounce [17].  

Some cases are more complicated.  If a message says something like
"This address is no longer active", I end up doing a bit of homework.
First, I make sure the person is still a member of SIGCSE [18].  Next,
I try to track down where they might be.  If I'm lucky, they've updated
their email address with ACM, even if they haven't done so with SIGCSE.
Those situations are rare.  More often, I do a Web search and I look on
LinkedIn.  On occasion, I'll write to someone at the department asking
for a new address.  Then I either update the address or write to the
person at the new address asking whether I should update.  It's a bit
of work, but I think it's the friendly thing to do.

*Questions and special requests*.  As you might expect, we get a variety
of questions and special requests.  "Did my post appear?"  "I've changed
jobs; can you update my email address?"  "I'm overwhelmed by email; please
switch me to digest mode."  Most of those requests are easy to handle and
the listserv UI suffices.  Once in a while, we need to do something that
doesn't quite fit within the UI.  For example, some posters would prefer
both an acknowledgement of their post and a copy.  The UI assumes that
you want only one (or neither).  Hence, for people with those special
requests [19], we get to figure out the instructions for command mode.
Here's one to achieve that last goal.

    SET SIGCSE-MEMBERS ACK REPRO FOR rebelsky@grinnell.edu

*Everything else*.  A variety of other tasks come up from time to time.
For example, when I started, I needed to clean out the mailing list to
eliminate people whose subscriptions had lapsed.  I still do that once in
a while.  I've made some policy suggestions to the Board and spent some
time discussing them via email.  I've also participated in some policy
discussions that stem from Board suggestions.  For example, the Board
suggested moving SIGCSE-ANNOUNCE from opt-in to opt-out.  I thought we'd
accomplished that last year, but it turns out that a miscommunication
with ACM Headquarters left the change in limbo.  It's now gone through,
but that's raised new complications, such as members who want to get
SIGCSE-ANNOUNCE with a different email address than their ACM membership
[20].  In most of these situations, I end up composing and sending a variety of
messages, not just as part of the discussion, but also messages to the
various listservs.

And there you have it, my life as SIGCSE Information Director, or at least
as SIGCSE listserv moderator.  It's not particularly thrilling, but it seems
to support our community well.

---

Postscript: Here are some of the templates I use.

*Request a repost*

> Dear,

> Thank you for your submission to the SIGCSE-members mailing list.  Unfortunately, I cannot accept it in this present form.  Our digest subscribers continue to ask the information directors to try to limit the amount of quoted material from previous messages in postings to SIGCSE members. It does not appear that your posting (appended) needs as much quoted material as you used.

> Please resubmit with only the essential information quoted.

> Thanks!

> \-\- SamR

> Samuel A. Rebelsky  
SIGCSE Information Co-Director  
Professor of Computer Science, Grinnell College  
rebelsky@grinnell.edu  
infodir@sigcse.org

I usually add something about the topic of the submission.  I may also
add a suggestion on cutting.

*After subscribing someone*

> I have subscribed you to the SIGCSE-Members mailing list.  Welcome to the list.  You should receive a confirmation notice from the LISTSERV.

> Be sure to check out the policy statement \[1\] and the list archives \[2,3\].

> Regards,

> \-\- SamR

> \[1\] http://sigcse.org/sigcse/membership/mailing-lists

> \[2\] https://listserv.acm.org/SCRIPTS/WA-ACMLPX.CGI?A0=SIGCSE-MEMBERS

> \[3\] https://listserv.acm.org/SCRIPTS/WA-ACMLPX.CGI?A0=SIGCSE-ANNOUNCE

> Samuel A. Rebelsky  
SIGCSE Information Co-Director  
Professor of Computer Science, Grinnell College  
rebelsky@grinnell.edu  
infodir@sigcse.org

*A response to a subscription request from a non-member*

> Thank you for your interest in the SIGCSE-members mailing list. I am sorry, but I cannot find a record of your SIGCSE membership. As our list policy \[1\] states, subscriptions to the SIGCSE-members and SIGCSE-announce lists are restricted to SIGCSE members. Although ACM manages SIGCSE memberships, SIGCSE memberships are separate from ACM memberships; you can be an ACM member but not a SIGCSE member (or vice versa).  Could you check your ACM membership page to verify that you are a SIGCSE member? 

> If you are not a member but would like to become one, please see the SIGCSE membership page \[2\]. I would encourage you to consider SIGCSE membership. It's relatively inexpensive ($25/year for electronic-only access and $40/year with printed materials; $12 for student members), and the SIGCSE mailing lists can be quite useful.

> Regards,

> \-\- SamR

> \[1\] http://www.sigcse.org/sigcse/membership/mailing-lists

> \[2\] http://www.sigcse.org/sigcse/membership

> Samuel A. Rebelsky  
SIGCSE Information Co-Director  
Professor of Computer Science, Grinnell College  
rebelsky@grinnell.edu  
infodir@sigcse.org

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

[5] The SIGCSE board has approved some specific exemptions to that rule,
such as the SIGCSE history

[6] Many mail readers hide the quoted material, so not all of our readers
know when they are quoting a lot of material.  But our typical digest
readers don't have the same experience; they have to wade through too
much repeated material.  We'd like to make their experience better.

[7] I'm surprised at the number that seem to be a reply-all.  Some clearly
address a broader audience than the original sender, but many do not.

[8] No one told me that when I started; it took me about six months to
figure it out.

[9] E.g., name@university.edu rather than name@cs.university.edu or
vice versa.

[10] Didn't I just say that there are three primary actions?  Now I seem
to have listed five.  But that's okay, I've split "reject" into two parts,
and I've added the rare, but still important, "check with SIGCSE chair".

[11] At one time, I was one of those members who did not understand the
structure.  I think that's how I ended up in this position.

[12] search

[14] Only in the cases in which they've provided it via their email message.

[15] In most cases, I'm already logged in.  I spend too much time on
the Listserv.

[16] It doesn't really matter when you are adding one or two folks.  But the
additional time and effort builds up as you add more and more.

[17] Well, *I* ignore the bounce.  I believe some past holders of this
position didn't like us being identified as spam and sent followup messages.

[18] When I started, we had not cleaned out the lists for some time.  We're
better now, but don't always get to it.

[19] Yes, I'm one of those people who wants both a copy of my messages and
an acknowledgement.

[20] Nope, not possible, at least at present.

---

*Version 1.0 of 2018-11-17.*
