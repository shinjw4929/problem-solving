#include <iostream>
#include <vector>

using namespace std;

int N = 100;
int K = 100000;
vector<vector<int>> dp;
vector<pair<int, int>> items;
void get_input();
void knapsack();

int main() {
    get_input();
    knapsack();
    cout << dp[N][K];
    return 0;
}

void get_input() {
    cin >> N >> K;
    dp.resize(N+1, vector<int>(K + 1, 0));
    items.resize(N + 1);
    for (int i = 1 ; i < N + 1 ; i++) {
        int weight, value;
        cin >> weight >> value;
        items[i] = {weight, value};
    }
}

void knapsack() {
    for (int i = 1 ; i < N + 1 ; i++) {
        for (int j = 1 ; j < K + 1 ; j++) {
            int cur_weight = items[i].first;
            int cur_value = items[i].second;
            if (cur_weight > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - cur_weight] + cur_value);
            }
        }
    }
}