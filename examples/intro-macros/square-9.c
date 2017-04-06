#include <stdio.h>

int
square (int x)
{
  return x*x;
} // square

int a;

int 
compute ()
{
  a += 3;
  return a;
}

#define SQUARE(X) ((X)*(X))

int 
main (int argc, char *argv[])
{
  a = 2;
  printf ("square(compute()) is %d\n", square(square(compute())));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("SQUARE(compute()) is %d\n", SQUARE(SQUARE(compute())));
  printf ("a is now %d\n", a);
  return 0;
} // main
