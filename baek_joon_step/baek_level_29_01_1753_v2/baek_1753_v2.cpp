#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V = 20000, E = 300000;
int start_v = 1;
vector<vector<pair<long long,int>>> adj_list; // u -> {w, v}
vector<long long> dist;

void get_input();
void dijkstra();


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    dijkstra();
    for (auto&iter :dist) {
        if (iter != LONG_LONG_MAX) {
            cout << iter << '\n';
        }
        else {
            cout << "INF" << '\n';
        }
    }
    return 0;
}

void get_input() {
    cin >> V >> E;
    cin >> start_v;
    start_v--;
    adj_list.resize(V);
    dist.assign(V, LONG_LONG_MAX);
    for (int i = 0 ; i < E ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u - 1].push_back({w, v - 1});
    }
}

void dijkstra() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start_v] = 0;
    pq.push({0, start_v});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        long long cur_W = cur.first;
        int cur_V = cur.second;
        for (int i = 0 ; i < adj_list[cur_V].size() ; i++) {
            auto next = adj_list[cur_V][i];
            long long next_W = cur_W + next.first;
            int next_V = next.second;
            if (next_W < dist[next_V]) {
                dist[next_V] = next_W;
                pq.push({next_W, next_V});
            }
        }
    }

}