#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> kanarr(vector<int> kan);
int max_kan_num(vector<int> kan);
void printkan(vector<int> kan);

int main() {
    int kanN;
    vector<int> input_arr;
    int temp;
    while (cin >> temp) {
        input_arr.push_back(temp);
    }
    for(int i = 0 ; i < input_arr.size(); i++) {
        kanN = pow(3, input_arr[i]);
        vector<int> kan(kanN, 1);
        kan = kanarr(kan);
        printkan(kan);
        cout << '\n';
    }
    return 0;
}


vector<int> kanarr(vector<int> kan) {
    int size = max_kan_num(kan);
    int target = size/3;
    int cnt = 0;
    if(size != 1) {
        for(int i = 0 ; i < kan.size(); i++) {
            if(kan[i] && cnt < target) {
                cnt ++;
            }
            else if(kan[i] && cnt >= target && cnt <target * 2) {
                kan[i] = 0;
                cnt ++;
            }
            else {
                cnt = 0;
            }
        }
        kan = kanarr(kan);
        return kan;
    }
    else {
        return kan;
    }

}

int max_kan_num(vector<int> kan) {
    int cnt = 0;
    for(int i = 0 ; i < kan.size() ; i++) {
        if(kan[i]) {
            cnt++;
        }
        else {
            break;
        }
    }
    return cnt;
}
void printkan(vector<int> kan) {
    for(int i = 0; i < kan.size(); i++) {
        if(kan[i]) {
            cout << '-';
        }
        else {
            cout << ' ';
        }
    }
}