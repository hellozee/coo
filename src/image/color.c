/**
  coo
  color.c
  Purpose : Provide definitions of the various color classes and their methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/

#include "color.h"

/**
 * @brief new_rgb_color creates a new RGB color object returns it
 * @param red
 * @param green
 * @param blue
 * @return
 */
c_rgb
new_rgb_color(double red, double green, double blue)
{
    c_rgb col;
    col.r = red;
    col.g = green;
    col.b = blue;
    return col;
}

/**
 * @brief new_material_rgb_color creates a new RGB material object returns it
 * @param red
 * @param green
 * @param blue
 * @param spec
 * @return
 */
c_material_rgb
new_material_rgb_color(double red, double green, double blue, double spec)
{
    c_material_rgb col;
    col.color = new_rgb_color(red,green,blue);
    col.specular = spec;
    return col;
}

double
color_brightness(c_material_rgb col)
{
    return (col.color.b + col.color.g + col.color.r)/3;
}

double cap_value(double val)
{
    if (val > 1){
        return 1;
    }
    if(val < 0){
        return 0;
    }
    return val;
}

c_material_rgb
color_multiply_scalar(double factor, c_material_rgb col)
{
    return new_material_rgb_color(cap_value(col.color.r * factor),
                                  cap_value(col.color.g * factor),
                                  cap_value(col.color.b * factor) ,col.specular);
}

c_material_rgb
color_add(c_material_rgb c1, c_material_rgb c2)
{
    return new_material_rgb_color(cap_value(c1.color.r + c2.color.r),
                                  cap_value(c1.color.g + c2.color.g),
                                  cap_value(c1.color.b + c2.color.b) ,
                                  cap_value(c1.specular + c2.specular));
}

c_material_rgb
color_multipy(c_material_rgb c1, c_material_rgb c2)
{
    return new_material_rgb_color(cap_value(c1.color.r * c2.color.r),
                                  cap_value(c1.color.g * c2.color.g),
                                  cap_value(c1.color.b * c2.color.b),
                                  cap_value(c1.specular * c2.specular));
}

c_material_rgb
color_average(c_material_rgb c1, c_material_rgb c2)
{
    return new_material_rgb_color((c1.color.r + c2.color.r)/2,
                                  (c1.color.g + c2.color.g)/2,
                                  (c1.color.b + c2.color.b)/2,
                                  (c1.specular + c2.specular)/2);
}
