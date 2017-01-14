/**
 * gcd.c
 *   Compute the gcd of values input on the command line.
 *
 * <Insert appropriate open-source license.>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include "mathlib.h"

// +-----------+-----------------------------------------------------
// | Utilities |
// +-----------+

/**
 * Print out usage information.
 */
void
usage ()
{
  fprintf (stderr, "Usage: gcd int1 int2 int3 ...\n");
} // usage

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int err;      // The result from str2long
  long result;  // The result we've computed so far.
  long newval;  // The next value read.

  if (argc < 2) 
    {
      fprintf (stderr, "Error: No parameters provided.\n");
      usage ();
      return 1;
    }

  // Convert the first parameter.  We don't check for failure because
  // we're going to reconvert the first parameter in a loop below, and
  // we do the error checking there.
  str2long (argv[1], &result);

  // Grab each parameter, in turn, and incorporate it into the GCD.
  int i;
  for (i = 1; i < argc; i++) 
    {
      if (((err = str2long (argv[i], &newval)) != 0) || (newval <= 0))
        {
          fprintf (stderr, 
                   "Error %d: "
                   "For parameter %d, "
                   "expected an integer in the range 1 to %ld, "
                   "received '%s'.\n",
                   err, i, LONG_MAX, argv[i]);
          usage ();
          return 1;
        } // if we fail to parse
      result = gcd (result, newval);
    } // for

  // And we're done.
  printf ("%ld\n", result);
  return 0;
} // main
