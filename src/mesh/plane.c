/**
  coo
  sphere.c
  Purpose : Provide definitions of the plane class and its methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/

#include "plane.h"

/**
 * @brief new_plane creates a new plane object returns the pointer to it
 * @param norm
 * @param dist
 * @param col
 * @return
 */
c_plane
*new_plane(c_vector norm, double dist, c_material_rgb col)
{
    c_plane *p = malloc(sizeof (c_plane));
    p->normal = norm;
    p->distance = dist;
    p->color = col;
    p->object.type = plane;
    return p;
}

/**
 * @brief plane_find_intersection calculates whethere the ray intersects with
 * the plane or not
 * @param ray
 * @param plane
 * @return
 */
double
plane_find_intersection(c_ray ray, c_plane *plane)
{
    double does_intersect = vector_dot_product(ray.direction,plane->normal);

    if(fequal(does_intersect,0)){
        //ray is parallel
        return -1;
    }

    c_vector scalar_product = vector_negate(
                vector_scalar_product(plane->distance,plane->normal));
    double dot_product = vector_dot_product(
                plane->normal,vector_add(ray.origin,scalar_product));

    return -1 * dot_product/does_intersect;
}
