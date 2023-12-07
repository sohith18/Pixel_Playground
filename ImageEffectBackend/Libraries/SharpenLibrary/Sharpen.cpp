#include"Sharpen.h"

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
    vector< vector<Pixel> > sharpenedImage(rows, vector<Pixel>(columns));
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