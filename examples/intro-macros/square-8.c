#include <stdio.h>

int
square (int x)
{
  return x*x;
} // square

#define SQUARE(X) ((X)*(X))

int 
main (int argc, char *argv[])
{
  int a = 2;
  int b = 2;
  printf ("square(a+=1) is %d\n", square(a+=1));
  printf ("a is now %d\n", a);
  printf ("SQUARE(b+=1) is %d\n", SQUARE(b+=1));
  printf ("b is now %d\n", b);
  return 0;
} // main
