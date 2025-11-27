#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int n;
vector<unordered_set<int>> adj;
vector<int> times;
vector<int> result;
vector<int> inEdges;
queue<int> workQ;

void getInput();
void calWorksDone();
int findMaxTime();

int main() {
    getInput();
    calWorksDone();
    cout << findMaxTime();
    return 0;
}

void getInput() {
    cin >> n;
    times.resize(n);
    result.resize(n);
    inEdges.resize(n);
    adj.resize(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> times[i];
        result = times;
        int cnt = 0;
        while(cin.peek() != '\n') {
            int temp;
            cin >> temp;
            if(temp == 0) {
                workQ.push(i);
            }
            else {
                if(adj[temp - 1].find(i) == adj[temp - 1].end()) {
                    cnt++;
                    adj[temp - 1].insert(i);
                }
            }
        }
        inEdges[i] = cnt;
    }
}
void calWorksDone() {
    while(!workQ.empty()) {
        int current = workQ.front();
        workQ.pop();
        for(auto &iter : adj[current]) {
            int next = iter;
            inEdges[next]--;
            if(inEdges[next] == 0) {
                workQ.push(next);
            }
            result[next] = max(result[next], result[current] + times[next]);
        }
    }

}

int findMaxTime() {
    int maxTime;
    for(int i = 0 ; i < n; i++) {
        maxTime = max(maxTime, result[i]);
    }
    return maxTime;
}
