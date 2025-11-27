#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N = 32000, M = 100000;
int visit_no = 0;
vector<vector<int>> adj;
map<int,int,greater<int>> pvn2idx;
vector<bool> visited;

void get_input();
void find_post_nos();
void dfs(int cur);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    find_post_nos();
    for (auto&iter :pvn2idx) {
        cout << iter.second + 1 << ' ';
    }
    return 0;
}

void get_input() {
    cin >> N >> M;
    adj.resize(N);
    visited.resize(N, false);
    for (int i = 0 ; i < M ; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
}

void find_post_nos() {
    for (int i = 0 ; i < N ; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

void dfs(int cur) {
    visited[cur] = true;
    visit_no++;
    for (int i = 0 ; i < adj[cur].size() ; i++) {
        int next_vertex = adj[cur][i];
        if (!visited[next_vertex]) {
            dfs(next_vertex);
        }
    }
    visit_no++;
    pvn2idx[visit_no] = cur;
}
