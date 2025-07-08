//
// Created by sjw49 on 2025-07-08.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 100;
vector<pair<int, int>> arr;
vector<int> dp;

void get_input();
void calculate_dp();

int main() {
    get_input();
    calculate_dp();
    return 0;
}

void get_input() {
    cin >> N;
    arr.resize(N);
    dp.resize(N, 1);
    for (auto &[u, v] :arr) {
        cin >> u >> v;
    }
    sort(arr.begin(), arr.end());
}

void calculate_dp() {
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < i ; j++) {
            if (arr[i].second > arr[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << N - *max_element(dp.begin(), dp.end());
}
