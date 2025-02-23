#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>
auto selected = std::array<bool, 16>{
    false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false,
};
auto stones = std::array<int64_t, 16>{};
auto cnt = 0;

auto dfs(int idx) -> int64_t {
  if (idx == cnt) {
    auto [a, b] = std::pair{0z, 0z};
    for (auto i = 0; i < cnt; i++) {
      if (selected[i]) {
        a = a + stones[i];
      } else {
        b = b + stones[i];
      }
    }
    return a > b ? a - b : b - a;
  } else {
    selected[idx] = false;
    auto v1 = dfs(idx + 1);
    selected[idx] = true;
    auto v2 = dfs(idx + 1);
    return std::min(v1, v2);
  }
}

auto main() -> int {
  std::cin >> cnt;
  std::copy_n(std::istream_iterator<int64_t>(std::cin), cnt, stones.begin());
  auto res = dfs(0);
  std::cout << res;
}
