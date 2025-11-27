#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int m;
int numOfCh;
int numOfH;
int result = INT_MAX;
vector<pair<int,int>> house;
vector<pair<int,int>> chick;
vector<vector<int>> dist;
vector<bool> visited;
vector<int> current;
vector<int> minDist;

void getInput();
void backTrack(int numA, int numB);
void calDist();
void calMinDist();

int main() {
    getInput();
    calDist();
    if(numOfCh > m) {
        for(int i = 0 ; i < numOfCh; i ++) {
            backTrack(i,0);
        }
    }
    else {
        calMinDist();
    }
    cout << result;
    return 0;
}

void getInput() {
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            int temp;
            cin >> temp;
            if(temp == 1) {
                house.push_back({i, j});
            }
            if(temp == 2) {
                chick.push_back({i, j});
            }
        }
    }
    numOfCh = chick.size();
    numOfH = house.size();
    current.resize(min(m,numOfCh));
    for(int i = 0 ; i < min(m, numOfCh); i++) {
        current[i] = i;
    }
    minDist.resize(numOfH, INT_MAX);
    visited.assign(numOfCh, false);
    dist.assign(numOfCh, vector<int>(numOfH,0));
}

void backTrack(int numA, int numB) {
    visited[numA] = true;
    current[numB] = numA;
    numB++;
    if(numB == min(m, numOfCh)) {
        calMinDist();
    }
    else {
        for(int i = numA ; i < numOfCh ; i++) {
            if(visited[i] == false) {
                backTrack(i, numB);
            }
        }
    }
    visited[numA] = false;
}

void calDist() {
    for(int i = 0; i < numOfCh; i++) {
        for(int j = 0 ; j < numOfH ; j++) {
            int chR = chick[i].first;
            int chC = chick[i].second;
            int hR = house[j].first;
            int hC = house[j].second;
            dist[i][j] = abs(chR - hR) + abs(chC - hC);
        }
    }

}
void calMinDist() {
    minDist.assign(numOfH, INT_MAX);
    for(int c = 0 ; c < current.size(); c++) {
        for(int i = 0 ; i < numOfH ; i++) {
            minDist[i] = min(minDist[i], dist[current[c]][i]);
        }
    }
    int localsum = 0;
    for(int i = 0 ; i < numOfH ; i++) {
        localsum = localsum + minDist[i];
    }
    result = min(result, localsum);
}
