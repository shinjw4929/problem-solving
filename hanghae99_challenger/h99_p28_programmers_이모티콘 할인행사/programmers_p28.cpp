#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> users;
vector<int> emoticons;
vector<int> discount;
vector<int> rate = {10, 20, 30, 40};
int numOfUsers;
int numOfEmoticons;
int totSum = 0;
int totSub = 0;


void backTrack(int idx);
void calUsers();


vector<int> solution(vector<vector<int>> _users, vector<int> _emoticons) {
    users = _users;
    emoticons = _emoticons;
    numOfUsers = users.size();
    numOfEmoticons = emoticons.size();
    discount.assign(numOfEmoticons, 0);
    vector<int> answer(2);
    
    
    backTrack(0);
    
    answer[0] = totSub;
    answer[1] = totSum;
    return answer;
}

void backTrack(int idx){
    if(idx == numOfEmoticons){
        calUsers();
    }
    else{
        for(int j = 0; j < 4 ; j++){
            discount[idx] = rate[j];
            backTrack(idx + 1);
        }
    }
}

void calUsers(){
    int localSub = 0;
    int localSum = 0;
    for(int i = 0 ; i < numOfUsers ; i++){
        int targetRate = users[i][0];
        int limitAmount = users[i][1];
        int localAmount = 0;
        for(int j = 0 ; j < numOfEmoticons ; j++){
            if(discount[j] >= targetRate){
                localAmount = localAmount + (emoticons[j] * (100 - discount[j]) / 100);
            }
        }
        if(localAmount >= limitAmount){
            localSub++;
        }
        else{
            localSum = localSum + localAmount;
        }
    }
    if(localSub > totSub){
        totSub = localSub;
        totSum = localSum;
    }
    else if(localSub == totSub && localSum > totSum){
        totSum = localSum;
    }
}

