#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int Partition(vector<int> &Array, int left, int right)
{
    int supp = Array[(left + right) / 2];
    int i = left - 1;
    int j = right + 1;
    while (true)
    {
        do
        {
            i++;
        } while (Array[i] < supp);

        do
        {
            j--;
        } while (Array[j] > supp);

        if (i >= j)
        {
            return j;
        }
        swap(Array[i], Array[j]);
    }
}

int RandomPartition(vector<int> &Array, int left, int right)
{
    int i = left + rand() % (right - left + 1);
    swap(Array[right], Array[i]);
    return Partition(Array, left, right);
}

int k_order_stat(vector<int> &Array, int K)
{
    int left = 0;
    int right = Array.size() - 1;

    int mid = 0;
    while (true)
    {
        mid = RandomPartition(Array, left, right);

        if (mid == K)
        {
            return Array[mid];
        }
        else if (K < mid)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
}

int main()
{
    srand(time(NULL));
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N = 0;
    int K = 0;
    int result = 0;

    fin >> N;
    vector<int> Array(N);
    fin >> K;
    K--;

    for (int i = 0; i < N; i++)
    {
        fin >> Array[i];
    }

    result = k_order_stat(Array, K);

    fout << result;

    return 0;
}