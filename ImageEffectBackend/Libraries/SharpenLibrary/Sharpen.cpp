#include"Sharpen.h"

//function that takes an input picture and ensures r,g,b is in appropriate range, adjusts if required, and returns a pixel
Pixel clampPixel(const Pixel& pixel) {
    Pixel result;
    result.r = min(255, max(0, pixel.r));
    result.g = min(255, max(0, pixel.g));
    result.b = min(255, max(0, pixel.b));
    return result;
}

int func(vector< vector<Pixel> > &image, float k[][3], int i, int j, int flag){

    //8 edge cases, 4 sides and 4 corners(since they don't have neighbours) -> we used method of extension
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

     //[1,1] to [n-2,m-2] not considering edges
     //CONVOLUTION, flipping both the rows and columns of the kernel and multiplying locally similar entries and summing
     //you keep considered pixel [i,j] at the centre and its neighbours (from i-1, j-1 to i+1, j+1) both the rows and columns of the kernel and multiplying locally similar entries and summing both the rows and columns of the kernel and multiplying locally similar entries and summingghbous surrounding it to get image matrix
     /*Kernel * Image
     [a b c     [1 2 3
      d e f    * 4 5 6
      g h i]     7 8 9]
    = (i.1)+(h. 2) + (g. 3) + (f. 4) + (e. 5) + (d. 6) + (c. 7) + (6.8) + (a.9)   ---->(1)

     How we got Kernel Matrix?
     formula used for sharpening: F(x,y) = f(x,y)+k*( f(x,y)-Fblur(x,y) ) /Highboost filtering
     [0 0 0
      0 1 0
      0 0  1] this will give the same image as it is. Let this be A
     Box blur is 1/9 * [1 1 1
                        1 1 1
                         1 1 1] let this be B.
     So kernel matrix for sharpening: A + K*(A-B),kernel shown below
     */

     //Using equation (1)
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
    sharpenValue/=10; //an appropriate range for sharpenvalue is 0 to 10.
    if(sharpenValue==0){return;} //no sharpening
    int rows = image.size();
    int columns = image[0].size();
    vector< vector<Pixel> > sharpenedImage(rows, vector<Pixel>(columns)); //initialises 2D vector of same dimension

    // Sharpening kernel, HOW I GOT THIS KERNEL? explained in the above function
    float kernel[3][3] = {{(sharpenValue*-1)/9, (sharpenValue*-1)/9, (sharpenValue*-1)/9},
                          {(sharpenValue*-1)/9, 1+(sharpenValue*8/9), (sharpenValue*-1)/9},
                          {(sharpenValue*-1)/9, (sharpenValue*-1)/9, (sharpenValue*-1)/9}};

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            //we call the function for each pixel with another flag argument to represent <r,g,b>
            sharpenedImage[i][j].r = func(image,kernel, i,j,0);
            sharpenedImage[i][j].g = func(image,kernel, i,j,1);
            sharpenedImage[i][j].b = func(image,kernel, i,j,2);
            sharpenedImage[i][j] = clampPixel(sharpenedImage[i][j]); //ensures range
        }
    }
    image=sharpenedImage; //assigning modified image back to the original
}
