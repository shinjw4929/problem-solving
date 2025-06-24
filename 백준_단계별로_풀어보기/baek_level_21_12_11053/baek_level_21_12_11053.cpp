#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<vector<int>> trace;
vector<int> rowmax;

void find_trace();
int find_max_length();

int main() {
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    trace.resize(n, vector<int>(n));
    rowmax.resize(n);
    find_trace();
    cout << find_max_length() + 1;

    return 0;
}

void find_trace() {
    for(int i = 0; i < n - 1 ; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] < arr[j]) {
                trace[i][j] = 1;
            }
        }
    }
}

int find_max_length() {
    for(int r = n - 2 ; r >= 0 ; r--) {
        for(int c = n - 1 ; c >= 0 ; c--) {
            int result = 0;
            if(trace[r][c]) {
                result = 1 + rowmax[c];
                if(rowmax[r] < result) {
                    rowmax[r] = result;
                }
            }
        }
    }
    int max = 0;
    for(int i = 0 ; i < n; i++) {
        if(max < rowmax[i]) {
            max = rowmax[i];
        }
    }
    return max;
}