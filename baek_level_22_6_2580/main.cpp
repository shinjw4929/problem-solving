#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));

bool sol_sudo();
bool isvalid(int r, int c, int num);

int main() {
    for(int r = 0 ; r < 9; r++) {
        for(int c = 0 ; c < 9 ; c++) {
            cin >> sudoku[r][c];
        }
    }

    sol_sudo();
    for(int r = 0 ; r < 9; r++) {
        for(int c = 0 ; c < 9 ; c++) {
            cout << sudoku[r][c] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

bool sol_sudo() {
    for(int r = 0 ; r < 9; r++) {
        for(int c = 0 ; c < 9 ; c++) {
            if(sudoku[r][c] == 0) {
                for(int i = 0 ; i <= 9 ; i++) {
                    if(isvalid(r, c, i)) {
                        sudoku[r][c] = i;
                        if(sol_sudo()) {
                            return true;
                        }
                        sudoku[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isvalid(int r, int c, int num) {
    for(int i = 0; i < 9 ; i++) {
        if(sudoku[r][i] == num) {
            return false;
        }
        if(sudoku[i][c] == num) {
            return false;
        }
    }
    for(int i = 0 ; i < 3; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            if(sudoku[r - r % 3 + i][c - c % 3 + j] == num) {
                return false;
            }
        }
    }
    return true;


}
