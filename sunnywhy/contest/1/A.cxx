// https://sunnywhy.com/contest/119/problem/A
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
  auto n = 0;
  cin >> n;
  auto xs = set<int>{};
  for (auto _ = 0; _ < n; _++) {
    auto x = 0;
    cin >> x;
    xs.insert(x);
  }
  auto i = 1;
  for (auto x : xs) {
    if (i == x)
      i = i + 1;
    else {
      break;
    }
  }
  auto j = 100000;
  for (auto _ = xs.rbegin(); _ != xs.rend(); _++) {
    auto x = *_;
    if (x == j)
      j = j - 1;
    else {
      break;
    }
  }
  cout << i << " " << j;
}
