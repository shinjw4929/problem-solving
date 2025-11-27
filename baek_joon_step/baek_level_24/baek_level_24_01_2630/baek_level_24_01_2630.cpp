#include <iostream>
#include <vector>

using namespace std;


void find_num(vector<vector<int>> &paper, int row, int col, int size);
int is_full(vector<vector<int>> &paper, int row, int col, int size);

int white = 0;
int blue = 0;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> paper(n, vector<int>(n));
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    //input
    find_num(paper, 0, 0, n);
    cout << white << '\n' << blue;

    return 0;
}

void find_num(vector<vector<int>> &paper, int row, int col, int size) {
    int temp = is_full(paper, row, col ,size);
    if(temp == 0) {
        find_num(paper, row, col, size / 2);
        find_num(paper, row + size / 2, col, size / 2);
        find_num(paper, row, col + size / 2, size / 2);
        find_num(paper, row + size / 2, col + size / 2, size / 2);
    }
    else {
        white  = white + (temp == -1);
        blue = blue + (temp == 1);
    }
}

int is_full(vector<vector<int>> &paper, int row, int col, int size) {
    int color = paper[row][col];

    for(int i = row ; i < row + size; i++) {
        for(int j = col; j < col + size; j++) {
            if(paper[i][j] != color) {
                return 0;
            }
        }
    }
    if(color == 1) {
        return  1;
    }
    return -1;
}
