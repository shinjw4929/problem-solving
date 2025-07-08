#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int input;
vector<int> dp;

void get_input();
int find_dp(int target);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    cout << find_dp(input);
    return 0;
}

void get_input() {
    cin >> input;
    dp.resize(input + 1, -1);
    dp[0] = 0;
    dp[1] = 0;
}

int find_dp(int target) {
    if (dp[target] == -1) {
        int temp = INT_MAX;
        if (target % 3 == 0) {
            temp = find_dp(target / 3) + 1;
        }
        if (target % 2 == 0) {
            temp = min(temp, find_dp(target / 2) + 1);
        }
        if (target > 1) {
            temp = min(temp, find_dp(target - 1) + 1);
        }
        dp[target] = temp;
    }
    return dp[target];
}