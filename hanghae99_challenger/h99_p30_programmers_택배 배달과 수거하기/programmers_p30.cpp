#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long answer = 0;
int cap;
int numOfHouse;
int lastDeliv = numOfHouse - 1;
int lastPick = numOfHouse - 1;

vector<int> deliveries;
vector<int> pickups;

void delNpick();

void pickStartEnd();

long long solution(int _cap, int _n, vector<int> _deliveries, vector<int> _pickups) {
    cap = _cap;
    numOfHouse = _n;
    deliveries = _deliveries;
    pickups = _pickups;
    for(int i = numOfHouse - 1; i >= 0; i--){
        if(deliveries[i]){
            lastDeliv = i;
            break;
        }
    }
    for(int i = numOfHouse - 1; i >= 0; i--){
        if(pickups[i]){
            lastPick = i;
            break;
        }
    }
    while(lastPick != -1 || lastDeliv != -1){
        delNpick();
    }
    return answer;
}


void delNpick(){
    int remain = cap;
    answer = answer + (max(lastDeliv, lastPick) + 1)*2;
    for(int i = lastDeliv ; i >=0 ; i--){
        if(deliveries[i] <= remain){
            remain = remain - deliveries[i];
            deliveries[i] = 0;
            if(i == 0) {
                lastDeliv = -1;
            }
        }
        else if(deliveries[i] > remain){
            deliveries[i] = deliveries[i] - remain;
            lastDeliv = i;
            break;
        }
    }
    remain = cap;
    for(int i = lastPick ; i >=0 ; i--){
        if(pickups[i] <= remain){
            remain = remain - pickups[i];
            pickups[i] = 0;
            if(i == 0) {
                lastPick = -1;
            }
        }
        else if(pickups[i] > remain){
            pickups[i] = pickups[i] - remain;
            lastPick = i;
            break;
        }
    }

}
