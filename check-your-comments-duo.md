Check your comments
===================

*Topics/tags: [Rants](index-rants), technical, short*

Grinnell appears to be moving toward a two-factor authentication
system for accessing our systems from off campus.  That's reasonable;
multi-factor authentication is becoming more and more standard [1].
From what I can tell, we will be using [Duo](https://duo.com/) to support
multi-factor authentication.  But multi-factor authentication is not
the subject of this musing [4].

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
opposite direction.  For example, here's what I might have written.

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

[2] I was told that they've made plans.  It's good to see ITS thinking
ahead.

[3] I wonder how common it is that the subject of the first paragraph
is not the subject of the musing.  That feels like one of my common
rhetorical strategies.  That is, I provide some context to introduce
what I'm writing, but I do not intend that context to be the subject.
I'll need to reflect more on that approach.  It seems natural as a writer,
but I'm not sure how natural it feels as a reader.

---

*Version 1.0 of 2018-11-02.*
