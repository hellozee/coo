#ifndef SPHERE_H
#define SPHERE_H

#include "../math/vector.h"
#include "../image/color.h"

typedef struct{
    c_vector position;
    double radius;
    c_material_rgb color;
}c_sphere;

c_sphere new_sphere(c_vector pos, double rad, c_material_rgb col);

#endif
