#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N = 1024;
    int M = 100000;
    cin >> N >> M;
    vector<vector<int>> mtx(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i < N + 1 ; i ++) {
        for (int j = 1 ; j < N + 1 ; j++) {
            cin >> mtx[i][j];
            mtx[i][j] += mtx[i][j - 1];
        }
    }
    for (int i = 0 ; i < M ; i++) {
        int row1, col1, row2, col2;
        cin >> row1 >> col1 >> row2 >> col2;
        int ans = 0;
        for (int r = row1 ; r <= row2 ; r++) {
            ans += (mtx[r][col2] - mtx[r][col1 - 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}