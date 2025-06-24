#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 0;
    cin >> T;
    for (int i = 0 ; i < T ; i++) {
        string cur_str;
        cin >> cur_str;
        string temp = cur_str;
        reverse(temp.begin(), temp.end());
        if (cur_str == temp) {
            cout << 1 << ' ' << cur_str.size() / 2 + 1 << '\n';
        }
        else {
            for (int j = 0 ; j < cur_str.size() / 2 ; j++) {
                if (cur_str[j] != temp[j]) {
                    cout << 0 << ' ' << j + 1 << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}