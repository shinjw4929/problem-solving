#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>;
using namespace std;

int n;
int maxLength = 0;
map<string, int> strMap;
map<string, vector<string>> headMap;
string s, t;

void getInput();
void findMaxHead();
void findST();

int main() {
    getInput();
    findMaxHead();
    findST();
    cout << s << '\n' << t;
    return 0;
}

void getInput() {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        string temp;
        cin >> temp;
        strMap[temp] = i;
    }
}

void findMaxHead() {
    string cur = strMap.begin()->first;
    string next;
    for(auto &iter : strMap) {
        int length = 0;
        string head = "";
        next = iter.first;
        if(cur == next) {
            continue;
        }

        for(int i = 0; i < min(cur.size(), next.size()); i++) {
            if(cur[i] == next[i]) {
                length++;
                head = head + cur[i];
            }
            else {
                break;
            }
        }

        if(length > maxLength) {
            headMap.erase(headMap.begin(), headMap.end());
            maxLength = length;
            headMap[head].push_back(cur);
            headMap[head].push_back(next);
        }
        else if(length == maxLength && maxLength != 0) {
            headMap[head].push_back(cur);
            headMap[head].push_back(next);
        }
        cur = next;
    }
}

void findST() {
    int minIdx = n;
    string minHead;
    for(auto &iter : headMap) {
        for(int i = 0 ; i < iter.second.size() ; i++) {
            string cur = iter.second[i];
            string curHead = iter.first;
            if(minIdx > strMap[cur]) {
                minIdx = strMap[cur];
                s = cur;
                minHead = curHead;
            }
        }
    }
    int second = n;
    for(int i = 0 ; i < headMap[minHead].size() ; i++) {
        string cur = headMap[minHead][i];
        if(strMap[cur] == minIdx) {
            continue;
        }
        else {
            if(second > strMap[cur]) {
                second = strMap[cur];
                t = cur;
            }
        }
    }
}
