#include<iostream>
#include<unordered_set>

using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    unordered_set<int> nums;
    for(int i = 0; i< n; i++) {
        int temp;
        cin >> temp;
        nums.insert(temp);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        if(nums.find(temp) == nums.end()) {
            cout << 0;
        }
        else {
            cout << 1;
        }
        cout << '\n';
    }
    return 0;
}