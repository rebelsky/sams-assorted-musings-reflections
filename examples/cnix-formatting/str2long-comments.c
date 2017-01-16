int
str2long (char *str, long *lp)
{
  long result = 0;              // The computed intermediate result.
  long sign = 1;                // The sign of the value.

  // Skip over whitespace
  while ((*str != '\0') && (isspace (*str)))
    str++;

  // Check for the sign
  if (*str == '-')
    {
      str++;
      sign = -1;
    }
  else if (*str == '+')
    {
      str++;
    }

  // Sanity check
  if (!*str)
    return 1;

  // Read all of the digits
  while (isdigit (*str))
    {
      long increment = sign * convertDigit (*str);
      // Upper-bound check
      if ((sign == 1) && (result > (LONG_MAX - increment) / 10))
        return 3;
      // Lower-bound check
      if ((sign == -1) && (result < (LONG_MIN - increment) / 10))
        return 3;
      // Update the result
      result = result * 10 + increment;
      // And move on to the next character
      str++;
    }                           // while

  // Sanity check
  if (*str != '\0')
    return 2;

  // I think that's it.
  *lp = result;
  return 0;
}                               // str2long
