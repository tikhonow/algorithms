#include <bitset>
#include <bits/stdc++.h>

int dp[(1 << 19)][19];
int a[20][20];
int n;
std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

long long int salesman_way()
{
    for (size_t i = 0; i < (1 << n); i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        dp[1 << i][i] = 0;
    }

    dp[0][0] = 0;

    for (size_t mask = 0; mask < (1 << n); mask++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (dp[mask][i] == INT_MAX)
                continue;
            for (size_t j = 0; j < n; j++)
            {
                if (!(mask & (1 << j)) && a[i][j] > 0)
                {
                    dp[mask ^ (1 << j)][j] = std::min(dp[mask ^ (1 << j)][j], dp[mask][i] + a[i][j]);
                }
            }
        }
    }

    long long int sum = INT_MAX;
    for (size_t i = 0; i < n; i++)
        if (dp[(1 << n) - 1][i] < sum)
        {
            sum = dp[(1 << n) - 1][i];
        }
    if (sum != INT_MAX)
    {
        return sum;
    }
    else
    {
        return -1;
    }
}

int main()
{
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> a[i][j];
            if (i == j)
                a[i][j] = 0;
        }
    }
    fout <<salesman_way();
}