#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void getInput(int &nV, int &nE, int& sV, vector<vector<pair<int, int>>>& dirAdj, vector<int> &dist);
void dijkstra(vector<vector<pair<int, int>>>& dirAdj, vector<int> &dist, int &startV);
void printResult(vector<int> &dist);

int main() {
    int numOfV, numOfE;
    int startV;
    vector<vector<pair<int, int>>> dirAdj;
    vector<int> dist;
    getInput(numOfV, numOfE, startV, dirAdj, dist);

    dijkstra(dirAdj, dist, startV);
    printResult(dist);
    return 0;
}

void getInput(int &nV, int &nE, int& sV, vector<vector<pair<int, int>>>& dirAdj, vector<int> &dist){
    cin >> nV >> nE >> sV;
    sV--;
    dirAdj.resize(nV);
    dist.assign(nV, INT_MAX);
    dist[sV] = 0;
    for(int i = 0 ; i < nE; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dirAdj[u - 1].push_back({w, v - 1});
    }
}

void dijkstra(vector<vector<pair<int, int>>>& dirAdj, vector<int> &dist, int &startV) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, startV});
    while(!pq.empty()) {
        int curV = pq.top().second;
        int curW = pq.top().first;
        pq.pop();

        if (dist[curV] < curW) continue;

        for(auto& iter: dirAdj[curV]) {
            int nextV = iter.second;
            int nextW = iter.first;
            if (dist[nextV] > curW + nextW) {
                dist[nextV] = curW + nextW;
                pq.push({dist[nextV], nextV});
            }

        }
    }
}

void printResult(vector<int> &dist) {
    for(auto &iter : dist) {
        if(iter != INT_MAX) {
            cout << iter << '\n';
        }
        else {
            cout << "INF" << '\n';
        }
    }
}
