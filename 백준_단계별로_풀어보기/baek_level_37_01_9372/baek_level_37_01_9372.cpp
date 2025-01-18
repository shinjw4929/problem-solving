#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0 ; t < T; t++) {
        int nV, nE;
        cin >> nV >> nE;
        for(int i = 0 ; i < nE ; i++) {
            int u, v;
            cin >> u >> v;
        }
        cout << nV - 1 << '\n';
    }

    return 0;
}
