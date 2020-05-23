#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

int main()
{
    std::ifstream fin("linear.in");
    std::ofstream fout("linear.out");
    int N;
    fin >> N;
    std::vector <long long> particle_storage;
    std::vector <long long> collision_times;
    for (long long i = 0; i < N; i++)
    {
        double x, y;
        fin >> x >> y;
        if (y == 1)
        {
            particle_storage.push_back(x);
        }
        else
        {
            if (particle_storage.size() != 0)
            {
                collision_times.push_back(ceil(abs((x - particle_storage.back()) / 2)));
                particle_storage.pop_back();
            }
        }
    }
    sort(collision_times.begin(), collision_times.end());
    long long  count_requests;
    fin >> count_requests;
    long long  k = 0;
    for (long long j = 0; j < count_requests; j++)
    {
        long long time;
        
        fin >> time;
        while (k < collision_times.size() && collision_times[k] <= time)
        {
            k++;
        }
        long long count_remaining_particles = N - 2*k;
        fout << count_remaining_particles << '\n';
    }
}