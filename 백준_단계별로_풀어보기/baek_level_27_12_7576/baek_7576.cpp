#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 1000, M = 1000;
vector<int> dR = {-1, 1, 0, 0};
vector<int> dC = {0, 0, -1, 1};
vector<vector<int>> mtx;
queue<pair<int, pair<int, int>>> bfsQ;

void get_input();
bool is_valid(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < M);
}
void cal_days();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    cal_days();
    return 0;
}

void get_input() {
    cin >> M >> N;
    mtx.resize(N, vector<int>(M, 0));
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            cin >> mtx[i][j];
            if (mtx[i][j] == 1) {
                bfsQ.push({0,{i, j}});
            }
        }
    }
}


void cal_days() {
    int max_days = 0;
    while (!bfsQ.empty()) {
        auto cur = bfsQ.front();
        int curW = cur.first;
        max_days = max(max_days, curW);
        int curR = cur.second.first;
        int curC = cur.second.second;
        bfsQ.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int nextW = curW + 1;
            int nextR = curR + dR[i];
            int nextC = curC + dC[i];
            if (is_valid(nextR,nextC)&&mtx[nextR][nextC] == 0) {
                mtx[nextR][nextC] = 1;
                bfsQ.push({nextW,{nextR, nextC}});
            }
        }
    }

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            if (mtx[i][j] == 0) {
                cout << -1;
                return;
            }
        }
    }
    cout << max_days;
}