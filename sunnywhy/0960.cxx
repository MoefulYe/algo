#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
auto dfs(std::string_view s) -> int {
  if (s.empty()) {
    return 1;
  } else if (auto front = s.front(); front == '0') {
    return 0;
  } else if (front == '1') {
    return dfs(s.substr(1));
  } else if (front > '1' && front < '9') {
    return 1 << (s.size() - 1);
  } else {
    assert(front == '9');
    return (1 << (s.size() - 1)) + dfs(s.substr(1));
  }
}

auto main() -> int {
  auto s = std::string();
  std::cin >> s;
  auto cnt_of_leading_zero =
      /*2^n-1 + 2^n-2 + ... + 2 = 1 << n - 2*/ (1uz << s.size()) - 2;
  auto cnt_of_non_zero = dfs(s);
  auto cnt = cnt_of_leading_zero + cnt_of_non_zero;
  std::cout << cnt;
}
