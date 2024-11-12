#include <iostream>
#include <vector>

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<long long> distance(n-1);
    vector<long long> price(n);
    for(int i = 0; i < n - 1; i++) {
        cin >> distance[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    long long cur_price = price[0];
    long long tot = cur_price * distance[0];;
    for(int i = 1; i < n-1; i++) {
        if(cur_price > price[i]) {
            cur_price = price[i];
        }
        tot = tot + cur_price * distance[i];
    }
    cout << tot;
    return 0;
}
