#ifndef DOMINANT_COLOUR_H
#define DOMINANT_COLOUR_H
#define N_DOM_COLOURS 10
#define K 50
#include<vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include "../Pixel.h"

using namespace std;

void findDominantColour(vector< vector<Pixel> > &image);

#endif