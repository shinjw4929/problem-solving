#include <iostream>
#include <vector>

using namespace std;

class tree {
private:
    int nNodes, nWant2Know;
    vector<vector<int>> nodeArr;
public:
    void getInput();
    void floyd_warshall();
};


int main() {
    tree prob;
    prob.getInput();
    return 0;
}

void tree::getInput() {
    cin >> nNodes >> nWant2Know;
    nodeArr.assign(nNodes, vector<int>(nNodes, -1));
    for(int i = 0 ; i < nNodes -1; i++) {
        int start, end, distance;
        cin >> start >> end >> distance;
        nodeArr[start - 1][end - 1] = distance;
        nodeArr[end - 1][start - 1] = distance;
    }
    floyd_warshall();
    for(int i = 0 ; i < nWant2Know ; i++) {
        int start, end;
        cin >> start >> end;
        cout << nodeArr[start - 1][end - 1] << '\n';
    }
}

void tree::floyd_warshall() {
    for(int target = 0 ; target < nNodes ; target++) {
        for(int i = 0 ; i < nNodes ; i++) {
            for(int j = 0 ; j < nNodes ; j++) {
                if(nodeArr[i][target] != -1 && nodeArr[target][j]!=-1) {
                    if(nodeArr[i][j] != -1) {
                        nodeArr[i][j] = min(nodeArr[i][j], nodeArr[i][target] + nodeArr[target][j]);
                    }
                    else {nodeArr[i][j] = nodeArr[i][target] + nodeArr[target][j];

                    }
                }
            }
        }
    }
}
