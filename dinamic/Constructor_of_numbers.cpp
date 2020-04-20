#include <iostream>
#include <fstream>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int check_star(int left, int star, int right)
{
    int max = MAX(left, right);
    if (max == 9)
    {
        max--;
        if (max == left || max == right)
        {
            max--;
        }
    }
    else
        max = 9;
    while ((star < max))
    {
        star++;
    }
    return star;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin >> N;
    string S;
    fin >> S;
    int a[N + 2];
    a[0] = -1;
    a[N + 1] = -1;
    int s = 0;
    int max_cool = 72 * (N - 1);
    int left, right, star;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == '*')
        {
            left = a[i];
            star = atoi(&S[i]);
            if (i == N - 1)
            {
                right = a[N + 1];
            }
            else
                right = atoi(&S[i + 1]);
            a[i + 1] = check_star(left, star, right);
        }
        else
            a[i + 1] = atoi(&S[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        s = s + a[i] * a[i + 1];
    }
    int answer = max_cool - s;
    fout << answer;
}