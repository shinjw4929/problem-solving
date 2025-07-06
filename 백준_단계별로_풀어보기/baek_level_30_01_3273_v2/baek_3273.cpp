#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N = 100000, X = 2000000, result = 0;
vector<int> arr;

void get_input();
void two_pointer();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    two_pointer();
    cout << result;
    return 0;
}

void get_input() {
    cin >> N;
    arr.resize(N);
    for (auto&iter: arr) {
        cin >> iter;
    }
    cin >> X;
    sort(arr.begin(), arr.end());
}
void two_pointer() {
    int left = 0, right = N - 1;
    while (left < right) {
        int cur_sum = arr[left] + arr[right];
        if (cur_sum > X) {
            right--;
        }
        else if (cur_sum < X) {
            left++;
        }
        else {
            result++;
            right--;
            left++;
        }
    }

}