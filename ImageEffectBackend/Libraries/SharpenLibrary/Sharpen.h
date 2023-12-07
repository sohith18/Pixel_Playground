#ifndef SHARPEN_H
#define SHARPEN_H
#include<vector>
#include<cmath>
#include "../Pixel.h"
using namespace std;

Pixel clampPixel(const Pixel& pixel);
int func(vector< vector<Pixel> > &image, float k[][3], int i, int j, int flag);
void applySharpen(vector< vector<Pixel> > &image, float sharpenValue);

#endif