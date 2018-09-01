#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "math/vector.h"
#include "math/ray.h"
#include "image/image.h"
#include "image/color.h"
#include "camera/camera.h"
#include "camera/light.h"
#include "mesh/sphere.h"
#include "mesh/plane.h"

int
main()
{
    printf("rendering..\n");

    int dpi = 72;
    unsigned int height = 360;
    unsigned int width = 480;

    double aspect_ratio = (double) width/ (double) height;

    c_rgb *pixels = (c_rgb*) malloc(sizeof(c_rgb) * height * width);
    
    c_vector i_cap = new_vector(1,0,0);
    c_vector j_cap = new_vector(0,1,0);
    c_vector k_cap = new_vector(0,0,1);

    c_vector camera_position = new_vector(3,1.5,-2);
    c_vector look_at = new_vector(0,0,0);
    c_vector diff_btw = new_vector(camera_position.x - look_at.x,
                                   camera_position.y - look_at.y,
                                   camera_position.z - look_at.z);

    c_vector camera_direction = vector_normalize(vector_negate(diff_btw));
    c_vector camera_right = vector_normalize(
                vector_cross_product(j_cap,camera_direction));
    c_vector camera_down = vector_cross_product(camera_right,camera_direction);

    c_camera scene_camera = new_camera(camera_position,camera_direction,
                                       camera_right,camera_down);

    c_material_rgb flat_white = new_material_rgb_color(1.0,1.0,1.0,0);
    c_material_rgb glossy_green = new_material_rgb_color(0.5,1.0,0.5,0.3);
    c_material_rgb flat_gray = new_material_rgb_color(0.5,0.5,0.5,0);
    c_material_rgb flat_black = new_material_rgb_color(0,0,0,0);
    c_material_rgb flat_maroon = new_material_rgb_color(0.5,0.25,0.25,0);

    c_vector light_position = new_vector(-7,10,-10);
    c_light scene_light = new_light(light_position,flat_white);

    c_vector sphere_position = new_vector(0,0,0);
    c_sphere *scene_sphere = new_sphere(sphere_position,1.0,glossy_green);

    c_plane *scene_plane = new_plane(j_cap,-1,flat_maroon);

    unsigned int scene_object_count = 2;
    void* scene_objects[] = {
        scene_sphere,
        scene_plane
    };

    double x_amount, y_amount;

    for(unsigned int i=0;i<width;i++){
        for(unsigned int j=0;j<height;j++){

            if(width > height){
                x_amount = (i + 0.5)/width * aspect_ratio -
                            ((width - height)/(double) height)/2;
                y_amount = ((height - j) + 0.5)/height;
            }else if(width < height){
                x_amount = (i + 0.5)/width;
                y_amount = (((height - j) + 0.5)/height)/aspect_ratio -
                            ((height - width)/(double) width)/2;
            }else{
                x_amount = (i + 0.5)/width;
                y_amount = ((height - j) + 0.5)/height;
            }

            c_vector right_scalar_product = vector_scalar_product(x_amount - 0.5,
                                                                  scene_camera.right);
            c_vector down_scalar_product = vector_scalar_product(y_amount - 0.5,
                                                                 scene_camera.down);
            c_vector camera_ray_direction = vector_add(scene_camera.direction,
                        vector_add(right_scalar_product,down_scalar_product));

            c_ray camera_ray = new_ray(scene_camera.position,camera_ray_direction);
            double *intersections = malloc(sizeof (double) * scene_object_count);

            for(unsigned int k=0; k<scene_object_count;k++){
                c_object *obj = (c_object*) scene_objects[k];

                switch (obj->type) {
                case plane:{
                    c_plane* p = (c_plane*) scene_objects[k];
                    intersections[k] = plane_find_intersection(camera_ray,p);
                    break;
                }
                case sphere:{
                    c_sphere* s = (c_sphere*) scene_objects[k];
                    intersections[k] = sphere_find_intersection(camera_ray,s);
                    break;
                }
                }
            }

            pixels[j*width + i] = flat_maroon.color;
        }
    }

    save_image("test.bmp",width,height,dpi,pixels);
    return 0;
}
