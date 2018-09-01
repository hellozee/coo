/**
  coo
  tracer.h
  Purpose : Provide prototype of the scene class and its methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/

#ifndef COO_RENDERER_H
#define COO_RENDERER_H

#include <limits.h>

#include "../math/vector.h"
#include "../math/ray.h"
#include "../image/image.h"
#include "../image/color.h"
#include "../camera/camera.h"
#include "../camera/light.h"
#include "../mesh/sphere.h"
#include "../mesh/plane.h"

struct c_scene;

typedef struct c_scene c_scene;

c_scene* new_scene(void **objects, unsigned int object_count, c_light *lights,
                     unsigned int light_count, c_camera camera);

c_rgb* render_scene(c_scene *scene);

#endif
