#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

class Mst {
private:
    int numOfV;
    float distance(pair<float, float> a, pair<float, float> b);
    vector<pair<float, float>> coord;


    vector<int> rank;
    vector<int> head;
    void unify(int a, int b);
    int findH(int target);
public:
    void getInput();
    void mkMST();
};

int main() {
    Mst sol;
    sol.getInput();
    sol.mkMST();
    return 0;
}

void Mst::getInput() {
    cin >> numOfV;
    rank.resize(numOfV, 0);
    head.resize(numOfV);
    for(int i = 0 ; i < numOfV ; i++) {
        head[i] = i;
    }

    for(int i = 0 ; i < numOfV ; i++) {
        float x, y;
        cin >> x >> y;
        coord.push_back({x, y});
    }
}

float Mst::distance(pair<float, float> a, pair<float, float> b) {
    float width = a.first - b.first;
    float length = a.second - b.second;
    return sqrt(width * width + length * length);
}

int Mst::findH(int target) {
    if(head[target] != target) {
        head[target] = findH(head[target]);
    }
    return head[target];
}

void Mst::unify(int a, int b) {
    int headA = head[a];
    int headB = head[b];
    if(rank[headA] > rank[headB]) {
        head[headB] = headA;
    }
    else if(rank[headA] < rank[headB]) {
        head[headA] = headB;
    }
    else {
        rank[headA]++;
        head[headB] = headA;
    }
}

void Mst::mkMST() {
    priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<>> pq;
    for(int i = 0 ; i < numOfV - 1 ; i++) {
        for(int j = i + 1 ; j < numOfV ; j++) {
            float dist = distance(coord[i], coord[j]);
            pq.push({dist, {i, j}});
        }
    }
    int cnt = 0;
    float result = 0;
    while(cnt < numOfV - 1) {
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        float dist = pq.top().first;
        pq.pop();
        if(findH(u) != findH(v)) {
            unify(u, v);
            result += dist;
            cnt++;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << result;
}
