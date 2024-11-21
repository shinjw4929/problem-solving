#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int limit;

void getInput();
void findMax(int toGo, int depth);
void bubble(int toGo, int idx);

int main() {
    getInput();
    for(int i = 0 ; i < n ; i ++) {
        if(limit > 0) {
            findMax(i, limit);
        }
    }
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << ' ';
    }
}

void getInput() {
    cin >> n;
    arr.resize(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    cin >> limit;
}

void findMax(int toGo, int depth) {
    int maxIdx = toGo;
    int maxVal = arr[toGo];
    for(int i = 0 ; i < min(depth + 1, n - toGo) ;i++) {
        if(maxVal < arr[i + toGo]) {
            maxVal = arr[i+toGo];
            maxIdx = i + toGo;
        }
    }
    limit = limit - (maxIdx - toGo);
    bubble(toGo, maxIdx);
}

void bubble(int toGo, int idx) {
    int lim = idx;
    for(int i = idx ; i > toGo ; i--) {
        int want2swap = arr[i - 1];
        int val = arr[i];
        arr[i] = want2swap;
        arr[i - 1] = val;
    }
}
