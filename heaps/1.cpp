#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N, M, tmp;
    vector<int> thirst;
    fin >> N >> M;
    for (int i=0; i < N; i++)
    {
        fin >> tmp;
        thirst.push_back(tmp);
    }
    for (int i=0; i < M; i++)
    {
        vector<int>::iterator it = max_element(thirst.begin(), thirst.end());
        *it /= 10;
    }
    fout << accumulate(thirst.begin(), thirst.end(), 0);
}