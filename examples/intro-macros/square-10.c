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
  int a;
  
  a = 2;
  printf ("a is %d\n", a);
  printf ("square(square(a++)) is %d\n", square(square(a++)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("SQUARE(SQUARE(a++)) is %d\n", SQUARE(SQUARE(a++)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("SQUARE(square(a++)) is %d\n", SQUARE(square(a++)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("square(SQUARE(a++)) is %d\n", square(SQUARE(a++)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("SQUARE(square(++a)) is %d\n", SQUARE(square(++a)));
  printf ("a is now %d\n", a);

  a = 2;
  printf ("a is %d\n", a);
  printf ("square(SQUARE(++a)) is %d\n", square(SQUARE(++a)));
  printf ("a is now %d\n", a);

  return 0;
} // main
