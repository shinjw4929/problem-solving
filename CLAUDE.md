# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 커뮤니케이션

사용자와는 한국어로 소통한다.

## 풀이 제시 금지 (중요)

이 저장소는 사용자가 직접 PS(코딩테스트) 문제를 푸는 학습 공간이다. **사용자가 명시적으로 "풀이를 알려줘", "코드를 작성해줘", "정답을 보여줘" 같이 명확하게 요청하지 않는 한, 문제에 대한 풀이(알고리즘 선택·핵심 아이디어·의사코드·정답 코드)를 직접 제시하지 않는다.**

- 사용자가 단순히 문제를 보여주거나 "이 문제 어때?", "이거 풀고 있어" 같이 말할 때 → 풀이를 먼저 꺼내지 않는다.
- 사용자가 자기 코드를 보여주고 "왜 틀렸지?", "런타임 에러 나" 같이 물을 때 → 풀이 자체를 새로 제시하지 말고, 사용자의 코드에 한해서 디버깅(틀린 지점·반례·복잡도 문제 지적)만 한다.
- 힌트조차 먼저 꺼내지 않는다. 사용자가 "힌트 줘"라고 명시할 때만 힌트로 답한다.
- 예외: 사용자가 푼 뒤 "더 나은 풀이가 있어?" 또는 "내 풀이 리뷰해줘"라고 요청하면 그때는 대안 풀이/개선안을 제시해도 된다.
- `Summary/` 폴더의 일반 알고리즘·자료구조 설명 요청은 풀이 제시가 아니므로 자유롭게 응답한다.

## What this repo is

Personal coding-test (PS) workspace for 백준(Baekjoon)/프로그래머스(Programmers)/항해99 problems, written in C++17. Each problem is its own self-contained `.cpp` file. There is no production code, no library, no shared runtime — only solutions.

README links (Korean):
- `baek_joon_step/` — 백준 단계별로 풀어보기
- `hanghae99_challenger/` — 항해99 스터디 챌린저 (one problem per day, paired with a TIL `.md`)
- `baek_joon/` — 그 외 백준 문제
- `programmers/` — 프로그래머스 (special: uses `pg.h` test harness, see below)
- `Summary/` — reference notes (STL/Algorithm/DataStructure/Technique). See `Summary/README.md` for the doc template before adding new notes.

## Build system — only `programmers/` is wired into CMake

`CMakeLists.txt` does **one** thing: it `GLOB_RECURSE`s `programmers/*.cpp` and creates one executable per problem folder, named `p<folder>`. So `programmers/12978/12978.cpp` builds as target `p12978`.

- `baek_joon/`, `baek_joon_step/`, `hanghae99_challenger/` are **not** in the CMake build. They each contain a `.cpp` that the user compiles/runs ad-hoc (CLion single-file run, or `g++` directly). Their committed `.exe` siblings (gitignored going forward) are leftovers from that workflow.
- Executable output is forced to `${CMAKE_BINARY_DIR}/bin` so MinGW/GDB can find binaries even when source paths contain Korean characters.
- `CONFIGURE_DEPENDS` means Ninja re-globs on every build — adding a new `programmers/NNNNN/NNNNN.cpp` requires no edit to `CMakeLists.txt`.

Build commands (PowerShell on Windows, MinGW/Ninja toolchain via CLion):

```powershell
# Configure (only needed once, or after CMakeLists changes)
cmake -S . -B cmake-build-debug -G Ninja

# Build a single problem
cmake --build cmake-build-debug --target p12978

# Run it
.\cmake-build-debug\bin\p12978.exe
```

CLion users: open the project root, pick the auto-generated `pNNNNN` target, hit Run.

## The `programmers/pg.h` test harness — important

Programmers problems use a tiny in-file test runner. The pattern, baked into every `programmers/<id>/<id>.cpp`:

```cpp
string solution(...) { ... }

#if __has_include("../pg.h")
#include "../pg.h"
int main() {
    pg::tests(solution, R"(
arg1   arg2   return
...    ...    ...
)");
    pg::summary();
}
#endif
```

Why the `__has_include` guard: the **whole file**, including the test block, is meant to be pasted into the Programmers web judge. Their compiler can't find `pg.h`, so the guard goes false and the `main()`/tests vanish — no manual stripping needed. **Preserve this pattern when adding new `programmers/` solutions.**

`pg.h` supports `int`, `long long`, `double`, `bool`, `std::string`, and arbitrarily nested `std::vector<...>` of those. Columns inside the raw-string table are **whitespace-separated** (bracket/quote-aware), and the last column is the expected return. Header rows (all non-numeric/quote tokens) are auto-skipped. See the comment block at the top of `pg.h` for the full contract.

## Non-Programmers solution style

`baek_joon*` and `hanghae99_challenger` solutions:
- Standard `int main()` reading from `stdin`, writing to `stdout`.
- Often use `ios::sync_with_stdio(false); cin.tie(nullptr);` (see `baek_joon_step/main.cpp` as the boilerplate template).
- Use `using namespace std;` freely — this is PS code, not library code.
- Globals (`int N;`, `vector<...> arr;`) and a `getInput()` / `solve()` split are common; don't refactor away from this style.

`hanghae99_challenger/h99_pNN_*/` folders pair each `.cpp` with a Korean-titled TIL `.md`. Leave the `.md` alone unless asked.

## Conventions worth knowing

- Source files and folders may contain **Korean characters** (especially `hanghae99_challenger/`). Don't rename them. The ASCII-output-dir trick in `CMakeLists.txt` exists specifically to keep the toolchain happy with these paths.
- `.exe` files are now gitignored (`*.exe` in `.gitignore`); historical commits contain them, that's fine.
- When adding a new Programmers problem: create `programmers/<id>/<id>.cpp` with a `solution(...)` function and the `__has_include` test block. CMake picks it up automatically as target `p<id>`.
- When adding to `Summary/`: follow `Summary/README.md` — pick STL / Algorithm / DataStructure / Technique by the rubric there, use ASCII filenames, follow the document template, and add a line to the "현재 목록" index.
