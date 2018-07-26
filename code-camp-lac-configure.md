Configuring code-camper accounts
===========================

*Topics/tags: [Code camps](index-code-camps), [the joy of code](index-joc), technical*

Unlike the Data Science for Social Good camp, which had the students do most
of their work in the cloud [1], the Language and Code camp has students
working directly in MathLAN.  They are creating HTML and CSS files and
writing programs in Racket.  That means that we have a lot of configuration
to do.  Let's see ...

* We need to set up their HTML directory [2] and set the permissions
  appropriately [3].
* We should give them starter code for the HTML activities so that they
  can see some Web page in their home directory.  That starter code
  belongs in their `public_html` directory.
* Most of the activities with Racket involve "try this code, then
  make these changes" [4]. We should give them the starter code for a 
  variety of Racket programs.
* We are relying on a bunch of Racket libraries that need to be installed.
  I'd prefer not to have the students install them.
* The first time you run DrRacket, you need to tell it what default language
  to use [5].  Rather than making the students do the steps, we should just
  give them an appropriate configuration file.

The starter code belongs in Git repositories.  That way, we can easily
update if we make changes [6].  I'm okay continuing to use GitHub [7] for
those repos.  You can find the current starter HTML code at
<https://github.com/grinnell-cs/lac-public-html>.  You can find the current
starter Racket code at <https://github.com/grinnell-cs/lac-examples>.

We can use `raco pkg install` to set up the Racket packages.  At first, I
was just using something like the following.

    raco pkg install sxml

However, I don't really want to re-issue that command if a package is
already installed [8,9].  I know that `raco pkg show` will give me the
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
Let's see what my script looks like.

    #!/bin/bash
    # lac-camp
    #   Set up a camper's account for the Language and Code camp.
    
    # Set up the public HTML directory and associated permissions
    if [ ! -d ~/public_html ]; then
      git clone https://github.com/grinnell-cs/lac-public-html.git ~/public_html
    fi
    chmod a+x ~
    chmod a+rx ~/public_html
    pushd ~/public_html
    git pull
    popd
    
    # Set up the sample code directory
    if [ ! -d ~/Desktop/lac ]; then
      git clone https://github.com/grinnell-cs/lac-examples.git ~/Desktop/lac
    fi
    pushd ~/Desktop/lac
    git pull
    popd
    
    # Add the Racket packages
    rackages=`raco pkg show`;
    function ri() {
      if `echo $rackages | grep -q "\b$1\b"`; then
        :
      else
        raco pkg install $1
      fi
    }
    ri mcfly
    ri overeasy
    ri sxml
    ri html-parsing
    ri html-writing
    if `echo $rackages | grep -q "\blac-camp\b"`; then
      :
    else
      raco pkg install https://github.com/grinnell-cs/lac-camp.git
    fi
    raco pkg update https://github.com/grinnell-cs/lac-camp.git
    
    # Add Racket configuration file if it does not exist
    if [ ! -d ~/.racket ]; then
      mkdir ~/.racket
    fi
    if [ ! -f ~/.racket/racket-prefs.rktd ]; then
      cp ~rebelsky/share/initial-racket-prefs.rktd ~/.racket
    fi

It took me a little bit to figure out the syntax for having no consequent
for a conditional in bash [10].  Other than that, this was relatively
straightforward.  It seems to work well for the purposes for which I
designed it.  And, now that I've written it, a simple for loop lets
me set up or update every camper's account [11].

    for user in $campers
    do
      echo "----------------------------------------------------------------"
      echo "Setting up $user"
      ssh $user@`hostname` ~rebelsky/bin/lac-camp
      echo ""
    done

There are times in which writing shell scripts slows me down.  In this
case, writing a shell script seems to have been a real win.  I expect to
use something similar the next time I have to get my CSC 151 students
set up at the beginning of the semester.  In that case, I won't know
their passwords, so I'll have them run it themselves.

I'm glad that I have the skills to write scripts like these.  Of course,
I have the skills, in part, because I teach CS.  If I didn't teach CS,
I probably wouldn't need to write scripts like these [12].

---

Postscript: Grammarly tells me that this piece has a shorter-than-average
word length.  I expect that the code is having a negative effect on
word length.

---

[1] Or, more precisely, on a Jupyter server.

[2] We're running Apache with a fairly standard configuration.  That means
that Web pages are served from `/home/USER/public_html`.

[3] The home directory needs `a+x`.  The HTML directory probably needs
`a+rx` although one could argue that we don't really need the `r`.

[4] At least most of the activities *should* take the approach of "try this 
then make changes".  Discussions with my research students suggest that I
have not been clear enough in that message.

[5] I'm not thrilled with that design.  But it's not in my control.

[6] I don't know how well that will work once the students start making
their own changes.  We shall see.

[7] I know that many people have moved away from GitHub because of the
acquisition by Microsoft.  I'm still comfortable with it.  Perhaps someday
I'll switch to GitLab or to my own server.

[8] It's not harmful; Racket just issues a note rather than re-installing.
But I'd prefer not to have to read all of those notes.

[9] There goes my attempt to keep the shell script simple.

[10] The syntax of `bash` is weird.  I still thought it was easier to
have no consequent then to try to negate the test.

[11] Well, there is a little matter of passwords.  But we had all of the
camper passwords when we set up their accounts.

[12] That may not be true.  There are many instances in which it's useful
to configure an account for a new user.

---

*Version 1.0 of 2018-07-23.*
