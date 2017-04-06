#include <stdio.h>

#define TWICE(X) X+X

int twice(x)
{
  return x+x;
}

int
main (int argc, char *argv[])
{
  int x = 5;
  printf ("TWICE(x+3) is %d\n", TWICE(x+3));
  printf ("twice(x+3) is %d\n", twice(x+3));
  return 0;
} // main
