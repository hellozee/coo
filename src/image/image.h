#ifndef IMAGE_H
#define IMAGE_H

#include "color.h"

#include <stdio.h>
#include <math.h>

void save_image(const char *file_name, 
                unsigned int width, unsigned int height, int dpi, c_rgb *data);

#endif
