#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long N, M, tmp;
    vector<long long> sequence;
    fin >> N >> M;
    for (long long i=0; i < N; i++)
    {
        fin >> tmp;
        sequence.push_back(tmp);
    }
    int min1, min2;
    for (int i=0; i < M; i++)
    {
        min1 = *min_element(sequence.begin(), sequence.end());
        sequence.erase(remove(sequence.begin(), sequence.end(), min1), sequence.end());
        min2 = *min_element(sequence.begin(), sequence.end());
        sequence.erase(remove(sequence.begin(), sequence.end(), min2), sequence.end());
        sequence.push_back(min1 + min2);
    }
    //copy(sequence.begin(), sequence.end(), std::ostream_iterator+<int>(fout, " "));
    for(long long i = 0; i < sequence.size(); i++) 
    {
        fout << sequence[i] << ' ';
    }
}