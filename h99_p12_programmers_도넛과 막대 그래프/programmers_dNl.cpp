//생각
//input 0개, output(MAX) : 생성
//output 0개 : 막대
//합 : 사이클(절대값2), 팔자(절대값 4)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> edges;
vector<int> input;
vector<int> output;
vector<int> answer;
int numOfVertices = 0;
int numOfEges = 0;

void findIO();
void findCre();
void findGraph();


vector<int> solution(vector<vector<int>> _edges) {
    vector<int> _answer;
    edges = _edges;
    answer = _answer;
    findIO();
    findCre();
    findGraph();
    return answer;
}


void findIO(){
    numOfEges = edges.size();
    int maxNode = -1;
    for(int i = 0 ; i <  numOfEges; i++){
        maxNode = max(maxNode, edges[i][0]);
        maxNode = max(maxNode, edges[i][1]);
    }
    numOfVertices = maxNode + 1;
    input.assign(numOfVertices, 0);
    output.assign(numOfVertices, 0);
    for(int i = 0 ; i < numOfEges; i++){
        input[edges[i][1]]++;
        output[edges[i][0]]++;
    }
    
}

void findCre(){
    vector<int> creIdx;
    for(int i = 1; i < numOfVertices; i++){
        if(input[i] == 0){
            creIdx.push_back(i);
        }
    }
    int maxOutput = 0;
    int maxIdx = 0;
    for(int i = 0; i < creIdx.size(); i++){
        if(maxOutput < output[creIdx[i]]){
            maxIdx = creIdx[i];
            maxOutput = output[creIdx[i]];
        }
    }
    answer.resize(4);
    answer[0] = maxIdx;
}


void findGraph(){
    int numOfGraph = output[answer[0]];
    int numOf8 = 0;
    int numOfCycle = 0;
    int numOfFlat = 0;
    for(int i = 1; i < numOfVertices; i++){
        if(i == answer[0]){
            continue;
        }
        if(input[i] + output[i] >= 4){
            numOf8++;
        }
        else if(output[i] == 0 && input[i] > 0){
            numOfFlat++;
        }
    }
    numOfCycle = numOfGraph - numOf8 - numOfFlat;
    answer[1] = numOfCycle;
    answer[2] = numOfFlat;
    answer[3] = numOf8;
}
