// url = https://sunnywhy.com/problem/747
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

auto n = 0, m = 0, k = 0; // n个节点, m条边, k个佛头, 节点编号从1开始
auto graph = vector<vector<int>>{};
auto visited = vector<bool>{};
auto dist = vector<int>{};
auto srcs = vector<int>{};

auto init() {
  cin >> n >> m >> k;
  graph = vector<vector<int>>(n + 1);
  visited = vector<bool>(n + 1, false);
  dist = vector<int>(n + 1, numeric_limits<int>::max());
  for (auto _ = 0; _ < k; _++) {
    auto src = 0;
    cin >> src;
    srcs.push_back(src);
  }
  for (auto _ = 0; _ < m; _++) {
    auto a = 0, b = 0;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

auto bfs(int src) {
  assert(src > 0);
  fill(visited.begin(), visited.end(), false);
  auto queue = deque<tuple<int, int>>{{src, 0}}; // 遍历到的编号, 距离
  while (queue.size() > 0) {
    auto [idx, dist1] = queue.front();
    queue.pop_front();
    visited[idx] = true;
    auto dist0 = dist[idx];
    if (dist1 < dist0) { // 新的距离比较短
      dist[idx] = dist1;
      for (auto neighor : graph[idx]) {
        queue.push_back({neighor, dist1 + 1});
      }
    }
  }
}

auto main() -> int {
  init();
  for (auto src : srcs) {
    bfs(src);
  }
  for (auto i = 1; i <= n; i++) {
    auto _ = dist[i];
    auto dist = _ == numeric_limits<int>::max() ? -1 : _;
    cout << dist << "\n";
  }
}
