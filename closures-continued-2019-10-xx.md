Closures, continued

A colleague pointed me to Python's discusison of this stuff.

https://www.python.org/dev/peps/pep-3104/

Says something similar to what I said about the dictionary workaround.

> However, this workaround only highlights the shortcomings of existing scopes: the purpose of a function is to encapsulate code in its own namespace, so it seems unfortunate that the programmer should have to create additional namespaces to make up for missing functionality in the existing local scopes, and then have to decide whether each name should reside in the real scope or the simulated scope.

Makes an interesting claim.

> Python is sometimes called a "multi-paradigm language" because it derives so much strength, practical flexibility, and pedagogical power from its support and graceful integration of multiple programming paradigms.

How can you say that it gracefully integrates multiple paradigms if it
does not support a key aspect of the functional paradigm?  

Also a comment about Ruby

> Ruby is an instructive example because it appears to be the only other currently popular language that, like Python, tries to support statically nested scopes without requiring variable declarations, and thus has to come up with an unusual solution. Functions in Ruby can contain other function definitions, and they can also contain code blocks enclosed in curly braces. Blocks have access to outer variables, but nested functions do not. Within a block, an assignment to a name implies a declaration of a local variable only if it would not shadow a name already bound in an outer scope; otherwise assignment is interpreted as rebinding of the outer name. Ruby's scoping syntax and rules have also been debated at great length, and changes seem likely in Ruby 2.0 [28].

