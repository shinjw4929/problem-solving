#include <iostream>
#include <vector>
#include <climits>

using namespace std;


vector<vector<vector<long long>>> dp(51, vector<vector<long long>>(51, vector<long long>(51, LONG_LONG_MIN)));

long long calculate_dp(int a, int b, int c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a = - 1, b = - 1, c = - 1;
    dp[0][0][0] = 1;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << calculate_dp(a, b, c) << '\n';
    }
    return 0;
}

long long calculate_dp(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20) {
        if (dp[a][b][c] == LONG_LONG_MIN) {
            dp[a][b][c] = calculate_dp(20, 20, 20);
        }
    }
    else if (a < b && b < c) {
        if (dp[a][b][c - 1] == LONG_LONG_MIN) {
            dp[a][b][c - 1] = calculate_dp(a, b, c - 1);
        }
        if (dp[a][b - 1][c - 1] == LONG_LONG_MIN) {
            dp[a][b - 1][c - 1] = calculate_dp(a, b - 1, c - 1);
        }
        if (dp[a][b - 1][c] == LONG_LONG_MIN) {
            dp[a][b - 1][c] = calculate_dp(a, b - 1, c);
        }
        dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
    }
    else {
        if (dp[a - 1][b][c] == LONG_LONG_MIN) {
            dp[a - 1][b][c] = calculate_dp(a - 1, b, c);
        }
        if (dp[a - 1][b - 1][c] == LONG_LONG_MIN) {
            dp[a - 1][b - 1][c] = calculate_dp(a - 1, b - 1, c);
        }
        if (dp[a - 1][b][c - 1] == LONG_LONG_MIN) {
            dp[a - 1][b][c - 1] = calculate_dp(a - 1, b, c - 1);
        }
        if (dp[a - 1][b - 1][c - 1] == LONG_LONG_MIN) {
            dp[a - 1][b - 1][c - 1] = calculate_dp(a - 1, b - 1, c - 1);
        }
        dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
    }
    return dp[a][b][c];
}