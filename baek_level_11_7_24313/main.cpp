#include <iostream>

using namespace std;

int main() {
    int a1, a0, c, n0;
    bool is_true = true; // n값이 증가함에 따라 O notation 만족안하면 false
    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    for(int i = n0; i <= 100 ; i ++) {
        if(c * i < a1 * i + a0) {
            is_true = false;
            break;
        }
    }
    if(is_true) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
