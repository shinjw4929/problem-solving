#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int V = 500, E = 6000;
vector<pair<int,pair<int,int>>> edge_arr;
vector<long long> dist;

void get_input();
int bellman_ford();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    if (bellman_ford() == - 1) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i < dist.size() ; i++) {
        if (dist[i] != LONG_LONG_MAX) {
            cout << dist[i] << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}

void get_input() {
    cin >> V >> E;
    edge_arr.resize(E);
    dist.resize(V, LONG_LONG_MAX);
    dist[0] = 0;
    for (int i = 0 ; i < E ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge_arr[i] = {w,{u - 1, v - 1}};
    }
}

int bellman_ford() {
    for (int i = 0 ; i < V - 1; i++) {
        for (int j = 0; j < E ; j++) {
            auto cur_E = edge_arr[j];
            int cur_U = cur_E.second.first;
            int cur_V = cur_E.second.second;
            int cur_W = cur_E.first;
            if (dist[cur_U] != LONG_LONG_MAX && dist[cur_V] > dist[cur_U] + cur_W) {
                dist[cur_V] = dist[cur_U] + cur_W;
            }
        }
    }
    vector<long long> origin_dist = dist;
    for (int j = 0; j < E ; j++) {
        auto cur_E = edge_arr[j];
        int cur_U = cur_E.second.first;
        int cur_V = cur_E.second.second;
        int cur_W = cur_E.first;
        if (dist[cur_U] != LONG_LONG_MAX && dist[cur_V] > dist[cur_U] + cur_W) {
            dist[cur_V] = dist[cur_U] + cur_W;
        }
    }
    if (dist != origin_dist) {
        return -1;
    }
    return 0;
}