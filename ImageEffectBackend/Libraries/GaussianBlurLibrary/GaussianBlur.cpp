#include "GaussianBlur.h"

double gaussian( double x, double mu, double sigma ) {
    const double a = ( x - mu ) / sigma;
    return exp( -0.5 * a * a );
}

void applyGaussianBlur(vector< vector<Pixel> >&image, float radius)
{
    radius=(int)radius%12;
    double sigma = radius/2;

    vector< vector<double> > kernel(int(2 * radius + 1), vector<double>(int(2 * radius + 1), 0));
    //vector<vector<double>> kernel(1+2*ceil(3*sigma), vector<double>(1+2*ceil(3*sigma), 0));

    double sum = 0;

    for (int i = 0; i < kernel.size(); i++)
    {
        for (int j = 0; j < kernel[i].size(); j++)
        {
            double x = gaussian(i, radius, sigma) * gaussian(j, radius, sigma);
            kernel[i][j] = x;
            sum += x;
        }
    }

    for (int i = 0; i < kernel.size(); i++)
    {
        for (int j = 0; j < kernel[i].size(); j++)
        {
            kernel[i][j] /= sum;
        }
    }

    int height = image[0].size();
    int width = image.size();
    int kernel_center_row,kernel_center_column = radius;

    int integer_r = int(radius);

    vector< vector<Pixel> > blurred_img(width,vector<Pixel>(height));

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            int new_red =0;
            int new_green = 0;
            int new_blue = 0;
            for(int ker_i= int(-1*radius);ker_i<=int(radius);ker_i++){ //columns
                for(int ker_j=int(-1*radius);ker_j<=int(radius);ker_j++){
                    int ker_box_row = i - ker_i;
                    int ker_box_col = j - ker_j;

                    if(ker_box_col>=0 && ker_box_row>=0 && ker_box_row<width && ker_box_col<height){
                        new_red+= kernel[integer_r+ker_i][integer_r+ker_j]*image[ker_box_row][ker_box_col].r;
                        new_green+= kernel[integer_r+ker_i][integer_r+ker_j]*image[ker_box_row][ker_box_col].g;
                        new_blue+= kernel[integer_r+ker_i][integer_r+ker_j]*image[ker_box_row][ker_box_col].b;
                    }
                }
            }




              if(new_red>255) new_red = 255;
              if(new_blue>255) new_blue = 255;
              if(new_green>255) new_green = 255;

              if(new_red<0) new_red = 0;
              if(new_blue<0) new_blue = 0;
              if(new_green<0) new_green = 0;


              blurred_img[i][j].r = (int)new_red;
              blurred_img[i][j].b = (int)new_blue;
              blurred_img[i][j].g = (int)new_green;
        }
    }

    if(radius!=0) image = blurred_img;



}