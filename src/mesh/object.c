/**
  coo
  object.c
  Purpose : Provide definitions of the object class and its methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/

#include "object.h"

/**
 * @brief fequal calculates whether the floating point numbers are equal or not
 * @param a
 * @param b
 * @return
 */
bool
fequal(double a, double b)
{
    return fabs(a-b) < EPSILON;
}
