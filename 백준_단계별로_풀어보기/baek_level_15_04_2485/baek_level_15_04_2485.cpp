#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //
    int num;
    cin >> num;
    vector<int> tree(num), dist(num - 1);
    for(int i = 0 ; i < num ; i++) {
        cin >> tree[i];
        if(i > 0) {
            dist[i - 1] = tree[i] - tree[i - 1];
        }
    }
    //입력

    //각 거리 차의 최대공약수를 구함
    int temp = __gcd(dist[0], dist[1]);
    for(int i = 2 ; i < num - 1; i++) {
        temp = __gcd(temp, dist[i]);
    }
    //최대공약수로 심어야할 나무 구함
    int sum = 0;
    for(int i = 0 ; i < num - 1; i++) {
        sum = sum + (dist[i] / temp - 1);
    }
    cout << sum;
    return 0;
}
