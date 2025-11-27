#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numOfOp;
int bitmask = 0;

void getInput();
void parseOp(string& op, int &num);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getInput();
    return 0;
}

void getInput() {
    cin >> numOfOp;
    for(int i = 0 ; i < numOfOp ; i ++) {
        int num;
        string operation;
        cin >> operation;
        if(operation != "all" && operation != "empty") {
            cin >> num;
        }

        parseOp(operation, num);
    }
}

void parseOp(string& op, int &num) {
    if(op == "add") {
        bitmask |= 1 << num;
    }
    else if(op == "remove") {
        bitmask &= ~(1 << num);
    }
    else if(op == "check") {
        if(bitmask & (1 << num)) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    else if(op == "toggle") {
        bitmask ^= 1 << num;
    }
    else if(op == "all") {
        bitmask = (1 << 21) - 1;
    }
    else if(op == "empty") {
        bitmask = 0;
    }
}