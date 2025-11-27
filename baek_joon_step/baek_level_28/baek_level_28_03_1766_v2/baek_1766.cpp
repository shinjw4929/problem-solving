#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 32000;
int M = 100000;
vector<vector<int>> adj;
vector<int> in_degree;

void get_input();
void kahn();


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    kahn();
    return 0;
}


void get_input() {
    cin >> N >> M;
    adj.resize(N);
    in_degree.assign(N, 0);
    for (int i = 0 ; i < M ; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        in_degree[v-1]++;
    }
}

void kahn() {
    priority_queue<int, vector<int>, greater<int>> topological_order_Q;
    for (int i = 0 ; i < N ; i++) {
        if (in_degree[i] == 0) {
            in_degree[i] = -1;
            topological_order_Q.push(i);
        }
    }
    while (!topological_order_Q.empty()) {
        int cur = topological_order_Q.top();
        topological_order_Q.pop();
        cout << cur + 1 << ' ';
        for (int i = 0 ; i < adj[cur].size() ; i++) {
            int next_V = adj[cur][i];
            in_degree[next_V]--;
            if (in_degree[next_V] == 0) {
                in_degree[next_V] = -1;
                topological_order_Q.push(next_V);
            }
        }
    }
}