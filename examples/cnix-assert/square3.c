/**
 * square.c
 *   A simple exploration of the joy of squaring.
 */

#include <assert.h>
#include <math.h>

long 
square (long x)
{
  return x*x;
} // square

int
main (int argc, char *argv[])
{
  assert (square (1) == 1);
  assert (square (-1) == 1);
  assert (square (10) == 100);
  assert (square (-15) == 225);
  assert (square (2147483647L) == 2147483647L*2147483647L);
  assert (square (-2147483648L) == 2147483648L*2147483648L);

  return 0;
} // main

