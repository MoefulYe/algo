// url = https://www.luogu.com.cn/problem/P1855
#include <bits/stdc++.h>
using namespace std;
namespace views = std::ranges::views;

auto n = 0, money_total = 0, time_total = 0;
struct Item {
  int time, money;
  friend auto operator>>(istream &is, Item &self) -> istream & {
    is >> self.money >> self.time;
    return is;
  }
};

auto dp = array<array<int, 256>, 256>{};
auto items = array<Item, 256>{};

auto main() -> int {
  cin >> n >> money_total >> time_total;
  copy_n(istream_iterator<Item>(cin), n, items.begin() + 1);
  for (const auto [time, money] : items | views::drop(1) | views::take(n)) {
    for (auto i = time_total; i >= time; i--) {
      for (auto j = money_total; j >= money; j--) {
        dp[i][j] = max(dp[i - time][j - money] + 1, dp[i][j]);
      }
    }
  }
  cout << dp[time_total][money_total];
}
