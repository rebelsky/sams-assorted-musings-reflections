Aggressive spam filters
=======================

*Topics/tags: [Miscellaneous](index-misc), email, short*

As one of the SIGCSE Information Directors [1], I get to see a lot of
bounce messages.  Sometimes messages bounce for strange reasons ("too
many hops"), sometimes someone has left the institution or changed
their email address ("there is no one with that email address here"),
sometimes it's a generic "this message has been tagged as spam", and
sometimes there's a very specific spam message.

Here's one spam response I recently received.

> 550-5.7.1 \*\*Your email has been rejected as it contains a shortened URL (e.g.
550 5.7.1 bit.ly).   Please remove the shortened URL(s) and resend .

I have no intention of resending; I didn't send the original and it's not
worth my time to deal with each recipient's institution's view of how to
filter spam.

But I'm also interested in the reason to filter.  From my perspective,
shortened URLs are part and parcel of how people do business on the
Interweb.  I realize that a shortened URL can lead to a phishing site
or one that might download malware.  However, almost any link you click
on the Interweb can lead to such a site.  I guess filtering such messages
makes the recipients slightly safer, but it doesn't seem to be all that
much safer.

It's also an interesting contrast to the wonders [2] of Proofpoint.  As you 
may recall, the Proofpoint software that Grinnell employs rewrites every
URL in a message so that when you click on it, it first goes to a site
that checks whether you are going to a "safe" destination.  After all,
you never know whether or not some evildoer has hijacked google.com.
But that's not the contrast I find interesting.  Rather, the designers
of Proofpoint appear to assume that no one ever reads URLs.  Certainly,
the mangled URLs that Proofpoint produces are unreadable.  Here's one of 
them.

> https://urldefense.proofpoint.com/v2/url?u=http-3A\_\_sigcse.org\_sigcse\_membership\_mailing-2Dlists&d=DwIFAg&c=HUrdOLg\_tCr0UMeDjWLBOM9lLDRpsndbROGxEKQRFzk&r=6rcUljFJZnpk5uomPd3v3WCzboqh0RuwO-BZyxMfi0U&m=zWEyj5tMrmg8UTSR\_MzfKCC2TS7qxvkVllVQsvzt3SE&s=Yr5JuWmqe5F55i2VF3TELzPQ7ipV6POiM3SuDGCBMZQ&e=

Is that safe to click?  Where does it lead?  The assumption is that I should
just trust Proofpoint to filter appropriately and that I don't care where
it leads.  But, well, Proofpoint doesn't always filter well.  For example,
much of campus received a phishing message this morning.  I clicked on the
URL this evening and Proofpoint still allows me to reach the phishing site.

I'd like to say that education is the solution to both problems.  That is,
if people were taught well and understood, then shortened URLs would
be permissible and URL rewriting would be unnecessary.  Unfortunately,
I know from talking to our ITS staff that there is a sufficiently large
population of people who aren't paying enough attention.  Every experimental
phishing expedition on campus [3] has revealed at least a few passwords.
And once an attacker has one account on campus, they can often get access
to more things.

Nonetheless, I find a policy that rejects shortened URLs excessive.

---

[1] That is, the people responsible for managing the mailing lists for
the ACM Special Interest Group on Computer Science Education.

[2] When I write "wonders", I actually mean "horrors".

[3] For example, when we hire someone to test our security.

---

*Version 1.0 of 2018-06-21.*
