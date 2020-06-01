#include <iostream>
#include <fstream>
#include <vector>

void Gene_cheater (int pos, const int p, int q, std::vector<std::pair<std::string,int>> &test, std::string &res, std::string str) {
    int count = 0;
    if (pos >= q) {
        for (int i = 0; i < p; i++) {
            count = 0;

            for (int j = 0; j < q; j++) {
                if (test[i].first[j] == str[j])
                    count++;
            }
            if (count != test[i].second)
                break;
            if (i == p - 1) {
                res = str;
                return;
            }
        }
        return;
    }
    char c = ' ';
    for (int k = 0; k < 2; k++) {
        if (k == 0)
        {
            c ='+';
        }
        else c = '-';
        Gene_cheater(pos + 1, p, q, test, res, (str + c));
    }
}

int main () {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int P, Q;
    std::string result;
    fin >> P >> Q;
    std::vector<std::pair<std::string,int>> test(P);

    for (int i = 0; i< P; i++) {
        fin >> test[i].first >> test[i].second;
    }

    Gene_cheater( 0, P, Q,test, result, "");
    fout << result;
}