#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<long long>sum(n+1);
    vector<long long>remainder(m);
    long long int cnt = 0;
    for(int i = 0 ; i < n; i++) {
        long long int temp;
        cin >> temp;
        temp = (sum[i] + temp) % m;
        remainder[temp]++;
        sum[i + 1] = temp;
    }
    cnt = remainder[0];
    for(int i = 1; i < n + 1;i++) {
        remainder[sum[i]] --;
        cnt = cnt + remainder[sum[i]];
    }
    cout << cnt;
    return 0;
}
