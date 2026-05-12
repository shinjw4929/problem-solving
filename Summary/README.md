# Summary

코딩테스트 준비용 레퍼런스 모음. 자주 쓰는 헤더·알고리즘·자료구조·풀이 기법을 정리한다.

## 폴더 구조

```
Summary/
  STL/             # 표준 라이브러리 헤더·컨테이너 사용법
  Algorithm/       # 정형화된 알고리즘
  DataStructure/   # 직접 구현하는 자료구조
  Technique/       # 풀이 패턴·접근법
```

### 분류 기준

| 카테고리 | 판단 기준 | 예시 |
|---|---|---|
| **STL** | "라이브러리 사용법을 까먹었다" | `sstream`, `string`, `priority_queue`, `algorithm`, `set/map` |
| **Algorithm** | "정해진 절차의 표준 알고리즘" | Dijkstra, Floyd-Warshall, BFS/DFS, 위상정렬, KMP |
| **DataStructure** | "직접 구현하는 자료구조" | Union-Find, Segment Tree, Trie, Fenwick Tree |
| **Technique** | "패턴 인식해야 하는 접근법" | 이분탐색, 투포인터, 슬라이딩 윈도우, DP 패턴 |

애매하면:
- **STL vs Technique**: 헤더 호출 위주면 STL, 사고방식·접근법 위주면 Technique
- **Algorithm vs DataStructure**: "절차"면 Algorithm, "저장 방식"이면 DataStructure (Union-Find=DS, Dijkstra=Algo. priority_queue를 쓴다는 이유로 Dijkstra를 DS로 두진 않음)

## 명명 규칙

- ASCII만. 파일명은 주제 그 자체 (`sstream.md`, `Dijkstra.md`, `UnionFind.md`). 번호·날짜 prefix 안 붙임.
- STL은 헤더명 그대로 소문자, Algorithm/DS는 PascalCase.

## 문서 작성 템플릿

일관성을 위해 가능한 한 아래 섹션을 따른다. 해당 없는 섹션은 생략.

```markdown
# 제목

한 줄 요약 — 이게 뭐고 언제 쓰는지.

## 언제 쓰나

이 도구/알고리즘을 떠올려야 하는 문제 신호. "X 같은 입력 조건이 보이면 Y를 쓴다" 식으로.

## 핵심 사용법

가장 자주 쓰는 패턴 1~3개. 짧은 코드 예시 + 설명.

## 응용

실제 문제에서 자주 보는 변형.

## 주의사항

off-by-one, 오버플로, 초기화 누락, 상태 리셋 등 자주 실수하는 지점.

## 프로그래머스 특화 팁 (선택)

프로그래머스 환경에서 특히 쓸모있는 패턴 (예: `solution()` 멀티 호출 대응).
```

## 새 문서 추가 절차

1. 분류 기준으로 카테고리 폴더 선택
2. `Summary/<카테고리>/<주제>.md` 생성, 위 템플릿대로 작성
3. 아래 "현재 목록"에 한 줄 추가

## 현재 목록

**STL**
- [sstream](STL/sstream.md) — 문자열 파싱·조립
