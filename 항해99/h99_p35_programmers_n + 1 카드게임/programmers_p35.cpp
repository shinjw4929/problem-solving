#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int validNum;
int remain;
unordered_set<int> onHand;
unordered_set<int> unSelected;
queue<int> toDraw;

int answer = 0;

void getInput(int& coin, vector<int>& cards);
bool updateCards();


int solution(int coin, vector<int> cards) {
    onHand.erase(onHand.begin(), onHand.end());
    unSelected.erase(unSelected.begin(), unSelected.end());
    answer = 0;
    while(!toDraw.empty()) {
        toDraw.pop();
    }
    getInput(coin, cards);
    while(updateCards()) {
    }
    return answer;
}

void getInput(int& coin, vector<int>& cards) {
    remain = coin;
    int numOfCards = cards.size();
    validNum = numOfCards + 1;
    while(!toDraw.empty()) {
        toDraw.pop();
    }
    for(int i = 0 ; i < numOfCards ; i++) {
        if(i < numOfCards/3) {
            onHand.insert(cards[i]);
        }
        else {
            toDraw.push(cards[i]);
        }
    }
}

bool updateCards() {
    bool success = false;
    bool zero = false;
    bool one = false;
    answer ++;
    if(toDraw.empty()) {
       return false;
    }
    for(int i = 0 ; i < 2 ; i++) {
        unSelected.insert(toDraw.front());
        toDraw.pop();
    }
    for(auto & iter : onHand) {
        int toFind = validNum - iter;
        if(onHand.count(toFind)) {
            onHand.erase(iter);
            onHand.erase(toFind);
            success = true;
            zero = true;
            break;
        }
    }
    if(zero == false) {
        for(auto & iter : onHand) {
            int toFind = validNum - iter;
            if(unSelected.count(toFind)) {
                onHand.erase(iter);
                unSelected.erase(toFind);
                if(remain >= 1) {
                    success = true;
                    one = true;
                    remain = remain - 1;
                }
                break;
            }
        }
    }
    if(zero == false && one == false) {
        for(auto & iter : unSelected) {
            int toFind = validNum - iter;
            if(unSelected.count(toFind)) {
                unSelected.erase(iter);
                unSelected.erase(toFind);
                if(remain >= 2) {
                    success = true;
                    remain = remain - 2;
                }
                break;
            }
        }
    }
    return success;
}
