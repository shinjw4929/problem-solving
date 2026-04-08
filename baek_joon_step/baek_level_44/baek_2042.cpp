#include <iostream>
#include <vector>
#include <c>

using namespace std;

int N = 1000000;
int M = 10000;
int K= 10000;

vector<double> segmentTree;

void input();
void createTree();


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    

    return 0;
}

void input(){
    cin >> N >> M >> K;
    createTree();
    for(int i = 0 ; i < N ; i++){
        
    }
}

void createTree(){
    int size = 2;
    while(size < N){
        size * 2;
    }
    segmentTree.assign(size*2, 0);
}