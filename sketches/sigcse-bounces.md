Handling bounced messages
=========================

*Topics/tags: [Email](index-email), [overcommitment](index-overcommitment)*

As one of the SIGCSE mailing list moderators, one of my [many
tasks](sigcse-list-workflows) is to read and consider how to respond
to bounced email messages.  This musing is intended to summarize the
different kinds of bounces I get and how I handle them.

```
This message was created automatically by the mail system (ecelerity).

A message that you sent could not be delivered to one or more of its
recipients. This is a permanent error. The following address(es) failed:

username@college.edu (reading confirmation): 553 Blocked Using Spam Pattern, Your Message May Contain The Spam Contents
```

This response is fairly clear.  The institution's spam filter thinks that
the message is spam.  Interestingly, the 1000+ other members did not have
it marked as spam.  I delete the bounce message and move on.

```
This message was created automatically by the mail system (ecelerity).

A message that you sent could not be delivered to one or more of its
recipients. This is a permanent error. The following address(es) failed:

username@college.edu (after RCPT TO): 550 Sender IP (209.119.5.133) is blacklisted at db.wpbl.info
```

I'm not sure why our listserv ends up on blacklists.  But it does once
in a while.  If the problem persists, I tend to contact one of the technical
support staff at ACM Headquarters.

```
username@college.edu (after RCPT TO): 541 5.4.1 Mail rejected by destination domain
```

Since there's not a lot of other information, I just delete the bounce
message.  If we get enough of those kinds of messages for a particular
user, I sometimes contact that user to let them know what's happening.

```
username@college.edu (after RCPT TO): 550-5.2.1 The email account that you tried to reach is disabled. Learn more at
550 5.2.1  https://support.google.com/mail/?p=DisabledUser l82si2329986qki.89 - gsmtp
```

That's almost certainly a permanent failure.  A first step is to learn
more about the user, which I do by searching on campus.acm.org (or,
more frequently, in my local copy of the database).  In this case, no
other followup seemed necessary.  I delete them on listserv.acm.org and
by using the unsubscribe tool (to prevent them from being re-added).

```
username@college.edu (reading confirmation): 550 5.7.0 DT:SPM .For more information, please visit [url elided]
```

Another one that identifies us as spam.  Ignore.

