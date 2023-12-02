#include "Sepia.h"

void applySepia(vector< vector<Pixel> > &image){
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].size();j++){
            int new_red = 0.393*image[i][j].r + 0.769*image[i][j].g + 0.189*image[i][j].b;
            int new_green = 0.349*image[i][j].r + 0.686*image[i][j].g + 0.168*image[i][j].b;
            int new_blue = 0.272*image[i][j].r + 0.534*image[i][j].g + 0.131*image[i][j].b;

            if(new_red>255) image[i][j].r =255;
            else image[i][j].r = new_red;
            if(new_green>255) image[i][j].g =255;
            else image[i][j].g = new_green;
            if(new_blue>255) image[i][j].b =255;
            else image[i][j].b = new_blue;


        }
    }

}