#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long N, tmp;
    vector<long long> sequence;
    fin >> N;
    for (long long i=0; i < N; i++)
    {
        fin >> tmp;
        sequence.push_back(tmp);
        sort(sequence.begin(), sequence.end());
        if (sequence.size() < 3) fout << sequence[0] << ' ';
        else fout << sequence[(i+1)/2] << ' ';
    }
}