#include <fstream>
#include <string>
#include <stack>
#include <vector>

int N;
char black_saber = 'X';
char white_saber = 'O';
char empty_cell  = '.';

char itoa(int a) {
    return 97 + a;
}

int CalculateSteps(std::string str) {
    int _steps = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '-') _steps++;
    }
    return _steps;
}

std::stack<std::string> ways;
char** field;

void find_long_take(int row, int col) {
    field[row][col] = empty_cell;
    std::string _last_step = ways.top();

    if (row - 2 >= 0 && col - 2 >= 0) {
        if (field[row - 2][col - 2] == empty_cell && field[row - 1][col - 1] == white_saber) {
            field[row - 1][col - 1] = empty_cell;
            ways.push({_last_step + "-" + (itoa(col - 2) + std::to_string(row - 2 + 1))});
            find_long_take(row - 2, col - 2);
            field[row - 1][col - 1] = white_saber;
        }
    }
    if (row + 2 < N && col - 2 >= 0) {
        if (field[row + 2][col - 2] == empty_cell && field[row + 1][col - 1] == white_saber) {
            field[row + 1][col - 1] = empty_cell;
            ways.push({_last_step + "-" + (itoa(col - 2) + std::to_string(row + 2 + 1))});
            find_long_take(row + 2, col - 2);
            field[row + 1][col - 1] = white_saber;
        }
    }
    if (row - 2 >= 0 && col + 2 < N) {
        if (field[row - 2][col + 2] == empty_cell && field[row - 1][col + 1] == white_saber) {
            field[row - 1][col + 1] = empty_cell;
            ways.push({_last_step + "-" + (itoa(col + 2) + std::to_string(row - 2 + 1))});
            find_long_take(row - 2, col + 2);
            field[row - 1][col + 1] = white_saber;
        }
    }
    if (row + 2 < N && col + 2 < N) {
        if (field[row + 2][col + 2] == empty_cell && field[row + 1][col + 1] == white_saber) {
            field[row + 1][col + 1] = empty_cell;
            ways.push({_last_step + "-" + (itoa(col + 2) + std::to_string(row + 2 + 1))});
            find_long_take(row + 2, col + 2);
            field[row + 1][col + 1] = white_saber;
        }
    }
    ways.push(_last_step);
    return;
}

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::string no_long_take_info = "Impossible";
    fin >> N;
    field = new char*[N];
    std::vector <std::pair<int,int>> black_checkers;

    for(int i = 0; i < N; i++) {
        field[N - i - 1] = new char[N];
        for(int j = 0; j < N; j++){
            fin >> field[N - i - 1][j];
            if(field[N - i - 1][j] == black_saber){
                black_checkers.push_back(std::make_pair(N - i - 1, j));
            }
        }
    }

    

    std::string longest_move_data;

    for(int  checker =0 ; checker< black_checkers.size(); checker++) {
        ways.push(std::string{itoa(black_checkers[checker].second) + std::to_string(black_checkers[checker].first + 1)});
        find_long_take(black_checkers[checker].first, black_checkers[checker].second);
        field[black_checkers[checker].first][black_checkers[checker].second] = black_saber;
        while (!ways.empty())
        {
            std::string _tmp = ways.top();
            if (CalculateSteps(_tmp) > CalculateSteps(longest_move_data)) {
                longest_move_data = _tmp;
            } 
            ways.pop();
        }
    }


    if (longest_move_data.length() / 2 > 1) {
        fout << longest_move_data;
    } else {
        fout << no_long_take_info;
    }
    return 0;
}