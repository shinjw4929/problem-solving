#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 1000;
vector<int> dp;
vector<int> arr;

void get_input();
void calculate_dp();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_dp();
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}

void get_input() {
    cin >> N;
    arr.resize(N);
    dp.resize(N, 1);
    for (auto& iter:arr) {
        cin >> iter;
    }
}


void calculate_dp() {
    for (int i = 0 ; i < N - 1; i++) {
        for (int j = i + 1 ; j < N ; j++) {
            if (arr[j] > arr[i]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
}