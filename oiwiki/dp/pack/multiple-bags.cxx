// url = https://oi.wiki/dp/knapsack/#%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85
// origin = https://www.luogu.com.cn/problem/P1776
#include <bits/stdc++.h>
using namespace std;
using namespace std::ranges::views;
struct Item {
  int v, w, m; // 价值, 重量, 数量
  friend auto operator>>(std::istream &is, Item &self) -> std::istream & {
    is >> self.v >> self.w >> self.m;
    return is;
  }
};
auto main() -> int {
  auto n = 0, w = 0;
  cin >> n >> w;
  auto dp = vector<uint64_t>(w + 1, 0uz);
  auto items = vector<Item>(n + 1);

  auto zero_one_pack = [&](int item_v, int item_w) {
    for (auto i = w; i >= item_w; i--) {
      dp[i] = max(dp[i], dp[i - item_w] + item_v);
    }
  };

  copy_n(istream_iterator<Item>(cin), n, items.begin() + 1);
  for (auto [v, w, m] : items | views::drop(1)) {
    auto i = 1;
    while (i < m) {
      zero_one_pack(v * i, w * i);
      m = m - i;
      i = i * 2;
    }
    zero_one_pack(v * m, w * m);
  }
  cout << dp[w];
}
