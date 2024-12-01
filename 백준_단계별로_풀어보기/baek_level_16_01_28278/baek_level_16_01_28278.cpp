#include <cstdio>  // scanf, printf 사용
using namespace std;

int stack[10000001];
int top = -1;

int main() {
    int N, inst;
    scanf("%d", &N);  // N을 입력받음

    for (int i = 0; i < N; i++) {
        scanf("%d", &inst);  // 명령을 입력받음
        switch (inst) {
            case 1: {
                int num;
                scanf("%d", &num);  // 숫자를 입력받고 스택에 push
                top++;
                stack[top] = num;
                break;
            }
            case 2:
                if (top == -1) {
                    printf("-1\n");  // 스택이 비어 있으면 -1 출력
                } else {
                    printf("%d\n", stack[top]);  // 스택의 최상단 값 출력
                    top--;  // pop
                }
            break;
            case 3:
                printf("%d\n", top + 1);  // 스택 크기 출력
            break;
            case 4:
                printf("%d\n", top == -1 ? 1 : 0);  // 스택이 비어 있으면 1, 아니면 0
            break;
            case 5:
                if (top == -1) {
                    printf("-1\n");  // 스택이 비어 있으면 -1 출력
                } else {
                    printf("%d\n", stack[top]);  // 스택의 최상단 값 출력
                }
            break;
            default:
                break;
        }
    }

    return 0;
}
