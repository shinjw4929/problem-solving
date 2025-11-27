#include <iostream>

using namespace std;

int main() {
    //입력
    int input, count, temp;
    cin >> input;
    count = input / 5;
    //5보다 크면 일단 5의 배수만큼 뺌
    temp = input - count * 5;

    for(int i = 0 ; i < input / 3 ; i++) {
        if(!(temp % 3)) {
            count = count + temp / 3;
            temp = 0;
            break;
        }
        else {
            count--;
            temp = temp + 5;
        }
    }

    if(temp) {
        count = -1;
    }
    cout << count;
    return 0;
}
