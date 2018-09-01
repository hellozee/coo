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
c_sphere
*new_sphere(c_vector pos, double rad, c_material_rgb col)
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
    //oc_vector as in origin to center vector
    c_vector oc_vector = vector_add(sphere->position,vector_negate(ray.origin));
    double temp = vector_dot_product(oc_vector,ray.direction);

    c_vector perpendicular = vector_add(ray.origin,
                    vector_scalar_product(temp,ray.direction));

    double perpendicular_length = vector_magnitude(vector_add(
                            sphere->position,vector_negate(perpendicular)));
    if(perpendicular_length > sphere->radius){
        return -1;
    }
    double delta = sqrt(sphere->radius*sphere->radius - pow(perpendicular_length,2));

    double intersection_one = temp - delta;
    double intersection_two = temp + delta;

    if(intersection_one >= 0 && intersection_one < intersection_two){
        return intersection_one;
    }

    if(intersection_two >=0 && intersection_two < intersection_one){
        return intersection_two;
    }

    return -1;
}

