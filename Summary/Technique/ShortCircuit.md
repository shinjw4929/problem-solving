# Short-Circuit Evaluation

`&&`, `||`는 왼쪽이 결정나면 오른쪽을 **평가하지 않는다**. 범위 검사와 접근을 한 줄에 안전하게 묶을 때 씀.

## 패턴

```cpp
// i == 0이면 s[i-1]은 평가조차 안 됨
if (i == 0 || s[i-1] == ' ') { ... }

// i >= n이면 arr[i] 접근 안 함
if (i < n && arr[i] == target) { ... }
```

## 주의

**가드를 항상 앞에.** 순서를 뒤집으면 정의되지 않은 동작(Undefined Behavior).

```cpp
if (s[i-1] == ' ' || i == 0)   // i=0일 때 s[-1] 먼저 → Undefined Behavior
```

`std::string::operator[]`의 인덱스는 `size_t`라서 `-1`이 거대한 양수로 변환됨.
