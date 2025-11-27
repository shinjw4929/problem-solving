#include <iostream>
#include <vector>

using namespace std;

class Tree {
private:
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;
    int nOfV;
    int vCnt = 0;
public:
    void getInput();
    void dfs(int idx);
    void printSol();
};

int main() {
    Tree tree;
    tree.getInput();
    tree.dfs(1);
    tree.printSol();
    return 0;
}

void Tree::getInput() {
    cin >> nOfV;
    adj.resize(nOfV + 1);
    visited.assign(nOfV + 1, false);
    parent.assign(nOfV + 1, 0);
    for(int i = 0 ; i < nOfV - 1 ; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Tree::dfs(int idx) {
    visited[idx] = true;
    for(int i = 0 ; i < adj[idx].size() ; i++) {
        if(!visited[adj[idx][i]]) {
            parent[adj[idx][i]] = idx;
            dfs(adj[idx][i]);
        }
    }
}

void Tree::printSol() {
    for(int i = 2; i < nOfV + 1 ; i++) {
        cout << parent[i] << '\n';
    }
}
