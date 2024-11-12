#include <iostream>

using namespace std ;

int main() {
    int p_num = 0;
    int *w_num, *h_num;
    int arr[100][100] = {0};

    cin >> p_num;
    w_num = new int[p_num];
    h_num = new int[p_num];

    for(int i = 0 ; i < p_num ; i++) {
        cin >> w_num[i] >> h_num[i];
        for(int r = 0 ; r < 10 ; r++) {
            for(int c = 0 ; c < 10 ; c++) {
                arr[h_num[i] + r][w_num[i] + c] = 1;
            }
        }
    }

    int tot = 0;
    for(int r = 0 ; r < 100 ; r++) {
        for(int c = 0 ; c < 100 ; c++) {
            tot = arr[r][c] + tot;
        }
    }
    cout << tot;

}
