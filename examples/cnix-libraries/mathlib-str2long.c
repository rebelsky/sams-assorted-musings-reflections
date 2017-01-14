/**
 * mathlib-str2long.c
 *   A string parsing routine for mathlib.
 *
 * <Insert appropriate open-source license.>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <limits.h>
#include <ctype.h>      // For isdigit and such.
#include "mathlib.h"

// +---------------+-------------------------------------------------
// | Local Helpers |
// +---------------+

/**
 * Convert a digit to an integer.  Does not do any sanity checking!
 */
int
convertDigit (char digit)
{
  return digit - '0';
} // convertDigit

// +---------------------+-------------------------------------------
// | Exported Procedures |
// +---------------------+

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

