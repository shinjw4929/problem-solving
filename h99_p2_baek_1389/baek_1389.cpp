#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> inter;

void update();
int find_min();

int main() {
    cin >> n >> m;
    inter.resize(n + 1, vector<int>(n + 1, 0));

    for(int i = 0 ; i < m; i++) {
        int man1, man2;
        cin >> man1 >> man2;
        inter[man1][man2] = 1;
        inter[man2][man1] = 1;
    }
    update();
    cout << find_min();
    return 0;
}

void update() {
    for(int target = 1; target < n + 1 ; target ++) {
        for(int i = 1 ; i < n + 1 ; i++) {
            for(int j = 1 ; j < n + 1 ; j++) {
                if(i != j && inter[i][target] && inter[target][j]) {
                    if(inter[i][j] == 0) {
                        inter[i][j] = inter[i][target] + inter[target][j];
                    }
                    else {
                        inter[i][j] = min(inter[i][j], inter[i][target] + inter[target][j]);
                    }
                }
            }
        }
    }
}

int find_min() {
    long long level = 0;
    long long min = -1;
    int minidx;
    for(int i = n ; i >= 1 ; i--) {
        for(int j = 1 ; j < n + 1 ; j++) {
            if(i != j) {
                level = level + inter[i][j];
            }
        }
        if(min == -1 || level <= min) {
            min = level;
            minidx = i;
        }
        level = 0;
    }
    return minidx;
}
