#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N = 100;
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N - 1 - i ; j++) {
            cout << ' ';
        }
        for (int j = 0 ; j < 2 * i + 1 ; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for (int i = N - 2 ; i >= 0 ; i--) {
        for (int j = 0 ; j < N - 1 - i ; j++) {
            cout << ' ';
        }
        for (int j = 0 ; j < 2 * i + 1 ; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}