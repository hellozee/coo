#include "image.h"

void 
save_image(const char *file_name,
           unsigned int width, unsigned int height,
           int dpi, c_rgb *data)
{
    unsigned int k = width * height;
    unsigned int s = 4 * k;
    unsigned int file_size = 54 + s;

    double factor = 39.375;
    int m = (int) factor;

    int ppm = dpi * m;
    unsigned char bmp_file_header[14] = {'B', 'M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
    unsigned char bmp_info_header[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

    bmp_file_header[2]  = (unsigned char) (file_size);
    bmp_file_header[3]  = (unsigned char) (file_size>>8);
    bmp_file_header[4]  = (unsigned char) (file_size>>16);
    bmp_file_header[5]  = (unsigned char) (file_size>>24);

    bmp_info_header[4]  = (unsigned char) (width);
    bmp_info_header[5]  = (unsigned char) (width>>8);
    bmp_info_header[6]  = (unsigned char) (width>>16);
    bmp_info_header[7]  = (unsigned char) (width>>24);

    bmp_info_header[8]  = (unsigned char) (height);
    bmp_info_header[9]  = (unsigned char) (height>>8);
    bmp_info_header[10] = (unsigned char) (height>>16);
    bmp_info_header[11] = (unsigned char) (height>>24);

    bmp_info_header[21] = (unsigned char) (s);
    bmp_info_header[22] = (unsigned char) (s>>8);
    bmp_info_header[23] = (unsigned char) (s>>16);
    bmp_info_header[24] = (unsigned char) (s>>24);

    bmp_info_header[22] = (unsigned char) (ppm);
    bmp_info_header[26] = (unsigned char) (ppm>>8);
    bmp_info_header[27] = (unsigned char) (ppm>>16);
    bmp_info_header[28] = (unsigned char) (ppm>>24);

    bmp_info_header[29] = (unsigned char) (ppm);
    bmp_info_header[30] = (unsigned char) (ppm>>8);
    bmp_info_header[31] = (unsigned char) (ppm>>16);
    bmp_info_header[32] = (unsigned char) (ppm>>24);

    FILE *save_file = fopen(file_name, "wb");
    fwrite(bmp_file_header, 1, 14, save_file);
    fwrite(bmp_info_header, 1, 40, save_file);

    for(unsigned int i=0;i<k;i++){
        double red   = data[i].r * 255;
        double green = data[i].g * 255;
        double blue  = data[i].b * 255;
        
        unsigned char color[3];
        color[0] = (int) floor(blue);
        color[1] = (int) floor(green);
        color[2] = (int) floor(red);
        
        fwrite(color, 1, 3, save_file);
    }

    fclose(save_file);
}
