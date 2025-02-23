/// https://sunnywhy.com/problem/685
/// 超时
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
auto ancestors(std::vector<int> &nodes, int idx) {
  auto res = std::vector<int>();
  while (idx != -1) {
    res.push_back(idx);
    idx = nodes[idx];
  }
  std::reverse(res.begin(), res.end());
  return res;
}

int main(int argc, char *argv[]) {
  auto n = 0, q = 0;
  std::cin >> n >> q;
  auto nodes = std::vector<int>(n, -1);
  for (auto _ = 0; _ < n - 1; _++) {
    auto a = 0, b = 0;
    std::cin >> a >> b;
    nodes[b] = a;
  }
  for (auto _ = 0; _ < q; _++) {
    auto a = 0, b = 0;
    std::cin >> a >> b;
    auto v1 = ancestors(nodes, a);
    auto v2 = ancestors(nodes, b);
    auto l = 0;
    auto r = (int)std::min(v1.size(), v2.size());
    while (l < r) {
      auto m = (l + r) / 2;
      if (v1[m] == v2[m]) {
        l = m + 1;
      } else { // v1[m] != v2[m]
        r = m;
      }
    }
    std::cout << v1[l - 1] << std::endl;
  }
  return 0;
}
