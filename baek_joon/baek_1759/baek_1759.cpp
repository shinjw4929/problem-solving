#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int L = 15, C = 15;

vector<char> arr;
vector<bool> visited;
vector<char> solution;
unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
int vowelCnt = 0;
int consonantCnt = 0;

void getInput();
void solve(int depth, int idx);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getInput();
    solve(L, 0);
    return 0;
}

void getInput() {
    cin >> L >> C;
    arr.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    visited.assign(C, false);
}

void solve(int depth, int idx) {
    if (depth == 0) {
        if (solution.size() == L && vowelCnt > 0 && consonantCnt > 1) {
            for (auto & iter: solution) {
                cout << iter;
            }
            cout << '\n';
        }
    }
    else {
        for (int i = idx ; i < arr.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (vowel.count(arr[i])) {
                    vowelCnt ++;
                }
                else {
                    consonantCnt ++;
                }
                solution.push_back(arr[i]);
                solve(depth - 1, i + 1);
                solution.pop_back();
                if (vowel.count(arr[i])) {
                    vowelCnt --;
                }
                else {
                    consonantCnt --;
                }
                visited[i] = false;
            }
        }
    }
}