#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <limits>
auto n = 0, k = 0;
auto xs = std::array<int, 16>();
auto msk = 0;

auto dfs(int idx, int cnt, int cover) -> int {
  if (n == idx) {
    if ((cover & msk) != msk) {
      return std::numeric_limits<int>::max();
    } else {
      return cnt;
    }
  } else if ((cover & msk) == msk) {
    return cnt;
  } else {
    auto v1 = dfs(idx + 1, cnt, cover);
    auto v2 = dfs(idx + 1, cnt + 1, cover | xs[idx]);
    return std::min(v1, v2);
  }
}

auto main() -> int {
  std::cin >> n >> k;
  msk = (1 << k) - 1;
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  auto res = dfs(0, 0, 0);
  std::cout << -1;
  if (res == std::numeric_limits<int>::max()) {
    std::cout << -1;
  } else {
    std::cout << res;
  }
}
