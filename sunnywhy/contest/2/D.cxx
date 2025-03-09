// url = https://sunnywhy.com/problem/898
// status = wa
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// 把根染红，那么根与子树的根同色，那么就转化成了子树的染色问题
// 对于叶子节点无需染色

auto nodes = vector<vector<int>>{};
constexpr auto root = 1;

auto init() {
  auto n = 0;
  cin >> n;
  nodes = vector<vector<int>>(n + 1);
  for (auto _ = 0; _ < n - 1; _++) {
    auto x = 0, y = 0;
    cin >> x >> y;
    nodes[x].push_back(y);
  }
}

auto dfs(int idx) {
  auto &child = nodes[idx];
  if (child.empty()) {
    return 0;
  } else {
    auto max = numeric_limits<int>::min();
    for (auto idx : child) {
      max = std::max(max, dfs(idx));
    }
    return max + 1;
  }
}

auto main() -> int {
  init();
  cout << dfs(root);
}
