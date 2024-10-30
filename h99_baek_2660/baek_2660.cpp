#include <iostream>
#include <vector>

using namespace std;

class boss {
public:
    int numOfMem;
    vector<vector<int>> friendArr;
    vector<pair<int, int>> candid;
    void getInput();
    void updatePoint();
    int findCandi();
    void print(int minPoint);
};


int main() {
    boss findboss;
    findboss.getInput();
    findboss.updatePoint();
    int min_point = findboss.findCandi();
    findboss.print(min_point);

    return 0;
}

void boss::getInput() {
    cin >> numOfMem;
    friendArr.resize(numOfMem + 1, vector<int>(numOfMem + 1));
    int memberNum1 = 0, memberNum2 = 0;
    while(true) {
        cin >> memberNum1 >> memberNum2;
        if(memberNum1 == -1 && memberNum2 == -1) {
            break;
        }
        friendArr[memberNum1][memberNum2] = 1;
        friendArr[memberNum2][memberNum1] = 1;
    }
}

void boss::updatePoint() {
    for(int target = 1 ; target < numOfMem + 1; target++) {
        for(int i = 1 ; i < numOfMem + 1; i++) {
            for(int j = 1 ; j < numOfMem + 1; j++) {
                int origin = friendArr[i][j];
                int bridge1 = friendArr[i][target];
                int bridge2 =friendArr[target][j];

                if(i != j && bridge1 && bridge2) {
                    if(origin) {
                        friendArr[i][j] = min(origin,bridge1 + bridge2);
                    }
                    else{
                        friendArr[i][j] = bridge1 + bridge2;
                    }
                }

            }
        }
    }
}

int boss::findCandi() {
    for(int i = 1 ; i < numOfMem + 1; i++) {
        int max = -1;
        for(int j = 1 ; j < numOfMem + 1; j++) {
            if(friendArr[i][j] > max) {
                max = friendArr[i][j];
            }
        }
        candid.push_back({i , max});
    }
    int minPoint = -1;
    for(int i = 0 ; i < numOfMem; i++) {
        if(minPoint == -1 || minPoint > candid[i].second) {
            minPoint = candid[i].second;
        }
    }
    return minPoint;
}




void boss::print(int minPoint) {
    int numOfCandid = 0;
    for(int i = 0 ; i < numOfMem ; i++) {
        if(candid[i].second == minPoint) {
            numOfCandid++;
        }
    }

    cout << minPoint << ' ' << numOfCandid << '\n';

    for(int i = 0 ; i < numOfMem ; i++) {
        if(candid[i].second == minPoint) {
            cout << candid[i].first << ' ';
        }
    }
}
