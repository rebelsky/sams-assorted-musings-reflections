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
  printf ("SQUARE(5) is %d\n", SQUARE(5));
  printf ("square(5) is %d\n", square(5));
  return 0;
} // main
