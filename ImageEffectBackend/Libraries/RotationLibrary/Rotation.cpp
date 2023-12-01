#include "Rotation.h"

void applyRotation(vector< vector<Pixel> > &image, int value) {
    for (int i = 0; i < value; i++)
    {
        vector< vector<Pixel> > image_copy;

        int a = image[0].size(); // Length
        int b = image.size(); // Breadth

        for (vector<Pixel> r : image) image_copy.push_back(r);

        image.clear();

        for (int i = 0; i < a; i++)
        {
            vector<Pixel> row;
            for (int j = b-1; j >= 0; j--)
            {
                row.push_back(image_copy[j][i]);
            }

            image.push_back(row);
        }
    }
}