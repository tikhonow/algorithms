#include <iostream>
using namespace std;
void quicksort(int *A, int low, int high)
{
    if (low < high)
    {
        int s = A[(low + high)/2];
        quicksort(A, low, s - 1);
        quicksort(A, s + 1, high);
    }       
}
int main()
{
    int n;
    cin >>  n;
    int A[n];
   
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    quicksort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }
}