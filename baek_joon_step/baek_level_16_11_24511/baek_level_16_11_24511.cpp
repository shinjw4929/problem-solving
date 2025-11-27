#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int *A, *B, *C, *queuestack;
    int count = 0;
    cin >> N;
    A = new int[N];
    B = new int[N];
    for(int i = 0; i < N ; i++) {
        cin >> A[i];
        if(!A[i]) {
            count ++;//A가 큐일때만 개수 셈
        }
    }
    for(int i = 0, idx = 0; i < N ; i++) {
        cin >> B[i];
    }
    cin >> M;
    C = new int[M];
    for(int i = 0; i < M ; i++) {
        cin >> C[i];
    }
    //입력


    queuestack = new int[count + M];
    int idx = 0;
    for(int i = N - 1; i >= 0 ; i--) {
        if(!A[i]) {
            queuestack[idx] = B[i]; // A가 큐면 B값 넣음
            idx++;
        }
    }
    for(int i = 0; i < M ; i++) {
        queuestack[idx] = C[i];
        idx++;
    }
    for(int i = 0; i < M ; i++) {
        cout << queuestack[i] << ' ';
    }


    delete[] A;
    delete[] B;
    delete[] queuestack;
    delete[] C;
    return 0;
}
