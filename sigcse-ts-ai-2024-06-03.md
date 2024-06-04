---
title: Developing and presenting AI policies for the SIGCSE Technical Symposium
number: 1286
tags: [Generative AI](index-generative-ai), technical, SIGCSE TS
blurb: Maybe I should have written them with generative AI.
version: 1.0
released: 2024-06-03
current: 
---
Although I've been doing my best to shed work, I still have some significant professional responsibilities. One of the most significant is that I am one of three Program Co-Chairs for the 2025 SIGCSE Technical Symposium on Computer Science Education (SIGCSE TS), the flagship conference on computer science education. It's my second year serving as SIGCSE TS Program Co-Chair, so I'm building upon things I learned the first time through.

SIGCSE TS 2024 was the first SIGCSE TS since the large-scale arrival of generative AI, LLMs, and related technologies---things people often refer to as "ChatGPT" for short. And these technologies had many impacts on the conference.

It makes sense that generative AI plays a role in a CS education conference. Faculty should be asking what roles generative AI might play in CS education. For example, (how) should we be teaching students about coding with prompts? How much of the generative AI technology should we cover in our classes? How do we cover that technology? What should we teach students about the ethics of generative AI? Given that most generative AI tools can complete the introductory CS sequence, how do we help students understand why we ask them to solve problems on their own and not just use these tools? And there are many more.

Generative AI has also become a research tool. For example, can we train an LLM to provide hints for students or to generate new questions of similar difficulty? How good are those hints or questions? 

Authors also use generative AI to help them write better. Not all computer scientists have substantial training in writing. SIGCSE TS is an international conference, so not all authors are native English speakers. New authors may not be used to the style of a CSEd conference (assuming there is such a style).

As you might expect, we encountered various issues relating to the use of generative AI. What kinds? Here are a few.

At least one set of authors used generative AI to write significant portions of a submission, leading to some wonderfully hallucinated references [1]. 

Some authors worried that one or more of the reviews they received was written using generative AI. When the authors contacted us directly, we had to try to determine what role generative AI played in the review.

Some reviewers raised appropriate concerns about research that involved custom LLMs that used copyrighted data scraped from the Interweb. These kinds of situations raise at least two questions for us as Program Chairs: Can we accept such papers, given that scraping copyrighted data is potentially illegal and may be unenthical [2]? If we reject some papers because the reviewers have raised these concerns, how do we reasonably ensure that all papers are treated equally?

Yeah, those seem to be the main ones. What are acceptable and unacceptable uses for writing with generative AI, whether it's papers or reviews? What are acceptable uses of data for LLMs, whether it's paper or reviews? How do we ensure uniform treatment of papers?

The Program Chairs tried asking about these issues. And, while there's some guidance, such as [The ACM Policy on Authorship](https://www.acm.org/publications/policies/new-acm-policy-on-authorship), it does not answer questions about what data can be fed to an LLM.

In addition, the information about the policies there is scattered.

In preparing for this year's SIGCSE TS, I thought it would be useful to clarify existing policies and to add advice on a few that extant policies failed to address.

I turn many things I write into musings. These should be no exception. Right? So here goes.

---

## SIGCSE TS Policies on Generative AI, LLMs, and Related Tools

The advent of generative AI, large language models, and related technologies have created many opportunities for our community, both in support of new kinds of research and in helping improve writing. Along with the opportunities come some challenges, particularly regarding the appropriate use of these technologies.

### Using generative AI to support writing papers

The [ACM Policy on Authorship](https://www.acm.org/publications/policies/new-acm-policy-on-authorship) indicates that

>  The use of generative AI tools and technologies to create content is permitted but must be fully disclosed in the Work. For example, the authors could include the following statement in the Acknowledgements section of the Work: ChatGPT was utilized to generate sections of this Work, including text, tables, graphs, code, data, citations, etc.). If you are uncertain about the need to disclose the use of a particular tool, err on the side of caution, and include a disclosure in the acknowledgements section of the Work.

We expect authors of SIGCSE TS papers to abide by these---and all---ACM guidelines.

### Generative AI as a research and teaching tool

Many SIGCSE TS authors are exploring possible roles of generative AI in their research and teaching. In some cases, questions have been raised about the appropriateness of using copyrighted work, such as problems from a course's website or a service like HackerRank. Since submitting copyrighted material to an LLM may make that material available as training data, and since the products of an LLM trained on such materials may be considered derivative works, **authors of papers that involve the use of copyrighted works as input to or training data for LLMs must obtain explicit permission from the copyright holders to use the works**. Authors must disclose such permission in the acknowledgements section of the paper.

We expect that reviewers who encounter situations in which an LLM or other tool is trained on copyrighted data will verify that the acknowledgements section indicates that permission was sought and obtained.

### Generative AI in the review process

Reviewers may **not** submit papers to LLMs, plagiarism detectors, summarizers, or other such tools. As the [ACM Peer Review Policy(https://www.acm.org/publications/policies/peer-review) indicates,

> [Reviewers may not upload] confidential submissions, technical approaches described by authors in their submissions, or any information about the authors into any system managed by a third party, including LLMs, that does not promise to maintain the confidentiality of that information by reviewers, since the storage, indexing, learning, and utilization of such submissions may violate the author's right to confidentiality.

Obviously, reviewers may not use generative AI tools to write their reviews. However, since "writing helpers", broadly defined, are now incorporated within most major editors and word processors, reviewers may take advantage of such tools to polish the writing in their reviews.

Similarly, APCs may not use generative AI tools to synthesize the reviews and discussion into a metareview, but may use tools to improve the writing or structure of the metareview.

### Checking citations

Unfortunately, we have seen the occasional "hallucinatory reference" in SIGCSE TS submissions. While we do not expect our reviewers to check every reference, we ask that reviewers pay additional attention to references for the time being. If possible, reviewers might consider checking some randomly selected references in each paper they review.

---

Wasn't that thrilling?

Welcome to the wonders of chairing a conference.

We need some community-wide discussion about the policy on the use of copyrighted data in training sets. For now, we're erring on the side of caution.

I wonder what feedback and commentary we'll get on these policies.

---

[1] Many of the references were close but not correct. That is, they were to authors who worked in the area and real journals. However, the particular articles cited had never appeared.

[2] Personally, I find it unethical to use others' data without their explicit permission. Many people I've talked to agree. However, large companies like Microsoft seem to disagree. And generative AI research seems to be a bit of a "wild west" in terms of data scraping.

[3] Many institutions give Program and Symposium Chairs a course release each year they serve as Chair. Grinnell does not.

[4] Chairs receive complimentary registration to the conference, hotel rooms during the conference, meals, and transportation costs. So there is some compensation. It's just not commensurate with the workload.
