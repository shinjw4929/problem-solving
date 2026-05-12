# sstream

문자열을 스트림처럼 다루는 헤더. **문자열 파싱**과 **숫자/문자열 조립**에 쓴다.

```cpp
#include <sstream>
```

## 언제 쓰나

- 인자가 `string s` 하나로 들어오는데 그 안에 **공백/콤마 등 구분자로 여러 값**이 섞여 있을 때 (특히 프로그래머스)
- `"12 -3 456"` 같은 문자열을 `int` 리스트로 바꿔야 할 때
- 여러 값을 `"min max"`, `"3.14"` 처럼 **포맷팅된 문자열로 조립**할 때
- C 스타일 `strtok`/`sscanf` 대신 안전·간결한 C++ 방식이 필요할 때

## 세 종류

| 클래스 | 방향 | 용도 | 사용 연산자 |
|---|---|---|---|
| `istringstream` | 문자열 **→** 값 | 입력 (파싱) | `>>`, `getline` |
| `ostringstream` | 값 **→** 문자열 | 출력 (조립) | `<<` |
| `stringstream` | 양방향 | 한 객체로 읽고 쓰기 (드물게) | `>>`, `<<`, `getline` |

> `getline`은 입력 가능한 모든 스트림 (`cin`, `ifstream`, `istringstream`, `stringstream`)에서 동작. `ostringstream`만 입력 불가.

> **하나만 고른다면**: 파싱은 `istringstream`, 조립은 `ostringstream`. `stringstream`은 같은 버퍼에 쓰고 다시 읽어야 할 때만 (코테에선 거의 안 씀).

---

## 핵심 사용법

### `istringstream` — 문자열 → 값

문자열에서 값을 **꺼내는** 용도. `>>` 연산자가 변수 타입에 맞춰 자동 파싱.

**(a) 공백 구분 파싱**

```cpp
string s = "12 -3 456 -78";
istringstream iss(s);
int n;
while (iss >> n) {
    // n에 12, -3, 456, -78 차례로 들어옴
}
```

`operator>>`가 처리해주는 것들:
- 공백·탭·개행 자동 스킵
- 변수 타입대로 파싱 (`int`, `long long`, `double`, `string`)
- 음수 부호 인식
- 더 읽을 게 없거나 변환 실패시 fail bit → `while` 루프 자연 종료

**(b) 타입 섞어서 한 번에**

```cpp
istringstream iss("1 2.5 hello");
int a;       iss >> a;    // 1
double b;    iss >> b;    // 2.5
string c;    iss >> c;    // "hello" (공백 만날 때까지)
```

**(c) 임의 구분자로 split (`getline` 활용)**

```cpp
string s = "apple,banana,cherry";
istringstream iss(s);
string token;
while (getline(iss, token, ',')) {
    // token에 "apple", "banana", "cherry"
}
```

> 빈 토큰도 반환됨. `"a,,b"`는 `["a", "", "b"]`로 나옴. 무시하려면 `if (token.empty()) continue;`

> 큰 수가 들어올 가능성 있으면 `long long`으로 받자. int 범위 초과시 fail bit 세팅됨.

---

### `ostringstream` — 값 → 문자열

여러 값을 **합쳐서 문자열로** 만드는 용도. `<<` 연산자로 누적.

```cpp
ostringstream oss;
oss << "min " << mn << " max " << mx;
string result = oss.str();   // "min 12 max 456"
```

`to_string()` + `+` 연결보다 빠르고, 타입 변환 코드도 짧음. 특히 값이 여러 개일 때 효과적.

**소수점 자리수 고정**:
```cpp
#include <iomanip>
ostringstream oss;
oss << fixed << setprecision(2) << 3.14159;
oss.str();   // "3.14"
```

**진수 변환**:
```cpp
ostringstream oss;
oss << hex << 255;        // "ff"
oss.str();
```

---

### `stringstream` — 양방향 (잘 안 씀)

같은 버퍼에 쓰고 읽기를 반복해야 할 때만 의미 있음. 코딩테스트에선 사실상 `istringstream` 또는 `ostringstream` 중 하나로 충분하므로 **굳이 쓸 필요 없다**.

```cpp
stringstream ss;
ss << "42 3.14";       // 쓰기
int a; double b;
ss >> a >> b;          // 같은 객체에서 읽기
```

---

## 응용

### 문자열 split해서 vector<int>로
```cpp
vector<int> parse(const string& s) {
    istringstream iss(s);
    vector<int> v;
    int n;
    while (iss >> n) v.push_back(n);
    return v;
}
```

### 한 줄에 형식이 섞인 입력
```cpp
// "John 25 175.5" 같은 입력
istringstream iss(line);
string name; int age; double height;
iss >> name >> age >> height;
```

### `min max` 형태 결과 조립
```cpp
return to_string(mn) + " " + to_string(mx);
// 또는
ostringstream oss;
oss << mn << " " << mx;
return oss.str();
```

---

## 주의사항

- **재사용시 상태 리셋**: 한 번 fail bit 세팅되면 다시 못 읽음
  ```cpp
  iss.clear();          // 상태 리셋
  iss.str(newString);   // 새 내용 설정
  ```
- `getline(cin, ...)` 직전에 `cin >> ...` 했다면 버퍼에 남은 `\n` 때문에 빈 줄 읽힘 → `cin.ignore()` 필요. (프로그래머스는 stdin 안 쓰니까 상관없음)
- `iss >> string`은 공백까지만 읽음. 한 줄 전체 읽으려면 `getline` 사용.

---

## 프로그래머스 특화 팁

프로그래머스는 보통 인자가 `string s`로 통째로 들어옴. 그 안에 공백/콤마 구분 데이터가 있을 때 sstream이 거의 정답:

```cpp
// "1 2 3 4" 같은 input → min/max
string solution(string s) {
    istringstream iss(s);
    int n, mn = INT_MAX, mx = INT_MIN;
    while (iss >> n) {
        mn = min(mn, n);
        mx = max(mx, n);
    }
    return to_string(mn) + " " + to_string(mx);
}
```
