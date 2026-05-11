#pragma once
// Programmers test helper.
// Paste the example table (with or without the header row) as a raw string;
// each row's last column is the expected return value.
//
// Append this block to the bottom of your solution file. The whole file —
// including this block — can be pasted to Programmers as-is: their compiler
// can't find pg.h, so __has_include is false and the block disappears.
//
//   #if __has_include("../pg.h")
//   #include "../pg.h"
//   int main() {
//       pg::tests(solution, R"(
//   N    road    K    result
//   5    [[1,2,1],[2,3,3],[5,2,2]]    3    4
//   6    [[1,2,1],[1,3,2],[2,3,2]]    4    4
//   )");
//       pg::summary();
//   }
//   #endif
//
// Supported types: int, long long, double, bool, std::string,
// and arbitrarily nested std::vector<...> of the above.

#include <cctype>
#include <chrono>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace pg {

inline std::string trim(const std::string& s) {
    size_t b = 0, e = s.size();
    while (b < e && std::isspace(static_cast<unsigned char>(s[b]))) ++b;
    while (e > b && std::isspace(static_cast<unsigned char>(s[e - 1]))) --e;
    return s.substr(b, e - b);
}

inline std::vector<std::string> split_brackets(const std::string& raw) {
    std::string t = trim(raw);
    if (t.size() < 2 || t.front() != '[' || t.back() != ']')
        throw std::runtime_error("expected [...] but got: " + raw);
    std::vector<std::string> out;
    std::string cur;
    int depth = 0;
    bool in_str = false;
    for (size_t i = 1; i + 1 < t.size(); ++i) {
        char c = t[i];
        if (in_str) {
            cur += c;
            if (c == '\\' && i + 2 < t.size()) cur += t[++i];
            else if (c == '"') in_str = false;
        } else if (c == '"') { in_str = true; cur += c; }
        else if (c == '[') { ++depth; cur += c; }
        else if (c == ']') { --depth; cur += c; }
        else if (c == ',' && depth == 0) { out.push_back(trim(cur)); cur.clear(); }
        else cur += c;
    }
    std::string last = trim(cur);
    if (!last.empty() || !out.empty()) out.push_back(last);
    return out;
}

inline std::vector<std::string> split_row(const std::string& s) {
    std::vector<std::string> out;
    std::string cur;
    int depth = 0;
    bool in_str = false;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (in_str) {
            cur += c;
            if (c == '\\' && i + 1 < s.size()) cur += s[++i];
            else if (c == '"') in_str = false;
        } else if (c == '"') { in_str = true; cur += c; }
        else if (c == '[') { ++depth; cur += c; }
        else if (c == ']') { --depth; cur += c; }
        else if (depth == 0 && std::isspace(static_cast<unsigned char>(c))) {
            if (!cur.empty()) { out.push_back(cur); cur.clear(); }
        } else cur += c;
    }
    if (!cur.empty()) out.push_back(cur);
    return out;
}

template <typename T> struct Parser;

template <> struct Parser<int> {
    static int apply(const std::string& s) { return std::stoi(trim(s)); }
};
template <> struct Parser<long long> {
    static long long apply(const std::string& s) { return std::stoll(trim(s)); }
};
template <> struct Parser<double> {
    static double apply(const std::string& s) { return std::stod(trim(s)); }
};
template <> struct Parser<bool> {
    static bool apply(const std::string& s) {
        std::string t = trim(s);
        if (t == "true") return true;
        if (t == "false") return false;
        throw std::runtime_error("bool parse: " + s);
    }
};
template <> struct Parser<std::string> {
    static std::string apply(const std::string& s) {
        std::string t = trim(s);
        if (t.size() >= 2 && t.front() == '"' && t.back() == '"') {
            std::string r;
            for (size_t i = 1; i + 1 < t.size(); ++i) {
                if (t[i] == '\\' && i + 2 < t.size()) r += t[++i];
                else r += t[i];
            }
            return r;
        }
        return t;
    }
};
template <typename T> struct Parser<std::vector<T>> {
    static std::vector<T> apply(const std::string& s) {
        std::vector<T> out;
        for (auto& part : split_brackets(s))
            if (!part.empty()) out.push_back(Parser<T>::apply(part));
        return out;
    }
};

template <typename T> T parse(const std::string& s) { return Parser<T>::apply(s); }

template <typename T> struct Printer {
    static std::string apply(const T& v) {
        std::ostringstream os; os << v; return os.str();
    }
};
template <> struct Printer<bool> {
    static std::string apply(bool v) { return v ? "true" : "false"; }
};
template <> struct Printer<std::string> {
    static std::string apply(const std::string& v) { return "\"" + v + "\""; }
};
template <typename T> struct Printer<std::vector<T>> {
    static std::string apply(const std::vector<T>& v) {
        std::string r = "[";
        for (size_t i = 0; i < v.size(); ++i) {
            if (i) r += ",";
            r += Printer<T>::apply(v[i]);
        }
        return r + "]";
    }
};
template <typename T> std::string to_str(const T& v) { return Printer<T>::apply(v); }

inline int& _counter() { static int n = 0; return n; }
inline int& _passed() { static int n = 0; return n; }

template <typename Ret, typename... Args, std::size_t... I>
Ret _call(Ret (*fn)(Args...), const std::vector<std::string>& cols, std::index_sequence<I...>) {
    return fn(Parser<std::decay_t<Args>>::apply(cols[I])...);
}

template <typename Ret, typename... Args>
void test(Ret (*fn)(Args...), const std::string& row) {
    int n = ++_counter();
    auto cols = split_row(row);
    constexpr size_t need = sizeof...(Args) + 1;
    if (cols.size() != need) {
        std::cout << "[#" << n << " FAIL] column count: expected "
                  << need << ", got " << cols.size() << "\n";
        return;
    }
    Ret expected = Parser<Ret>::apply(cols.back());
    auto t0 = std::chrono::steady_clock::now();
    Ret got = _call(fn, cols, std::index_sequence_for<Args...>{});
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  std::chrono::steady_clock::now() - t0).count();
    bool ok = (got == expected);
    if (ok) ++_passed();
    std::cout << "[#" << n << " " << (ok ? "OK  " : "FAIL") << " " << ms
              << "ms] got=" << to_str(got)
              << " expected=" << to_str(expected) << "\n";
}

template <typename... Ts, std::size_t... I>
void _probe(const std::vector<std::string>& cols, std::index_sequence<I...>) {
    ((void)Parser<std::decay_t<Ts>>::apply(cols[I]), ...);
}

template <typename Ret, typename... Args>
void tests(Ret (*fn)(Args...), const std::string& block) {
    std::istringstream iss(block);
    std::string line;
    while (std::getline(iss, line)) {
        std::string t = trim(line);
        if (t.empty()) continue;
        auto cols = split_row(t);
        if (cols.size() != sizeof...(Args) + 1) continue;
        try {
            _probe<Args..., Ret>(cols, std::index_sequence_for<Args..., Ret>{});
        } catch (...) {
            continue;
        }
        test(fn, t);
    }
}

template <typename Ret, typename... Args>
void run(Ret (*fn)(Args...), const std::string& row) {
    auto cols = split_row(row);
    if (cols.size() != sizeof...(Args)) {
        std::cout << "[run] column count mismatch\n"; return;
    }
    Ret got = _call(fn, cols, std::index_sequence_for<Args...>{});
    std::cout << "result = " << to_str(got) << "\n";
}

inline void summary() {
    std::cout << "\n=== " << _passed() << "/" << _counter() << " passed ===\n";
}

}  // namespace pg
