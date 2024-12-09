#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int k;
int n;
vector<vector<int>> reqs;
vector<vector<pair<int,int>>> typeReq;
vector<int> mentor;
priority_queue<int, vector<int>, greater<int>> endTime;
vector<int> wait;
int totTime = INT_MAX;

void backtrack(int current, int remain);
void mkTypeArr();
void calTime();
int calWaitForIter(int mentors, vector<pair<int, int>> &curReq);


int solution(int _k, int _n, vector<vector<int>> _reqs) {
    k = _k;
    n = _n;
    reqs = _reqs;
    typeReq.resize(k);
    wait.resize(k);
    mkTypeArr();
    for(int i = 0 ; i < k ; i ++) {
        mentor.assign(k, 1);
        backtrack(i, n - k);
    }
    int answer = totTime;
    return answer;
}


void backtrack(int current, int remain) {
    if(remain > 0) {
        mentor[current]++;
    }
    remain--;
    if(remain > 0) {
        for(int i = current ; i < k ; i++) {
            backtrack(i, remain);
            mentor[i]--;
        }
    }
    else {
        calTime();
    }
}


void mkTypeArr() {
    for(auto &iter : reqs) {
        typeReq[iter[2] - 1].push_back({iter[0], iter[1]});
    }
}


void calTime() {
    vector<int> curWait(k , 0);
    for(int i = 0 ; i < k; i++) {
        int curMentor = mentor[i];
        vector<pair<int,int>> &curReq = typeReq[i];
        endTime = priority_queue<int, vector<int>, greater<int>>();
        curWait[i] = calWaitForIter(curMentor, curReq);
    }
    int sum = 0;
    for(int i = 0 ; i < k ; i++) {
        sum = sum + curWait[i];
    }
    totTime = min(sum, totTime);
}

int calWaitForIter(int mentors, vector<pair<int, int>> &curReq) {
    int totWait = 0;
    int curStart;
    int curTerm;
    for(int i = 0 ; i < curReq.size() ; i ++) {
        curStart = curReq[i].first;
        curTerm = curReq[i].second;
        int localWait = 0;
        if(mentors>0) {
            mentors--;
            endTime.push(curStart + curTerm);
        }
        else {
            if(endTime.empty()) {
                endTime.push(curStart + curTerm);
            }
            else {
                if(endTime.top() > curStart) {
                    localWait = endTime.top() - curStart;
                    totWait = totWait + localWait;
                    endTime.push(curTerm + endTime.top());
                    endTime.pop();
                }
                else {
                    endTime.push(curStart + curTerm);
                    endTime.pop();
                }
            }
        }

    }


    return totWait;
}














int main() {
    vector<vector<int>> inputRE = {{5, 55, 2}, {10, 90, 2}, {20, 40, 2}, {50, 45, 2}, {100, 50, 2}};
    //cout << solution(2, 3, inputRE);
    cout << solution(2, 3, inputRE);
    return 0;
}
