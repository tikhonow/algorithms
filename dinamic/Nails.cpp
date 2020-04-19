#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#define MIN(a,b) ((a) < (b) ? (a) : (b))


using namespace std;

int cmp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N, n;
    fin >> N;
    int nails[105];
    for (int i = 0; i < N; i++)
    {
        fin >> nails[i];
    }
    qsort(nails, N, sizeof(int),cmp);
    int threads [105];
    threads[1] = nails[1] - nails[0];
    threads[2] = nails[2] - nails[0];
    if (N > 3)
    {
        for (int i = 3;i < N; i++)
        {
            int first_variant = threads[i - 1];
            int second_variant = threads[i - 2];
            threads[i] = MIN(first_variant, second_variant) + nails[i] - nails[i - 1];
        }
    }
    fout << threads[N - 1];
}