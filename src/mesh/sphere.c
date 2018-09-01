#include "sphere.h"

c_sphere *new_sphere(c_vector pos, double rad, c_material_rgb col)
{
    c_sphere *s = malloc(sizeof (c_sphere));
    s->color = col;
    s->position = pos;
    s->radius = rad;
    s->object.type = sphere;
    return s;
}

c_vector
sphere_normal_at(c_vector point, c_sphere *sphere)
{
    c_vector normal = vector_add(point, vector_negate(sphere->position));
    normal = vector_normalize(normal);
    return normal;
}

double
sphere_find_intersection(c_ray ray, c_sphere *sphere)
{
    double a = 1; //normalized
    double b = (ray.origin.x - sphere->position.x) * ray.direction.x +
               (ray.origin.y - sphere->position.y) * ray.direction.y +
               (ray.origin.z - sphere->position.z) * ray.direction.z;
    b *= 2;

    return 0;
}

