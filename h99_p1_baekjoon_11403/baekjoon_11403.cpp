#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<bool>> gmtx;
vector<vector<bool>> result;

void update(int row);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    gmtx.resize(n, vector<bool>(n));
    result.resize(n, vector<bool>(n));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            bool temp;
            cin >> temp;
            gmtx[i][j] = temp;
            result[i][j] = temp;
        }
    }

    for(int target = 0 ; target < n ; target++) {
        for(int start = 0 ; start < n; start++) {
            for(int end = 0; end < n ; end++) {
                gmtx[start][end] = gmtx[start][end] || (gmtx[start][target] && gmtx[target][end]);
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            cout << gmtx[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
