#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N = 2000, M = 2000, K = 2000;
    cin >> N >> M >> K;
    vector<vector<int>> mtx_b(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> mtx_w(N + 1, vector<int>(M + 1, 0));

    for (int i = 1 ; i <= N ; i++) {
        string temp;
        cin >> temp;
        for (int j = 1 ; j <= M ; j++) {
            char color = temp[j - 1];
            if ((i+j) % 2 == 0 && color == 'B') {
                mtx_b[i][j] = 1;
            }
            else if ((i+j) % 2 == 0 && color == 'W') {
                mtx_w[i][j] = 1;
            }
            else if ((i+j) % 2 == 1 && color == 'B') {
                mtx_w[i][j] = 1;
            }
            else if ((i+j) % 2 == 1 && color == 'W') {
                mtx_b[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= N ; i++) {
        for (int j = 1; j <= M ; j++) {
            mtx_b[i][j] += mtx_b[i][j-1];
            mtx_w[i][j] += mtx_w[i][j-1];
        }
    }
    for (int i = 1; i <= N ; i++) {
        for (int j = 1; j <= M ; j++) {
            mtx_b[i][j] += mtx_b[i-1][j];
            mtx_w[i][j] += mtx_w[i-1][j];
        }
    }
    int global_min = INT_MAX;
    for (int i = 0 ; i + K <= N ; i++) {
        for (int j = 0 ; j+K <= M ; j++) {
            int prefix_sum_b = mtx_b[i+K][j+K] - mtx_b[i][j+K] - mtx_b[i+K][j] + mtx_b[i][j];
            int prefix_sum_w = mtx_w[i+K][j+K] - mtx_w[i][j+K] - mtx_w[i+K][j] + mtx_w[i][j];
            int local_min = min(prefix_sum_b, prefix_sum_w);
            global_min = min(global_min, local_min);
        }
    }
    cout << global_min;
    return 0;
}