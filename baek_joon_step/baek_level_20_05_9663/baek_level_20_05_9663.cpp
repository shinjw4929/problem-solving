#include <iostream>
#include <vector>

using namespace std;

int n;
int result = 0;
vector<bool> column;
vector<bool> left_diag;
vector<bool> right_diag;

void dfs(int row);


int main() {
    cin >> n;
    column.resize(n, true);
    left_diag.resize(2*n - 1, true);
    right_diag.resize(2*n - 1, true);
    dfs(0);
    cout << result;
    return 0;
}

void dfs(int row) {
    if(row == n) {
        result ++;
    }
    else {
        for(int col = 0 ; col < n; col++) {
            if(column[col] && left_diag[row + col] && right_diag[row - col + n - 1]) {
                column[col] = left_diag[row + col] = right_diag[row - col + n - 1] = false;
                dfs(row + 1);
                column[col] = left_diag[row + col] = right_diag[row - col + n - 1] = true;
            }
            else {

            }
        }
    }
}
