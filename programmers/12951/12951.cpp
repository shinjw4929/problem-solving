#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    s[0] = toupper(s[0]);
    char prev = s[0];
    for(int i = 1 ; i < s.size() ; i++){
        if(prev != ' '){
            s[i] = tolower(s[i]);
        }
        else{
            s[i] = toupper(s[i]);
        }
        prev = s[i];
    }
    string answer = s;
    return answer;
}

#if __has_include("../pg.h")
#include "../pg.h"
int main() {
    pg::tests(solution, R"(
s	return
"3people unFollowed me"	"3people Unfollowed Me"
"for the last week"	"For The Last Week"
)");
    pg::summary();
}
#endif