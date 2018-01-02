#include <stdio.h>
#include <assert.h>

#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  if (EXPECTED != ACTUAL) \
    { \
      fprintf (stderr, "For %s, expected %d, got %d\n", #ACTUAL, EXPECTED, ACTUAL); \
    }

/**
 * Find the multiple of ten closest to n.
 */
int
nmo10 (int n)
{
  return n - (n % 10);
}

int
main (int argc, char *argv[])
{ 
  assert (0 == nmo10 (3));
  assert (10 == nmo10 (12));
  assert (20 == nmo10 (18));
  assert (20 == nmo10 (22));
  return 0;
} // main
