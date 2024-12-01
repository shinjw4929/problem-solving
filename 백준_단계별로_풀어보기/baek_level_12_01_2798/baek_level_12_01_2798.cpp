#include <iostream>

using namespace std;

int main() {
    int n, m; //input
    int approx = 0, temp = 0;
    cin >> n >> m;
    int *arr = new int[n];//input
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    for(int i = 0 ; i < n - 2 ; i++) {
        for(int j = i + 1 ; j < n - 1 ; j++) {
            for(int k = j + 1 ; k < n ; k++) {
                temp = arr[i] + arr[j] + arr[k];
                if(temp <= m && temp >= approx) {
                    approx = temp;
                }
            }
        }
    }
    cout << approx;

    delete arr;
    return 0;
}
