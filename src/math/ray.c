#include "ray.h"

Ray new_ray(Vector orig, Vector dir){
    Ray r;
    r.direction = dir;
    r.origin = orig;
    return r;
}
