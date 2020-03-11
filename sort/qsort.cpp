#include <iostream>
using namespace std;
void qs(int *array, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, supporting_element = array[(left + right) / 2];
        do
        {
            while (array[left]  < supporting_element) left++;
            while (array[right] > supporting_element) right--;
            if (left <= right)
            {
                int tmp = array[left];
                array[left] = array[right];
                array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(array, first, right);
        qs(array, left, last);
    }
}
int main()
{
    
    int size_array;
    cin >> size_array;
    int array[size_array];
    for (int i = 0; i < size_array; i++)
    {
        cin >> array[i];
    }
    qs(array,0,size_array-1);
    for (int i = 0; i < size_array; i++)
    {
        cout << array[i];
    }
}
