#include <stdio.h>

#define TWICE(X) X+X

int twice(x)
{
  return x+x;
}

int
main (int argc, char *argv[])
{
  printf ("TWICE(3) is %d\n", TWICE(3));
  printf ("twice(3) is %d\n", twice(3));
  return 0;
} // main
