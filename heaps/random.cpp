#include <fstream>
#include <iostream>
using namespace std;
int main()
{
    ofstream fout("input.txt");
    int N,A,B;
    cin >> N >> A >> B;
    cout << "File is generate!";
    for (int i=0; i < N; i++)
    {
        fout << rand() % (B - A + 1) + A;
        fout << ' ';
    }  
}