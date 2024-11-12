#include<iostream>

using namespace std;

void hanoi(int from, int to, int sup, int want2move);
void move(int from, int to);

int main() {
    int height;
    cin >> height;
    if(height == 1) {
        cout << '1' << '\n';
    }
    else {
        cout << (1 << height) - 1 << '\n';
    }
    hanoi(1, 3, 2, height);
    return 0;
}

void hanoi(int from, int to, int sup, int want2move) {
    if(want2move == 1) {
        move(from, to);
    }
    else {
        hanoi(from, sup, to, want2move - 1);
        move(from, to);
        hanoi(sup, to, from, want2move - 1);
    }
}

void move(int from, int to) {
    cout << from << ' ' << to << '\n';
}
