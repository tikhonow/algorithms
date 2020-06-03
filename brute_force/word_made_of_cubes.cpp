#include <fstream>
#include <string>
#include <vector>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<std::string> cubes;
std::vector<int> answer;

void wordscubes(std::string word, std::vector<int> &b, int h) {
    if (word.size() == h) {
        for (int i = 0; i<  answer.size(); i++) {
            fout << answer[i]<<" ";
        }
        exit(0);
    }
    for (int i = 0; i < cubes.size(); i++) {
        if (b[i] == 0) {
            b[i] = 1;
            if (cubes[i].find(word[h]) != -1) {
                answer.push_back(i + 1);
                wordscubes(word, b, h + 1);
                answer.pop_back();
            }
            b[i] = 0;
        }
    }
}

int main() {

    int n;
    std::string tmp, word;
    fin >> n >> word;
    std::vector<int> b(n,0);
    for (int i = 0; i < n; i++) {
        fin >> tmp;
        cubes.push_back(tmp);
    }
    wordscubes(word, b, 0);
    fout << 0;
}