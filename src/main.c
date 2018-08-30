#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "math/vector.h"
#include "math/ray.h"
#include "image/image.h"
#include "camera/camera.h"

int main(){
    printf("rendering..\n");

    int dpi = 72;
    int height = 600;
    int width = 800;

    ColorTuple *pixels = (ColorTuple*) malloc(sizeof(ColorTuple) * 
                            height * width);
    
    Vector i_cap = new_vector(1,0,0);
    Vector j_cap = new_vector(0,1,0);
    Vector k_cap = new_vector(0,0,1);

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
