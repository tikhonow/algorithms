#include <fstream>
#include <vector>
#include <stack>

std::vector<int> g[100000];
std::vector<int> ans;
std::stack<int> st;

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

bool correct(int N)
{
    for (int i = 0; i < N; i++)
        if (g[i].size() % 2 == 1)
            return false;
    return true;
}

void eulerian_cycle(int v)
{
    if (v == -1)
    {
        fout << -1;
        return;
    }
    st.push(v);
    while (!st.empty())
    {
        int v = st.top();
        if (g[v].size() == 0)
        {
            ans.push_back(v + 1);
            st.pop();
        }
        else
        {
            int t;
            t = g[v][g[v].size() - 1];
            for (int i = 0; i < g[t].size(); i++)
                if (g[t][i] == v)
                {
                    std::swap(g[t][i], g[t][g[t].size() - 1]);
                    g[t].pop_back();
                    break;
                }
            g[v].pop_back();
            st.push(t);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        fout << ans[i] << ' ';
}

int main()
{

    int N, M;
    fin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        fin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    (!correct(N)) ? eulerian_cycle(-1): eulerian_cycle(0);

}