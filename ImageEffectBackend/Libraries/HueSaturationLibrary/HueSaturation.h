#ifndef HUE_SATURATION_H
#define HUE_SATURATION_H
#include<vector>
#include <algorithm>
#include <cmath>
#include "../Pixel.h"

using namespace std;

void applyHueSaturation(vector< vector<Pixel> > &image, float saturationValue, float hueValue);

#endif