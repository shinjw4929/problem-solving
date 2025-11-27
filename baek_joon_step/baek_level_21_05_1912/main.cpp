#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int size_of_arr = 100000;
vector<int> num_arr;


void get_input();
void calculate_dp();
int solution = INT_MIN;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_dp();
    cout << solution;
    return 0;
}

void get_input() {
    cin >> size_of_arr;
    num_arr.resize(size_of_arr);
    for (int i = 0 ; i < size_of_arr ; i++) {
        cin >> num_arr[i];
        solution = max(solution, num_arr[i]);
    }
}

void calculate_dp() {
    int min_val = 0;

    for (int i = 1 ; i < size_of_arr ; i++) {
        num_arr[i] += num_arr[i - 1];
    }

    for (int i = 0 ; i < size_of_arr ; i++) {
        if (num_arr[i] - min_val > solution) {
            solution = num_arr[i] - min_val;
        }
        if (min_val > num_arr[i]) {
            min_val = num_arr[i];
        }
    }
}