/**
 * expt1
 *   A simple experiment with pointers and dereferences.
 *
 * <insert FOSS license>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <malloc.h>

// +-----------+-----------------------------------------------------
// | Constants |
// +-----------+

// The longest string length
#define MAXLEN 32

// +------+----------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  char *ptr = malloc (MAXLEN);
  printf ("Assigning to element 0 of %p ... ", ptr);
  *ptr = 'a';
  printf ("done\n");
  return 0;
} // main
