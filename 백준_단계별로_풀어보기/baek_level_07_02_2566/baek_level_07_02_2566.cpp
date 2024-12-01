#include <iostream>

using namespace std;

int main() {
    int nin_sq[9][9] = {0};
    int max = 0, row = 0, column = 0;

    for(int r = 0 ; r < 9 ; r++) {
        for(int c = 0 ; c < 9; c++) {
            cin >> nin_sq[r][c];
            if(nin_sq[r][c] > max) {
                max = nin_sq[r][c];
                row = r;
                column = c;
            }
        }
    }
    cout << max << endl;
    cout << row + 1 << " " << column + 1;


}
