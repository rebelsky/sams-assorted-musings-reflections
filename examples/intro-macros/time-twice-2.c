#include <stdio.h>
#include <sys/time.h>

#define TWICE(X) X+X

int twice(x)
{
  return x+x;
}

#define REPETITIONS 1000000000

#define TIME(LINE) \
  { \
    struct timeval start; \
    struct timeval finish; \
    int i; \
    long elapsed; \
    gettimeofday(&start, NULL); \
    for (i = 0; i < REPETITIONS; i++) \
      { \
        LINE; \
      } \
    printf ("We spent %ld microseconds.\n", elapsed); \
  }

int
main (int argc, char *argv[])
{
  long x;   // For doing pointless computations

  x = 0;
  printf ("Using the macro\n");
  TIME (x += TWICE(3));
  printf ("Our result is %ld.\n\n", x);

  x = 0;
  printf ("Using the procedure\n");
  TIME (x += twice(3));
  printf ("Our result is %ld.\n\n", x);

  return 0;
} // main
