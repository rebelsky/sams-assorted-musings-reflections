---
title: Sensitive to case sensitivity
number: NNN
tags: [Rants](index-rants), technical
blurb: I hate computers!
version: 0.1
released: 2026-09-30 
current: 2026-09-13
---
As I may have mentioned recently, I've been switching between MacBooks. I've been using a reliable 2019 MacBook Pro. But I really should be using my College-owned 2023 MacBook Pro. Among other things, the former has an Intel chip and the new one has an Apple M3 Pro chip. It should be faster. It should better support newer applications. The College would also prefer that I use my College-owned laptop for College business.

As I've mentioned, I'm now using [SyncThing](https://syncthing.net) to [synchronize the two machines](sink-2026-08-13). SyncThing had been working well. Then, suddenly, it stopped working so well. I started getting a synchronization error for my home directory. After a bit, I tracked down the issue: The 2023 MacBook uses a case-insensitive file system while the 2019 MacBook has a case-sensitive one.

What does that mean? The newer MacBook does not distinguish between lowercase and uppercase letters. That is, on that MacBook, `myfile.txt` and `MyFile.txt` name the same file. In contrast, the older MacBook treats them as different files (or at least different file names).

As a Linux user, I'm accustomed to case-sensitive file systems. That's probably why the older MacBook has one. However, it appears that most Macs are case-insensitive. Why? I don't know. However, the two approaches don't naturally mesh. Unfortunately, some pieces of software, such as [Adobe Creative Cloud](adobe-idiocies-2026-04-05), won't work on case-sensitive file systems. Steam won't, either.

At some point, I got fed up. So I did the "natural" thing: I searched on the Web for a solution. The AI slop that Google fed me seemed reasonable: Back up your computer. Erase the disk, setting the new format to case-insensitive. Restore from your backup. That seemed straightforward enough.

And so I tried. As you might expected, after erasing the disk, I had to reinstall the OS. That took a few hours. Then I got to the "reload backup from Time Machine" page. And I tried. But it simply stopped. No message. No nothing. And then I searched the Web. Guess what? You can't restore to a case-insensitive file system from a case-sensitive file system.

Have I mentioned that I hate computers? [1]


https://github.com/cr/MacCaseSensitiveConversion

---

[1] Most of my students have heard me say that. Repeatedly.
