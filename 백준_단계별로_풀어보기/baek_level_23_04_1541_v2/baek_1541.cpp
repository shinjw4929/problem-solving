//
// Created by sjw49 on 2025-07-09.
//
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

vector<int> nums;
vector<char> ops;

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
    string input;
    cin >> input;
    string temp = "";
    temp += input[0];
    for (int i = 1 ; i < input.size() ; i++) {
        char cur_char = input[i];
        if (cur_char == '-' || cur_char == '+') {
            nums.push_back(stoi(temp));
            temp = "";
            ops.push_back(cur_char);
        }
        else {
            temp += cur_char;
        }
    }
    nums.push_back(stoi(temp));
}

void greedy() {
    int first_minus = -1;
    for (int i = 0 ; i < ops.size() ; i++) {
        if (ops[i] == '-') {
            first_minus = i;
            break;
        }
    }
    if (first_minus == - 1) {
        cout << accumulate(nums.begin(), nums.end(), 0);
        return;
    }
    int plus = accumulate(nums.begin(), nums.begin() + first_minus + 1, 0);
    int minus = accumulate(nums.begin() + 1 + first_minus, nums.end(), 0);
    cout <<  plus - minus;
}
