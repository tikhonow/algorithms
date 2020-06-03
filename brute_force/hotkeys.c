#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 1000

char title_names[SIZE][SIZE+1];
int n,count,sum,a_count,a_sum,n_a;
int hotkey[SIZE], ahotkey[SIZE];
bool used[255];

void hothotkey(int pos){
    int i, keycnt = 0;
    if (pos >= n){
        if (a_count >= count){
            if ((a_count > count) || (a_sum < sum)){
                count = a_count;
                sum = a_sum;
                for (int i = 0; i < n; ++i){
                    hotkey[i] = ahotkey[i];
                }
            }
        }
        return;
    }
    for (int i = 1; title_names[pos][i] != '\0'; ++i){
        if ((title_names[pos][i] == '\0') || (title_names[pos][i] == '\n')) { break;}
        if (((count == n) && ((a_sum + i - 1) >= sum)) || (sum == n_a)){
            break;
        }
        if (used[title_names[pos][i]] == false){
            a_count++;
            a_sum = a_sum + i - 1;
            keycnt++;
            ahotkey[pos] = i;
            used[title_names[pos][i]] = true;
            hothotkey(pos+1);
            ahotkey[pos] = -1;
            a_count--;
            a_sum = a_sum - i + 1;
            used[title_names[pos][i]] = false;
        }
    }
    if ((count+1) != n){
        hothotkey(pos+1);
    }

}


int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    for (int i = 0; i < SIZE; ++i){
        ahotkey[i] = -1;
        hotkey[i] = -1;
    }
    fscanf(in,"%d\n", &n);
    for (int i = 0; i < n; ++i){
        char tmp[SIZE];
        fgets(tmp, SIZE, in);
        strcat(title_names[i],"<");
        strcat(title_names[i],tmp);
        n_a = n_a + i;
    }
    hothotkey(0);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; title_names[i][j] != '\0'; ++j) {
            if ((title_names[i][j] == '\0') || (title_names[i][j] == '\n')) { break;}
            if ((j == hotkey[i]) || (n == 1)) {
                fprintf(out, "%c", '&');
            }
            fprintf(out,"%c",title_names[i][j]);
        }
        fprintf(out,"\n");
    }
    return 0;
}