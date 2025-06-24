#include <iostream>
#include <vector>

using namespace std;

int num_of_house;
vector<vector<int>> cost_arr;

void get_input();
void calculate_cost();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    get_input();
    calculate_cost();
    cout << min(min(cost_arr[num_of_house - 1][0],cost_arr[num_of_house - 1][1]),cost_arr[num_of_house - 1][2]);
    return 0;
}

void get_input() {
    cin >> num_of_house;
    cost_arr.resize(num_of_house);
    for (int i = 0 ; i < num_of_house ; i++) {
        int cost1, cost2, cost3;
        cin >> cost1 >> cost2 >> cost3;
        cost_arr[i].push_back(cost1);
        cost_arr[i].push_back(cost2);
        cost_arr[i].push_back(cost3);
    }
}

void calculate_cost() {
    for (int i = 1 ; i < num_of_house ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cost_arr[i][j] = min(cost_arr[i][j] + cost_arr[i-1][(j + 1) % 3], cost_arr[i][j] + cost_arr[i-1][(j + 2) % 3]);
        }
    }
}