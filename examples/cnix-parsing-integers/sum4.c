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
#include <limits.h>     // For LONG_MAX and LONG_MIN
#include <ctype.h>      // For isdigit and such.

// +---------+-------------------------------------------------------
// | Helpers |
// +---------+

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
  long val1;
  long val2;
  int err;

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
  if ((err = str2long (argv[1], &val1)) != 0)
    {
      fprintf (stderr, 
               "Error %d: "
               "For parameter one, "
               "expected an integer in the range %ld to %ld, "
               "received '%s'.\n",
               err, LONG_MIN, LONG_MAX, argv[1]);
      return 1;
    }
  if ((err = str2long (argv[2], &val2)) != 0)
    {
      fprintf (stderr, 
               "Error %d: "
               "For parameter two, "
               "expected an integer in the range %ld to %ld, "
               "received '%s'.\n",
               err, LONG_MIN, LONG_MAX, argv[2]);
      return 1;
    }

  // Do the real work
  printf ("%ld\n", val1+val2);

  // And we're done
  return 0;
} // main

