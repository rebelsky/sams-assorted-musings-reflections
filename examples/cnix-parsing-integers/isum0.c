/**
 * isum.c
 *   Prompt the user for two integers and print their sum.
 *
 * <insert appropriate open source license>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main ()
{
  int val1;
  int val2;

  printf ("Please enter an integer: ");
  fflush (stdout);
  scanf ("%d", &val1);
  printf ("Please enter another integer: ");
  fflush (stdout);
  scanf ("%d", &val2);

  // Do the real work
  printf("%d + %d = %d\n", val1, val2, val1+val2);

  // And we're done
  return 0;
} // main

