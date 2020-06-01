#include <vector>
#include <string>
#include <map>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");
int a, b, c;
std::vector<bool> use;
std::map<int, int> all_a;

void permetation_a(int pos, std::string s, std::string perm){
    if (pos == s.length()) {
        if (perm[0] != '0'){
            all_a.insert({c - stoi(perm), stoi(perm)});
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (!use[i]) {
            use[i] = true;
            perm[pos] = s[i];
            permetation_a(pos + 1, s, perm);
            use[i] = false;
        }
    }
}
void permetation_b(int pos, std::string s, std::string perm){
    if (pos == s.length()) {
        if (all_a.find(stoi(perm)) != all_a.end()){
            if (perm[0] != '0'){
                fout << "YES" << "\n";
                fout << c - stoi(perm) << ' ' << stoi(perm);
                exit(0);
            }
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (!use[i]) {
            use[i] = true;
            perm[pos] = s[i];
            permetation_b(pos + 1, s, perm);
            use[i] = false;
        }
    }
}

int main() {
    fin >> a >> b >> c;
    std::string a_str = std::to_string(a);
    std::string b_str = std::to_string(b);
    int pos = 0;
    std::string a_perm = std::string(a_str.length(), '1');
    std::string b_perm = std::string(b_str.length(), '1');
    if (a_str.length() > b_str.length()){
        use.resize(a_str.length());
    }
    else{
        use.resize(b_str.length());
    }
    permetation_a(pos, a_str, a_perm);
    permetation_b(pos, b_str, b_perm);
    fout << "NO";
}