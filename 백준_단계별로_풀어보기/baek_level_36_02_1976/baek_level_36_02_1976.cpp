#include <iostream>
#include <vector>


using namespace std;

class UF {
private:
    int numOfV, numOfT;
    vector<int> to_travel;
    vector<int> head;
    vector<int> rank;
    vector<vector<int>> graph;
    int findHead(int target);
    void unify(int a, int b);
public:
    void getInput();
    void findSet();
};

int main() {
    UF sol;
    sol.getInput();
    sol.findSet();
    return 0;
}

void UF::getInput() {
    cin >> numOfV >> numOfT;
    graph.resize(numOfV, vector<int>(numOfV, 0));
    head.resize(numOfV);
    rank.resize(numOfV, 0);
    to_travel.resize(numOfT);

    for(int i = 0 ; i < numOfV ; i++) {
        head[i] = i;
    }

    for(int i = 0 ; i < numOfV ; i++) {
        for(int j = 0 ; j < numOfV ; j++) {
            cin >> graph[i][j];
        }
    }
    for(int i = 0 ; i < numOfT ; i++) {
        cin >> to_travel[i];
    }
}

void UF::findSet() {
    for(int i = 0 ; i < numOfV ; i++) {
        for(int j = 0 ; j < numOfV ; j++) {
            if(graph[i][j]) {
                if(findHead(i) != findHead(j)) {
                    unify(i, j);
                }
            }
        }
    }

    bool poss = true;
    int tempHead = findHead(to_travel[0] - 1);
    for(auto&iter : to_travel) {
        if(tempHead != findHead(iter - 1)) {
            poss = false;
            break;
        }
    }
    if(poss) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

int UF::findHead(int target) {
    if(head[target] != target) {
        head[target] = findHead(head[target]);
    }
    return head[target];
}

void UF::unify(int a, int b) {
    int headA = findHead(a);
    int headB = findHead(b);

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
