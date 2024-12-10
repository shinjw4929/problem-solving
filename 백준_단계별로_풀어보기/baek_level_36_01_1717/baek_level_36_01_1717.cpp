#include <iostream>
#include <vector>

using namespace std;

class Sets {
private:
    int numOfSet;
    int numOfOp;
    vector<int> root;
    vector<int> rank;
public:
    void getInput();
    void uni(int a, int b);
    void uniFind(int a, int b);
    int findRoot(int &argu);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Sets UF;
    UF.getInput();
    return 0;
}

void Sets::getInput() {
    cin >> numOfSet >> numOfOp;
    root.resize(numOfSet + 1);
    rank.resize(numOfSet+1, 0);

    for(int i = 0 ; i < numOfSet + 1; i++) {
        root[i] = i;
    }
    for(int i = 0 ; i < numOfOp ; i++) {
        int op, argu1, argu2;
        cin >> op >> argu1 >> argu2;
        if(op == 0) {
            uni(argu1, argu2);
        }
        else {
            uniFind(argu1, argu2);
        }
    }
}

void Sets::uni(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rank[rootA] > rank[rootB]) {
        root[rootB] = rootA;
    }
    else if(rank[rootA] < rank[rootB]){
        root[rootA] = rootB;
    }
    else {
        root[rootB] = rootA;
        rank[rootA] ++;
    }

}

void Sets::uniFind(int a, int b) {
    if(findRoot(a) == findRoot(b)) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
}

int Sets::findRoot(int &argu) {
    if(root[argu] != argu) {
        root[argu] = findRoot(root[argu]);
    }
    return root[argu];
}
