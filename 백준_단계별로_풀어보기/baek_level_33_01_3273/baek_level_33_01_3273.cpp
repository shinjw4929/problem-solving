#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numOfArr, targetNum;
    cin >> numOfArr;
    vector<int> arr(numOfArr);
    for(int i = 0 ; i < numOfArr ; i++) {
        cin >> arr[i];
    }
    cin >> targetNum;

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = numOfArr - 1;
    int cnt = 0;
    while(left < right) {
        int currentSum = arr[left] + arr[right];
        if(currentSum == targetNum) {
            left ++;
            right--;
            cnt++;
        }
        else if(currentSum > targetNum) {
            right--;
        }
        else {
            left++;
        }
    }
    cout << cnt;
    return 0;
}
