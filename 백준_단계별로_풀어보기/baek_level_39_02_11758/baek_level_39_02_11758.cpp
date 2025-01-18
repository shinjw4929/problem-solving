#include <iostream>

using namespace std;

pair<int, int> p1;
pair<int, int> p2;
pair<int, int> p3;


void getInput();
void calDir();

int main() {
    getInput();
    calDir();
    return 0;
}

void getInput() {
    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;
}

void calDir() {
    int Ux = p2.first - p1.first;
    int Uy = p2.second - p1.second;
    int Vx = p3.first - p2.first;
    int Vy = p3.second - p2.second;
    int det = Ux * Vy - Uy * Vx;
    if(det > 0) {
        cout << 1;
    }
    else if(det < 0) {
        cout << -1;
    }
    else {
        cout << 0;
    }
}
