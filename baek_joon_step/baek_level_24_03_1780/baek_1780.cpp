#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N = pow(3, 7);
vector<int> num_of_paper(3, 0);
vector<vector<int>> mtx;

void get_input();
void divide_mtx(int lr, int lc, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    divide_mtx(0, 0, N);
    for (auto& iter: num_of_paper) {
        cout << iter << '\n';
    }
    return 0;
}

void get_input() {
    cin >> N;
    mtx.resize(N, vector<int>(N, 0));
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N  ; j++) {
            int temp;
            cin >> temp;
            temp++;
            mtx[i][j] = temp;
        }
    }
}

void divide_mtx(int lr, int lc, int size) {
    if (size == 1) {
        num_of_paper[mtx[lr][lc]]++;
    }
    else {
        bool all_same = true;
        int prev = mtx[lr][lc];
        for (int i = lr ; i < lr + size ; i++) {
            for (int j = lc ; j < lc + size ; j++) {
                if (mtx[i][j] != prev) {
                    all_same = false;
                    break;
                }
                prev = mtx[i][j];
            }
        }
        if (all_same) {
            num_of_paper[mtx[lr][lc]]++;
        }
        else {
            for (int i = 0 ; i < 3 ; i++) {
                for (int j = 0 ; j < 3 ; j++) {
                    divide_mtx(lr + (i * size/3), lc + (j * size/3), size/3);
                }
            }
        }
    }
}