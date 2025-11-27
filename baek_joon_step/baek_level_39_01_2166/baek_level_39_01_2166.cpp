#include <iostream>
#include <vector>

using namespace std;

int numOfV;
vector<pair<int, int>> coordinate;

void getInput();
void calarea();
long long ccw(pair<int, int> a, pair<int, int> b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getInput();
    calarea();

    return 0;
}

void getInput(){
    cin >> numOfV;
    coordinate.resize(numOfV);
    for(int i = 0 ; i < numOfV ; i ++) {
        int xCo, yCo;
        cin >> xCo >> yCo;
        coordinate[i] = {xCo, yCo};
    }
}

void calarea() {
    pair<int, int> pivot = coordinate[0];
    double sum = 0;
    for(int i = 1 ; i < numOfV - 1 ; i++) {
        pair<int, int> cur = coordinate[i];
        pair<int, int> next = coordinate[i + 1];
        pair<int, int> side1 = {cur.first - pivot.first, cur.second - pivot.second};
        pair<int, int> side2 = {next.first - pivot.first, next.second - pivot.second};
        sum += ccw(side1, side2);
    }
    cout << fixed;
    cout.precision((1));
    sum = abs(sum);
    cout << sum / 2;
}

long long ccw(pair<int, int> a, pair<int, int> b) {
    return  (long long)a.first * (long long)b.second- (long long)a.second * (long long)b.first;
}