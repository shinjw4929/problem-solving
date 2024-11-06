#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> parent_map;
map<string, int> all_amount;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int num_of_names = enroll.size();
    int num_of_sellers = seller.size();
    for(int i = 0 ; i < num_of_names ; i++){
        string & current_name = enroll[i];
        parent_map[current_name] = referral[i];
        all_amount[current_name] = 0;
    }
    
    for(int i = 0 ; i < num_of_sellers ; i++){
        string & current_seller = seller[i];
        int current_amount = amount[i] * 100;
        while(current_seller != "-" && current_amount > 0){
            int to_send = current_amount / 10;
            int remain = current_amount - to_send;
            all_amount[current_seller] = all_amount[current_seller] + remain;
            current_amount = to_send;
            current_seller = parent_map[current_seller];
        }
    }
    vector<int> answer;
    for(int i = 0 ; i < num_of_names ; i++){
        answer.push_back(all_amount[enroll[i]]);
    }
    
    
    return answer;
}
