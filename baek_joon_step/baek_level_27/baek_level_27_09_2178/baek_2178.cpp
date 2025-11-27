#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N = 100, M = 100;
vector<int> dR = {1, 0, 0, -1};
vector<int> dC = {0, 1, -1, 0};
vector<vector<int>> mtx;

void get_input();
bool is_valid(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < M);
}
void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    bfs();
    return 0;
}

void get_input() {
    cin >> N >> M;
    mtx.resize(N, vector<int>(M,0));
    for (int i = 0 ; i < N ; i++) {
        string temp;
        cin >> temp;
        for (int j = 0 ; j < M ; j++) {
            mtx[i][j] = temp[j] - '0';
        }
    }
}

void bfs() {
    queue<pair<int, pair<int,int>>> bfsQ;
    bfsQ.push({1,{0,0}});
    mtx[0][0] = 0;
    while (!bfsQ.empty()) {
        int curW = bfsQ.front().first;
        int curR = bfsQ.front().second.first;
        int curC = bfsQ.front().second.second;
        if (curR == N - 1 && curC == M - 1) {
            cout << curW;
            return;
        }
        bfsQ.pop();
        for (int i = 0; i < 4 ; i++) {
            int nextW = curW + 1;
            int nextR = curR + dR[i];
            int nextC = curC + dC[i];
            if (is_valid(nextR, nextC) && mtx[nextR][nextC]) {
                mtx[nextR][nextC] = 0;
                bfsQ.push({nextW, {nextR, nextC}});
            }
        }
    }
}