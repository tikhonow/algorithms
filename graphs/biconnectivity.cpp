#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<int> g[100000];
bool visited[100000] = {false};
std::vector<int> timeIn;
std::vector<bool> answer;
int counter = 0;

int dfs(int& timer, int v, int p = -1)
{
    visited[v] = true;
    timeIn[v] = timer;
    int fv = timer++;
    int children = 0;
    for (int i = 0; i < g[v].size(); i++)
    {
        if(g[v][i] == p)
            continue;
        if (visited[g[v][i]])
            fv = std::min(fv,timeIn[g[v][i]]);
        else
        {
            int fnext = dfs(timer,g[v][i],v);
            fv = std::min(fv,fnext);
            if(fnext >= timeIn[v] && answer[v] != true  && p != -1)
            {
                answer[v] = true;
                counter++;
            }  
            children++;
        }
    }
    if(p == -1 && answer[v] != true  && children > 1)
    {
        answer[v] = true;
        counter++;
    }
    return fv;
}

int main()
{
    int N,M;
    fin >> N >> M;
    int tmpV1,tmpV2;
    timeIn = std::vector<int> (N);
    answer = std::vector<bool> (N,false);
    for (int i = 0; i < M; i++)
    {
        fin >> tmpV1 >> tmpV2 ;
        g[tmpV1-1].push_back(tmpV2-1);
        g[tmpV2-1].push_back(tmpV1-1);
    }

    int timer = 0;
    dfs(timer,0);

    fout << counter << " ";
    for (int i = 0; i < N; i++)
        if(answer[i])
            fout << i+1 << " ";
    
    fin.close();
	fout.close();
    return 0;
}