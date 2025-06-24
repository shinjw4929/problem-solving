#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 100;
    vector<vector<long long>>dp(101, vector<long long>(10,0));
    long long mod = 1000000000;
    for (int i = 0 ; i < 10 ; i++) {
        dp[1][i] = 1;
    }
    cin >> N;

    for (int i = 2 ; i <= N ; i++) {
        dp[i][0] = dp[i - 1][1] % mod;
        for (int j = 1 ; j < 9 ; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
        dp[i][9] = dp[i - 1][8] % mod;
    }
    long long sol = 0;
    for (int i = 1 ; i < 10 ; i++) {
        sol += dp[N][i];
        sol %= mod;
    }
    cout << sol % mod;
    return 0;
}