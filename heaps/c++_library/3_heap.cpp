#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long N, M, tmp;
    vector<long long> v;
    fin >> N >> M;
        make_heap(v.begin(), v.end());
    for (long long i=0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        push_heap(v.begin(), v.end()); 
        for(int i = 0; i < v.size(); i++) 
        {
            fout << v[i] << ' ';
        }
        fout << '\n';
    }
}