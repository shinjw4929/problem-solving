#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N = 100000;
vector<int> arr;
int min_diff = INT_MAX;
pair<int, int> result = {0, 0};

void get_input();
void two_pointer();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    two_pointer();
    cout << result.first << ' ' << result.second;
    return 0;
}

void get_input() {
    cin >> N;
    arr.resize(N);
    for (auto&iter : arr) {
        cin >> iter;
    }
    sort(arr.begin(), arr.end());
}

void two_pointer() {
    int left = 0, right = N - 1;
    while (left < right) {
        int cur_sum = arr[left] + arr[right];
        if (abs(cur_sum) < min_diff) {
            min_diff = abs(cur_sum);
            result = {arr[left], arr[right]};
        }
        if (cur_sum < 0) {
            left++;
        }
        else if (cur_sum > 0){
            right--;
        }
        else {
            break;
        }
    }
}