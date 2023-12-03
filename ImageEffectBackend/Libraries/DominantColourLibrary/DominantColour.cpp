#include "DominantColour.h"


void bubble_sort(int output_arr[], vector < vector<Pixel> > &clusters)
{
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (clusters[output_arr[i]].size() > clusters[output_arr[j]].size())
            {
                int temp = output_arr[i];
                output_arr[i] = output_arr[j];
                output_arr[j] = temp;
            }
        }
    }
}

bool pixel_comparator(Pixel p1, Pixel p2)
{
    if (p1.r > p2.r) return true;
    else if (p1.r < p2.r) return false;
    else
    {

        if (p1.g > p2.g) return true;
        else if (p1.g < p2.g) return false;
        else
        {
            if (p1.b > p2.b) return true;
            else return false;
        }
    }
}

double distance(Pixel p1, Pixel p2)
{
    int d1 = (p1.r-p2.r)*(p1.r-p2.r);
    int d2 = (p1.r-p2.r)*(p1.r-p2.r);
    int d3 = (p1.r-p2.r)*(p1.r-p2.r);

    return d1+d2+d3;
}

bool change_clusters(Pixel arr[], vector< vector<Pixel> > &clusters)
{
    bool change = false;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < clusters[i].size(); j++)
        {
            int m_index = 0;
            Pixel p = clusters[i][j];
            for (int c = 1; c < K; c++)
            {
                if (distance(arr[c], p) < distance(arr[m_index], p)) m_index = c;
            }

            if (m_index != i)
            {
                change = true;
                auto it = clusters[i].begin();
                clusters[i].erase(it+j);
                clusters[m_index].push_back(p);
            }
        }
    }

    return change;
}

void findDominantColour(vector< vector<Pixel> > &image)
{
    srand(20);
    vector< vector<Pixel> > clusters;
    Pixel arr[K];
    for (int i = 0; i < K; i++)
    {
        Pixel p = {.r = rand()%256, .g = rand()%256, .b = rand()%256};
        arr[i] = p;
        vector<Pixel> pixels;
        clusters.push_back(pixels);
    }

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            int m_index = 0;
            Pixel p = image[i][j];
            for (int c = 1; c < K; c++)
            {
                if (distance(arr[c], p) < distance(arr[m_index], p)) m_index = c;
            }

            clusters[m_index].push_back(p);
        }
    }

    int run = 3;
    while (run--)
    {
        for (int i = 0; i < K; i++)
        {
            long long int sum_r = 0;
            long long int sum_g = 0;
            long long int sum_b = 0;
            long long int num = clusters[i].size();

            if(num!=0){
                for (int j = 0; j < num; j++)
                {
                    sum_r += clusters[i][j].r;
                    sum_g += clusters[i][j].g;
                    sum_b += clusters[i][j].b;
                }


                arr[i].r = sum_r/num;
                arr[i].g = sum_g/num;
                arr[i].b = sum_b/num;
            }
        }

        bool change = change_clusters(arr, clusters);

        if (!change) break;
    }

    int sorted_arr[K];
    for (int i = 0; i < K; i++) sorted_arr[i] = i;

    bubble_sort(sorted_arr, clusters);

    Pixel display_colours[N_DOM_COLOURS];
    for (int i = 0; i < N_DOM_COLOURS; i++) display_colours[i] = arr[sorted_arr[i]];

    sort(display_colours, display_colours+N_DOM_COLOURS, pixel_comparator);

    int breadth = image.size();
    for (int c = 0; c < N_DOM_COLOURS; c++)
    {
        for (int i = c*breadth/N_DOM_COLOURS; i < max((c+1)*breadth/N_DOM_COLOURS, breadth); i++)
        {
            for (int j = 0; j < image[i].size(); j++)
            {
                image[i][j].r = display_colours[c].r;;
                image[i][j].g = display_colours[c].g;
                image[i][j].b = display_colours[c].b;

            }
        }
    }
}