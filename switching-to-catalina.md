Switching to Catalina
=====================

*Topics/tags: [???]*

As long-time readers may recall, I [recently upgraded my MacBook to
macOS Mojave](upgrades-2019-10-02).  I'm usually reluctant to upgrade
my operating system unless I know of significant benefits from the
new OS.  I'd delayed the upgrade to Mojave because it did not seem
to have any features I needed.  But then Grinnell changed its email
authentication mechanism, and I needed to upgrade.

When Catalina was released, I read through the list of changes and
new features and found one that I really wanted: Sidecar.  For those
who haven't been paying attention, Sidecar allows you to use your
iPad as a second monitor.  That seemed like a great feature to me,
particular since it also allows you to use the iPencil.

But I've been delaying my upgrade until [the Mac GPG
Suite](https://gpgtools.org/) supported Catalina [1].  It does now,
so I decided to upgrade my Mac

But Sidecar doesn't support my MacBook [2].  Only MacBooks released
in 2016 or more recently do.  I wish I had seen that before I
upgraded.

A lot of time for mail to upgrade its database.  But that's not
surprising.  At least it took less than an hour.  (I didn't time
the exact amount.)

Need to install XCode developer tools again. You think I would have
memorized `xcode-select --install` by now.

Upgrading Mac GPG was easier than I expected, other than the need to pay
for another license.  I don't mind paying for Mac GPG; I know that it's
a lot of work for them to reverse engineer the Mail app so that they can
integrate the encryption and decryption.  And the payment process was
also smooth.

Another downside: The Overdrive [3] app no longer works because
it's 32-bit software.  That change [has also generated some
heat](https://company.overdrive.com/2019/09/25/important-update-on-the-overdrive-desktop-app-for-mac/),
although for Overdrive, not for Apple.  It is really that hard to
recompile [4]?

What in hell is this `zsh` that is now the default shell?  I'll admit
that I still miss `tcsh`, which I always found had a clearer syntax
than `bash`.  But it looks like lots of people use `zsh`.  I don't
want to learn a whole new syntax for configuring my system, do I?  I
guess this transition will end up being a topic for another musing.

Moving files around.  Bleh.  My /Music is now in /Users/....

---

[1] If you want to read some really nasty posts, check out [their
support pages](https://gpgtools.tenderapp.com/).  When Mojave came out,
GPGTools went from open-source software to for-pay software.  So when
it didn't work upon the release of Catalina, many of those who had paid
were understandably upset.  It doesn't help that the folks who build
the tools are mediocre communicators.

[2] Or vice versa.

[3] Overdrive is the system the Drake Library contracted with to
supply ebooks and audio books.  Since most ebooks work on my Kindle,
I use it primarily for audiobooks on my MacBook.

[4] I know that building 64-bit apps is not always as simple as recompiling.
But if you've used a sensible development environment, it should be.  And
it's not like the change was unexpected.

---

*Verison 0.1 of 2019-11-22.*
