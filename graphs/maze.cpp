#include <fstream>
#include <vector>

const int MAXSIZE = 100;
const int WALL = -1;
const int BLANK = -2; 

int lee(std::vector<int> maze[MAXSIZE], int ax, int ay, int bx, int by, int N)
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int wave = 0;
    bool stop;

    maze[ay][ax] = 0;
    
    do
    {
        stop = true; 
        for (auto y = 0; y < N; ++y)
            for (auto x = 0; x < N; ++x)
                if (maze[y][x] == wave) 
                {
                    for (auto k = 0; k < 4; ++k) 
                    {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 && iy < N && ix >= 0 && ix < N &&
                            maze[iy][ix] == BLANK)
                        {
                            stop = false;       
                            maze[iy][ix] = wave + 1; 
                        }
                    }
                }
        wave++;
    } while (!stop && maze[by][bx] == BLANK);

    return maze[by][bx];
}

int main()
{
    int N, x , y, x1 ,y1;
    char cell;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::vector<int> maze[MAXSIZE];
    fin >> N >> x >> y >> x1 >> y1;
    x--, y--, x1--, y1--;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fin >> cell;
            int a = (cell == '#' ? WALL : BLANK);
            maze[i].push_back(a);
        }
    }
    fout << lee(maze,x, y, x1, y1, N);
}
