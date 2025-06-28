#include <iostream>
#include <vector>

using namespace std;

int V = 100;
int E;
vector<vector<int>> adj;
vector<bool> visited;
void get_input();
void dfs(int curV);

int main() {
    get_input();
    dfs(0);
    int sol = 0;
    for (const auto&iter :visited) {
        if (iter) {
            sol++;
        }
    }
    cout << (sol - 1);
    return 0;
}

void get_input() {
    cin >> V >> E;
    adj.resize(V);
    visited.assign(V, false);
    for (int i = 0 ; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[0] = true;
}

void dfs(int curV) {
    vector<int> & cur_arr = adj[curV];
    for (int i = 0 ; i < cur_arr.size() ; i++) {
        int nextV = cur_arr[i];
        if (!visited[nextV]) {
            visited[nextV] = true;
            dfs(nextV);
        }
    }
}