#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long input = 0;
long long MOD = 1000000007;
void mtx_mult(vector<vector<long long>>& result, const vector<vector<long long>>& mtx1, const vector<vector<long long>>& mtx2);
void mtx_pow();
string str_divide(string& target);

int main() {
    cin >> input;
    if (input == 1) {
        cout << 1;
        return 0;
    }
    input--;
    mtx_pow();
    return 0;
}


void mtx_mult(vector<vector<long long>>& result, const vector<vector<long long>>& mtx1, const vector<vector<long long>>& mtx2) {
    vector<vector<long long>> temp_mtx(2, vector<long long>(2, 0));
    for (int i = 0 ; i < mtx1.size() ; i++) {
        for (int j = 0 ; j < mtx2[0].size(); j++) {
            int temp = 0;
            for (int k = 0 ; k < mtx2.size() ; k++) {
                temp += (mtx1[i][k] * mtx2[k][j]) % MOD;
            }
            temp_mtx[i][j] = temp % MOD;
        }
    }
    result = temp_mtx;
}

void mtx_pow() {
    vector<vector<long long>> mtx ={{1, 1},{1, 0}};
    vector<vector<long long>> next_mtx(2, vector<long long>(2));
    vector<vector<long long>> remain_mtx ={{1, 0}, {0, 1}};
    while (input > 1) {
        long long remain = input % 2;
        input /= 2;
        mtx_mult(next_mtx, mtx, mtx);
        if (remain) {
            mtx_mult(remain_mtx, remain_mtx, mtx);
        }
        mtx = next_mtx;
    }
    mtx_mult(remain_mtx,remain_mtx, mtx);
    cout << remain_mtx[0][0];
}