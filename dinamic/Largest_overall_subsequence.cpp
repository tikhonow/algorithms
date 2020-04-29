#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string A, B;
    fin >> A >> B;
    int n = A.length();
    int m = B.length();
    
    int LCS[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {     // Цикл, который идёт по строкам
        for (int j = 0; j < m + 1; j++) // Цикл, который идёт по элементам
        {
            LCS[i][j] = 0; // Заполнение вектора или массива (в данном случае ввод)
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j ++)
        {
            if (A[i - 1] == B[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else 
            {
                LCS[i][j] = MAX(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    //cout << LCS[n][m];
    int i = n;
    int j = m;
    string sub;
    int index = 0;
    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[i - 1])
        {
            sub.insert(0,1,A[i - 1]);
            i --;
            j --;
        }
        else 
        {
            if (LCS[i - 1][j] == LCS[i][j])
        {
            i--;
        }
        else
        {
            j--;
        }
        }
    }
    cout << sub;
}