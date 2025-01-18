#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nV;
int nE;
int result = 0;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
vector<int> rootOf;
vector<int> rankOf;

void getInput();
void kruscal();
void unionOp(int u, int v);
int findOp(int idx);

int main() {
    getInput();
    kruscal();
    cout << result;
    return 0;
}

void getInput() {
    cin >> nV >> nE;
    rootOf.resize(nV + 1);
    rankOf.resize(nV + 1, 0);

    for(int i = 0 ; i < nV + 1 ; i++) {
        rootOf[i] = i;
    }

    for(int i = 0 ; i < nE ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({w, {u, v}});
    }
}

void kruscal() {
    int Ecnt = 0;
    while(Ecnt < nV - 1) {
        pair<int, pair<int, int>> cur = pq.top();
        int u = cur.second.first;
        int v = cur.second.second;
        int w = cur.first;
        pq.pop();
        if(findOp(u) != findOp(v)) {
            result += w;
            Ecnt++;
            unionOp(u, v);
        }

    }
}

void unionOp(int u, int v) {
    if(rankOf[rootOf[u]] > rankOf[rootOf[v]]) {
        rootOf[rootOf[v]] = rootOf[u];
    }
    else if(rankOf[rootOf[v]] < rankOf[rootOf[u]]) {
        rootOf[rootOf[u]] = rootOf[v];
    }
    else {
        rankOf[rootOf[u]]++;
        rootOf[rootOf[v]] = rootOf[u];
    }
}

int findOp(int idx) {
    if(rootOf[idx] != idx) {
        rootOf[idx] = findOp(rootOf[idx]);
    }
    return rootOf[idx];
}