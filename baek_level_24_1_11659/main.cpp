#include <iostream>
#include <vector>


using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long int> arr(n + 1);
    for(int i = 1 ; i < n + 1 ; i++) {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }
    for(int i = 0 ; i < m ; i++) {
        int from, to;
        cin >> from >> to;
        cout << arr[to] - arr[from - 1] << '\n';
    }

    return 0;
}
