#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

int Partition(std::vector<int> &Array, int left, int right)
{

    int supp = Array[left + rand() % (right - left)];
     //Array[(left + right) / 2];
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
        std::swap(Array[i], Array[j]);
    }
}

int RandomPartition(std::vector<int> &Array, int left, int right)
{
    int i = left + rand() % (right - left);
    std::swap(Array[right], Array[i]);
    return Partition(Array, left, right);
}

int k_order_stat(std::vector<int> &Array, int K)
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
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int N = 0;
    int K = 0;
    int result = 0;

    fin >> N >> K;
    std::vector<int> Array(N);
    K--;

    for (int i = 0; i < N; i++)
    {
        fin >> Array[i];
    }

    result = k_order_stat(Array, K);

    fout << result;

    return 0;
}