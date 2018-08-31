#ifndef C_RAY_H
#define C_RAY_H

#include "vector.h"

typedef struct{
    c_vector origin, direction; 
}c_ray;

c_ray new_ray(c_vector orig, c_vector dir);

#endif
