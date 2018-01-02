// Use stacks of ints
#undef TYPE
#undef TYPED
#define TYPE int 
#define TYPED(THING) i_ ## THING
#include "generic-stack.h"
// Use stacks of doubles
#undef TYPE
#undef TYPED
#define TYPE double
#define TYPED(THING) d_ ## THING
#include "generic-stack.h"
// Use stacks of strings
#undef TYPE
#undef TYPED
#define TYPE char *
#define TYPED(THING) str_ ## THING
#include "generic-stack.h"

