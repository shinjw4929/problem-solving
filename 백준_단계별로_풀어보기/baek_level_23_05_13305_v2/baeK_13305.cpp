//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <vector>


using namespace std;

int N = 100000;
vector<long long> load_arr;
vector<long long> cost_arr;

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
    load_arr.resize(N - 1);
    cost_arr.resize(N);
    for (auto & iter : load_arr) {
        cin >> iter;
    }
    for (auto &iter : cost_arr) {
        cin >> iter;
    }
}

void greedy() {
    long long prev = cost_arr[0];
    for (int i = 1 ; i < N ; i++) {
        if (prev < cost_arr[i]) {
            cost_arr[i] = prev;
        }
        else {
            prev = cost_arr[i];
        }
    }
    long long cost_sum = 0;
    for (int i = 0 ; i < N - 1; i++) {
        cost_sum += cost_arr[i]*load_arr[i];
    }
    cout << cost_sum;
}