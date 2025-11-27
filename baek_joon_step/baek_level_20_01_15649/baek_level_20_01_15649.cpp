#include <iostream>
#include <vector>

using namespace std;

void select(vector<int> arr, vector<int>before, int sel);
void printarr(vector<int> arr);

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> n(N);
    vector<int> b;
    for(int i = 0; i < N ; i++) {
        n[i] = i + 1;
    }

    select(n, b, M);
    return 0;
}


void select(vector<int> arr, vector<int>before, int sel) {
    int arrsize = arr.size();
    if(sel == 1) {
        for(int i = 0 ; i < arrsize ; i++) {
            printarr(before);
            cout << arr[i] << '\n';
        }
    }
    else {
        for(int i = 0; i < arrsize; i++) {
            int temp = arr[i];
            before.push_back(temp);
            arr.erase(arr.begin()+i);
            select(arr, before, sel - 1);
            arr.insert(arr.begin()+i, temp);
            before.pop_back();
        }
    }
}

void printarr(vector<int> arr) {
    if(arr.empty()) {

    }
    else {
        for(int i = 0 ; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
    }
}