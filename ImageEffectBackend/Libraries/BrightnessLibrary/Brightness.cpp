#include "Brightness.h"


//amount - 0 to 200
void applyBrightness(vector <vector<Pixel> >& image,float amount){
    //Just to increase the effect of brightness when user moves slider
    float old_amount = 2*amount;

    // Looping to get each pixel
    for(int i=0;i<image.size();i++){
           for(int j=0;j<image[i].size();j++){



                // Middle point in slider gives original image
                // Below midpoint of slider - decrease brightness
                // Above midpoint of slider - increase brightness
                float new_amount = old_amount - 200;

                // Changing rgb accordingly
                float new_r = image[i][j].r + new_amount;
                float new_g = image[i][j].g + new_amount;
                float new_b = image[i][j].b + new_amount;

                //Making sure that rgb lies b/w 0-255
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

