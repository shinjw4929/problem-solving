#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findnum(int tofind, int st, int end);
vector<vector<int>> alpha;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int numOfq;
    cin >> input >> numOfq;
    int size = input.size();

    alpha.resize(26, vector<int>(size + 1));
    for(int i = 0 ; i < 26 ; i ++) {
        for(int j = 0 ; j < size ; j++) {
            if(input[j]-97 == i) {
                alpha[i][j + 1] = alpha[i][j] + 1;
            }
            else {
                alpha[i][j + 1] = alpha[i][j];
            }
        }
    }


    for(int i = 0 ; i < numOfq ; i++) {
        char tofind;
        int start, end;
        cin >> tofind >> start >> end;
        cout << findnum(tofind-97, start, end) << '\n';
    }

    return 0;
}

int findnum(int tofind, int st, int end) {
    return(alpha[tofind][end + 1] - alpha[tofind][st]);
}
