#include <iostream>
#include <vector>

using namespace std;

void select(vector<int> arr, vector<bool> visited, int sel, int m);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<bool> visited(n, false);
    select(arr, visited,0 , m);
    return 0;
}

void select(vector<int> arr, vector<bool> visited, int sel, int m) {
    if(sel == m) {
        for(int i = 0 ; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for(int i = 0; i < arr.size(); i++) {
            if(!visited[i]) {
                arr[sel] = i + 1;
                visited[i] = true;
                select(arr, visited, sel + 1 ,m);
            }
        }
    }
}