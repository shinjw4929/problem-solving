#include <iostream>

using namespace std;

long long int factorial(int num);

int main() {
    int N = 20;
    cin >> N;
    cout << factorial(N);
    return 0;
}

long long int factorial(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}