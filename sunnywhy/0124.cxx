#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
int arr[32] = {};
auto main() -> int32_t {
  arr[1] = 1;
  arr[2] = 1;
  auto n = 0;
  std::cin >> n;
  assert(n >= 2);
  for (auto i = 3; i <= n; i++) {
    auto max = std::numeric_limits<int>::min();
    for (auto j = 1; j < i; j++) {
      auto rest = i - j;
      auto prod = arr[j] * rest;
      max = std::max(max, prod);
    }
  }
  std::cout << arr[n];
}
