#include "ray.h"

c_ray 
new_ray(c_vector orig, c_vector dir)
{
    c_ray r;
    //direction is always an unit vector
    dir = vector_normalize(dir);
    r.direction = dir;
    r.origin = orig;
    return r;
}
