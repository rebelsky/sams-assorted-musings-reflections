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
#include <limits.h>
#include "mathlib.h"
#include <ctype.h>      // For isdigit and such.
#include <stdio.h>

// +-----------+-----------------------------------------------------
// | Utilities |
// +-----------+

/**
 * Convert a digit to an integer.  Does not do any sanity checking!
 */
int
convertDigit (char digit)
{
  return digit - '0';
} // convertDigit

/**
 * Convert a string to a long, which it stores in *lp.  
 *
 * Returns 
 *   0, upon success
 *   1, if presented with the empty string
 *   2, if the string includes non-digit characters other than initial 
 *      whitespace
 *   3, if the string represents a value outside the bounds of longs
 *   4, for other errors
 */
int
str2long (char *str, long *lp)
{
  long result = 0;
  long sign = 1;

  // Skip over whitespace
  while ((*str != '\0') && (isspace (*str)))
    str++;

  // Check for the sign
  if (*str == '-') 
    {
      str++;
      sign = -1;
    }
  else if (*str == '+')
    {
      str++;
    }

  // Sanity check
  if (!*str)
    return 1;

  // Read all of the digits
  while (isdigit (*str)) 
    {
      long increment = sign * convertDigit (*str);
      // Upper-bound check
      if ((sign == 1) && (result > (LONG_MAX - increment) / 10))
        return 3;
      // Lower-bound check
      if ((sign == -1) && (result < (LONG_MIN - increment) / 10))
        return 3;
      // Update the result
      result = result*10 + increment;
      // And move on to the next character
      str++;
    } // while

  // Sanity check
  if (*str != '\0')
    return 2;

  // I think that's it.
  *lp = result;
  return 0;
} // str2long

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
  for (int i = 1; i < argc; i++) 
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
