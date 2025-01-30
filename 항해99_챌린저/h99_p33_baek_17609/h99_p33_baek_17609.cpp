#include <iostream>
#include <string>

using namespace std;

class Pal {
private:
    int cnt;
    int numOfT;
    int judge(string& str, int idx1, int idx2);
public:
    void getInput();
};

int main() {
    Pal sol;
    sol.getInput();
    return 0;
}

void Pal::getInput() {
    cin >> numOfT;
    for (int i = 0 ; i < numOfT ; i++) {
        cnt = 0;
        string str;
        cin >> str;
        cout << judge(str, 0, str.size() - 1) << '\n';
    }
}

int Pal::judge(string& str, int idx1, int idx2) {
    while (true) {
        if (idx1 >= idx2) {
            return 0;
        }
        if (str[idx1] == str[idx2]) {
            idx1++;
            idx2--;
        }
        else {
            if (cnt == 0) {
                cnt++;
                if (judge(str, idx1 + 1, idx2) == 0 || judge(str, idx1, idx2 - 1) == 0) {
                    return 1;
                }
                else {
                    return 2;
                }
            }
            else {
                return 2;
            }
        }
    }

}
