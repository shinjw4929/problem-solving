#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

class Dice{
private:
    int numOfD;
    vector<vector<int>> Darr;
    vector<int> tempSum;
    vector<int> tempCase;
    vector<vector<int>> allOfcase;
    int localSum = 0;
    priority_queue<pair<int, vector<int>>> pq;
    
public:
    void getIput(vector<vector<int>>& dice);
    void choose(int cur, int depth);
    void calAllcase(vector<int> &answer);
    void calOnecase(vector<int> &diceIdx, int depth);
    int findRate(vector<int> &sumOfA, vector<int> &sumOfB);
};

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    Dice sol;
    sol.getIput(dice);
    sol.choose(0, 0);
    sol.calAllcase(answer);
    return answer;
}

void Dice::getIput(vector<vector<int>>& dice){
    Darr = dice;
    numOfD = Darr.size();
}

void Dice::choose(int cur, int depth){
    if(depth == numOfD/2){
        allOfcase.push_back(tempCase);
        for(auto &iter: tempCase){
            cout << iter << ' ';
        }
        return;
    }
    for(int i = cur ; i < numOfD ; i ++){
        tempCase.push_back(i + 1);
        choose(i + 1, depth + 1);
        tempCase.pop_back();
    }
}

void Dice::calAllcase(vector<int> &answer){
    vector<int> poss;
    set<int> origin;
    for(int i = 1 ; i < numOfD + 1 ; i++){
        origin.insert(i);
    }
    for(auto &iter : allOfcase){
        set<int> tempSet = origin;
        vector<int> diceB;
        for(auto& iterA : iter){
            tempSet.erase(iterA);
        }
        for(auto& iterB : tempSet){
            diceB.push_back(iterB);
        }
        calOnecase(iter, 0);
        vector<int> sumOfA = tempSum;
        tempSum.clear();
        calOnecase(diceB, 0);
        vector<int> sumOfB = tempSum;
        tempSum.clear();   
        int win = findRate(sumOfA, sumOfB);
        pq.push({win, iter});
    }
    answer = pq.top().second;
}


void Dice::calOnecase(vector<int> &diceIdx, int depth){
    if(depth == numOfD / 2){
        tempSum.push_back(localSum);
        return;
    }
    int cur = diceIdx[depth] - 1;
    for(int i = 0 ; i < 6 ; i++){
        localSum += Darr[cur][i];
        calOnecase(diceIdx, depth + 1);
        localSum -= Darr[cur][i];
    }
}


int Dice::findRate(vector<int> &sumOfA, vector<int> &sumOfB){
    int wins = 0;
    for(auto & iterA: sumOfA){
        for(auto &iterB : sumOfB){
            if(iterA > iterB){
                wins++;
            }
        }
    }
    return wins;
}
