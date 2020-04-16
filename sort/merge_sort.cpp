#include <fstream>
#include <vector>
#include <fstream>

using namespace std;

class Sorts
{
    int count = 0;

private:
    void merge(int arr[], int l, int m, int r)
    {
        int index_left, index_right, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for (index_left = 0; index_left < n1; index_left++)
            L[index_left] = arr[l + index_left];
        for (index_right = 0; index_right < n2; index_right++)
            R[index_right] = arr[m + 1 + index_right];
        index_left = 0;
        index_right = 0;
        k = l;
        while (index_left < n1 && index_right < n2)
        {
            if (L[index_left] <= R[index_right])
            {
                arr[k] = L[index_left];
                index_left++;
            }
            else
            {
                arr[k] = R[index_right];
                index_right++;
                count = index_left + 1;
            }
            k++;
        }

        while (index_left < n1)
        {
            arr[k] = L[index_left];
            index_left++;
            k++;
        }
        while (index_right < n2)
        {
            arr[k] = R[index_right];
            index_right++;
            k++;
        }
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
    int inverse()
    {
        return count;
    }
};
Sorts sort;
int main()
{

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        fin >> arr[i];
    }
    sort.mergeSort(arr, 0, N - 1);
    fout << sort.inverse();
}