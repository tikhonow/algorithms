#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int m = 1000000;
std::vector<int> DoubleHashing(m, -1);

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

void Delete(int x)
{
    int hash = (x % m);
    // Double Hashing - Insert
    int hash2 = 1 + (x % (m - 1)); // 1 + (k mod (m - 1))
    int k = 0;
    int hashDouble = (hash + k * hash2) % m;
    while (DoubleHashing[hashDouble] != -1 && DoubleHashing[hashDouble] != x && k < m)
    {
        k++;
        hashDouble = (hash + k * hash2) % m;
    }
    DoubleHashing[hashDouble] = -2;

    return;
}

void Insert(int x)
{
    int hash = (x % m);
    if (DoubleHashing.at(hash) == x)
    {
        return;
    }
    // Double Hashing - Insert
    int hash2 = 1 + (x % (m - 1)); // 1 + (k mod (m - 1))
    int k = 0;
    int hashDouble = (hash + k * hash2) % m;
    while (DoubleHashing[hashDouble] != -1 && DoubleHashing[hashDouble] != -2 && k < m)
    {
        k++;
        hashDouble = (hash + k * hash2) % m;
    }
    DoubleHashing[hashDouble] = x;

    return;
}

int main()
{
    int size = 0, LinCol = 0, QuadCol = 0, DoubCol = 0;
    int a = 1;
    while (a != 0)
    {
        fin >> a;
        if (a > 0)
        {
            Insert(a);
            size++;
        }
        else
        {
            Delete(-a);
            size--;
        }
    }

    std::sort(DoubleHashing.begin(), DoubleHashing.end());
    for (int i = 0; i < m; i++)
    {
        if (DoubleHashing[i] > 0)
        {
            fout << DoubleHashing[i] << "  ";
        }
    }
}