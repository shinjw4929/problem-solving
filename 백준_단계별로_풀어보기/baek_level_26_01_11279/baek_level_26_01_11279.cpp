#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    priority_queue<int> max_heap;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp > 0) {
            max_heap.push(temp);
        }
        else {
            if(max_heap.empty()) {
                cout << 0 << '\n';
            }
            else {
                int max_val = max_heap.top();
                cout << max_val << '\n';
                max_heap.pop();
            }

        }
    }



    return 0;
}
