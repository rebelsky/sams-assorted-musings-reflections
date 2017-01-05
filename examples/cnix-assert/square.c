/**
 * square.c
 *   A simple exploration of the joy of squaring.
 */

#include <assert.h>
#include <math.h>

long 
square (long x)
{
  return (long) pow (x, 2);
} // square

int
main (int argc, char *argv[])
{
  assert (square (1) == 1);
  assert (square (-1) == 1);
  assert (square (10) == 100);
  assert (square (-15) == 225);
  return 0;
} // main

