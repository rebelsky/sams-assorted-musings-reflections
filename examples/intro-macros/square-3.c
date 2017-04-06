#include <stdio.h>

#define SQUARE(X) (X*X)

int
square (int x)
{
  return x*x;
} // square

int 
main (int argc, char *argv[])
{
  printf ("square(617.312) is %lf\n", (double) square(617.312));
  printf ("SQUARE(617.312) is %lf\n", SQUARE(617.312));
  return 0;
} // main
