#include "GaussianBlur.h"

// radius - 0 to 50
void applyGaussianBlur(vector< vector<Pixel> >&image, float radius)
{
     if(radius==0) return;  //edge case

     double sigma = radius/2;

     //Calculating kernel matrix
     vector<double> kernel(int(2 * radius + 1),0);

     double sum = 0;
     int integer_r = int(radius);

     for (int i = -integer_r; i <=integer_r; i++)
     {
         double exponentNumerator = double(-(i * i));
         double exponentDenominator = (2 * sigma * sigma);

         double eExpression = exp( exponentNumerator / exponentDenominator);
         double kernelValue = eExpression / sqrt(2 * M_PI * sigma * sigma);

         kernel[i + integer_r] = kernelValue;
         sum += kernelValue;
     }

     // Normalising kernel matrix
     for (int i = 0; i < kernel.size(); i++)
     {
         kernel[i] /= sum;
     }

     int height = image.size();
     int width = image[0].size();



     vector< vector<Pixel> > blurred_img(height,vector<Pixel>(width));

     // Convolution of each pixel of image with kernel
     // Doing 1-D convolution along both x and y axis
     for(int i=0;i<height;i++){
         for(int j=0;j<width;j++){
             double new_red =0;
             double new_green = 0;
             double new_blue = 0;
             double sum = 0;
             for(int ker_i= -integer_r;ker_i<=integer_r;ker_i++){  //Convolve along x-axis

                 int ker_box_row = j - ker_i;          //goes through row first

                 if(ker_box_row>=0 && ker_box_row<width){
                     new_red+= kernel[integer_r+ker_i]*image[i][ker_box_row].r;
                     new_green+= kernel[integer_r+ker_i]*image[i][ker_box_row].g;
                     new_blue+= kernel[integer_r+ker_i]*image[i][ker_box_row].b;
                     sum+=kernel[ker_i+integer_r];
                 }

             }

               // To ensure that pixel values lies b/w 0 to 255
               if(new_red>255) new_red = 255;
               if(new_blue>255) new_blue = 255;
               if(new_green>255) new_green = 255;

                 if(sum>0){           //Normalising(avg) the values (helps in eliminating black edges)
                    new_red /= sum;
                    new_green /= sum;
                    new_blue /= sum;
                 }


               blurred_img[i][j].r = (int)new_red;
               blurred_img[i][j].b = (int)new_blue;
               blurred_img[i][j].g = (int)new_green;
         }
     }


     for(int i=0;i<width;i++){
         for(int j=0;j<height;j++){
             double new_red =0;
             double new_green = 0;
             double new_blue = 0;
             double sum = 0;
             for(int ker_j= -integer_r;ker_j<=integer_r;ker_j++){ //Convolve along y-axis

                 int ker_box_row = j - ker_j;           //goes through whole column first

                 if(ker_box_row>=0 && ker_box_row<height){
                     new_red+= kernel[integer_r+ker_j]*blurred_img[ker_box_row][i].r;
                     new_green+= kernel[integer_r+ker_j]*blurred_img[ker_box_row][i].g;
                     new_blue+= kernel[integer_r+ker_j]*blurred_img[ker_box_row][i].b;
                     sum+= kernel[ker_j + integer_r];
                 }

             }

               // To ensure that pixel values lies b/w 0 to 255
               if(new_red>255) new_red = 255;
               if(new_blue>255) new_blue = 255;
               if(new_green>255) new_green = 255;


                if(sum>0){                //Normalising(avg) the values (helps in eliminating black edges)
                    new_red /= sum;
                    new_green /= sum;
                    new_blue /= sum;
                }


               image[j][i].r = (int)new_red;
               image[j][i].b = (int)new_blue;
               image[j][i].g = (int)new_green;
         }
     }

}