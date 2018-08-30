#include "camera.h"

Camera new_camera(Vector pos, Vector dir, Vector rht, Vector dwn){
    Camera c;
    c.position = pos;
    c.direction = dir;
    c.right = rht;
    c.down = dwn;
    return c;
}
