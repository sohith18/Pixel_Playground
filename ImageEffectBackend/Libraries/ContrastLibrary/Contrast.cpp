#include "Contrast.h"

void applyContrast(vector< vector<Pixel> > &image, float contrastFactor){
 int rows = image.size(); // Number of rows
 int cols = image[0].size(); // Number of columns

for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //(a contrast factor of 1 has no effect) below 1 decreases contrast and above 1 increases contrast
            image[i][j].r = static_cast<int>((image[i][j].r - 127) * contrastFactor) + 127;
            image[i][j].g = static_cast<int>((image[i][j].g - 127) * contrastFactor) + 127;
            image[i][j].b = static_cast<int>((image[i][j].b - 127) * contrastFactor) + 127;

            if(image[i][j].r>255){image[i][j].r=255;}
            if(image[i][j].g<0){image[i][j].g=0;}
            if(image[i][j].b>255){image[i][j].b=255;}
            if(image[i][j].r<0){image[i][j].r=0;}
            if(image[i][j].g>255){image[i][j].g=255;}
            if(image[i][j].b<0){image[i][j].b=0;}
}}}