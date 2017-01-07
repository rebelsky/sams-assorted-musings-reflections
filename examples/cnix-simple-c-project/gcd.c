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

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  // Identical numbers
  assert (gcd (5, 5) == 5);
  assert (gcd (11, 11) == 11);
  assert (gcd (24, 24) == 24);

  // Some "obvious" answers
  assert (gcd (6, 3) == 3);
  assert (gcd (3, 6) == 3);
  assert (gcd (21, 6) == 3);
  assert (gcd (6, 21) == 3);
  assert (gcd (10, 25) == 5);
  assert (gcd (5, 25) == 5);
  assert (gcd (50, 70) == 10);
  assert (gcd (70, 50) == 10);

  // Relatively prime
  assert (gcd (10, 9) == 1);
  assert (gcd (9, 10) == 1);
  assert (gcd (502, 9) == 1);
  assert (gcd (9, 205) == 1);

  // One of the parameters is 1.
  assert (gcd (1, 1) == 1);
  assert (gcd (1, 5) == 1);
  assert (gcd (5, 1) == 1);
  assert (gcd (24, 1) == 1);
  assert (gcd (1, 25) == 1);

  // Large integers
  assert (gcd (INT_MAX, INT_MAX) == INT_MAX);
  assert (gcd (3 * (INT_MAX / 3), INT_MAX / 3) == INT_MAX / 3);
  assert (gcd (INT_MAX / 3, 3 * (INT_MAX / 3)) == INT_MAX / 3);
  assert (gcd (5 * (INT_MAX / 5), INT_MAX / 5) == INT_MAX / 5);
  assert (gcd (INT_MAX / 5, 5 * (INT_MAX / 5)) == INT_MAX / 5);
  assert (gcd (14 * (INT_MAX / 14), INT_MAX / 14) == INT_MAX / 14);
  assert (gcd (INT_MAX / 14, 14 * (INT_MAX / 14)) == INT_MAX / 14);
  assert (gcd (311 * (INT_MAX / 311), INT_MAX / 311) == INT_MAX / 311);
  assert (gcd (INT_MAX / 311, 311 * (INT_MAX / 311)) == INT_MAX / 311);

  // Fibonacci
  assert (gcd (21, 13) == 1);
  assert (gcd (13, 21) == 1);
  assert (gcd (63, 39) == 3);
  assert (gcd (39, 63) == 3);
  assert (gcd (55, 34) == 1);
  assert (gcd (34, 55) == 1);
  assert (gcd (550, 340) == 10);

  // And we're done.
  return 0;
} // main
