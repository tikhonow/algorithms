#include <vector>
#include <fstream>
#include <algorithm>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

class hash
{
    std::vector<int> values[1000000];

public:
    void del(int value)
    {
        int key = getKey(value);
        int a = serch(value, key);
        if (a != -1)
        {
            values[key].erase(values[key].begin() + a);
        }
    }

    void push(int value)
    {
        int key = getKey(value);
        if (serch(value, key) == -1)
        {
            values[key].push_back(value);
        }
    }

    void output()
    {
    std::vector<int> sorted;
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 0; j < values[i].size(); j++)
        {
            sorted.push_back(values[i][j]);
        }
    }
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < sorted.size(); i++)
    {
        fout << sorted[i] << ' ';
    }
    }

private:
    int getKey(int value)
    {
        return (value % 1024);
    }

    int serch(int value, int key)
    {
        int ans = -1;
        for (int i = 0; i < values[key].size(); i++)
            if (values[key][i] == value)
                ans = i;
        return ans;
    }
};
hash table;

int main()
{
    int a = 1;
    while (a != 0)
    {
        fin >> a;
        if (a > 0)
        {
            table.push(a);
        }
        else
        {
            table.del(-a);
        }
    }
    table.output();
}