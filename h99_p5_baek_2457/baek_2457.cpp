#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class flower {
private:
    int numF;
    vector<pair<int, int>> flowerArr;

public:
    int resultF = 0;
    bool valid = false;
    void getInput();
    void greedy();
};

bool compare(const pair<int, int>& f1, const pair<int, int>& f2) {
    if (f1.first == f2.first) {
        return f1.second > f2.second;
    }
    return (f1.first < f2.first);
}

int main() {
    flower problem;
    problem.getInput();
    problem.greedy();
    if(problem.valid) {
        cout << problem.resultF;
    }
    else {
        cout << 0;
    }
    return 0;
}

void flower::getInput() {
    cin >> numF;
    flowerArr.resize(numF);
    for(int i = 0 ; i < numF ; i++) {
        int openM, openD;
        int closeM, closeD;
        cin >> openM >> openD >> closeM >> closeD;
        int start = openM * 100 + openD;
        int end = closeM * 100 + closeD;
        flowerArr[i] = {start , end};
    }
}
void flower::greedy() {
    sort(flowerArr.begin(), flowerArr.end(),compare);

    int start = 301;
    int end = 1201;
    int maxEnd = 0;
    int index = 0;

    while (start < end) {
        bool found = false;
        // start 이전 꽃들 중 가장 늦게 지는 꽃 찾기
        while (index < numF && flowerArr[index].first <= start) {
            maxEnd = max(maxEnd, flowerArr[index].second);
            found = true;
            index++;
        }

        if (!found) {
            valid = false;
            resultF = 0;
            return;
        }

        resultF++;
        start = maxEnd;

        if (start >= end) {
            valid = true;
            return;
        }
    }
    valid = false;
}
