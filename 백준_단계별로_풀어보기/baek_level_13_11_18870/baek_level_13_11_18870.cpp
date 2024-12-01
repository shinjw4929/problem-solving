#include <iostream>
#include <vector>
#include <algorithm>
#include <array>  // std::array를 사용하기 위해 필요

using namespace std;

bool compare(const array<int, 3>& a, const array<int, 3>& b);

bool compare2(const array<int, 3>& a, const array<int, 3>& b);

int main() {
    int in_num;
    cin >> in_num;
    vector<array<int, 3>> arr(in_num, {0, 0, 0});

    // 입력받기
    for(int i = 0 ; i < in_num ; i++) {
        int temp;
        cin >> temp;
        arr[i][0] = temp; // 첫 번째 요소에 입력값 저장
        arr[i][1] = i;    // 두 번째 요소에 인덱스 저장
    }

    // 배열 크기 순으로 정렬
    sort(arr.begin(), arr.end(), compare);

    // 원소 크기가 같으면 압축 주소 증가x
    for(int i = 1 ; i < in_num ; i++) {
        if(arr[i - 1][0] != arr[i][0]) {
            arr[i][2] = arr[i - 1][2] + 1;
        }
        else {
            arr[i][2] = arr[i - 1][2];
        }
    }

    // 다시 인덱스를 기준으로 정렬
    sort(arr.begin(), arr.end(), compare2);

    // 출력
    for(int i = 0 ; i < in_num - 1 ; i++) {
        cout << arr[i][2] << ' ';
    }
    cout << arr[in_num - 1][2];  // 마지막 요소 출력
    return 0;
}

bool compare(const array<int, 3>& a, const array<int, 3>& b) {
    return a[0] < b[0];  // 첫 번째 요소를 기준으로 비교
}

bool compare2(const array<int, 3>& a, const array<int, 3>& b) {
    return a[1] < b[1];  // 두 번째 요소(인덱스)를 기준으로 비교
}
