/**
  coo
  object.c
  Purpose : Provide prototype of the sphere class and its methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/
#ifndef COO_SPHERE_H
#define COO_SPHERE_H

#include "object.h"
#include "../math/vector.h"
#include "../image/color.h"

typedef struct{
    c_object object;
    c_vector position;
    double radius;
    c_material_rgb color;
}c_sphere;

c_sphere *new_sphere(c_vector pos, double rad, c_material_rgb col);
c_vector sphere_normal_at(c_vector point, c_sphere *sphere);
double sphere_find_intersection(c_ray ray, c_sphere *sphere);

#endif
