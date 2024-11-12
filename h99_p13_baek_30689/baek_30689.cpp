#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
int m;
int result = 0;
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
unordered_map<char, int> dir;
vector<vector<char>> dir_mtx;
vector<vector<int>> weight_mtx;
vector<vector<int>> status; //0: 탐색전, 1: 탐색중, 2: 탐색완료

void getInput();
void dfs(int r, int c);
bool isEnd(int r, int c);


int main() {
    dir['U'] = 0;
    dir['D'] = 1;
    dir['L'] = 2;
    dir['R'] = 3;
    getInput();
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(status[i][j] == 0) {
                dfs(i, j);
            }
        }
    }
    cout << result;
    return 0;
}


void getInput() {
    cin >> n >> m;
    dir_mtx.resize(n, vector<char>(m));
    weight_mtx.resize(n, vector<int>(m));
    status.resize(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> dir_mtx[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            cin >> weight_mtx[i][j];
        }
    }
}
bool isEnd(int r, int c) {
    return (r < 0 || r >= n || c < 0 || c >= m);
}

void dfs(int r, int c) {
    int dirIdx = dir[dir_mtx[r][c]];
    int nextR = r + dr[dirIdx];
    int nextC = c + dc[dirIdx];
    if(status[r][c] == 1) {
        int minW = weight_mtx[r][c];
        status[r][c] = 2;
        while(nextR != r || nextC != c) {
            status[nextR][nextC] = 2;
            minW = min(minW, weight_mtx[nextR][nextC]);
            dirIdx = dir[dir_mtx[nextR][nextC]];
            nextR = nextR + dr[dirIdx];
            nextC = nextC + dc[dirIdx];
        }
        result = result + minW;
    }
    else if(status[r][c] == 0) {
        status[r][c] = 1;
        if(isEnd(nextR, nextC)) {
            status[r][c] = 2;
        }
        else {
            dfs(nextR, nextC);
            status[r][c] = 2;
        }
    }
}
