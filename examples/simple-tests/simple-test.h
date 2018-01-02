#ifndef _SIMPLE_TEST_H_
#define _SIMPLE_TEST_H_

/**
 * simple-test.h
 *
 * A collection of macros that permit very simple testing.
 *
 * <insert FLOSS license>
 */

// +--------------+--------------------------------------------------
// | Design Notes |
// +--------------+

/*

 */

// +--------+--------------------------------------------------------
// | Macros |
// +--------+

#ifdef TEST
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) \
  do \
    {  \
      int expected = EXPECTED; \
      int actual = ACTUAL; \
      if (expected != actual) \
        { \
          fprintf (stderr, "For '%s', expected %d, got %d\n", \
                   #ACTUAL, expected, actual); \
        } \
    } \
  while (0)

#else
#define CHECK_EQUAL_INT(EXPECTED, ACTUAL) do { } while (0)
#endif

#endif // _SIMPLE_TEST_H_
