#include <iostream>

using namespace std;

long long cal(long long a, long long b, long long c);

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << cal(a, b, c);
    return 0;
}

long long cal(long long a, long long b, long long c) {
    a = a % c;
    long long result = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            result = (result * a) % c;
        }
        a = (a * a) % c;
        b = b/2;
    }
    return result;
}