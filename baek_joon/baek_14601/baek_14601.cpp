#include <iostream>
#include <vector>

using namespace std;


int K = 7, x = 128, y = 128;
int arrSize;
int cnt = 1;
vector<vector<int>> arr;

void getInput();
void solve();
void findHole(int basisX, int basisY, int unitSize, int targetX, int targetY);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getInput();
    solve();
    return 0;
}

void getInput() {
    cin >> K >> x >> y;
    x--;
    y--;
    arrSize = 1 << K;
    arr.resize(arrSize, vector<int>(arrSize));
    arr[y][x] = -1;
}

void solve() {
    findHole(0, 0, (1 << K), x, y);
    for (int i = arrSize - 1 ; i >= 0; i--) {
        for (int j = 0 ; j < arrSize; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void findHole(int basisX, int basisY, int unitSize, int targetX, int targetY) {
    if (unitSize == 1) return;

    int nextSize = unitSize / 2;
    // 현재 영역의 '중앙'을 가리키도록 수정 (왼쪽/아래쪽 사분면의 마지막 인덱스)
    int midX = basisX + nextSize - 1;
    int midY = basisY + nextSize - 1;
    int currentCnt = cnt++;

    // targetX, targetY가 중앙선(mid)을 넘었는지 확인
    bool isRight = (targetX > midX);
    bool isUp = (targetY > midY);

    // 1. 배수구가 없는 사분면의 중앙 인접 칸을 채움
    // 1사분면(우상)에 배수구가 없다면 해당 칸을 채움
    if (!(isRight && isUp))    arr[midY + 1][midX + 1] = currentCnt;
    // 2사분면(좌상)에 배수구가 없다면 해당 칸을 채움
    if (!(!isRight && isUp))   arr[midY + 1][midX] = currentCnt;
    // 3사분면(좌하)에 배수구가 없다면 해당 칸을 채움
    if (!(!isRight && !isUp))  arr[midY][midX] = currentCnt;
    // 4사분면(우하)에 배수구가 없다면 해당 칸을 채움
    if (!(isRight && !isUp))   arr[midY][midX + 1] = currentCnt;

    // 2. 재귀 호출 (각 사분면으로 분할)
    // 1사분면 (우상): x 범위 [basisX + nextSize, ...], y 범위 [basisY + nextSize, ...]
    findHole(basisX + nextSize, basisY + nextSize, nextSize,
             (isRight && isUp) ? targetX : basisX + nextSize,
             (isRight && isUp) ? targetY : basisY + nextSize);

    // 2사분면 (좌상): x 범위 [basisX, midX], y 범위 [basisY + nextSize, ...]
    findHole(basisX, basisY + nextSize, nextSize,
             (!isRight && isUp) ? targetX : midX,
             (!isRight && isUp) ? targetY : midY + 1);

    // 3사분면 (좌하): x 범위 [basisX, midX], y 범위 [basisY, midY]
    findHole(basisX, basisY, nextSize,
             (!isRight && !isUp) ? targetX : midX,
             (!isRight && !isUp) ? targetY : midY);

    // 4사분면 (우하): x 범위 [basisX + nextSize, ...], y 범위 [basisY, midY]
    findHole(basisX + nextSize, basisY, nextSize,
             (isRight && !isUp) ? targetX : midX + 1,
             (isRight && !isUp) ? targetY : midY);
}