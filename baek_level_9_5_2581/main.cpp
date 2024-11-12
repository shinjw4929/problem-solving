#include <iostream>
#include <cmath>

#define MAX 10001

using namespace std;

int is_prime(int num);


int main() {
    int in1, in2;
    int min = MAX, total = 0;
    cin >> in1 >> in2; //변수 초기화 및 입력

    for(int i = in1; i <= in2 ; i++) {
        if( (i > 1) && (i % 2 || i == 2)) { //2이거나 홀수면 소수인지 확인, 1제외함
            int temp = is_prime(i); //소수 확인
            total = total + temp;
            if(temp && min > temp) {
                min = temp;
            }
        }
    }
    if(min == MAX) {//소수 없는 경우
        cout << -1;
    }
    else {
        cout << total << endl << min;
    }


    return 0;
}

int is_prime(int num) {
    if(num == 2 || num == 3) { //2,3일 경우
        return num;
    }
    int rt_num = sqrt(num);
    for(int i = 2 ; i <= rt_num ; i++) {//for문 돌면서 소수인지 검사
        if(!(num % i)) {
            return 0;
        }
    }
    return num;
}