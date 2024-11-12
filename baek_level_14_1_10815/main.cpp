#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ///////////////입력
    int num1, num2;
    cin >> num1;
    vector<int> arr1(num1);
    for(int &i : arr1) {
        cin >> i;
    }
    cin >> num2;
    vector<int> arr2(num2);
    for(int &i : arr2) {
        cin >> i;
    }
    //////////////

    sort(arr1.begin(), arr1.end());//arr1 정렬
    for(int i = 0 ; i < num2; i++) {
        arr2[i] = binary_search(arr1.begin(), arr1.end(), arr2[i]);
    }

    for(int &i : arr2) {
        cout << i << ' ';
    }



    return 0;
}
