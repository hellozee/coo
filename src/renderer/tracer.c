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
calculate_color(c_vector i_pos, c_vector i_dir, int index, c_scene *scene)
{
    c_object *obj = (c_object*) scene->scene_objects[index];
    c_material_rgb object_color;
    c_vector object_normal;

    switch (obj->type) {
    case plane:{
        c_plane* p = (c_plane*) scene->scene_objects[index];
        object_color = p->color;
        object_normal = p->normal;
        break;
    }
    case sphere:{
        c_sphere* s = (c_sphere*) scene->scene_objects[index];
        object_color = s->color;
        object_normal = sphere_normal_at(i_pos,s);
        break;
    }
    }

    c_material_rgb final_color = color_multiply_scalar(0.2, object_color);

    for(unsigned int i=0;i<scene->scene_light_count;i++){
        c_vector light_direction = scene->scene_lights[i].position;
        light_direction = vector_add(light_direction,vector_negate(i_pos));
        light_direction = vector_normalize(light_direction);

        double cosine_angle = vector_dot_product(object_normal, light_direction);

        if(cosine_angle > 0){
            //now we check for shadows
            bool under_shadow = false;
            c_vector lo_vector = scene->scene_lights[i].position;
            lo_vector = vector_add(lo_vector,vector_negate(i_pos));
            lo_vector = vector_normalize(lo_vector);

            double mod_lo = vector_magnitude(lo_vector);
            c_ray shadow_ray = new_ray(i_pos,lo_vector);

            double secondary_intersections[scene->scene_object_count];

            for(unsigned int j=0; j<scene->scene_object_count && !under_shadow; j++){
                c_object *obj = (c_object*) scene->scene_objects[index];

                switch (obj->type) {
                case plane:{
                    c_plane *p = (c_plane*) scene->scene_objects[index];
                    secondary_intersections[j] = plane_find_intersection(shadow_ray,
                                                                         p);
                    break;
                }
                case sphere:{
                    c_sphere *s = (c_sphere*) scene->scene_objects[index];
                    secondary_intersections[j] = sphere_find_intersection(shadow_ray,
                                                                          s);
                    break;
                }
                }
            }

            for(unsigned int j=0; j<scene->scene_object_count; j++){
                if(secondary_intersections[j] <= mod_lo){
                    under_shadow = true;
                    break;
                }
            }

            if(!under_shadow){
                c_material_rgb temp_col = color_multiply_scalar(
                                    cosine_angle,scene->scene_lights[i].color);
                temp_col = color_multipy(temp_col,object_color);
                final_color = color_add(final_color,temp_col);

                if(object_color.specular > 0){
                    double first_dot_product = vector_dot_product(object_normal,
                                                            vector_negate(i_dir));
                    c_vector first_scalar_product = vector_scalar_product(
                                                first_dot_product, object_normal);
                    c_vector first_sum = vector_add(first_scalar_product,i_dir);
                    c_vector second_scalar_product = vector_scalar_product(2,first_sum);
                    c_vector second_sum = vector_add(vector_negate(i_dir),
                                                     second_scalar_product);
                    c_vector reflection_direction = vector_normalize(second_sum);

                    double specular = vector_dot_product(reflection_direction,
                                                         lo_vector);

                    if(specular>0){
                        specular = pow(specular,10);
                        specular = specular * object_color.specular;
                        c_material_rgb col = color_multiply_scalar(
                                            specular,scene->scene_lights[i].color);
                        final_color = color_add(final_color,col);
                    }
                }
            }
        }
    }
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
                    break;
                }
                case sphere:{
                    c_sphere *s = (c_sphere*) scene->scene_objects[k];
                    intersections[k] = sphere_find_intersection(camera_ray,s);
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
                                                     scene);
                pixels[j*width + i] = col.color;
            }else{
                pixels[j*width + i] = new_rgb_color(0,0,0);
            }
        }
    }
    return pixels;
}
