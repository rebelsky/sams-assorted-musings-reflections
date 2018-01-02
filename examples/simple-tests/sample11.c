#include <stdio.h>

#ifdef NOTEST
#define __TESTING__ 0
#else
#define __TESTING__ 1
#endif

#ifdef FOO
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  do \
    { \
      if (__TESTING__) \
        { \
          int expected = EXPECTED;
          int actual = ACTUAL;
          if (expected != actual) \
            { \
              fprintf (stderr, \
                       "%s, line %d: For '%s', expected %d, got %d\n", \
                       __FILE__, __LINE__, #ACTUAL, expected, actual); \
            } \
        } \
    } \
  while (0)
#else
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  do \
    { \
      if (__TESTING__) \
        { \
          if (EXPECTED != ACTUAL) \
            { \
              fprintf (stderr, \
                       "%s, line %d: For '%s', expected %d, got %d\n", \
                       __FILE__, __LINE__, #ACTUAL, EXPECTED, ACTUAL); \
            } \
        } \
    } \
  while (0)
#endif

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
  int x = 0;
  CHECK_EQUAL_INT (1, x++);
  CHECK_EQUAL_INT (1, x);

  return 0;
} // main
