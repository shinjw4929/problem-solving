#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
vector<int> books;
vector<int> dist;

void getInput();
void findMaxDist();
void pickUpBooks(int maxdist);
void calDist();

int main() {
    getInput();
    int idx = 0;
    while(!books.empty()) {
        findMaxDist();
        pickUpBooks(dist[idx]);
        idx++;
    }
    calDist();
    return 0;
}

void getInput() {
    cin >> n >> m;
    books.assign(n, 0);
    for(int i = 0 ; i < n ; i++) {
        cin >> books[i];
    }
    sort(books.begin(), books.end());
}

void findMaxDist() {
    int maxDist = books.back();
    if(abs(books.back()) <= abs(books.front())) {
        maxDist = books.front();
    }
    dist.push_back(maxDist);
}

void pickUpBooks(int maxdist) {
    int onHand = 0;
    int range = books.size();

    if(maxdist < 0) {
        for(int i = 0; i < min(m, range); i++) {
            if(books[i] < 0) {
                onHand++;
            }
            else {
                break;
            }
        }
        books.erase(books.begin(), books.begin() + onHand);
    }
    else {
        for(int i = range - 1;  i >= range - min(m, range) ; i--) {
            if(books[i] >= 0) {
                onHand++;
            }
            else {
                break;
            }
        }
            books.erase(books.end() - onHand, books.end());
    }

}

void calDist() {
    bool isEnd = true;
    int tot = 0;
    for(auto &iter : dist) {
        if(isEnd) {
            tot = abs(iter);
            isEnd = false;
        }
        else {
            tot = tot + 2 * abs(iter);
        }
    }
    cout << tot;
}
