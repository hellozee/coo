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
    double a = 1; //normalized
    double b = (ray.origin.x - sphere->position.x) * ray.direction.x +
            (ray.origin.y - sphere->position.y) * ray.direction.y +
            (ray.origin.z - sphere->position.z) * ray.direction.z;
    b *= 2;

    double c = pow(ray.origin.x - sphere->position.x, 2) +
            pow(ray.origin.y - sphere->position.y, 2) +
            pow(ray.origin.z - sphere->position.z, 2) - pow(sphere->radius, 2);

    double discriminant = b*b - 4*a*c;

    if( discriminant > 0 ){
        double first_root = (-1*b - sqrt(discriminant))/2*a;
        double second_root = (-1*b + sqrt(discriminant))/2*a;
        if(first_root > 0){
            return first_root;
        }else{
            return second_root;
        }
    }
    return -1;
}

