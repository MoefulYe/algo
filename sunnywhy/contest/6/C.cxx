// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2622

#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
  friend auto operator>>(istream &is, Point &self) -> istream & {
    cin >> self.x >> self.y;
    return is;
  }
};

auto n = 0;
auto father = vector<int>{};
auto nodes = vector<Point>{};

auto init() {
  cin >> n;
  father = vector<int>(n, -1);
  nodes = vector<Point>(n);
  copy_n(istream_iterator<Point>(cin), n, nodes.begin());
}

auto find(int node) -> int {
  auto i = node;
  while (father[i] != -1) {
    i = father[i];
  }
  auto root = i;
  auto j = node;
  while (j != root) {
    auto tmp = father[j];
    father[j] = root;
    j = tmp;
  }
  return root;
}

auto uni(int root1, int root2) {
  if (root1 == root2) {
    return;
  }
  father[root2] = root1;
}

using Index = multimap<int, tuple<int, int>>;

auto index_x() -> Index {
  auto by_x = vector<int>(n);
  iota(by_x.begin(), by_x.end(), 0);
  sort(by_x.begin(), by_x.end(),
       [](int lhs, int rhs) { return nodes[lhs].x < nodes[rhs].x; });
  auto index_x = Index{};
  for (auto i = 0; i < n - 1; i++) {
    auto node1 = by_x[i];
    auto node2 = by_x[i + 1];
    auto dist = nodes[node2].x - nodes[node1].x;
    index_x.insert({dist, {node2, node1}});
  }
  return index_x;
}

auto index_y() -> Index {
  auto by_y = vector<int>(n);
  iota(by_y.begin(), by_y.end(), 0);
  sort(by_y.begin(), by_y.end(),
       [](int lhs, int rhs) { return nodes[lhs].y < nodes[rhs].y; });
  auto index_y = Index{};
  for (auto i = 0; i < n - 1; i++) {
    auto node1 = by_y[i];
    auto node2 = by_y[i + 1];
    auto dist = nodes[node2].y - nodes[node1].y;
    index_y.insert({dist, {node2, node1}});
  }
  return index_y;
}

auto main() -> int {
  init();
  auto idx_x = index_x();
  auto idx_y = index_y();
  auto i = idx_x.begin();
  auto j = idx_y.begin();
  auto sum = 0;
  auto cnt = 0;
  while (true) {
    auto dist1 = i->first;
    auto dist2 = j->first;
    if (dist1 <= dist2) {
      auto [node1, node2] = i->second;
      auto root1 = find(node1);
      auto root2 = find(node2);
      i++;
      if (root1 != root2) {
        uni(root1, root2);
        cnt++;
        sum = sum + dist1;
      }
    } else {
      auto [node1, node2] = j->second;
      auto root1 = find(node1);
      auto root2 = find(node2);
      j++;
      if (root1 != root2) {
        uni(root1, root2);
        cnt++;
        sum = sum + dist2;
      }
    }
    if (cnt == n - 1) {
      break;
    }
  }
  cout << sum;
}
