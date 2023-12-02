#include "Brightness.h"


void applyBrightness(vector<vector<Pixel>>& image,float amount){
    for(int i=0;i<image.size();i++){
           for(int j=0;j<image[i].size();j++){


                float new_amount = amount - 100;

                float new_r = image[i][j].r + new_amount;
                float new_g = image[i][j].g + new_amount;
                float new_b = image[i][j].b + new_amount;

                if(new_r>255) new_r = 255;
                if(new_b>255) new_b = 255;
                if(new_g>255) new_g = 255;

                if(new_r<0) new_r = 0;
                if(new_b<0) new_b = 0;
                if(new_g<0) new_g = 0;


                image[i][j].r = (int)new_r;
                image[i][j].b = (int)new_b;
                image[i][j].g = (int)new_g;

           }
     }
}

