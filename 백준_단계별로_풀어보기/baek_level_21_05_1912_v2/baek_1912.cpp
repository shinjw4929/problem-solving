#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 100000;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n);
    for (auto& iter : arr) {
        cin >> iter;
    }
    dp[0] = arr[0];
    int sol = dp[0];
    for (int i = 1 ; i < n ; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        sol = max(dp[i],sol);
    }
    cout << sol;
    return 0;
}