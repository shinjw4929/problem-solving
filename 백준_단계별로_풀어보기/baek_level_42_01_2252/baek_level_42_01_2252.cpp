#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Topo {
private:
    int numOfV;
    int numOfE;
    int visitNum = 0;
    int start;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<pair<int, int>> postN; //post#, vertex
public:
    void getInput();
    void serch();
    void dfs(int curV);
    void print();
};

int main() {
    Topo sol;
    sol.getInput();
    sol.serch();
    sol.print();
    return 0;
}

void Topo::getInput() {
    cin >> numOfV >> numOfE;
    adj.resize(numOfV + 1, vector<int>());
    visited.resize(numOfV + 1 , false);
    postN.resize(numOfV);
    for(int i = 0 ; i < numOfE ; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void Topo::serch() {
    for(int i = 1 ; i < numOfV + 1 ; i++) {
        if(visited[i] == false) {
            dfs(i);
        }
    }
}


void Topo::dfs(int curV) {
    visited[curV] = true;
    for(auto &iter : adj[curV]) {
        if(!visited[iter]) {
            visitNum ++;
            dfs(iter);
        }
    }
    visitNum++;
    postN[curV - 1] = {visitNum, curV};
}
void Topo::print() {
    sort(postN.begin(), postN.end(), greater());
    for(auto &iter : postN) {
        cout << iter.second << ' ';
    }
}
