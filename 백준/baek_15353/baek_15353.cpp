#include <iostream>
#include <string>

using namespace std;



int main() {
    string numA;
    string numB;
    cin >> numA >> numB;

    int sumSize = max(numA.size(), numB.size()) + 1;

    string result(sumSize,'0');
    int carry = 0;

    for(int i = 0 ; i < sumSize ; i++) {
        int digitA = (i < numA.size()) ? numA[numA.size() - 1 - i] -'0' : 0;
        int digitB = (i < numB.size()) ? numB[numB.size() - 1 - i] -'0' : 0;
        int localSum = digitA + digitB + carry;
        result[sumSize - 1 - i] = localSum % 10 + '0';
        carry = localSum / 10;
    }
    if(result.front() == '0') {
        result.erase(result.begin(), result.begin() + 1);
    }
    cout << result;


    return 0;
}
