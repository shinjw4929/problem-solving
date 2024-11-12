#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int in_num;
    cin >> in_num;
    unordered_set<string> s;
    for(int i = 0 ; i < in_num ; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        if(temp2 == "enter") {
            s.insert(temp1);
        }
        else if(temp2 == "leave") {
            s.erase(temp1);
        }
    }
    vector<string> name(s.begin(), s.end());
    sort(name.begin(),name.end(), greater<string>());

    for(string&i : name) {
        cout << i << '\n';
    }
    return 0;
}
