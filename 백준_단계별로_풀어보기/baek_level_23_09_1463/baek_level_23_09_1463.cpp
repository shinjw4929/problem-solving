#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> dp;
int main() {
    int input;
    cin >> input;
    dp.assign(input + 1, INT_MAX);
    int temp = 1;
    int cnt = 0;
    dp[1] = 0;
    for(int i = 2 ; i < input + 1 ; i++) {
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[input];
    return 0;
}
