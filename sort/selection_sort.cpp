#include <fstream>

int main() 
{ 
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int size_array;
    fin >> size_array;
    int array[size_array];
    int min;
    int min_i;
    for(int i = 0; i < size_array; i++)
    {
        fin >> array[i];
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
        fout << array[k] << ' ';
    }

    return 0; 
}