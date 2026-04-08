#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N = 100000; //[1, 100000]
long long M = 1000000000; //[1, 1000000000]
long long maxJudgeTime = 0;
vector<long long> arr;

void getInput();
void solve();
long long countHuman(long long time);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getInput();
    solve();
    return 0;
}

void getInput() {
    cin >> N >> M;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        maxJudgeTime = max(maxJudgeTime, arr[i]);
    }
}

void solve() {
    long long left = 1;
    long long right = M * maxJudgeTime;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long toCompare = countHuman(mid);
        if (toCompare >= M) {
            right = mid - 1;
        }
        else if (toCompare < M) {
            left = mid + 1;
        }
    }
    cout << left;
}

long long countHuman(long long time) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += time / arr[i];
        // M 이상이 되는 순간 더 계산할 필요 없이 바로 리턴
        if (sum >= M) return sum;
    }
    return sum;
}