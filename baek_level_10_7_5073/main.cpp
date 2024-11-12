#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while(a != 0 && b != 0 && c != 0) {
        if((a >= b + c)||(b >= a + c)||(c >= a + b)) {
            cout << "Invalid" << endl;
        }
        else if(a == b && b ==c) {
            cout << "Equilateral" << endl;
        }
        else if(a == b || b == c || c == a) {
            cout << "Isosceles" << endl;
        }
        else {
            cout << "Scalene " << endl;
        }
        cin >> a >> b >> c;
    }
    return 0;
}
