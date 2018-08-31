#include "color.h"

c_rgb
new_rgb_color(double red, double green, double blue)
{
    c_rgb col;
    col.r = red;
    col.g = green;
    col.b = blue;
    return col;
}

c_material_rgb
new_material_rgb_color(double red, double green, double blue, double spec)
{
    c_material_rgb col;
    col.r = red;
    col.g = green;
    col.b = blue;
    col.s = spec;
    return col;
}
