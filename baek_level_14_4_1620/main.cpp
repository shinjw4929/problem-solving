#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    map<string, int> pokemon;//맵을 통해 key를 통해 value찾음
    map<int, string> reverse_pokemon;//맵을 2개로 만들고 value를 통해 key찾음
    string arr[num2];

    //도감 입력
    for(int i = 1 ; i <= num1 ; i++) {
        string temp;
        cin >> temp;
        pokemon.insert({temp, i});
        reverse_pokemon.insert({i, temp});
    }
    //문제 입력
    for(int i = 0 ; i < num2 ; i++) {
        string temp;
        cin >> temp;
        arr[i] = temp;
    }

    for(int i =0 ; i <num2 ; i++) {
        if(isdigit(arr[i][0])) {
            int num = stoi(arr[i]);
            cout << reverse_pokemon.find(num)->second << '\n';
        }
        else {
            auto it = pokemon.find(arr[i]);
            cout << it->second << '\n';
        }
    }
    return 0;
}
