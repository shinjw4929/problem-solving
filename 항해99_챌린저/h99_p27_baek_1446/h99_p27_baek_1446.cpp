#include <iostream>
#include <vector>
using namespace std;

class Prob {
private:
    int numOfE;
    int totDist;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> dp;
public:
    void getInput();
    void calDist();
};


int main() {
    Prob sol;
    sol.getInput();
    sol.calDist();
    return 0;
}

void Prob::getInput() {
    cin >> numOfE >> totDist;
    dp.resize(totDist + 1);
    for (int i = 0 ; i < totDist + 1; i++) {
        dp[i] = i;
    }
    for (int i = 0 ; i < numOfE ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (v - u > w && v <= totDist) {
            edges.push_back({w, {u,v}});
        }
    }
}


void Prob::calDist() {
    for (int i = 1 ; i < totDist + 1 ;i++) {
        dp[i] = dp[i - 1] + 1;
        for (auto & iter : edges) {
            if (iter.second.second == i) {
                dp[i] = min(dp[i], dp[iter.second.first] + iter.first);
            }
        }
    }
    cout << dp[totDist];
}
