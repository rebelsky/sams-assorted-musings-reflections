/**
 * jessie2b.c
 *   Jessie's continued experiments with the twice function.  It keeps
 *   returning 0, but the code makes it look correct.  The mentors have
 *   not been able to figure it out.  Jamie told me to put in a useless 
 *   #include.  But that shouldn't make any difference.  However, I've 
 *   tried everything else.  
 */

#include "utils.h"     // Jamie, this is pointless!
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
