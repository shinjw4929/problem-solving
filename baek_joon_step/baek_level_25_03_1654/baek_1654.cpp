#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K = 10000, N = 1000000;
vector<int> arr;
void get_input();
void find_max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    find_max();
    return 0;
}

void get_input() {
    cin >> K >> N;
    arr.resize(K);
    for (auto &iter : arr) {
        cin >> iter;
    }
}

void find_max() {
    long long maxV = 0;
    if (!arr.empty()) {
        maxV = *max_element(arr.begin(), arr.end());
    }

    long long minV = 1;
    long long sol = 0;

    while (minV <= maxV) {
        // midV 계산은 반복문 안에서, 오버플로우에 안전한 방식으로 수행합니다.
        long long midV = minV + (maxV - minV) / 2;

        long long tot = 0;
        for (const auto &iter : arr) {
            tot += iter / midV;
        }
        if (tot >= N) {
            sol = midV;
            minV = midV + 1;
        } else {
            maxV = midV - 1;
        }
    }
    cout << sol;
}