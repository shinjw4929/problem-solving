#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int numOfV;
int numOfE;
vector<long long> distArr;
vector<pair<long long, pair<int, int>>> edgeArr;


void getInput();
void bellmamFord();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getInput();
    bellmamFord();
    return 0;
}


void getInput() {
    cin >> numOfV >> numOfE;
    edgeArr.resize(numOfE);
    distArr.resize(numOfV, INT_MAX);
    for(int i = 0 ; i < numOfE ; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgeArr[i] = {w, {u - 1, v - 1}};
    }
}

void bellmamFord() {
    int startV = 1 - 1;
    distArr[startV] = 0;
    for(int i = 0 ; i < numOfV - 1; i ++) {
        for(int j = 0 ; j < numOfE ; j++) {
            int start = edgeArr[j].second.first;
            int end = edgeArr[j].second.second;
            long long w = edgeArr[j].first;
            if(distArr[start] != INT_MAX) {
                distArr[end] = min(distArr[end], distArr[start] + w);
            }
        }
    }
    vector<long long> temp(numOfV);
    temp = distArr;
    for(int j = 0 ; j < numOfE ; j++) {
        int start = edgeArr[j].second.first;
        int end = edgeArr[j].second.second;
        long long w = edgeArr[j].first;
        if(distArr[start] != INT_MAX) {
            distArr[end] = min(distArr[end], distArr[start] + w);
        }
    }
    if(temp != distArr) {
        cout << -1;
        return;
    }
    for(int i = 1 ; i < numOfV ; i++) {
        if(distArr[i] != INT_MAX) {
            cout << distArr[i];
        }
        else {
            cout << -1;
        }
        cout <<'\n';
    }

}
