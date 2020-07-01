#include <fstream>
#include <vector>
std::vector<long long> g[100002];
std::vector<bool> used(100002);
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int N, M, start = 0;
class gametur
{

private:
    void DFS(long long V, std::vector<bool> &used)
    {
        used[V] = true;
        for (long long i = 0; i < g[V].size(); i++)
        {
            long long to = g[V][i];
            if (!used[to])
                DFS(to, used);
        }
    }

    void print_DFS(long long V, std::vector<bool> &used)
    {
        used[V] = true;
        for (long long i = 0; i < g[V].size(); i++)
        {
            long long to = g[V][i];
            if (!used[to])
            {
                print_DFS(to, used);
                fout << V << ' ' << to << std::endl;
            }
        }
    }

    bool find_vertex(long long V, long long N)
    {
        std::vector<bool> used(100002, 0);
        DFS(V, used);
        for (long long i = 1; i <= N; i++)
        {
            if (!used[i])
                return false;
        }
        return true;
    }

    void DFS(long long V)
    {
        used[V] = true;
        for (int i = 0; i < g[V].size(); i++)
        {
            long long to = g[V][i];
            if (!used[to])
                DFS(to);
        }
    }

public:
    void tournament_start()
    {
        for (long long i = 1; i <= N; i++)
        {
            if (!used[i])
            {
                DFS(i);
                start = i;
            }
        }
        if (find_vertex(start, N))
        {
            fout << "Yes" << std::endl;
            std::vector<bool> used(100002, 0);
            print_DFS(start, used);
        }
        else
            fout << "No";
    }
};

int main()
{
    fin >> N >> M;
    for (long long i = 0; i < M; i++)
    {
        long v, to;
        fin >> v >> to;
        g[v].push_back(to);
    }
    gametur g;
    g.tournament_start();
    return 0;
}