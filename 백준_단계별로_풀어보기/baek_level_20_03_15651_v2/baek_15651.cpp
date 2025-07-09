//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <vector>

using namespace std;

int N = 7, M = 7;
vector<int> permutation;

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
}

void back_tracking(int depth) {
    if (depth == M) {
        for (auto & iter : permutation) {
            cout << iter + 1 << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = 0 ; i < N ; i++) {
            permutation.push_back(i);
            back_tracking(depth + 1);
            permutation.pop_back();
        }
    }

}