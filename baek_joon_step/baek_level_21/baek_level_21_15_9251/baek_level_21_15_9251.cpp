#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int size1 = str1.size(), size2 = str2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for (int r = 1 ; r < size1 + 1 ; r++) {
        for (int c = 1 ; c < size2 + 1 ; c++) {
            if (str1[r - 1] == str2[c - 1]) {
                dp[r][c] = dp[r - 1][c - 1] + 1;
            }
            else {
                dp[r][c] = max(dp[r][c - 1], dp[r - 1][c]);
            }
        }
    }
    cout << dp[size1][size2];
    return 0;
}