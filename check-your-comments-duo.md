Check your comments
===================

*Topics/tags: [Rants](index-rants), technical, short*

Grinnell appears to be be moving to a two-factor authentication system
for access from off campus.  That's reasonable; multi-factor authentication
is becoming more and more standard [1].  It appears that we will be using
[Duo](https://duo.com/) to support multi-factor authentication.

While I was looking around to learn more about Duo, I decided to watch
[a video about installing on Linux systems](https://duo.com/docs/duounix).
At about 3:50 into that video, they have the following section.

> Voice: Add autopush equals yes to enable this parameter setting.

> Screen: `autopush = yes`

> Voice: We recommend commenting out a line before this parameter to
indicate what it does.

> Screen: `; enables autopush`

It's comments like that that make people say "_comments are pointless_".
That is, the comment adds absolutely nothing to the code.  And if it
adds nothing, you should not write it.

What would be better?  Well, if you assume that the reader knows what
"autopush" means, no comment is necessary.  Otherwise, I'd suggest
something like "Automatically send a request to the user's phone",
which is what the setting does.  Of course, I often stray in the
opposite direction.  For example, here's what I might ahve written.

    ; Uncomment one of the two autopush settings below.
    ; Option 1: Automatically send a push request to the user's phone
    autopush = yes
    ; Option 2: Prompt the user for an authentication method (default)
    ; autopush = no

Comments can be helpful.  But only if the explain, rather than repeat,
the underlying code.  I wish more people would write thorough, clear,
and useful documentation, particularly in demonstration videos.

---

[1] One of my colleagues did ask what we're going to do for people who
do not have cell phones.  I've passed the question on to ITS [2].

[2] I was told "They can have it call any phone", or something like that.
I'll believe it when I see it [3].

[3] Or is that "I'll believe it when I hear it."

---

*Version 0.9 of 2018-11-01.*
