#include <iostream>
#include <vector>

using namespace std;

int n = 300;
vector<int> arr;
vector<int> dp;

void get_input();
void calculate_dp();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_dp();
    cout << dp[n-1];
    return 0;
}

void get_input() {
    cin >> n;
    arr.resize(n, 0);
    dp.resize(n, 0);
    for (auto& iter: arr) {
        cin >> iter;
    }
}

void calculate_dp() {
    dp[0] = arr[0];
    if (n == 1) return;
    dp[1] = arr[0] + arr[1];
    if (n == 2) return;
    dp[2] = arr[2] + max(arr[1], arr[0]);
    if (n == 3) return;
    for (int i = 3 ; i < n ; i++) {
        dp[i] = arr[i] + max(arr[i - 1] + dp[i - 3], dp[i - 2]);
    }
}