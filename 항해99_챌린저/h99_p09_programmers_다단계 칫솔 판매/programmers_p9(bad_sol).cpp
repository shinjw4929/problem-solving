#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount);
void update_map(unordered_map<string, int> &name2idx, int &size, vector<string> &enroll);
void mkTree(vector<int> &tree, unordered_map<string, int> &name2idx, int &size, vector<string> &referral, bool isRev);

int main() {
    vector<string> enroll ={"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
    vector<string> referral ={"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
    vector<string> seller ={"young", "john", "tod", "emily", "mary"};
    vector<int> amount = {12, 4, 2, 5, 10};
    vector<int> ans = solution(enroll, referral, seller, amount);
    for(int i = 0 ; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string, int> name2idx;
    int numOfNames = enroll.size();
    int numOfSeller = seller.size();
    update_map(name2idx, numOfNames, enroll);
    vector<int> tree(numOfNames);
    mkTree(tree, name2idx, numOfNames,referral,false);
    vector<int> answer(numOfNames, 0);

    for(int i = 0 ; i < numOfSeller ; i++) {
        int currentIdx = name2idx[seller[i]];
        int currentMoney = amount[i] * 100;
        while(currentMoney > 0 && currentIdx != -1) {
            int send = currentMoney / 10;
            int remain = currentMoney - send;
            answer[currentIdx] = answer[currentIdx] + remain;
            currentMoney = send;
            currentIdx = tree[currentIdx];
        }
    }
    return answer;
}

void update_map(unordered_map<string, int> &name2idx, int &size, vector<string> &enroll) {
    for(int i = 0 ; i < size ; i++) {
        name2idx[enroll[i]] = i;
    }
}

void mkTree(vector<int>& tree, unordered_map<string, int> &name2idx, int &size, vector<string> &referral, bool isRev) {
    for(int i = 0 ; i < size ; i++) {
        string parent = referral[i];
        if(parent == "-") {
            tree[i] = -1;
        }
        else {
            tree[i] = name2idx[parent];
        }
    }
}
