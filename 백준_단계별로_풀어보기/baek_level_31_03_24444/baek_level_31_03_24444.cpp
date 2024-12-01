#include <iostream>
#include<vector>
#include<unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class graph {
private:
    int numOfV, numOfE;
    int order = 1;
    vector<vector<int>> vNeGraph;
    vector<int> visitOrder;

    unordered_set<int> isVisited;
    queue<int> bfsQ;
public:
    int startV;
    void getInput();
    void bfs();
    void print();
};

int main() {
    graph prob;
    prob.getInput();
    prob.bfs();
    prob.print();
    return 0;
}
void graph::getInput() {
    cin >> numOfV >> numOfE >> startV;
    visitOrder.resize(numOfV, 0);
    vNeGraph.resize(numOfV);
    startV--;
    visitOrder[startV] = order;
    order++;
    isVisited.insert(startV);
    bfsQ.push(startV);
    for(int i = 0; i < numOfE; i++) {
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        vNeGraph[start].push_back(end);
        vNeGraph[end].push_back(start);
    }
    for(int i = 0; i < numOfV; i++) {
        sort(vNeGraph[i].begin(), vNeGraph[i].end());
    }


}

void graph::bfs() {
    while(!bfsQ.empty()) {
        int start = bfsQ.front();
        bfsQ.pop();
        for(int i = 0; i < vNeGraph[start].size(); i++) {
            int end = vNeGraph[start][i];
            if(isVisited.find(end) == isVisited.end()) {
                isVisited.insert(end);
                bfsQ.push(end);
                visitOrder[end] = order;
                order++;
            }
        }
    }
}

void graph::print() {
    for(int i = 0; i < numOfV ; i++) {
        cout << visitOrder[i] << '\n';
    }
}
