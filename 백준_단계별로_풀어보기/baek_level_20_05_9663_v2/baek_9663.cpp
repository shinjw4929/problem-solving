//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <vector>

using namespace std;

int N = 15;
int sol = 0;
vector<bool> diag_up;
vector<bool> diag_down;
vector<bool> columns;

void get_input();
void back_tracking(int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    back_tracking(0);
    cout << sol;
    return 0;
}

void get_input() {
    cin >> N;
    diag_up.assign(N * 2 - 1, true);
    diag_down.assign(N * 2 - 1, true);
    columns.assign(N, true);
}
void back_tracking(int depth) {
    if (depth == N) {
        sol++;
        return;
    }
    int cur_row = depth;
    for (int i = 0 ; i < N ; i++) {
        int cur_diag_up = cur_row + i;
        int cur_diag_down = cur_row - i + N - 1;
        if (columns[i] && diag_up[cur_diag_up] && diag_down[cur_diag_down]) {
            columns[i] = false;
            diag_up[cur_diag_up] = false;
            diag_down[cur_diag_down] = false;
            back_tracking(depth + 1);
            columns[i] = true;
            diag_up[cur_diag_up] = true;
            diag_down[cur_diag_down] = true;
        }
    }
}