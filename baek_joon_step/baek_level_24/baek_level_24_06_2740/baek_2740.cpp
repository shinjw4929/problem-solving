#include <iostream>
#include <vector>

using namespace std;

int N = 100, M = 100, K = 100;
vector<vector<int>> mtx_A;
vector<vector<int>> mtx_B;

void get_input();
void mtx_mult();

int main(){
    get_input();
    mtx_mult();
    return 0;
}

void get_input() {
    cin >> N >> M;
    mtx_A.resize(N, vector<int>(M));
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            cin >> mtx_A[i][j];
        }
    }
    cin >> M >> K;
    mtx_B.resize(M, vector<int>(K));
    for (int i = 0 ; i < M ; i++) {
        for (int j = 0 ; j < K ; j++) {
            cin >> mtx_B[i][j];
        }
    }
}

void mtx_mult() {
    for (int i = 0 ; i < N ; i++) {
        vector<int> &R = mtx_A[i];
        for (int k = 0 ; k < K ; k++) {
            int temp = 0;
            for (int j = 0 ; j < M ; j++) {
                temp += R[j] * mtx_B[j][k];
            }
            cout << temp << ' ';
        }
        cout << '\n';
    }
}