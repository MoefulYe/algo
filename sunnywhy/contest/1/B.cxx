// https://sunnywhy.com/contest/119/problem/
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

constexpr auto N = 16 * 1024;
int father[N];
auto n = 0, m = 0;

auto init() {
  cin >> n >> m;
  fill(father + 1, father + n + 1, -1);
}

auto find(const int idx) -> int {
  auto i = idx;
  while (father[i] > 0) {
    i = father[i];
  }
  auto root = i;
  auto j = idx;
  while (j != root) {
    auto fa = father[j];
    father[j] = root;
    j = fa;
  }
  return root;
}

auto uni(int root1, int root2) -> int {
  // NOTE
  if (root1 == root2) {
    return root1;
  }
  // NOTE
  // assert(root1 != root2);
  assert(father[root1] < 0);
  assert(father[root2] < 0);
  auto cnt1 = -father[root1];
  auto cnt2 = -father[root2];
  if (cnt1 >= cnt2) {
    father[root2] = root1;
    father[root1] = -(cnt1 + cnt2);
    return root1;
  } else {
    father[root1] = root2;
    father[root2] = -(cnt1 + cnt2);
    return root2;
  }
}

auto main() -> int {
  init();
  for (auto _ = 0; _ < m; _++) {
    auto u = 0, v = 0;
    cin >> u >> v;
    auto root_u = find(u);
    auto root_v = find(v);
    uni(root_u, root_v);
  }
  auto max = numeric_limits<int>::min();
  for (auto i = 1; i <= n; i++) {
    auto fa = father[i];
    assert(fa != 0);
    if (fa > 0)
      continue;
    auto cnt = -fa;
    max = std::max(max, cnt);
  }
  cout << max;
}
