/**
  coo
  color.h
  Purpose : Provide prototypes of the various color classes and their methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/

#ifndef COO_COLOR_H
#define COO_COLOR_H

typedef struct{
    union{
        double val[3];
    };
    double r,g,b;
}c_rgb;

c_rgb new_rgb_color(double red, double green, double blue);

typedef struct{
    c_rgb color;
    double specular;
}c_material_rgb;

static const c_material_rgb flat_white = {{1.0,1.0,1.0},0.0};
static const c_material_rgb flat_gray  = {{0.5,0.5,0.5},0.0};
static const c_material_rgb flat_black = {{0.0,0.0,0.0},0.0};

c_material_rgb new_material_rgb_color(double red, double green, double blue,
                                      double spec);
double color_brightness(c_material_rgb col);
c_material_rgb color_multiply_scalar(double factor, c_material_rgb col);
c_material_rgb color_add(c_material_rgb c1, c_material_rgb c2);
c_material_rgb color_multipy(c_material_rgb c1, c_material_rgb c2);
c_material_rgb color_average(c_material_rgb c1, c_material_rgb c2);
#endif

