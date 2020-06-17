#include <fstream>

using namespace std;
const int W = 100;     // ширина рабочего поля
const int H = 100;      // высота рабочего поля
const int WALL = -1;  // непроходимая ячейка
const int BLANK = -2; // свободная непомеченная ячейка
int N;

int px[W * H], py[W * H]; // координаты ячеек, входящих  путь
int len;                  // длина пути
int grid[H][W];           // рабочее поле

// Перед вызовом lee() массив grid заполнен значениями WALL и BLANK

int  lee(int ax, int ay, int bx, int by) // поиск пути из ячейки (ax, ay) в ячейку (bx, by)
{
    int dx[4] = {1, 0, -1, 0}; // смещения, соответствующие соседям ячейки
    int dy[4] = {0, 1, 0, -1}; // справа, снизу, слева и сверху
    int d, x, y, k;
    bool stop;

    // распространение волны
    d = 0;
    grid[ay][ax] = 0; // стартовая ячейка помечена 0
    do
    {
        stop = true; // предполагаем, что все свободные клетки уже помечены
        for (y = 0; y < N; ++y)
            for (x = 0; x < N; ++x)
                if (grid[y][x] == d) // ячейка (x, y) помечена числом d
                {
                    for (k = 0; k < 4; ++k) // проходим по всем непомеченным соседям
                    {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 && iy < N && ix >= 0 && ix < N &&
                            grid[iy][ix] == BLANK)
                        {
                            stop = false;         // найдены непомеченные клетки
                            grid[iy][ix] = d + 1; // распространяем волну
                        }
                    }
                }
        d++;
    } while (!stop && grid[by][bx] == BLANK);

    // восстановление пути
    len = grid[by][bx]; // длина кратчайшего пути из (ax, ay) в (bx, by)
    return len;
    x = bx;
    y = by;
    d = len;
    while (d > 0)
    {
        px[d] = x;
        py[d] = y; // записываем ячейку (x, y) в путь
        d--;
        for (k = 0; k < 4; ++k)
        {
            int iy = y + dy[k], ix = x + dx[k];
            if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
                grid[iy][ix] == d)
            {
                x = x + dx[k];
                y = y + dy[k]; // переходим в ячейку, которая на 1 ближе к старту
                break;
            }
        }
    }
    px[0] = ax;
    py[0] = ay; // теперь px[0..len] и py[0..len] - координаты ячеек пути;
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
