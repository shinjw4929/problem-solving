#include <iostream>

using namespace std;

int main() {
    //1 + 6 + 12 + 18 + 24 + ...
    int input, temp, shell = 1;
    cin >> input;
    //어느 껍질인지 찾음
    //1로부터 6개 방향 직선 그어서 껍질과 만나는 수와 비교 후 최소 정함
    temp = input - shell;

    while(temp > 0) {
        temp = temp - shell * 6;
        shell ++;
    }
    cout << shell;

    return 0;
}
