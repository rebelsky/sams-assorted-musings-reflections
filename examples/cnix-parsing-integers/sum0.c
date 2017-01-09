/**
 * sum.c
 *   Compute the sum of two values entered on the command line.
 *
 * <insert appropriate open source license>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <stdlib.h>

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Report on usage.
 */
void
usage ()
{
  fprintf (stderr, "Usage: sum INT1 INT2\n");
} // usage

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  // Sanity check
  if (argc != 3)
    {
      fprintf (stderr,
               "Incorrect number of parameters: Expected 2 params, got %d\n",
               argc - 1);
      usage ();
      return 1;
    }

  // Convert to integers
  int val1 = atoi (argv[1]);
  int val2 = atoi (argv[2]);

  // Do the real work
  printf ("%d\n", val1+val2);

  // And we're done
  return 0;
} // main

