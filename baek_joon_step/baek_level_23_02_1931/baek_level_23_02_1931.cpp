#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Max = 2147483647;

int n;
int cnt = 1;
vector<pair<int, int>> times;

bool pairsortFirst(pair<int, int> a, pair<int, int> b);
bool pairsortSecond(pair<int, int> a, pair<int, int> b);

int main() {
    cin >> n;
    times.resize(n);
    for(int i = 0; i < n ; i++) {
        cin >> times[i].first >> times[i].second;
    }
    sort(times.begin(), times.end(), pairsortFirst);
    sort(times.begin(), times.end(), pairsortSecond);
    int min = times[0].second;
    times[0].first = -1;

    for(int i = 1; i < n ; i++) {
        if(times[i].first >= min) {
            min = times[i].second;
            times[i].first = -1;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

bool pairsortFirst(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
bool pairsortSecond(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}