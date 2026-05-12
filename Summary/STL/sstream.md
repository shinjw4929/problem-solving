# sstream

문자열을 스트림처럼 다루는 헤더. **파싱**과 **조립**용.

```cpp
#include <sstream>
```

## 언제 쓰나

- `string s` 하나에 공백/콤마로 여러 값이 섞여 들어올 때 (특히 프로그래머스)
- `"12 -3 456"` → `vector<int>` 변환
- 여러 값을 `"min max"` 같은 포맷 문자열로 조립

## 클래스

| 클래스 | 방향 | 연산자 |
|---|---|---|
| `istringstream` | 문자열 → 값 (파싱) | `>>`, `getline` |
| `ostringstream` | 값 → 문자열 (조립) | `<<` |
| `stringstream` | 양방향 (코테에선 거의 안 씀) | `>>`, `<<`, `getline` |

---

## `istringstream` — 파싱

`>>`가 공백 스킵 + 타입대로 자동 파싱. 더 못 읽으면 fail bit → `while` 자연 종료.

```cpp
string s = "12 -3 456 -78";
istringstream iss(s);
int n;
while (iss >> n) { /* 12, -3, 456, -78 */ }
```

**타입 섞어서**:
```cpp
istringstream iss("1 2.5 hello");
int a; double b; string c;
iss >> a >> b >> c;        // 1, 2.5, "hello"
```

**임의 구분자 split** — `getline`의 3번째 인자:
```cpp
istringstream iss("apple,banana,cherry");
string tok;
while (getline(iss, tok, ',')) { /* ... */ }
```
> 빈 토큰도 반환됨. `"a,,b"` → `["a", "", "b"]`. 무시하려면 `if (tok.empty()) continue;`

> int 범위 초과 가능성 있으면 `long long`으로 받기. 초과 시 fail bit.

---

## `ostringstream` — 조립

```cpp
ostringstream oss;
oss << "min " << mn << " max " << mx;
string result = oss.str();   // "min 12 max 456"
```

`to_string + "+"` 연결보다 짧고, 값이 많을수록 유리.

**소수점·진수 변환** (`<iomanip>` 필요):
```cpp
oss << fixed << setprecision(2) << 3.14159;   // "3.14"
oss << hex << 255;                            // "ff"
```

---

## `stringstream`

같은 버퍼에 쓰고 읽기를 반복할 때만 의미 있음. 코테에선 `istringstream` / `ostringstream` 중 하나로 충분.

---

## 주의사항

- **재사용 시 상태 리셋**: 한 번 fail bit 세팅되면 그대로 멈춤
  ```cpp
  iss.clear();          // 상태 리셋
  iss.str(newString);   // 새 내용
  ```
- `iss >> string`은 공백까지만 읽음. 한 줄 전체는 `getline`.
- `cin >> ...` 직후 `getline(cin, ...)`은 버퍼에 남은 `\n` 때문에 빈 줄 읽힘 → `cin.ignore()`. (프로그래머스는 stdin 안 쓰니 무관)
