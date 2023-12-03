#include "GaussianBlur.h"
#include <vector>
#include <cmath>

using namespace std;


double gaussian( double x, double mu, double sigma ) {
    const double a = ( x - mu ) / sigma;
    return exp( -0.5 * a * a );
}

void applyGaussianBlur(vector<vector<Pixel>>&image, float radius)
{
    double sigma = radius/2;

    vector<vector<double>> kernel(int(2 * radius + 1), vector<double>(int(2 * radius + 1), 0));
    //vector<vector<double>> kernel(1+2*ceil(3*sigma), vector<double>(1+2*ceil(3*sigma), 0));

    double sum = 0;
    int integer_r = int(radius);

    for (int i = -integer_r; i < integer_r; i++)
    {
        for (int j = -integer_r; j < integer_r; j++)
        {
            double exponentNumerator = double(-(i * i+ j * j));
            double exponentDenominator = (2 * sigma * sigma);

            double eExpression = exp( exponentNumerator / exponentDenominator);
            double kernelValue = (eExpression / (2 * M_PI * sigma * sigma));

                            // We add radius to the indices to prevent out of bound issues because x and y can be negative
            kernel[i + integer_r][j + integer_r] = kernelValue;
            sum += kernelValue;
        }
    }

    for (int i = 0; i < kernel.size(); i++)
    {
        for (int j = 0; j < kernel[i].size(); j++)
        {
            kernel[i][j] /= sum;
        }
    }

    int height = image.size();
    int width = image[0].size();



    vector<vector<Pixel>> blurred_img(height,vector<Pixel>(width));

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            double new_red =0;
            double new_green = 0;
            double new_blue = 0;
            for(int ker_i= -1*integer_r;ker_i<integer_r;ker_i++){ //columns
                for(int ker_j=-1*integer_r;ker_j<integer_r;ker_j++){
                    int ker_box_row = i - ker_i;
                    int ker_box_col = j - ker_j;

                    if(ker_box_col>=0 && ker_box_row>=0 && ker_box_row<height && ker_box_col<width){
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