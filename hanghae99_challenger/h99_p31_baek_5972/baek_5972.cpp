#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int numOfV;
int numOfE;
vector<vector<pair<int,int>>> adj;
vector<int> weightArr;
vector<bool> visited;
priority_queue<pair<int, int>,vector<pair<int, int>>, greater<>> pq;


void getInput();
void dijkstra();

int main() {
    getInput();
    dijkstra();
    cout << weightArr[numOfV - 1];

    return 0;
}

void getInput() {
    cin >> numOfV >> numOfE;
    weightArr.assign(numOfV, INT_MAX);
    weightArr[0] = 0;
    visited.assign(numOfV, false);
    adj.resize(numOfV);
    for(int i = 0 ; i < numOfE ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({w, v - 1});
        adj[v - 1].push_back({w, u - 1});
    }
}

void dijkstra() {
    pq.push({0,0});
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if(visited[cur.second]) {
            continue;
        }
        visited[cur.second] = true;
        for(auto &iter : adj[cur.second]) {
            if(visited[iter.second] == false) {
                if(weightArr[iter.second] > cur.first + iter.first) {
                    weightArr[iter.second] = cur.first + iter.first;
                    pq.push({weightArr[iter.second], iter.second});
                }
            }
        }
    }
}