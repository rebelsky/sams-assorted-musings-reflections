/**
 * sum.c
 *   Compute the sum of two values entered on the command line.
 *
 * <insert appropriate open source license>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>      // For printf and fprintf
#include <stdlib.h>     // For scanf
#include <limits.h>     // For INT_MAX and INT_MIN

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Convert a string to an integer, which it stores in *ip.  Returns 1 if 
 * it succeeds and 0 otherwise.
 */
int
str2int (char *str, int *ip)
{
  char *extra;
  long result = strtol (str, &extra, 10);
  if (*extra != '\0')
    return 0;
  if (result < INT_MIN)
    return 0;
  if (result > INT_MAX)
    return 0;
  *ip = (int) result;
  return 1;
} // str2int

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
  int val1;
  int val2;

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
  if (! str2int (argv[1], &val1))
    {
      fprintf (stderr, 
               "For parameter one, expected an integer, received '%s'.\n",
               argv[1]);
      return 1;
    }
  if (! str2int (argv[2], &val2))
    {
      fprintf (stderr, 
               "For parameter two, expected an integer, received '%s'.\n",
               argv[2]);
      return 1;
    }

  // Do the real work
  printf ("%d\n", val1+val2);

  // And we're done
  return 0;
} // main

