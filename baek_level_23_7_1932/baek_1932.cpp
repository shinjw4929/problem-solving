#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> tri(n);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            int temp;
            cin >> temp;
            tri[i].push_back(temp);
        }
    }
    for(int i = 1 ; i < n ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            if(j == 0) {
                tri[i][j] = tri[i - 1][j] + tri[i][j];
            }
            else if(j == i) {
                tri[i][j] = tri[i - 1][j - 1] + tri[i][j];
            }
            else {
                tri[i][j] = max(tri[i - 1][j] + tri[i][j], tri[i- 1][j - 1] + tri[i][j]);
            }
        }
    }
    int maxSum = 0;
    for(int i = 0 ; i < n ; i++) {
        maxSum = max(maxSum , tri[n - 1][i]);
    }
    cout << maxSum;
    return 0;
}
