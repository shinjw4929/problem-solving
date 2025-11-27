//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <vector>

using namespace std;

int N = 8, M = 8;
vector<int> combination;
vector<bool> visited;
void get_input();
void back_tracking(int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    back_tracking(0);
    return 0;
}

void get_input() {
    cin >> N >> M;
    visited.assign(N, false);
}

void back_tracking(int depth) {
    if (depth == M) {
        for (int i = 0 ; i < M ; i++) {
            cout << combination[i] + 1 << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = 0 ; i < N ; i++) {
            if (!visited[i]) {
                visited[i] = true;
                combination.push_back(i);
                back_tracking(depth + 1);
                visited[i] = false;
                combination.pop_back();
            }
        }
    }
}
