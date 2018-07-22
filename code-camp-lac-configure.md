Configuring student accounts
============================

*Topics/tags: [Code camps](index-code-camps), technical*

Unlike the Data Science for Social Good camp, which had the students do most
of their work in the cloud [1], the Language and Code camp will have students
working directly in MathLAN.  They'll be creating HTML and CSS files and
writing programs in Racket.  That means that we have a lot of configuration
to do.  Let's see ...

* We need to set up their HTML directory [2] and set the permissions
  appropriately [3].
* We should give them starter code for the HTML activities so that they
  can see some Web page in their home directory.  That starter code
  belongs in their `public_html` directory.
* Most of the activities with Racket involve "try this code, then
  make these changes." We should give them the starter code for a variety
  of Racket programs.
* We are relying on a bunch of Racket libraries that need to be installed.
  I'd prefer not to have the students install them.
* The first time you run DrRacket, you need to tell it what default language
  to use [4].  Rather than making the students do the steps, we should just
  give them an appropriate configuration file.

The starter code belongs in Git repositories.  That way, we can easily
update if we make changes [5].  I'm okay continuing to use GitHub [6] for
those repos.  You can find the current starter HTML code at
<https://github.com/grinnell-cs/lac-public-html>.  You can find the current
starter Racket code at <https://github.com/grinnell-cs/lac-examples>.

We can use `raco pkg install` to set up the Racket packages.  At first, I
was just using something like the following.

    raco pkg install sxml

However, I don't really want to re-issue that command if a package is
already installed [7].  I know that `raco pkg show` will give me the
list of all the installed packages.  Let's see what I can do.

    rackages=`raco pkg show`;
    function ri() {
      if `echo $rackages | grep -q "\b$1\b"`; then
      else
        raco pkg install $1
      fi
    }

That's not perfect, but it will suffice.

What's left?  The Racket configuration file.  I can just copy that.

---

[1] Or, more precisely, on a Jupyter server.

[2] We're running Apache with a fairly standard configuration.  That means
that Web pages are served from `/home/USER/public_html`.

[3] The home directory needs `a+x`.  The HTML directory probably needs
`a+rx` although one could argue that we don't really need the `r`.

[4] I'm not thrilled with that decision.  But it's not in my control.

[5] I don't know how well that will work once the students start making
their own changes.  We shall see.

[6] I know that many people have moved away from GitHub because of the
acquisition by Microsoft.  I'm still comfortable with it.  Perhaps someday
I'll switch to GitLab or to my own server.

[7] There goes my attempt to keep the shell script simple.

---

*Version 0.5 of 2018-07-22.*
