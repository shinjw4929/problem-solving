#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Zelda {
private:
    int arrSize;
    vector<vector<int>> arr;
    vector<vector<int>> distanceArr;
    int problemNum = 0;
public:
    void processInput();
    void dijkstra();
    void updateMaxHeap(priority_queue<pair<int, pair<int,int>>> &max_heap);
    bool valid(pair<int, int> p);
};


int main() {
    Zelda prob;
    prob.processInput();


    return 0;
}

void Zelda::processInput() {
    while(true) {
        cin >> arrSize;
        problemNum++;
        if(arrSize == 0) {
            break;
        }
        distanceArr.assign(arrSize, vector<int>(arrSize, -1));
        arr.assign(arrSize, vector<int>(arrSize, 0));
        for(int i = 0 ; i < arrSize ; i++) {
            for(int j = 0 ; j < arrSize ; j++) {
                cin >> arr[i][j];
            }
        }
        dijkstra();
    }
}


void Zelda::dijkstra() {
    priority_queue<pair<int, pair<int,int>>> max_heap;

    max_heap.push({(-1)* arr[0][0], {0, 0}});
    while(!max_heap.empty()) {
        updateMaxHeap(max_heap);
    }
    cout << "Problem " << problemNum << ": " << distanceArr[arrSize - 1][arrSize - 1] << '\n';
}

void Zelda::updateMaxHeap(priority_queue<pair<int, pair<int,int>>> &max_heap) {
    pair<int, int> up, down, left, right;
    int currentWeight = max_heap.top().first;
    pair<int, int> current = max_heap.top().second;
    max_heap.pop();
    up = {current.first - 1, current.second};
    down = {current.first + 1, current.second};
    left = {current.first , current.second -1};
    right = {current.first , current.second + 1};


    int minWeight = -1 * currentWeight;
    if(valid(up)) {
        if(distanceArr[up.first][up.second] != -1) {
            minWeight = min(minWeight, arr[current.first][current.second] + distanceArr[up.first][up.second]);
        }
    }
    if(valid(down)) {
        if(distanceArr[down.first][down.second] != -1) {
            minWeight = min(minWeight, arr[current.first][current.second] + distanceArr[down.first][down.second]);
        }
    }
    if(valid(left)) {
        if(distanceArr[left.first][left.second] != -1) {
            minWeight = min(minWeight, arr[current.first][current.second] + distanceArr[left.first][left.second]);
        }
    }
    if(valid(right)) {
        if(distanceArr[right.first][right.second] != -1) {
            minWeight = min(minWeight, arr[current.first][current.second] + distanceArr[right.first][right.second]);
        }
    }
    distanceArr[current.first][current.second] = minWeight;
    if((minWeight != -1 * currentWeight)) {
        if(valid(up) && (minWeight + arr[up.first][up.second] < distanceArr[up.first][up.second])) {
            max_heap.push({-1 *minWeight - arr[up.first][up.second], up});
        }
            if(valid(down)&& (minWeight + arr[down.first][down.second] < distanceArr[down.first][down.second])) {
            max_heap.push({-1 *minWeight - arr[down.first][down.second], down});
        }
        if(valid(left)&& (minWeight + arr[left.first][left.second] < distanceArr[left.first][left.second])) {
            max_heap.push({-1 *minWeight - arr[left.first][left.second], left});
        }
        if(valid(right)&& (minWeight + arr[right.first][right.second] < distanceArr[right.first][right.second])) {
            max_heap.push({-1 *minWeight - arr[right.first][right.second], right});
        }
    }
    else {
        if(valid(up)) {
            if(distanceArr[up.first][up.second] == -1) {
                max_heap.push({-1 *minWeight - arr[up.first][up.second], up});
            }
        }
        if(valid(down)) {
            if(distanceArr[down.first][down.second] == -1) {
                max_heap.push({-1 *minWeight - arr[down.first][down.second], down});
            }
        }
        if(valid(left)) {
            if(distanceArr[left.first][left.second] == -1) {
                max_heap.push({-1 *minWeight - arr[left.first][left.second], left});
            }
        }
        if(valid(right)) {
            if(distanceArr[right.first][right.second] == -1) {
                max_heap.push({-1 *minWeight - arr[right.first][right.second], right});
            }
        }
    }

}

bool Zelda::valid(pair<int, int> p) {
    if(p.first < arrSize && p.first >= 0 && p.second < arrSize && p.second >= 0) {
        return true;
    }
    return false;
}
