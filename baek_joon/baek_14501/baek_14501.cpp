#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<pair<int, int>> arr;
vector<int> dp;

void getInput();
void solve();

int main () {
    getInput();
    solve();
    return 0;
}

void getInput() {
    cin >> N;
    arr.resize(N);
    for (int i = 0 ; i < N ; i++) {
        int time, money;
        cin >> time >> money;
        arr[i].first = time;
        arr[i].second = money;
    }
    dp.assign(N + 1, 0);
}

void solve() {
    for (int i = 0 ; i < N ; i++) {
        int time = arr[i].first;
        int money = arr[i].second;

        if (time <= N - i) {
            dp[i + time] = max(dp[i + time], dp[i] + money);
            for (int j = i + time; j <= N ; j++) {
                dp[j] = max(dp[j], dp[i + time]);
            }
        }
    }
    cout << dp[N];
}