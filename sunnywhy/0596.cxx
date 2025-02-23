#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>
auto main() -> int {
  uint64_t n = 0, k = 0;
  uint64_t l = 0, r = 0;
  std::cin >> n >> k >> l >> r;
  auto as = std::vector<uint64_t>(n);
  std::copy_n(std::istream_iterator<uint64_t>(std::cin), n, as.begin());
  auto pre = std::vector<uint64_t>(n + 1);
  pre.front() = 0;
  for (auto i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + as[i];
  }
  auto group_sum = pre.back();
  auto groupl = l / n;
  auto offsetl = l % n;
  auto groupr = r / n;
  auto offsetr = r % n;
  auto ans = (l - r) * group_sum + pre[groupr + 1] - pre[groupl];
  std::cout << ans;
  return 0;
}
