#include <vector>
#include <fstream>

std::vector<int> g[100000];
bool used[100000] = {false};
int N, count;

void dfs(int v)
{
    used[v] = true;
    for (auto i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
    count++;
    

}

int topsort()
{
    for (int i = 0; i < N; ++i)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    return count;
}

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int M;
    fin >> N >> M;
    int module1, module2;
    for (int i = 0; i < M; i++)
    {
        fin >> module1 >> module2;
        g[module1 - 1].push_back(module2 - 1);
        g[module2 - 1].push_back(module1 - 1);
    }

    fout << topsort();

    fin.close();
    fout.close();
    return 0;
}