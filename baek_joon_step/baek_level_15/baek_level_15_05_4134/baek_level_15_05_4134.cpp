#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long int nxt_prime(long long int n);

int main() {
    int test_num;
    cin >> test_num;
    vector<long long int> test(test_num);

    for(int i = 0 ; i < test_num ; i++) {
        cin >> test[i];//입력
        cout << nxt_prime(test[i]) << '\n';//함수에 넣고 출력
    }
    return 0;
}


long long int nxt_prime(long long int n) {
    if(n==0 || n==1 || n==2) {
        return 2;
    }
    if(n % 2 == 0) {
        n++;
    }
    int check = 1;
    while(check) {
        for(int i = 2 ; i <= sqrt(n) ; i++) {
            if(!(n%i)) {
                n = n + 2;
                check = 2;
                i = 2;
                break;
            }
        }
        if(check == 2) {
            check = 1;
        }
        else if(check == 1) {
            check = 0;
        }
    }
    return n;
}