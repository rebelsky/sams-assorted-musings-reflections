---
title: Class rosters
number: 1429
tags: [Rants](index-rants)
blurb: What happened to "use a single source of data"?
version: 1.0
released: 2026-08-30
current: 
---
It's the start of the semester. That means I need class rosters for all of my classes. And I need them not just as Web pages or printed documents, but also as data files. Why? Because I must add the students to other systems, such as GradeScope, Teams, and Scamper. I also use the rosters to print out individual cards for each student.

I have two main sources for my class rosters: Ellucian Self Service and Grinnell's custom-written pictorial class roster. Perhaps I have three; there's also a roster in Canvas. Guess what? They are inconsistent. How are they inconsistent? In part, it's the information they provide. For example, Self Service includes the students' pronouns (at least if they've provided them); the other two do not. On the other hand, only the custom-written roster includes their preferred names. I'd much rather use preferred names, especially since some of the "actual" names may be dead names. Does Canvas distinguish itself in any way? Yes! Canvas also includes students marked as "inactive". Why?

I'd been using Self Service because I'd thought it was the "official" list. However, when I manually typed the names into Teams to add the students, I sometimes struggled because the names that Microsoft recognizes seem to come from a different database, one that matches the names that the custom roster software provides. Amazingly, if Self Service has "William" and Microsoft has "Fivel", it's not going to find the name when I type "Fivel" [1].

You may find yourself asking why I'm manually adding student names to Teams. As far as I can tell, the only way to add from a CSV [2] file is with PowerShell, and I don't think I have access to PowerShell. Perhaps I should ask ITS. Or perhaps I should ask my overworked academic assistants to do the typing for me. I wonder what others do.

Where was I? Oh, that's right. I was considering which of the three rosters I should use. Until recently, Self Service was the only one that allowed me to download a CSV. While I can't use the CSV with Teams, I can use it for Gradescope and for making identity cards for the students. With a bit of coding, I can also use a CSV to create all the Scamper accounts [3]. So I like CSVs.

Our old pictorial rosters didn't have an option to download information. Our new ones seem to. Yay! And, as I said, the pictorial rosters generally have the students' preferred names. I don't have pronouns, but I can ask students or copy them by hand.

Still, I find myself wondering why we can't rely on one consistent set of information. Isn't that the point of a data store?

---

**_Postscript_**: Grammarly gave this a score of 98/100. I find myself wondering what criteria it uses.

---

[1] The use of "Fivel" as a nickname for "William" represents an old dad joke.

[2] CSV stands for "comma-separated values". It's the most common easily-sharable format for tabular data.

[3] Creating Scamper accounts also involves generating passwords or reading the passwords Scamper generates.
