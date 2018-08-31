#ifndef COLOR_H
#define COLOR_H

typedef struct{
    double r,g,b;
}c_rgb;

c_rgb new_rgb_color(double red, double green, double blue);

typedef struct{
    double r,g,b,s;
}c_material_rgb;

c_material_rgb new_material_rgb_color(double red, double green, double blue, double spec);

#endif
