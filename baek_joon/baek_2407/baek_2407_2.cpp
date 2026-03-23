#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N = 100000; //[2, 100000]
vector<int> arr;

void getInput();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getInput();
    solve();
}

void getInput() {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
}

void solve() {
    int left = 0, right = N - 1;
    int solutionLeft = arr[left];
    int solutionRight = arr[right];
    int solution = abs(solutionLeft + solutionRight);
    while (left < right) {
        int current = arr[left] + arr[right];
        if (solution > abs(current)) {
            solutionLeft = arr[left];
            solutionRight = arr[right];
            solution = abs(solutionLeft + solutionRight);
        }

        if (current > 0) {
            right--;
        }
        else if (current < 0) {
            left++;
        }
        else {
            break;
        }
    }

    cout << solutionLeft << " " << solutionRight;
}