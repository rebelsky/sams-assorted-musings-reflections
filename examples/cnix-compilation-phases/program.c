/**
 * program.c
 *   A sample program.
 */

#include "header.h"

#define X 23
#define DOUBLE(Y) (Y * 2)

int
main (int argc, char *argv[])
{
  printf ("%d,%d\n", DOUBLE(5), foo(DOUBLE(X)));
  return 0;
} // main

int
foo (int x) 
{
  return x * x;
} // foo
