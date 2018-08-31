#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "math/vector.h"
#include "math/ray.h"
#include "image/image.h"
#include "image/color.h"
#include "camera/camera.h"
#include "camera/light.h"

int main()
{
    printf("rendering..\n");

    int dpi = 72;
    int height = 600;
    int width = 800;

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

    c_vector light_position = new_vector(-7,10,-10);
    c_light scene_light = new_light(light_position,flat_white);

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            pixels[j*width + i].r = 1.0;
            pixels[j*width + i].g = 0.5;
            pixels[j*width + i].b = 0.5;
        }
    }

    save_image("test.bmp",width,height,dpi,pixels);
    return 0;
}
