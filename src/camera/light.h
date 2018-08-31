#ifndef C_LIGHT_H
#define C_LIGHT_H

#include "../math/vector.h"
#include "../image/color.h"

typedef struct{
    c_vector position;
    c_material_rgb color;
}c_light;

c_light new_light(c_vector pos, c_material_rgb col);

#endif
