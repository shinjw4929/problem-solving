#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> dp(101, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for (int i = 5 ; i < 101 ; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    int T;
    cin >> T;
    for (int i = 0 ; i < T ; i++) {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
    return 0;
}