#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int arr_size;
    cin >> arr_size;
    arr.resize(arr_size);
    for (auto& iter: arr) {
        cin >> iter;
    }
    vector<int> dp(arr_size);

    if (arr_size == 1) {
        cout << arr[0];
        return 0;
    }
    else if (arr_size == 2) {
        cout << arr[0] + arr[1];
        return 0;
    }
    else if (arr_size == 3) {
        cout << max(arr[0] + arr[2], arr[1] + arr[2]);
        return 0;
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    for (int i = 3 ; i < arr_size ; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }
    cout<< dp[arr_size - 1];
    return 0;
}