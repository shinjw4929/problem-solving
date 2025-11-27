#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 500;
vector<vector<int>> dp;

void get_input();
void calculate_dp();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_dp();
    cout << *max_element(dp[n-1].begin(), dp[n-1].end());
    return 0;
}

void get_input() {
    cin >> n;
    dp.resize(n, vector<int>(n, 0));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= i ; j++) {
            cin >> dp[i][j];
        }
    }
}

void calculate_dp() {
    for (int i = 1 ; i < n ; i++) {
        for (int j = 0 ; j <= i ; j++) {
            if (j > 0 && j < i) {
                dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            else if (j == i) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            else if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            }
        }
    }
}