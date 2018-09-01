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
