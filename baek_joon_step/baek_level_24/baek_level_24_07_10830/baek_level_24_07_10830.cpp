#include <iostream>
#include <vector>

using namespace std;

int n;
long long b;
vector<vector<long long>> mtx;
vector<vector<long long>> tempmtx;
vector<vector<long long>> result;
bool first = true;

void sq();

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> b;
    mtx.resize(n, vector<long long>(n));
    tempmtx.resize(n, vector<long long>(n));
    result.resize(n, vector<long long>(n));
    for(int i = 0 ; i < n; i++) {
        for(int j = 0 ; j < n ; j++) {
            long long temp;
            cin >> temp;
            mtx[i][j] = temp % 1000;
        }
    }

    while(b > 0) {
        sq();
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

void sq() {
    if(b % 2 == 1 && !first) {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0; j < n; j++) {
                long long acc = 0;
                for(int k = 0; k < n; k++) {
                    acc = acc + (result[i][k] * mtx[k][j]) % 1000;
                }
                tempmtx[i][j] = acc % 1000;
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0; j < n; j++) {
                result[i][j] = tempmtx[i][j];
            }
        }
    }
    else if(b % 2 == 1 && first) {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0; j < n; j++) {
                result[i][j] = mtx[i][j];
            }
        }
        first = false;
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            long long acc = 0;
            for(int k = 0; k < n; k++) {
                acc = acc + (mtx[i][k] * mtx[k][j]) % 1000;
            }
            tempmtx[i][j] = acc % 1000;
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            mtx[i][j] = tempmtx[i][j];
        }
    }

    b = b/2;
}