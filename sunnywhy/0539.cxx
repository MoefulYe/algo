#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
auto wanquan(int x) -> bool {
  if (x == 0) {
    return false;
  } else if (x > 0) {
    auto sqrt = (int)std::sqrt((double)x);
    return sqrt * sqrt == x;
  } else {
    assert(false);
  }
}

auto dfs(std::string_view s, int tmp) -> bool {
  if (s.empty()) {
    return wanquan(tmp);
  } else {
    auto digit = s.front() - '0';
    auto s1 = s.substr(1);
    // 切割
    auto ok1 = wanquan(tmp);
    if (ok1) { // 可以分割
      auto tmp1 = digit;
      auto ok2 = dfs(s1, tmp1);
      auto tmp2 = tmp * 10 + digit;
      auto ok3 = dfs(s1, tmp2);
      return ok2 || ok3;
    } else {
      auto tmp2 = tmp * 10 + digit;
      auto ok3 = dfs(s1, tmp2);
      return ok3;
    }
  }
}

auto main() -> int {
  auto s = std::string();
  std::cin >> s;
  assert(s.size() > 0);
  auto tmp = s.front() - '0';
  auto ok = dfs(s.substr(1), tmp);
  if (ok) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
}
