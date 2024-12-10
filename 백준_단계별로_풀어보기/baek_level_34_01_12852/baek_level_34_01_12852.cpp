#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Mk1 {
    int target;
    int numOfOperation = 0;
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
    vector<int> current;
    void backTrack(int num);
    void print();
public:
    void getInput();
    void calUpdate();
};

int main() {
    Mk1 mk;
    mk.getInput();
    mk.calUpdate();
    return 0;
}

void Mk1::getInput() {
    cin >> target;
    vector<int> temp;
    pq.push({INT_MAX, temp});
}

void Mk1::backTrack(int num) {

    if(num == 1) {
        current.push_back(1);
        if(pq.top().first > numOfOperation) {
            pq.push({numOfOperation, current});
        }
        current.pop_back();
        return;
    }
    if(num > 1) {
        if(pq.top().first <= numOfOperation) {
            return;
        }
    }

    if(num % 3 == 0) {
        numOfOperation++;
        current.push_back(num);
        backTrack(num / 3);
        numOfOperation--;
        current.pop_back();
    }
    if(num % 2 == 0) {
        numOfOperation++;
        current.push_back(num);
        backTrack(num / 2);
        numOfOperation--;
        current.pop_back();
    }
    if(num > 1) {
        numOfOperation++;
        current.push_back(num);
        backTrack(num - 1);
        numOfOperation--;
        current.pop_back();
    }
}

void Mk1::calUpdate() {
    backTrack(target);
    print();
}

void Mk1::print() {
    cout << pq.top().first << '\n';
    for(int i = 0 ; i < pq.top().second.size() ; i++) {
        cout << pq.top().second[i] << ' ';
    }
}
