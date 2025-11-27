#include <iostream>
#include <vector>

using namespace std;

class Query {
private:
    int nV;
    int root;
    int nQ;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> dp;
public:
    void getInput();
    void findNumOfVinSubT(int curV);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Query sol;
    sol.getInput();
    return 0;
}

void Query::getInput() {
    cin >> nV >> root >> nQ;
    adj.resize(nV + 1);
    visited.resize(nV + 1, false);
    dp.resize(nV + 1, -1);
    for(int i = 0 ; i < nV - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    findNumOfVinSubT(root);
    for(int i = 0 ; i < nQ ; i ++) {
        int query;
        cin >> query;
        cout << dp[query] + 1 << '\n';
    }
}


void Query::findNumOfVinSubT(int curV) {
    visited[curV] = true;
    dp[curV] = 0;
    for(auto &iter : adj[curV]) {
        if(dp[iter] == -1 && visited[iter] == false) {
            findNumOfVinSubT((iter));
            dp[curV] += (dp[iter] + 1);
        }
    }
}
