#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;


int numOfHuman = 20;
int ans =INT_MAX;
vector<vector<int>> point_mtx;
vector<int> team1;
vector<int> team2;

void get_intput();

void dfs_combination(int idx, int cnt);

void find_team2();
void cal_diff();

int main() {
    get_intput();
    dfs_combination(0, 0);
    cout << ans;
    return 0;
}

void get_intput() {
    cin >> numOfHuman;
    point_mtx.resize(numOfHuman, vector<int>(numOfHuman));
    for (int i = 0 ; i < numOfHuman ; i++) {
        for (int j = 0 ; j < numOfHuman ; j++) {
            cin >> point_mtx[i][j];
        }
    }
    team1.resize(numOfHuman/2);
}

void dfs_combination(int idx, int cnt) {
    if (cnt == numOfHuman/2) {
        find_team2();
        cal_diff();
    }
    else {
        for (int i = idx ; i < numOfHuman ; i++) {
            team1[cnt] = i;
            dfs_combination(i + 1, cnt + 1);
        }
    }
}

void find_team2() {
    set<int> temp;
    for (int i = 0 ; i < numOfHuman; i ++) {
        temp.insert(i);
    }
    for (auto&iter : team1) {
        if (temp.count(iter)) {
            temp.erase(iter);
        }
    }
    team2.erase(team2.begin(), team2.end());
    for (auto&iter : temp) {
        team2.push_back(iter);
    }
}

void cal_diff() {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < team1.size() ; i++) {
        for (int j = 0 ; j < team1.size() ; j++) {
            sum1 += point_mtx[team1[i]][team1[j]];
        }
    }
    for (int i = 0; i < team2.size() ; i++) {
        for (int j = 0 ; j < team2.size() ; j++) {
            sum2 += point_mtx[team2[i]][team2[j]];
        }
    }
    ans = min(ans, abs(sum1 - sum2));
}