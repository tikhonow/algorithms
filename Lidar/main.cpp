/*#include <fstream>

using namespace std;

class lidar
{

}*/
#define NDEBUG
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cassert>
#include <algorithm>
#include <functional>
#include <fstream>

using namespace std;

double update(vector<double> scan)
{
    const auto median_it = scan.begin() + scan.size() / 2;
    nth_element(scan.begin(), median_it, scan.end());
    auto median = *median_it;

    assert(!scan.empty());
    if (scan.size() % 2 == 0)
    {
        const auto median_it1 = scan.begin() + scan.size() / 2 - 1;
        const auto median_it2 = scan.begin() + scan.size() / 2;

        std::nth_element(scan.begin(), median_it1, scan.end());
        const auto e1 = *median_it1;

        std::nth_element(scan.begin(), median_it2, scan.end());
        const auto e2 = *median_it2;

        return (e1 + e2) / 2;
    }
    else
    {
        const auto median_it = scan.begin() + scan.size() / 2;
        std::nth_element(scan.begin(), median_it, scan.end());
        return *median_it;
    }
}
int main()
{
    ifstream fin("input.txt");
    int n, i;
    double tmp;
    cout << "Input the vector size: " << endl;
    cin >> n;
    vector<double> foo(n);
    for (i = 0; i < n; i++)
    {
        fin >> tmp;
        foo[i] = tmp;
    }
    double median;
    median = update(foo);

    cout << median << endl;
}