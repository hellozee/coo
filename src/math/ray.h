#ifndef RAY_H
#define RAY_H

#include "vector.h"

typedef struct{
    Vector origin, direction; 
}Ray;

Ray new_ray(Vector orig, Vector dir);

#endif
