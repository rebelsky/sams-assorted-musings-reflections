Microsoft nagging
=================

*Topics/tags: [Rants](index-rants), technology, short*

I run Microsoft Office 2019 for Mac [1,3] on my Macbook.  Because it's
a Microsoft product [4], it needs regular updates.  But I'm one of those
people who like to update things themselves, rather than have the 
software update without my knowledge.  So I have Automatic Updates
turned off.   Unfortunately, that doesn't stop Microsoft Update from
asking me about once a day whether I want to turn automatic update on.
The options are "Yes" and "Not Now".  Where's the "No.  Stop asking!"
option?

As you might expect, I find that regular frustrating.  Nonetheless,
for the past few months, I've been just closing the stupid alert rather
than figuring out a more general solution.

The other morning I got fed up.  And so I did a Web search to find a possible
answer [5].

Conveniently, [one of the first pages I found](https://answers.microsoft.com/en-us/msoffice/forum/all/how-to-stop-office-nagging-about-automatic-updates/5db1680b-25de-45c7-92fa-9d6949a3059b) asked nearly the same question.

> I have Office Home and Student installed on my Mac. Recently it's started nagging me with a "Turn On Automatic Updates?" prompt: "Always install new features and updates for Microsoft apps". The only two options given are "Not Now" and "Turn On". If I click "Not Now", it keeps coming back.

> I don't want automatic updates. How do I tell it "no, and stop asking"? I'm happy to be notified when updates are available, but I don't want to automate acceptance.

As is typical, many of the answers were unhelpful, at best.  They included
links to pages on how to turn on automatic updates and suggestions to
re-download the Microsoft AutoUpdate application.

But there was one bit of advice that worked (which is noted as the best
answer on the page).  Under the Notifications entry in System Preferences,
you turn off alerts from the Microsoft AU Daemon.  Supposedly, that turns
off the "Turn on Automatic Updates?" alert but leaves the "it's time to
update your Microsoft products" alert.

We'll see how it goes.

---

Followup: The same day I made the change, I got a message from the
update daemon that I needed to update my Microsoft products.  That was
not a good sign.  But I've gone too more days since then without a 
message, which I'll take as a better sign.

---

Postscript: Whenever I write about Microsoft, I'm tempted to say something
about defenestration.  However, this musing is more about Office than
Windows.  I need to expand my range of Dad jokes.

---

[1] Or whatever they call it these days.  My particular version seems
to be "Microsoft Office Home & Business 2019".  It doesn't seem to
specify an OS, even though I run it on macOS [2].

[2] Perhaps my license permits both?

[3] While I generally prefer Free, Libre, and Open-Source software, I
accept that I may need to use proprietary software for interoperability
or convenience.

[4] Or perhaps just because it's software.

[5] I wonder what I would have done in the pre-Interweb days [6].

[6] I do recall an adventure with Microsoft Word for Mac circa 1988 in
which I had found that tabs with leading dots were not working correctly.
If you were too close to the tab stop, they appeared to the right,
rather than to the left.  And so I called Microsoft Support.  I think
their conclusion was "It was in the previous version, so it's a feature,
not a bug."  I can't reproduce it in Word 2019.
