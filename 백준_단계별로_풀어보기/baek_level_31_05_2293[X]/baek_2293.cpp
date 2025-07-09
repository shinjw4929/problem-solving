#include <iostream>
#include <vector>

using namespace std;

int N = 100, K = 10000;
vector<int> coins;
vector<int> dp;

void get_input();
void calculate_dp();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_dp();
    cout << dp[K];
    return 0;
}

void get_input() {
    cin >> N >> K;
    dp.resize(K + 1, 0);
    for (int i = 0 ; i < N ; i++) {
        int temp;
        cin >>temp;
        if (temp <= K) {
            coins.push_back(temp);
        }
    }
    dp[0] = 1;
    N = coins.size();
}

void calculate_dp() {
    for (int i = 0 ; i < N ; i++) {
        for (int j = coins[i] ; j <= K ; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
}
