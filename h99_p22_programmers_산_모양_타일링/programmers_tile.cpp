#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    vector<long long> dp(n, 0);
    if(tops[0]){
        dp[0] = 4;
    }
    else{
        dp[0] = 3;
    }
    
    if(n > 1){
        if(tops[1]){
            dp[1] = dp[0] * 3 + dp[0] - 1;
        }
        else{
            dp[1] = dp[0] * 2 + dp[0] - 1;
        }

        for(int i = 2 ; i < n ; i++){
            int multi = 3;
            if(tops[i]){
                multi++;
            }
            dp[i] = (dp[i - 1] * multi) % 10007 - dp[i - 2]  % 10007;
            if(dp[i] < 0){
                dp[i] = dp[i] + 10007;
            }
        }
    }

    

    int answer = dp[n - 1];
    return answer;
}
