#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <math.h>

typedef struct{
    double r,g,b;
}c_rgb;

void save_image(const char *file_name, 
                int width, int height, int dpi, c_rgb *data);

#endif
