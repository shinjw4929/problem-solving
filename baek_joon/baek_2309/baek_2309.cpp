#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int sum;

void getInput();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getInput();
    solve();
    return 0;
}

void getInput() {
    arr.resize(9);
    for (int i = 0 ; i < 9 ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
}

void solve() {
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = i + 1; j < 9 ; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (auto iter : arr) {
                    if (iter != arr[i] && iter != arr[j]) {
                        cout << iter << '\n';
                    }
                }
                return;
            }
        }
    }
}