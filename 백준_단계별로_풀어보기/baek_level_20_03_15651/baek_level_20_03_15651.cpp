#include <iostream>
#include <vector>

using namespace std;

void pi(vector<int> arr, int level, int m);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    pi(arr, 0, m);
    return 0;
}

void pi(vector<int> arr, int level, int m) {
    if(level == m) {
        for(int i = 0 ; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for(int i = 0 ; i < arr.size(); i++) {
            arr[level] = i + 1;
            pi(arr, level + 1, m);
        }
    }

}