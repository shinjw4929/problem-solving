#include <iostream>
#include <vector>

using namespace std;

void print_3sq(int size);

vector<vector <int>> cal_sq(vector<vector <int>> sq, int thick);

int main() {
    int inputN;
    cin >> inputN;
    print_3sq(inputN);
    return 0;
}

void print_3sq(int size) {
    vector<vector <int>> sq(size, vector<int>(size, 1));
    sq = cal_sq(sq, size/3);
    for(int i = 0; i < size; i++) {
        for(int j = 0 ; j < size ; j++) {
            if(sq[i][j] == 1) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}

vector<vector <int>> cal_sq(vector<vector <int>> sq, int thick) {
    int size = sq.size();
    int i_cnt = 0, j_cnt = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0 ; j < size ; j++) {
            if((j_cnt >= thick && j_cnt < thick * 2) && (i_cnt >= thick && i_cnt < thick * 2)) {
                sq[i][j] = 0;
            }
            j_cnt++;
            if(j_cnt == thick * 3) {
                j_cnt = 0;
            }
        }
        i_cnt++;
        if(i_cnt == thick * 3) {
            i_cnt = 0;
        }
    }
    if(thick == 1) {
        return sq;
    }
    else {
        sq = cal_sq(sq, thick/3);
        return sq;
    }
}