/**
 * jamie.c
 *   Jamie's quick experiment with the twice function.  Twice 5 is 10.
 */
 
#include "utils.h"      // Shared utilities, including twice
#include <assert.h>     // A quick and dirty test.

int
main (int argc, char *argv[])
{
  assert (twice (5) == 10);
  return 0;
} // main
