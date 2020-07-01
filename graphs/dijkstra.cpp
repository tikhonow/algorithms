#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define INF 1000000001
int N;
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
std::vector<std::vector<std::pair<long long,long long>>> g(100000);	
std::vector<bool> visited(100000, false);

void Dijkstra(std::vector<int>& d, int start)
{
    d[start] = 0;
    std::priority_queue <std::pair<long long,long long>> q;
    q.push(std::pair<long long,long long>(0,start));
    while (!q.empty())
    {
        int v = q.top().second, dir = -q.top().first; q.pop();
        if(dir > d[v] || visited[v]) continue;
    
        for (int i = 0; i < g[v].size(); i++)
        {
            if(d[v] + g[v][i].second < d[g[v][i].first])
            {
                d[g[v][i].first] = d[v] + g[v][i].second; 
                q.push(std::pair<long long,long long>(-d[g[v][i].first], g[v][i].first)); 
            }
            visited[v] = true;
        }
    }
}

int main() 
{
    int M, start;
    fin >> N >> M >> start;
    
    int a,b,weight;

    for (int i = 0; i < M; i++)
    {
        fin >> a >> b >> weight;
        g[a-1].push_back(std::pair<long long,long long>(b-1,weight));
    }

    std::vector<int> dist(N, INF);

    Dijkstra(dist,start-1);
    
    for (int i = 0; i < dist.size(); i++)
    {
        if(dist[i] == INF)
            fout << -1 << std::endl;
        else
            fout << dist[i] << std::endl;
    }   
	fin.close();
    fout.close();
	return 0;
}