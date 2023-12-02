#ifndef DOMINANT_COLOUR_H
#define DOMINANT_COLOUR_H
#include<vector>
#include <algorithm>
#include <cstdlib> 
#include <cmath>
#include "../Pixel.h"
#define K 50
#define N_DOM_COLOURS 10

using namespace std;

void findDominantColour(vector< vector<Pixel> > &image);

#endif