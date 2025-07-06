#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int input = 40;
    cin >> input;
    vector<int> dp(40, 0); //save count of recursive function call
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3 ; i <= input ; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[input] << ' ' << input - 2;
    return 0;
}
