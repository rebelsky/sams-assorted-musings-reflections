---
title: Having fun guest teaching an algorithms course
number: 1386
tags: [Teaching](index-teaching)
blurb: The poor students.
version: 1.0
released: 2025-12-13
current: 
---
This past week, a colleague asked me to substitute for their upper-division class in algorithms. I can never recall whether we call the course "Algorithm Analysis" or "Analysis of Algorithms". I suppose it doesn't really matter. When talking to other computer scientists about the course, I tend to refer to it as a "CLRS-style" course.

My task was fairly straightforward. The students were wrapping up the unit on Dynamic Programming [1], which meant that they were doing mock interviews. Students paired off, with one as the interviewer and the other as the interviewee. We then kicked the interviewees out of the room, discussed with the interviewers the problems they'd be asking their partners about, and then brought the interviewees back in for the interviews. My roles were to introduce the problems and likely solutions to the interviewers and to check in on the interviews during class.

These kinds of "solve an algorithm problem" interviews, sometimes called "technical interviews", are far too common in the computing industry. And it's not clear that the interviews tell you anything other than whether the person has prepared well for this type of interview. They don't, for example, tell you anything about how the person collaborates with others or whether they generate clear code [2].

I decided to have a bit of fun with the class. Hence, on the first day, I introduced a fictitious narrative about the interviews. Here's an approximation of what I said.

---

> Welcome to interview days at GrinCo [3], where our employees smile more.

> It's required.

> GrinCo's typical interview lead couldn't be here, so I'm here as a temp from the Ministry of Unemployed Computer Scientists. For some reason, President Trump always reverses the acronym when talking to us [4].

> I am employee 54111, but you can call me "Sam" [5]. Most people seem to.

> I see that EA, your normal interviewer, could not be here. 

> Wow! I hadn't realized that GrinCo had purchased Electronic Arts. That's so cool.

> _After observing student reactions._ Well, when I was your age, Electronic Arts was cool.

> Whoops. Sorry. I need to follow the script; I want to remain employed. Let's see. The next task is to pair you up. Please form pairs.

> Wow! It looks like you successfully formed pairs of senior engineers and potential new hires. What are the odds?

> _Pause._

> No, I'm serious. It says that I'm supposed to ask about odds. What are the odds that each pair would have one engineer and one applicant?

> _Pause._

> Oh well. I'll just note that it was too difficult for you. It's good that we're not really planning to hire any of you.

> As you know, today's interview is about dynamic programming. After all, the true mark of someone's likely quality as an engineer is their ability to solve contrived dynamic programming problems.

> GrinCo thanks the senior engineers who made the time to attend. Clearly, you have too much free time. We'll be doubling your workload.

> GrinCo also thanks all of the potential employees. We very much appreciate the useful code and ideas you provided in your "practice problems". Thanks for signing over your intellectual property rights as part of the interview process.

> Is [mangling of teaching assistant's name] here? Are you sure? Anyone? Let me try reading it again. _Repeat with additional manglings. Eventually, people figure out that it's the TA._

> We want to thank you for your excellent idea of paying employees in fifteen-minute blocks, rounding them as appropriate, and scheduling them to start their shifts five minutes before the hour and end their shifts ten minutes before the hour. That strategy allows us to get ten free minutes for each shift [6].

> I'm going to ask the interviewees to leave the room for a few minutes so  I can discuss processes with the interviewers. You can enjoy our lovely lounge space. And, while I'm sorry to report that we no longer have a free café, you are welcome to visit it [7].

---

I'm not sure if the students enjoyed any of that, but I certainly had fun.

For the next class, I took a different approach. Rather than taking on a mythical persona, I pushed the students a bit on the topic at hand. In particular, I asked the students to consider the following sequence of questions. I often ask my students similar questions when we study different algorithm design strategies.

---

> What kinds of problems do you use dynamic programming to solve? For example, I don't think you'd use it to sort. But there must be some kind of problem that suggests you should see whether a dynamic programming solution would work.

> Are there problems of that kind that dynamic programming fails to solve---or fails to solve efficiently?

> What other techniques might you use to solve those kinds of problems?

> What are the key ideas in dynamic programming?

> What are the steps in developing a dynamic programming solution? [8]

> I expect that you all wondered why this technique is called "dynamic programming" and, as good students, looked it up. What did you find? [9]

---

I suppose I could have asked other questions, such as what tends to go wrong when you try to design a dynamic programming algorithm. However, I wanted to give them time for the interviews; the ones I asked were enough.

---

It's fun to guest teach classes like that, particularly when the other instructor has done the heavy lifting of preparing most of the class materials. I enjoy taking on another persona from time to time [10]. And it's valuable to ask students reflective questions like those above.

We haven't worked out next year's schedule yet, but I've heard rumors that I may be teaching Algorithm Analysis. I look forward to it!

---

[1] A lovely marketing term.

[2] At least one interviewer I've spoken with says the company usually prioritizes whether an applicant completes the task within the allotted time over the quality of the code they produce. They do, however, care that students write efficient code.

[3] Many of our Microsoft services are labeled as "grinco", such as "grinco.sharepoint.com". GrinCo has always seemed like an amazingly corporate term to me, so I adopt it for situations like this.

[4] The acronym for the Ministry of Unemployed Computer Scientists should be MUCS. However, if you reverse it, you get SCUM. I can see Trump addressing the members as such.

[5] A "5" looks somewhat like an "S". A "4" looks a bit like an "A". And three 1's in a row look like an "M", particularly if you put the serifs at the top.

[6] Grinnell recently upgraded its payroll system. It now rounds the start and end of each shift to the nearest multiple of 15 minutes (at the hour, quarter past, half past, quarter to). For our class mentors, who are typically scheduled to end their shifts at the end of class (ten minutes before the hour) and who are asked to start a few minutes before the beginning of class, honest reporting of time means that they are underpaid.

[7] The class is held in the HSSC. It has a large open area and a café.

[8] From my perspective, one of the two central ideas in dynamic programming is that you formulate a recursive solution, usually one that involves multiple recursive calls. On the first day of class, students told me that they came up with those recursive formulations, but didn't bother to write them down. I hoped to encourage them to do so.

[9] Unfortunately, one student decided that pulling up ChatGPT would be a good way to answer that question. Fortunately, ChatGPT gave a mediocre answer at best.

[10] Some students who took Algorithm Analysis with me may recall me taking on the persona of our textbook author.
