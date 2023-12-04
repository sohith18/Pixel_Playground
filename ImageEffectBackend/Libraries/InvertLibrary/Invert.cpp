#include"Invert.h"

void applyInvert(vector<vector<Pixel>>& image){
        int rows = image.size(); // Number of rows
        int cols = image[0].size(); // Number of columns

        //vector<vector<Pixel>> image_copy(image);
        //image.clear();
        for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    // Invert RGB values for each pixel
                    image[i][j].r = 255 - image[i][j].r;
                    image[i][j].g = 255 - image[i][j].g;
                    image[i][j].b = 255 - image[i][j].b;
                }
            }
}