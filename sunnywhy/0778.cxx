#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
auto n = 0;
auto xs = std::vector<int64_t>();
auto abs(int64_t x) { return x >= 0 ? x : -x; }

auto dfs(int idx, int64_t acc, int64_t tmp) -> int64_t {
  if (idx == xs.size()) {
    return std::max(abs(tmp), acc);
  } else {
    auto x = xs[idx];
    auto acc1 = std::max(abs(tmp), acc);
    auto v1 = dfs(idx + 1, acc1, x);
    auto v2 = dfs(idx + 1, acc, tmp + x);
    return std::min(v1, v2);
  }
}

auto main() -> int {
  std::cin >> n;
  std::copy_n(std::istream_iterator<int64_t>(std::cin), n,
              std::back_inserter(xs));
  assert(!xs.empty());
  auto res = dfs(1, 0, xs.front());
  std::cout << res;
  M_PI;
}
