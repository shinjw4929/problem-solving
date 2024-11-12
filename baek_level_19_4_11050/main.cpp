#include <iostream>

using namespace std;

int main() {
    long long int N, K;
    cin >> N >> K;
    long long int n_k = N-K;
    long long int comb = 1;
    for(long long int i = 1 ; i <= N ; i++) {
        comb = comb * i;
    }
    for(long long int i = 1 ; i <= K ; i++) {
        comb = comb / i;
    }
    for(long long int i = 1 ; i <= n_k ; i++) {
        comb = comb / i;
    }
    cout << comb;
    return 0;
}
