#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin >> N;
    vector<int> particle_storage;
    vector<int> collision_times;
    for (int i = 0; i < N; i++)
    {
        float x, y;
        fin >> x >> y;
        if (y == 1)
        {
            particle_storage.push_back(x);
        }
        else
        {
            if (particle_storage.size() != 0)
            {
                collision_times.push_back(ceil((x - particle_storage.back()) / 2));
                particle_storage.pop_back();
            }
        }
    }
    sort(collision_times.begin(), collision_times.end());
    int count_requests;
    fin >> count_requests;
    for (int j = 0; j < count_requests; j++)
    {
        int time;
        int k = 0;
        fin >> time;
        while (k < collision_times.size() && collision_times[k] <= time)
        {
            k++;
        }
        int count_remaining_particles = N - 2*k;
        fout << count_remaining_particles << '\n';
    }
}