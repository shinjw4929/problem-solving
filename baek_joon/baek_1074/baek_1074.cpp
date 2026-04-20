#include <iostream>
#include <vector>

using namespace std;

int N = 15, r = 32768, c = 32768;
vector<int> arr = {0, 1, 2, 3};

void getInput();
void solve();
int find2Add(int sizeOfSide, int &currentR, int &currentC);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getInput();
    solve();
    return 0;
}

void getInput() {
    cin >> N >> r >> c;
}

void solve() {
    int solution = 0;
    int tempR = r, tempC = c;
    for (int i = N - 1; i >= 0; i--) {
        solution += find2Add(1 << i, tempR, tempC);
    }
    solution += arr[tempR*2 + tempC];
    cout << solution;
}

int find2Add(int unitSize, int &currentR, int &currentC) {
    int weightOfC = currentC / unitSize;
    int weightOfR = currentR / unitSize * 2;
    int weight = weightOfC + weightOfR;

    currentC = currentC % unitSize;
    currentR = currentR % unitSize;

    return weight * (unitSize * unitSize);
}