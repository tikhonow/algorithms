#include <fstream>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt"); 
    int N;
    std::string S;
    fin >> N >> S;
    int dp[10][100001] = {0};

    for (int i = 0; i < N; i++) {
        if (S[i] == '*') {
            for (int j = 0; j < 10; j++) {
                for (int h = 0; h < 10; h++) {
                    if (j != h)
                        dp[h][i + 1] = MAX(dp[h][i + 1], dp[j][i] + j * h);
                }
            }
        } else {
            int a = S[i] - '0';
            int answer;
            for (int j = 0; j < 10; j++) {
                if (j == a)
                    answer = 0;
                else {
                    answer = a * j;
                }
                dp[j][i + 1] = MAX(dp[j][i + 1], dp[a][i] + answer);

            }
        }
    }
    fout << 72 * (N - 1) - dp[0][N];
}