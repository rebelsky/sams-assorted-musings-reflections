/**
 * mathlib.h
 *   A simple library of math utilities.
 *
 * <Insert appropriate open-source license.>
 */

#ifndef __MATHLIB_H__
#define __MATHLIB_H__

// +------------+----------------------------------------------------
// | Procedures |
// +------------+

/**
 * Compute the greatest common divisor of two positive integers.
 */
extern int gcd(int x, int y);

/**
 * Convert a string to a long, which it stores in *lp.  
 *
 * Returns 
 *   0, upon success
 *   1, if presented with the empty string
 *   2, if the string includes non-digit characters other than initial 
 *      whitespace
 *   3, if the string represents a value outside the bounds of longs
 *   4, for other errors
 */
extern int str2long (char *str, long *lp);

#endif // __MATHLIB_H__
