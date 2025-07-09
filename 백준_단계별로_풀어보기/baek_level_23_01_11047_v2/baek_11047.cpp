//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <vector>

using namespace std;

int N = 10;
int K = 100000000;
vector<int> coins;

void get_input();
void calculate();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate();
    return 0;
}


void get_input() {
    cin >> N >> K;
    for (int i = 0 ; i < N ; i++) {
        int temp;
        cin >> temp;
        if (temp <= K) {
            coins.push_back(temp);
        }
    }
    N = coins.size();
}

void calculate() {
    int sol = 0;
    for (int i = 0 ; i < N ; i++) {
        int cur_coin = coins[N - 1 - i];
        int temp = K / cur_coin;
        K -= temp * cur_coin;
        sol += temp;
    }
    cout << sol;
}