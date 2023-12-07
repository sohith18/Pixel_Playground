#include "HueSaturation.h"

/*
HSV to RGB :
https://en.wikipedia.org/wiki/HSL_and_HSV#Color_conversion_formulae

RGB to HSV:
https://www.rapidtables.com/convert/color/rgb-to-hsv.html
*/

// Convert RGB values to HSV values
void rgb_to_hsv(int rgb[], float hsv[])
{
    float r1 = (float)rgb[0]/(float)255;
    float g1 = (float)rgb[1]/(float)255;
    float b1 = (float)rgb[2]/(float)255;

    float rgb1[] = {r1, g1, b1};

    float cmax = max(max(r1, g1), b1);
    float cmin = min(min(r1, g1), b1);
    float delta = cmax - cmin;

    float h, s, v;

    if (delta == 0) h = 0;
    else if (cmax == r1) h = 60*(fmod((g1-b1)/delta, 6));
    else if (cmax == g1) h = 60*((b1-r1)/delta + 2);
    else h = 60*((r1-g1)/delta + 4);

    if (cmax == 0) s = 0;
    else s = delta/cmax;

    v = cmax;

    hsv[0] = h;
    hsv[1] = s;
    hsv[2] = v;
}

// Convery HSV values back to RGB
void hsv_to_rgb(float hsv[], int rgb[])
{
    float h = hsv[0];
    float s = hsv[1];
    float v = hsv[2];

    float c = v * s;
    float h1 = h/60;
    float x = c * (1 - abs(fmod(h1, 2)-1));

    float r1, g1, b1;

    if (h1 >= 0 && h1 < 1)
    {
        r1 = c; g1 = x; b1 = 0;
    }
    else if (h1 >= 1 && h1 < 2)
    {
        r1 = x; g1 = c; b1 = 0;
    }
    else if (h1 >= 2 && h1 < 3)
    {
        r1 = 0; g1 = c; b1 = x;
    }
    else if (h1 >= 3 && h1 < 4)
    {
        r1 = 0; g1 = x; b1 = c;
    }
    else if (h1 >= 4 && h1 < 5)
    {
        r1 = x; g1 = 0; b1 = c;
    }
    else
    {
        r1 = c; g1 = 0; b1 = x;
    }

    float m = v - c;

    rgb[0] = (r1+m)*255;
    rgb[1] = (g1+m)*255;
    rgb[2] = (b1+m)*255;
}


void applyHueSaturation(vector< vector<Pixel> > &image, float saturationValue, float hueValue) {
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0;j < image[i].size(); j++)
        {
           int r = image[i][j].r;
           int g = image[i][j].g;
           int b = image[i][j].b;

           float hsv[3];
           int rgb[] = {r, g, b};

           rgb_to_hsv(rgb, hsv);

           // Change hue and saturation values
           hsv[0] = hueValue*18/5;
           hsv[1] = saturationValue/100;

           hsv_to_rgb(hsv, rgb);

           image[i][j].r = rgb[0];
           image[i][j].g = rgb[1];
           image[i][j].b = rgb[2];
        }
    }
}


