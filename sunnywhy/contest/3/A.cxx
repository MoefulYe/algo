// url = https://sunnywhy.com/problem/753
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

auto primes(int n) {
  auto is_prime = vector<bool>(n + 1);
  auto ret = vector<int>{};
  fill(is_prime.begin(), is_prime.end(), true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (auto i = 2; i <= n; i = i + 1) {
    if (is_prime[i]) {
      /// NOTE
      if ((uint64_t)i * i > n)
        continue;
      for (auto j = i * i; j <= n; j = j + i) {
        is_prime[j] = false;
      }
    }
  }
  for (auto i = 2; i <= n; i++) {
    if (is_prime[i]) {
      ret.push_back(i);
    }
  }
  return ret;
}

auto ps = primes(100000);
auto prods = vector<int>{};

auto fenjie(int n) -> vector<int> {
  auto ret = vector<int>{};
  for (auto p : ps) {
    auto cnt = 0;
    while (n % p == 0) {
      cnt = cnt + 1;
      n = n / p;
    }
    if (cnt > 0) {
      ret.push_back(p);
    }
    /// NOTE
    if (n == 1) {
      break;
    }
  }
  /// NOTE 注意n > 1而不是0
  if (n > 1) {
    ret.push_back(n);
  }
  return ret;
}

auto dfs(vector<int> &fenjie, int idx, int yinzishu, int prod) {
  if (yinzishu == 3) {
    prods.push_back(prod);
  } else if (idx == fenjie.size()) {
    return;
  } else {
    auto p = fenjie[idx];
    dfs(fenjie, idx + 1, yinzishu + 1, prod * p);
    dfs(fenjie, idx + 1, yinzishu, prod);
  }
}

auto main() -> int {
  auto n = 0;
  cin >> n;
  auto ps = fenjie(n);
  dfs(ps, 0, 0, 1);
  if (prods.empty()) {
    cout << "-1";
  } else {
    sort(prods.begin(), prods.end());
    for (auto prod : prods) {
      cout << prod << "\n";
    }
  }
}
