#ifndef BLUR_H
#define BLUR_H
#include<vector>
#include "../Pixel.h"

using namespace std;

void applyGaussianBlur(vector< vector<Pixel> > &image, float radius);

#endif