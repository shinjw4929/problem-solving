#include <iostream>
#include <vector>

using namespace std;


int N = 10000;
vector<int> nums;

void get_input();
int cal_dp();

int main() {
    get_input();
    cout << cal_dp();
    return 0;
}

void get_input() {
    cin >> N;
    nums.resize(N);
    for (auto &iter : nums) {
        cin >> iter;
    }
}

int cal_dp() {
    vector<int> dp(nums);
    if (N == 1) {
        return nums[0];
    }
    if (N == 2) {
        return nums[0] + nums[1];
    }
    if (N == 3) {
        return max(nums[0] + nums[1],max(nums[0] + nums[2], nums[1] + nums[2]));
    }
    dp[0] = nums[0];
    dp[1] = nums[0] + nums[1];
    dp[2] = max(nums[0] + nums[1],max(nums[0] + nums[2], nums[1] + nums[2]));
    for (int i = 3 ; i < N ; i++) {
        dp[i] = max(dp[i-1],max(dp[i-2] + nums[i], dp[i-3] + nums[i-1] + nums[i]));
    }
    return dp[N-1];
}