#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> coins;

int main() {
    cin >> n >> k;
    coins.resize(n);
    for(int i = 0; i < n ; i++) {
        cin >> coins[i];
    }

    int count = 0;
    for(int i = 0; i < n ; i++) {
        int current = coins[n - 1 - i];
        if(current <= k) {
            int temp = k / current;
            count = count + temp;
            k = k - (temp)*current;
        }
    }
    cout << count;


    return 0;
}
