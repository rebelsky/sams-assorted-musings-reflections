---
title: CSC-151's many GitHub repos
number: 1265
tags: [CSC151](index-151)
blurb: Somewhat shared resources for the course.
version: 1.0
released: 2024-01-03
current: 
---
Like most computer scientists, the faculty of Grinnell's Department of Computer Science use version control systems to maintain all sorts of things, including our course materials. When Janet Davis and I first designed the MediaComputing version of CSC-151, we used CVS. When Charlie Curtsinger moved the course to Jekyll, he also switched the version control system to GitHub. Or maybe we switched to GitHub before then. I don't recall. And I'm too lazy to look it up since it doesn't really matter [1].

In any case, we now use Git and GitHub to maintain the CSC-151 materials. And, for better or for worse, we have seen a proliferation of repositories. This musing provides a guide to many of the various repos, both public and private. 

## Various versions of the course

**<https://github.com/grinnell-cs/csc151-images>** (public)

The Web site for the image-based version of CSC-151, the one we'll be teaching in Spring 2024. The repo includes the syllabus and schedule, the various handouts (including some of mine that you'll probably want to delete), the daily readings and labs, and the mini-projects (homework assignments). We keep it public so that students can post corrections [2] and so that others can easily grab parts of it. As mentioned [before](csc151-new-instructor), we use Jekyll to build our sites [3]. This version currently uses Racket but will eventually migrate to Scamper.

Historically, we push common changes directly to the main branch (perhaps with a few exceptions). For example, if we correct a typo or a reading, we should make that change in the main branch.

By custom, when there are multiple simultaneous sections of the course, we each create our own branch for the course. My typical workflow when I sit down to work on my section is something like the following.

```
git checkout main
git pull 
git checkout 2024Sp-rebelsky 
git pull 
git merge main 
```

That is, I start every session by pulling and merging any changes from the main branch. Sometimes, it's necessary to do a `git stash save` and a `git stash pop` if I've inadvertently made changes that I haven't pushed.

As you might expect, changes to the readings and labs should be made in the main branch. Changes more relevant to individual sections (e.g., rearranging the schedule or changing due dates) should likely be made in those sections.

_Feel free to modify readings and labs!_ We all own this course.

**<https://github.com/grinnell-cs/csc151-music>** (private)

The Web site for the music-based version of CSC-151. As before, this repository contains the syllabus and schedule, handouts, readings and labs. This one also includes past exams and such, which is why it's private [4]. You can find those materials in the `vault` directory.

It's also the repo used for <https://csc151.cs.grinnell.edu>.

I've not worked on this one so I don't know the protocols. 

**<https://github.com/grinnell-cs/csc151-dh>** (public)

The Web site for the most recent digital humanities version of CSC-151. You can guess the contents by now. Other than the problem-solving topic, this version of CSC-151 differs from the current one in that it includes a discussion of regular expressions (using an alternate syntax that we hope is easier for students to understand) as well as a bit of discussion of Racket structs [5].

**<https://github.com/grinnell-cs/csc151-dighum>** (private)

An older version of the digital humanities version. Why do we have two repos for the same version? Mostly because someone made this one private, and I'm a firm believer in having the repos public [6]. I also wanted to encourage students to send corrections via GitHub [7].

**<https://github.com/grinnell-cs/csc151-datasci>** (private)

The data science light version of CSC-151. Will it be used if we bring back a data science version, or will the new data science version be all new? That's a question for the future.

## Other relevant repositories

As you might expect, the Web sites are not the only repositories associated with the course. We have a variety of ancillary materials, too. You should make copies of these repositories.

**<https://github.com/grinnell-cs/csc151>** (public)

Here, you can find the Racket library we've developed for CSC-151. As I mentioned in [the introductory musing](csc151-new-instructor), the library provides a variety of procedures, including support for some higher-order procedures (an alternate nondeterministic `reduce`, composition, and sectioning/cutting), some additional image procedures [8], a simple counter system, binary trees, and more. 

We try to let students know when we update this repo so that they can ensure they are using the latest version.

At some point, we'll figure out how to share this explicitly with the broader Racket community.

**<https://github.com/grinnell-cs/racket-autograder-gradescope>** (public)

Here, you will find the autograder library we use with Racket and Gradescope [9].

**<https://github.com/grinnell-cs/csc151-admin>** (private)

This repository contains the administrative materials for the public repositories. It includes autograders for assignments and labs [10], a few other files that I don't feel comfortable including in a public repo, learning assessments from each semester, and quizzes for each semester. The old LAs and quizzes should serve as helpful resources as we need to write LAs and quizzes for a new semester.

**<https://github.com/grinnell-cs/gradescope-mastery>** (public)

Scripts we use to turn the Gradescope reports into grades. These are supposed to handle redos, mastery grading, and such. As of this writing [11], the only one there is a broken version of my script. You may be able to find another script in the `csc151-music` repo [12].

## Some less relevant repositories

**<https://github.com/grinnell-cs/csc151-finals>** (private)

Final examinations from 2017--2018 and 2018--2019. Since we've changed the format of the course, it's not clear that these will be useful. Few of the problems target only one topic.

**<https://github.com/grinnell-cs/csc151-quizzes-repo>** (private)

Quizzes from Fall 2016 through Fall 2017. Different branches contain the different versions of the quizzes. Since we've changed the format of the course, it's not clear that these will be useful. However, they may provide some ideas for LAs. I haven't looked at them since before the pandemic.

**<https://github.com/grinnell-cs/csc151-scripts>** (private)

We used to have students run shell scripts to configure DrRacket. This repo contains those shell scripts. Configuring "by hand" seems to work at present.

**<https://github.com/grinnell-cs/csc151www>** (public)

A wrapper library for the various Racket WWW libraries. We've used this in some sessions of the digital humanities version of CSC-151.

**<https://github.com/rebelsky/csc151>** (public)

The old MediaScheme version of the course. This version is from back when we used DocBook rather than Markdown/Jekyll as our source language for the site. You are likely better off reading the materials on [the corresponding Web site](https://rebelsky.cs.grinnell.edu/Courses/CSC151/2016S/home/) which dates back to Spring 2016.

## Concluding notes

I've left out some repositories, such as old versions of the 151 library or an old version of the DH course. I have likely missed some other repositories. Nonetheless, I think we've covered the important ones in the first two sections. You can find others by skimming the list of repositories in <https://github.com/grinnell-cs>. As should be able to tell, you can feel free to make your own if you feel they are necessary or even useful.

---

[1] I found an answer while looking for other repos. We moved to GitHub before we moved to Jekyll. We still have some DocBook-sourced Web sites on GitHub.

[2] They never do.

[3] Our notes on using Jekyll are coming soon.

[4] I use a separate private repository for the administrative materials.

[5] I'd like to fit `struct`s into the image-making version. Unfortunately, that version seems to packed as it is.

[6] That's something I forgot to mention in "The dangers of working with SamR": I'm opinionated. Strongly opinionated.

[7] They never do. I may have mentioned that already.

[8] With more coming soon.

[9] Perhaps I'll discuss that in another musing. For now, you can look at the examples.

[10] I suppose those don't need to be private.

[11] Wednesday, 3 January 2024.

[12] Yup. It's at <https://github.com/grinnell-cs/csc151-music/blob/main/vault/gradescope/grader>.
