Sentient and malicious
======================

*Topics/tags: [Miscellaneous](index-misc), short*

As I've noted previously, I try to teach my students many different
things, some technical, some general, some moral.  Along the way,
I introduce a variety of aphorisms (e.g., "Trust the magic recursion
fairy" and "There's more to life than computer science").  One of
the more important aphorisms I give is "Computers are sentient and
malicious" [1].  I do add some additional background to that statement.
It goes something like this.

> Computers reveal that they are sentient and malicious through a common
behavior.  You will try to do something.  It won't work.  You will try
again.  It still won't work.  So you'll ask me or one of the class mentors
for help.  And we'll suggest the same thing you just tried.  You'll say,
"I tried that".  But we'll ask you to try again.  And, lo and behold, the
action that failed two (or more) times before will work.

> This behavior reveals some important things about computers.  First, 
they know what you're doing.  Second, they want to frustrate you.  Third,
they know that you'll be embarrassed when things suddenly work once 
someone in authority is standing behind you.  As I said, computers are
sentient and malicious.

I don't really believe that computers are sentient.  But I must
accept that I see this behavior again and again and again.  A student
asks a question.  I say "Try this".  They say "I tried that".  I
say "try it anyway".  And, magically, things work.  Of course, there
are also times that they are off by one character [2] or I ask them
to do someething slightly different than what they've tried in the
past.  But I'm pretty sure there are times that things just seem
to work because I'm there.  And, in the end, blaming the computer
makes things feel a bit less stressful [3].

I had a similar experience this week.  On Monday, I was so involved
in code camp that I managed to allow my MacBook's battery to drain
to 0%.  When I plugged it back in, the light wouldn't even come on
on the charger.  I spent some time searching for the problem on the
Web, but got no good answers.  A day later, I managed to get the
amber light to turn on, which means that it's charging.  But the
computer still would not turn on.  I tried reseting the SMC.  It
wouldn't turn on.  So I left it overnight.  No luck.  A day later,
I unplugged it and pluggeed it back in.  The light turned green.
That's supposed to mean that it's fully charged.  But the computer
still wouldn't turn on.

So I did the next reasonable thing.  I made an appointment at the Apple
Store.  I figured they would tell me that something needed to be replaced.
I made some mental estimates on what would lead me to repair rather than
replace the machine.

Today I got to the Apple store.  While waiting for the friendly
genius bar representative [5], I plugged in the Mac and tried to
turn it on.  Lo and behold, it turned on.  The battery showed 0%
charge.  The system information showed sixteen hours to full.  But
it turned on.  We'd spent the hour driving to the Apple store, so
I thought I'd go through with my appointment.  I described the
situation.  We talked about the 0% charge and what appeared to be
a long charging time.  And he suggested that we run system diagnostics.
He expected something to come up for the power supply or the battery.
But the diagnoistics on those were fine.  There was a suggestion
that we run a more detailed video check.  That worried me a bit,
since my last problem with the Mac had been [a non-working
screen](checking-my-mac-2018-03-21).  So we waited fifteen minutes
for the video test to progress.  My Mac passed with flying colors.

So, why wouldn't my Mac start the other times?  I have no idea.
Even the tech seemed somewhat frustrated, "I'd really like to give
you a reason."  But I'll stick with my aphorism, _Computers are
sentient and malicious._

---

[1] Rumour has it that some CS faculty are also sentient and malicious.

[2] For example, our login screen makes it particularly hard to tell
if you type a space before your username.  If you type a space before
your username, it won't recognize your account.

[3] I also tell them to remember how much they laughed when things went
wrong while they were writing "nut butter and jam sandwich" algorithms.
That's right, you should laugh, rather than get frustrated, when
your program screws up [4].

[4] That statement assumes that you are not writing software that affects
people.

[5] My experience with the Jordan Creek Apple star is that the genius
bar folks are generally pretty friendly.  I did overhear one being a
little snarky to someone who had dumped their phone in water and said
"But it's supposed to be water proof!".  But they've always been helpful
to me.  I'm writing this while sitting at the Apple Store and the rep
who is next to me is being very helpful to the customer, being clear,
patient, and sympathethic.

---

*Version 0.9 of 2018-06-24.*
