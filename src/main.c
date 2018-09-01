#include "renderer/tracer.h"

int
main()
{
    printf("rendering..\n");

    int dpi = 72;
    unsigned int height = 360;
    unsigned int width = 480;

    //creating a new camera for our scene
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
                                       camera_right,camera_down, width, height);

    //some dummy materials for the scene
    c_material_rgb glossy_green = new_material_rgb_color(0.5,1.0,0.5,0.3);
    c_material_rgb flat_maroon = new_material_rgb_color(0.5,0.25,0.25,0);

    //scene lights
    c_vector light_position = new_vector(-7,10,-10);
    c_light scene_light = new_light(light_position,flat_white);

    unsigned int scene_light_count = 1;
    c_light scene_lights[] = {scene_light};

    //scene objects
    c_vector sphere_position = new_vector(0,0,0);
    c_sphere *scene_sphere = new_sphere(sphere_position,1.0,glossy_green);

    c_plane *scene_plane = new_plane(j_cap,-1,flat_maroon);

    unsigned int scene_object_count = 2;
    void* scene_objects[] = {
        scene_sphere,
        scene_plane
    };

    //ray tracer code
    c_scene *scene = new_scene(scene_objects,scene_object_count,scene_lights,
                               scene_light_count,scene_camera);
    c_rgb *rendered_pixels = render_scene(scene);
    save_image("test.bmp",width,height,dpi,rendered_pixels);
    return 0;
}
