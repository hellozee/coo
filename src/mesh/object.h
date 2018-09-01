#ifndef COO_OBJECT_H
#define COO_OBJECT_H

#define EPSILON 1e-6

#include "../math/ray.h"

#include <stdbool.h>
#include <stdlib.h>

enum c_object_type{
    sphere = 0,
    plane
};

typedef struct{
    enum c_object_type type;
}c_object;

bool fequal(double a, double b);

#endif
