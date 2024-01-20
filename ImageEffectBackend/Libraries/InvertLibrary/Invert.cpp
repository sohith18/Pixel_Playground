#include"Invert.h"

void applyInvert(vector< vector<Pixel> >& image){
        int rows = image.size(); // Number of rows
        int cols = image[0].size(); // Number of columns

        for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    // Invert RGB values for each pixel, (Note that 255 is max possible value)
                    image[i][j].r = 255 - image[i][j].r;
                    image[i][j].g = 255 - image[i][j].g;
                    image[i][j].b = 255 - image[i][j].b;
                }
            }
}