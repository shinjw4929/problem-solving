#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
vector<vector<int>> visited; //-1 : 벽, 0 : 탐색x, 1 : 탐색 완료, -2 : 인접 벽
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
queue <pair<int, pair<int, int>>> Q;

void getInput();
void dfs(int r, int c, int level);
bool valid(int nextR, int nextC);
void updateMtx();

int main() {
    getInput();
    dfs(0, 0, 0);
    if(visited[n -1][n -1] == 1) {
        cout << 0;
    }
    else {
        updateMtx();
    }
    return 0;
}


void getInput() {
    cin >> n;
    visited.assign(n, vector<int>(n, -1));
    for(int i = 0 ; i < n ; i++) {
        string temp;
        cin >> temp;
        for(int j = 0 ; j < n ; j++) {
            int current = temp[j] - 48;
            if(current) {
                visited[i][j] = 0;
            }
        }
    }
}

void dfs(int r, int c, int level) {
    visited[r][c] = 1;
    for(int i = 0 ; i < 4 ; i++) {
        int nextR = r + dr[i];
        int nextC = c + dc[i];
        if(valid(nextR, nextC)) {
            if(visited[nextR][nextC] == 0) {
                dfs(nextR, nextC, level);
            }
            else if(visited[nextR][nextC] == -1) {
                visited[nextR][nextC] = -2;
                Q.push({level + 1,{nextR, nextC}});
            }

        }
    }
    visited[r][c] = 1;
}

bool valid(int nextR, int nextC) {
    return (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n);
}

void updateMtx() {
    do {
        pair<int, int> current = Q.front().second;
        int cLv = Q.front().first;
        Q.pop();
        int cR = current.first;
        int cC = current.second;
        visited[cR][cC] = 1;
        dfs(cR, cC, cLv);
        if(visited[n - 1][n - 1] == 1) {
            cout << cLv;
            break;
        }
    }while(!Q.empty());
}
