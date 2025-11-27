#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(1000001);

int main() {
    int input;
    cin >> input;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3 ; i <= input ;i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    cout << dp[input];
}