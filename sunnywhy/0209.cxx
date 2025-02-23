#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>
constexpr auto N = 1024 * 1024;
bool is_prime[N];

auto primes(int n) -> std::vector<int> {
  assert(n <= N);
  std::fill_n(is_prime, n, true);
  is_prime[0] = is_prime[1] = false;
  for (auto i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (auto j = i * i; j <= n; j = j + i) {
        is_prime[j] = false;
      }
    }
  }

  auto primes = std::vector<int>();
  for (auto i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}

auto main() -> int {
  auto n = 0;
  std::cin >> n;
  auto ps = primes(N);
  auto cnt = 0;
  auto pred = -1;
  for (auto p : ps) {
    if (pred + 2 == p) {
      cnt++;
      if (cnt == n) {
        std::cout << pred << " " << p;
        return 0;
      }
    }
    pred = p;
  }
  assert(false);
}
