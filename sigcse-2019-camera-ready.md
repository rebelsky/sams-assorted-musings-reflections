Preparing "camera-ready" copy for SIGCSE 2019 
=============================================

*Topics/tags: [Overcommitment](index-overcommitment), SIGCSE, academia, long*

The annual SIGCSE Technical Symposium on Computer Science Education has
long been one of the primary places to read and hear about advances in
CS education.  While there are others [1], SIGCSE remains an important
venue.  It's also the one I'm most likely to attend.  SIGCSE 2019 is the 
fiftieth anniversary, and I'm looking forward to it [2].

This year, I submitted three papers to SIGCSE.  Why three?  Two reported
on summer camps that my students and I designed.  We wrote two papers
on the summer camps because we had two different camp designs that we'd
been working on and had not yet published [3].  My experience has been that
our success rate on these kinds of papers is about 50% [4] and I wanted
to be relatively confident that the students could present [5,6].  This is
the third or so year we've submitted two camp papers and, in each year,
it strikes me that the paper I like less is the one that gets accepted.

That's two of the three papers.  The third paper was a report on the
revised design of our software design course.  I'm passing the course on
to other people, and we're changing it slightly, so it seemed appropriate
to write something about the four years that we've offered the course.
Janet Davis, who designed the course, and I have also told each other
multiple times that we needed to write *something* about the course.
So we spent some time getting something ready.  While we did not have
confidence that what we wrote would be accepted, we did know that the
pressure of putting together a conference paper would give us a starting
point for future work.  Plus, reviews are usually a good way to get
feedback on the work, even when papers are rejected.

For reasons that I don't completely understand, all three papers were
accepted.  The SIGCSE proceedings are considered an archival publication,
so our next task was to get the papers ready for publication, creating
the so-called ``camera ready'' version [7].  From my perspective, there
are four primary subtasks to achieve that version.  First, one needs to
read and incorporate the reviewers' suggestions [8].  Second, one needs to
clean up the text as appropriate for an archival version.  The occasional
typo or mis-formatted line can creep into a draft; they don't belong
in the final version.  Third, one often needs to cut the paper down to
the appropriate length.  Addressing reviewers' suggestions often leads
to more text, rather than less [9], but SIGCSE has a hard cap of six
pages for papers [10,11].  Finally, one needs to make sure that the
paper follows the formatting expectations of the conference.

For this musing, I'll focus primarily on the last task, since that
one almost always falls to me.

Between the time I submitted the paper and now, the [ACM LaTeX style
sheet](https://www.acm.org/publications/proceedings-template) has
gone from version 1.54 to version 1.56.  That meant downloading it
and installing appropriate files.  I never know whether I should put
them in a common place or include them as part of the local "project".
Since I'm collaborating with others, I tend to use the latter strategy.

Getting it ready for the conference also means adding some
conference-specific information.  The email that ACM sent me [12]
includes two sets of LaTeX code to include.  I wasn't sure why, but I
used both.  Unfortunately, I discovered that one doesn't work.  Why do
they have things like `\CopyrightYear` if they aren't defined in the
ACM style file?  My sense is that they changed the instructions and,
instead of eliminating the old ones, just added new ones, too.

Skipping ahead, the last task is to fill out a form and upload a PDF
of the camera-ready version and a zip file of the components of that
version.  I found the form annoying.  I don't mind copying the abstract,
keywords, and bibliography from other files.  I do mind that some things
are automatically selected, like "I have no bibliography".  And I 
don't like that I have to click a button and wait for the page to
reload for each additional author.  It's annoying that when the page
reloads, my browser brings me back to the top and I have to scroll down.
Since I have sixteen authors for one paper [14], I tried to click the
button a few times before adding data, but that didn't work.

After submitting the first paper, I got a note that I needed to
reformat the last page because the two columns weren't balanced.
The last page is the list of works cited.  One of the suggestions
was

> (a) Insert `\\vfill\eject` before reference 11 to move more over to column two and produce a more balanced last page.

It appears that whoever wrote that recommendation doesn't regularly
write LaTeX [15].  BibTex automatically generates the code for the
formatted bibliography, so it doesn't make sense to edit it by hand.
Fortunately, they provided an alternate strategy.

> (b) If you have used `\\usepackage{balance}` you can include `\\balance` between  `\\bibliographystyle` and `\\bibliography`

I'm not sure why they've used double backslashes, and I don't use the
`balance` package, but it's easy enough to make those changes.

What about the reviewers' suggested changes, the cutting, and the final 
read-through?  I incorporated as many suggestions as I could.  Not all
were possible.  For example, we couldn't do a series of interviews to
extend the value of our study [16], and we certainly couldn't gather
longitudinal data on the long-term impact of the camp.  On the other
hand, there were a host of smaller suggestions that were worth considering.
And I appreciate that many reviewers were willing to point out the host
of small errors that permeated the drafts [17].  I caught a few more in the
final read through.

The cutting?  Some cutting was hard.  Janet and I had already excised
a useful section about the evolution of CSC 322 [18].  After adding
material to address the reviewers' concerns, we ended up with a
half page or so to cut.  I made some stabs at it, and Janet did
the rest.  For the other two papers, the responsibility was mine.
At one point, I was left with the abstract and the references on the
seventh page of each paper and couldn't get any further.  In a fit of
frustration, I started composing a letter to the program chairs [19].
But it's not fair to ask for an exemption.  In the end, I 
knew that I should be able to cut the text.  And I was able to do so [20].

The papers are done.  And they're submitted.  What's next?  Preparing
the presentations [21].  But that can wait until closer to the conference.

---

**Appendix 1: Email from ACM**

*Here's the email I received from the ACM and the incorrect LaTeX code it includes.*

Subject: ACM Copyright Text, Bibstrip, and Form - Proceedings of the 50th ACM Technical Symposium on Computer Science Education 186 ert642

Your ACM Copyright Form for paper "Exploring the Effects of a Summer Middle-School Camp Emphasizing Data Science for Social Good" in Proceedings of the 50th ACM Technical Symposium on Computer Science Education has been accepted and is attached for your records.

If there are errors in either the title or author listing, please contact the proceedings coordinator for this publication, to receive a blank form to be completed for your accepted paper.


When preparing your paper for submission using the ACM TeX templates, the rights and permissions information and the bibliographic strip must appear on the lower left hand portion of the first page.

The new ACM Consolidated TeX template Version 1.3 and above <https://www.acm.org/publications/proceedings-template> automatically creates and positions these text blocks for you based on the code snippet which is system-generated based on your rights management choice and this particular conference.

Please copy and paste the following code snippet into your TeX file between \begin{document} and \maketitle, either after or before CCS codes.

    \copyrightyear{2019}
    \acmYear{2019}
    \setcopyright{acmcopyright}
    \acmConference[SIGCSE '19]{Proceedings of the 50th ACM Technical Symposium on Computer Science Education}{February 27-March 2, 2019}{Minneapolis, MN, USA}
    \acmBooktitle{Proceedings of the 50th ACM Technical Symposium on Computer Science Education (SIGCSE '19), February 27-March 2, 2019, Minneapolis, MN, USA}
    \acmPrice{15.00}
    \acmDOI{10.1145/3287324.3287510}
    \acmISBN{978-1-4503-5890-3/19/02}

ACM TeX template .cls version 2.8, automatically creates and positions these text blocks for you based on the code snippet which is system-generated based on your rights management choice and this particular conference.

Please copy and paste the following code snippet into your TeX file between \begin{document} and \maketitle, either after or before CCS codes.

   \CopyrightYear{2019}
   \setcopyright{acmcopyright}
   \conferenceinfo{SIGCSE '19,}{February 27-March 2, 2019, Minneapolis, MN, USA}
   \isbn{978-1-4503-5890-3/19/02}\acmPrice{$15.00}
   \doi{https://doi.org/10.1145/3287324.3287510}

If you are using the ACM Microsoft Word template, or still using an older version of the ACM TeX template, or the current versions of the ACM SIGCHI, SIGGRAPH, or SIGPLAN TeX templates, you must copy and paste the following text block into your document as per the instructions provided with the templates you are using:

Permission to make digital or hard copies of all or part of this work for personal or classroom use is granted without fee provided that copies are not made or distributed for profit or commercial advantage and that copies bear this notice and the full citation on the first page. Copyrights for components of this work owned by others than ACM must be honored. Abstracting with credit is permitted. To copy otherwise, or republish, to post on servers or to redistribute to lists, requires prior specific permission and/or a fee. Request permissions from Permissions@acm.org.

    SIGCSE '19, February 27-March 2, 2019, Minneapolis, MN, USA
    © 2019 Association for Computing Machinery.
    ACM ISBN 978-1-4503-5890-3/19/02…$15.00
    https://doi.org/10.1145/3287324.3287510

NOTE: Make sure to include your article's DOI as part of the bibstrip data; DOIs will be registered and become active shortly after publication in the ACM Digital Library. Once you have your camera ready copy ready, please send your source files and PDF to your event contact for processing.

---

**Appendix 2: The obnoxious email that I did not send**

*And yes, I titled the draft "Obnoxious Question".*

Dear Sarah and Jian,

Thanks, once again, for allowing us a seventh page to use for references.
As you well know, that decision means that authors don't have to balance
including a citation with including more content.  It also provides a bit
more fairness, since those who draw broadly from the literature get as
much space as those who make less use.

I wonder if you'd consider making a similar exception for the
acknowledgements section.  Like the references, the acknowledgements
differ significantly from project to project, so one could claim that
it accomplishes similar goals.  And even a moderately long reference
list provides room for an acknowledgement section on the seventh page.

Thanks!

\-\- SamR

---

[1] The others include the annual [ITiCSE](https://iticse.acm.org/)
conference on Innovation and Technology in Computer Science Education,
the [ICER](https://icer.acm.org/) International Computing Education
Research conference, the new [CompEd](http://www.acmcomped.org/)
ACM Global Computing Education Research Conference, the [Kali
Calling](https://www.kolicalling.fi/) International Conference
on Computing Education Research, a few journals, [Mark Guzdial's
'blog](https://computinged.wordpress.com/), and some other things I'm
forgetting about.

[2] That's in spite of it being in Minneapolis in late February and
early March.

[3] We also have a curriculum for the craft of code camp for elementary
school students.  It's not clear that we have anything to write about
that.

[4] That's somewhat better than the average conference acceptance rate
of about 30-35%.

[5] They could also have presented the work in poster form.  I find that
presenting papers is a more valuable experience for the students, not least
because their work appears in archival form.

[6] Yes, I realize that submitting two papers with 50% odds only gives
me odds of 75%.

[7] I'm pretty sure that they don't use cameras anymore.

[8] SIGCSE generally has five reviews per paper along with one
"meta review" that summarizes the views of the reviewers and any
further discussion they had.

[9] For example, the reviews of both code camp papers included a request
that we more clearly differentiate this camp from other initiatives.  Doing
so takes space.

[10] This year, we were allowed a seventh page for citations.  I appreciate
the extra space, particularly since it does not penalize authors for
citing.

[11] Six pages may not sound like a lot.  But six pages f a conference
paper (two columns, 10 pt) ends up being about 5500 words.
That corresponds to approximately a twenty-page, double-spaced,
single-column paper.

[12] See the appendix for details.

[14] Why sixteen?  It's a paper about two years of curriculum development.
I had seven students work on the curriculum the first year and eight the 
second year.  One overlapped the two years.  Plus there's Sarah and me.

[15] I was going to say "Given that ACM sends non-working LaTeX code,
that shouldn't be a surprise".  But this is someone from Sheridan
Communications.

[16] Maybe that's a topic for another paper.

[17] From what my reviewers say, my drafts are generally well written but
poorly edited.  That's a good description of my work.  Particularly this
year, when I was submitting the originals at 4 a.m. or so, editing did
not seem like a real possibility.

[18] Janet had argued against cutting that section, but I saw no option.
Since I cut it before submitting the paper, I'm not sure what the 
reviewers would have said about it.  If we ever write an extended version
of the paper, I"ll add it back in.

[19] See the second appendix.

[20] Michelle helped.

[21] My next SIGCSE task is getting the student volunteers site up
and running.  But that's one of my other roles.

---

*Version 1.0 of 2018-12-01.*
