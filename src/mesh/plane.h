/**
  coo
  object.c
  Purpose : Provide prototype of the plane class and its methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/
#ifndef COO_PLANE_H
#define COO_PLANE_H

#include "object.h"
#include "../math/vector.h"
#include "../image/color.h"
#include "../math/ray.h"

typedef struct{
    c_object object;
    c_vector normal;
    double distance;
    c_material_rgb color;
}c_plane;

c_plane *new_plane(c_vector norm, double dist, c_material_rgb col);
double plane_find_intersection(c_ray ray, c_plane *plane);

#endif
