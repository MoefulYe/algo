// url = https://oi.wiki/dp/knapsack/#%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85
// origin = https://www.luogu.com.cn/problem/P1616
#include <bits/stdc++.h>
using namespace std;

struct Item {
  int time, value;
  friend auto operator>>(istream &is, Item &self) -> istream & {
    is >> self.time >> self.value;
    return is;
  }
};

auto main() -> int {
  auto t = 0, m = 0;
  cin >> t >> m;
  auto dp = vector<uint64_t>(t + 1, 0);
  auto items = vector<Item>(m + 1);
  copy_n(istream_iterator<Item>(cin), m, items.begin() + 1);
  for (auto i = 1; i <= m; i++) {
    auto [time, value] = items[i];
    for (auto j = time; j <= t; j++) {
      dp[j] = max(dp[j], dp[j - time] + value);
    }
  }
  cout << dp[t];
}
