#ifndef COO_CAMERA_H
#define COO_CAMERA_H

#include "../math/vector.h"

typedef struct{
    c_vector position, direction, right, down;
    unsigned int width, height;
}c_camera;

c_camera new_camera(c_vector pos, c_vector dir, c_vector rht, c_vector dwn,
                    unsigned int w, unsigned int h);

#endif
