#include <iostream>
#include <vector>

using namespace std;

int testCase;
int numOfFlies;
vector<int> costArr;
vector<vector<int>> dp;


int main() {
    cin >> testCase;
    for(int t = 0; t < testCase ; t++) {
        cin >> numOfFlies;
        costArr.assign(numOfFlies, 0);
        for(int j = 0; j < numOfFlies ; j++) {
            cin >> costArr[j];
        }
        dp.assign(numOfFlies, vector<int>(numOfFlies, 0));

        for(int i = 0; i < numOfFlies - 1;i++) {
            for(int j = i + 1 ; j < numOfFlies;j++) {
                if(j == i+1) {
                    dp[i][j] = costArr[i] + costArr[j];
                }
                else {
                    dp[i][j] = dp[i][j - 1] + costArr[j];
                }
            }
        }

        for(int i = 2; i < numOfFlies ; i++) {
            int start = 0;
            for(int j = i; j < numOfFlies ; j++) {
                int origin = dp[start][j];
                for(int k = start; k < j + 1; k++) {
                        dp[start][j] = min(dp[start][j], dp[start][k] + dp[k+1][j] + origin);
                }
                start++;
            }
        }
        cout << dp[0][numOfFlies - 1] << '\n';
    }
    return 0;
}
