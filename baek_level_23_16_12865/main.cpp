#include <iostream>
#include <vector>

using namespace std;

int n;
int k;
vector<pair<int, int>> object; //무게, 가치
vector<vector<int>> dp;


void getInput();
void update();
void printMax();

int main() {
    getInput();
    update();
    return 0;
}

void getInput() {
    cin >> n >> k;
    object.resize(n + 1, {0, 0});
    dp.assign(n + 1, vector<int>(k + 1, 0));
    for(int i = 1 ; i < n + 1 ; i++) {
        int weight, value;
        cin >> weight >> value;
        object[i] = {weight, value};
    }

}

void update() {
    for(int i = 1 ; i < n + 1 ; i++) {
        for(int w = 0 ; w <= k ; w++) {
            if(w - object[i].first < 0) {
                dp[i][w] = dp[i - 1][w];
            }
            else{
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - object[i].first] + object[i].second);
            }
        }
    }
    cout << dp[n][k];
}
