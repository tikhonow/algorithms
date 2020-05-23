#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

long long array[MAX];
long long n, i, j;
long long inversions;

void merge(long long left, long long middle, long long right)
{
  long long i = left, j = middle + 1;
  while((i <= middle) && (j <= right))
  {
    if (array[i] <= array[j])
      i++;
    else
    {
      j++;
      inversions += middle - i + 1;
    }
  }
  sort(array + left, array + right + 1);
}

void mergeSort(long long left, long long right)
{ 
  if (left < right)
  {
    long long middle = (left + right) / 2;
    mergeSort(left,middle);
    mergeSort(middle+1,right);
    merge(left, middle, right);
  }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n;
    for (i = 0; i < n; i++)
    {
        fin >> array[i];
    }
    fin.close();
    mergeSort(0, n - 1);
    fout << inversions;
    fout.close();
  return 0;

}