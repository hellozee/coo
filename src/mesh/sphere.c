#include "sphere.h"

c_sphere
new_sphere(c_vector pos, double rad, c_material_rgb col)
{
    c_sphere s;
    s.color = col;
    s.position = pos;
    s.radius = rad;
    s.object.type = sphere;
    return s;
}
