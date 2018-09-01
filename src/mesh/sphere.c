/**
  coo
  sphere.c
  Purpose : Provide definitions of the sphere class and its methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/

#include "sphere.h"

/**
 * @brief new_sphere creates a new sphere object returns the pointer to it
 * @param pos
 * @param rad
 * @param col
 * @return
 */
c_sphere *new_sphere(c_vector pos, double rad, c_material_rgb col)
{
    c_sphere *s = malloc(sizeof (c_sphere));
    s->color = col;
    s->position = pos;
    s->radius = rad;
    s->object.type = sphere;
    return s;
}

/**
 * @brief sphere_normal_at calculates the normal at the point over the given sphere
 * @param point
 * @param sphere
 * @return
 */
c_vector
sphere_normal_at(c_vector point, c_sphere *sphere)
{
    c_vector normal = vector_add(point, vector_negate(sphere->position));
    normal = vector_normalize(normal);
    return normal;
}

/**
 * @brief sphere_find_intersection calculates whethere the ray intersects with
 * the sphere or not
 * @param ray
 * @param sphere
 * @return
 */
double
sphere_find_intersection(c_ray ray, c_sphere *sphere)
{                         
    c_vector oc_vector = vector_add(sphere->position,vector_negate(ray.origin));

    c_vector cd_vector = vector_add(ray.origin,vector_scalar_product( vector_dot_product(oc_vector,ray.direction),ray.direction));

    cd_vector = vector_add(sphere->position,vector_negate(cd_vector));

    double r_square = pow(sphere->radius,2);
    double c_square = vector_magnitude(oc_vector);
    double v_square = vector_magnitude(cd_vector);

    double discriminant = r_square - c_square + v_square;

    return -1 * discriminant;
}

