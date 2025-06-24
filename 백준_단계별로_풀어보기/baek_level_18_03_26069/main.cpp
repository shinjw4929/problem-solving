#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int numOfHuman = 0;
unordered_set<string> isDancing;

void getInput();

int main() {
    getInput();
    cout  << isDancing.size();
    return 0;
}

void getInput() {
    cin >> numOfHuman;
    for (int i = 0 ; i < numOfHuman ; i++) {
        string name1, name2;
        cin >> name1 >> name2;
        if (name1 == "ChongChong" || name2 == "ChongChong") {
            isDancing.insert(name1);
            isDancing.insert(name2);
        }
        else if (isDancing.count(name1) || isDancing.count(name2)) {
            isDancing.insert(name1);
            isDancing.insert(name2);
        }
    }
}