#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    list<int> chess_list(6);
    chess_list = {1, 1, 2, 2, 2, 8};
    for (auto& iter:chess_list) {
        int input;
        cin >> input;
        cout << iter - input << ' ';
    }

    return 0;
}