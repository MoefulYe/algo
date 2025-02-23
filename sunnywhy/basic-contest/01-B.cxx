#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
auto dist(char x, char y) -> int {
  assert(x >= '0' && x <= '9');
  assert(y >= '0' && y <= '9');
  return std::min({abs(y - x), abs(y - x + 10), abs(y - x - 10)});
}

auto main() -> int {
  auto a = std::string(), b = std::string();
  std::cin >> a >> b;
  assert(a.size() == b.size());
  auto cnt = 0;
  for (auto i = 0; i < a.size(); i++) {
    cnt = cnt + dist(a[i], b[i]);
  }
  std::cout << cnt;
}
