#include "Flip.h"
void applyFlip(vector<vector<Pixel>>& image, int hf, int vf) {
    if (hf == 0 && vf == 0) {
        return;
    }

    int rows = image.size(); // Number of rows
    int cols = image[0].size(); // Number of columns

    vector<vector<Pixel>> image_copy(image);
    image.clear();

    if (hf == 0 && vf == 1) {
        for (int i = rows - 1; i >= 0; --i) {
            image.push_back(image_copy[i]);
        }
    } else if (hf == 1 && vf == 0) {
        for (int i = 0; i < rows; ++i) {
            vector<Pixel> row;
            for (int j = cols - 1; j >= 0; --j) {
                row.push_back(image_copy[i][j]);
            }
            image.push_back(row);
        }
    }
    else if(hf==1 && vf==1){
        //both flips
        for (int i = rows - 1; i >= 0; --i) {
                    image.push_back(image_copy[i]);
        }
        image_copy=image;
        image.clear();
        for (int i = 0; i < rows; ++i) {
                    vector<Pixel> row;
                    for (int j = cols - 1; j >= 0; --j) {
                        row.push_back(image_copy[i][j]);
                    }
                    image.push_back(row);
                }
    }
}