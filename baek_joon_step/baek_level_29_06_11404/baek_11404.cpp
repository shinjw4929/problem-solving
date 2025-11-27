#include <iostream>
#include <vector>

using namespace std;

int V = 100, E = 100000;
vector<vector<long long>> adj_mtx;

void get_input();
void floyd_warshall();


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    floyd_warshall();
    for (int i = 0 ; i < V ; i++) {
        for (int  j = 0 ; j < V ; j++) {
            cout << adj_mtx[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

void get_input() {
    cin >> V >> E;
    adj_mtx.assign(V, vector<long long>(V, 0));
    for (int i = 0 ; i < E ; i ++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        if (adj_mtx[u - 1][v - 1] == 0) {
            adj_mtx[u - 1][v - 1] = w;
        }
        else {
            adj_mtx[u - 1][v - 1] = min(adj_mtx[u - 1][v - 1], w);
        }
    }
}

void floyd_warshall() {
    for (int target = 0 ; target < V ; target++) {
        for (int i = 0 ; i < V ; i++) {
            for (int j = 0 ; j < V ; j++) {
                if (i != j && adj_mtx[i][target] && adj_mtx[target][j]) {
                    if (adj_mtx[i][j]) {
                        adj_mtx[i][j] = min(adj_mtx[i][j],adj_mtx[i][target] + adj_mtx[target][j]);
                    }
                    else {
                        adj_mtx[i][j] = adj_mtx[i][target] + adj_mtx[target][j];
                    }
                }
            }
        }
    }
}