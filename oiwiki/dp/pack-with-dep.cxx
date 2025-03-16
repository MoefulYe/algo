// url =
// https://oi.wiki/dp/knapsack/#%E6%9C%89%E4%BE%9D%E8%B5%96%E7%9A%84%E8%83%8C%E5%8C%85
// origin = https://www.luogu.com.cn/problem/P1064

#include <bits/stdc++.h>
using namespace std;
using namespace std::ranges::views;

struct Item {
  int v; // 价格
  int w; // 单位价值
  vector<tuple<int, int>> subs;
};

auto n = 0, m = 0; // 多少钱, 物品数量
auto items = array<Item, 64>{};
auto dp = array<int, 1024 * 32>{};

auto main() -> int {
  cin >> n >> m;
  fill(dp.begin(), dp.begin() + n + 1, 0);
  auto j = 0;
  for (const auto _ : views::iota(m)) {
    auto v = 0, p = 0, q = 0;
    cin >> v >> p >> q;
    if (q == 0) {
      j++;
      auto &item = items[j];
      item.v = v;
      item.w = p;
    } else {
      auto &item = items[q];
      item.subs.push_back({v, p});
      assert(item.subs.size() <= 2);
    }
  }
  for (const auto &[v, w, subs] : items | views::drop(1) | views::take(j)) {
    if (subs.size() == 0) {
      for (auto i = n; i >= v; i--) {
        auto if_take0 = dp[i];
        auto if_take1 = dp[i - v] + v * w;
        dp[i] = max(if_take0, if_take1);
      }
    } else if (subs.size() == 1) {
      auto [v1, w1] = subs[0];
      for (auto i = n; i >= v; i--) {
        auto if_take00 = dp[i];
        auto if_take10 = dp[i - v] + v * w;
        auto if_take11 = i >= v1 + v ? dp[i - v - v1] + v * w + v1 * w1 : 0;
        dp[i] = max({if_take00, if_take10, if_take11});
      }
    } else if (subs.size() == 2) {
      auto [v1, w1] = subs[0];
      auto [v2, w2] = subs[1];
      for (auto i = n; i >= v; i--) {
        auto if_take000 = dp[i];
        auto if_take100 = dp[i - v] + v * w;
        auto if_take110 = i >= v1 + v ? dp[i - v - v1] + v * w + v1 * w1 : 0;
        auto if_take101 = i >= v2 + v ? dp[i - v - v2] + v * w + v2 * w2 : 0;
        auto if_take111 = i >= v2 + v1 + v
                              ? dp[i - v - v1 - v2] + v * w + v1 * w1 + v2 * w2
                              : 0;
        dp[i] = max({if_take000, if_take100, if_take100, if_take110, if_take101,
                     if_take111});
      }
    } else {
      assert(false);
    }
  }
  cout << dp[n];
}
