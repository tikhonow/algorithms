#include <fstream>
#include <stack>
#include <vector>

std::vector<int> g[100000];
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int N;
void eulerian_cycle(int v)
{
    while (g[v].size())
    {
        int tmp = g[v].back();
        g[v].pop_back();
        int i;
        for (i = 0; i < g[tmp].size() && g[tmp][i] != v; i++);
        g[tmp].erase(g[tmp].begin() + i);

        eulerian_cycle(tmp);
    }

    fout << v + 1 << " ";
}

void correct()
{
    for (int i = 0; i < N; i++)
    {
        if (g[i].size() % 2 != 0)
        {
            fout << -1;
            exit(0);
        }
    }
}
int main()
{
    int M;
    fin >> N >> M;
    int a, b;

    for (int i = 0; i < M; i++)
    {
        fin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    correct();
    eulerian_cycle(0);

    fin.close();
    fout.close();
    return 0;
}