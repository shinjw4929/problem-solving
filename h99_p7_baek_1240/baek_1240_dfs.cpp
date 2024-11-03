#include <iostream>
#include <vector>

using namespace std;

class Tree {
private:
    int numNodes, numQueries;
    vector<vector<pair<int, int>>> adjList;
    vector<bool> visited;
public:
    void getInput();
    int dfs(int current, int target, int distance);
    void processQueries();
};

int main() {
    Tree tree;
    tree.getInput();
    tree.processQueries();
    return 0;
}

void Tree::getInput() {
    cin >> numNodes >> numQueries;
    adjList.resize(numNodes + 1);
    for (int i = 0; i < numNodes - 1; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }
}

int Tree::dfs(int current, int target, int distance) {
    if (current == target) {
        return distance;
    }
    visited[current] = true;
    for (const auto& neighbor : adjList[current]) {
        int nextNode = neighbor.first;
        int edgeWeight = neighbor.second;
        if (!visited[nextNode]) {
            int result = dfs(nextNode, target, distance + edgeWeight);
            if (result != -1) {
                return result;
            }
        }
    }
    return -1;
}

void Tree::processQueries() {
    for (int i = 0; i < numQueries; i++) {
        visited.assign(numNodes + 1, false);
        int start, end;
        cin >> start >> end;
        cout << dfs(start, end, 0) << '\n';
    }
}
