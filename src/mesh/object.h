/**
  coo
  object.c
  Purpose : Provide prototype of the object class and its methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/

#ifndef COO_OBJECT_H
#define COO_OBJECT_H

#define EPSILON 1e-6

#include "../math/ray.h"

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief The c_object_type enum useful for determining the type of the child objects
 */
enum c_object_type{
    sphere = 0,
    plane
};

typedef struct{
    enum c_object_type type;
}c_object;

bool fequal(double a, double b);

#endif
