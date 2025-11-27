#include <iostream>
#include <vector>

#define MAX 10001
using namespace std;

class Graph {
private:
    int numOfT, numOfV, numOfE, numOfW;
    vector<vector<pair<int, int>>> adj;
    vector<int> timeArr;
public:
    void getInput();
    bool bellman_ford();
};

int main() {
    Graph prob;
    prob.getInput();
    return 0;
}

void Graph::getInput() {
    cin >> numOfT;
    for (int t = 0; t < numOfT; t++) {
        cin >> numOfV >> numOfE >> numOfW;
        adj.assign(numOfV, vector<pair<int, int>>());
        timeArr.assign(numOfV, MAX);
        timeArr[0] = 0;

        for (int i = 0; i < numOfE; i++) {
            int start, end, time;
            cin >> start >> end >> time;
            start--; end--;
            adj[start].push_back({end, time});
            adj[end].push_back({start, time});
        }
        for (int i = 0; i < numOfW; i++) {
            int start, end, time;
            cin >> start >> end >> time;
            start--; end--;
            adj[start].push_back({end, -time});
        }

        if (bellman_ford()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

bool Graph::bellman_ford() {
    for (int i = 0; i < numOfV - 1; i++) {
        for (int u = 0; u < numOfV; u++) {
            for (auto [v, weight] : adj[u]) {
                if (timeArr[v] > timeArr[u] + weight) {
                    timeArr[v] = timeArr[u] + weight;
                }
            }
        }
    }

    for (int u = 0; u < numOfV; u++) {
        for (auto [v, weight] : adj[u]) {
            if (timeArr[v] > timeArr[u] + weight) {
                return true;
            }
        }
    }
    return false;
}
