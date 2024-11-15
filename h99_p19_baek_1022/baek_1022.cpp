#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int r1, c1, r2, c2;
vector<vector<int>> mtx;
int mtxR = 0;
int mtxC = 0;
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
int u = 0;
int d = 0;
int l = 0;
int r = 0;
int dir = 3;
int radius = 0;


void getInput();
void mkMtx();
void updateDir(int r, int c);
bool valid(int r, int c);
void printMtx();

int main() {
    getInput();
    mkMtx();
    printMtx();
    return 0;
}

void getInput() {
    cin >> r1 >> c1 >> r2 >> c2;
    mtxR = abs(r2 - r1) + 1;
    mtxC = abs(c2 - c1) + 1;
    mtx.resize(mtxR, vector<int>(mtxC, 0));
}

void mkMtx() {
    int cNum = 1;
    int cR = -r1;
    int cC = -c1;

    while(!mtx[0][0] || !mtx[0][mtxC - 1] || !mtx[mtxR - 1][0] || !mtx[mtxR - 1][mtxC - 1]) {
        if(valid(cR, cC)) {
            mtx[cR][cC] = cNum;
        }
        cNum++;
        int nextR = cR + dr[dir];
        int nextC = cC + dc[dir];
        updateDir(nextR, nextC);
        cR = nextR;
        cC = nextC;
    }

}

void updateDir(int r, int c) {
    if(radius < c + c1) {
        radius++;
        u = 0;
        d = 0;
        l = 0;
        r = 0;
        dir = 0;
        u++;
        return;
    }
    if(u < 2 * radius - 1) {
        u++;
        dir = 0;
    }
    else if(l < 2 * radius) {
        l++;
        dir = 2;
    }
    else if(d < 2 * radius) {
        d++;
        dir = 1;
    }
    else {
        r++;
        dir = 3;
    }

}

bool valid(int r, int c) {
    return (r >= 0 && c >= 0 && r < mtxR && c < mtxC);
}

void printMtx() {
    int maxN = max(mtx[0][0], mtx[0][mtxC - 1]);
    maxN = max(maxN, mtx[mtxR -1][0]);
    maxN = max(maxN, mtx[mtxR -1][mtxC - 1]);
    int cnt = 0;
    while(maxN != 0) {
        maxN = maxN / 10;
        cnt++;
    }

    for(int i = 0 ; i < mtxR ; i ++) {
        for(int j = 0; j < mtxC ; j++) {
            cout << setw(cnt) << mtx[i][j] << ' ';
        }
        cout << '\n';
    }
}
