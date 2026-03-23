#include <iostream>
#include <vector>

using namespace std;

int N = 1000000, M = 2000000000;
int maxHeight = 0;
vector<int> tree;

void getInput();
void solve();
long long findOptimalHeight(int height);

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
    tree.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        maxHeight = max(maxHeight, tree[i]);
    }
}

void solve() {
    int left = 1, right = maxHeight;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (M > findOptimalHeight(mid)) {
            right = mid - 1;
        }
        else if (M < findOptimalHeight(mid)) {
            left = mid + 1;
        }
        else {
            cout << mid;
            return;
        }
    }
    cout << right;
}

long long findOptimalHeight(int height) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += static_cast<long long>(max(0, tree[i] - height));
    }
    return sum;
}