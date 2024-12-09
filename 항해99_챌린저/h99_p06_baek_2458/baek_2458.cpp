#include <iostream>
#include <vector>

using namespace std;

class height {
private:
    int nVertices;
    int nEdges;
    vector<vector<int>> graph;
    vector<pair<int, int>> shortNlong;
public:
    int num_know = 0;
    void getInput();
    void floyd_warshall();
    void find_shorter_longer();
    void find_knowing();
};

int main() {
    height prob;
    prob.getInput();
    prob.floyd_warshall();
    prob.find_shorter_longer();
    prob.find_knowing();
    cout << prob.num_know;
    return 0;
}

void height::getInput() {
    cin >> nVertices >> nEdges;
    graph.assign(nVertices, vector<int>(nVertices, -1));
    shortNlong.resize(nVertices,{0,0});
    for(int i = 0 ; i < nEdges ; i++) {
        int shortMan, longMan;
        cin >> shortMan >> longMan;
        graph[shortMan - 1][longMan - 1] = 1;
    }
}

void height::floyd_warshall() {
    for(int target = 0 ; target < nVertices ; target++) {
        for(int i = 0 ; i < nVertices ; i++) {
            for(int j = 0 ; j < nVertices ; j++) {
                if(graph[i][target] != -1 && graph[target][j] != -1) {
                    graph[i][j] = 1;
                }
            }
        }
    }
}


void height::find_shorter_longer() {
    for(int i = 0 ; i < nVertices ; i++) {
        for(int j = 0 ; j < nVertices; j++) {
            if(graph[i][j] == 1) {
                shortNlong[i].second++;
                shortNlong[j].first++;
            }
        }
    }
}

void height::find_knowing() {
    for(int i = 0 ; i < nVertices ; i++) {
        if(shortNlong[i].first + shortNlong[i].second == nVertices - 1) {
            num_know++;
        }
    }
}
