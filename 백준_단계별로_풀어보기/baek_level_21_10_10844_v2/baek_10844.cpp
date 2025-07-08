#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int MOD = 1000000000;
int N = 100;
vector<vector<int>> dp;

void get_input();
void calculate_dp();

int main() {
    get_input();
    calculate_dp();
    return 0;
}


void get_input() {
    cin >> N;
    dp.resize(N + 1, vector<int>(10, 0));
    for (int i = 1 ; i < 10 ; i++) {
        dp[1][i] = 1;
    }
}

void calculate_dp() {
    for (int i = 2 ; i < N + 1; i++) {
        for (int j = 1 ; j <= 8 ; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
        dp[i][0] = dp[i - 1][1] % MOD;
        dp[i][9] = dp[i - 1][8] % MOD;
    }
    int sum = 0;
    for (int i = 0 ; i < 10 ; i++) {
        sum += dp[N][i];
        sum %= MOD;
    }
    cout << sum;
}