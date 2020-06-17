#include <fstream>

using namespace std;
const int MAX = 100;
const int WALL = -1;
const int BLANK = -2; 
int N;

int px[W * H], py[W * H];
int len;
int grid[H][W];

int  lee(int ax, int ay, int bx, int by)
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int d, x, y, k;
    bool stop;

    d = 0;
    grid[ay][ax] = 0;
    do
    {
        stop = true; 
        for (y = 0; y < N; ++y)
            for (x = 0; x < N; ++x)
                if (grid[y][x] == d) 
                {
                    for (k = 0; k < 4; ++k) 
                    {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 && iy < N && ix >= 0 && ix < N &&
                            grid[iy][ix] == BLANK)
                        {
                            stop = false;       
                            grid[iy][ix] = d + 1; 
                        }
                    }
                }
        d++;
    } while (!stop && grid[by][bx] == BLANK);

    len = grid[by][bx]; 
    return len;
    x = bx;
    y = by;
    d = len;
    while (d > 0)
    {
        px[d] = x;
        py[d] = y; 
        d--;
        for (k = 0; k < 4; ++k)
        {
            int iy = y + dy[k], ix = x + dx[k];
            if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
                grid[iy][ix] == d)
            {
                x = x + dx[k];
                y = y + dy[k]; 
                break;
            }
        }
    }
    px[0] = ax;
    py[0] = ay; 
}

int main()
{
    int x , y, x1 ,y1;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> N >> x >> y >> x1 >> y1;
    for (int i = 0; i < 1;i++)
    {
        x--;
        y--;
        x1--;
        y1--;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char a;
            fin >> a;
            grid[i][j] = (a == '#' ? WALL : BLANK); //ставим стены
        }
    }
    fout << lee(x, y, x1, y1);
}
