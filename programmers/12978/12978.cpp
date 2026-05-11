#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> weight;
int _N, _K;
int dijkstra();

int solution(int N, vector<vector<int> > road, int K) {
    adj.assign(N + 1, {});
    weight.assign(N + 1, INT_MAX);
    weight[1] = 0;
    _N = N;
    _K = K;

    for (int i = 0; i < road.size() ; i++) {
        int u = road[i][0];
        int v = road[i][1];
        int w = road[i][2];
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    return dijkstra();
}

int dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int currentU = pq.top().second;
        int currentW = pq.top().first;
        pq.pop();
        for (int i = 0; i < adj[currentU].size(); i++) {
            int v = adj[currentU][i].second;
            int w = adj[currentU][i].first;
            if (currentW + w < weight[v]) {
                weight[v] = currentW + w;
                pq.push({weight[v], v});
            }
        }
    }

    int cnt = 0;
    for (const auto & iter: weight){
        if (iter <= _K){
            cnt ++;
        }
    }
    return cnt;
}




#if __has_include("../pg.h")
#include "../pg.h"
int main() {
    pg::tests(solution, R"(
N	road	K	result
5	[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]]	3	4
6	[[1,2,1],[1,3,2],[2,3,2],[3,4,3],[3,5,2],[3,5,3],[5,6,1]]	4	4
)");
    pg::summary();
}
#endif