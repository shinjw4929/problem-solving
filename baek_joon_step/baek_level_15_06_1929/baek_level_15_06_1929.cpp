#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    vector<int> arr(num2+1,0);
    for(int i = num1 ; i <= num2 ; i++) {
        arr[i] = i;
    }

    arr[1] = 0;
    for(int i = 2 ; i <= sqrt(num2) ; i++) {
        for(int j = 2 ; i * j <= num2 ; j++) {
            if(arr[i*j]) {
                arr[i*j] = 0;
            }
        }
    }

    for(int i = num1 ; i <= num2 ; i++) {
        if(arr[i]) {
            cout << arr[i] <<'\n';
        }
    }
    return 0;
}
