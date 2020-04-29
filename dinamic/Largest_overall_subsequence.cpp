#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string A;
    string B;
    fin >> A;
    fin >> B;
    int n = A.length();
    int m = B.length();
    int i = 1;
    int j = 1;
    int F[1000+1][1000 + 1] = {};
    for (i; i < n + 1; i++)
    {
        for (j; j < m +1; j++)
        {
            if (A[i -1] == B[j - 1])
            {
                F[i][j] = F[i - 1][j - 1] + 1;
            }
            else 
            {
               F[i][j] = MAX(F[i - 1][j], F[i][j - 1]);
            }
        }
    }
    i = n;
    j = m;
    vector<char> sequence;
    //вывод найденной последовательности
    while (i*j > 0)
    {
        if (A[i - 1] == B[j -1])
        {
            sequence.push_back(A[i - 1]);
            i--;
            j--;
            
        }
        else if (F[i - 1][j] == F[i][j])
        {
            /* code */i--;
        }
        
        
    }
    cout << sequence[0];
    cout << sequence[1];
    cout << sequence[2];
    cout << sequence[3];
}
