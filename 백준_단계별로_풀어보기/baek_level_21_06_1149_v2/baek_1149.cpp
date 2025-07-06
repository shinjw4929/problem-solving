#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 1000;
vector<vector<int>> mtx;

void get_input();
void calculate_dp();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_dp();
    cout << *min_element(mtx[N - 1].begin(), mtx[N - 1].end());
    return 0;
}

void get_input() {
    cin >> N;
    mtx.resize(N, vector<int>(3,0));
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cin >> mtx[i][j];
        }
    }
}

void calculate_dp() {
    for (int i = 1 ; i < N ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            mtx[i][j] = min(mtx[i][j] + mtx[i - 1][(j + 1) % 3], mtx[i][j] + mtx[i - 1][(j + 2) % 3]);
        }
    }
}