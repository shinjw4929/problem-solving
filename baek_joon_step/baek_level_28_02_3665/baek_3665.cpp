#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int T = 100, n = 500, m = 25000;
vector<int> past_order;
vector<int> new_order;
vector<int> in_degree;
unordered_map<int, int> idx2order;
vector<pair<int, int>> changed_arr;
vector<set<int>> adj;

void get_input();
void mk_adj();
void kahn();

int main() {
    get_input();
    return 0;
}

void get_input() {
    cin >> T;
    for (int i = 0 ; i < T ; i++) {
        cin >> n;
        past_order.assign(n, 0);
        in_degree.assign(n, 0);
        new_order.erase(new_order.begin(), new_order.end());
        idx2order.clear();
        for (int j = 0 ; j < n ; j++) {
            int temp;
            cin >> temp;
            past_order[j] = temp - 1;
            idx2order[temp - 1] = j;
        }
        cin >> m;
        changed_arr.assign(m, {0, 0});
        for (int j = 0 ; j < m ; j++) {
            int u, v;
            cin >> u >> v;
            changed_arr[j] = {u - 1, v - 1};
        }
        mk_adj();
        kahn();
    }
}

void mk_adj() {
    adj.erase(adj.begin(), adj.end());
    adj.resize(n);
    for (int j = 0 ; j < n - 1 ; j++) {
        for (int k = j + 1 ; k < n ; k++ ) {
            adj[past_order[j]].insert(past_order[k]);
            in_degree[past_order[k]]++;
        }
    }
    for (int j = 0 ; j < m ; j++) {
        int u = changed_arr[j].first;
        int v = changed_arr[j].second;
        if (idx2order[u] > idx2order[v]) {
            adj[v].erase(u);
            adj[u].insert(v);
            in_degree[u]--;
            in_degree[v]++;
        }
        else {
            adj[u].erase(v);
            adj[v].insert(u);
            in_degree[v]--;
            in_degree[u]++;
        }
    }
}

void kahn() {
    queue<int> kahnQ;
    for (int i = 0 ; i < in_degree.size() ; i++) {
        if (in_degree[i] == 0) {
            kahnQ.push(i);
        }
    }
    while (!kahnQ.empty()) {
        if (kahnQ.size() > 1) {
            cout << "?" <<'\n';
            return;
        }
        int cur = kahnQ.front();
        in_degree[cur] = -1;
        kahnQ.pop();
        new_order.push_back(cur + 1);
        for (auto&iter : adj[cur]) {
            in_degree[iter]--;
            if (in_degree[iter] == 0) {
                kahnQ.push(iter);
            }
        }
    }
    for (int i = 0 ; i < in_degree.size() ; i++) {
        if (in_degree[i] >= 0) {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }
    }
    for (auto & iter: new_order) {
        cout << iter << ' ';
    }
}