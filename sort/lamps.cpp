#include <fstream>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int N;
    fin >> N;
    int array[101] = {0};
    int max = 0;   
    for (int i = 0; i < N; i++)
    {
        int x,y;
        fin >> x;
        int left = x - y;
        int right = x + y;
        if (left < 0)
            left = 0;
        if (right > 101)
            right = 99;
        for (int j = left; j < right; ++j)
            array[j]++;
    }
    for (int i = 0; i < 100; ++i)
    {
        if (max < array[i])
            max = array[i];
    }
    fout << max;
}