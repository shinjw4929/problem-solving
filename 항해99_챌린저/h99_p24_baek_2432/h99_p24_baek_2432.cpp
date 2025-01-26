#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Weight {
private:
    int numOfV;
    vector<int> wArr;
public:
    void getInput();
    void findImposs();
};

int main() {
    Weight sol;
    sol.getInput();
    sol.findImposs();
}

void Weight::getInput() {
    cin >> numOfV;
    wArr.resize(numOfV);
    for(int i = 0 ; i < numOfV ; i++) {
        cin >> wArr[i];
    }
    sort(wArr.begin(), wArr.end());
}

void Weight::findImposs() {
    if(wArr[0] != 1) {
        cout << 1;
        return;
    }
    int rangeMax = 1;
    for(int i = 1 ; i < numOfV ; i++) {
        if(wArr[i] > rangeMax + 1) {
            cout << rangeMax + 1;
            return;
        }
        else {
            rangeMax = rangeMax + wArr[i];
        }
    }
    cout << rangeMax + 1;
}
