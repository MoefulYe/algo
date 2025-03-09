// https://www.luogu.com.cn/problem/P2871
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <ranges>
#include <string_view>
using namespace std;
auto main() -> int {
  auto n = 0, v = 0;
  cin >> n >> v;
  auto costs = vector<int>(n);
  auto worths = vector<int>(n);
  auto g = vector(n + 1, false);
  auto dp = vector(n + 1, 0);
  for (auto _ = 0; _ < n; _++) {
    auto c = 0, w = 0;
    cin >> c >> w;
    costs.push_back(c);
    worths.push_back(w);
  }
}
