#include <stdio.h>

#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  if (EXPECTED != ACTUAL) \
    { \
      fprintf (stderr, "Expected %d, got %d\n", EXPECTED, ACTUAL); \
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
  CHECK_EQUAL_INT(0, nmo10(3));
  CHECK_EQUAL_INT(10, nmo10(12));
  CHECK_EQUAL_INT(20, nmo10(18));
  CHECK_EQUAL_INT(20, nmo10(22));
  return 0;
} // main
