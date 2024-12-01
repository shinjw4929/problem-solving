#include <iostream>

using namespace std;

int main() {
    int in1, in2; // input #2
    int quo1, quo2;

    cin >> in1 >> in2;
    while(in1 != 0 && in2 != 0) {
        quo1 = in1 / in2; //앞에꺼 뒤로 나눔
        quo2 = in2 / in1; //뒤에꺼 앞으로 나눔

        if(in2 * quo1 == in1) { //몫으로 곱해서 원래거랑 같으면 출력
            cout << "multiple" << endl;
        }
        else if(in1 * quo2 == in2) {
            cout << "factor" << endl;
        }
        else {//둘다 아닌경우
            cout << "neither" << endl;
        }



        cin >> in1 >> in2;
    }

    return 0;
}
