#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>
constexpr auto N = 1e7 + 1024;
auto primes(int n) -> std::vector<int> {
  auto is_prime = std::vector<int>(n + 1, true);
  auto primes = std::vector<int>();
  is_prime[0] = is_prime[1] = false;
  for (auto i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (auto j = i * i; j <= n; j = j + i) {
        is_prime[j] = false;
      }
    }
  }
  for (auto i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}
auto ps = primes(N);

int _main() {
  auto n = 0;
  std::cin >> n;
  auto it = std::upper_bound(std::begin(ps), std::end(ps), n);
  if (it == std::begin(ps)) {
    assert("unreachable");
  } else if (it == std::end(ps)) {
    assert("unreachable");
  } else if (it - std::begin(ps) < 2) {
    std::cout << "No " << *it;
  } else {
    auto v1 = *(it - 2);
    auto v2 = *(it - 1);
    auto v3 = *it;
    if (v1 + v3 == 2 * v2) {
      std::cout << "Yes";
    } else {
      std::cout << "No " << v3;
    }
  }
  std::cout << "\n";
  return 0;
}

auto main() -> int {
  auto n = 0;
  std::cin >> n;
  for (auto _ = 0; _ < n; _++) {
    _main();
  }
}
