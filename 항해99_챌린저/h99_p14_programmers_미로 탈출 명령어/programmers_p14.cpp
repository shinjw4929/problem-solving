#include <string>
#include <vector>

using namespace std;

void dfs(int currentR, int currentC, const int &n, const int &m, const int &destR, const int &destC, int remain, string path);
bool valid(const int &r, const int &c, const int &n, const int &m);

vector<string> strArr;
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};
vector<char> dir = {'u', 'd', 'l', 'r'};
vector<int> order = {1, 2, 3, 0};
bool isFin = false;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int distR = abs(x - r);
    int distC = abs(y - c);
    int totDist = distR + distC;
    if(totDist > k || (k - totDist) % 2){
        answer = "impossible";
    }
    else{
        dfs(x, y, n, m, r, c, k, "");
        answer = strArr.front();
    }
    return answer;
}

bool valid(const int &r, const int &c, const int &n, const int &m){
    return (r<=n && r>0 && c<=m && c>0);
}

void dfs(int currentR, int currentC, const int &n, const int &m, const int &destR, const int &destC, int remain, string path){
    if(isFin){
        return;
    }
    if(currentR == destR && currentC == destC && remain == 0){
        strArr.push_back(path);
        isFin = true;
        return;
    }
    for(int i : order){
        int nextR = currentR + dr[i];
        int nextC = currentC + dc[i];
        char direction = dir[i];
        if(valid(nextR, nextC, n, m)){
            int distR = abs(nextR - destR);
            int distC = abs(nextC - destC);
            int totDist = distR + distC;
            int currentRemain = remain - 1;
            if(totDist <= currentRemain && (currentRemain - totDist) % 2 == 0){
                dfs(nextR, nextC, n, m, destR, destC, remain - 1, path + direction);
                if (isFin) return;
            }
        }
    }
  
}
