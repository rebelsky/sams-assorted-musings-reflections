#include <stdio.h>

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
  int i;
  for (i = -10; i <= 10; i++) 
    {
      printf ("nmo10(%d) = %d\n", i, nmo10(i));
    }
  return 0;
} // main
