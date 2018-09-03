/**
  coo
  tracer.c
  Purpose : Provide definitions of the scene class and its methods

  @author Kuntal Majumder ( zee at hellozee dot me )
**/
#include "tracer.h"

/**
 * @brief c_scene data structure for storing the scene
 */
struct c_scene{
    void **scene_objects;
    unsigned int scene_object_count;
    c_light *scene_lights;
    unsigned int scene_light_count;
    c_camera scene_camera;
};

/**
 * @brief new_scene creates a new scene object returns the pointer to it
 * @param objects
 * @param object_count
 * @param lights
 * @param light_count
 * @param camera
 * @return
 */
c_scene*
new_scene(void **objects, unsigned int object_count, c_light *lights,
           unsigned int light_count, c_camera camera)
{
    c_scene* t = malloc(sizeof (c_scene));
    t->scene_camera = camera;
    t->scene_light_count = light_count;
    t->scene_lights = lights;
    t->scene_objects = objects;
    t->scene_object_count = object_count;
    return t;
}

/**
 * @brief index_of_first_intersection calculates the minimum index of intersection
 * among the given objects
 * @param intersections
 * @param size
 * @return
 */
int
index_of_first_intersection(double *intersections, unsigned int size)
{
    // return the index of the winning intersection
    int return_index = -1;

    // otherwise there is more than one intersection
    // first find the maximum value
    double max = 0;
    for (unsigned int i = 0; i < size; i++) {
        if (intersections[i] > max) {
            max = intersections[i];
        }
    }

    // then starting from the maximum value find the minimum positive value
    if (max > 0) {
        // we only want positive intersections
        for (unsigned int i = 0; i < size; i++) {
            if (intersections[i] > 0 && intersections[i] <= max) {
                max = intersections[i];
                return_index = (int) i;
            }
        }
    }

    return return_index;
}

/**
 * @brief calculate_color calculates shadows and reflections
 * @param i_pos
 * @param i_dir
 * @param index
 * @param scene
 * @return
 */
c_material_rgb
calculate_color(c_vector i_pos, c_vector i_dir, int index, c_scene *scene,
                enum c_object_type *type)
{
    c_vector object_normal;
    c_vector light_direction = vector_add(scene->scene_lights[0].position,
            vector_negate(i_pos));

    double factor;

    switch(type[index]) {
    case sphere:{
        c_sphere *s = (c_sphere*)scene->scene_objects[index];
        object_normal = sphere_normal_at(i_pos,s);
        break;
    }
    case plane:{
        c_plane *p = (c_plane*) scene->scene_objects[index];
        object_normal = p->normal;
        break;
    }
    }

    factor = vector_dot_product(vector_normalize(light_direction),
                                       vector_normalize(object_normal));
    c_material_rgb final_color = color_multiply_scalar(factor,scene->scene_lights[0].color);

    switch (type[index]) {
    case plane:{
        c_plane *p = (c_plane*) scene->scene_objects[index];
        final_color = color_add(final_color,p->color);
        break;
    }
    case sphere:{
        c_sphere *s = (c_sphere*) scene->scene_objects[index];
        final_color = color_add(final_color,s->color);
        break;
    }
    }
    final_color = color_multiply_scalar(0.5,final_color);
    final_color = color_cap_value(final_color);
    return final_color;
}

/**
 * @brief render_scene ray traces the given scene and returns a pointer to the
 * genererated pixels array
 * @param scene
 * @return
 */
c_rgb*
render_scene(c_scene *scene)
{
    double x_amount, y_amount;
    unsigned int width = scene->scene_camera.width;
    unsigned int height = scene->scene_camera.height;
    double aspect_ratio = (double) width/ (double) height;
    c_rgb *pixels = (c_rgb*) malloc(sizeof(c_rgb) * height * width);
    enum c_object_type *types = (enum c_object_type*) malloc(
                sizeof (enum c_object_type) * scene->scene_object_count);

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
                                                                  scene->scene_camera.right);
            c_vector down_scalar_product = vector_scalar_product(y_amount - 0.5,
                                                                 scene->scene_camera.down);
            c_vector camera_ray_direction = vector_add(scene->scene_camera.direction,
                        vector_add(right_scalar_product,down_scalar_product));

            c_ray camera_ray = new_ray(scene->scene_camera.position,
                                       camera_ray_direction);
            double *intersections = malloc(sizeof (double) * scene->scene_object_count);

            for(unsigned int k=0; k<scene->scene_object_count;k++){
                c_object *obj = (c_object*) scene->scene_objects[k];

                switch (obj->type) {
                case plane:{
                    c_plane *p = (c_plane*) scene->scene_objects[k];
                    intersections[k] = plane_find_intersection(camera_ray,p);
                    types[k] = plane;
                    break;
                }
                case sphere:{
                    c_sphere *s = (c_sphere*) scene->scene_objects[k];
                    intersections[k] = sphere_find_intersection(camera_ray,s);
                    types[k] = sphere;
                    break;
                }
                }
            }
            int first_intersection = index_of_first_intersection(intersections,
                                                    scene->scene_object_count);
            if(first_intersection > -1){
                c_vector reflected_ray = vector_scalar_product(
                            intersections[first_intersection], camera_ray_direction);
                c_vector intersection_position = vector_add(
                            scene->scene_camera.position, reflected_ray);

                c_material_rgb col = calculate_color(intersection_position,
                                                     camera_ray_direction,
                                                     first_intersection,
                                                     scene,types);
                pixels[j*width + i] = col.color;
            }else{
                pixels[j*width + i] = new_rgb_color(0,0,0);
            }
        }
    }
    return pixels;
}
