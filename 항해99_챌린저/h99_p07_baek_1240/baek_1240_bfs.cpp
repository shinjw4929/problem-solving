#include <iostream>
#include <vector>
#include <queue>
#include <variant>

using namespace std;

class Tree {
private:
    int numOfNodes, numOfQueries;
    vector<vector<pair<int, int>>> adj;
    vector<bool> visited;
public:
    void getInput();
    void processQueries();
    int bfs(int start, int end);
};

int main() {
    Tree tree;
    tree.getInput();
    tree.processQueries();
    return 0;
}


void Tree::getInput() {
    cin >> numOfNodes >> numOfQueries;
    adj.resize(numOfNodes + 1);
    for(int i = 0 ; i < numOfNodes - 1; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
}

void Tree::processQueries() {
    for(int i = 0 ; i< numOfQueries ; i++) {
        int start, end;
        cin >> start >> end;
        cout << bfs(start, end) << '\n';
    }
}

int Tree::bfs(int start, int end) {
    visited.assign(numOfNodes + 1, false);
    queue<pair<int, int>> bfsQ; // current_node & sum_of_distance;
    bfsQ.push({start, 0});
    visited[start] = true;

    while(!bfsQ.empty()) {
        int currentNode = bfsQ.front().first;
        int currentWeight = bfsQ.front().second;
        bfsQ.pop();
        if(currentNode == end) {
            return currentWeight;
        }
        for(auto &neighbor : adj[currentNode]) {
            if(!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                bfsQ.push({neighbor.first, neighbor.second + currentWeight});
            }
        }
    }
    return -1;
}
