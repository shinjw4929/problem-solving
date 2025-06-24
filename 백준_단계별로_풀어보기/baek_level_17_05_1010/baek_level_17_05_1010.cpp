#include <iostream>

using namespace std;

int main() {
    int t;
    long long int N, M, sub, H = 1;
    cin >> t;
    for(int test = 0 ; test < t ; test++) {
        cin >> N >> M;
        sub = M - N;
        for(long long int i = N + 1, j = 1 ; i <= M && j <= sub ; i++ , j++) {
            H = H * i;
            H = H / j;
        }
        cout << H << '\n';
        H = 1;
    }
    return 0;
}
