#include "light.h"

c_light
new_light(c_vector pos, c_material_rgb col)
{
    c_light light;
    light.position = pos;
    light.color = col;
    return light;
}
