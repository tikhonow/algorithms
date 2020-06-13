#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

int main()
{
    
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int N;
    fin >> N;
    std::vector <std::pair<int, bool>> dot(N * 2);
    std::vector <std::pair<int, int>> xy(N);
    for (int i = 0; i < N; i++)
    {
        fin >> xy[i].first >> xy[i].second;
        dot[i].first = xy[i].first - xy[i].second;
        dot[i].second = false;
        dot[2 * N - i - 1].first = xy[i].first + xy[i].second;
        dot[2 * N - i - 1].second = true;
    }
    sort(dot.begin(), dot.end());

    int max = 0;
    int counter = 0;

    for (int i = 0; i < N * 2 ; i++)
    {
        if (dot[i].second)
            counter--;
        else
            counter++;
        if (counter > max)
            max = counter;

    }
    fout << max;
}