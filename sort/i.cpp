#include <fstream>
using namespace std;
int inverses(int *A, int N)
{ 
    int count = 0;
    for(int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if( A[i] > A[j] )
            {
                count++;   
            }
            
        }
    }
    return count;
}
int main()
{
    ofstream fout;
    fout.open("output.txt");
    ifstream fin;
    fin.open("input.txt");
    int N;
    fin >> N;
    int A[N];
    for(int i = 0; i< N; i++)
    {
        fin >>A[i];
    }
    fout << inverses(A, N);
}
