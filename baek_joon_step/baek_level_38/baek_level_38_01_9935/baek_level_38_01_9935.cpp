#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    string bomb;
    string result;
    cin >> str >> bomb;

    for(int i = 0 ; i < str.size() ; i++) {
        result += str[i];
        if(result.size() >= bomb.size()) {
            bool isBomb = true;
            for(int j = 0 ; j < bomb.size() ; j++) {
                if(result[j + result.size() - bomb.size()] != bomb[j]) {
                    isBomb = false;
                    break;
                }
            }

            if(isBomb) {
                result.erase(result.end() - bomb.size(), result.end());
            }

        }
    }


    if(result.empty()) {
        cout << "FRULA";
    }
    else {
        cout << result;
    }


    return 0;
}
