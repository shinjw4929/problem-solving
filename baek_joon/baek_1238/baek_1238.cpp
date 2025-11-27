#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int numOfV;
int numOfE;
int destV;


vector<int> dist;
vector<vector<pair<int, int>>> adj; //weight, endV;

void getInput();
void findMaxDist();
void dijkstra(int start);

int main() {
    getInput();
    findMaxDist();

    return 0;
}

void getInput() {
    cin >> numOfV >> numOfE >> destV;
    adj.resize(numOfV);
    for(int i = 0 ; i < numOfE ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back({w, v-1});
    }
}

void dijkstra(int start) {
    dist.assign(numOfV, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // w, v
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int curV = pq.top().second;
        int curW = pq.top().first;
        pq.pop();
        for(auto &iter : adj[curV]) {
            int nextV = iter.second;
            int nextW = iter.first + curW;
            if(dist[nextV] > nextW) {
                dist[nextV] = nextW;
                pq.push({nextW, nextV});
            }
        }
    }


}

void findMaxDist() {
    vector<int> eachDist(numOfV, 0);
    for(int i = 0 ; i < numOfV ; i++) {
        dijkstra(i);
        if(i != destV - 1) {
            eachDist[i] += dist[destV - 1];
        }
        else {
            for(int j = 0 ; j < numOfV ; j++) {
                eachDist[j] += dist[j];
            }
        }
    }
    int maxResult = -1;
    for(int i = 0 ; i < numOfV ; i++) {
        maxResult = max(maxResult, eachDist[i]);
    }
    cout << maxResult;
}
