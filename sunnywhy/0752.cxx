#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <utility>
#include <vector>
constexpr auto N = 1 << 15;
auto primes(int n) -> std::vector<int> {
  auto is_prime = std::vector<bool>(n + 1, true);
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
using Prime = int;
using Exp = int;
using Int = std::map<Prime, Exp>;

auto insert(Int &i, int v) {
  for (auto p : ps) {
    if (v == 1) {
      break;
    }
    auto cnt = 0;
    while (v % p == 0) {
      v = v / p;
      cnt++;
    }
    if (cnt > 0) {
      auto [it, ok] = i.insert({p, cnt});
      if (!ok) {
        it->second += cnt;
      }
    }
  }
  if (v > 1) {
    auto [it, ok] = i.insert({v, 1});
    if (!ok) {
      it->second += 1;
    }
  }
}

auto main() -> int {
  auto n = 0, m = 0;
  std::cin >> n >> m;
  auto i = Int();
  auto j = Int();
  auto k = Int();
  for (auto _ = 0; _ < n; _++) {
    auto ai = 0;
    std::cin >> ai;
    insert(i, ai);
  }
  for (auto _ = 0; _ < m; _++) {
    auto bi = 0;
    std::cin >> bi;
    insert(j, bi);
  }
  // std::for_each_n(std::istream_iterator<int>(std::cin), n,
  //                 [&](auto ai) { insert(i, ai); });
  // std::for_each_n(std::istream_iterator<int>(std::cin), m,
  //                 [&](auto bi) { insert(j, bi); });
  for (auto [p, e] : i) {
    if (auto it = j.find(p); it != j.end()) {
      auto e1 = it->second;
      auto e2 = std::min(e, e1);
      k.insert({p, e2});
    }
  }
  if (k.empty()) {
    std::cout << "1 1\n";
  } else {
    for (auto [p, e] : k) {
      std::cout << p << ' ' << e << '\n';
    }
  }
}
