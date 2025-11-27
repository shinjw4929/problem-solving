#include <iostream>
#include <map>

using namespace std;

int main() {
    int totalNum;
    cin >> totalNum;
    map<int, int> num;
    for(int i = 0 ; i < totalNum ; i++) {
        int temp;
        cin >> temp;
        num[temp]++;
    }
    int goodCnt = 0 ;
    for(auto &iter : num) {
        for(auto &numA : num) {
            int sum = iter.first;
            int A = numA.first;
            int numOfSum = iter.second;
            int numOfA = numA.second;
            int B = sum - A;
            if(num.find(B) != num.end()) {
                if( sum != A && sum != B && A != B) {
                    goodCnt = goodCnt + numOfSum;
                    break;
                }
                else if(sum != A && sum != B && A == B) {
                    if(numOfA > 1) {
                        goodCnt = goodCnt + numOfSum;
                        break;
                    }
                }
                else if(sum == A && sum == B) {
                    if(numOfSum > 2) {
                        goodCnt = goodCnt + numOfSum;
                        break;
                    }
                }
                else if(sum == A && sum != B) {
                    if(numOfSum > 1) {
                        goodCnt = goodCnt + numOfSum;
                        break;
                    }
                }
                else if(sum != A && sum == B) {
                    if(numOfSum > 1) {
                        goodCnt = goodCnt + numOfSum;
                        break;
                    }
                }
                else if(A == B) {
                    if(numOfA > 1) {
                        goodCnt = goodCnt + numOfSum;
                        break;
                    }
                }
            }

        }
    }


    cout << goodCnt;

    return 0;
}
