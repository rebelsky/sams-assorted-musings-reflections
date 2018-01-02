#include <stdio.h>

#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  if (EXPECTED != ACTUAL) \
    { \
      fprintf (stderr, \
               "%s, line %d: For '%s', expected %d, got %d\n", \
               __FILE__, __LINE__, #ACTUAL, EXPECTED, ACTUAL); \
    }

/**
 * Find the multiple of ten closest to n.
 */
int
nmo10 (int n)
{
  if ((n % 10) < 5)
    return n - (n % 10);
  else
    return 10 + n - (n % 10);
} // nmo10

int
main (int argc, char *argv[])
{ 
  CHECK_EQUAL_INT (0, nmo10 (0));
  CHECK_EQUAL_INT (0, nmo10 (3));
  CHECK_EQUAL_INT (10, nmo10 (9));
  CHECK_EQUAL_INT (10, nmo10 (12));
  CHECK_EQUAL_INT (20, nmo10 (18));
  CHECK_EQUAL_INT (20, nmo10 (22));
  CHECK_EQUAL_INT (1000, nmo10 (998));
  CHECK_EQUAL_INT (1000, nmo10 (1000));
  CHECK_EQUAL_INT (1000, nmo10 (1005));
  return 0;
} // main
