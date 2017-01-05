#include <assert.h>

void
join (char *name, char *fname, char *lname)
{
  // Check expectations
  assert (name != NULL);
  assert (fname != NULL);
  assert (lname != NULL);
  assert (name != fname);
  assert (name != lname);
  // Do the first step
  strncpy (name, fname, MAX_STR);
  // Make sure it worked
  assert (strncmp (name, fname, MAXSTR) == 0);
  // Do the remaining work
  strcat (name, " ");
  strncat (name, lname, MAX_STR);
} // join
