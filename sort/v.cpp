#include <iostream>
using namespace std;

int main() 
{ 
    int size_array;
    int K;
    cin >> size_array;
    cin >> K;
    int array[size_array];
    int min;
    int min_i;
    for(int i = 0; i < size_array; i++)
    {
        cin >> array[i];
    }
    for(int i = 0; i < size_array; i++) 
    {
        min_i = i;
        min   = array[i];
        for(int j = i + 1; j < size_array; j++)
        if ( array[j] < min ) 
        {
            min_i = j;
            min   = array[j];
        }

        array[min_i] = array[i]; 
        array[i] = min;
    }
    for (int k = 0; k< size_array; k++)
    {
        cout << array[K] << ' ';
    }

    return 0; 
}