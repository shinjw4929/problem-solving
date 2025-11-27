#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num, min_d = 1000001, max_d = 1;
    cin >> num;
    for(int i = 0 ; i < num ; i++) {
        int temp;
        cin >> temp;
        if(temp < min_d) {
            min_d = temp;
        }
        if(temp > max_d) {
            max_d = temp;
        }
    }
    cout << min_d * max_d;
    return 0;
}
