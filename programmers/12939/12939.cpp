#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <climits>

using namespace std;

string solution(string s) {
    istringstream iss(s);
    long long minimum = INT_MAX;
    long long maximum = INT_MIN;
    long long temp = 0;
    while(iss >> temp) {
        minimum = min(minimum, temp);
        maximum = max(maximum, temp);
    }
    string answer = "";
    answer += to_string(minimum);
    answer += ' ';
    answer += to_string(maximum);
    return answer;
}


#if __has_include("../pg.h")
#include "../pg.h"
int main() {
    pg::tests(solution, R"(
s	return
"1 2 3 4"	"1 4"
"-1 -2 -3 -4"	"-4 -1"
"-1 -1"	"-1 -1"
)");
    pg::summary();
}
#endif