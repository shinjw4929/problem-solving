#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V = 800, E = 200000;

vector<vector<pair<long long, int>>> adj_list;
vector<int> must2visit;

void get_input();
void find_min_dist();
vector<long long> dijkstra(int start);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    find_min_dist();
    return 0;
}


void get_input() {
    cin >> V >> E;
    adj_list.resize(V);
    for (int i = 0 ; i < E ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj_list[u].push_back({w,v});
        adj_list[v].push_back({w,u});
    }
    for (int i = 0 ; i < 2; i++) {
        int u;
        cin >> u;
        must2visit.push_back(u - 1);
    }
}

void find_min_dist() {
    vector<long long> dist_from_1 = dijkstra(0);
    vector<long long> dist_from_V1 = dijkstra(must2visit[0]);
    vector<long long> dist_from_V2 = dijkstra(must2visit[1]);

    long long v1 = must2visit[0];
    long long v2 = must2visit[1];

    long long candidate1 = LONG_LONG_MAX;
    long long candidate2 = LONG_LONG_MAX;

    if (dist_from_1[v1] != LONG_LONG_MAX && dist_from_V1[v2] != LONG_LONG_MAX && dist_from_V2[V - 1] != LONG_LONG_MAX) {
        candidate1 = dist_from_1[v1] + dist_from_V1[v2] + dist_from_V2[V - 1];
    }

    if (dist_from_1[v2] != LONG_LONG_MAX && dist_from_V2[v1] != LONG_LONG_MAX && dist_from_V1[V - 1] != LONG_LONG_MAX) {
        candidate2 = dist_from_1[v2] + dist_from_V2[v1] + dist_from_V1[V - 1];
    }

    long long result = min(candidate1, candidate2);

    if (result == LONG_LONG_MAX) {
        cout << -1;
    } else {
        cout << result;
    }
}

vector<long long> dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(V, LONG_LONG_MAX);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int cur_V = cur.second;
        long long cur_W = cur.first;
        for (int i = 0 ; i < adj_list[cur_V].size() ; i++) {
            auto next = adj_list[cur_V][i];
            int next_V = next.second;
            long long next_W = cur_W + next.first;
            if (dist[next_V] > next_W) {
                dist[next_V] = next_W;
                pq.push({next_W, next_V});
            }
        }
    }
    return dist;
}