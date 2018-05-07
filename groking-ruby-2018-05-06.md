Groking Ruby (or failing to grok Ruby)
======================================

*Tags/topics: [The joy of code](index-joc), technical, Ruby, newbie*

In this semester's CSC 322, I've expanded my coverage of more advanced 
issues in object-oriented design, or at least object-oriented design
in Ruby.  In part, that's a reaction to what seems to be a decrease in
the coverage of OOP/OOD [1] we do in CSC 207.  But it's also because
the standard "encapsulation, inheritance, polymorphism" triumvirate
no longer captures everything a modern programmer should know about
object-oriented design.

On the advice of an alum, I've been using Sandi Metz's _Practical 
Object-Oriented Design in Ruby_ to help them think through some issues.
Throughout the book, Metz builds an extended example based on a
hypothetical bicycle excursion company.  In chapter 6, in which Metz
introduces (or re-introduces) inheritance, she develops a general
`Bicycle` class and represents the information we need to know about 
bikes as we plan trips.  One of the most important procedures provided 
by the `Bicycle` class is `spares`, which produces a list of the spare
parts that should be brought along with the `Bicycle`.

In an interesting alternate to the traditional inheritance approach,
Metz suggests that the subclasses not override the `spares` procedure.
Instead, they are allowed to provide a `local_spares` procedure for the
additional spare parts they need, such as handlebar tape on road bikes,
shocks on mountain bikes, and flags on recumbent bikes.  And yes, those
are the three subclasses she introduces.

Those of you who speak Ruby can read more details in [the Github repo for
the chapter](https://github.com/skmetz/poodr/blob/master/chapter_6.rb).
The code of interest starts on line 679 or so.

Metz then starts chapter 7 by asking how her readers would implement
recumbent mountain bikes.  The rest of the chapter introduces mixins
(modules, in Ruby).  But the use of mixins ends up having to do more
with scheduling objects than with implementing recumbent mountain bikes.
Since Metz did not answer the recumbent mountain bike question, I decided
to challenge my students to do so.  And I tried to make clear that they
should try to keep the code DRY [4].

Of course, when I give a design problem like that, I also try to think
about how I'd approach it.  I'm not sure that mixins are the best approach,
but I tried to approach the problem as if mixins provided a good solution.
Now, I'm not an experienced Ruby programmer and I don't traditionally use
mixins in the object-oriented languages I commonly use [5].

My own solution involved creating a separate class for each of the kinds
of bikes and using mixins for the common parts like "Shocks" and "Flag".
That way, `MountainBike` and `RecumbentMountainBike` could both include
`Shocks` while `RecumbentBike` and `RecumbentMountainBike` could both
include `Flag`.  Since it appears that recumbent bikes of all types
have different size tires than the corresponding nonrecumbent bikes,
I was comfortable making each class specify its own default tire size.

But here's the problem I encountered: The `local_spares` method of
`RecumbentMountainBike` should probably call the `local_spares` method
of both `Shocks` and `Flags` [6,7].  As a Ruby Newbie
[8], I don't know enough about issues like delegating a
message to a particular mixin, rather than the one given by
default.  Eventually, I ended up at the [Ruby documentation for
Modules](https://ruby-doc.org/core-2.2.0/Module.html).  A bit of
experimentation led me to write something like the following [9].

    class RecumbentMountainBike
      # ...
      def local_spares
        shocks = Shocks::instance_method(:local_spares).bind(self).call
        flag = Flag::instance_method(:local_spares).bind(self).call
        shocks.merge(flag)
      end
    end

I realize that the repeated code means that I should probably write a
loop.  And the more I think about it, the more I also expect that using
modules is the wrong approach to this problem; I'd be more tempted to
design objects that represent the various additional parts and do some
things with those objects.  But those design issues are not my concerns at
the moment.  My bigger concern is how I should call the instance methods
in the modules.  `Shocks::instance_method(:local_spares).bind(self).call`
is a hideous bit of code that I'd never want to impose upon a student.
I wonder if there's a better way to specify a particular instance method
to call in Ruby.  There must be.

---

Postscript: Here's part of another really bad strategy that is nonetheless
kind of fun.  I'm having the `Bicycle` class call `post_initialize` on any
module that happens to have it.  That way, I can specify the additions
in each class of bike by just choosing the right modules.  Note: While
I was experimenting with this approach, I added stupid messages to the
`post_initialize` methods.

    class Bicycle
      def initialize(args={})
        # Get the list of included modules (which I'm calling the parts)
        @parts = self.class.included_modules
        @parts.delete(Kernel)
    
        # ...
    
        # Let the parts do their own initialization
        @parts.each do |part|
          if part.instance_methods.include?(:post_initialize) then
            part.instance_method(:post_initialize).bind(self).call(args)
          end
        end
    
        # Subclasses can initialize, too
        post_initialize(args)
      end
    
      # ...
    
      def post_initialize(args)
      end
    
      def spares
        spare_parts = { tire_size: tire_size, chain: chain }        # From Metz
        @parts.each do |part|
          if part.instance_methods.include?(:local_spares) then
            spare_parts.merge(part.instance_method(:local_spares).bind(self).call)
          end
        end
        spare_parts.merge(local_spares)
      end
        
    end
    
    module Flag
      def post_initialize(args)
        puts "Flag me down!"
      end
    
      def local_spares
        # ...
      end
    end
    
    module Shocks
      def post_initialize(args)
        puts "It's so shocking!"
      end
    
      def local_spares
        # ...
      end
    end
    
    module Tape
      attr_reader :tape_color               # From Metz
    
      def post_initialize(args)
        @tape_color = args[:tape_color] || "Grinnell Red"
        puts "Taped up in #{tape_color}
      end
    
      def local_spares
        { tape_color: tape_color }          # From Metz
      end
    end
    
    module Dirt
      # ...
    end
    
    # Empty implementations of all the Bicycle subclass methods so that
    # we don't accidentally call one of the mixin methods twice.
    module Hack
      def post_initialize(args)
      end
    
      def local_spares
      end
    end
    
    class RecumbentMountainBike < Bicycle
      include Flag
      include Shocks
      include Dirt
      include Hack
    
      def default_tire_size
        '2.25'
      end
    end
    
    class TapedUpRecumbentBike < Bicycle
      include Flag
      include Tape
      include Hack
    
      def default_tire_size
        '28'                                # From Metz
      end
    end
    
This approach is unlikely to be successful in the long run.  But it
was fun to write.  I enjoyed exploring the powers of introspection.
And, while this is not the right approach for representing bikes, I can
anticipate writing other programs that use this strategy.

Even if it were a good approach for the bike problem, it needs work.
For example, I have two similar loops in which I check each of the
parts and call a function on each.  Should I generalize it?  Probably.
But not today.

There are times that I'm surprised at what stupendously strange approaches
languages support.  There are times I'm surprised at what awful code I
can write that use these approaches.  I also wonder why I find this "fun".

---

If you've made it this far, you probably know Ruby and have a high
tolerance for bad code.  But I know that you want to make things better.

1. What is the right way to call an instance method in a particular module
that you've included?  Alternately, why might it be a bad idea to call an 
instance method in a particular module that you've included, other than
it represents some fairly tight coupling of the code?

2. How awful is the "query all modules for a method and then call it"
approach?

---

Postscript: I'm finally giving up teaching the class that uses Ruby.
Why is that only now that I find this beautifully stupid ways to do things
in Ruby?  Oh well.  I'll be teaching our algorithms, data-structures,
and intro OOD course next spring.  I can do lots of stupid things in Java,
too [10].

---

Postscript: Would I post code like this in public if I didn't have tenure
already?  Possibly; it's not any worse than most of the code that appears
on QueueUnderflow, or whatever that site is called.

---

Acknowledgments: Since I don't know a lot about mountain
bikes or recumbent bikes, I grabbed the tire size from
<http://lightfootcycles.com/Ranger-Recumbent-Mountain-Bike>.

---

[1] OOP: Object-oriented programming.  OOD: Object-oriented design.
OOPS: Object-oriented programming systems.

[2] Not all bikes have shocks.

[3] The chain holds values like '10-speed'.  I'm not quite sure why
that's called a chain, but mine is not to reason why.

[4] Don't Repeat Yourself.

[5] Does Java support mixins?  I don't think so, at least not as naturally
as some other languages.

[6] Similarly, the `post_initialize` method of `RecumbentMountainBike`
should also call the `local_spares` method of both `Shocks` and `Flags`.

[7] This assumes that the two mixins have those methods.  I suppose
that I should not require those methods.

[8] Rubie Newby?

[9] I'm not yet completely comfortable with "trust the classes", so I
added a test to make sure that each mixin actually provided a `local_spares`
method.  That also lets me make fewer assumptions about the mixins.

[10] Did someone say "Anonymous Inner Classes" [11]?

[11] If I recall correctly, most of my code that uses anonymous inner 
classes ends up being done much better with lambdas.

----

*Version 1.0 of 2018-05-07.*
