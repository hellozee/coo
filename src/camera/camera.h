#ifndef C_CAMERA_H
#define C_CAMERA_H

#include "../math/vector.h"

typedef struct{
    c_vector position, direction, right, down;
}c_camera;

c_camera new_camera(c_vector pos, c_vector dir, c_vector rht, c_vector dwn);

#endif
