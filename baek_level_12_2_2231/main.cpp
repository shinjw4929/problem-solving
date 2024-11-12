#include <iostream>

using namespace std;

int main() {
    int input;
    cin >> input;
    int temp = input ,count = 0, sum = 0;
    int answ = 0;

    //자릿수 세기
    while(temp) {
        temp = temp / 10;
        count ++;
    }

    //숫자 1부터 끝까지 빼고 빠진 수의 각 자리 수의 합이 뺀 수와 같으면 생성자 후보
    for(int i = 1 ; i < input ; i++) {
        sum = 0;
        temp = input - i;
        for(int j = 0 ; j < count ; j++) {
            sum = sum + temp % 10;
            temp = temp / 10;
        }
        if(sum == i) {
            answ = input - i ;
        }
    }

    cout << answ;
    return 0;
}
