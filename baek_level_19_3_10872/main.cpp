#include <iostream>

using namespace std;

int main() {
    long long int N ,fact = 1;
    cin >> N;
    for(long long int i = 1 ; i <= N ; i++) {
        fact = fact * i;
    }

    cout << fact;
    return 0;
}
