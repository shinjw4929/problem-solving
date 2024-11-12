#include <iostream>

using namespace std;

int main() {
    int in1, in2, in3;
    int num_day = 0;
    int temp, left;
    cin >> in1 >> in2 >> in3;
    temp = (in3 - in1) / (in1 -in2);
    left = in3 - temp*(in1-in2);
    if(left <= in1) {
        num_day = temp + 1;
    }
    else {
        while(left > 0) {
            left = left - in1;
            num_day ++;
            if(left > 0) {
                left = left + in2;
            }
        }
        num_day = num_day + temp;
    }


    cout << num_day;


    return 0;
}
