#include "camera.h"

c_camera 
new_camera(c_vector pos, c_vector dir, c_vector rht, c_vector dwn,
           unsigned int w, unsigned int h)
{
    c_camera c;
    c.position = pos;
    c.direction = dir;
    c.right = rht;
    c.down = dwn;
    c.width = w;
    c.height = h;
    return c;
}
