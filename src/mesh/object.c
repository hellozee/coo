#include "object.h"

bool
fequal(double a, double b)
{
    return fabs(a-b) < EPSILON;
}
