Slow Internet connections
=========================

*Topics/tags: [Rants](index-rants), short, rambly*

This past week, I've been on vacation with my wonderful wife.  In
spite of [my workaholic tendencies](workaholic-2018-02-10), I went
on a cruise with her.  Perhaps I'll write about my experience with
the cruise in a separate musing.  For today, I'm writing about my
experience with Internet on the cruise.

We purchased an "Internet Value Package", which is supposed to give
you access to your email, news, Web sites, and such; just no
streaming.  It appears that Carnival interprets access differently
than I do.  While the list of messages would eventually appear on
my phone, when I clicked on any individual message, it would take
over a minute to load [1].  And, while I could ssh in to the MathLAN,
I could not work in real time.  I'd type a command, wait some time
for it to appear, read the results, and type the next command.
Fortunately, I type fast.  And, when necessary, I can edit in `vi`
without seeing the results [2].  But it's not fun.

But, well, it made it hard to work.  And it made it hard to muse.
After the first night, I started writing on my laptop and using
`git` to transfer files.  But my ssh certificate did not work well
with whatever crap Carnival does with Internet connections, so it
took a bit of finagling to get stuff downloaded and uploaded.

I managed two more days of posting my musings.  Then I decided that it
wasn't worth the extra twenty or thirty minutes it took to get through
things, particularly the "joy" of trying to work without `spell` and
using [Grammarly](https://www.grammarly.com/) over an incredibly slow 
Internet connection.

Detour: _Sam, how slow is it?_  Well, while writing this, I was
trying to connect to <https://passwordreset.grinnell.edu> in my Web
broswer because I was having trouble with getting email [3].  This
time, I did time things.  After five minutes, the page still had
not loaded [4].  I don't consider that a useful connection.

To make it worse, some services treat you worse when you have a slow
Internet connection.  I was logging in to Amazon to download a Kindle
book.  It appears that I typed in the password before the page had
fully loaded.  So Amazon shot back with "For your security, we want
you to type both your password and the letters that appear in the
image below."  But, well, if I have a slow Internet connection, adding
steps to the page load means I'm even less likely to be able to log in.

In any case, the pain of trying to muse without my normal tools and 
the increased pain of trying to post my musings meant that by Wednesday,
I decided it wasn't worth my time.  While I did think about topics over
the next few days, I didn't spend any time writing.  I thought about
posting an "On vacation" musing.  It went something like the following.

> I'm on vacation.  I deserve a day off from musing.

However, I don't want to fall behind on musing.  So I'm spending some
of the last day of the cruise writing while looking out over the ocean.
It's a "day at sea", so we're stuck on the ship.  Musing beats gambling,
eating, going to silly presentations, and ship shopping.  Musing doesn't
beat drinking, but I'm not in a drinking mood right now.

I did have to get some real work done this week.  I think I spent
an hour on the code camps, an hour or more dealing with GHC and
Tapia tasks, and an hour dealing with miscellaneous department-related
email.  GHC and Tapia would probably have taken thirty minutes with
a real Internet connection.  The other two hours would probably
have taken twenty minutes.

Is there a moral to all this?  Here are mine.

* Don't trust cruise Internet connections.
* If you must use a cruise Internet connection, buy the most expensive.
  I didn't pay for the "streaming" service since I didn't plan on streaming.
  But 
---

[1] I didn't time.  It was just clear that it was a long time.

[2] Years of working as a sysadmin on an old Unix box has some benefits.
I learned to line edit, and slow `vi` is a lot like a line editor.

[3] That is, I kept getting "please reenter your password" messages, which
is generally a sign that my account has been accidentally locked by Grinnell's
security policies and needs to be unlocked.

[4] Admittedly, I was also trying to open the Amazon home page at the
same time.

---

*Version 1.0 of 2018-06-16.*
