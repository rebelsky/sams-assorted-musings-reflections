/**
 * jessie2.c
 *   Jessie's continued experiments with the twice function.  What
 *   is going wrong?  And why does Jamie say it works okay?
 */
 
#include <stdio.h>     // A quick and dirty test.

int
main (int argc, char *argv[])
{
  fprintf (stderr, "twice(1) is %lf\n", twice (1));
  fprintf (stderr, "twice(2) is %lf\n", twice (2));
  fprintf (stderr, "twice(3) is %lf\n", twice (3));
  fprintf (stderr, "twice(5) is %lf\n", twice (5));
  fprintf (stderr, "twice(6.0) is %lf\n", twice (6.0));
  fprintf (stderr, "twice(-1) is %lf\n", twice (-1));
  fprintf (stderr, "twice(-5) is %lf\n", twice (-5));
  return 0;
} // main
