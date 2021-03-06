#include <fstream>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    long long n, a[102], b;
    fin >> n >> a[1];
    a[0] = 0;
    if (n < 2)
    {
        fout << a[1];
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        fin >> b;
        a[i] = MAX(a[i - 1], a[i - 2]) + b;
    }
    fout << a[n];
    return 0;
}