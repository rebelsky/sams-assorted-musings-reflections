#include <stdio.h>
#include <sys/time.h>

#define TWICE(X) X+X

int twice(x)
{
  return x+x;
}

#define REPETITIONS 1000000000

int
main (int argc, char *argv[])
{
  long x;   // For doing pointless computations
  int i;    // Counter variable for loops

  struct timeval start;         // The start of a computation
  struct timeval finish;         // The end of a computation

  long elapsed;                 // Elapsed time in microseconds

  // Compute how long a lot of calls to TWICE take
  x = 0;
  gettimeofday(&start, NULL);
  for (i = 0; i < REPETITIONS; i++)
    {
      x += TWICE(3);
    }
  gettimeofday(&finish, NULL);
  elapsed = 1000000 * (finish.tv_sec - start.tv_sec)  
          + (finish.tv_usec - start.tv_usec);
  printf ("Using the macro, we spent %ld microseconds.\n", elapsed);
  printf ("Our result is %ld.\n\n", x);

  // Compute how long a lot of calls to TWICE take
  x = 0;
  gettimeofday(&start, NULL);
  for (i = 0; i < REPETITIONS; i++)
    {
      x += twice(3);
    }
  gettimeofday(&finish, NULL);
  elapsed = 1000000 * (finish.tv_sec - start.tv_sec)  
          + (finish.tv_usec - start.tv_usec);
  printf ("Using the procedure, we spent %ld microseconds.\n", elapsed);
  printf ("Our result is %ld.\n\n", x);

  return 0;
} // main
