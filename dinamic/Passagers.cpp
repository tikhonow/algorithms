#include <fstream>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, k;
    fin >> n >> k;
    int pattern [1000001];
    int place;

    for (int i = 0; i < k; i++) {
        fin >> place;
        pattern[place] = 1;
    }

    int dp[1000001][3] = {0};
    dp[0][1] = 1;

    for (int i = 1; i < n + 1; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000007;
        if (pattern[i] != 1) {
            dp[i][1] = dp[i - 1][0] % 1000000007;
            dp[i][2] = dp[i - 1][1] % 1000000007;
        }
    }
    fout << (dp[n][0] + dp[n][1]) % 1000000007;
}