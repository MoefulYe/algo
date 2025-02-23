#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <set>

auto possiblities = std::set<int64_t>{};
auto negs = std::array<bool, 16>{
    false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false,
};
auto xs = std::array<int64_t, 16>{};
auto n = 0;

auto dfs(int idx) {
  if (idx == n) {
    auto acc = 0z;
    for (auto i = 0; i < n; i++) {
      if (negs[i]) {
        acc = acc - xs[i];
      } else {
        acc = acc + xs[i];
      }
    }
    possiblities.insert(acc);
    return;
  }
  negs[idx] = false;
  dfs(idx + 1);
  negs[idx] = true;
  dfs(idx + 1);
}

auto main(int argc, char *argv[]) -> int {
  std::cin >> n;
  std::copy_n(std::istream_iterator<int64_t>(std::cin), n, xs.begin());
  dfs(0);
  for (auto x : possiblities) {
    std::cout << x << "\n";
  }
  return 0;
}
