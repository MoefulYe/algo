#include <cmath>
#include <iostream>
#include <vector>
constexpr auto N = 1024;
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

int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto ps = primes((int)sqrt(n));
  auto prime_factor_cnt = 0uz;
  auto double_prime_factor_cnt = 0uz;
  for (auto p : ps) {
    if (n == 1) {
      break;
    }
    auto cnt = 0;
    while (n % p == 0) {
      n = n / p;
      cnt++;
    }
    if (cnt > 0) {
      prime_factor_cnt++;
    }
    if (cnt > 1) {
      double_prime_factor_cnt++;
    }
  }
  if (n > 1) {
    prime_factor_cnt++;
  }
  auto res =
      prime_factor_cnt * (prime_factor_cnt - 1) / 2 + double_prime_factor_cnt;
  std::cout << res;
}
