#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N = 25;
int local_apt = 0;
vector<vector<int>> mtx;
vector<int> dR = {-1, 1, 0, 0};
vector<int> dC = {0, 0, -1, 1};

void get_input();
bool is_valid(int r, int c) {
    return (r >= 0 && c >= 0 && r < N && c < N);
}

void dfs(int curR, int curC);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    int tot_apt = 0;
    vector<int> apt_nums;

    for (int i = 0 ; i < N ;i++) {
        for (int j = 0 ; j < N ; j++) {
            if (mtx[i][j]) {
                local_apt = 0;
                tot_apt++;
                dfs(i, j);
                apt_nums.push_back(local_apt);
            }
        }
    }
    sort(apt_nums.begin(), apt_nums.end());
    cout << tot_apt << '\n';
    for (auto &iter:apt_nums) {
        cout << iter <<'\n';
    }
    return 0;
}

void get_input() {
    cin >> N;
    mtx.resize(N, vector<int>(N,0));
    for (int i = 0 ; i < N ; i++) {
        string temp;
        cin >> temp;
        for (int j = 0 ; j < N; j++) {
            mtx[i][j] = temp[j] - '0';
        }
    }
}

void dfs(int curR, int curC) {
    mtx[curR][curC] = 0;
    local_apt++;
    for (int i = 0 ; i < 4 ; i++) {
        int nextR = curR + dR[i];
        int nextC = curC + dC[i];
        if (is_valid(nextR, nextC) && mtx[nextR][nextC] == 1) {
            dfs(nextR, nextC);
        }
    }
}

