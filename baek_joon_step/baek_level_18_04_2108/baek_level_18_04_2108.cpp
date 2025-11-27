#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <unordered_map>

using namespace std;

int main() {
    int num;
    int cnt_max = 1;
    int mode;
    cin >> num;
    vector<int> numarr(num);
    vector<int> manynum;
    unordered_map<int, int>Count_num;


    for(int i = 0; i < num ; i++) {
        int temp;
        cin >> temp;
        numarr[i] = temp;
        if(!Count_num.count(temp)) {
            Count_num[temp] = 1;
        }
        else {
            Count_num[temp] = Count_num[temp] + 1;
            if(cnt_max < Count_num[temp]) {
                cnt_max = Count_num[temp];
            }
        }
    }
    //input
    sort(numarr.begin(), numarr.end());

    for(const auto &iter : Count_num) {
        if(iter.second == cnt_max) {
            manynum.push_back(iter.first);
        }
    }
    if(manynum.size() > 1) {
        sort(manynum.begin(), manynum.end());
        mode = manynum[1];
    }
    else {
        mode = manynum[0];
    }


    cout << (int)round(static_cast<float>(accumulate(numarr.begin(), numarr.end(), 0)) / num) << '\n';
    cout << numarr[num/2] << '\n';
    cout << mode << '\n';
    cout << abs(numarr[num - 1] - numarr[0]);



    return 0;
}
