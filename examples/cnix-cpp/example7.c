#include <stdio.h>
int 
main (int argc, char *argv[])
{
#ifdef TESTING
  srand (0);
#else
  srand (time (0));
#endif
  printf ("%d\n", rand ());
  return 0;
} // example7
