---
title: Reflections on yet another registration process
number: 1262
tags: [Registration](index-registration), [Grinnell](index-grinnell)
blurb: It's complicated. 
version: 1.0
released: 2023-12-20
current:
---
_Note: I started this musing about a month ago. Since Registration didn't finish before Thanksgiving, I didn't finish the musing. I've updated it, but it may not have done a perfect job. Please excuse any tense switches._

We've finally finished Preregistration/Registration season at Grinnell. We're at about the fourth new registration process we've used over the past four semesters. It did not seem to work as anyone planned or hoped. I feel bad for the Registrar's staff, who must bear the brunt of the problems [1]. Many people [2] asked, "Why is Grinnell's registration so complicated?" Since I spend way too much time thinking about [Grinnell's registration](index-registration), I thought I'd muse a bit on what happened (or failed to happen).

For the first twenty-some-odd years of my Grinnell career, we had a relatively consistent registration system. Here's a description I wrote in [a musing from six years ago](prereg-2017S).

> We let students enroll in whatever courses they want, and let the courses over-enroll. Then, at the end, we have a period in which we try to figure out how to fix everything. There are multiple fixes to employ: We balance sections; we cut students and tell them to find something else; we sometimes let classes grow a bit; we cancel classes and add additional sections; we try to convince the Dean to fund an extra section and find someone to teach that section. After that, the students who've been cut try to find something else to fit into their schedule, or beg the faculty to allow their courses to over-enroll, or whatever.

A few years ago, when Anne Harris became president, she decided that the system was broken and that it needed to be changed. Among other things, she worried about the equity issues when faculty decide who to cut without clear policies in place. There were also concerns that the system put a lot of work on the Registrar's office. We were also told that our switch of Registration systems (from Ellucian Webadvisor to Ellucian SelfService, or something like that) made our old system untenable [3].

And so folks [4] have been trying to find an appropriate replacement. Unfortunately, we've repeatedly discovered that automating registration is a difficult problem. It doesn't help that we have conflicting priorities and never completely resolved those conflicts. For example, is it more critical that every student get at least one of their top-two classes or that every student makes progress in their major(s) [5]?

In any case, it's hard enough to develop an appropriate system that we're now on our fourth or so approach. This one showed some promise: Instead of registering for classes and then getting cut, students were supposed to add themselves to waitlists and then we'd have the registration system prioritize them and send out invitations [6]. It sounded like this system retained a key advantage from the old system (in that we'd have some sense of demand) but also provided the fairness of automatically applying predefined priorities. 

This new system included other rules, such as that everyone was supposed to get enrolled in two courses before the system moved on to putting people in their third and fourth courses. To make that work, students needed to prioritize courses for the "select two" round and then add more courses later.

We knew in advance that the system would be imperfect. Among other things, we can't express all of the priorities we want. For example, one of our priorities in CS is that every major and prospective major gets at least one course creditable toward the major. But we can't encode that in the system. But it's also that the system can't handle the more complex aspects of registration.

For example, consider a situation in which we have two sections of a class, each with a capacity of 20. Suppose there are ten students who can only take section 1 (e.g., because they have a required course for a second major at the time section 2 meets), ten students who can only take section 2, and twenty who can take either section. The waiting list for each section will have 30 students. There is an optimal distribution of students to sections. However, if we do one section at a time, about 2/3 of the students who can only take that section won't get in.

There are ways to ameliorate the situation. For example, if you randomly choose one student from the waiting list from each section, switching between sections as you go, in most cases, all but one or two students will get placed. It's not perfect, but it's much better. Since I don't understand how our registration software works, I don't know if this is possible to automate. I suppose it could be done by hand, but that would be time-consuming.

In addition, the current system is not equitable. For example, I have a student who plans to be a CS/Psych major. In an ideal world, they would be able to take MAT-208, a CSC class, a Psych class, and one other class next semester. However, it was clear that MAT-208 would fill in the "top two classes" round, the CS classes they could take would fill in that round, and most Psych classes would fill in that round. So "pick your top two" didn't let them get the three courses they should take. In contrast, some of my students had majors with courses that they knew would never fill in the "top two classes" round; they could more freely select the electives that they found interesting in that round *and* get appropriate courses to move forward.

From my experience, as well as my conversations with colleagues, it's clear that this new system requires much more advising effort and advising time.

Grinnell's complex characteristics
----------------------------------

Why must we use such complex registration systems, given that other schools get by with less complex systems? I suppose there are a variety of reasons. Here are some.

At some schools, particularly larger schools, many classes don't have a set capacity; since they have large lecture classes, it's relatively easy to add additional seats. At Grinnell, keep our classes small and generally try to stick to the specified capacities.

At some schools, students must declare a major before they enroll and there are limits to how many students are accepted to each major. Since the path through a major is relatively predictable, you can know in advance how many slots you need and ensure that you have appropriate staffing. If you won't, you can either add staffing or further limit the number of students in the major. At Grinnell, students generally don't declare a major until their fourth semester, and many add a second major in their fifth or sixth semester.

At most schools, students take a variety of pre-specified general-education courses, so, once again, those needs are relatively predictable; it's only major courses and a small number of electives that cause issues. At Grinnell, we have an "individually advised curriculum", so things are much more up in the air. The individually advised curriculum also encourages students to believe that they can take the classes they want, rather than limit themselves to those that are available [7].

Even at schools with those advantages, students may still not get the classes they need. I've certainly seen discussion of the large numbers of students who need to take five years to graduate because they can't get all their required courses in the semester they need those courses.

Approaches to registration
--------------------------

What are the simpler registration mechanisms that other schools use? Would they work at Grinnell? I don't know all the registration mechanisms in use. But I know of a few basic patterns. Let's consider some of them.

_First come, first served_ (FCFS). In this model, whoever requests a class first gets the class. There are many variants. In some, students must get a faculty signature. In others, students must sign up for a meeting with an advisor and can only register after they've met with their advisor. Back when I was in college, we had a system in which you signed up immediately after meeting with your advisor, so students camped out overnight the night before you could schedule advisor appointments; you needed to do so if you wanted popular courses like, say, Shakespeare with Bevington or Film with Mast.

FCFS systems never struck me as particularly equitable, particularly when you need to wait in line for something. Not everyone has the time to wait in line. Some have jobs that will prevent them from waiting. In addition, first-come, first-served systems prioritize students who know exactly what they want; one of the goals of a liberal arts education is that you can explore.

_Randomized._  In these systems, students are randomly chosen to be the next person to pick their class (or classes). We use something like this for first-year registration at Grinnell. The randomized FCFS system might show some potential, particularly if it's one class at a time. However, it fails to adjust for the priorities that departments may have for classes (e.g., that majors have priority). I also don't think that our registration software is designed to handle this approach, which suggests it will require a lot of manual work.

_Seniority-based_. This model is much like FCFS, except prioritization is based on class year. At least one other small school with an open curriculum uses this approach. I don't know how well it works. In my discipline, I worry that some of the senior non-majors would take seats away from the first- and second-year students who want to start the major or make forward progress in the major.

_Economic_. In these systems, each student receives a fixed number of tokens and uses them to buy slots in classes or bid on slots in classes. Presumably, as demand goes up, costs would go up.  I've seen such systems in the past, but I don't know if any are still in play.

Economic systems are likely to have the same problems as our current system; students in majors whose courses have few open slots will likely need to spend their tokens on core courses, while students in majors whose classes don't fill can save their tokens for other courses.

Economic registration systems also prioritize those who are better at manipulating systems.

_Application based_. Some schools require students to apply to classes, at least to high-demand classes. Faculty members then read through the applications and decide who to accept based on those applications. Since there's a formal application process, it's a bit fairer than the more open ended "faculty get to decide". But there's still a chance for inequity and bias in the system.

After going through the approaches, I don't think any of these would work better than some variant of the current system. Part of the problem is that we have multiple situations in which the supply-to-demand ratio is low, almost one (sometimes less than one). In such situations, the registration system has to behave almost perfectly since there's no space for errors. The manual work from the old system was one way to help reach optimal or near-optimal distribution; automating it is unlikely to be possible [8].

Designing a new system
----------------------

So what should we do?

Some colleagues have suggested that we return to the old system. That's not a bad idea. We've now specified priorities for each class, and we could use those under the old system. In many ways, filling classes and then cutting is better than wait lists, since we have a much clearer view of what the demand is. (Students can put themselves on waitlists for multiple sections; they can only enroll in a single section. On the other hand, waitlists have the advantage that students can say "I'll take any of these".) And cutting according to published priorities accomplishes President Harris's equity/equality goals.

Still, I'd try something different.

In phase one, students would register for their _necessary_ classes. For declared majors/concentrators, that would be one course in each major or concentration, perhaps a second class if they are behind, and potentially an additional requirement (such as MAT-208 for CS majors or CHM-211 for Biology majors). For undeclared students, that would be one course in each of up to two likely majors. How would we know that the courses are required or what their prospective majors are? We could trust the students. Or we could ask advisors (or department chairs) to sign off on them.

Courses might over-enroll in phase one. Hence, in phase two, we'd see what adjustments needed to be made. Adjustments could involve balancing sections [9]. They could involve talking to students about taking other courses. But I'd hope that we'd have comparatively few conflicts [10]. And the overlaps would likely be infrequent enough that we could give students the individual attention they deserve.

In phase three, each student would be permitted to add _one_ elective class. Students who had side-enrolled in a special course (e.g., one with a study-abroad component) would have that course count for their phase-three course. Our current waitlist + priority approach might work well here, although I'd suggest that we simply enroll students in courses directly as we take them off the waitlist, rather than inviting them to enroll. 

Note that some students might have only two courses after phase three (one for their major and one elective) while others might have as many as four (one for each of two majors, one required external course, and the elective). That's it's own kind of inquity, but I consider it much less inequitable than our current system.

After phase three, each student should have (a) courses that allow them to advance in their major(s) and (b) an elective they would like.  At this point, we could move to open, first-come, first-served registration in phase four. That phase could also prioritize students by seniority.

Would that work? I don't know. I'd hope so. There are, of course, other details that have to be ironed out, such as what to do about the students who intend to do 3-2 programs. 

I also don't know if our technology would support this. But it seems like it should.

Could students manipulate the system? I'm sure they'll find ways. Some will declare a major just to get courses in that major and then drop it later. Others will find ways to manufacture conflicts to ensure they get the section they want. Perhaps there are ways to take advantage of the waitlist system. However, students will always find a way to manipulate systems.

As always, your comments are welcome.

---

[1] I also feel bad for the students who experience negative effects.

[2] E.g., students, parents on the Grinnell Family Facebook page.

[3] I don't really buy the "the software won't let you do it" claim. You can usually find workarounds. However, I accept that the workarounds would have likely consumed more staff time.

[4] Mostly our Registrar.

[5] Yes, that's really been a conflict.

[6] Many of us thought students would be automatically added once they were taken off the wait list. We were wrong. 

[7] It's not an unreasonable perspective as long as it's tempered by an understanding that classes fill.

[8] For a single department, there are some algorithms that could work. A paper on the topic will be presented at the 2024 SIGCSE Technical Symposium in Computer Science Education. 

[9] While concerns have been raised that balancing sections might violate the Higher Education Opportunity Act, it should be okay to balance sections if they use the same textbook.

[10] Increasing staffing in departments with a low supply-to-demand ratio would also help.
