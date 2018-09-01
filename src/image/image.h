/**
  coo
  image.h
  Purpose : Provide definitions for manipulating bitmaps

  @author Kuntal Majumder ( zee at hellozee dot me )
**/

#ifndef COO_IMAGE_H
#define COO_IMAGE_H

#include "color.h"

#include <stdio.h>
#include <math.h>

void save_image(const char *file_name, 
                unsigned int width, unsigned int height, int dpi, c_rgb *data);

#endif
