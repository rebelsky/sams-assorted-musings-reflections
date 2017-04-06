#include <stdio.h>

#define TWICE(X) (X+X)

int twice(x)
{
  return x+x;
}

int
main (int argc, char *argv[])
{
  printf ("4*TWICE(3) is %d\n", 4*TWICE(3));
  printf ("4*twice(3) is %d\n", 4*twice(3));
  return 0;
} // main
