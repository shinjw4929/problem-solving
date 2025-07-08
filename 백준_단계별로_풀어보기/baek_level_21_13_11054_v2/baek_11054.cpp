#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 1000;
vector<int> arr;
vector<int> dp_lis;
vector<int> dp_lds;

void get_input();
void calculate_dp();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_dp();
    return 0;
}

void get_input() {
    cin >> N;
    arr.resize(N);
    dp_lis.resize(N,1);
    dp_lds.resize(N,1);
    for (auto& iter : arr) {
        cin >> iter;
    }
}

void calculate_dp() {
    for (int i = 0 ; i < N - 1 ; i++) {
        for (int j = i + 1 ; j < N ; j++) {
            if (arr[i] < arr[j]) {
                dp_lis[j] = max(dp_lis[j], dp_lis[i] + 1);
            }
        }
    }
    for (int i = N - 1 ; i > 0 ; i--) {
        for (int j = i - 1 ; j >= 0 ; j--) {
            if (arr[i] < arr[j]) {
                dp_lds[j] = max(dp_lds[j], dp_lds[i] + 1);
            }
        }
    }

    int result = 0;
    for (int i = 0 ; i < N ; i++) {
        result = max(result, dp_lis[i] + dp_lds[i] - 1);
    }
    cout << result;
}