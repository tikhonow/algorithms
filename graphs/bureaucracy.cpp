#include <fstream>
#include <vector>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int N;
std::vector<int> g[100000];
std::vector<int> ans;
int visited[100000] = {0};
bool cycle = false;

void dfs(int v)
{
    visited[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (visited[g[v][i]] == 0)
        {
            dfs(g[v][i]);
        }
        else if (visited[g[v][i]] == 1)
        {
            cycle = true;
            return;
        }
    }
    visited[v] = 2;
    ans.push_back(v + 1);
}

void pr1()
{
    fout << -1;
}

void pr()
{
    for (int i = ans.size() - 1; i >= 0; i--)
        fout << ans[i] << " ";
}
int main()
{
    int M;
    fin >> N >> M;

    int offical1, offical2;

    for (int i = 0; i < M; i++)
    {
        fin >> offical1 >> offical2;
        g[offical1 - 1].push_back(offical2 - 1);
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    (cycle) ? pr1():pr();

    fin.close();
    fout.close();
    return 0;
}