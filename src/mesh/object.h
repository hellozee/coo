#ifndef C_OBJECT_H
#define C_OBJECT_H

#define EPSILON 1e-6

#include "../math/ray.h"
#include <stdbool.h>

enum c_object_type{
    sphere,
    plane
};

typedef struct{
    enum c_object_type type;
}c_object;

bool fequal(double a, double b);

#endif
