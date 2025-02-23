#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
auto main() -> int {
  auto n = 0, k = 0;
  std::cin >> n >> k;
  auto xs = std::vector<int>(n + 1);
  for (auto i = 1; i <= n; i++) {
    auto x = 0;
    std::cin >> x;
    xs[i] = xs[i - 1] + x;
  }
  auto min = std::numeric_limits<int>::max();
  for (auto i = 0; i < n; i++) {
    auto x = xs[i] + k;
    auto it = std::lower_bound(xs.begin(), xs.end(), x);
    if (it == xs.end()) {
      break;
    } else {
      auto len = (int)(it - xs.begin()) - i;
      min = std::min(min, len);
    }
  }
  if (min == std::numeric_limits<int>::max()) {
    std::cout << -1;
  } else {
    std::cout << min;
  }
}
