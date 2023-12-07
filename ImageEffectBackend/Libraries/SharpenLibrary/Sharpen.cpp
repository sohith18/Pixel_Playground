#include"Sharpen.h"

void applyGaussianBlur(vector< vector<Pixel> >&image, float radius)
{
     if(radius==0) return;  //edge case

     double sigma = radius/2;

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

     for (int i = 0; i < kernel.size(); i++)
     {
         kernel[i] /= sum;
     }

     int height = image.size();
     int width = image[0].size();



     vector< vector<Pixel> > blurred_img(height,vector<Pixel>(width));

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




Pixel clampPixel(const Pixel& pixel) {
    Pixel result;
    result.r = min(255, max(0, pixel.r));
    result.g = min(255, max(0, pixel.g));
    result.b = min(255, max(0, pixel.b));
    return result;
}

int func(vector< vector<Pixel> > &image, float k[][3], int i, int j, int flag){
    if(i==0 && j==0){
        if(flag==0){return (int)((k[0][0]*image[i+1][j+1].r)+k[0][1]*image[i+1][j].r+k[0][2]*image[i+1][j].r+k[1][0]*image[i][j+1].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j].r+k[2][0]*image[i][j+1].r+k[2][1]*image[i][j].r+k[2][2]*image[i][j].r);}
         if(flag==1){return (int)((k[0][0]*image[i+1][j+1].g)+k[0][1]*image[i+1][j].g+k[0][2]*image[i+1][j].g+k[1][0]*image[i][j+1].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j].g+k[2][0]*image[i][j+1].g+k[2][1]*image[i][j].g+k[2][2]*image[i][j].g);}
          if(flag==2){return (int)((k[0][0]*image[i+1][j+1].b)+k[0][1]*image[i+1][j].b+k[0][2]*image[i+1][j].b+k[1][0]*image[i][j+1].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j].b+k[2][0]*image[i][j+1].b+k[2][1]*image[i][j].b+k[2][2]*image[i][j].b);}
    }
    else if(i==image.size()-1 && j==0){
        if(flag==0)return (int)((k[0][0]*image[i][j+1].r)+k[0][1]*image[i][j].r+k[0][2]*image[i][j].r+k[1][0]*image[i][j+1].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j].r+k[2][0]*image[i-1][j+1].r+k[2][1]*image[i-1][j].r+k[2][2]*image[i-1][j].r);
        if(flag==1)return (int)((k[0][0]*image[i][j+1].g)+k[0][1]*image[i][j].g+k[0][2]*image[i][j].g+k[1][0]*image[i][j+1].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j].g+k[2][0]*image[i-1][j+1].g+k[2][1]*image[i-1][j].g+k[2][2]*image[i-1][j].g);
        if(flag==2)return (int)((k[0][0]*image[i][j+1].b)+k[0][1]*image[i][j].b+k[0][2]*image[i][j].b+k[1][0]*image[i][j+1].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j].b+k[2][0]*image[i-1][j+1].b+k[2][1]*image[i-1][j].b+k[2][2]*image[i-1][j].b);
    }
    else if(i==0 && j==image[0].size()-1){
        if(flag==0)return (int)((k[0][0]*image[i+1][j].r)+k[0][1]*image[i+1][j].r+k[0][2]*image[i+1][j-1].r+k[1][0]*image[i][j].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j-1].r+k[2][0]*image[i][j].r+k[2][1]*image[i][j].r+k[2][2]*image[i][j-1].r);
        if(flag==1)return (int)((k[0][0]*image[i+1][j].g)+k[0][1]*image[i+1][j].g+k[0][2]*image[i+1][j-1].g+k[1][0]*image[i][j].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j-1].g+k[2][0]*image[i][j].r+k[2][1]*image[i][j].g+k[2][2]*image[i][j-1].g);
        if(flag==2)return (int)((k[0][0]*image[i+1][j].b)+k[0][1]*image[i+1][j].b+k[0][2]*image[i+1][j-1].b+k[1][0]*image[i][j].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j-1].b+k[2][0]*image[i][j].r+k[2][1]*image[i][j].b+k[2][2]*image[i][j-1].b);
    }
    else if(i==image.size()-1 && j==image[0].size()-1){
        if(flag==0)return (int)((k[0][0]*image[i][j].r)+k[0][1]*image[i][j].r+k[0][2]*image[i][j-1].r+k[1][0]*image[i][j].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j-1].r+k[2][0]*image[i-1][j].r+k[2][1]*image[i-1][j].r+k[2][2]*image[i-1][j-1].r);
        if(flag==1)return (int)((k[0][0]*image[i][j].g)+k[0][1]*image[i][j].g+k[0][2]*image[i][j-1].g+k[1][0]*image[i][j].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j-1].g+k[2][0]*image[i-1][j].g+k[2][1]*image[i-1][j].g+k[2][2]*image[i-1][j-1].g);
        if(flag==2)return (int)((k[0][0]*image[i][j].b)+k[0][1]*image[i][j].b+k[0][2]*image[i][j-1].b+k[1][0]*image[i][j].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j-1].b+k[2][0]*image[i-1][j].b+k[2][1]*image[i-1][j].b+k[2][2]*image[i-1][j-1].b);
    }
    else if(i==0){
        if(flag==0)return (int)((k[0][0]*image[i+1][j+1].r)+k[0][1]*image[i+1][j].r+k[0][2]*image[i+1][j-1].r+k[1][0]*image[i][j+1].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j-1].r+k[2][0]*image[i][j+1].r+k[2][1]*image[i][j].r+k[2][2]*image[i][j-1].r);
        if(flag==1)return (int)((k[0][0]*image[i+1][j+1].g)+k[0][1]*image[i+1][j].g+k[0][2]*image[i+1][j-1].g+k[1][0]*image[i][j+1].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j-1].g+k[2][0]*image[i][j+1].g+k[2][1]*image[i][j].g+k[2][2]*image[i][j-1].g);
        if(flag==2)return (int)((k[0][0]*image[i+1][j+1].b)+k[0][1]*image[i+1][j].b+k[0][2]*image[i+1][j-1].b+k[1][0]*image[i][j+1].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j-1].b+k[2][0]*image[i][j+1].b+k[2][1]*image[i][j].b+k[2][2]*image[i][j-1].b);
    }
    else if(j==0){
        if(flag==0)return (int)((k[0][0]*image[i+1][j+1].r)+k[0][1]*image[i+1][j].r+k[0][2]*image[i+1][j].r+k[1][0]*image[i][j+1].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j].r+k[2][0]*image[i-1][j+1].r+k[2][1]*image[i-1][j].r+k[2][2]*image[i-1][j].r);
        if(flag==1)return (int)((k[0][0]*image[i+1][j+1].g)+k[0][1]*image[i+1][j].g+k[0][2]*image[i+1][j].g+k[1][0]*image[i][j+1].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j].g+k[2][0]*image[i-1][j+1].g+k[2][1]*image[i-1][j].g+k[2][2]*image[i-1][j].g);
        if(flag==2)return (int)((k[0][0]*image[i+1][j+1].b)+k[0][1]*image[i+1][j].b+k[0][2]*image[i+1][j].b+k[1][0]*image[i][j+1].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j].b+k[2][0]*image[i-1][j+1].b+k[2][1]*image[i-1][j].b+k[2][2]*image[i-1][j].b);

    }
    else if(i==image.size()-1){
        if(flag==0)return (int)((k[0][0]*image[i][j+1].r)+k[0][1]*image[i][j].r+k[0][2]*image[i][j-1].r+k[1][0]*image[i][j+1].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j-1].r+k[2][0]*image[i-1][j+1].r+k[2][1]*image[i-1][j].r+k[2][2]*image[i-1][j-1].r);
        if(flag==1)return (int)((k[0][0]*image[i][j+1].g)+k[0][1]*image[i][j].g+k[0][2]*image[i][j-1].g+k[1][0]*image[i][j+1].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j-1].g+k[2][0]*image[i-1][j+1].g+k[2][1]*image[i-1][j].g+k[2][2]*image[i-1][j-1].g);
        if(flag==2)return (int)((k[0][0]*image[i][j+1].b)+k[0][1]*image[i][j].b+k[0][2]*image[i][j-1].b+k[1][0]*image[i][j+1].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j-1].b+k[2][0]*image[i-1][j+1].b+k[2][1]*image[i-1][j].b+k[2][2]*image[i-1][j-1].b);
    }
    else if(j==image.size()-1){
        if(flag==0)return (int)((k[0][0]*image[i+1][j].r)+k[0][1]*image[i+1][j].r+k[0][2]*image[i+1][j-1].r+k[1][0]*image[i][j].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j-1].r+k[2][0]*image[i-1][j].r+k[2][1]*image[i-1][j].r+k[2][2]*image[i-1][j-1].r);
        if(flag==1)return (int)((k[0][0]*image[i+1][j].g)+k[0][1]*image[i+1][j].g+k[0][2]*image[i+1][j-1].g+k[1][0]*image[i][j].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j-1].g+k[2][0]*image[i-1][j].g+k[2][1]*image[i-1][j].g+k[2][2]*image[i-1][j-1].g);
        if(flag==2)return (int)((k[0][0]*image[i+1][j].b)+k[0][1]*image[i+1][j].b+k[0][2]*image[i+1][j-1].b+k[1][0]*image[i][j].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j-1].b+k[2][0]*image[i-1][j].b+k[2][1]*image[i-1][j].b+k[2][2]*image[i-1][j-1].b);
    }
    else{
        if(flag==0){
            return (int)((k[0][0]*image[i+1][j+1].r)+k[0][1]*image[i+1][j].r+k[0][2]*image[i+1][j-1].r+k[1][0]*image[i][j+1].r+k[1][1]*image[i][j].r+k[1][2]*image[i][j-1].r+k[2][0]*image[i-1][j+1].r+k[2][1]*image[i-1][j].r+k[2][2]*image[i-1][j-1].r);
        }
        if(flag==1){
            return (int)((k[0][0]*image[i+1][j+1].g)+k[0][1]*image[i+1][j].g+k[0][2]*image[i+1][j-1].g+k[1][0]*image[i][j+1].g+k[1][1]*image[i][j].g+k[1][2]*image[i][j-1].g+k[2][0]*image[i-1][j+1].g+k[2][1]*image[i-1][j].g+k[2][2]*image[i-1][j-1].g);
        }
        if(flag==2){
            return (int)((k[0][0]*image[i+1][j+1].b)+k[0][1]*image[i+1][j].b+k[0][2]*image[i+1][j-1].b+k[1][0]*image[i][j+1].b+k[1][1]*image[i][j].b+k[1][2]*image[i][j-1].b+k[2][0]*image[i-1][j+1].b+k[2][1]*image[i-1][j].b+k[2][2]*image[i-1][j-1].b);
        }
    }
    return -1;//Exception handling
}

void applySharpen(vector< vector<Pixel> > &image, float sharpenValue){
    sharpenValue/=10;
    if(sharpenValue==0){return;}
    int rows = image.size();
    int columns = image[0].size();
    vector<vector<Pixel>> sharpenedImage(rows, vector<Pixel>(columns));
    // Sharpening kernel
    float kernel[3][3] = {{(sharpenValue*-1)/9, (sharpenValue*-1)/9, (sharpenValue*-1)/9},
                          {(sharpenValue*-1)/9, 1+(sharpenValue*8/9), (sharpenValue*-1)/9},
                          {(sharpenValue*-1)/9, (sharpenValue*-1)/9, (sharpenValue*-1)/9}};
    //[1,1] to [n-2,m-2] not considering edges
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            sharpenedImage[i][j].r = func(image,kernel, i,j,0);
            sharpenedImage[i][j].g = func(image,kernel, i,j,1);
            sharpenedImage[i][j].b = func(image,kernel, i,j,2);
            sharpenedImage[i][j] = clampPixel(sharpenedImage[i][j]);
        }
    }
    image=sharpenedImage;
}
