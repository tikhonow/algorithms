#include <vector>
#include <algorithm>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

class doublehash
{
    int hashsize;
    std::vector<int> values;

private:

    int hash11(int x)
    {
        return(x % hashsize);
    }

    int hash22(int x)
    {
        return(1 + (x % (hashsize - 1)));
    }

public:

    doublehash()
    {
        hashsize = 1000000;
        for (int k = 0; k < hashsize; k++)
        {
            values.push_back(-1);
        }

    }

    void Delete(int x)
    {
        int hash = hash11(x);

        int hash2 = hash22(x);
        int k = 0;
        int hashDouble = (hash + k * hash2) % hashsize;
        while (values[hashDouble] != -1 && values[hashDouble] != x && k < hashsize)
        {
            k++;
            hashDouble = (hash + k * hash2) % hashsize;
        }
        values[hashDouble] = -2;

        return;
    }

    void Insert(int x)
    {
        int hash = hash11(x);
        if (values.at(hash) == x)
        {
            return;
        }

        int hash2 = hash22(x); 
        int k = 0;
        int hashDouble = (hash + k * hash2) % hashsize;
        while (values[hashDouble] != -1 && values[hashDouble] != -2 && k < hashsize)
        {
            k++;
            hashDouble = (hash + k * hash2) % hashsize;
        }
        values[hashDouble] = x;

        return;
    }

    void output()
    {
        std::sort(values.begin(), values.end());
        for (int i = 0; i < hashsize; i++)
        {
            if (values[i] > 0)
            {
                fout << values[i] << "  ";
            }
        }
    }
};

int main()
{
    doublehash table;
    int a = 1;
    while (a != 0)
    {
        fin >> a;
        a > 0 ? table.Insert(a) : table.Delete(-a);
    }
    table.output();
    fin.close();
    fout.close();
    return 0;
}