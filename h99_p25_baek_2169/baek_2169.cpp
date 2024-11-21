#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int numOfR;
int numOfC;
int result = INT_MIN;
vector<vector<int>> mtx;
vector<vector<int>> dp;

void getInput();
void findMax();

int main() {
    getInput();
    findMax();
    cout << dp[numOfR - 1][numOfC - 1];
    return 0;
}

void getInput() {
    cin >> numOfR >> numOfC;
    mtx.resize(numOfR, vector<int>(numOfC));
    dp.assign(numOfR, vector<int>(numOfC, 0));
    for(int i = 0 ; i < numOfR ; i++) {
        for(int j = 0 ; j < numOfC ; j ++) {
            cin >> mtx[i][j];
        }
    }
}

void findMax() {
    dp[0][0] = mtx[0][0];
    for(int i = 1 ; i < numOfC ; i++) {
        dp[0][i] = mtx[0][i] + dp[0][i - 1];
    }

    for(int row = 1 ; row < numOfR ; row++) {
        vector<int> right(numOfC, INT_MIN);
        right[numOfC - 1] = mtx[row][numOfC - 1] + dp[row - 1][numOfC - 1];
        for(int col = numOfC - 2 ; col >= 0 ; col--) {
            right[col] = max(right[col + 1], dp[row - 1][col])  + mtx[row][col];
        }
        vector<int> left(numOfC, INT_MIN);
        left[0] = mtx[row][0] + dp[row - 1][0];
        for(int col = 1 ; col < numOfC ; col++) {
            left[col] = max(left[col - 1],dp[row - 1][col])  + mtx[row][col];
        }
        for(int col = 0 ; col < numOfC ; col++) {
            dp[row][col] = max(left[col], right[col]);
        }
    }
}
