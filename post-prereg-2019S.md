Reflections on preregistration data for spring 2019
===================================================

_Topics/tags: [Miscellaneous](index-misc), [Grinnell](index-grinnell), rambly, long, unedited_

Throughout preregistration period, I
keep track of [the status of Grinnell's course
offerings](https://itwebapps.grinnell.edu/DotNet/CourseOffering/).
In part, I do so to help with my work: It's useful to know what the
pressure points in CS will be [1,2] and, as an advisor, I want to be
able to warn my advisees about courses that will likely over-fill [3].
Plus, I'm a bit of a data junkie.

It's become a bit of a tradition for me to muse about the preregistration 
data on the last night of preregistration.  So, let's see where things
stand.

This year, I realized that I could use Google Sheets to help me track the
data.  I started with a sheet with the following command in the 
cell A1.

    =IMPORTHTML("https://itwebapps.grinnell.edu/DotNet/CourseOffering/", "table", 1)

Since that table lacks a "current enrollment" column and also combines
"slots available" and "capacity" into a single cell, I added new columns.
Column's K and L have available and capacity, and get created by using 
something like `=SPLIT(H2,"/")`.  Column M, enrollment, is just
the result of subtracting column K from column L.  Now I can explore
the data in new ways, such as sorting by enrollment or available slots [4].

Wednesday morning, before I created the spreadsheet, I looked for the
classes with the largest enrollments.  Those were as follows:

* ECN-111-04, _Introduction to Economics_: 42 enrolled, capacity of 26.
  Intro Econ has five sections, so that's not so troublesome.
* CSC-151-01, _Functional Problem Solving w/lab_: 39 enrolled, capacity of 32
  We have one other section.  That's a bit troublesome.
* ART-111-02, _Introduction to the Studio_: 37 enrolled, capacity of 15.
  There's one other section, already full.  This is very troublesome.
* BIO-150-02, _Intro to Biological Inqry w/ lab_: 37 enrolled, capacity of 24
  There are other sections.
* LIN-114-01, _Intro to General Linguistics_: 36 enrolled, capacity
  of 25.  Of course, that course [does not allow juniors and seniors to
  preregister](prereg-jrsr), so it would probably be far at the top if
  it did.

At the end of preregistration, the classes with the highest enrollments
were as follows.

* MUS-120-04, _Performance: Voice_.  57 enrolled, capacity of 22.  I assume
  that Music has a way to handle this much demand, but I'm not sure.  The
  high enrollment seems like a natural consequence of Grinnell's "every
  student has music lessons included in their tuition".  But we have a
  variety of voice instructors, and it doesn't look like 200-level voice
  is over-enrolled, so I'll cross my fingers that these high enrollments
  are a positive, rather than a challenge.
* ART-111-02, _Introduction to the Studio_.  56 enrolled, capacity of 15.
  ART-111 is always over-enrolled, but rarely by this much.  More on Studio
  Art will follow in the general comments.
* CSC-151-01, _Functional Problem Solving_.  53 enrolled, capacity of 32.
  *I'm number three!*  But I guess that's not a good thing; I don't like
  cutting students from my classes.  My quick analysis suggests that if
  we cut all non-first-year students from CSC 151 and balance the two sections,
  we'll only be over-enrolled by one [6].  I'd like every interested student to
  be able to take intro CS, but that's not going to happen this year.  Maybe
  some can take CSC-105.
* ECN-111-04, _Introduction to Economics_.  51 enrolled, capacity of 26.
  Fortunately, there are five sections of Intro Econ, so balancing should
  work.  If I calculate correctly, the five sections will have an
  average enrollment of 19 students.
* ENV-145-01, _Nations and the Global Environment_, 51 enrolled,
  capacity of 50.  

The spreadsheet has made a big difference in one way; in most years,
I don't look at the music practica or ensembles, and so don't include
them in my reflections.  This year, they appear in my spreadsheet, so
they enter my consciousness.  I see that MUS-101-06, _Grinnell Symphony
Orchestra_, orchestra has 48 and that MUS-120-92, _Perf: Piano_ has 45.

What about over-enrolled classes?  ART-111-02 is number one, with 41
more students than slots.  Voice is number two, with 35 more students
than slots.  ART-134-01 is number three, with 32 more students than slots.
ECN-111-04 is number four, with twenty-five too many students, and
STA-209-03 [7] has twenty-two too many students.

Studio Art always over-enrolls.  But I'm pretty sure that it's
worse this year than it's been in the past [8].  If we include the
over-enrollment by eight in ART-111-01, Art has enough extra demand
to support five additional sections of 100-level classes.  And that
doesn't even include the over-enrollment by eight in the special topic on
_Contemporary Photography_.  Since we consider creative expression on of
the six pillars of Grinnell's liberal arts education [9], I wonder why
we don't hire more studio art faculty [10].  Perhaps the new position
in Media Studies will help.  For the time being, let's hope that the
department can identify a few part-time people to cover more sections
and that they can find spaces to offer those sections.  And, of course,
let's hope that the Dean will pay for those sections.

Traditionally, STA-209, _Applied Statistics_, is another course
that over-enrolls.  And this semester, we have one section that is
over-enrolled by twenty-two students.  But there are 42 slots available
in the four other sections, so it appears that we have reached the
appropriate level of staffing for that class.  It looks like MAT-115,
_Introduction to Statistics_ is over-enrolled by nineteen in one section
with only eight slots available in the other section.  Maybe they can
push some students to 209.  Or perhaps we [11] can cut one section of 209
to offer another section of 115.  

What else is over-enrolled?  I've already mentioned ECN-111, which they
should be able to balance, and CSC-151, which we'll handle by cutting
anyone who is not a first-year student.  The 1:00 p.m. section of
MAT-215, _Linear Algebra_, is over-enrolled by twenty and the 11:00
a.m. section is over-enrolled by one.  There are six slots left in the
2:00 p.m. section, but that's not enough.  For the second semester in a
row, it looks like Math will have to cut a few folks.  Fortunately,
it looks like there's sufficient room in MAT-218, which has over-enrolled
in past semesters, even though a few students may have to shift from 
_Elementary Number Theory_ to _Graph Theory_.

Other multi-section courses that had a section significantly over-enroll
by double digits include BIO-150-02, _Introduction to Biological
Inquiry_ (nineteen too many in one section), SOC-111-05, _Introduction
to Sociology_ (sixteen too many in one section), ENG-205-02, _The Craft
of Fiction_ (fifteen too many in one section), CHM-129-03, _General
Chemistry_ (fourteen too many), ANT-104-02, _Anthropological Inquiries_
(fourteen too many), MAT-133-02, _Calculus II_ (ten too many), and
CHM-222-01 [12], _Organic Chemistry_ (ten too many).  

How will students in those courses fare?  

* There are enough sections of BIO-150 to cover everyone.  But each
  section has its own topic, so students will not necessarily be able to
  do the kind of biology they would like.
* SOC-111 has forty-five open slots, and so should be able to cover 
  the over-enrollment.  
* ENG-205 has a second section with four slots available, so some 
  students will necessarily be cut.  It looks like ENG-206, _The Craft 
  of Poetry_, and ENG-388, _Writing Seminar: Screenwriting_, are also 
  over-enrolled, so there are not places for all the students who want 
  to do creative writing.  Perhaps a few can end up in ENG-386, _Writing 
  Seminar: Poetry_.  Or perhaps not, since that likely has the 200-level 
  classes as prereqs.  
* There are enough slots in CHM-129; some students will just have to do
  a workshop-style course rather than separate lecture and lab.
* The two other sections of CHM-222 combine to provide zero available
  spaces.  My guess is that Chem will balance the three sections and keep
  all students, even though they are larger than planned.
* ANT-104 appears to have a total over-enrollment of six.  I'm not sure
  what they'll do about that.
* Finally, there seem to be enough slots to cover all the interest in
  Calculus II.

Then we have the situations that all of us hate to encounter, classes
with only one section that are over-enrolled.  I've already mentioned
Drawing and Photography.  What else is up there?  

* ECN-226, _Economics of Innovation_, has twenty students too many.
  That's not surprising.  The course is always popular, and I recall
  that Brad was not able to offer it last year.
* CSC-213, _Operating Systems and Parallel Algorithms_, has twenty
  students too many.  We really wanted to be able to offer a second
  section, but don't have the staffing.  I'll write more about CS in a
  subsequent paragraph.
* LIN-114, _Introduction to General Linguistics_ has nineteen students
  too many, and that's with the course already cutting out all juniors
  and seniors.  We really need to find a way to offer more sections [14].
* PHE-195, _Off the Grid_, is over-enrolled by seventeen students.
  Is there a way for the College to pay Zeiss extra to offer another
  section?  [15] Would he be willing to do so?
  Hutchison to teach a second section, if she's willing?
* PHE-202-01, _Coaching Methods_, is over-enrolled by fifteen.  I'm not
  sure what the alternatives are there.
* ENG-274, _Sex, Gender, & Critical Theory_, is over-enrolled by fourteen.
  That's become typical for a Garrison class, so I'm sure that John and
  the English department have a strategy in mind.
* EDU-295-02, _ST: Incarcerated Literacies_, is over-enrolled by fourteen.
  I'm not sure what the options are there.  
* THD-117, _Introduction to Acting_, is also over-enrolled by fourteen.
  Once again, we see an over-enrolled creative expression course.
  While I'm sure that Craig has a standard process for handling that
  situation, it may be that the College needs to think more broadly
  about its support for creative expression.
* PHI-271, _Neurophilosophy_, is over-enrolled by twelve.  It's good,
  but perhaps not surprising, to see some Philosophy courses getting
  high demand.  This may be a case in which students get dropped
  and encouraged to consider other philosophy courses.
* MUS-201, _Digital Music-Making_, is over-enrolled by twelve.  There's
  no room in the classroom for more students.  I wonder whether they'll
  prioritize music majors or what.
* BIO-345, _Advanced Genetics_, is over-enrolled by ten, even though
  it's an 8:00 a.m. class.  Advanced Genetics always over-enrolls.
  I expect they'll end up having to ask a few students to shift to
  Animal Physiology or the Special Topics course in Immunology.
* ARH/CLS-395, _ST: Ancient Greek Sculpture_, is over-enrolled by ten.
  Monessa always has to cut students.  I wonder if it ever gets any
  easier.

That's about all I can cope with thinking about for now.  For those who
care, here are a few other over-enrolled single-section classes:

* Over-enrolled by nine students: CSC 262-01, _Computer Vision_, 
  ENG-295-02, _ST: Grinnell Writer's Workshop_, and
  ART-240-01, _Ceramics_.
* Over-enrolled by seven: 
  POL-295-01, _ST: Political Psychology_,
  PSY-248-01, _Abnormal Psychology_,
  HIS-277-01, _China's Rise_,
  MAT-321-01, _Foundations of Abstract Algebra_ [16],
  ANT/AMS-295-01, _ST: Politics Food & Otherness_ [17],
  ENG-121-01, _Introduction to Shakespeare_ [18], and
  SOC-285-01, _Contemporary Sociological Theory_.
* Over-enrolled by six:
  ENG-223-01, _Tradition of English Lit I_,
  HIS-244-01, _World War II on Eastern Front_,
  ARH/CLS-250-01, _Roman Archaeology and Art_ [19], and
  CSC-324-01 and CSC 324-02, _Software Design & Development_ [20].
  
Is this worse than prior years?  I'm not sure.  But I get depressed
thinking about not only the effects on students as they are cut from
classes they want to take, but also the faculty workload (not only work
involved in the the process, but the emotional load).  And then there's
the followup load for both students and faculty as they collaborate to
identify appropriate alternatives.  At least there are still

Switching topics, I thought it would be interesting to look at courses
with multiple sections taught by the same instructor.  That provides an
opportunity to consider potential effects of class time.  By focusing
on the same course and the same instructor, we generally eliminate issues
of topic [21] and of student bias about instructors [23].

This year, there appear to be a variety of opportunities to compare
offering times.  (Same Prof, same class, different times.)

* There are two sections of ANT-104, _Anthropological Inquiries_, with 
  Kulstad.  The MWF 9:00 a.m. section is over-enrolled by fourteen.  The
  MWF 1:00 p.m. section is over-enrolled by three.
* There are two sections of ARH-103, _Introduction to Art History_, with
  Rivera.  The MWF 10:00 a.m. section is over-enrolled by five students.
  There are nine open slots in the MWF 11:00 a.m. section.
* There are two sections of CSC-207, _Object-Oriented Problem Solving,
  Data Structures, and Algorithms_, with Rebelsky.  The MWF 8:30
  a.m. section has eight slots. The MWF 1:00 p.m. section has seven slots.
  [24]
* There are two sections of CSC-341, _Automata, Formal Languages, and
  Computational Complexity_ [25], with Hamid.  There are three slots
  in the MWF 9:00 a.m. section and two slots in the MWF 1:00 p.m. section.
* There are two sections of ECN-111, _Introduction to Economics_,
  with Ferguson.  There are twenty-three slots in the MWF 8:00
  a.m. section and thirteen slots in the MWF 9:00 a.m. section.
* There are two sections of ECN-111 with Ohrn.  There is one slot in
  the TuTh 8:00 a.m. section.  In contrast, the TuTh 9:30 a.m. section
  is over-enrolled by twenty-five students.
* There are two sections of ECN-280, _Microeconomic Analysis_, with
  McGavock.  The MWF 9:00 a.m. section is over-enrolled by four.
  There are four slots in the MWF 10:00 a.m. section.  At least they
  balance nicely.
* There are two sections of ENG-120, _Literary Analysis_, with Sutaria.
  There are no slots available in the MWF 10:00 a.m. section.  The MWF
  1:00 p.m. section is over-enrolled by six.  [26].
* There are two sections of FRN-102, _Introduction to French II_, with
  Alexandre.  The MTWF 8:00 a.m. section has twenty available slots.
  The MTWF 10:00 a.m. section has nine available slots.
* There are two sections of GRM-102, _Continuing German_, with Samper
  Vendrell.  The MTWF 8:00 a.m. section has twelve available slots.
  The MTWF 10:00 a.m. section has thirteen available slots.
* There are two sections of GWS-495, _Bad Feminists, Bad Critics_, with
  Allen.  The MWF 10:00 a.m. section has three available slots.  The MWF
  2:00 p.m. section has ten available slots.
* There are two sections of JPN-102, _Beginning Japanese_, with Kojima.
  The MWF 10:00 a.m. section has eight slots and the MWF 2:00 p.m. section
  has six slots.
* There are two sections of MAT-215, _Linear Algebra_, with Mileti.  The
  MWF 1:00 p.m. section is over-enrolled by twenty.  In contrast, the
  MWF 2:00 p.m. section has six available slots.  I wonder why the hour
  makes such a difference.
* There are two sections of MAT/CSC-208, _Discrete Structures_, with
  Stone.  There are fifteen available slots in the MWF 8:00 a.m. section
  and one available slot in the MWF 1:00 p.m. section.
* There are two sections of STA-209, _Applied Statistics_, with Miller.
  There's one slot left in the MWF 10:00 a.m. section.  In contrast,
  the MWF 1:00 p.m. section is over-enrolled by 22 students.  Who knew
  that 1:00 p.m. was so popular?
* There also two sections of STA-209 with Olsen.  There are 6 open slots
  in the MWF 8:30 a.m. section.  There are also 17 slots available in the
  MWF 2:30 p.m. section.  Of course, there's a second section MWF at
  2:30 p.m., with 18 available slots, so that may have draw students
  away from the 2:30 p.m. section.

My not-so-surprising conclusion from all that analysis: Students avoid
8:00 a.m. classes if they can.  I guess the biggest exception is German.
Perhaps that says something about students who take 100-level German.
But, more broadly, it may be worthwhile rethinking our use of 8:00
a.m.  slots.  I know that we need the 8:00 a.m. sections to make sure
that students can take a wide variety of classes and so that we have
classrooms for all the classes.  Still, I wonder whether there's some
other alternative.

I also learned that 1:00 p.m. is a comparatively popular time.
I wonder why.

What else?  Oh, yeah, I'd promised to discuss how CS plans to deal with
the over-enrollment of twenty students in CSC-213.  I'll admit that I
don't know for sure; we're discussing it on Monday.  We'll keep all of
the seniors who need it to graduate.  I assume we'll keep all of the
juniors who have not yet taken CSC-211 or CSC-213 [27].  Beyond that,
I'm not sure.  In the past, we've tried to balance those students to
other courses.  But there's no room in CSC 301, _Analysis of Algorithms_
or CSC-324 and _Software Design and Development_, and only a few slots in
CSC-341.  We may be able to do some shuffling to allow us to offer another
section of one of the core courses, which should help.  Fortunately,
next year should be better as we'll be at approximately one more FTE
than this, and we seem to have leveled off at about sixty majors per year.

I'll also note that there are some great courses that still have room.
I don't want to list too many because that would make courses conspicuous
by their absence. Let me just say that if I were still a student, I'd
try to take Fredo's ART-295-01, _ST: Caribbean Art and Visual Culture_
and Katya's ANT-295-03, _Mapping Antisemitism_.  More generally, I'm
glad to see that there's still a wide array of courses I can recommend
to my advisees, or at least my open-minded advisees.

---

[1] For example, it can be useful to think ahead to special requests we
might make to the Dean or to courses we can afford to combine to free
up another section.

[2] It's less important now that I'm not chair.

[3] "You should probably drop a note to the faculty member.  And we should
have a fallback plan."

[4] I turns out that I need to copy the data into a new spreadsheet to
do so, since sorting also affects the formula that filled the spreadsheet.
There's probably a way around that, but it was easier to just make a new
each of whose cells linked to the data in the original [5].

[5] I also made a copy of the data at the end of preregistration so that
post-prereg changes won't affect the info.

[6] I'm not saying that's what we'll do; I'm just reporting on the data.

[7] I almost wrote "MAT-209-03".  This year is the first in which
statistics gets its own designation.

[8] Perhaps Grinnell students
are reacting to [Simpson college's plan to cut their art
department](https://www.desmoinesregister.com/story/news/2018/10/10/simpson-college-indianola-layoffs-13-positions-jobs-faculty-staff-cuts-iowa-schools-private/1593909002/),
which stuns me.

[9] While [the
text](https://catalog.grinnell.edu/content.php?catoid=16&navoid=3312#Elements_of_a_Liberal_Education)
seems to foreground the "study of creative expression" above the actual
expression, my sense is that most of us foreground the expression.

[10] The obvious answer is that the President and the Trustees don't
support expanding the faculty, and there are no natural cuts elsewhere
in the faculty.

[11] By "we", I mean "Whoever has to worry about these things".  I'm
not involved at all in decisions about statistics.  I'm not even sure
whether or not the Math/Stat faculty are involved in decisions about 115.

[12] That's the 8:00 a.m. section!

[14] I know that CS would like to help with that issue.  But we're already
struggling too much with our courses.

[15] I don't usually ask that question.  But for folks who have multiple
responsibilities at the College and courses that are one- or two-credits,
sometimes other options seem possible.

[16] Ouch!  That's a required course for the major.

[17] Students love Katya.  And the Monday 7:00-9:50 p.m. slot seems to
be a time they particularly like taking her courses.

[18] A Garrison course with spring-break travel.  I'm surprised it was
not even higher.

[19] An MC class.  I'm surprised the numbers aren't higher.

[20] I know I said I was only doing single-section classes.  But both
sections are over-enrolled.  Plus, it's my department.

[21] I don't think there's an instance in which a faculty member teaches
two different sections of a course with the same number but different
content [22].  I'm pretty sure that BIO-150 and ENG-120 are the primary
variable-content introductory courses.  It's rare that someone teaches
two sections of BIO-150.  And I believe that when someone teaches two
sections of ENG-120, they have the same focus.

[22] I have considered doing that with CSC 151, but have not done so yet.
Few faculty are as crazy as I am.

[23] Students have been known to make decisions based on what they've
heard about particular instructors, even though they should know that
opinions are not always accurate.  They are also more likely to choose
a course with a named instructor than "Staff".

[24] It's nice to know that I'll have a semester in which some of my
classes have reasonable enrollments.  If I count correctly, I'll have
33 in CSC-151-01, 16 in CSC-207-01, and 17 in CSC-207-02.  While there's
a small temptation to combine the two sections of 207, I don't think
that would be healthy for me or the students.

[25] Computer science seems to employ long course titles.  We once had
a course that we called "Team-based software development for community
organizations."  Right now, I think "Object-Oriented Problem Solving,
Data Structures, and Algorithms" is the longest one.

[26] The other section of Literary Analysis is also over-enrolled.  I
wonder what English plans, or what the Dean will require.

[27] Otherwise, we're just kicking the can down the road.

---

*Version 1.0 of 2018-11-16.*
