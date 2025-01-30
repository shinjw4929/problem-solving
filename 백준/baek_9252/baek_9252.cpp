#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lcs {
private:
    string str1, str2;
    int size1, size2;
    vector<vector<int>> dp;
    vector<char> result;
    void updateDp();
    void findLcs();
public:
    void getInput();
    void calLenNfind();
};
int main() {
    Lcs sol;
    sol.getInput();
    sol.calLenNfind();
    return 0;
}

void Lcs::getInput() {
    cin >> str1 >> str2;
    size1 = str1.size();
    size2 = str2.size();
    dp.resize(size1 + 1, vector<int>(size2 + 1, 0));
}

void Lcs::calLenNfind() {
    updateDp();
    cout << dp[size1][size2] <<'\n';
    findLcs();
    for (int i = result.size() - 1 ; i >= 0 ;i--) {
        cout << result[i];
    }
}

void Lcs::updateDp() {
    for (int r = 1 ; r < size1 + 1 ; r++) {
        for (int c = 1 ; c < size2 + 1 ; c++) {
            if (str1[r - 1] == str2[c - 1]) {
                dp[r][c] = dp[r-1][c-1] + 1;
            }
            else {
                dp[r][c] = max(dp[r-1][c], dp[r][c-1]);
            }
        }
    }
}

void Lcs::findLcs() {
    int row = size1;
    int col = size2;

    while (row > 0 && col > 0) {
        if (str1[row - 1] == str2[col - 1]) {
            result.push_back(str1[row - 1]);
            row--;
            col--;
        }
        else {
            if (dp[row][col - 1] > dp[row - 1][col]) {
                col --;
            }
            else {
                row --;
            }
        }
    }
}
