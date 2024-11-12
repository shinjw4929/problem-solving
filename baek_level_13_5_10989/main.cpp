#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, maxnum = 0;
    vector<int> arr1, arr2;//입력 어레이, counting어레이

    //개수 받아옴
    cin >> num;
    for(int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        if(maxnum < temp) {
            maxnum = temp;
        }
        arr1.push_back(temp);
    }
    //카운팅 어레이 크기 정해줌, 0으로 초기화
    arr2.resize(maxnum + 1, 0);
    //카운팅 해줌
    for(int i = 0 ; i < num; i++) {
        arr2[arr1[i]]++;
    }

    int k = 0;
    for (int i = 0; i < maxnum + 1; i++) {
        while (arr2[i]--) {
            arr1[k++] = i;
        }
    }


    for(int i : arr1) {
        cout << i << '\n';
    }
    return 0;
}
