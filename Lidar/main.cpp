#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double find_median(vector<double> arr)
{
    //Здесь должна быть функция поиска медианы
}
int main()
{
    int n, i;
    double tmp;
    cout << "Input the vector size: " << endl;
    cin >> n;
    vector<double> array(n);
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        array[i] = tmp;
    }
    double median;
    median = find_median(array);

    cout << median << endl;
}