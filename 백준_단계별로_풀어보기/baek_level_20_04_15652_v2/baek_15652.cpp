//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <vector>

using namespace std;

int N = 8, M = 8;
vector<int> combination;

void back_tracking(int depth, int cur);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    back_tracking(0 ,0);
    return 0;
}

void back_tracking(int depth, int cur) {
    if (depth == M) {
        for (auto& iter : combination) {
            cout << iter + 1 << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = cur ; i < N ; i++) {
            combination.push_back(i);
            back_tracking(depth + 1, i);
            combination.pop_back();
        }
    }
}