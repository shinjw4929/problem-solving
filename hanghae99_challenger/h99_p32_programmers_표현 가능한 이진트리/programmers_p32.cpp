#include <string>
#include <vector>
#include <iostream>

using namespace std;

string mkBitStr(long long num);
void mkStrTree(string& bitStr);
bool isPoss(string& bitStr, char head, int start, int end);

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto & iter : numbers){
        string curStr = mkBitStr(iter);
        mkStrTree(curStr);
        bool localAns = isPoss(curStr, curStr[curStr.size()/2], 0, curStr.size()-1);
        answer.push_back(localAns);
    }
    
    return answer;
}

string mkBitStr(long long num){
    string bitStr;
    if(num == 0){
        bitStr = {'0'};
    }
    while(num > 0){
        int remain = num % 2;
        bitStr = bitStr + to_string(remain);
        num = num / 2;
    }
    return bitStr;
}

void mkStrTree(string& bitStr){
    int strSize = bitStr.size();
    int treeSize = 1;
    int idx = 1;
    while(treeSize < bitStr.size()){
        treeSize = treeSize + (1 << idx);
        idx++;
    }
    
    for(int i = strSize; i < treeSize; i++){
        bitStr = bitStr + '0';
    }
}

bool isPoss(string& bitStr, char head, int start, int end){
    int curSize = end - start + 1;
    int mid = (start + end) / 2;
    char curRoot = bitStr[mid];
    if(head < curRoot){
        return false;
    }
    if(curRoot == '0' && curSize > 1){
        if(bitStr[mid - 1] == '1' || bitStr[mid + 1] == '1'){
            return false;
        }
    }
    if(curSize == 1){
        return true;
    }
    else if(curSize >= 3 && mid > 0){
        return (isPoss(bitStr, curRoot, start, mid - 1) && isPoss(bitStr, curRoot, mid + 1, end));
    }
}

