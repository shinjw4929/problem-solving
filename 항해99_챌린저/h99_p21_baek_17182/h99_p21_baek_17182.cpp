#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int numOfV;
int startV;
vector<vector<int>> timeArr;
vector<bool> visited;
vector<bool> allTrue;
int result = INT_MAX;
int temp = 0;

void getInput();
void floydWarshall();
void dfs(int vertex);

int main() {
    getInput();
    floydWarshall();
    dfs(startV);
    cout << result;
    return 0;
}


void getInput() {
    cin >> numOfV >> startV;
    visited.resize(numOfV, false);
    allTrue.resize(numOfV, true);
    timeArr.resize(numOfV, vector<int>(numOfV));
    for(int i = 0 ; i < numOfV ; i++) {
        for(int j = 0 ; j < numOfV ; j++) {
            cin >> timeArr[i][j];
        }
    }
}

void floydWarshall() {
    for(int target = 0 ; target < numOfV ; target++) {
        for(int i = 0 ;  i < numOfV ; i++) {
            for(int j = 0 ; j < numOfV ; j++) {
                timeArr[i][j] = min(timeArr[i][j], timeArr[i][target] + timeArr[target][j]);
            }
        }
    }
}

void dfs(int vertex) {
    visited[vertex] = true;
    for(int i = 0 ; i < numOfV ; i++) {
        if(!visited[i]) {
            temp += timeArr[vertex][i];
            dfs(i);
            temp -= timeArr[vertex][i];
        }
    }

    if(visited == allTrue) {
        result = min(result, temp);
    }

    visited[vertex] = false;
}
