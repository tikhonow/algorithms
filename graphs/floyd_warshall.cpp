#include <algorithm>
#include <fstream>
#include <vector>
#define INF 100000001

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int N;
std::vector<std::vector<int>> g(100,std::vector<int>(100,INF));


void Floyd()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if(g[j][i] < INF && g[i][k] < INF)
                    g[j][k] = std::min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }
}

int main() 
{	
    int M;
    fin >> N >> M;
    for (int i = 0; i < N; i++)
        g[i][i] = 0;

    int a,b,weight;

    for (int i = 0; i < M; i++)
    {
        fin >> a >> b >> weight;
        g[a-1][b-1] = weight;
    }
    
    Floyd();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(g[i][j] != INF)
                fout << g[i][j] << " ";
        }
        fout << std::endl;
    }
    
	fin.close();
    fout.close();
	return 0;
}