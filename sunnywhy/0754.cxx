#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
auto primes(int n) -> std::vector<uint64_t> {
  auto is_prime = std::vector<bool>(n + 1, true);
  auto primes = std::vector<uint64_t>();
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

constexpr auto N = 1024 * 1024 * 16;
auto ps = primes(N);
auto key() {
  auto l = 0, r = 0;
  std::cin >> l >> r;
  auto it1 = std::lower_bound(std::begin(ps), std::end(ps), l);
  auto it2 = std::upper_bound(std::begin(ps), std::end(ps), r);
  auto acc = std::accumulate(it1, it2, 0uz, std::plus());
  return acc;
}

auto main() -> int {
  auto n = 0;
  std::cin >> n;
  for (auto _ = 0; _ < n; _++) {
    auto k = key();
    std::cout << k << '\n';
  }
}
