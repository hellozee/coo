#ifndef CAMERA_H
#define CAMERA_H

#include "../math/vector.h"

typedef struct{
    Vector position, direction, right, down;
}Camera;

Camera new_camera(Vector pos, Vector dir, Vector rht, Vector dwn);

#endif
