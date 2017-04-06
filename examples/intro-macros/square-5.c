#include <stdio.h>

#define SQUARE(X) ((X)*(X))

int
square (int x)
{
  return x*x;
} // square

int 
main (int argc, char *argv[])
{
  printf ("square(3+5) is %d\n", square(3+5));
  printf ("SQUARE(3+5) is %d\n", SQUARE(3+5));
  return 0;
} // main
