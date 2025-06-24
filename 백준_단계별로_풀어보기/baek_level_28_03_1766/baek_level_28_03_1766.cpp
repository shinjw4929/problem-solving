#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Topo {
private:
    int numOfV;
    int numOfE;
    vector<int> inDegree;
    vector<vector<int>> adj;
    vector<int> orders;
public:
    void getInput();
    void ordering();
};


int main() {
    Topo sol;
    sol.getInput();
    sol.ordering();
    return 0;
}

void Topo::getInput() {
    cin >> numOfV >> numOfE;
    inDegree.resize(numOfV, 0);
    adj.resize(numOfV);
    for(int i = 0 ; i < numOfE ; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        inDegree[v]++;
        adj[u].push_back(v);
    }
}

void Topo::ordering() {
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0 ; i < numOfV ; i++) {
        if(!inDegree[i]) {
            pq.push(i);
        }
    }
    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        orders.push_back(cur);
        for(auto &iter : adj[cur]) {
            inDegree[iter]--;
            if(!inDegree[iter]) {
                pq.push(iter);
            }
        }
    }
    for(auto& iter: orders) {
        cout << iter + 1 << ' ';
    }
}
