Class wrappers
==============

Part of an ongoing series of things I needed to write anyway.

_We're discussing Design Patterns in our software design class this week.
For those of you who don't know, Design Patterns represent common solutions
to problems that occur in the design of software projects.  They were
inspired by Christopher Alexander's [_A Pattern Language_](http://www.patternlanguage.com/apl/aplsample/aplsample.htm).  They've gone on to inspire a
host of other kinds of "Patterns", including "CS Teaching Patterns"._

_I ran out of time at the end of Monday's class, so I thought I'd put
what I was going to say into a musing.  I was talking about a class
of patterns that I call "wrappers", starting with the Adapter pattern._

---

**The Problem**.  We find ourselves in a situation in which the application 
we are developing requires an object with a certain set of operations and,
while we don't have that object, we do have objects with a similar set of
operations.

**The Solution**.  Create a class that provides the expected operations,
but delegates the work to the extant class.

**An Example**.  

We're designing an awesome time management system for overcommitted faculty
members.  One thing we need in the system is a first-in-first-out to-do
list.  We might describe that as follows.


    public interface SimpleToDoList {
      public void addItem(String item);
      public String nextItem(void);
      public boolean empty(void);
    }

When we get to the implementation stage, we might decide that these
requirements are really similar to a `StringQueue` [1] class that we've
written in the past.

    public class StringQueue {
      public void enqueue(String str);
      public String dequeue(void);
      public boolean hasMoreItems(void);
    }

The *wrong* thing to do is to say "Oh, we'll just use `StringQueue`
instead of `SimpleToDoList`."  Why?  We might later realize that we want
to add another feature to our to-do lists.  We'll then have extra work
and cognitive overload in figuring out which instances of `StringQueue`
represent our simple to-do lists and which actually represent queues
of strings.

The Adapter pattern suggests that we write a simple class that delegates.
Here's a sketch.

    public class SimpleToDoListOne implements SimpleToDoList {
      StringQueue queue;

      public SimpleToDoListOne() {
        this.queue = new StringQueue();
      }
      
      public void addItem(String item) {
        this.queue.enqueue(item);
      }
    
      public String nextItem(void) {
        return this.queue.dequeue();
      }

      public boolean empty(void) {
        return !(this.queue.hasMoreItems());
      }
    }

It's a comparatively trivial class to write.  But writing that adapter
makes our code much more, well, adaptable.  If we decide to add a
feature to `SimpleToDoList`, or to change policies, or whatever, we
can work there, rather than in the client class (our life manager)
or in the wrapped class (the queue).  We keep the responsibilities
where they should be.

---

**Other kinds of class wrappers**

Before I learned Design Patterns, I generally used the term "*wrapper*"
for this approach [2].  You take an existing class (or procedure, or data
structure) and you wrap some code around it.  You'll find that there are
multiple Patterns that you use this wrapping approach.  And you'll find
the process of wrapping generally useful.

Here's one of my favorite uses of wrapping.  There's probably
a design pattern name for it, but I'm never sure whether it's
Decorator or something else.  Suppose we have an interface, a class
that implements that interface, and an additional expectation we want
to add.  For example, we might want a version of a `SimpleToDoList` that
logs each action (for historical purposes, for debugging, whatever).
Let's write that.

    public class LoggingSimpleToDoList implements SimpleToDoList {
      /** The real to-do list we're wrapping. */
      SimpleToDoList core;

      /** Where the log goes. */
      PrintWriter out;

      public LoggingSimpleToDoList(SimpleToDoList core, PrintWriter out) {
        this.core = core;
        this.out = out;
      }
  
      public void addItem(String item) {
        this.out.println("ADD " + item);
        this.core.addItem(item);
      }

      public String nextItem(void) {
        String str = this.core.nextItem();
        this.out.println("GET " + item);
        return str;
      }

      public boolean empty(void) {
        return this.core.empty();
      }
    }

The underlying principle is the same.  We have a core object with some
capabilities.  We write an object that uses the other object to do most
of the real work and adds some other capability.  We've effectively
wrapped one class with another.

---

**Wrapping procedures in Scheme**

Note that you can "wrap" Scheme procedures, too.  We do a form of that
in CSC 151 when we create equivalents to extant procedures that 
log their steps.  But we could generalize that approach.  Let's see.
Here's a simple procedure that takes a procedure and a symbol as input
and returns a procedure that displays the call to the wrapped procedure
and then calls the wrapped procedure.

    (define logproc
      (lambda (proc name)
        (lambda params
          (write (cons name params))
          (newline)
          (apply proc params))))

And here's that procedure in action.

    > (define + (logproc + '+))
    > (+ 2 3)
    (+ 2 3)
    5
    > (+ (+ 2 3) (+ 4 5) 6)
    (+ 2 3)
    (+ 4 5)
    (+ 5 9 6)
    20

Here's a fancier version of that procedure.

    (define log-call
      (lambda (proc name)
        (lambda params
          (let ([result (apply proc params)])
            (write (cons name params))
            (display " => ")
            (write result)
            (newline)
            result))))
    
And here's that fancier version in action.

    > (define + (log-call + '+))
    > (+ (+ 1 2) (+ 3 4) (+ 5 7 8))
    (+ 1 2) => 3
    (+ 3 4) => 7
    (+ 5 7 8) => 20
    (+ 3 7 20) => 30
    30
    > (define sum
        (lambda (lst)
          (if (null? lst)
              0
              (+ (car lst) (sum (cdr lst))))))
    > (sum (list 5 1 2 3 6))
    (+ 6 0) => 6
    (+ 3 6) => 9
    (+ 2 9) => 11
    (+ 1 11) => 12
    (+ 5 12) => 17
    17

It behaves even better than I would expect [3].

    > (define sum (log-call sum 'sum))
    > (sum (list 5 1 2 3 6))
    (sum ()) => 0
    (+ 6 0) => 6
    (sum (6)) => 6
    (+ 3 6) => 9
    (sum (3 6)) => 9
    (+ 2 9) => 11
    (sum (2 3 6)) => 11
    (+ 1 11) => 12
    (sum (1 2 3 6)) => 12
    (+ 5 12) => 17
    (sum (5 1 2 3 6)) => 17
    17

Isn't Scheme great [4]?

---

[1] Well, probably `Queue<String>`, but let's not worry about that
right now.  We're considering these issues conceptually, not in terms
of actual Java.

[2] I still do.

[3] That is, I did not expect the following example to work.  But Scheme,
or at least Racket, scopes a bit differently than I expected.

[4] Or perhaps just terrifying.

---

*Version 1.1.0 of 2018-03-06.*
