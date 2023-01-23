/*This program takes the name of a user-entered .pgm file
and a threshold value and recreates a copy of the image
with the new threshold, saved in a new .pgm file named 
by the user. Images can be viewed using GIMP. 
To run: ./a coins.pgm <name>.pgm 10 
Note: -output.pgm is already included as a 
      sample output with a threshold of 10.
      -edges.pgm is also provided as an 
      alternative input image to coins.pgm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _image {
    int** pixels;
    int width;
    int height;
} Image;

Image* readImage(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }
    Image *img = (Image*)malloc(sizeof(Image));
    char num[2];
    fscanf(fp, "%s", num);
    fscanf(fp, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(fp, "%d", &maxval);

    img->pixels = (int**)malloc(sizeof(int*) * img->height);
    for(int i=0; i < img->height; i++) {
        img->pixels[i] = (int*)malloc(sizeof(int) * img->width);
    }
    for(int row = 0; row < img->height; row++) {
        for(int col = 0; col < img->width; col++) {
            fscanf(fp, "%d", &img->pixels[row][col]);         
        }
    }
    //fclose(fp);
    
    return img;
}
Image* edgeDetect(Image* img, int threshold) {
 
    Image *output = (Image*)malloc(sizeof(Image));
    output->height = img->height;
    output->width = img->width;
    output->pixels = (int**)malloc(sizeof(int*) * output->height);
    for(int i=0; i < output->height; i++) {
        output->pixels[i] = (int*)malloc(sizeof(int) * output->width);
    }
    for (int row = 0; row < output->height; row++) {
        for (int col = 0; col < output->width; col++) {
            output->pixels[row][col] = 0;
        }
    }
    for (int row = 0; row < output->height - 1; row++) {
        for (int col = 0; col < output->width - 1; col++) {
            int curr, right, below;
            curr = img->pixels[row][col];
            right = img->pixels[row][col+1];
            below = img->pixels[row+1][col];
            if (abs(curr - right) > threshold || abs(curr - below) > threshold) {
                output->pixels[row][col] = 255;
            }
        }
    }
    return output;
}

int saveImage(char* filename, Image* img) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        return 1;
    }
    fprintf(fp, "P2\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "255\n");
    for (int row = 0; row < img->height; row++) {
        for (int col = 0; col < img->width; col++) {
            fprintf(fp, "%d\n", img->pixels[row][col]);
        }
    }
    
    fclose(fp);
    return 0;
}

void freeImage(Image* img) {
    for (int row = 0; row < img->height; row++) {
        free(img->pixels[row]);
    }
    free(img->pixels);
    free(img);
    return;
}

int main(int argc, char** argv) {

    if (argc != 4) {
        printf("Usage: ./a.out input.pgm output.pgm threshold\n");
        return 1;
    }

    Image *img = readImage(argv[1]);
    if (!img) {
        printf("Unable to read image: %s\n", argv[1]);
        return 1;
    }
    int threshold = atoi(argv[3]);
    Image *edges = edgeDetect(img, threshold);

    if (saveImage(argv[2], edges) == 1) {
        printf("Unable to write image: %s\n", argv[2]);
        return 1;
    }
    freeImage(img);
    freeImage(edges);

    return 0;
}