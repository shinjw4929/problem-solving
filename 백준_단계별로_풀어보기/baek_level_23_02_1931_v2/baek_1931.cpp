//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> arr;

bool my_sort(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) {
        return true;
    }
    else if (a.second == b.second && a.first < b.first) {
        return true;
    }
    return false;
}

void get_input();
void greedy();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    greedy();
    return 0;
}

void get_input() {
    cin >> N;
    arr.resize(N);
    for (auto& [start, end] : arr) {
        cin >> start >> end;
    }
    sort(arr.begin(), arr.end(), my_sort);
}

void greedy() {
    int sol = 1;
    int prev = arr[0].second;
    for (int i = 1 ; i < N ; i++) {
        int cur_start = arr[i].first;
        int cur_end = arr[i].second;
        if (cur_start >= prev) {
            sol++;
            prev = cur_end;
        }
    }
    cout << sol;
}