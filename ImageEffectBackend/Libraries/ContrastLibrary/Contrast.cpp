#include "Contrast.h"

void applyContrast(vector< vector<Pixel> > &image, float contrastFactor){
 int rows = image.size(); // Number of rows
 int cols = image[0].size(); // Number of columns

for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //contrast? increasing it makes dark areas darker and light areas lighter (decreasing opposite effect, less vibrant)
            //general formula for contrast-> New Pixel Value=(Old Pixel Value−Middle Value)×Contrast Factor+Middle Value
            //here middle value is 127
            //(a contrast factor of 1 has no effect) below 1 decreases contrast and above 1 increases contrast

            //a reasonable range for contrast factor is 0.5 to 2.5, so I have adjusted the contrast factor accordingly
            // in apply function of contrast.java

            image[i][j].r = static_cast<int>((image[i][j].r - 127) * contrastFactor) + 127;
            image[i][j].g = static_cast<int>((image[i][j].g - 127) * contrastFactor) + 127;
            image[i][j].b = static_cast<int>((image[i][j].b - 127) * contrastFactor) + 127;

            //ensuring that the rgb values do not go out of range, so assigning the minimum 0/maxumum 255 as per requirement
            if(image[i][j].r>255){image[i][j].r=255;}
            if(image[i][j].g<0){image[i][j].g=0;}
            if(image[i][j].b>255){image[i][j].b=255;}
            if(image[i][j].r<0){image[i][j].r=0;}
            if(image[i][j].g>255){image[i][j].g=255;}
            if(image[i][j].b<0){image[i][j].b=0;}
}}}