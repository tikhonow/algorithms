#include <fstream>
#include <vector>
using namespace std;

vector<int> arr1;
vector<int> arr2;
void merge_and_finding_inversions(int low, int high, int mid);
int count;

void mergesort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge_and_finding_inversions(low, high, mid);
    }
    return;
}


void merge_and_finding_inversions(int low, int high, int mid)
{
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr1[i] < arr1[j])
        {
            arr2[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr2[k] = arr1[j];
            k++;
            j++;
            count += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        arr2[k] = arr1[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        arr2[k] = arr1[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr1[i] = arr2[i];
    }
}
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;
    count = 0;
    arr1.resize(N);
    arr2.resize(N);
    for (int i = 0; i < N; i++)
    {
        fin >> arr1[i];
    }
    mergesort(0, N - 1);

    fout << count << "\n";
}