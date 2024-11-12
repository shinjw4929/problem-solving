#include <iostream>
#include <vector>

using namespace std;

int fib(int n);
int fibonacci(int n);

int fibcnt = 0;
int fcnt = 0;
vector<int> f(3);

int main() {
    int n;
    cin >> n;
    fib(n);
    fibonacci(n);
    cout << fibcnt << ' ' << fcnt;
    return 0;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        fibcnt++;
        return 1;
    }
    else {
        return (fib(n - 1) + fib(n - 2));
    }
}

int fibonacci(int n){
    f[1] = 1;
    f[2] = 1;
    for(int i = 3 ; i <= n ; i ++) {
        fcnt++;
        f[i] <- f[i - 1] + f[i - 2];
    }
    return f[n];
}