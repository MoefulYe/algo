#include <cassert>
#include <iostream>
#include <string>
auto dfs(std::string_view s, int acc, int tmp) -> int {
  if (s.empty()) {
    return acc + tmp;
  } else {
    auto digit = s.front() - '0';
    auto s1 = s.substr(1);
    // 切割
    auto acc1 = acc + tmp;
    auto tmp1 = digit;
    auto v1 = dfs(s1, acc1, tmp1);
    // else
    auto tmp2 = tmp * 10 + digit;
    auto v2 = dfs(s1, acc, tmp2);
    return v1 + v2;
  }
}

auto main() -> int {
  auto s = std::string();
  std::cin >> s;
  assert(s.size() > 0);
  auto tmp = s.front() - '0';
  auto res = dfs(s.substr(1), 0, tmp);
  std::cout << res;
}
