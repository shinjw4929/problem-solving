#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> dp;
vector<int> dprev;

void max_inc();
void max_dec();

int main() {
    cin >> n;
    arr.resize(n);
    dp.resize(n, 1);
    dprev.resize(n, 1);
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    max_inc();
    max_dec();

    int maxresult = 0;
    for(int i = 0 ; i < n; i++) {
        dp[i] = dp[i] + dprev[i] - 1;
        maxresult = max(maxresult, dp[i]);
    }
    cout << maxresult;
    return 0;
}

void max_inc() {
    for(int i = 1 ; i < n; i++) {
        for(int j = 0 ; j < i ; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}
void max_dec() {
    for(int i = n - 2 ; i >= 0; i--) {
        for(int j = n - 1 ; j > i; j--) {
            if(arr[j] < arr[i]) {
                dprev[i] = max(dprev[i], dprev[j] + 1);
            }
        }
    }
}