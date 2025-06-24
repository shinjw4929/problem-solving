#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int numOfWords;
int limit;
map<string, int> wordFrequency;
vector<string> vocabulary;

void getInput();
bool mySort(string str1, string str2) {
    if (wordFrequency[str1] != wordFrequency[str2]) {
        return wordFrequency[str1] > wordFrequency[str2];
    }
    else if (str1.size() != str2.size()) {
        return str1.size() > str2.size();
    }
    return str1 < str2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getInput();
    sort(vocabulary.begin(), vocabulary.end(), mySort);
    for (auto& iter : vocabulary) {
        cout << iter << '\n';
    }
    return 0;
}

void getInput() {
    cin>> numOfWords >> limit;
    for (int i = 0 ; i < numOfWords ; i++) {
        string str;
        cin >> str;
        if (str.size() >= limit) {
            wordFrequency[str]++;
        }
    }
    for (auto &iter : wordFrequency) {
        vocabulary.push_back(iter.first);
    }
}