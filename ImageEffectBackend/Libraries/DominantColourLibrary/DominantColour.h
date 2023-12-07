#ifndef DOMINANT_COLOUR_H
#define DOMINANT_COLOUR_H
#define N_DOM_COLOURS 1
#define K 50
#include<vector>
#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include "../Pixel.h"

using namespace std;

void findDominantColour(vector< vector<Pixel> > &image);

#endif