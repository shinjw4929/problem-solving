#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n, ent_count = 0, gom_count = 0;
    unordered_map<string, int> map;

    cin >> n;
    for(int i = 0; i < n ; i++) {
        string temp;
        cin >> temp;
        if(temp == "ENTER") {
            ent_count ++;
        }
        else {
            if(map.count(temp) && ent_count == map.at(temp)) {
            }
            else {
                map[temp] = ent_count;
                gom_count = gom_count+ 1;
            }
        }
    }
    cout << gom_count;

    return 0;
}
