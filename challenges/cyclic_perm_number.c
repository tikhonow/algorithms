#include <stdio.h>
#include <string.h>
char S[200000 + 2];

int source_line_number()
{
    int n = strlen(S);
    int M[n], P[n], T[n], B[n];
    int c = 0, d = 0, i1 = 0, j = 0;
    int max = 0;
    max = (n < 256) ? max = 256 : max = n;
    int D[max] = {0};
    for (int i = 0; i < n; ++i) {
        M[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        P[M[i]] = S[M[i]];
    }
    int k = 0;
    while (k < n) {
        for (int i = 0; i < n; ++i)
            D[P[i]]++;
        int u = 0;
        for (int i = 0; i < max; ++i) {
            d = u + D[i];
            D[i] = u;
            u = d;
        }
        for (int i = 0; i < n; ++i) {
            i1 = (M[i] - k + n) % n;
            c = P[i1];
            j = D[c];
            T[j] = i1;
            D[c] = j + 1;
        }
        for (int i = 0; i < n; ++i)
            M[i] = T[i];
        B[M[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if ((P[M[i]] != P[M[i - 1]]) || (P[(M[i] + k) % n] != P[(M[i - 1] + k) % n]))
                B[M[i]] = B[M[i - 1]] + 1;
            else B[M[i]] = B[M[i - 1]];
        }
        for (int i = 0; i < n; ++i) {
            P[i] = B[i];
        }
        k = (k)? (k * 2):(1);
    }
    return P[0];
}

int main() {
    FILE *input, *fout;
    input = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    fgets(S, 200000 + 1, input);
    fprintf(fout, "%i", source_line_number());
    fclose(input);
    fclose(fout);
    return 0;
}