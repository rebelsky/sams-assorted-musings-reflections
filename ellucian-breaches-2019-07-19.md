The latest Ellucian breach
==========================

*Topics/tags: [Academia](index-academia), technology*

I began today, as I begin most weekdays, by skimming the news in
academia.  I was intrigued to find that both [_Chronicle_](https://www.chronicle.com/article/At-Least-62-Colleges-Were/246730) [1] and [_Inside Higher Ed_](https://www.insidehighered.com/news/2019/07/19/ellucian-banner-security-flaw-highlighted-education-department) [2] had articles about a data breach related to Ellucian products.

Reading the article, I breathed a little easier seeing that it was a breach
related to Banner rather than to Colleague [3].  Still, it's frustrating
to see that a programming issue puts so much student data at risk.  I wonder
whether FERPA requires that each institution that was subject to the Banner
flaw notify each student at that institution that the data were at risk.

I also wonder how much it has to do with what the strange programming
practices that I associate with Ellucian.  What do I mean when I say
"strange programming practices"?  It's a host of different things,
which include:

* Web pages that ask for input data but only have one option [4], 
* pages with multiple drop-down menus that let you select from only one of 
  those drop-down menus but require you to scroll to the bottom to get 
  the associated action to run [5], 
* such reliance on state in their Web systems that one can't open a 
  link in a new window or use a back button, and
* a failure to cache complex-to-compute information, which leads to a
  fifteen-or-so second wait each time you load certain pages [6].

They're getting better.  For example, each student page on SelfService
has a static and predictable URL; those fixed URLs allow me to bypass the
"List my advisees" front end and jump directly to advisee pages that
I have bookmarked.  But they still have a long way to go.  A recent
"feature" to send email to all of your advisees doesn't work because they
can't read Web standards.

In any case, it appears that someone found a way to
hack the system by taking advantage of unexpected race
conditions.  My quick read of [the description of the
exploit](https://github.com/JoshuaMulliken/CVE-2019-8978) suggests that
there are two issues at play: First, they use university id numbers
as identifiers.  Second, it appears that the system does not tie
"authorization" to a particular connection.  (It can be hard to do that
on the Web; an IP address does not suffice.)  As I understand it, if
you keep trying to connect using someone else's university id number,
you may find that when they try to log in, you get the connection that
is intended for them.

I understand that Web state is hard.  I understand that distributed
processing is hard and that race conditions happen.  But what I don't
understand is the timeline, which I'm reproducing from the report
of the student worker at the University of South Carolina [7,8]

```
December 18, 2018: Attempted reporting through Ellucian's marketing web-form and sent to informationsecurityassessmentteam@ellucian.com
December 20, 2018: Submitted report to CERT Coordination Center at Carnegie Mellon University
January 2, 2019: Submitted report to a CISO at Ellucian who was discovered through LinkedIn
January 2, 2019: Requested information on responsible disclosure procedure from the University of South Carolina
January 3, 2019: Was told to report through ActionLine by Ellucian 
January 4, 2019: Was told by the University of South Carolina that there is no procedure for reporting vulnerabilities
January 4, 2019: Told the University of South Carolina that I had discovered a vulnerability in Banner
February 18, 2019: CERT informed me of failure to reach the vendor and advised me to publicly disclose
February 25, 2019: Sent draft of advisory to Ellucian and set the date of disclosure to March 4th.
February 28, 2019: Ran demo of vulnerability for Ellucian over Zoom conference
March 1, 2019: Was asked by the University of South Carolina to delay publication
March 21, 2019: The University of South Carolina received a backported patch from Ellucian
March 26, 2019: Ellucian finalized patches for all versions
March 29, 2019: Was told by Ellucian that the University of South Carolina would be doing changes on the 1st of April
April 1, 2019: Requested information on patch status from the University of South Carolina
April 5, 2019: The University of South Carolina gave ETA of April 30, 2019
April 30, 2019: The University of South Carolina updated ETA to the middle of May
May 7, 2019: Set publication date of disclosure to May 13
May 10, 2019: The University of South Carolina posted a planned outage notice for all Banner Services scheduled for May 11
May 11, 2019: The University of South Carolina successfully installed the patch
May 13, 2019: Disclosure published
```

It appears that this student found a bug, reported it in multiple ways,
and Ellucian still did not contact the student until the student indicated
that he would release a public report [9].  Two months to respond to a
serious security flaw is way too long, especially CMU's CERT team was
involved, contacted the company, and got no response.
It looks like it took a month to develop a patch, which is reasonable.
Then it took South Carolina another month and a half to install the patch.
I know that it's hard to find a time to patch administrative systems,
but that strikes me as a long time.  So nearly five months passed between
the discovery of the patch and the announcement; it seems like it could
have been a month and a half.

Did Ellucian communicate the urgency of the patch to its clients?
It's hard to tell.  What I see is that in the month since the
flaw was revealed (with Ellucian's knowledge), at least 62
institutions have been targeted and [at least 600 accounts
were created in one twenty-four hour period using this
vulnerability](https://ifap.ed.gov/eannouncements/071719ITSecurAlertExploitationEllucianBannerSysVulnerability.html).

Have I ever mentioned how much I hate computers?

In any case, I'm glad that Grinnell is okay.  For now.  And my friend
who works at an institution that uses Banner says that they are okay too.

---

Postscript: This was one of those musings that I thought would go somewhere
when it started, but ran out of steam toward the end.  My apologies.
Maybe I'll come up with a followup musing in a few weeks [10].

---

Postscript: Perhaps all of the things I find annoying in Ellucian
products are an outcome of them trying to avoid breaches.  But there
must be a better way.

---

[1] That is, _The Chronicle of Higher Education_.

[2] It's just _Inside Higher Ed_.  But I thought it was only fair to
add an endnote for _IHE_, since I'd written one for _Chronicle_.

[3] As I understand it, Ellucian has two major products: Banner and Colleague.
Grinnell runs Colleague.

[4] If the user has no choice, why bother with the question?

[5] Welcome to the wonder of "Assist my advisees".

[6] Welcome to the joy of loading a student on SelfService.  And yes,
I just checked, it took about fifteen seconds between clicking on the
link and seeing the page.

[7] I keep wanting to call it USC, but I think another school got
those three initials.

[8] In other University of South Carolina news, [its Trustees have
caved in to the state governor and appointed a new president
over the objections of students, faculty, and even some
donors](https://www.chronicle.com/article/University-of-South-Carolina/246736).

[9] The usal path for this kind of security report is that one
contacts the vendor, such as Microsoft, describes the flaw, and reaches
an agreed-upon time to release a public notification.

[10] Or months.

---

*Version 1.0 of 2019-07-19.*
