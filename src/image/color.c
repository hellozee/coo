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

/**
 * @brief color_brightness returns the grayscaled version of the current color
 * @param col
 * @return
 */
double
color_brightness(c_material_rgb col)
{
    return (col.color.b + col.color.g + col.color.r)/3;
}

/**
 * @brief cap_value keeps the color values from overflowing or underflowing
 * @param col
 * @return
 */
c_material_rgb
color_cap_value(c_material_rgb col)
{
    if(col.color.r > 1) col.color.r = 1;
    if(col.color.g > 1) col.color.g = 1;
    if(col.color.b > 1) col.color.b = 1;
    if(col.specular > 1) col.specular = 1;
    if(col.color.r < 0) col.color.r = 0;
    if(col.color.g < 0) col.color.g = 0;
    if(col.color.b < 0) col.color.b = 0;
    if(col.specular < 0) col.specular = 0;
    return col;
}

/**
 * @brief color_multiply_scalar multiplies the color with a scalar factor
 * @param factor
 * @param col
 * @return
 */
c_material_rgb
color_multiply_scalar(double factor, c_material_rgb col)
{
    c_material_rgb return_color = new_material_rgb_color(col.color.r * factor,
                                                         col.color.g * factor,
                                                         col.color.b * factor ,
                                                         col.specular);
    return return_color;
}

/**
 * @brief color_add adds 2 colors
 * @param c1
 * @param c2
 * @return
 */
c_material_rgb
color_add(c_material_rgb c1, c_material_rgb c2)
{
    c_material_rgb return_color = new_material_rgb_color(c1.color.r + c2.color.r,
                                                         c1.color.g + c2.color.g,
                                                         c1.color.b + c2.color.b ,
                                                         c1.specular + c2.specular);
    return return_color;
}

/**
 * @brief color_multipy multiplies 2 colors
 * @param c1
 * @param c2
 * @return
 */
c_material_rgb
color_multipy(c_material_rgb c1, c_material_rgb c2)
{
    c_material_rgb return_color = new_material_rgb_color(c1.color.r * c2.color.r,
                                                         c1.color.g * c2.color.g,
                                                         c1.color.b * c2.color.b,
                                                         c1.specular * c2.specular);
    return return_color;
}

/**
 * @brief color_average returns the average of 2 colors
 * @param c1
 * @param c2
 * @return
 */
c_material_rgb
color_average(c_material_rgb c1, c_material_rgb c2)
{
    return new_material_rgb_color((c1.color.r + c2.color.r)/2,
                                  (c1.color.g + c2.color.g)/2,
                                  (c1.color.b + c2.color.b)/2,
                                  (c1.specular + c2.specular)/2);
}
