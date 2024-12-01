#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 100000

using namespace std;

int main() {
    int input; //input#
    cin >> input;
    int rt, count = 0, temp = 0;

    while (input != -1) {
        rt = sqrt(input); //sqrt(input)에 대해서 조사하여 약수 구함 -> 시간 복잡도 O(N^(1/2))
        int arrsize = rt*2; //배열 크기
        int *arr = new int[arrsize]; //배열 동적할당
        fill_n(arr, arrsize, MAX); //배열을 MAX로 초기화
        int idx = 0;
        for(int i = 1; i <= rt; i++) { //약수 구함
            if(!(input % i)) {
                arr[idx] = i;
                temp = temp + i;
                count ++; //총 약수

                int pair = input / i;
                if(pair != i && input / i != input) { //구한 약수로 다른 약수 구함(자기자신, 제곱수 제외
                    arr[arrsize - 1 - idx] = pair;
                    temp = temp + (pair);
                    count ++;
                }
                idx ++;
            }
        }

        if(temp == input) {
            sort(arr, arr + arrsize);
            cout << input << " = ";
            for(int idx = 0; idx < count - 1; idx++) {
                cout << arr[idx] << " + ";
            }
            cout << arr[count - 1] << endl;
        }
        else {
            cout << input << " is NOT perfect." << endl;
        }
        cin >> input;
        temp = 0;
        count = 0;

        delete arr;
    }

    return 0;
}
