#include "DominantColour.h"

double distance(Pixel p1, Pixel p2)
{
    int d1 = (p1.r-p2.r)*(p1.r-p2.r);
    int d2 = (p1.r-p2.r)*(p1.r-p2.r);
    int d3 = (p1.r-p2.r)*(p1.r-p2.r);

    return d1+d2+d3;
}

bool change_clusters(Pixel arr[], vector< vector<Pixel> > &clusters, int k)
{
    bool change = false;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < clusters[i].size(); j++)
        {
            int m_index = 0;
            Pixel p = clusters[i][j];
            for (int c = 1; c < k; c++)
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
    int k = 50;
    vector< vector<Pixel> > clusters;
    Pixel arr[k];
    for (int i = 0; i < k; i++)
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
            for (int c = 1; c < k; c++)
            {
                if (distance(arr[c], p) < distance(arr[m_index], p)) m_index = c;
            }

            clusters[m_index].push_back(p);
        }
    }

    int run = 3;
    while (run--)
    {
        for (int i = 0; i < k; i++)
        {
            long long int sum_r = 0;
            long long int sum_g = 0;
            long long int sum_b = 0;
            long long int num = clusters[i].size();

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

        bool change = change_clusters(arr, clusters, k);

        if (!change) break;
    }

    int index = 0;
    for (int i = 1; i < k; i++)
    {
        if (clusters[index].size() < clusters[i].size()) index = i;
    }

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            image[i][j].r = arr[index].r;;
            image[i][j].g = arr[index].g;
            image[i][j].b = arr[index].b;

        }
    }
}