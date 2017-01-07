/**
 * mathlib-gcd.c
 *   The greatest-common-divisor procedure for mathlib.
 *
 * <Insert appropriate open-source license.>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "mathlib.h"

// +---------------------+-------------------------------------------
// | Exported Procedures |
// +---------------------+

/**
 * Compute the greatest common divisor of two positive integers.
 */
int 
gcd(int x, int y)
{
  if (y == 0)
    return x;
  else 
    return gcd (y, x % y);
} // gcd
