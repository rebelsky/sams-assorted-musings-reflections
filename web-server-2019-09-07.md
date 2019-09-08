The CS Web server
=================

*Topics/tags: [Miscellaneous](index-misc)*

Last night at a little after eight p.m., I sat down to watch
Grinnell's volleyball team take on Cornell College [1,2].  Since
they were doing warmups, I decided to finish and post the musing I
had drafted earlier in the day [3].  But first, I checked my
electronic mail.  At the top of the list was a message from our
SysAdmin indicating that,

> Due to suspicious activity on [the Web server], we have  taken
the precaution of temporarily isolating that server from the network.

Since our Web server is at the center of my electronic universe, I
found that message a bit concerning.  Fortunately, I'm not teaching
classes this semester, so I wasn't worried about my course webs at
the moment.  However, I had just posted our job advertisement to
the SIGCSE-Jobs listserv [4], so my first response was "Information
on the job is posted on the server".  I will admit that I was also
a bit sad that "SamR's Assorted Musings and Rants" would not be
available, but I accept that my 'blog is much important than our
course webs.  My colleagues quickly noted that their courses are all 
on our server.  By the end of the evening, our SysAdmin had managed
to get our home directories posted on another server, one at
<http://132.161.196.205/> [6].  It's supposed to be available at
<http://www-temp.cs.grinnell.edu/>, but the DNS system does not
seem to have propagated that alias yet.  I'm not sure why we didn't
just associate `www.cs.grinnell.edu` with `132.161.196.205`, but
I assume the folks [7] at ITS are busy trying to figure things out.

Do I blame ITS for taking our Web server down so abruptly?  Nope.
Given [what happened at Regis this fall](https://www.regisupdates.com/),
I expect that they take all potential attacks very seriously.

Whose fault is it that our server was vulnerable?  That's a more
complicated question.  I'd say that there's blame to go around.
We've been talking about changes for over four years; two sets of
student SysAdmins had trouble making the updates that we wanted
and, since ITS took over system administration two or so years ago,
they seem not to have had time to make updates.  But we've been
discussing it, and it looked like we would be making changes at the
end of this year [8].

This experience has reminded me that I rely way too much on our
Web server.  I posted to Facebook that "I think I need a life".
However, I think the real moral is "I need to run my own Web server."

---

[1] No, not Cornell University.  And not Grinnell College, either.

[2] Grinnell one three sets to none.  Congrats Pioneers!

[3] At times, I muse at night.  At times, I draft the musings during
the day and then post them at night.

[4] SIGCSE-Jobs is new.  I consider its creation one of my positive
accomplishments as SIGCSE information co-director [5].

[5] I have no idea why they decided to call us "information directors".
It makes it hard to add the "co-" because there are two of us.

[6] You won't find anything at that exact URL, but you can append
`/~rebelsky/` to see my subsite.

[7] Or perhaps just one person.

[8] I have a feeling that our timetable will be accelerated.

---

*Version 1.0 of 2019-09-07.*
