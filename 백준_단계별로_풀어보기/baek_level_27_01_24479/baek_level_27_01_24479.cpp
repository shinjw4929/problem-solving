#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class problemGraph {
private:
    int numOfVertices;
    int numOfEdges;
    int visitOrder = 1;
    vector<int> visitArr;
    vector<vector<int>> graph;
public:
    int startVertex;
    void getInput();
    void dfs(int start_node);
    void print();
};

int main() {
    problemGraph prob;
    prob.getInput();
    prob.dfs(prob.startVertex - 1);
    prob.print();
    return 0;
}

void problemGraph::getInput() {
    cin >> numOfVertices >> numOfEdges >> startVertex;

    graph.resize(numOfVertices);
    visitArr.resize(numOfVertices, -1);

    for(int i = 0; i < numOfEdges; i++) {
        int start, end;
        cin >> start >> end;
        graph[start-1].push_back(end - 1);
        graph[end-1].push_back(start - 1);
    }
    for(int i = 0; i < numOfVertices; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
}

void problemGraph::dfs(int start_node) {
    if(visitArr[start_node] == -1) {
        visitArr[start_node] = visitOrder;
    }
    for(int neighbor : graph[start_node]) {
        if(visitArr[neighbor] == -1) {
            visitOrder++;
            dfs(neighbor);
        }
    }
}

void problemGraph::print() {
    for(int i = 0 ; i < numOfVertices ; i++) {
        if(visitArr[i] == -1) {
            cout << 0 << '\n';
        }
        else {
            cout << visitArr[i] << '\n';
        }

    }
}