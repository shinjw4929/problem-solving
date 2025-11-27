//
// Created by sjw49 on 2025-07-08.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N = 1000, M = 1000;
string str1;
string str2;
vector<vector<int>> dp;

void get_input();
void calculate_dp();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_dp();
    cout << dp[N][M];
    return 0;
}

void get_input() {
    cin >> str1 >> str2;
    N = str1.size();
    M = str2.size();
    dp.resize(N + 1, vector<int>(M + 1, 0));
}

void calculate_dp() {
    for (int i = 1 ; i <= N ; i++) {
        char to_compare = str1[i - 1];
        for (int j = 1 ; j <= M ; j++) {
            char cur = str2[j - 1];
            if (cur == to_compare) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
}