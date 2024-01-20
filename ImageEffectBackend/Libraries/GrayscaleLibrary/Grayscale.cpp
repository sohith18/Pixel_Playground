#include"Grayscale.h"

void applyGrayscale(vector< vector<Pixel> >& image){
        int rows = image.size(); // Number of rows
        int cols = image[0].size(); // Number of columns

        for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    /*
                       Weight for red is 0.299/1=0.299, weight for green is 0.587/1=0.587, weight for blue is 0.0.114/1=0.114. Note that 0.299+0.587+0.114=1
                       The weights 0.299, 0.587 and 0.114 are derived based on the luminance values normalized to the maximum intensity of each channel.
                    */
                    image[i][j].r= 0.299*image[i][j].r+0.587*image[i][j].g+0.114*image[i][j].b;
                    image[i][j].g= image[i][j].r;
                    image[i][j].b= image[i][j].r;
                }
            }
}