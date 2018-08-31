#ifndef C_SPHERE_H
#define C_SPHERE_H

#include "object.h"
#include "../math/vector.h"
#include "../image/color.h"

typedef struct{
    c_vector position;
    double radius;
    c_material_rgb color;
    c_object object;
}c_sphere;

c_sphere new_sphere(c_vector pos, double rad, c_material_rgb col);

#endif
