#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N = 100000;
    int K = 100000;
    cin >> N >> K;
    vector<int> arr(N);
    for (auto&iter:arr) {
        cin >> iter;
    }
    for (int i = 1 ; i < N ; i++) {
        arr[i] += arr[i-1];
    }
    int MAX_TEMP = arr[K - 1];
    for (int i = K ; i < N ; i++) {
        MAX_TEMP = max(MAX_TEMP, arr[i] - arr[i-K]);
    }
    cout << MAX_TEMP;
    return 0;
}