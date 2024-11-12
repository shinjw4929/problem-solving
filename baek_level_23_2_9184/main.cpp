#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int fun_w(int a, int b, int c);
unordered_map<int, int> dp;
int three2one(int a, int b, int c);

int main() {
    int a = 0, b = 0, c = 0;
    while(a != -1 || b != -1 || c != -1) {
        cin >> a >> b >> c;
        if(a != -1 || b != -1 || c != -1) {
            cout << "w(" << a << ", " << b <<  ", " << c << ") = "
            << fun_w(a,b,c) << '\n';
        }
    }
    return 0;
}

int fun_w(int a, int b, int c) {
    int mapped = three2one(a, b, c);
    int ret;
    if(dp.find(mapped) != dp.end()) {
        ret = dp[mapped];
    }
    else if(mapped == 0) {
        dp[0] = 1;
        ret = 1;
    }
    else if(mapped == 202020) {
        dp[mapped] = fun_w(20,20,20);
        ret = dp[mapped];
    }
    else if(mapped == -1) {
        dp[mapped] = fun_w(19, 20, 20) + fun_w(19, 19, 20) + fun_w(19, 20, 19) - fun_w(19, 19, 19);
        ret = dp[mapped];
    }
    else if(a < b && b < c) {
        dp[mapped] = fun_w(a, b, c-1) + fun_w(a, b-1, c-1) - fun_w(a, b-1, c);
        ret = dp[mapped];
    }
    else {
        dp[mapped] = fun_w(a-1, b, c) + fun_w(a-1, b-1, c) + fun_w(a-1, b, c-1) - fun_w(a-1, b-1, c-1);
        ret = dp[mapped];
    }
    return ret;
}

int three2one(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        return 0;
    }
    else if(a > 20 || b > 20 || c > 20){
        return 202020;
    }
    else if(a == 20 && b == 20 && c == 20) {
        return -1;
    }
    else {
        return a*10000 + b*100 + c;
    }
}