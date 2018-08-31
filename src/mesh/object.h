#ifndef OBJECT_H
#define OBJECT_H

#include "../math/ray.h"

typedef struct{
}c_object;

double object_find_intersection(const c_object *obj, c_ray ray);

#endif
