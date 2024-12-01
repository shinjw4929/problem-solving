#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int in1 = 0, in2 = 2;
    int rem = 0;
    string outnum;
    cin >> in1 >> in2;

    while(in1 > 0) {
        rem = in1 % in2;
        in1 = in1 / in2;

        if(rem >= 10) {
            rem = rem + 55;
            outnum += rem;
        }
        else
            outnum += to_string(rem);
    }
    reverse(outnum.begin(), outnum.end());

    cout << outnum;
    return 0;
}
