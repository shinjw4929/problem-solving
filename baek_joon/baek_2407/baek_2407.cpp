#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> pascal;
string comb(int a, int b);
string strSum(string a, string b);

int main() {
    int n, m;
    cin >> n >> m;
    pascal.resize(n + 1, vector<string>(n + 1));
    cout << comb(n, m);
    return 0;
}


string comb(int a, int b) {
    if(pascal[a][b] == "") {
        if(a == b || b == 0) {
            pascal[a][b] = '1';
        }
        else {
            pascal[a][b] = strSum(comb(a-1, b-1), comb(a-1, b));
        }
    }

    return pascal[a][b];
}

string strSum(string a, string b) {
    int sumSize = max(a.size(), b.size()) + 1;
    string sum(sumSize, '0');
    int carry = 0;
    for(int i = 0 ; i < sumSize ; i++) {
        int digitA = (i < a.size()) ? a[a.size() - 1 - i] - '0' : 0;
        int digitB = (i < b.size()) ? b[b.size() - 1 - i] - '0' : 0;
        int localSum = digitA + digitB + carry;
        sum[sumSize - 1 - i] = localSum % 10 + '0';
        carry = localSum / 10;
    }
    if(sum[0] == '0') {
        sum.erase(sum.begin(), sum.begin() + 1);
    }
    return sum;
}
