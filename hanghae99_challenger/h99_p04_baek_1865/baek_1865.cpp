#include <iostream>
#include <vector>

#define MAX 10001

using namespace std;

class prob {
public:
    int num_testcase, num_vertices, num_edges, num_neg_edges;
    vector<vector<int>> vertex_arr;
    void inputNsolve();
    void floyd_warshall();
    void print_possibility();
};

int main() {
    prob graph;
    graph.inputNsolve();
    return 0;
}

void prob::inputNsolve() {
    cin >> num_testcase;
    for(int t = 0 ; t < num_testcase; t++) {
        cin >> num_vertices >> num_edges >> num_neg_edges;
        vertex_arr.erase(vertex_arr.begin(), vertex_arr.end());
        vertex_arr.resize(num_vertices, vector<int>(num_vertices, MAX));
        for(int i = 0; i < num_edges; i++) {
            int start, end, time;
            cin >> start >> end >> time;
            start--;
            end--;
            if(vertex_arr[start][end] > time) {
                vertex_arr[start][end] = time;
                vertex_arr[end][start] = time;
            }
        }
        for(int i = 0 ; i < num_neg_edges; i++) {
            int start, end, time;
            cin >> start >> end >> time;
            start--;
            end--;
            if(vertex_arr[start][end] > 0) {
                vertex_arr[start][end] = -1 * time;
            }
        }
        floyd_warshall();
        print_possibility();
    }
}


void prob::floyd_warshall() {
    for(int target = 0 ; target < num_vertices; target++) {
        for(int i = 0 ; i < num_vertices; i++) {
            for(int j = 0 ; j < num_vertices; j++) {
                vertex_arr[i][j] = min(vertex_arr[i][j], vertex_arr[i][target] + vertex_arr[target][j]);
            }
        }
    }
}

void prob::print_possibility() {
    bool possible = false;
    for(int i = 0; i < num_vertices ; i++) {
        if(vertex_arr[i][i] < 0) {
            possible = true;
        }
    }
    if(possible) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
}
