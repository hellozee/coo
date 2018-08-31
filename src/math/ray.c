#include "ray.h"

c_ray 
new_ray(c_vector orig, c_vector dir)
{
    c_ray r;
    r.direction = dir;
    r.origin = orig;
    return r;
}
