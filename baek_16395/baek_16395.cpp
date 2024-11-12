#include <iostream>

using namespace std;

int pascal(int r, int c);

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    cout << pascal(n1, n2);
    return 0;
}


int pascal(int r, int c) {
    int sum = 0;
    if(r == 1 || c == 1 ||r == c) {
        return 1;
    }
    else {
        return pascal(r - 1, c) + pascal(r - 1, c - 1);
    }
    return sum;
}
