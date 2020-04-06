#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long N, M, tmp;
    vector<long long> thirst;
    fin >> N >> M;
    for (long long i=0; i < N; i++)
    {
        fin >> tmp;
        thirst.push_back(tmp);
    }
    make_heap(thirst.begin(), thirst.end());
    long long max;
    for (long long i=0; i < M; i++)
    {
        max = thirst.front();
        max = max/10;
        pop_heap(thirst.begin(), thirst.end()); 
        thirst.pop_back(); 
        thirst.push_back(max);
        push_heap(thirst.begin(), thirst.end()); 
    }
    fout << accumulate(thirst.begin(), thirst.end(), 0);
}
