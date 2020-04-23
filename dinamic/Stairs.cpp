#include <fstream>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long n, a[102], b;
    fin >> n >> a[1];
    a[0] = 0;
    //Если количество ступеней – 1, ответ –
    if (n < 2)
    { // единственная ступенька.
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