#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> arr;
vector<int> dp;

int main() {
    cin >> n >> k;
    arr.resize(n);
    dp.resize(k + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // 동적 계획법으로 배낭 문제 해결
    for (int i = 0; i < n; i++) {
        // 현재 아이템을 고려하여, 무게를 내림차순으로 순회
        for (int w = k; w >= arr[i].first; w--) {
            dp[w] = max(dp[w], dp[w - arr[i].first] + arr[i].second);
        }
    }

    cout << dp[k] << endl;
    return 0;
}
