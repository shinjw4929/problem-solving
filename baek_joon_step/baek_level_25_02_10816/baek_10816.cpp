#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N = 500000, M = 500000;
    cin >> N;
    unordered_map<int, int> card2num;
    for (int i = 0 ; i < N ; i++) {
        int temp;
        cin >> temp;
        card2num[temp]++;
    }
    cin >> M;
    for (int i = 0 ; i < M ; i++) {
        int temp;
        cin >> temp;
        cout << card2num[temp] << ' ';
    }
    return 0;
}