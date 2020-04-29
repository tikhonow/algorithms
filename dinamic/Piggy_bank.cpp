#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int E, F, N;
    fin >> E >> F >> N;
    int coin_weight = F - E;
    vector<pair<int, int>> coins;

    pair<int, int> pair;

    vector<int> swin(coin_weight + 1, 10000);

    swin[0] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        fin >> pair.first;
        fin >> pair.second;
        for (int j = 0; j < coin_weight + 1; j++)
        {
            if (j >= pair.second)
            {
                if (swin[j] < (swin[j - pair.second] + pair.first))
                {
                    swin[j] = swin[j];
                }
                else
                {
                    swin[j] = swin[j - pair.second] + pair.first;
                }
            }
        }
    }

    if (swin[coin_weight] == 10000)
    {
        fout << -1;
    }
    else
    {
        fout << swin[coin_weight];
    }
}