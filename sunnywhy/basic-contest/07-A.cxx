#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <string_view>
#include <vector>
auto dist(uint32_t x, uint32_t y) -> int {
  auto ret = 0;
  auto z = x ^ y; // 1不同
  auto cnt = 0;
  while (z != 0) {
    if (z & 1) {
      cnt++;
    }
    x = x >> 1;
  }
  return cnt;
}
auto main() -> int {
  auto n = 0, s = 0;
  std::cin >> n >> s;
  auto input = std::string();
  auto xs = std::vector<uint32_t>(n);
  for (auto i = 0; i < n; i++) {
    std::cin >> input;
    auto x = std::stoul(input, 0, 2);
    xs[i] = x;
  }
  auto min = std::numeric_limits<int>::max();
  for (auto i = 0; i < n; i++) {
    for (auto j = i + 1; j < n; j++) {
      auto x = xs[i];
      auto y = xs[j];
      min = std::min(min, dist(x, y));
    }
  }
  std::cout << min;
}
